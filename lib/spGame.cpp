#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "spMatrix.hpp"
#include "spGame.hpp"

spGame::spGame(const float windowWidth, const float windowHeight){
    if( !glfwInit() ){
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return;
    }

    if( !glfwOpenWindow(windowWidth, windowHeight, 0,0,0,0, 32,0, GLFW_WINDOW ) ){
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        return;
    }

    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }

    glfwSetWindowTitle( "spGame Window" );
    glfwEnable( GLFW_STICKY_KEYS );

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    this->viewWidth = windowWidth/.75f;
    this->viewHeight = windowHeight/.75f;
}

spm::mat4 spGame::calculateViewProjection(){
    glm::mat4 Projection = glm::ortho(0.0f, this->viewWidth, 0.0f, this->viewHeight, -5.0f, 5.0f);
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

spm::vec2 spGame::GetViewDimensions(){
    spm::vec2 dim = spm::vec2(this->viewWidth, this->viewHeight);
    return dim;
}
