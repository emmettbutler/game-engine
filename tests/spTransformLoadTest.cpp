#include <sys/time.h>

#include "spSprite.hpp"
#include "spGame.hpp"

int main(){
    timespec ts, te;
    spGame *frame;
    if((frame = new spGame(1280.0f, 768.0f)) == NULL){
        return -1;
    }

    int numSprites = 200;
    spSprite *sprites[200] = {0};

    spm::vec2 viewDim = frame->GetViewDimensions();
    for(int i = 0; i < numSprites; i++){
        int choice = rand() % 4;
        const char *tex;
        switch(choice){
            case 0: tex = "textures/Cop_Head_Dog_1.png"; break;
            case 1: tex = "textures/BusinessHead_Dog_1.png"; break;
            case 2: tex = "textures/Nudie_Head_Dog_1.png"; break;
            case 3: tex = "textures/Jogger_Head_Dog_1.png"; break;
        }
        sprites[i] = new spSprite(rand() % (int)viewDim.m[0], rand() % (int)viewDim.m[1]/2, tex);
    }
    spm::vec2 anchorPoint = spm::vec2(viewDim.m[0]/2, viewDim.m[1]/2);
    int ttime = 0;

    srand(time(NULL));

    do{
        clock_gettime(CLOCK_REALTIME, &ts);

        ttime++;
        glClear(GL_COLOR_BUFFER_BIT);

        for(int i = 0; i < numSprites; i++){
            float scaler = 1.5f * (sin(.09 * ttime) + 2.0f);
            sprites[i]->SetAngle(sprites[i]->GetAngle() + .04);
            sprites[i]->SetPosition(spm::vec2(
                        anchorPoint.m[0] + 20 * i * sin(i * .01f * ttime),
                        anchorPoint.m[1] + 20 * i * cos(i * .01f * ttime))
                    );
            sprites[i]->Draw(frame);
        }

        glfwSwapBuffers();

        // fps timing
        clock_gettime(CLOCK_REALTIME, &te);
        int nsec_elapsed = te.tv_nsec - ts.tv_nsec;
        float sec_elapsed = nsec_elapsed / 1000000000.0f;
        if(ttime % 10 == 0 && sec_elapsed > 0){
                printf("FPS: %0.2f\n", sec_elapsed * 1000.0f);
                printf("\033[2J\033[1;1H");
        }
    } while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
        glfwGetWindowParam( GLFW_OPENED ) );

    for(int i = 0; i < numSprites; i++){
        sprites[i]->Dealloc();
        delete sprites[i];
        sprites[i] = NULL;
    }
}
