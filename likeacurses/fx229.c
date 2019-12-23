#include <stdio.h>
#include <stdlib.h> // malloc
#include <time.h> // srand
#include <math.h>
#include "fgetch.h"

#define SIZE (int)pow(MAX, 2)
#define MAX 20
#define MIN 1
#define POSITION 1
#define LAST_POSITION 0
#define FLOOR_SHAPE 39 //32 //39
#define SHAPE 42
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68

int posi(int *arg) {
	int p;
	for (int i = 0; i < SIZE; i++) {
		if (arg[i] == POSITION)
			p = i;
	}
	return p;
}

// Taslagin ekrana basilmasi icin tanimlanan fonksiyon
// Aldigi parametre pointer.
void showArray(int *arg) {
	for (int i=0; i < SIZE; i++) {
        // eger i degiskeni MAX sabitine bolumunden kalan 0 ise bir bosluk birakiyor.
        // boylece dizimiz daha anlamli ve guzel gozukuyor.
		if (i%MAX == 0)
			printf("\n");
        // dizimizin i. index numarasindaki eleman ekrana bastirilir.
		if (arg[i] == 0)
			printf("%c ", FLOOR_SHAPE);

		if (arg[i] == POSITION)
			printf("%c ", SHAPE);
	}
	printf("\n");
}

// Gonderilen ilk deger pointer, ikinci deger ise kullanicinin girdigi degerdir.
void positionMovement(int *arg, int status) {
    // position degiskeni tanimlanir.
	int position;

    // dizinin i. elemani '1' e esit ise position degerini i degerine esitliyoruz.
    // buradaki amac kullanicinin o anki bulundugu konumu saklamak.
	for (int i = 0; i < SIZE; i++) {
		if (arg[i] == POSITION)
			position = i;
	}
 
	switch(status) {
		case KEY_UP: // up
  			// dizi disina cikildigi vakit '1' degeri ekranda gozukmuyor. Bu yuzden
			// dongu ile diziyi bastan sona tariyoruz eger '1' degerine rastlamaz ise
			// dizinin o anki konumuna  (SIZE-MAX) sabitlerinin sonucunun index numarasina
			// POSITION sabitini ekliyoruz.
			for (int i = 0; i < SIZE; i++)
				if (arg[i] != POSITION)
					arg[position+(SIZE-MAX)] = POSITION;
				else
					// dizide yukariya dogru bir hamle gerceklestirecegimiz icin o anki konumumuzdan
            		// MAX sabitini cikariyoruz ve cikan index numarasina 1 degerini atiyoruz.   
					arg[position-MAX] = POSITION;
			arg[position] = LAST_POSITION;
			break;

		case KEY_DOWN: // down
  			// dizi disina cikildigi vakit '1' degeri ekranda gozukmuyor. Bu yuzden
			// dongu ile diziyi bastan sona tariyoruz eger '1' degerine rastlamaz ise
			// ve position degeri (SIZE-MAX) degerinden daha buyuk ise
			// dizinin o anki konumundan (SIZE-MAX) sabitlerinin sonucunun index numarasina
			// POSITION sabitini ekliyoruz.

			for (int i = 0; i < SIZE; ++i) {	
				if ( arg[i] != POSITION && (SIZE-MAX) <= position )
					arg[position-(SIZE-MAX)] = POSITION;
				else {
            		// dizide asagiya dogru bir hamle gerceklestirecegimiz icin o anki konumumuza
            		// MAX sabitini ekliyoruz ve cikan index numarasina 1 degerini atiyoruz.
					arg[position+MAX] = POSITION;
					break;
				}
			}
			arg[position] = LAST_POSITION;
			break;

		case KEY_RIGHT: // right
  

			if ((position+1)%MAX == 0)
				arg[position-(MAX-1)] = POSITION;

			if ((position+1)%MAX != 0)
				// dizide sga dogru bir hamle gerceklestirecegimiz icin o anki konumumuza
            	// MIN sabitini ekliyoruz ve cikan index numarasina 1 degerini atiyoruz.  
				arg[position+MIN] = POSITION;

			arg[position] = LAST_POSITION;
			break;

		case KEY_LEFT: // left
  

			if (position%MAX == 0)
				arg[position+(MAX-1)] = POSITION;

			if (position%MAX != 0) 
				// dizide sola dogru bir hamle gerceklestirecegimiz icin o anki konumumuzdan
            	// MIN sabitini cikariyoruz ve cikan index numarasina 1 degerini atiyoruz.  
				arg[position-MIN] = POSITION;

			arg[position] = LAST_POSITION;
			break;
	}
}

int main() {
	char status;
    // malloc ile hafizada SIZE boyutunda yer ayriltilir.	
	int *map = (int *)malloc(sizeof(int)*SIZE);
    // program tekrar calistirildiktan sonra rastgele sayi üretmek icin srand kullanilir.
	srand(time(NULL));
    // 0 ile SIZE arasinda rastgele index numarasi elde edilir ve spawn degiskenine atanir.
    // spawn ile pozisyon belirlenir.
	int spawn = rand()%SIZE;
    // olusturulan dizinin her program calistiginda rastgele index numarasina '1' degeri eklenir.
    // geri kalan index numaralarina ait olan degerler standart olarak '0' degerine atanir.
	map[spawn] = POSITION;
	//printf("POSITION: @%d / INPUT: @%d( %d )", posi(map), 0, 0);

    // sonsuz donguye aliyoruz.
	while (1) {
        // ekrani temizliyoruz.
		system("clear");
		showArray(map);
		status = getch();
		positionMovement(map, status);
		//printf("POSITION: @%d / INPUT: @%d( %c )", posi(map), status, status);

    	// status adindaki degiskene klavyeden enter'a basilmadan veri alinir.
        // dizinin taslagini cizdirmek icin tanimlanmis fonksiyon icerisine diziyi ve kullanicidan alinan deger gonderilir.	
	}	
}

