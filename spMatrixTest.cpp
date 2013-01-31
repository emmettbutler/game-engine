#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "spMatrix.hpp"
using namespace spm;

int main(int argc, char *argv[]){
    spm::mat4 a(1.0), c;
    spm::vec3 b(2.0f, 3.0f, 4.0f);

    a.prettyPrint();
    printf("*\n");
    b.prettyPrint();

    c = a * b;

    printf("=\n");
    c.prettyPrint();

    assert(c.m[2][2] == 4.0f);
}
