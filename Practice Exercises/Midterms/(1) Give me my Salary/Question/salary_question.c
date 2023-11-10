#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WEEKLY_HOUR 40

// Function Prototypes
void inputICEBOX(int category, double total_hour);
void displayRateCategory(int category, const double rate[]);

/*******************************************************************
* overtimeHour() calculates the overtime hours based on a comparison
* between the total hours and the weekly limit.  
*
* Think about:
* - How to compare total hours and the limit
* - What to return if overtime is worked vs not
********************************************************************/
double overtimeHour(double total_hour);

/******************************************************************* 
* totalPay() calculates the total pay based on:
* - The category rate from the rate[] array
* - The total hours worked
* - Any overtime hours calculated previously  
* - Overtime pay rate is 0.5x the category rate
*
* Think about:
* - How to get the category rate from the array
* - How to calculate regular pay and overtime pay
* - How to combine them for the total pay
********************************************************************/
double totalPay(int category, const double rate[], double total_hour, double overtime_hour);

int main(void) {
    printf("Welcome to ICEBOX\n");
    
    const double category_rate[] = {100, 170.40, 406.92};
    int category = 0;
	double total_hours = 0;

	do{
    	printf("\nCategory contains from 1 - 3 only\n");
		printf("Enter category: "); 
		scanf("%d", &category);
		
		do{
			printf("Enter total hours worked: "); 
			scanf("%lf", &total_hours);
		}while(total_hours > 1920 || total_hours < 0);
	}while(category < 1 || category > 3);

	displayRateCategory(category, category_rate);
	
	// Implement your code here
    
	return 0;
}

// Function Definitions
void displayRateCategory(int category, const double rate[]){
    switch(category){
        case 1 : 
			printf("RATE: Php %.2lf per hour\n", rate[0]); 
		break;
		
        case 2 : 
			printf("RATE: Php %.2lf per hour\n", rate[1]); 
		break;
		
        case 3 : 
			printf("RATE: Php %.2lf per hour\n", rate[2]); 
		break;
		
        default : 
			printf("Please enter category 1 - 3 only\n"); 
		break;
    }
}

// Implement your function definition here

double overtimeHour(double total_hour) {
	// Implement overtime calculation here
}

double totalPay(int category, const double rate[], double total_hour, double overtime_hour) {
	// Implement pay calculation here
}
