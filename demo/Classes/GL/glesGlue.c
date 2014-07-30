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

#include "glesGlue.h"

void gGlBegin(GLenum prim)
{
    currentPrimitive = prim;
    vertexCount = 0;
    glVertexPointer(3, GL_FLOAT, sizeof(gVertex_t), vertices[0].xyz);
    glTexCoordPointer(2, GL_FLOAT, sizeof(gVertex_t), vertices[0].st);
    glColorPointer(4, GL_FLOAT, sizeof(gVertex_t), vertices[0].rgba);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}


void gGlVertex3f(float x, float y, float z)
{
    if (vertexCount > kVertexCount) return;
    vec3Set(vertex.xyz, x, y, z);
    vertices[vertexCount] = vertex;
    vertexCount++;
}


void gGlColor4f(float r, float g, float b, float a)
{
    color4Set(vertex.rgba, r, g, b, a);
}


void gGlTexCoord2f(float s, float t)
{
    vec2Set(vertex.st, s, t);
}


void gGlEnd()
{
    if (vertexCount == 0)
    {
        currentPrimitive = 0;
        return;
    }
    glDrawArrays(currentPrimitive, 0, vertexCount);
    vertexCount = 0;
    currentPrimitive = 0;
}


void gGlError(const char *source) {}
