#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STARTING_VALUE 0.5 // use this as the initial x_{0}

double pDoublePrime(double x);
double qDoublePrime(double x);
double fDoublePrime(double x);

// Implement necessary function prototypes

int main(void){
	double critical_value = newtonsMethod(STARTING_VALUE, pow(2,20));
	
	printf("c = %.32lf", critical_value);
	
	return 0;
}

double pDoublePrime(double x) {
	// p''(x) = 2x^3+12x^2+24x-8
	double degree_3, degree_2, degree_1, result;
	degree_3 = degree_2 = degree_1 = 0;
	
	degree_3 = 2 * pow(x, 3);
	degree_2 = 12 * pow(x, 2);
	degree_1 = 24 * x;
	
	result = degree_3 + degree_2 + degree_1 - 8;
	
	return result;
}

double qDoublePrime(double x) {
	// q''(x) = (x+2)^3
	double result = pow((x + 2), 3);
	
	return result;
}

double fDoublePrime(double x) {
	// f''(x) = \frac{2x^3+12x^2+24x-8}{(x+2)^3}
	return pDoublePrime(x)/qDoublePrime(x);
}

// Implement necessary function definitions
