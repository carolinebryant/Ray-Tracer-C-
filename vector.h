/* 
CPSC 102 
Project 4 Basic Ray Tracer in C++
Name: Caroline Bryant
*/

#ifndef VECTOR_H
#define VECTOR_H

class VECTOR {
	double x, y, z;

public:
	VECTOR () {};

	VECTOR (double x, double y, double z) {
		this -> x = x;
		this -> y = y;
		this -> z = z;
	}

	VECTOR set (double x, double y, double z) {
		this -> x = x;
		this -> y = y;
		this -> z = z;

	return *this;
	}

	VECTOR normalize (void);

	VECTOR add (VECTOR v2);
	VECTOR operator+ (VECTOR v2);

	VECTOR subtract (VECTOR v2);
	VECTOR operator- (VECTOR v2);

	VECTOR multiply (VECTOR v2);
	VECTOR operator* (VECTOR v2);

	VECTOR scalar_mult (double s);
	VECTOR operator* (double s);

	VECTOR scalar_divide (double s);
	VECTOR operator/ (double s);

	double dot_product (VECTOR v2);

	double length (void);

	double access (VECTOR v2, VECTOR v3);
	double access (VECTOR v2, double v3);

	VECTOR calc (VECTOR v2, double v3);

};

#endif

