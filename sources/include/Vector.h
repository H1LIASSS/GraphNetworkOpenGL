#pragma once

#include "glad/glad.h"


class Vector {
public:
	GLfloat x=0, y=0, z=0;
	Vector() {
		x = 0, y = 0, z = 0;
	}
	Vector(GLfloat _x, GLfloat _y, GLfloat _z) {
		x = _x, y = _y, z = _z;
	}

};