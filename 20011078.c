#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

typedef struct Yazar {
	int yazarID ;
	char yazarAD[30], yazarSOYAD[30];
	struct Yazar *next;
	
} YAZAR;

typedef struct Kitap {
char kitapAdi[30]; 
char ISBN[13]; 
int adet; 
struct Kitap *next; 
struct KitapOrnek *head ;

} KITAP;

typedef struct KitapOrnek { 
char EtiketNo[20]; 
char Durum[9]; 
struct KitapOrnek *next ;

} KITAPORNEK;
	
typedef struct KitapYazar { 
char ISBN[13];
int YazarID;

} KITAPYAZAR;
	
typedef struct Tarih { 
int gun:5; 
int ay:4; 
int yil:12;

}TARIH;

typedef struct KitapOdunc { 
char EtiketNo[20]; 
char ogrID[9]; 
int islemTipi:1; 
struct Tarih islemTarihi;

} KITAPODUNC;

typedef struct Ogrenci { 
 char ogrID[9];
 char ad[30]; 
 char soyad[30]; 
 int puan; 
 struct Ogrenci *next; 
 struct Ogrenci *prev;
 
 } OGRENCI;
 
void menu();
void islemler(int a);
void kullanicimenu(int i);

YAZAR* yazarEkle(YAZAR *head);
YAZAR* yazarSil(YAZAR *head);
YAZAR* yazarDuzenle(YAZAR *head);
void yazarYazdir(YAZAR *head);

KITAP* kitapEkle(KITAP *head);
KITAP* kitapSil(KITAP *head);
KITAP* kitapDuzenle(KITAP *head);
void kitapYazdir(KITAP *head);

OGRENCI* ogrenciEkle(OGRENCI *head);
OGRENCI* ogrenciSil(OGRENCI *head);
OGRENCI* ogrenciDuzenle(OGRENCI *head);
void ogrenciYazdir(OGRENCI *head);

KITAPYAZAR* readcsvky(KITAPYAZAR *head);
KITAPYAZAR* kitapYazaresles(KITAPYAZAR *head, KITAP *head1);
KITAPYAZAR* kitapYazarguc(KITAPYAZAR *head, KITAP *head1);
void raftaKitap(KITAP *head);

YAZAR* readcsvy(YAZAR *head);
YAZAR* tersCevir(YAZAR *head);

KITAP* readcsvk(KITAP *head);
KITAP* tersCevirK(KITAP *head);

OGRENCI* readcsvo(OGRENCI *head);
OGRENCI* tersCevirO(OGRENCI *head);

KITAPODUNC* kitapOT(KITAPODUNC *head , KITAPORNEK *head1);
KITAPODUNC* readcsvko(KITAPODUNC *head);

