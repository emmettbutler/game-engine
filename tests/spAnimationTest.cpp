#include <sys/time.h>

#include "spSprite.hpp"
#include "spGame.hpp"

int main(){
    timespec ts, te;
    float sec_elapsed;
    spGame *frame;
    if((frame = new spGame(1280.0f, 768.0f)) == NULL){
        return -1;
    }

    spm::vec2 viewDim = frame->GetViewDimensions();
    const char *tex;

    char **anims = new char*[4];
    anims[0] = "textures/Cop_Head_Dog_1.png";
    anims[1] = "textures/BusinessHead_Dog_1.png";
    anims[2] = "textures/Nudie_Head_Dog_1.png";
    anims[3] = "textures/Jogger_Head_Dog_1.png";

    spSprite *sprite = new spSprite(viewDim.m[0]/2, viewDim.m[1]/2, "textures/Jogger_Head_Dog_1.png");
    sprite->AddAnimationFrames(anims);

    int ttime = 0;

    srand(time(NULL));

    do{
        clock_gettime(CLOCK_REALTIME, &ts);

        ttime++;
        glClear(GL_COLOR_BUFFER_BIT);

        sprite->PlayAnimation(sec_elapsed);
        sprite->Draw(frame);

        glfwSwapBuffers();

        // fps timing
        clock_gettime(CLOCK_REALTIME, &te);
        int nsec_elapsed = te.tv_nsec - ts.tv_nsec;
        sec_elapsed = nsec_elapsed / 1000000000.0f;
        if(ttime % 10 == 0 && sec_elapsed > 0){
                printf("FPS: %0.2f\n", sec_elapsed * 1000.0f);
                printf("\033[2J\033[1;1H");
        }
    } while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
        glfwGetWindowParam( GLFW_OPENED ) );

    sprite->Dealloc();
    delete sprite;
    sprite = NULL;
}
