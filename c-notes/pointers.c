#include <stdio.h>
#include <stdlib.h>

void f(int *); // fonksiyon prototipi
void g(int);

int main(){
	int *p; // p seklinde pointer tanimlanir.
	int a = 10; // a degiskenine 10 degeri atanir.
	p = &a; // a degiskeninin adresini pointer'a aktarilir.
	printf("%d\n", *p);
	*p = 20; // pointer'in gosterdigi deger degistirilir.
	printf("%d\n", a); // a nin degeri de degisir.

	// bellekte a tane elemanin oldugu bir dizi alani olusturulur. 
	int *q = (int *)malloc(sizeof(int)*a);
	q[3] = 70; // pointer'i dizi gibi kullaniyoruz.
	printf("\n%d\n", q[3]);

	f(&a); // a nin adresini gonderiyoruz.
	printf("\n%d\n", a);

	g(a);
	printf("\n%d\n", a);
}

void g(int a) { // call by value - deger ile cagirma
	a = 90; // a burada kopyalaniyor. Global degil local dir.
}

void f(int * a){ // call by reference - atıf ile cagirma
	*a = 80; // orjinal a nin icine 80 degerini koy.
}