#include "common.hpp"
#include <GL/glew.h>
#include <GL/glfw.h>

class spGame{
    public:
        spGame();
        spGame(const float windowWidth, const float windowHeight);
        spm::mat4 calculateViewProjection();
        spm::vec2 GetViewDimensions();
    private:
        float viewWidth, viewHeight;
};
