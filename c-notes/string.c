#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char isim[20]; // dizgi
	char *soyisim; // pointer
	// 20 karakterlik yer ayir.
	soyisim = (char *) malloc(sizeof(char)*20); 
	// diziler ayrica birer pointer oldugu icin
	// isim degiskeninin onune & isareti koymamiza gerek yoktur.
	scanf("%s", isim);
	scanf("%s", soyisim);
	printf("merhaba %s %s\n", isim, soyisim);

	printf("ucuncu karakterler: %c %c\n", isim[3], soyisim[3]);

	char ilk[20] = "ilk mesaj";
	char ikinci[20] = "ikinci mesaj";
	char *ilks = ilk;
	char *ikincis = ikinci;
	printf("%s %s\n", ilks, ikincis);

	// shallow copy ilks = ikincis;

	/* deep copy
	int i = 0;
	char c = ikincis[0];
	while(c!='\0') {
		ilks[i] = ikincis[i];
		i++;
		c = ikincis[i];
	}
	*/

	// veya
	strcpy(ilks, ikincis);

	printf("%s %s\n", ilks, ikincis);
	ilks[3] = 'x';
	printf("%s %s\n", ilks, ikincis);

	// len fonksiyonu
	printf("%lu\n", strlen(ilks));
}