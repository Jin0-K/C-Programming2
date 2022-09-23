// quick sort

#include <stdio.h>

// sort the array from the smallest to the largest
void qsort(double v[], int left, int right) {
	int i, last;
	void swap(double v[], int i, int j);

	// do nothing if array contains  fewer than two elements
	if (left >= right) {
		return;
	}
	// move partition element
	swap(v, left, (left + right) / 2);
	last = left; 
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left]) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last -1);
	qsort(v, last + 1, right);
}

void swap(double v[], int i, int j) {
	double temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;	
}


#define ELEMENTS 10

int main(void) {
	double array[] = {1.1, 9.9, 2.2, 8.8, 3.3, 7.7, 4.4, 6.6, 5.5, 0.0};

	// print out array[]
	printf("[ ");
	for (int i = 0; i < (sizeof(array)/sizeof(double)); i++) {
		printf("%.1f ", array[i]);
	}
	printf("] ");
	printf("\n");
	
	qsort(array, 0, 9);

	// ptint out array[]
	printf("[ ");
	for (int i = 0; i < (sizeof(array)/sizeof(double)); i++) {
		printf("%.1f ", array[i]);
	}
	printf("] ");
	printf("\n");
	
	
	return 0;
}
