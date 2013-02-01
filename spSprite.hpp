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
        void SetTransform(spm::vec2 position, float angle);
        spm::mat4 GetTransform();
        void SetScale(spm::vec2 newScale);
        spm::vec2 GetScale();
        void Dealloc();
    private:
        void init();
        spm::mat4 translation, rotation, scale_mat;

        float x, y, height, width;
        spm::vec2 scale;
        GLuint shaderID, vertexbuffer, uvbuffer, vertexPosition_modelspaceID;
        GLuint vertexUVID, Texture, TextureID, MVPID;
        spm::mat4 MVP;
};