int main(){
	srand(time(NULL));
	printf("\t\t\t\t\t KUTUPHANE OTOMASYONU UYGULAMASI\n");
	int i, j, k, flag1, choice, c2;
	char a;
	
	YAZAR *start1 = NULL; //(YAZAR*)(malloc(sizeof(YAZAR)));	
	KITAP *start2 = NULL;
	OGRENCI *start3 = NULL;
	KITAPYAZAR *startky = NULL;
	KITAPORNEK *startkor = NULL;
	KITAPODUNC *startkod = NULL;

	do{
		menu();
		scanf("%d", &choice);
		switch (choice){
			case 1:			
			islemler(1);
				scanf("%d", &c2);
				if(start1 == NULL){
					start1 = readcsvy(start1);	
					start1 = tersCevir(start1);				
				}		
					switch (c2){					
						case 1 :
							start1 = yazarEkle(start1);
							break;
						case 2 :
							start1 = yazarSil(start1);
							break;
						case 3 :
							start1 = yazarDuzenle(start1);
							break;
						case 4 :
							yazarYazdir(start1);
							break;
							
					}
			break;
			case 2:
				islemler(2);
				scanf("%d", &c2);
				if(start3 == NULL){
				//	start3 = readcsvo(start3);						printf("1");
				//	start3= tersCevirO(start3);						printf("1");			
				}	
				switch (c2){
					case 1 :
						start3 = ogrenciEkle(start3);
						break;
					case 2 :
						start3 = ogrenciSil(start3);
						break;
					case 3 :
						start3 = ogrenciDuzenle(start3);
						break;
					case 4 :
						ogrenciYazdir(start3);				
						break;
							
				}				
				
			break;
			case 3:
				islemler(3);
				scanf("%d", &c2);
				if(start2 == NULL){
					start2 = readcsvk(start2);	
					start2 = tersCevirK(start2);			
				}	
				switch (c2){
					case 1 :
						start2 = kitapEkle(start2);
						break;
					case 2 :
						start2 = kitapSil(start2);
						break;
					case 3 :
						start2 = kitapDuzenle(start2);
						break;
					case 4 :
						kitapYazdir(start2);
						break;
					case 5 :
						raftaKitap(start2);
						break;							
				}
				
				break;
			case 4:
				islemler(4);	
				scanf("%d", &c2);
				if(startky == NULL){
					startky = readcsvky(startky);			
				}
				switch (c2){
					case 1 :
					//	startky = kitapYazaresles(startky , startko);
						break;
					case 2 :
					// startky = kitapYazarguc(startky , startko);
						break;
				}	
				break;
			case 5:
				islemler(5);	
				scanf("%d", &c2);
				switch (c2){
					case 1 :
						
						break;
					case 2 :
			
						break;
					case 3 :
				
						break;
					case 4 :
				
						break;
				}	
				break;
			case 9:
				break;
			default:
				printf("\nHatali tus girdiniz! Lutfen 1 ile 5 arasinda bir sayi girin.");
				scanf("%c",&a);	scanf("%c",&a);
				system("cls");
				break;
				
		}
	}
	while(choice != 9);

	return 0;
}

