/*
 * Copyright (c) 2014 Hackdirt Ltd.
 * Author: David Petrie (david@davidpetrie.com)
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software. Permission is granted to anyone to use this software for
 * any purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim
 * that you wrote the original software. If you use this software in a product, an
 * acknowledgment in the product documentation would be appreciated but is not
 * required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef GLES_GLUE_H
#define GLES_GLUE_H

#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>

#define kVertexCount 512

#ifndef uint32_t
typedef unsigned int uint32_t;
#endif

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec4_t color4_t;

#define vec2Set(__v, __x, __y) { __v[0] = __x; __v[1] = __y; }
#define vec3Set(__v, __x, __y, __z) { __v[0] = __x; __v[1] = __y; __v[2] = __z; }
#define vec4Set(__v, __x, __y, __z, __u) { __v[0] = __x; __v[1] = __y; __v[2] = __z; __v[3] = __u; }
#define color4Set(__c, __r, __g, __b, __a) { vec4Set(__c, __r, __g, __b, __a) }
#define color4SetC(__cDst, __cSrc) { color4Set(__cDst, __cSrc[0], __cSrc[1], __cSrc[2], __cSrc[3]); }

typedef struct gVertex
{
    vec3_t xyz;
    vec2_t st;
    color4_t rgba;
} gVertex_t;

static gVertex_t vertices[kVertexCount];
static gVertex_t vertex;
static GLenum currentPrimitive = GL_TRIANGLES;
static uint32_t vertexCount = 0;

#ifdef __cplusplus
extern "C" {
#endif

    void gGlBegin(GLenum prim);

    void gGlVertex3f(float x, float y, float z);

    void gGlColor4f(float r, float g, float b, float a);

    void gGlTexCoord2f(float s, float t);

    void gGlEnd();

    void gGlError(const char *source);
    
#ifdef __cplusplus
}
#endif

#endif