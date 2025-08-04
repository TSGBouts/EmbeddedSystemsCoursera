#include <stdio.h>
#include "stats.h"

int main(){
	unsigned char data[] = {0, 2, 1, 5};
	unsigned char *arr = data;
	unsigned int length = 4; 
	print_statistics(arr, length);
	sort_array(arr, length);
	printf("Sorted array: ");
	for (int i = 0; i < length; i++) printf("%d ", arr[i]);
	return 0;
}

void print_statistics(unsigned char* arr, unsigned int length){
	printf("Median is: %d \n", find_median(arr, length));
	printf("Maximum is: %d \n", find_maximum(arr, length));
	printf("Mean is: %.2f \n", find_mean(arr, length));
	printf("Minimum is: %d \n", find_minimum(arr, length));
}

void print_array(unsigned char* arr, unsigned int length){
	for (int i = 0; i < length; i++) printf("%u ", arr[i]);
}

int find_median(unsigned char* arr, unsigned int length){
	if (length % 2 == 1) return arr[length / 2];
	else return (arr[length/2] + arr[length/2 - 1]) / 2;
}

float find_mean(unsigned char* arr, unsigned int length){
	int sum = 0;
	for (int i = 0; i < length; i++) sum += arr[i];
	return sum/length;
}

int find_maximum(unsigned char* arr, unsigned int length){
	int max = 0;
	for (int i = 0; i < length; i++){
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

int find_minimum(unsigned char* arr, unsigned int length){
	int min = 0;
	for (int i = 0; i < length; i++){
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

void sort_array(unsigned char* arr, unsigned int length){
	for (int i = 0; i < length - 1; ++i){
		for (int j = 0; j < length - i - 1; ++j){
			if (arr[j] < arr[j + 1]){
				unsigned char temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
