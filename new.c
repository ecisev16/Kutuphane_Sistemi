#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct yazar{
    char name[30];
    char surname[30];
    int ID;
    struct yazar *next;
}YAZARLAR;

typedef struct ogrenci{
    char name[30];
    char surname[30];
    char ID[10];
    int scor;
    struct ogrenci *next; 
    struct ogrenci *prev;  
}OGRENCILER;

typedef struct kitapOrnek{
    char EtiketNo[20];
    char Durum[10];
    struct kitapOrnek *next;

}KITAPORNEK;

typedef struct kitap{
    char kitapAdi[30];
    char ISBN[15];
    int adet;
    struct kitap *next;
    struct kitapOrnek *head;
}KITAP;

typedef struct kitapYazar{
    char ISBN[15];
    int yazarID;
    struct kitapYazar *next;
}KITAPYAZAR;

typedef struct tarih{
    int gun:5;
    int ay:4;
    int yil:12;
}TARIH;

typedef struct kitapOdunc{
    char etiketNo[20];
    char ogrID[10];
    int islemTipi:1;
    struct tarih islemTarihi;
}KITAPODUNC;

int takeYazarlar_file(YAZARLAR **);
void takeYazarlar_user(YAZARLAR **, int );
void printYazarlar(YAZARLAR **);
int deleteYazarlar(YAZARLAR **);
void takeOgrenciler_file(OGRENCILER **);
void takeOgrenciler_user(OGRENCILER **);
void printOgrenciler(OGRENCILER **);
int deleteOgrenciler(OGRENCILER **);
void takeKitaplar_file(KITAP **);
void Split_Data_y(YAZARLAR*,char line[100], int);
void Split_Data_o(OGRENCILER*, char line[100]);
void Split_Data_k(KITAP*, char line[100]);
void Split_Data_ky(KITAPYAZAR* , char line[100]);
void takeKitapYazar_file(KITAPYAZAR **kityaz);

