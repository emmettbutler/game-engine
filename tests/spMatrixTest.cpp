#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "spMatrix.hpp"

using namespace spm;

int main(int argc, char *argv[]){
    spm::mat4 a, b, c;
    a = spm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                10.0f, 20.0f, 0.0f, 1.0f);
    b = spm::mat4(6.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 2.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f);
    a.pp();
    b.pp();

    c = b * a;
    c.pp();
    assert(c.m[0][0] == 6.0f);
}
