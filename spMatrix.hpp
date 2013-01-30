#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

namespace spm{
    class vec3{
        public:
            vec3();
            vec3(const float x, const float y, const float z);
            float m[3];
    };

    class vec2{
        public:
            vec2();
            vec2(const float x, const float y);
            float m[2];
    };
    class mat4{
        public:
            mat4();
            mat4(const float x1, const float y1, const float z1, const float w1,
                const float x2, const float y2, const float z2, const float w2,
                const float x3, const float y3, const float z3, const float w3,
                const float x4, const float y4, const float z4, const float w4);
            mat4& operator=(const mat4 &rhs);
            const mat4 operator*(const mat4 &other) const;
            const mat4 operator*(const vec3 &other) const;
            const mat4 operator*(const vec2 &other) const;
            bool operator==(const mat4 &other) const;
            bool operator!=(const mat4 &other) const;
            float m[4][4];
    };
}