int main(){
    
    YAZARLAR *yazar = NULL;
    OGRENCILER *ogrenci = NULL;
    KITAP *kitap = NULL;
    KITAPYAZAR *kityaz = NULL;

    int nextID;
    int option;
    int option2;

    printf("Yapmak istediginiz islemin numarasini giriniz.\n\nOGRENCI ISLEMLERI\n\n1- Ogrenci Ekle, Sil, GUncelle\n2- Ogrenci Bilgisi Goruntuleme\n3- Kitap Teslim Etmemis Ogrencileri Listele\4- Cezali Ogrencileri Listele\n5- TUm Ogrencileri Listele\n6- Kitap Odunc Al/Teslim Et\n\nKITAP ISLEMLERI\n\n7- Kitap Ekle, Sil, Guncelle\n8- Kitap Bilgisi Goruntuleme\n9- Raftaki Kitaplari Listele\n10- Zamaninda Teslim Edilmeyen Kitaplari Listele\n11- Kitap-Yazar Eslestir \n12- Kitabin Yazarini Guncelle\n\nYAZAR ISLEMLERI\n\n13- Yazar Ekle, Sil, Guncelle\n14- Yazar Bilgisi Goruntuleme\n\n");
    scanf("%d", &option);
    nextID = takeYazarlar_file(&yazar);
    takeOgrenciler_file(&ogrenci);
    takeKitaplar_file(&kitap);
    takeKitapYazar_file(&kityaz);

    while(option != 15){

        switch(option){
            case 1 :
                printf("Hangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                scanf("%d", &option2);
                while(option2!=4){

                    switch(option2){
                        case 1 : takeOgrenciler_user(&ogrenci); break;
                        case 2 :
                            printf("\n\n\n%d\n\n\n",deleteOgrenciler(&ogrenci));
                            printOgrenciler(&ogrenci);
                        break;
                        case 3 : break;
                    }
                    printf("Hangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                    scanf("%d", &option2);
                }

                break;           
            break;
            case 2 : break;
            case 3 : break;
            case 4 : break;
            case 5 : break;
            case 6 : break;
            case 7 : break;
            case 8 : break;
            case 9 : break;
            case 10 : break;
            case 11 : break;
            case 12 : break;
            case 13 : 
                printf("Hangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                scanf("%d", &option2);
                while(option2!=4){

                    switch(option2){
                        case 1 : takeYazarlar_user(&yazar, nextID); break;
                        case 2 :
                            printf("\n\n\n%d\n\n\n",deleteYazarlar(&yazar));
                            printYazarlar(&yazar);
                        break;
                        case 3 : break;
                    }
                    printf("Hangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                    scanf("%d", &option2);
                }

                break;
            case 14 : break;  // printYazarlar(&yazar);
            case 15 : break;


        }
        printf("Yapmak istediginiz islemin numarasini giriniz.\n\nOGRENCI ISLEMLERI\n\n1- Ogrenci Ekle, Sil, GUncelle\n2- Ogrenci Bilgisi Goruntuleme\n3- Kitap Teslim Etmemis Ogrencileri Listele\4- Cezali Ogrencileri Listele\n5- TUm Ogrencileri Listele\n6- Kitap Odunc Al/Teslim Et\n\nKITAP ISLEMLERI\n\n7- Kitap Ekle, Sil, Guncelle\n8- Kitap Bilgisi Goruntuleme\n9- Raftaki Kitaplari Listele\n10- Zamaninda Teslim Edilmeyen Kitaplari Listele\n11- Kitap-Yazar Eslestir \n12- Kitabin Yazarini Guncelle\n\nYAZAR ISLEMLERI\n\n13- Yazar Ekle, Sil, Guncelle\n14- Yazar Bilgisi Goruntuleme\n\n");
        scanf("%d", &option);
    }
    

    return 0;
}



int takeYazarlar_file(YAZARLAR **yazar){
    FILE *fp;
    //int i=0;
    int nextID;
    char line[100];
    char *sp;

    fp = fopen("Yazarlar.csv", "r+");
    YAZARLAR *yzr = (YAZARLAR*)malloc(sizeof(YAZARLAR));

    if(fgets(line, 100, fp) != NULL){
        *yazar = yzr;
    }
    yzr->next = NULL;
    
    Split_Data_y(yzr, line, nextID);
    
    printf("\n\n\n%d %s %s", yzr->ID, yzr->name, yzr->surname);
    


    while(fgets(line, 100, fp) != NULL){

        YAZARLAR *yzr = (YAZARLAR*)malloc(sizeof(YAZARLAR));
        if(yzr == NULL){
            exit(-1);
        }

        yzr->next = NULL;
        YAZARLAR *curr = *yazar;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = yzr;

        Split_Data_y(yzr, line, nextID);
        printf("\n%d %s %s", yzr->ID, yzr->name, yzr->surname);

    }
    
    fclose(fp);
    return nextID;
}

void takeYazarlar_user(YAZARLAR **yazar, int nextID){
        FILE *fp;
        YAZARLAR *yzr = (YAZARLAR*)malloc(sizeof(YAZARLAR));

        if(yzr == NULL){
            exit(-1);
        } 

        yzr->ID = nextID;

        printf("Yazar bilfilerini giriniz(sirasiyle ad, soyad.): ");
        scanf("%s %s", yzr->name, yzr->surname);
        fp = fopen("Yazarlar.csv", "a");
        printf("%d %s %s", yzr->ID, yzr->name, yzr->surname);
        fprintf(fp, "\n%d,%s,%s", yzr->ID, yzr->name, yzr->surname);

        yzr->next = NULL;
        if(*yazar==NULL){
            *yazar=yzr;
            return;
        }
        
        YAZARLAR *curr = *yazar;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = yzr;
        
        fclose(fp);
        return;
}

void printYazarlar(YAZARLAR **yazar){
    YAZARLAR *curr = *yazar;
    FILE *fp;
    fp = fopen("Yazarlar.csv","w");
    while(curr->next != NULL){
        printf("%d %s %s\n", curr->ID, curr->name, curr->surname);
        fprintf(fp, "%d,%s,%s\n", curr->ID, curr->name, curr->surname);
        curr = curr->next;
    }
    printf("%d %s %s", curr->ID, curr->name, curr->surname);
    fprintf(fp, "%d,%s,%s", curr->ID, curr->name, curr->surname);
    fclose(fp);
}

int deleteYazarlar(YAZARLAR **yazar){

    char name[30];
    char surname[30];
    int found = 0;
    printf("silmek istediğiniz yazar adini ve soyadini giriniz: ");
    scanf("%s %s", name, surname);

    YAZARLAR *curr = *yazar;
    YAZARLAR *prev = NULL;

    while((curr!=NULL) && !found){
        if((strcmp(curr->name, name) == 0)&&(strcmp(curr->surname, surname) == 0)){ //&&(strcmp(curr->surname, surname) == 0)  (strcmp(curr->name, name) == 0)&&
            found = 1;
            if(prev == NULL){
                *yazar = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
        }
        prev = curr;
        curr = curr->next;
    }

    return found;
}



void takeOgrenciler_file(OGRENCILER **ogrenci){
    FILE *fp;
    //int i=0;
    char line[100];
    char *sp;

    fp = fopen("Ogrenciler.csv","r+");
    OGRENCILER *ogr = (OGRENCILER*)malloc(sizeof(OGRENCILER));

    if(fgets(line, 100, fp) != NULL){
        *ogrenci = ogr;
    }
    ogr->next = NULL;
    ogr->prev = NULL;

    Split_Data_o(ogr, line);

    printf("\n\n%s %s %s %d", ogr->ID, ogr->name, ogr->surname, ogr->scor);

    while(fgets(line, 100, fp) != NULL){

        OGRENCILER *ogr = (OGRENCILER*)malloc(sizeof(OGRENCILER));
        if(ogr == NULL){
            exit(-1);
        }

        ogr->next = NULL;
        OGRENCILER *curr = *ogrenci;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = ogr;
        ogr->prev = curr;

        Split_Data_o(ogr, line);

        printf("\n%s %s %s %d", ogr->ID, ogr->name, ogr->surname, ogr->scor);

    }
}

void takeOgrenciler_user(OGRENCILER **ogrenci){
    FILE *fp;
    OGRENCILER *ogr = (OGRENCILER*)malloc(sizeof(OGRENCILER));
    if(ogr == NULL){
        exit(-1);
    } 

    ogr->next = NULL;
    OGRENCILER *curr = *ogrenci;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ogr;
    ogr->prev = curr;
    ogr->scor = 100;
    printf("Ogrenci bilfilerini giriniz(sirasiyle ad, soyad, numara.): ");
    scanf("%s %s %s", ogr->name, ogr->surname, ogr->ID);
    fp = fopen("Ogrenciler.csv", "a");
    printf("%s %s %s %d", ogr->ID, ogr->name, ogr->surname, ogr->scor);
    fprintf(fp, "\n%s,%s,%s,%d", ogr->ID, ogr->name, ogr->surname, ogr->scor);
    fclose(fp);
}

void printOgrenciler(OGRENCILER **ogrenci){
    OGRENCILER *curr = *ogrenci;
    FILE *fp;
    fp = fopen("Ogrenciler.csv","w");
    while(curr->next != NULL){
        printf("%s %s %s %d\n", curr->ID, curr->name, curr->surname, curr->scor);
        fprintf(fp, "%d,%s,%s,%d\n", curr->ID, curr->name, curr->surname, curr->scor);
        curr = curr->next;
    }
    printf("%s %s %s %d", curr->ID, curr->name, curr->surname, curr->scor);
    fprintf(fp, "%s,%s,%s,%d", curr->ID, curr->name, curr->surname, curr->scor);
    fclose(fp);
}

int deleteOgrenciler(OGRENCILER **ogrenci){

    char name[30];
    char surname[30];
    int found = 0;
    printf("silmek istediğiniz ogrenci adini ve soyadini giriniz: ");
    scanf("%s %s", name, surname);

    OGRENCILER *curr = *ogrenci;
    OGRENCILER *prev = NULL;

    while((curr!=NULL) && !found){
        if((strcmp(curr->name, name) == 0)&&(strcmp(curr->surname, surname) == 0)){ //&&(strcmp(curr->surname, surname) == 0)  (strcmp(curr->name, name) == 0)&&
            found = 1;
            if(prev == NULL){
                *ogrenci = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
        }
        prev = curr;
        curr = curr->next;
    }
    return found;
}



void takeKitaplar_file(KITAP **kitap){

    FILE *fp;
    //int i=0;
    char line[100];
    char *sp;

    fp = fopen("Kitaplar.csv","r+");
    KITAP *ktp = (KITAP*)malloc(sizeof(KITAP));

    if(fgets(line, 100, fp) != NULL){
        *kitap = ktp;
    }
    ktp->next = NULL;

    Split_Data_k(ktp,line); 

    printf("\n\n%s %s %d", ktp->kitapAdi, ktp->ISBN, ktp->adet);

    while(fgets(line, 100, fp) != NULL){

        KITAP *ktp = (KITAP*)malloc(sizeof(KITAP));
        if(ktp == NULL){
            exit(-1);
        }

        ktp->next = NULL;
        KITAP *curr = *kitap;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = ktp;

        Split_Data_k(ktp,line);  

        printf("\n%s %s %d", ktp->kitapAdi, ktp->ISBN, ktp->adet);

    }
}

void takeKitapYazar_file(KITAPYAZAR **kityaz){
    FILE *fp;
    //int i=0;
    int nextID;
    char line[100];
    char *sp;

    fp = fopen("KitapYazar.csv", "r+");
    KITAPYAZAR *kit = (KITAPYAZAR*)malloc(sizeof(KITAPYAZAR));

    if(fgets(line, 100, fp) != NULL){
        *kityaz = kit;
    }
    kit->next = NULL;
    
    Split_Data_ky(kit, line);
    
    printf("\n\n\n%s %d", kit->ISBN, kit->yazarID);
    


    while(fgets(line, 100, fp) != NULL){

        KITAPYAZAR *kit = (KITAPYAZAR*)malloc(sizeof(KITAPYAZAR));
        if(kit == NULL){
            exit(-1);
        }

        kit->next = NULL;
        KITAPYAZAR *curr = *kityaz;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = kit;

        Split_Data_ky(kit, line);
        printf("\n%s %d", kit->ISBN, kit->yazarID);

    }
    
    fclose(fp);
}

void Split_Data_y(YAZARLAR* yzr, char line[100], int nextID){
	char *sp;

	sp = strtok(line, ",");
    yzr->ID = atof(sp);
    nextID = yzr->ID + 1;

    sp = strtok(NULL, ",");
    strcpy(yzr->name, sp);
    
    sp = strtok(NULL, "\n");
    strcpy(yzr->surname, sp);
}

void Split_Data_o(OGRENCILER* ogr, char line[100]){
	char *sp;

	sp = strtok(line, ",");
    strcpy(ogr->ID, sp);

    sp = strtok(NULL, ",");
    strcpy(ogr->name, sp);
    
    sp = strtok(NULL, ",");
    strcpy(ogr->surname, sp);

    sp = strtok(NULL, "\n");
    ogr->scor = atof(sp); 
}

void Split_Data_k(KITAP* ktp, char line[100]){
	char *sp;

	sp = strtok(line, ",");
    strcpy(ktp->kitapAdi, sp);

    sp = strtok(NULL, ",");
    strcpy(ktp->ISBN, sp);

    sp = strtok(NULL, "\n");
    ktp->adet = atof(sp); 
}

void Split_Data_ky(KITAPYAZAR* kit, char line[100]){
	char *sp;

	sp = strtok(line, ",");
    strcpy(kit->ISBN, sp);

    sp = strtok(NULL, "\n");
    kit->yazarID = atof(sp); 
}

