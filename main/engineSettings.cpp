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

#include <string.h>
#include <iostream>

#include "engineSettings.hpp"
#include "../thirdparty/inih/ini.h"

EngineSettings::EngineSettings(){}
EngineSettings::~EngineSettings(){}

static int iniSettingsCallback(void* user, const char* section, const char* name, const char* value)
{
    EngineSettings* target = (EngineSettings*) user;

    #define NAMEIS(n) strcmp(name, n) == 0

    if(NAMEIS("product_title"))
    {
        target->productTitle = value;
        std::cout << value << std::endl;
    }
    else if (NAMEIS("resolution_x"))
    {
        target->resolutionX = std::stoi(value);
    }
    else if (NAMEIS("resolution_y"))
    {
        target->resolutionY = std::stoi(value);
    }

    std::cout << "loading" << std::endl;
}

bool EngineSettings::LoadFromFile(const char* filename)
{
    //TODO: load enginesettings from config file
    ini_parse(filename, iniSettingsCallback, this);

    std::cout << productTitle << std::endl;

    return false;
}