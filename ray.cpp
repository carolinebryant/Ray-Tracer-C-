/* 
CPSC 102 
Project 4 Basic Ray Tracer in C++
Name: Caroline Bryant
*/

#include <iostream>
#include <math.h>
#include "ray.h"
#include "vector.h"
#include "sphere.h"
#include "light.h"

using namespace std; 

int main () {

	VECTOR intersect_pt;
	VECTOR normal;

	// structure hold red color
	COLOR_T obj_color;
	obj_color.r = 1;
	obj_color.g = 0;
	obj_color.b = 0;

	// structure holds black color
	COLOR_T color;
	color.r = 0;
	color.g = 0;
	color.b = 0;
	
	// image dimensions
	int width = 500, height = 500;

	double x = 0, y = 0;
 
	RAY_T ray;

	unsigned char ppmr, ppmg, ppmb;

	// set up light
	VECTOR source(-10, 10 ,5);
	LIGHT light(source);

	// set up sphere
	VECTOR center(0, 0, 10);
	SPHERE sphere(center, 3.0);

	// ppm header 
	cout << "P6" << endl << width << " " << height << " " << "255" << endl;

	// for each pixel
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {

			// compute ray origin  
			ray.org.set(0, 0, 0);

			// compute ray direction 
			ray.dir.set(-0.5+(x/500.0), 0.5-(y/500.0), 1);

			// normalize ray direction 
			ray.dir = ray.dir.normalize();

			if (sphere.intersect_sph (ray, intersect_pt, normal) == true) {

				color = light.lighting (intersect_pt, normal, obj_color, ray);

				// caps r g b values at 1
				if (color.r > 1) {
					color.r = 1;
				}

				if (color.g > 1) {
					color.g = 1;
				}

				if (color.b > 1) {
					color.b = 1;
				}

				// converts double r g b values back to unsigned char to be printed
				ppmr = (unsigned char)(color.r*255);
				ppmg = (unsigned char)(color.g*255);
				ppmb = (unsigned char)(color.b*255);

				cout << ppmr << ppmg << ppmb;
			}

			// prints black background
			else { 

				cout << (unsigned char)(0*255) 
				     << (unsigned char)(0*255) 
				     << (unsigned char)(0*255);
			}


		} // end of inner for loop
	} // end of outer for loop


	return 0;
}


