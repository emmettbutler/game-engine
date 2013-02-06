#include "spSprite.hpp"
#include "spGame.hpp"

int main(){
    spGame *frame;
    if((frame = new spGame(1280.0f, 768.0f)) == NULL){
        return -1;
    }

    spm::vec2 viewDim = frame->GetViewDimensions();
    spSprite *sprite = new spSprite(viewDim.m[0]/2, viewDim.m[1]/2, "textures/BusinessHead_Dog_1.png");
    spm::vec2 anchorPoint = spm::vec2(viewDim.m[0]/2, viewDim.m[1]/2);
    int time = 0;

    do{
        time++;
        glClear(GL_COLOR_BUFFER_BIT);

        float scaler = 1.5f * (sin(.09 * time) + 2.0f);
        sprite->SetScale(spm::vec2(scaler, scaler));
        sprite->SetAngle(sprite->GetAngle() + .04);
        sprite->SetPosition(spm::vec2(
                    anchorPoint.m[0] + 400.0f * sin(.01f * time),
                    anchorPoint.m[1] + 400.0f * cos(.01f * time))
                );
        sprite->Draw(frame);

        glfwSwapBuffers();
    } while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
        glfwGetWindowParam( GLFW_OPENED ) );

    sprite->Dealloc();
    delete sprite;
    sprite = NULL;
}
