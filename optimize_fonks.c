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

void(void* head){

    YAZARLAR *yazar =(YAZARLAR)malloc(sizeof(YAZARLAR));
    *head = yazar;
    yazar->next = NUll;
    yazar->ID = 12;

}

int main(){

    YAZARLAR *yzr = NULL;
    OGRENCILER *ogr = NULL;



    return 0;
}

void takeOgrenciler(OGRENCILER **ogrenci, (*yontem)(OGRENCILER *)){
    FILE *fp;
    OGRENCILER *ogr = (OGRENCILER*)malloc(sizeof(OGRENCILER));
    if(ogr == NULL){
        exit(-1);
    } 

    ogr->next = NULL;
    if(*ogrenci==NULL){
        *ogrenci=ogr;
        return;
    }

    OGRENCILER *curr = *ogrenci;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ogr;
    ogr->prev = curr;

    yontem(ogr);
    ogr->scor = 100;

    
    fclose(fp);
}

void user(OGRENCILER* ogrenci){
    printf("Ogrenci bilfilerini giriniz(sirasiyle ad, soyad, numara.): ");
    scanf("%s %s %s", ogr->name, ogr->surname, ogr->ID);
    fp = fopen("Ogrenciler.csv", "a");
    printf("%s %s %s %d", ogr->ID, ogr->name, ogr->surname, ogr->scor);
    fprintf(fp, "\n%s,%s,%s,%d", ogr->ID, ogr->name, ogr->surname, ogr->scor);
}
 void file(OGRENCILER* ogrenci){
    fp = fopen("Ogrenciler.csv","r+");
    char line[100];
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
void takeOgrenciler_file(OGRENCILER **ogrenci){
    FILE *fp;
    OGRENCILER *ogr = (OGRENCILER*)malloc(sizeof(OGRENCILER));
    if(ogr == NULL){
        exit(-1);
    }

    char line[100];
    fp = fopen("Ogrenciler.csv","r+");
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
            printf("", curr->)
        }
        prev = curr;
        curr = curr->next;
    }

    return found;
}
