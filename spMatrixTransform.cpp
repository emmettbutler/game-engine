#include "spMatrixTransform.hpp"

namespace spm{
    // TODO - make the parameters const?
    spm::mat4 translation(spm::vec3 translation){
        float xTrans = translation.m[0];
        float yTrans = translation.m[1];
        return spm::mat4(
                    1.0f, 0.0f, 0.0f, xTrans,
                    0.0f, 1.0f, 0.0f, yTrans,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f
                );
    }

    spm::mat4 scale(spm::vec3 scale){
        float xScale = scale.m[0];
        float yScale = scale.m[1];
        return spm::mat4(
                    xScale, 0.0f, 0.0f, 0.0f,
                    0.0f, yScale, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f
                );
    }
}
