#include "spMatrix.hpp"
using namespace spm;

//@implementation mat4

mat4::mat4(){
    m[0][0] = 1.0f;
    m[1][0] = 0.0f;
    m[2][0] = 0.0f;
    m[3][0] = 0.0f;

    m[0][1] = 0.0f;
    m[1][1] = 1.0f;
    m[2][1] = 0.0f;
    m[3][1] = 0.0f;

    m[0][2] = 0.0f;
    m[1][2] = 0.0f;
    m[2][2] = 1.0f;
    m[3][2] = 0.0f;

    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    m[3][3] = 1.0f;
}

mat4::mat4(const float scaler){
    m[0][0] = scaler;
    m[1][0] = 0.0f;
    m[2][0] = 0.0f;
    m[3][0] = 0.0f;

    m[0][1] = 0.0f;
    m[1][1] = scaler;
    m[2][1] = 0.0f;
    m[3][1] = 0.0f;

    m[0][2] = 0.0f;
    m[1][2] = 0.0f;
    m[2][2] = scaler;
    m[3][2] = 0.0f;

    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    m[3][3] = scaler;
}

mat4::mat4(const float x1, const float y1, const float z1, const float w1,
    const float x2, const float y2, const float z2, const float w2,
    const float x3, const float y3, const float z3, const float w3,
    const float x4, const float y4, const float z4, const float w4){
    m[0][0] = x1;
    m[1][0] = y1;
    m[2][0] = z1;
    m[3][0] = w1;

    m[0][1] = x2;
    m[1][1] = y2;
    m[2][1] = z2;
    m[3][1] = w2;

    m[0][2] = x3;
    m[1][2] = y3;
    m[2][2] = z3;
    m[3][2] = w3;

    m[0][3] = x4;
    m[1][3] = y4;
    m[2][3] = z4;
    m[3][3] = w4;
}

// operator overloads
mat4& mat4::operator=(const mat4 &rhs){
    if (this != &rhs){
        this->m[0][0] = rhs.m[0][0];
        this->m[0][1] = rhs.m[0][1];
        this->m[0][2] = rhs.m[0][2];
        this->m[0][3] = rhs.m[0][3];

        this->m[1][0] = rhs.m[1][0];
        this->m[1][1] = rhs.m[1][1];
        this->m[1][2] = rhs.m[1][2];
        this->m[1][3] = rhs.m[1][3];

        this->m[2][0] = rhs.m[2][0];
        this->m[2][1] = rhs.m[2][1];
        this->m[2][2] = rhs.m[2][2];
        this->m[2][3] = rhs.m[2][3];

        this->m[3][0] = rhs.m[3][0];
        this->m[3][1] = rhs.m[3][1];
        this->m[3][2] = rhs.m[3][2];
        this->m[3][3] = rhs.m[3][3];
    }
    return *this;
}

const mat4 mat4::operator*(const mat4 &other) const{
    // cross product between 2 4x4 matrices
    mat4 result = *this;

    result.m[0][0] = spm::vec4(this->m[0][0], this->m[0][1], this->m[0][2], this->m[0][3]) * spm::vec4(this->m[0][0], this->m[1][0], this->m[2][0], this->m[3][0]);
    result.m[0][1] = spm::vec4(this->m[0][0], this->m[0][1], this->m[0][2], this->m[0][3]) * spm::vec4(this->m[0][1], this->m[1][1], this->m[2][1], this->m[3][1]);
    result.m[0][2] = spm::vec4(this->m[0][0], this->m[0][1], this->m[0][2], this->m[0][3]) * spm::vec4(this->m[0][2], this->m[1][2], this->m[2][2], this->m[3][2]);
    result.m[0][3] = spm::vec4(this->m[0][0], this->m[0][1], this->m[0][2], this->m[0][3]) * spm::vec4(this->m[0][3], this->m[1][3], this->m[2][3], this->m[3][3]);

    result.m[1][0] = spm::vec4(this->m[1][0], this->m[1][1], this->m[1][2], this->m[1][3]) * spm::vec4(this->m[0][0], this->m[1][0], this->m[2][0], this->m[3][0]);
    result.m[1][1] = spm::vec4(this->m[1][0], this->m[1][1], this->m[1][2], this->m[1][3]) * spm::vec4(this->m[0][1], this->m[1][1], this->m[2][1], this->m[3][1]);
    result.m[1][2] = spm::vec4(this->m[1][0], this->m[1][1], this->m[1][2], this->m[1][3]) * spm::vec4(this->m[0][2], this->m[1][2], this->m[2][2], this->m[3][2]);
    result.m[1][3] = spm::vec4(this->m[1][0], this->m[1][1], this->m[1][2], this->m[1][3]) * spm::vec4(this->m[0][3], this->m[1][3], this->m[2][3], this->m[3][3]);

    result.m[2][0] = spm::vec4(this->m[2][0], this->m[2][1], this->m[2][2], this->m[2][3]) * spm::vec4(this->m[0][0], this->m[1][0], this->m[2][0], this->m[3][0]);
    result.m[2][1] = spm::vec4(this->m[2][0], this->m[2][1], this->m[2][2], this->m[2][3]) * spm::vec4(this->m[0][1], this->m[1][1], this->m[2][1], this->m[3][1]);
    result.m[2][2] = spm::vec4(this->m[2][0], this->m[2][1], this->m[2][2], this->m[2][3]) * spm::vec4(this->m[0][2], this->m[1][2], this->m[2][2], this->m[3][2]);
    result.m[2][3] = spm::vec4(this->m[2][0], this->m[2][1], this->m[2][2], this->m[2][3]) * spm::vec4(this->m[0][3], this->m[1][3], this->m[2][3], this->m[3][3]);

    result.m[3][0] = spm::vec4(this->m[3][0], this->m[3][1], this->m[3][2], this->m[3][3]) * spm::vec4(this->m[0][0], this->m[1][0], this->m[2][0], this->m[3][0]);
    result.m[3][1] = spm::vec4(this->m[3][0], this->m[3][1], this->m[3][2], this->m[3][3]) * spm::vec4(this->m[0][1], this->m[1][1], this->m[2][1], this->m[3][1]);
    result.m[3][2] = spm::vec4(this->m[3][0], this->m[3][1], this->m[3][2], this->m[3][3]) * spm::vec4(this->m[0][2], this->m[1][2], this->m[2][2], this->m[3][2]);
    result.m[3][3] = spm::vec4(this->m[3][0], this->m[3][1], this->m[3][2], this->m[3][3]) * spm::vec4(this->m[0][3], this->m[1][3], this->m[2][3], this->m[3][3]);

    return result;
}

