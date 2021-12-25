#include <time.h>
#include <stdlib.h>

int sumarray(int* array) {
	volatile int sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += array[i*10];
	}
	return sum;
}

void main() {
	volatile int* array = (int*)malloc(sizeof(int) * 10000*10);
	for (int i = 0; i < 10000; i++) {
		array[i*10] = i;
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