YAZAR* yazarEkle(YAZAR *head){

	YAZAR *ekle = (YAZAR*)(malloc(sizeof(YAZAR)));
	ekle->next = NULL;
	YAZAR *q = NULL;
	q = head;	
		
	FILE *file;
	file = fopen("Yazarlar.csv", "a");
	if (file == NULL){
		printf("Error opening file\n");
	}
	ekle->yazarID = 1;
	printf("\nYAZAR EKLEME\nYazarin adini giriniz:");
	scanf("%s",ekle->yazarAD );
	printf("Yazarin soyadini giriniz:");
	scanf("%s",ekle->yazarSOYAD );
	if (head == NULL){
		head = ekle;
	}
	else{
		while(q->next != NULL){
			q = q->next;	
		}
		ekle->yazarID = (q->yazarID+1);
		q->next = ekle;
	}
	fprintf(file,"\n%d, %s, %s", ekle->yazarID, ekle->yazarAD, ekle->yazarSOYAD);
	printf("\nKayit basarili.\n\n\n");
	sleep(1);
	fclose(file);
	
	return head;
}
YAZAR* yazarSil(YAZAR *head){
	
	FILE *file;
	file = fopen("Yazarlar.csv", "w+");
	
	if (file == NULL){
		printf("Error opening file\n");
	}

	YAZAR *bef = NULL;	YAZAR *after = NULL , *fyaz = NULL;	
	YAZAR *iter = NULL;	YAZAR *temp = NULL;	YAZAR *temp2 = NULL;
	temp = head;	iter = head , fyaz = head;
	int i, a , j=1;
	printf("\nKacinci yazarin kaydi silinecek?\n==");
	scanf("%d", &a);
	if(a == 1){
		iter = head->next;
		free(head);
		head = iter;
	}
	else{
		while(temp->yazarID != a){
			temp2 = temp;
			temp = temp->next;
		}	
		if(temp->next == NULL){
			free(temp);
			temp2->next = NULL;
		}
		else{
			after = temp->next;
			free(temp);
			temp2->next = after;
		}	
	}
		while(fyaz != NULL){	
			fprintf(file,"%d, %s, %s", fyaz->yazarID, fyaz->yazarAD, fyaz->yazarSOYAD);
			fyaz = fyaz->next;
		}
		
	fclose(file);
	printf("\nYazar Kaydi basariyla silindi!\n");
	sleep(1);
	return head;
}
void yazarYazdir(YAZAR *head){
	

	FILE *file;
	file = fopen("Yazarlar.csv", "r");
	if (file == NULL){
		printf("Error opening file\n");
	}

	char a;
	YAZAR *q = NULL;
	q = head;
	printf("\n");
		
	while(q != NULL){																									//STRUCT YAPISINDA YAZDIRMA
		printf("ID-> %d  %s %s\n", q->yazarID , q->yazarAD, q->yazarSOYAD);
		q = q->next;
	}	
	fclose(file);
	scanf("%c",&a);	scanf("%c",&a);
}
YAZAR* yazarDuzenle(YAZAR *head){
	
	FILE *file;
	file = fopen("Yazarlar.csv", "w+");
	if (file == NULL){
		printf("Error opening file\n");
	}
	
	char a;
	int i, j, s;
	YAZAR *q = NULL , *fyaz = head;	 q = head;
	printf("\nKacinci yazarin(ID) kaydi yenilenecek?\n==");
	scanf("%d", &s);
	for(i=1 ; i<s ; i++){
		q = q->next;
	}
	printf("\nYAZAR YENILEME\nYazarin adini giriniz:");
	scanf("%s",q->yazarAD );
	printf("Yazarin soyadini giriniz:");
	scanf("%s",q->yazarSOYAD );
	
	while(fyaz != NULL){	
		fprintf(file,"%d, %s, %s", fyaz->yazarID, fyaz->yazarAD, fyaz->yazarSOYAD);
		fyaz = fyaz->next;
	}
		
	printf("\n\nYazar Kaydi basariyla yenilendi!\n");
	sleep(1);
	
	fclose(file);
	return head;
}

