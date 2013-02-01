#include "spMatrix.hpp"
using namespace spm;

//@implementation mat4

mat4::mat4(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m[i][j] = 0.0f;
        }
    }
}

mat4::mat4(const float scaler){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m[i][j] = 0.0f;
            if(i == j){
                m[i][j] = scaler;
            }
        }
    }
}

mat4::mat4(const float x1, const float y1, const float z1, const float w1,
    const float x2, const float y2, const float z2, const float w2,
    const float x3, const float y3, const float z3, const float w3,
    const float transx, const float transy, const float transz, const float w4){
    m[0][0] = x1;
    m[0][1] = y1;
    m[0][2] = z1;
    m[0][3] = w1;

    m[1][0] = x2;
    m[1][1] = y2;
    m[1][2] = z2;
    m[1][3] = w2;

    m[2][0] = x3;
    m[2][1] = y3;
    m[2][2] = z3;
    m[2][3] = w3;

    m[3][0] = transx;
    m[3][1] = transy;
    m[3][2] = transz;
    m[3][3] = w4;
}

// operator overloads
mat4& mat4::operator=(const mat4 &rhs){
    if (this != &rhs){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                this->m[i][j] = rhs.m[i][j];
            }
        }
    }
    return *this;
}

const mat4 mat4::operator*(const mat4 &other) const{
    // product of 2 4x4 matrices
    mat4 result;
    result = mat4();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                result.m[i][j] += this->m[i][k] * other.m[k][j];
            }
        }
    }

    return result;
}

const mat4 mat4::operator*(const vec3 &other) const{
    // cross product between a 3d vector and a 4x4 matrix
    // TODO - this is broken and wrong
    assert(false);
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
    printf("spm::mat4 COMPARISON OPERATOR UNIMPLEMENTED!\n");
    assert(false);
    return false;
}

bool mat4::operator!=(const mat4 &other) const{
    return !(*this == other);
}

void mat4::pp(){
    for(int i = 0; i < 4; i++){
        printf("| ");
        for(int j = 0; j < 4; j++){
            printf("%0.2f ", m[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

vec2::vec2(){
    m[0] = 1.0f;
    m[1] = 1.0f;
}

vec2::vec2(const float x, const float y){
    m[0] = x;
    m[1] = y;
}

void vec2::pp(){
    printf("| ");
    for(int i = 0; i < 2; i++){
        printf("%0.2f ", m[i]);
    }
    printf("|\n\n");
}

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

void vec3::pp(){
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
