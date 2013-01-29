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

    if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) ){
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        return -1;
    }

    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    const float viewWidth = 1024.0f/5.0f;
    const float viewHeight = 768.0f/5.0f;

    spSprite *mySprite = new spSprite(viewWidth/2, viewHeight/2);
    spSprite *mySprite2 = new spSprite(viewWidth/4, viewHeight/4);
    spSprite *mySprite3 = new spSprite(viewWidth/8, viewHeight/8);

    glfwSetWindowTitle( "Sprite Test" );
    glfwEnable( GLFW_STICKY_KEYS );
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    GLuint programID = LoadShaders( "shaders/TransformVertexShader.vs", "shaders/TextureFragmentShader.fs" );

    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    GLuint vertexbuffer, uvbuffer;

    // enable transparent sprites
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glm::mat4 Projection = glm::ortho(0.0f, viewWidth, 0.0f, viewHeight, -5.0f, 5.0f);
    glm::mat4 View = glm::lookAt(
                                glm::vec3(0,0,5),
                                glm::vec3(0,0,0),
                                glm::vec3(0,1,0)
                           );

    do{
        glClear(GL_COLOR_BUFFER_BIT);

        mySprite->Draw(Projection * View);
        mySprite2->Draw(Projection * View);
        mySprite3->Draw(Projection * View);

        glfwSwapBuffers();
    }
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
        glfwGetWindowParam( GLFW_OPENED ) );

    //glDeleteBuffers(1, &vertexbuffer);
    //glDeleteBuffers(1, &uvbuffer);
    //glDeleteProgram(programID);
    //glDeleteTextures(1, &TextureID);

    glfwTerminate();

    return 0;
}
