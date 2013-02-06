#include "spSprite.hpp"
#include "spGame.hpp"


int main(){

    const float windowWidth = 1024.0f;
    const float windowHeight = 768.0f;

    spGame *frame;
    if((frame = new spGame(windowWidth, windowHeight)) == NULL){
        return -1;
    };

    srand(time(NULL));
    int numSprites = 100;
    spSprite *sprites[100] = {0};
    int i = 0;

    do{
        glClear(GL_COLOR_BUFFER_BIT);

        if(sprites[i] != NULL){
            spm::vec2 myScale;
            myScale = sprites[i]->GetScale();
            sprites[i]->SetScale(spm::vec2(myScale.m[0] * 1.8f, myScale.m[1] * 1.8f));
        } else {
            spm::vec2 viewDim = frame->GetViewDimensions();
            sprites[i] = new spSprite(rand() % (int)viewDim.m[0], rand() % (int)viewDim.m[1], "textures/BusinessHead_Dog_1.png");
        }
        if(i < numSprites){
            i++;
        } else {
            i = 0;
        }

        for(int j = 0; j < numSprites; j++){
            if(sprites[j] != NULL){
                // TODO - passing context in here is a bad interface
                // ideally it should be just Draw()
                // that requires a singleton instance of the Game class
                // accessed from inside Draw
                sprites[j]->Draw(frame);
            }
        }

        // TODO - how to remove this and other glfw calls from the external API?
        glfwSwapBuffers();
    } while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
        glfwGetWindowParam( GLFW_OPENED ) );

    for(int j = 0; j < numSprites; j++){
        if(sprites[j] != NULL){
            sprites[j]->Dealloc();
            delete sprites[j];
            sprites[j] = NULL;
        }
    }

    glfwTerminate();

    return 0;
}
