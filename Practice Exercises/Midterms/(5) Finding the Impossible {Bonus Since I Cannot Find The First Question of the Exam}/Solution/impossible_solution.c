#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STARTING_VALUE 0.5

double pDoublePrime(double x);
double qDoublePrime(double x);
double fDoublePrime(double x);

double pTriplePrime(double x);
double qTriplePrime(double x);
double fTriplePrime(double x);

double newtonsMethod(double x, int iteration);

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

double pTriplePrime(double x) {
	// p^{(3)}(x) = 72
	return 72; 
}

double qTriplePrime(double x) {
	// p^{(3)}(x) = (x+2)^4
	return pow((x + 2), 4);
}

double fTriplePrime(double x) {
	// f^{(3)}(x) = \frac{72}{(x+2)^4}
	return pTriplePrime(x)/qTriplePrime(x);
}

double newtonsMethod(double x, int iteration) {
	int j = 0;
	double x_a = 0, x_b = x;
	
	for(j = 0; j < iteration; j++) {
		// x_{n+1} = x_{n} - \frac{f(x)}{f'(x)}
		x_a = x_b - (fDoublePrime(x_b) / fTriplePrime(x_b));
		
		// Stores x_a to x_b meaning:
		// x_{n+2} = x_{n+1}
		// x_{n+3} = x_{n+2} 
		// ... 
		// x_{n+m} = x_{n+(m-1)}
		x_b = x_a;
	}
	
	return x_b;
}
