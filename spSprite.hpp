#include <GL/glew.h>
#include <GL/glfw.h>

#include <shader.hpp>
#include <texture.hpp>

#include "spMatrixStack.hpp"
#include "spMatrixTransform.hpp"
using namespace spm;

class spSprite{
    public:
        spSprite();
        spSprite(float x, float y);
        spSprite(float x, float y, float width, float height);
        void Draw(spm::mat4 viewProjection);
        void SetTransform(float xTrans, float yTrans, float angle);
        spm::mat4 GetTransform();
        void SetScale(const float xScale, const float yScale);
        spm::vec3 GetScale();
        void Dealloc();
    private:
        void init();
        spm::mat4 translation, rotation, scale;

        float x, y, height, width, xScale, yScale;
        GLuint shaderID, vertexbuffer, uvbuffer, vertexPosition_modelspaceID;
        GLuint vertexUVID, Texture, TextureID, MVPID;
        spm::mat4 MVP;
};
