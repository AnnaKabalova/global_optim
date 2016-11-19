#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "global.h"

int main() {
	int N; 
	double E;
	double M;
	double m;
	double r;
	printf("input r \n");
	scanf("%lf", &r);
	printf("input N \n");
	scanf("%i", &N);
	double e = 0.0000001;
	int i = 1;
	double a = -10;
	double b = 10;
	list head(a);
	head.add(a, b);
	while (i < N) {
		head.insert(r, e);
	
	
	}
	//list tail(b,r);
	//list A(a);
	//list B(b, r);
 	head.print();
	//	node *A = createlist(a);
	//node *B = CreateEndList(b, r);


	

	return 0;

}