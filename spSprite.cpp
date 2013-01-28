#include "spSprite.hpp"

spSprite::spSprite(float x, float y){
    this->x = x;
    this->y = y;
    this->transformStack = new spMatrixStack();
    glm::mat4 Model = glm::mat4(1.0f);
    this->transformStack->Push(Model);
}

glm::mat4 spSprite::GetTransform(){
    return this->transformStack->Pop();
}

void spSprite::Draw(){

}
