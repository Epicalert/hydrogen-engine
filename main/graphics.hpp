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

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <GL/glew.h>

//initializes the graphics library
void hInitGraphics();
//cleans up the graphics library
void hCleanupGraphics();

//prepares buffers and enables them
void hPrepareBuffers();
//loads a shader and returns its id
int hLoadShader(const char* filename);

//loads a text file and returns its contents
std::string hLoadTextFile(std::string filename);

#endif