KITAP* kitapEkle(KITAP *head){

	KITAP *ekle = (KITAP*)(malloc(sizeof(KITAP)));
	ekle->next = NULL;
	KITAP *q = NULL;
	q = head;
		
	FILE *file1;
	file1 = fopen("Kitaplar.csv", "a");
	if (file1 == NULL){
		printf("Error opening file\n");
	}
	
	printf("\nKITAP EKLEME\nEklenecek olan kitabin adini girin: ");
	getchar();
	gets(ekle->kitapAdi);
	printf("\nKitabin ISBN numarisini girin: ");
	scanf("%s", ekle->ISBN);
	printf("\nBu kitaptan kac tane eklenecek: ");
	scanf("%d", &ekle->adet);
	
	if(head == NULL){
		head = ekle;
	}
	else{
		while(q->next != NULL){
			q = q->next;
		}
		q->next = ekle;
	}
	fprintf(file1,"\n%s,%s,%d",ekle->kitapAdi,ekle->ISBN,ekle->adet);
	fclose(file1);
	printf("\n\nKitap Kaydi basariyla eklendi!");
	sleep(1);
	return head;
}
KITAP* kitapSil(KITAP *head){	
	int i, a, j = 1;
	char name[100];
	KITAP *fyaz = NULL; fyaz = head;
	
	FILE *file;
	file = fopen("Kitaplar.csv", "w+");
	if (file == NULL){
		printf("Error opening file\n");
	}
	
	KITAP *bef = NULL, *after = NULL, *temp = NULL ;
	temp = head;
	
	printf("\nSilinecek kitabin ISBN numarasi nedir?\n==");
	scanf("%s", name);
	if (!(strcmp(head->ISBN,name))){
		temp = head->next;
		free(head);
		head = temp;
	}
	else {
		while(!(strcmp(temp->next->ISBN,name))){
			temp = temp->next;
		}
		if(temp->next->next == NULL){
			free(temp->next);
			temp->next = NULL;		
		}
		else {
			bef = temp;
			after = temp->next->next;
			free(temp->next);
			bef->next = after;
		}
		
	}
	while(fyaz != NULL){	
		fprintf(file,"%s,%s,%d\n", fyaz->kitapAdi, fyaz->ISBN, fyaz->adet);
		fyaz = fyaz->next;
	}	
	printf("\n\nKitap Kaydi basariyla silindi!");
	fclose(file);
	sleep(1);
	return head;
}
void kitapYazdir(KITAP *head){
	char a;
	char name[10];
	strcpy(name, "Rafta");
	KITAP *q = NULL;
	q = head;
	int i =1;
	printf("\n");
	while(q != NULL){
		printf("%d.Kitabin = %s \nISBN Numarasi-> %s \nAdeti-> %d\n",i , q->kitapAdi, q->ISBN, q->adet);
		q = q->next;
		printf("\n");
		i++;
	}
	scanf("%c",&a);	scanf("%c",&a);
}
KITAP* kitapDuzenle(KITAP *head){	
	char a, name[100];
	int i, j, c;
	char ISBNN[100];
	FILE *file;
	file = fopen("Kitaplar.csv", "w+");
	if (file == NULL){
		printf("Error opening file\n");
	}
	KITAP *q = NULL;	q = head;
	KITAP *fyaz = NULL;	fyaz = head;
	printf("\nYenilenecek kitabin ISBN numarasi nedir?\n==");
	getchar();
	gets(name);
	while(!strcmp(q->ISBN,name)){	
		q = q->next;
	}
	printf("\nKITAP YENILEME\nKitabin adini giriniz:");
	getchar();
	gets(q->kitapAdi);
	printf("\nKitabin adetini giriniz:");
	scanf("%d",q->adet);
	printf("\nKitabin ISBN numarasini giriniz:");
	scanf("%s",ISBNN);
	strcpy(q->ISBN,ISBNN);
	while(fyaz != NULL){	
		fprintf(file,"%s,%s,%d \n", fyaz->kitapAdi, fyaz->ISBN, fyaz->adet);
		fyaz = fyaz->next;
	}	
	fclose(file);
	printf("\n\nKitap Kaydi basariyla yenilendi!");
	sleep(1);

	return head;
}

