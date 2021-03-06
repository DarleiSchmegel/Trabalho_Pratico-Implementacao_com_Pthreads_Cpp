#include <stdio.h>
#include <malloc.h>
#include "pokeLib.h"

struct Atrib{
	int p;
	int c;
};

void * fibo (void* dta){
	int n = (int*) *dta;
	int *n1, *n2, *r = (int *) malloc (sizeof(int)), *r1, *r2;
	struct Atrib a1, a2;

	if (n<=2){
		*r = 1;
	}
	else{
		n1 = (int *) malloc (sizeof(int));
		n1 = n-1;
		a1.p = 0;
		a1.c = n1;
		t1 = spawn (&a1, fibo, (void*) n1);
		n2 = (int *) malloc (sizeof(int));
		n2 = n -2;
		a2.p = 0;
		a1.c = n2;
		t2 = spawn (&a2, fibo, (void*) n2);
		sync(t1, (void*) &r1);
		sync(t2, (void*) &r2);
		r = *r1 + *r2;
		free(r1);
		free(r2);
		free(n1);
		free(n2);
	}
	return r;
}

int main(){
	int n, *r, tId;
	struct Atrib a;
	n = 10;
	a.p = 0;
	a.c = n;
	tId = spawn (&a, fibo, &n);
	sync(tId, &r);

	printf("Fibonacci (%d) = %d \n", n, r); //Ponto de possível erro
	return 0;

}
