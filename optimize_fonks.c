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