OGRENCI* ogrenciEkle(OGRENCI *head){
	
	FILE *file;
	file = fopen("Ogrenciler.csv", "a");
	if (file == NULL){
		printf("Error opening file\n");
	}
	//file = head; 
	
	OGRENCI *before = NULL , *after = NULL , *temp = NULL; 
	temp = head;
	
	OGRENCI *ekle = (OGRENCI*)malloc(sizeof(OGRENCI));
	
	printf("\nOGRENCI EKLEME\n\nOgrencinin adini girin: ");		scanf("%s", ekle->ad);
	printf("Ogrencinin soyadini girin: ");						scanf("%s", ekle->soyad);
	printf("Ogrencinin puani: ");								scanf("%d", &ekle->puan);
	printf("Ogrencinin ID'si: ");								scanf("%s", ekle->ogrID);
	ekle->next = NULL;  ekle->prev = NULL;
	if(head == NULL){
		head = ekle;
	}
	else {
		while(temp->next != NULL){
			temp = temp->next;
		}
		ekle->prev = temp;
		temp->next = ekle;
	}
	printf("\nKayit basarili.\n\n\n");
	fprintf(file,"\n%s, %s, %s, %d", ekle->ogrID, ekle->ad, ekle->soyad, ekle->puan);
	sleep(1);
	fclose(file);
}
OGRENCI* ogrenciSil(OGRENCI *head){

	OGRENCI *fyaz = NULL , *temp = NULL;	fyaz = head , temp = head;
	
	FILE *file;
	file = fopen("Ogrenciler.csv", "w+");
	if (file == NULL){
		printf("Error opening file\n");
	}
	
	OGRENCI *q = NULL;	q = head;
	OGRENCI *once = NULL ; 
	OGRENCI *sonra = NULL;
	char IDn[100];
	
	printf("\nSilinecek ogrencinin numarasini girin:");
	scanf("%s", IDn);
	if(strcmp(head->ogrID,IDn)){
		sonra = temp->next;
		free(temp);
		sonra->prev = NULL;
		head = sonra;
	}
	else{
		while(!strcmp(temp->ogrID,IDn) && temp != NULL){
			temp = temp->next;
		}	
		if(temp->next == NULL ){
			once = temp->prev;
			once->next=NULL;
			free(temp);
		}
		else{
			once = temp->prev;
			sonra = temp->next;
			once->next = sonra ;	
			sonra->prev = once;
			free(temp);

		}
	}
	
	while(fyaz != NULL){	
		fprintf(file,"%s, %s, %s, %d\n", fyaz->ogrID, fyaz->ad, fyaz->soyad, fyaz->puan);
		fyaz = fyaz->next;
	}
	printf("\n\nOgrenci kaydi basariyla silindi.");
	fclose(file);
	sleep(1);
	
	return head;
}
OGRENCI* ogrenciDuzenle(OGRENCI *head){
	
	FILE *file;
	file = fopen("Ogrenciler.csv", "w+");
	if (file == NULL){
		printf("Error opening file\n");
	}
	
	OGRENCI *q = NULL , *fyaz = NULL;
	q = head; fyaz = head;
	char IDn[100];
	printf("Duzenlenecek ogrencinin ID'sini girin.");
	scanf("%s", IDn);
	while(!strcmp(q->ogrID,IDn)){
		q = q->next;
	}
	printf("\nOGRENCI DUZENLEME\n\nOgrencinin adini girin: ");		scanf("%s", q->ad);
	printf("Ogrencinin soyadini girin: ");							scanf("%s", q->soyad);
	printf("Ogrencinin puani: ");									scanf("%d", &q->puan);
	printf("Ogrencinin ID'si: ");									scanf("%s", q->ogrID);	
	
	while(fyaz != NULL){	
		fprintf(file,"%s, %s, %s, %d\n", fyaz->ogrID, fyaz->ad, fyaz->soyad, fyaz->puan);
		fyaz = fyaz->next;
	}	
	printf("Ogrenci kaydi basariyla duzenlendi.");
	fclose(file);
	sleep(1);
	
	return head;
}
void ogrenciYazdir(OGRENCI *head){
	char a;
	OGRENCI *q = NULL;	
	q = head;
	if(q == NULL){
		printf("\nOgrenci Kaydi Bulunamadi!");
	}
	printf("\n");
	while(q != NULL){
		printf("%s ID'li Ogrenci %s %s", q->ogrID, q->ad, q->soyad);
		printf("\nOgrenci puani --> %d\n", q->puan);
		q = q->next;
		printf("\n");
	}
	scanf("%c",&a);	scanf("%c",&a);
}

