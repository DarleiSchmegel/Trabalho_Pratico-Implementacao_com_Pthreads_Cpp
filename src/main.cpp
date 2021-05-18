#include <stdio.h>
#include <malloc.h>
#include "pokeLib.h"

void* fibo (void* dta){
  int* n = (int*) dta;
  int *r = (int *) malloc (sizeof(int));
  *r = (*n) * 10;
  return r;
}

int main() {
  int id,r,param = 2;
  start(10);

  struct Atrib a;
	a.p = 0;
	a.c = 0;
	id = spawn(&a, fibo, &param);
  printf("spaw ID main: %d \n", id);
  finish();

  sync(id, (void**) &r);
  printf("R main : %d\n", r);

  return 0;
}