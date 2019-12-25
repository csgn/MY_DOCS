#include <stdio.h>

#define ABCD 2

/*
	#if expression - ifade
	#elif expression - ifade
	#ifdef identifier - tanimlayici
	#ifndef identifier - tanimlayici
	#else
	#endif

*/

int main(void) {

	#ifdef ABCD
		printf("1: yes\n");
	#else
		printf("1: no\n");
	#endif

	#ifndef ABCD
		printf("2: no1\n");
	#elif ABCD == 2
		printf("2: yes\n");
	#endif

	#if !defined(DCBA) && (ABCD) < 2*4-3
		printf("3: yes\n");
	#endif

}