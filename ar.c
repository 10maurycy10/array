#include <time.h>
#include <stdlib.h>

int sumarray(int* array) {
	volatile int sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += array[i];
	}
	return sum;
}

void main() {
	int* array = (int*)malloc(sizeof(int) * 10000);
	for (int i = 0; i < 10000; i++) {
		array[i] = i;
	}
	time_t before, after;
	before = clock();
	for (int i = 0; i < 10000; i++) {
		sumarray(array);
	}
	after = clock();
	free(array);
	 printf("%d %d\n",after - before,CLOCKS_PER_SEC);
}
