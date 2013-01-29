#include <GL/glew.h>
#include <GL/glfw.h>

#include <shader.hpp>
#include <texture.hpp>

#include "spMatrixStack.hpp"

class spSprite{
    public:
        spSprite();
        spSprite(float x, float y);
        spSprite(float x, float y, float width, float height);
        void Draw(glm::mat4 viewProjection);
        glm::mat4 GetTransform();
    private:
        void init();
        spMatrixStack *transformStack;

        float x, y, height, width;
        GLuint shaderID, vertexbuffer, uvbuffer, vertexPosition_modelspaceID;
        GLuint vertexUVID, Texture, TextureID, MVPID;
        glm::mat4 MVP;
};
