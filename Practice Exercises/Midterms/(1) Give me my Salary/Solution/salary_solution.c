#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WEEKLY_HOUR 40

// Function Prototypes
void inputICEBOX(int category, double total_hour);

void displayRateCategory(int category, const double rate[]);

double overtimeHour(double total_hour);
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

    printf("\nICEBOX Payslip\n");
    printf("CATEGORY: Level %d\n", category);
    printf("TOTAL HOURS WORKED: %.2lf\n", total_hours);
    
    double overtime_hours = overtimeHour(total_hours);
    printf("OVERTIME HOURS: %.2lf\n", overtime_hours);
    
    double total_pay = totalPay(category, category_rate, total_hours, overtime_hours);
    printf("TOTAL PAY: Php %.2lf", total_pay);
    
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

double overtimeHour(double total_hour) {
	double overtime_hour = 0;
	
	if(total_hour > WEEKLY_HOUR) {
		overtime_hour = total_hour - WEEKLY_HOUR;
	}
	return overtime_hour;
}

double totalPay(int category, const double rate[], double total_hour, double overtime_hour) {
	double payoff = total_hour + (overtime_hour * 0.5), total_pay = 0;
	
    switch(category){
        case 1 : 
        	total_pay = payoff * rate[0];
        break;
        
        case 2 : 
        	total_pay = payoff * rate[1];
		break;	
		
        case 3 : 
        	total_pay = payoff * rate[2];
		break;
		default :
			printf("ERROR!\n");
		break;
    }
    
    return total_pay;
}
