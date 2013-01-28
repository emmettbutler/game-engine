#include "spMatrixStack.hpp"

class spSprite{
    public:
        spSprite();
        spSprite(float x, float y);
        spSprite(float x, float y, float width, float height);
        void Draw();
        glm::mat4 GetTransform();
    private:
        float x, y, height, width;
        spMatrixStack *transformStack;
};
