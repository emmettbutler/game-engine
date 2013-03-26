#include "spAnimation.hpp"

spAnimation::spAnimation(char *frames[], int strcount){
    this->anims = new animData[strcount];
    for(int i = 0; i < strcount; i++){
        this->anims[i].frame = loadPngImage(frames[i], this->anims[i].width, this->anims[i].height);
    }
    this->animTimer = 0;
    this->frameNum = strcount - 1;
    this->frameCounter = 0;
    this->animRate = .8;
}

spAnimation::animData spAnimation::Play(float elapsed){
    if(elapsed >= 0.0f){
        this->animTimer += elapsed;
    }
    if(this->animTimer >= this->animRate){
        this->animTimer = 0;
        if(this->frameCounter < this->frameNum){
            this->frameCounter++;
        } else {
            this->frameCounter = 0;
        }
    }
    return this->anims[this->frameCounter];
}