void menu(){
//	system("cls");
	printf("\nYapmak istediginiz islem turunu secin.\n\n1- Yazar Ekleme/Silme/Duzenleme/Listeleme Islemleri\n");
	printf("2- Ogrenci Ekleme/Silme/Duzenleme/Listeleme Islemleri\n3- Kitap Ekleme/Silme/Duzenleme/Listeleme Islemleri\n");
	printf("4- Kitap-Yazar Iliskilendirme Islemleri\n5- Ogrenci Kitap Odunc Alma Islemleri\n9- Cikis\n== ");	
}
void islemler(int a){
	switch (a){
		case 1 :
			printf("\n\n\nYAZAR ISLEMLERI\n\n1- Yazar Ekle\n2- Yazar Sil\n3- Yazar Duzenleme\n4- Yazarlari Listele\n== ");
			break;
		case 2 :
			printf("\n\n\nOGRENCI ISLEMLERI\n\n1- Ogrenci Ekle\n2- Ogrenci Sil\n3- Ogrenci Duzenleme\n4- Ogrencileri Listele\n== ");							
			break;
		case 3 :
			printf("\n\n\nKITAP ISLEMLERI\n\n1- Kitap Ekle\n2- Kitap Sil\n3- Kitap Duzenleme\n4- Kitaplari Listele\n5- Raftaki kitaplari listele\n== ");				
			break;
		case 4 :
			printf("\n\n\nKITAP-YAZAR ILISKILENDIRME ISLEMLERI\n\n1- Kitap-Yazar eslestir\n2- Kitabin yazarini guncelle\n== ");		
			break;
		case 5 :
			printf("\n\n\nOGRENCI-KITAP ODUNC ISLEMLERI\n\n1- Kitap odunc al/teslim et\n2- Cezali ogrencileri listele\n3- Kitap teslim etmemis ogrencileri listele\n4- Zamaninda teslim edilmeyen kitaplari listele\n== ");
			break;						
	}
}

KITAPYAZAR* kitapYazaresles(KITAPYAZAR *head, KITAP *head1){
	
	KITAPYAZAR *esles = NULL;

	FILE *file;
	file = fopen("KitapYazar.csv", "a");
	if (file == NULL){
		printf("Error opening file\n");
	}
	if(head == NULL){

	}
	
}
void raftaKitap(KITAP *head){
	KITAPORNEK *raf = NULL;
	char a;
	KITAP *q = NULL;
	q = head;
	int i =1;
	printf("\n");
	while(q != NULL){
		raf = q->head;
		printf("%d.Kitabin = %s Durumu = %s\nISBN Numarasi-> %s \nAdeti-> %d\n",i ,raf->Durum, q->kitapAdi, q->ISBN, q->adet);
		q = q->next;
		printf("\n");
		i++;
	}
	scanf("%c",&a);	scanf("%c",&a);
}

