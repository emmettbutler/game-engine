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
        void SetTransform(float xTrans, float yTrans, float angle);
        glm::mat4 GetTransform();
        void Dealloc();
    private:
        void init();
        glm::mat4 translation, rotation, scale;

        float x, y, height, width;
        GLuint shaderID, vertexbuffer, uvbuffer, vertexPosition_modelspaceID;
        GLuint vertexUVID, Texture, TextureID, MVPID;
        glm::mat4 MVP;
};
