#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace spm{
    glm::mat4 translation(glm::vec3 translation);
    glm::mat4 rotation(const float angle, glm::vec3 axis);
    glm::mat4 scale(glm::vec3 scale);
}
