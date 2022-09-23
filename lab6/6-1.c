// The distance between pt1 and pt2
// The rectangular area made by pt1 and pt2

#include <math.h>
#include <stdio.h>

// return absolute value of the number
int absolute(int n1) {
	if (n1 >= 0) {
		return n1;
	}
	else {
		return -n1;
	}
}

int main(void) {
	struct point {
		int x;
		int y;
	};
	struct point pt1 = { 10, 20 };
	struct point pt2 = { 30, 40 };

	//find distance between pt1 and pt2
	double dist = sqrt(pow((pt1.x - pt2.x), 2) + pow((pt1.y - pt2.y), 2));
	printf("distance : %.2lf\n", dist);

	//find area of rectangle made by pt1 and pt2
	int x_dis = absolute(pt1.x - pt2.x);
	int y_dis = absolute(pt1.y - pt2.y);

	printf("The area of rectangle : %d\n", x_dis * y_dis);
	
	return 0;
}
