/* 
CPSC 102 
Project 4 Basic Ray Tracer in C++
Name: Caroline Bryant
*/

#ifndef LIGHT_H
#define LIGHT_H

class LIGHT {

	VECTOR source;

public:
	
	LIGHT() {};

	LIGHT(VECTOR loc) {
	
		this->source = loc;
	}

	COLOR_T lighting (VECTOR intersect_pt, VECTOR normal, COLOR_T obj_color, RAY_T ray);

};

#endif
