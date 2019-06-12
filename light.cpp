/* 
CPSC 102 
Project 4 Basic Ray Tracer in C++
Name: Caroline Bryant
*/

#include <math.h>
#include "ray.h"
#include "vector.h"
#include "light.h"

using namespace std;

COLOR_T LIGHT :: lighting (VECTOR intersect_pt, VECTOR normal, COLOR_T obj_color, RAY_T ray) {

	VECTOR L;
	COLOR_T new_color;
	double result, prod;

	// adds ambient light
	new_color.r = (0.1 * obj_color.r);
	new_color.g = (0.1 * obj_color.g);
	new_color.b = (0.1 * obj_color.b);

	// calculates diffuse lighting
	L = this->source - intersect_pt;
	
	// normalize vector L
	L = L.normalize();

	// result holds dot product of the normal line and the light vector
	result = normal.dot_product(L);

	// if dot product is less than zero, add ambient and diffuse lighting together
	if (result > 0) {


		new_color.r += (result * obj_color.r); 
		new_color.g += (result * obj_color.g); 
		new_color.b += (result * obj_color.b); 

		// structure to hold vector R
		VECTOR R;  
	
		// calculates specular lighting
		R = L.calc(normal, result);

		// normalize vector R
		R = R.normalize();

		// prod holds dot product of vector R and the ray direction 
		prod = R.dot_product(ray.dir);

		// if dot product is less than zero, adds specular lighting  
		if (prod > 0) {

			new_color.r += pow(prod, 100);
 			new_color.g += pow(prod, 100);
			new_color.b += pow(prod, 100);	

		} // if (prod > 0) 

	} // if (result > 0)

return new_color;
}   