const mat4 mat4::operator*(const vec3 &other) const{
    // cross product between a 3d vector and a 4x4 matrix
    mat4 result = *this;
    result.m[0][0] *= other.m[0];
    result.m[1][0] *= other.m[1];
    result.m[2][0] *= other.m[2];
    result.m[3][0] *= 1.0f;

    result.m[0][1] *= other.m[0];
    result.m[1][1] *= other.m[1];
    result.m[2][1] *= other.m[2];
    result.m[3][1] *= 1.0f;

    result.m[0][2] *= other.m[0];
    result.m[1][2] *= other.m[1];
    result.m[2][2] *= other.m[2];
    result.m[3][2] *= 1.0f;

    result.m[0][3] *= other.m[0];
    result.m[1][3] *= other.m[1];
    result.m[2][3] *= other.m[2];
    result.m[3][3] *= 1.0f;

    return result;
}

const mat4 mat4::operator*(const vec2 &other) const{
    // cross product between a 2d vector and a 4x4 matrix
    mat4 result = *this;
    result.m[0][0] *= other.m[0];
    result.m[1][0] *= other.m[1];
    result.m[2][0] *= 1.0f;
    result.m[3][0] *= 1.0f;

    result.m[0][1] *= other.m[0];
    result.m[1][1] *= other.m[1];
    result.m[2][1] *= 1.0f;
    result.m[3][1] *= 1.0f;

    result.m[0][2] *= other.m[0];
    result.m[1][2] *= other.m[1];
    result.m[2][2] *= 1.0f;
    result.m[3][2] *= 1.0f;

    result.m[0][3] *= other.m[0];
    result.m[1][3] *= other.m[1];
    result.m[2][3] *= 1.0f;
    result.m[3][3] *= 1.0f;
    return result;
}

bool mat4::operator==(const mat4 &other) const{
    if(m[0][0] == other.m[0][0]){
        return true;
    }
    return false;
}

bool mat4::operator!=(const mat4 &other) const{
    return !(*this == other);
}

void mat4::prettyPrint(){
    for(int i = 0; i < 4; i++){
        printf("| ");
        for(int j = 0; j < 4; j++){
            printf("%0.2f ", m[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

// end @implementation mat4

// @implementation vec3

vec3::vec3(){
    m[0] = 1.0f;
    m[1] = 1.0f;
    m[2] = 1.0f;
    m[3] = 1.0f;
}

vec3::vec3(const float x, const float y, const float z){
    m[0] = x;
    m[1] = y;
    m[2] = z;
    m[3] = 1.0f;
}

void vec3::prettyPrint(){
    printf("| ");
    for(int i = 0; i < 3; i++){
        printf("%0.2f ", m[i]);
    }
    printf("|\n\n");
}

// end @implementation vec3

vec4::vec4(){
    m[0] = 1.0f;
    m[1] = 1.0f;
    m[2] = 1.0f;
    m[3] = 1.0f;
}

vec4::vec4(const float x, const float y, const float z, const float w){
    m[0] = x;
    m[1] = y;
    m[2] = z;
    m[3] = w;
}

const float vec4::operator*(const vec4 &other) const{
    // dot product
    return this->m[0]*other.m[0] + this->m[1]*other.m[1] + this->m[2]*other.m[2] + this->m[3]*other.m[3];
}
