/*
   Hydrogen Engine
       https://github.com/Epicalert/hydrogen-engine

   Copyright 2019 Amado Wilkins

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

 
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <ios>

#include <glm/common.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "graphics.hpp"

const int vboCount = 1;
GLuint vbo[vboCount];
GLuint vao[1];

glm::mat4 modelViewProjection;

const GLfloat testTri[3][3] = 
{
    {0.0, 0.0, 0.0},
    {0.5, 1.0, 0.0},
    {1.0, 0.0, 0.0}
};
int shaderId = -1;

void hInitGraphics()
{
    glGenBuffers(vboCount, vbo);

    glGenVertexArrays(1, vao);

    hPrepareBuffers();

    shaderId = hLoadShader("white-unlit");
    glBindAttribLocation(shaderId, 0, "in_Position");
    glUseProgram(shaderId);
}

void hCleanupGraphics()
{
    glDisableVertexAttribArray(0);

    glDeleteBuffers(1, vbo);
    glDeleteVertexArrays(1, vao);
}


void hPrepareBuffers()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, (3*3) * sizeof(GLfloat), testTri, GL_STATIC_DRAW);

    const int attribIndexPosition = 0;

    glVertexAttribPointer(attribIndexPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(attribIndexPosition);
}

void hCheckShader(int obj)
{
    GLint status = GL_FALSE;
    
    if(glIsShader(obj)) 
    {
        glGetShaderiv(obj, GL_COMPILE_STATUS, &status);
    }
    if(glIsProgram(obj)) 
    {
        glGetProgramiv(obj, GL_LINK_STATUS, &status);
    }

    if(status == GL_TRUE) return;
    
    GLchar log[ 1 << 15 ] = { 0 };
    
    if(glIsShader(obj))
    {
        glGetShaderInfoLog( obj, sizeof(log), NULL, log );
    }
    if(glIsProgram(obj))
    {
        glGetProgramInfoLog( obj, sizeof(log), NULL, log );
    }

    std::cerr << "Shader failed to compile!" << std::endl << log << std::endl;
}

int hLoadShader(const char* filename)
{
    //load file data
    std::string fnameString = std::string(filename);

    std::string vertCode = hLoadTextFile("res/" + fnameString + "-vert.glsl");
    std::string fragCode = hLoadTextFile("res/" + fnameString + "-frag.glsl");

    char* vertSrc = const_cast<char*>(vertCode.c_str());
    char* fragSrc = const_cast<char*>(fragCode.c_str());

    int vertLength = vertCode.length();
    int fragLength = fragCode.length();

    //compile and pass to gpu
    int vertShaderId = glCreateShader(GL_VERTEX_SHADER);
    int fragShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertShaderId, 1, &vertSrc, &vertLength);
    glShaderSource(fragShaderId, 1, &fragSrc, &fragLength);

    glCompileShader(vertShaderId);
    glCompileShader(fragShaderId);

    //link shaders into one shader program
    int loadedShaderId = glCreateProgram();

    glAttachShader(loadedShaderId, vertShaderId);
    glAttachShader(loadedShaderId, fragShaderId);

    glLinkProgram(loadedShaderId);

    hCheckShader(vertShaderId);
    hCheckShader(fragShaderId);
    hCheckShader(loadedShaderId);

    //return the shader program's id
    return loadedShaderId;
}

std::string hLoadTextFile(std::string filename)
{
    std::cout << "Loading " << filename << std::endl;

    std::ifstream stream(filename);

    if(!stream)
    {
        std::cout << "ERROR: Load failed." << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << stream.rdbuf();

    std::string contents = buffer.str();

    return contents;
}

void hCalculateMVP(float aspectRatio, glm::vec3 cameraPos, glm::vec3 cameraLook)
{
    glm::mat4 model = glm::translate(glm::mat4(1),  glm::vec3(0,0,0) );
 
    glm::mat4 view = glm::lookAt
    (
        cameraPos,    //camera position
        cameraPos + cameraLook,     //look target position
        glm::vec3(0, 1, 0)      //up vector
    );

    glm::mat4 projection = glm::perspective
    (
        70.0f,              //fov
        aspectRatio,      //aspect ratio
        0.1f,               //near clip
        100.0f              //far clip
    );
 
    modelViewProjection = projection * view * model;

    int mvpId = glGetUniformLocation(shaderId, "mvpMatrix");
    glUniformMatrix4fv(mvpId, 1, GL_FALSE, &modelViewProjection[0][0]);
}
