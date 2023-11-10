#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/****************************************************************
 * Hint:
 * - Use the distance formula
 *
 * \begin{equation}
 * 	\begin{split}
 *		d &= \sqrt{(x_{2}-x_{1})^{2} + (y_{2}-y_{1})^{2}}
 *	\end{split}
 * \end{equation}
****************************************************************/

double distance(int x_1, int x_2, int y_1, int y_2);

int main(void) {
	int x_1, x_2, y_1, y_2;
	double r_1, r_2, d;
	
	printf("Enter the point coordinates (x,y) of the first circle: ");
	scanf("%d %d", &x_1, &y_1);
	
	printf("Enter the radius of the first circle: ");
	scanf("%lf", &r_1);
	
	printf("\n");
	
	printf("Enter the point coordinates (x,y) of the second circle: ");
	scanf("%d %d", &x_2, &y_2);
	
	printf("Enter the radius of the second circle: ");
	scanf("%lf", &r_2);
	
	printf("\n");
	
	
	d = distance(x_1, x_2, y_1, y_2);
	
	printf("Do both the first and second radius of the cell towers intersects? ");
	
	(d <= (r_1 + r_2)) ? printf("YES") : printf("NO");
}

double distance(int x_1, int x_2, int y_1, int y_2) {
	return sqrt(pow((x_2-x_1), 2) + pow((y_2-y_1), 2));
}
