// sort multidimensional array

#include <stdio.h>

// Used bubble sort
void sort(char arr[][10], int len) {
	void swap(char arr[][10], int idx1, int idx2);

	for (int i = 0; i < len-1; i++) {
		for (int j = i + 1; j < len; j++) {
			int k = 0;
			while (1) {
				if (arr[i][k] > arr[j][k]) {
					swap(arr, i, j);
					break;
				}
				else {
					break;
				}
				if (arr[i][k] == '\0') {
					if (arr[j][k] != '\0') {
						swap(arr, i, j);
						break;
					}
					else {
						break;
					}
				}
				k++;
			}
		}
	}
}

void swap(char arr[][10], int idx1, int idx2) {
	char temp[10];
	int i = 0;

	do {
		temp[i] = arr[idx1][i];
	} while (arr[idx1][i++] != '\0');
	
	i = 0;
	do {
		arr[idx1][i] = arr[idx2][i];
	} while (arr[idx2][i++] != '\0');
	
	i = 0;
	do {
		arr[idx2][i] = temp[i];
	} while (temp[i++] != '\0');
}

#define ELEMENTS 7
#define NAMELEN 10

int main(void) {
	char array[ELEMENTS][NAMELEN] = {"kim", "lee", "park", "choi", "jung", "kang", "cho"};

	printf("Original array: [ ");
	for (int i = 0; i < ELEMENTS; i++) {
		printf("%s ", array[i]);
	}
	printf("]\n");

	sort(array, ELEMENTS);

	printf("Sorted array: [ ");
	for (int i = 0; i < ELEMENTS; i++) {
		printf("%s ", array[i]);
	}
	printf("]\n");

	return 0;
}
