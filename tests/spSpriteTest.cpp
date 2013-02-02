#include <GL/glew.h>
#include <GL/glfw.h>

#include <shader.hpp>
#include <texture.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "spSprite.hpp"
#include "spGame.hpp"


spm::mat4 calculateViewProjection(const float viewWidth, const float viewHeight){
    glm::mat4 Projection = glm::ortho(0.0f, viewWidth, 0.0f, viewHeight, -5.0f, 5.0f);
    glm::mat4 View = glm::lookAt(glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0));
    spm::mat4 myProjection = spm::mat4(
        Projection[0][0], Projection[0][1], Projection[0][2], Projection[0][3],
        Projection[1][0], Projection[1][1], Projection[1][2], Projection[1][3],
        Projection[2][0], Projection[2][1], Projection[2][2], Projection[2][3],
        Projection[3][0], Projection[3][1], Projection[3][2], Projection[3][3]
            );

    spm::mat4 myView = spm::mat4(
        View[0][0], View[0][1], View[0][2], View[0][3],
        View[1][0], View[1][1], View[1][2], View[1][3],
        View[2][0], View[2][1], View[2][2], View[2][3],
        View[3][0], View[3][1], View[3][2], View[3][3]
            );

    spm::mat4 viewProjection;
    viewProjection = myView * myProjection;
    return viewProjection;
}

int main(){

    const float windowWidth = 1024.0f;
    const float windowHeight = 768.0f;

    if((new spGame(windowWidth, windowHeight)) == NULL){
        return -1;
    };

    const float viewWidth = windowWidth/5.0f;
    const float viewHeight = windowHeight/5.0f;

    spm::mat4 viewProjection = calculateViewProjection(viewWidth, viewHeight);

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
            sprites[i] = new spSprite(rand() % (int)viewWidth, rand() % (int)viewHeight);
        }
        if(i < numSprites){
            i++;
        } else {
            i = 0;
        }

        for(int j = 0; j < numSprites; j++){
            if(sprites[j] != NULL){
                sprites[j]->Draw(viewProjection);
            }
        }

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
