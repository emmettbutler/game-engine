#include "spSprite.hpp"

spSprite::spSprite(float x, float y){
    this->x = x;
    this->y = y;
    this->transformStack = new spMatrixStack();
    glm::mat4 Model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f)), glm::vec3(5.0f, 5.0f, 0.0f));
    this->transformStack->Push(Model);
}

glm::mat4 spSprite::GetTransform(){
    return this->transformStack->CalculateTransform();
}

void spSprite::Draw(){

}
