#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glfw.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <shader.hpp>
#include <texture.hpp>

#include "spSprite.hpp"

int main(){

    if( !glfwInit() ){
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

    const float windowWidth = 1024.0f;
    const float windowHeight = 768.0f;

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

    const float viewWidth = windowWidth/5.0f;
    const float viewHeight = windowHeight/5.0f;

    glfwSetWindowTitle( "Sprite Test" );
    glfwEnable( GLFW_STICKY_KEYS );

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLuint vertexbuffer, uvbuffer;

    glm::mat4 Projection = glm::ortho(0.0f, viewWidth, 0.0f, viewHeight, -5.0f, 5.0f);
    glm::mat4 View = glm::lookAt(glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0));

    spSprite *mySprite = new spSprite(viewWidth/2, viewHeight/2);
    spSprite *mySprite2 = new spSprite(viewWidth/4, viewHeight/4);
    spSprite *mySprite3 = new spSprite(viewWidth/8, viewHeight/8);

    do{
        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 viewProjection = Projection * View;
        mySprite->Draw(viewProjection);
        mySprite2->Draw(viewProjection);
        mySprite3->Draw(viewProjection);

        glfwSwapBuffers();
    }
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
        glfwGetWindowParam( GLFW_OPENED ) );

    mySprite->Dealloc();
    mySprite2->Dealloc();
    mySprite3->Dealloc();

    glfwTerminate();

    return 0;
}
