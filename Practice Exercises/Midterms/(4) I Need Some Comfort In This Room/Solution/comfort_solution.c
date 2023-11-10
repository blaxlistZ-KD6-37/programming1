#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LABOR_RATE 17.50
#define TAX_RATE 0.12

// Function Prototypes
int getArea(int l, int w);

float computeInstalledPrice(int length, int width, float price);
float computeSubtotal(int length, int width, float carpetCost, int discount);
float computeTotal(int length, int width, float carpetCost, int discount);

void printMeasurement(int length, int width);
void printCharges(int length, int width, float carpetCost, int discount);

int main(void) {
  int room_length = 0, room_width = 0, customer_discount = 0;
  float carpet_price = 0;
  
  printf("%-42s ", "Enter length of room (feet):");
  scanf("%d", &room_length);
  printf("%-42s ", "Enter width of room (feet):");
  scanf("%d", &room_width);
  printf("%-42s ", "Enter customer discount (percentage):");
  scanf("%d", &customer_discount);
  printf("%-42s ", "Enter cost of carpet in square foot (Php):");
  scanf("%f", &carpet_price);
    
  printMeasurement(room_length, room_width);
  printCharges(room_length, room_width, carpet_price, customer_discount);

  printf("\n");

  // Installed Prices
  float installed_prices = computeInstalledPrice(room_length, room_width, carpet_price);
  printf("%-28sPhp","INSTALLED PRICE");
  printf("%10.2f", installed_prices);
    
  printf("\n");
  printf("Discount");
  float customer_discount_percent = ((float) customer_discount / 100);
  float discounted_price = installed_prices * customer_discount_percent;
  printf("%17d%%%15.2f", customer_discount, discounted_price);
    
  printf("\n"); printf("%-28s-------------","");

  printf("\n");

  // Subtotal
  printf("%-28sPhp","SUBTOTAL");
  float sub_total = computeSubtotal(room_length, room_width, carpet_price, customer_discount);
  printf("%10.2f", sub_total);

  printf("\n");
  int tax_rate_whole = TAX_RATE * 100;
  printf("%-23s%d%%","Tax", tax_rate_whole);
  float sub_total_tax = computeSubtotal(room_length, room_width, carpet_price, customer_discount) * TAX_RATE;
  printf("%15.2f", sub_total_tax);

  printf("\n");

  // Total
  printf("%-28sPhp","TOTAL");
  float total = computeTotal(room_length, room_width, carpet_price, customer_discount);
  printf("%10.2f", total);
}

// Function definitions
int getArea(int l, int w) {
  return l * w;
}

float computeInstalledPrice(int length, int width, float price) {
    int room_area = getArea(length, width);
    int carpetCost = (LABOR_RATE * room_area) + (price * room_area);
    
    return carpetCost;
}

float computeSubtotal(int length, int width, float carpetCost, int discount) {
    float installed_price = computeInstalledPrice(length, width, carpetCost);
    float discount_percent = (float) discount / 100; // Typecasted into a float datatype
    float discounted_price = installed_price * discount_percent;
    
    return installed_price - discounted_price;
}

float computeTotal(int length, int width, float carpetCost, int discount) {
    float sub_total = computeSubtotal(length, width, carpetCost, discount);
    float sub_total_tax = sub_total * TAX_RATE;

    return sub_total + sub_total_tax; 
}

void printMeasurement(int length, int width) { 
    printf("\n");
    printf("MEASUREMENT");
    printf("\n");
    printf("%-15s%d","Length", length); 
    printf("%-2sfeet",""); printf("\n");
    printf("%-15s%d","Width", width);
    printf("%-2sfeet",""); printf("\n");
    printf("%-15s%d","Area", getArea(length, width));
    printf("%2ssquare feet",""); printf("\n");
}

void printCharges(int length, int width, float carpetCost, int discount) {
  printf("\n");
  printf("CHARGES"); printf("\n"); 
  printf("%-13sCOST/SQ.FT","DESCRIPTION");
  printf("%-5sCHARGE",""); printf("\n");
  printf("%-13s-------------","-----------"); printf("%-2s-------------","");
    
  printf("\n");  
    
  //Carpet
  printf("%-13sPhp","Carpet");
  printf("%10.2f", carpetCost);
  printf("%-2sPhp","");
  printf("%10.2f", carpetCost * getArea(length, width));

  printf("\n");
    
  //Labor
  printf("Labor");
  printf("%21.2f%15.2f", LABOR_RATE, LABOR_RATE * getArea(length, width));

  printf("\n"); printf("%-28s-------------","");
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
