// Use qsort to sort the input strings
// sort in numeric order when "-n" is in option


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 10000



void swap(char arr[][10], int idx1, int idx2) {
        char temp[10];
        int i;

        for (i = 0; arr[idx1][i] != '\0'; i++) {
                temp[i] = arr[idx1][i];
                temp[i+1] = '\0';
        }
        for (i = 0; arr[idx2][i] != '\0'; i++) {
                arr[idx1][i] = arr[idx2][i];
                arr[idx1][i+1] = '\0';
        }
        for (i = 0; temp[i] != '\0'; i++) {
                arr[idx2][i] = temp[i];
                arr[idx2][i+1] = '\0';
        }
}

/*
void Qsort(char arr[][10], int left, int right) {
        int i, j;

        void swap(char arr[][10], int idx1, int idx2);

        if (left >= right) {
                return;
                                                                                                                    1,9        꼭대기

