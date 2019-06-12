/* 
CPSC 102 
Project 4 Basic Ray Tracer in C++
Name: Caroline Bryant
*/

#include <math.h>
#include "vector.h"
#include "ray.h"

using namespace std;

// normalize vector function, divide each vector by its length
VECTOR VECTOR :: normalize (void) {

	double len;
	len = sqrt((x*x) + (y*y) + (z*z));

	x /= len;
	y /= len;
	z /= len;

	return *this;
}

// computes dot product, multiply each component of the normal vector by the light vector
double VECTOR :: dot_product (VECTOR v2) {

	double result;
	result = ((x*v2.x) + (y*v2.y) + (z*v2.z));

	return result;
}

VECTOR VECTOR :: add (VECTOR v2) {

	VECTOR v3;

	v3.x = x + v2.x;
	v3.y = y + v2.y;
	v3.z = z + v2.z;

	return v3;
}

VECTOR VECTOR :: operator+ (VECTOR v2) {

	return (this-> add(v2));
}

VECTOR VECTOR :: subtract(VECTOR v2) {

	VECTOR v3;
	
	v3.x = x - v2.x;
	v3.y = y - v2.y;
	v3.z = z - v2.z;

	return v3;
}

VECTOR VECTOR :: operator- (VECTOR v2) {

	return (this-> subtract(v2));
}

VECTOR VECTOR :: multiply (VECTOR v2) {

	VECTOR v3;

	v3.x = x * v2.x;
	v3.y = y * v2.y;
	v3.z = z * v2.z;

	return v3;
}

VECTOR VECTOR :: operator* (VECTOR v2) {

	return (this-> multiply(v2));
}

VECTOR VECTOR :: scalar_mult(double s) {

	VECTOR v3;

	v3.x = x * s;
	v3.y = y * s;
	v3.z = z * s;

	return v3;
}

VECTOR VECTOR :: operator* (double s) {

	return (this-> scalar_mult(s));
}

VECTOR VECTOR :: scalar_divide (double s) {

	VECTOR v3;

	v3.x = x / s;
	v3.y = y / s;
	v3.z = z / s;

	return v3;
}
	
VECTOR VECTOR :: operator/ (double s) {

	return (this-> scalar_divide(s));
}

double VECTOR :: length (void) {

	return sizeof(this);
}

double VECTOR :: access (VECTOR v2, VECTOR v3) {

	double pass; 
	pass = 2 * ((x * (v2.x - v3.x)) + (y * (v2.y - v3.y)) + (z * (v2.z - v3.z)));

	return pass;

}

double VECTOR :: access (VECTOR v2, double v3) {

	double pass;
	pass = (((x - v2.x) * (x - v2.x)) + ((y - v2.y) * (y - v2.y)) + ((z - v2.z) * (z - v2.z))) - (v3 * v3); 

	return pass;
}

VECTOR VECTOR :: calc (VECTOR v2, double v3) {

	VECTOR pass;
	pass.x = (x - (2 * v3 * v2.x)); 
	pass.y = (y - (2 * v3 * v2.y));
	pass.z = (z - (2 * v3 * v2.z));
		
	return pass;
} 

