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
	double e = 0.0000000001;
	int i = 1;
	double a = -2;
	double b = 10;
	list A(a);
	
	A.addtail(a, b, r);
	A.print();
	printf(" \n");
	printf(" \n");
	bool flag = true;
	while (i < N) {
	flag = A.insert(r, e);
	A.print();
	printf(" \n");
	printf(" \n");
	if (flag == true)
	i++;
	else break;
	}
	A.searchmin();
	return 0;

}