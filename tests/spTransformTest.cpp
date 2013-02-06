#include "spSprite.hpp"
#include "spGame.hpp"

int main(){
    const float windowWidth = 1280.0f;
    const float windowHeight = 768.0f;

    spGame *frame;
    if((frame = new spGame(windowWidth, windowHeight)) == NULL){
        return -1;
    }

    spm::vec2 viewDim = frame->GetViewDimensions();
    spSprite *sprite = new spSprite(viewDim.m[0]/2, viewDim.m[1]/2);
    spm::vec2 anchorPoint = spm::vec2(viewDim.m[0]/2, viewDim.m[1]/2);
    int time = 0;

    do{
        time++;
        glClear(GL_COLOR_BUFFER_BIT);

        spm::vec2 myScale, myPosition;
        myScale = sprite->GetScale();
        float scaler = 1.5f * (sin(.09 * time) + 2.0f);
        sprite->SetScale(spm::vec2(scaler, scaler));
        sprite->SetAngle(sprite->GetAngle() + .04);

        myPosition = sprite->GetPosition();
        sprite->SetPosition(spm::vec2(
                    anchorPoint.m[0] + 400.0f * sin(.01f * time),
                    anchorPoint.m[1] + 400.0f * cos(.01f * time))
                );

        // TODO - instead of having to explicitly call draw for each actor,
        // maybe encapsulate the entire game loop in spGame and keep references to
        // all added actors (a la flixel)
        sprite->Draw(frame);

        glfwSwapBuffers();
    } while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
        glfwGetWindowParam( GLFW_OPENED ) );

    sprite->Dealloc();
    delete sprite;
    sprite = NULL;
}
