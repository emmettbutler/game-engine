#include <GL/glew.h>
#include <GL/glfw.h>

#include <texture.hpp>

class spAnimation{

    public:
        typedef struct _animData {
            GLuint frame;
            int width, height;
        } animData;

        spAnimation(char *frames[], int strcount);
        animData Play(float elapsed);
    private:
        int frameCounter, frameNum;
        float animTimer, animRate;
        animData *anims;
};
