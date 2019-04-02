#include <stdio.h>

int data[10] = { 1, 10, 9, 6, 7, 3, 4, 8, 5, 2 };
int number = 10;
//퀵 정렬
void quick(int *data, int start, int end) {
	if (start >= end) {
		return;
	}
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (data[i] >= data[key]) {
			i++;
		}
		while (data[j] <= data[key] && j > start) {
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}

		quick(data, start, j - 1);
		quick(data, j + 1, end);
	}
}

int main(void) {
	int i, j, temp, min, index;
	/* 버블 정렬
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9-i; j++) {
			if (data[j] < data[j+1]) {
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	*/
	/* 삽입 정렬
	for (i = 0; i < 10; i++) {
		min = -1;
		for (j = i; j < 10; j++) {
			if (min < data[j]) {
				min = data[j];
				index = j;
			}
		}
		temp = data[i];
		data[i] = data[index];
		data[index] = temp;
	}
	*/
	quick(data, 0, number - 1);
	for (i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	putchar('\n');
	return 0;
}
