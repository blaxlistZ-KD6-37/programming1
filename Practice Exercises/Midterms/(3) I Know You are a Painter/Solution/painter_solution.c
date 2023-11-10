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
	int j, k;
	j = k = 0;
	
	if(height <= 2) {
		printf("Height must be greater than 2.");
	} else {
	    for(j = 1; j <= height; j++) {
	        for(k = 1; k <= j; k++) {
	            if(j <= height - (k - 1)) {
	            	printf("*");
	            } else {
	            	printf("");
	            }
	        }
	        if(j <= height - 1){
	        	printf("\n");
			}
	    }	
	}
}