YAZAR* readcsvy(YAZAR *head) {
	
		YAZAR *okunan = NULL , *tra = NULL;
	    FILE *fread = fopen("Yazarlar.csv", "r");
	    if (fread == NULL) {
	        printf("Error opening file!\n");
	    }
	    char row[1024];
	    char *token;
		while (fgets(row, 1024, fread) != NULL) {
	        okunan = (YAZAR*)malloc(sizeof(YAZAR));
	        
	       	token = strtok(row, ","); 
	       	okunan->yazarID = atoi(token);
	       	token = strtok(NULL, ",");
	       	strcpy(okunan->yazarAD, token);
	       	token = strtok(NULL, ",");
	       	strcpy(okunan->yazarSOYAD, token);
	       	
			okunan->next = head;
	        head = okunan;
	    }

    fclose(fread);
    return head;
}
KITAP* readcsvk(KITAP *head) {

		int i , j;	
		char name[10], etiket[20];
		strcpy(name, "Rafta");
		KITAP *okunan = NULL , *tra = NULL ;

	    FILE *fread = fopen("Kitaplar.csv", "r");
	    if (fread == NULL) {
	        printf("Error opening file!\n");
	    }
	    char row[1024];
	    char *token;
		while (fgets(row, 1024, fread) != NULL) {
			
			KITAPORNEK *raflar = NULL;	
	        okunan = (KITAP*)malloc(sizeof(KITAP));
	        okunan->head = NULL;
	        
	       	token = strtok(row, ","); 
	       	strcpy(okunan->kitapAdi, token);
	       	token = strtok(NULL, ",");
	       	strcpy(okunan->ISBN, token);
	       	token = strtok(NULL, ",");
			okunan->adet = atoi(token);
			j = okunan->adet;
			
	       	raflar = okunan->head;
			for(i=1 ; i<=j ; i++){	
				if(raflar = NULL){		
		     		sprintf(etiket, "%s_%d", okunan->ISBN, i);
		     		strcpy(raflar->EtiketNo,etiket);
	      	 		strcpy(raflar->Durum, name);
	      	 		raflar->next = NULL;
				}
				else{
			  		while(raflar != NULL){
						raflar = raflar->next;		  			
					}
					raflar = (KITAPORNEK*)malloc(sizeof(KITAPORNEK));
		     		sprintf(etiket, "%s_%d", okunan->ISBN, i);
		     		strcpy(raflar->EtiketNo,etiket);
	      	 		strcpy(raflar->Durum, name);
					raflar->next = NULL;
				}
			}
			okunan->next = head;
	        head = okunan;
	    }

    fclose(fread);
    return head;
}
OGRENCI* readcsvo(OGRENCI *head) {	

		OGRENCI *okunan = NULL , *tra = NULL, *bass = NULL;
		bass = head;
	    FILE *fread = fopen("Ogrenciler.csv", "r");
	    if (fread == NULL) {
	        printf("Error opening file!\n");
	    }
	    char row[1024];
	    char *token;
		while (fgets(row, 1024, fread) != NULL) {
	        okunan = (OGRENCI*)malloc(sizeof(OGRENCI));    
			  
	       	token = strtok(row, ","); 
	       	strcpy(okunan->ogrID, token);
	       	token = strtok(NULL, ",");
	       	strcpy(okunan->ad, token);
	       	token = strtok(NULL, ",");
	       	strcpy(okunan->soyad, token);
	       	token = strtok(NULL, ",");
			okunan->puan = atoi(token);
	       	
	       	if(head == NULL){
	       		head = okunan;
	       	 //   head->prev = NULL;
			}
			else{			
				tra = bass;
				
				while(tra->next != NULL){
					tra = tra->next;
				}
				tra->next = okunan;
				okunan->prev = tra;
			//	okunan->next = NULL;
		    }
	    }    
    fclose(fread);
    return head;
}
KITAPYAZAR* readcsvky(KITAPYAZAR *head){
	
	KITAP *tra = NULL;
	KITAPYAZAR *okunan = NULL , **dizimsi;

	int count;
	FILE *fread = fopen("KitapYazar.csv", "r");
	if (fread == NULL) {
		printf("Error opening file!\n");
	}
	char row[1024];
	char *token;
	dizimsi =(KITAPYAZAR**)malloc(sizeof(KITAPYAZAR*));
		while (fgets(row, 1024, fread) != NULL) {
			dizimsi = realloc(dizimsi,sizeof(KITAPYAZAR)*(count+1));
			dizimsi[count] = (KITAPYAZAR*)malloc(sizeof(KITAPYAZAR));
				        
	       	token = strtok(row, ","); 
	       	dizimsi[count]->YazarID = atoi(token);
	       	token = strtok(NULL, ",");
	       	strcpy(dizimsi[count]->ISBN, token);

	    }
    fclose(fread);
    return head;
	
}

YAZAR* tersCevir(YAZAR *head) {
		// Duz linked list ile kayit ededemedim tersten linked list ise calisti bu yuzden linked listi ters alýp bir daha ters cevirdim.
    YAZAR *prev = NULL, *current = head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
KITAP* tersCevirK(KITAP *head) {
		// Duz linked list ile kayit ededemedim tersten linked list ise calisti bu yuzden linked listi ters alýp bir daha ters cevirdim.
    KITAP *prev = NULL, *current = head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
/*
OGRENCI* tersCevirO(OGRENCI *head) {
		// Duz linked list ile kayit ededemedim tersten linked list ise calisti bu yuzden linked listi ters alýp bir daha ters cevirdim.
    OGRENCI *prev = NULL, *current = head, *next = NULL;
    while (current->next != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}*/
