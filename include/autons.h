#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

//autos
void FarSideSafe();
void CloseSideSafe();
void CloseSideRushQual();
void CloseSideRushElim();
void pidTest();