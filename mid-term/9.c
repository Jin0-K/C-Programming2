// command-line argument
// Lexicographic comparison

#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
	char arr[argc][20];

	for (int i = 0; i < argc; i++) { // copy argv to arr
		for (int j = 0; argv[i][j] != '\0'; j++) {
			arr[i][j] = argv[i][j];
			arr[i][j+1] = '\0';
		}
	}

	for (int i = 1; i < argc; i++) {
		for (int j = i + 1; j < argc; j++) {
			if (strcmp(arr[i], arr[j]) > 0) {
				char temp[20];

				for (int k = 0; arr[i][k] != '\0'; k++) {
				       temp[k] = arr[i][k];
				       temp[k+1] = '\0';
				}

				for (int k = 0; arr[j][k] != '\0'; k++) {
					arr[i][k] = arr[j][k];
					arr[i][k+1] = '\0';
				}
				for (int k = 0; temp[k] != '\0'; k++) {
					arr[j][k] = temp[k];
					arr[j][k+1] = '\0';
				}
			}
		}
	}

	printf("\n");
	for (int i = 1; i < argc; i++) {
		printf("%s\n", arr[i]);
	}

	return 0;
}
