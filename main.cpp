#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <GL/glew.h>
#include <GL/glfw.h>

#include <shader.hpp>
#include <texture.hpp>

#include "spSprite.hpp"

int setupWindow(const float windowWidth, const float windowHeight){
    if( !glfwInit() ){
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

    if( !glfwOpenWindow(windowWidth, windowHeight, 0,0,0,0, 32,0, GLFW_WINDOW ) ){
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        return -1;
    }

    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    glfwSetWindowTitle( "Sprite Test" );
    glfwEnable( GLFW_STICKY_KEYS );

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

spm::mat4 calculateViewProjection(const float viewWidth, const float viewHeight){
    spm::mat4 Projection = spm::ortho(0.0f, viewWidth, 0.0f, viewHeight, -5.0f, 5.0f);
    spm::mat4 View = spm::lookAt(spm::vec3(0,0,5), spm::vec3(0,0,0), spm::vec3(0,1,0));
    return Projection * View;
}

int main(){

    const float windowWidth = 1024.0f;
    const float windowHeight = 768.0f;

    if(setupWindow(windowWidth, windowHeight) == -1){
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
            spm::vec3 myScale = sprites[i]->GetScale();
            sprites[i]->SetScale(2.0 * (i % 5), 2.0 * (i % 5));
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
