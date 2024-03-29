#include <sys/time.h>
#include <string.h>

#include "spSprite.hpp"
#include "spAnimation.hpp"
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

    char *anims[4];
    for(int i = 0; i < 4; i++){
        anims[i] = (char *)malloc(50 * sizeof(char));
    }
    strcpy(anims[0], "textures/Cop_Head_Dog_1.png");
    strcpy(anims[1], "textures/BusinessHead_Dog_1.png");
    strcpy(anims[2], "textures/Nudie_Head_Dog_1.png");
    strcpy(anims[3], "textures/Jogger_Head_Dog_1.png");

    spSprite *sprite = new spSprite(viewDim.m[0]/2, viewDim.m[1]/2, "textures/Jogger_Head_Dog_1.png");
    spAnimation *anim = new spAnimation(anims, sizeof(anims)/sizeof(anims[0]));

    int ttime = 0;

    srand(time(NULL));

    do{
        clock_gettime(CLOCK_REALTIME, &ts);

        ttime++;
        glClear(GL_COLOR_BUFFER_BIT);

        spAnimation::animData d = anim->Play(sec_elapsed);
        sprite->Update(d.frame, d.width, d.height);
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
