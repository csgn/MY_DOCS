#include <stdio.h>
#include <stdlib.h>

typedef enum {
	man,
	woman
} gender;

typedef struct {
	int age;
	char * name;
	gender c;
} human;

int 
retStatus(human *person) {
	if (person-> c == man && person->age > 55)
		return 1;
	if (person-> c == woman && person->age > 50)
		return 1;
	return 0;
}

int 
main() {
	human sergen;
	sergen.age = 18;
	sergen.c = man;
	printf("sergen-yasi: %d\n", sergen.age);
	printf("sergen-cinsiyeti: %u\n", sergen.c);
	printf("sergen-emeklidurumu: %d\n\n", retStatus(&sergen));

	human *defne;
	defne = (human*) malloc(sizeof(human));
	defne -> age = 25;
	defne -> c = woman;
	printf("defne-yasi: %d\n", defne -> age);
	printf("defne-cinsiyeti: %d\n", defne -> c);
	printf("defne-emeklidurumu: %d\n\n", retStatus(defne));

	human ali;
	ali.age = 56;
	ali.c = man;
	printf("ali-yasi: %d\n", ali.age);
	printf("ali-cinsiyeti: %u\n", ali.c);
	printf("ali-emeklidurumu: %d\n\n", retStatus(&ali));

}
