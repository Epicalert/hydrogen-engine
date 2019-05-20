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

#include "engineSettings.hpp"

EngineSettings::EngineSettings(){}
EngineSettings::~EngineSettings(){}

bool EngineSettings::LoadFromFile()
{
    //TODO: load enginesettings from config file
    return false;
}


const char* EngineSettings::GetTitle()
{
    return productTitle;
}

int EngineSettings::GetResX()
{
    return resolutionX;
}

int EngineSettings::GetResY()
{
    return resolutionY;
}