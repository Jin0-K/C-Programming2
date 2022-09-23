// Celsius to Fahrenheit transformation
// -20 to 40 (step 5)
// Celsius is int, Fahrenheit is float

#include <stdio.h>

int main(void){
	int celsius;
	float fahr;
	int lower, upper, step;

	lower = -20;
	upper = 40;
	step = 5;

	celsius = lower;

	printf("Celsius\tFahrenheit\n");
	while (celsius <= upper) {
		// celsius = 5 * (fahr - 32) / 9;
		fahr = celsius * 9 / 5 + 32;
		printf("%d\t%.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}
