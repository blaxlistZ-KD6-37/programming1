#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Base Case:
	Odd_Height {
		*
		**
		*
	}

	Even_Height {
		*
		**
		**
		*
	}

*/

// Function Prototype
void canvasPaint(int height);

int main(void) {
	int height = 0;
	
    printf("Input height: "); scanf("%d", &height);
    
    canvasPaint(height);

    return 0;
}

void canvasPaint(int height){
	// Input function logic here
}
