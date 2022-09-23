// sum and average of row and column, total sum and average of a[]

#include <stdio.h>

int main(void) {
	double a[][5] = {{1.0,  2.0,  3.0,  4.0,  5.0},
			 {6.0,  7.0,  8.0,  9.0,  10.0},
			 {11.0, 12.0, 13.0, 14.0, 15.0},
			 {16.0, 17.0, 18.0, 19.0, 20.0},
			 {21.0, 22.0, 23.0, 24.0, 25.0}};
	double sum_row[5], sum_col[5];
	double avr_row[5], avr_col[5];
	double ttl_sum = 0, ttl_avr = 0;

	for (int i = 0; i < 5; i++) {
		sum_row[i] = 0.0;
		sum_col[i] = 0.0;
		for (int j = 0; j < 5; j++) {
			sum_row[i] += a[i][j];
			sum_col[i] += a[j][i];
		}
	}

	for (int i = 0; i < 5; i++) {
		avr_row[i] = sum_row[i] / 5;
		avr_col[i] = sum_col[i] / 5;
	}

	for (int i = 0; i < 5; i++) {
		ttl_sum += sum_row[i];
	}
	
	ttl_avr = ttl_sum / 25;

	// Print
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%6.2lf ", a[i][j]);
		}
		printf("%6.2lf %6.2lf\n", sum_row[i], avr_row[i]);
	}
	printf("\n");
	
	
	for (int i = 0; i < 5; i++) {
		printf("%6.2lf ", sum_col[i]);
	}
	printf("%6.2lf\n", ttl_sum);

	for (int i = 0; i < 5; i++) {
		printf("%6.2lf ", avr_col[i]);
	}
	printf("       %6.2lf\n", ttl_avr);


	return 0;
}
