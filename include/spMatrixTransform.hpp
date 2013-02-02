#include "spMatrix.hpp"
using namespace spm;

namespace spm{
    spm::mat4 translation(spm::vec3 translation);
    spm::mat4 rotation(const float angle, spm::vec3 axis);
    spm::mat4 scale(spm::vec3 scale);
}
