#include "spMatrixTransform.hpp"

namespace spm{
    glm::mat4 translation(glm::vec3 translation){
        float xTrans = translation[0];
        float yTrans = translation[1];
        return glm::mat4(
                    1.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    xTrans, yTrans, 0.0f, 1.0f
                );
    }
}
