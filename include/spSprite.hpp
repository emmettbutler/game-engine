#include <GL/glew.h>
#include <GL/glfw.h>

#include <shader.hpp>
#include <texture.hpp>

#include "spMatrixTransform.hpp"
using namespace spm;

class spSprite{
    public:
        spSprite();
        spSprite(float x, float y, const char *texture);
        spSprite(float x, float y, float width, float height);
        // TODO - passing in a void* here is pretty hacky. this should internally
        // use a singleton instance of the game context so we don't have to
        // pass it anything
        void Draw(void *frame);
        void SetTransform(spm::vec2 position, float angle);
        spm::mat4 GetTransform();
        void SetScale(spm::vec2 newScale);
        spm::vec2 GetScale();
        void SetAngle(const float angle);
        float GetAngle();
        void SetPosition(spm::vec2 pos);
        spm::vec2 GetPosition();
        void AddAnimationFrames(char **frames);
        void PlayAnimation(float elapsed);
        void Dealloc();
    private:
        void init(const char *texture);
        void setupQuad(int width, int height);
        void setShaderParams();
        spm::mat4 translation, rotation, scale_mat;

        float x, y, height, width, angle, animRate, animTimer;
        spm::vec2 scale;
        GLuint shaderID, vertexbuffer, uvbuffer, vertexPosition_modelspaceID;
        GLuint vertexUVID, currentTexture, TextureID, MVPID;
        GLuint *anims;
        GLuint shrink_filter, exp_filter;
        int frameCounter, frameNum;
        spm::mat4 MVP;
};
