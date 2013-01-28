#include "spSprite.hpp"
#include "spMatrixTransform.hpp"

spSprite::spSprite(float x, float y){
    this->x = x;
    this->y = y;
    this->transformStack = new spMatrixStack();

    glm::mat4 Model = glm::mat4(1.0f);
    this->transformStack->Push(Model);

    glm::mat4 trans = spTranslation(glm::vec3(x, y, 0.0f));
    this->transformStack->Push(trans);
}

glm::mat4 spSprite::GetTransform(){
    return this->transformStack->CalculateTransform();
}

void spSprite::Draw(){

}
