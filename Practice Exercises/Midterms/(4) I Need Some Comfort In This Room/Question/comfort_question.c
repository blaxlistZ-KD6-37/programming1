#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LABOR_RATE 17.50
#define TAX_RATE 0.12

// Function Prototypes
int getArea(int l, int w);

/*******************************************************************************
 * The computeInstalledPrice() will calculate the installed price. The installed 
 * price is the cost of carpet and the cost of labor.
 */
float computeInstalledPrice(int length, int width, float price);

/*******************************************************************************
 * The computeSubtotal() will calculate the subtotal. Based on installed price
 * and the discount.
 */
float computeSubtotal(int length, int width, float carpetCost, int discount);

/*******************************************************************************
 * The computeTotal() will calculate the total. Based on installed price, the 
 * discount and added tax.
 */
float computeTotal(int length, int width, float carpetCost, int discount);

/*******************************************************************************
 * The printMeasurement() will display all the measurements base on format. The
 * length, width and area.
 */
void printMeasurement(int length, int width);

/*******************************************************************************
 * The printCharges() will display all charges base on format (see output for
 * charges).
 */
void printCharges(int length, int width, float carpetCost, int discount);

int main(void) {
  int room_length, room_width, customer_discount;
  float carpet_price;
  
  printf("%-42s ", "Enter length of room (feet):");
  scanf("%d", &room_length);
  printf("%-42s ", "Enter width of room (feet):");
  scanf("%d", &room_width);
  printf("%-42s ", "Enter customer discount (percentage):");
  scanf("%d", &customer_discount);
  printf("%-42s ", "Enter cost of carpet in square foot (Php):");
  scanf("%f", &carpet_price);
    
  // To do function call for printMeasurement()
  printMeasurement(room_length, room_width);
    
  // To do function call for printCharges()
  printCharges(room_length, room_width, carpet_price, customer_discount);

  printf("\n");

  // Implement your written program here
  
  return 0;
}

// Function Definitions
int getArea(int l, int w) {
  return l * w;
}

// Implement your function definitions here.

float computeInstalledPrice(int length, int width, float price) {
	// Implement computeInstalledPrice logic here
}

float computeSubtotal(int length, int width, float carpetCost, int discount) {
	// Implement computeSubtotal logic here
}

float computeTotal(int length, int width, float carpetCost, int discount) {
	// Implement computeTotal logic here
}

void printMeasurement(int length, int width) { 
	// Implement printMeasurement logic here
}

void printCharges(int length, int width, float carpetCost, int discount) {
	// Implement printCharges logic here
}

/**
 * NOTE: formatting guide
 * printf("%15sEND", "hello world");
 *     hello worldEND
 * ^^^^^^^^^^^^^^^^^^
 * hello world will allocate 15 character and it will appear as right justified
 * 
 * printf("%-15sEND", "hello world");
 * hello world    END
 * ^^^^^^^^^^^^^^^^^^
 * hello world will allocate 15 character and adding the negative(-) will appear 
 * as left justified
 * 
 * This applies to all format specifiers.
 */
