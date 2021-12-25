#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct node {
	int val[10];
	struct node* next;
};

// initlize a linked list of 10000 reveres consecutive initegers
struct node* initll() {
	// initalize the final node to null
	struct node* cnode = (struct node*)0;
	for (int i = 0; i < 10000; i++) {
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->next = cnode;
		newnode->val[0] = i+1;
		cnode = newnode;
	}
}

// dealocate a linked list, but wont free data (safe to call on null)
void dropll(struct node* cnode) {
	while (cnode) {
		struct node* next = cnode->next;
		free(cnode);
		cnode = next;
	}
}

int sumll(struct node* cnode) {
	volatile int sum = 0;
	while (cnode) {
		sum += cnode->val[0];
		cnode = cnode->next;
	}
	return sum;
}

int main() {
	struct node* ll = initll();
	time_t before, after;
	before = clock();
	for (int i = 0; i<10000; i++) {
		sumll(ll);
	}
	after = clock();
	printf("%d %d\n",after - before,CLOCKS_PER_SEC);
	dropll(ll);
	return 1;
}
