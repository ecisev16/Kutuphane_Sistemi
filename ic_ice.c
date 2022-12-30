#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void takeOrnek(KITAPORNEK **kitapOrnek){
    char durum[10] = "olumlu";
    char etiketno[15] = "123456_1";
    KITAPORNEK *kitOrn = (KITAPORNEK*)malloc(sizeof(KITAPORNEK));
    if(kitOrn == NULL){
        exit(-1);
    }

    kitOrn->next = NULL;
    strcpy(kitOrn->Durum,durum);
    strcpy(kitOrn->EtiketNo,etiketno);
    if(*kitapOrnek==NULL){
        *kitapOrnek = kitOrn;
        //printf("%s %s", kitOrn->Durum, kitOrn->EtiketNo);
        return;
    }

    KITAPORNEK *curr = *kitapOrnek;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = NULL;
    //printf("%s %s", kitOrn->Durum, kitOrn->EtiketNo);


}

void takeKitap(KITAP **kitap){
    char ISBN[10] = "123456";
    char kitapAdi[20] = "eci sev";
    KITAP *kit = (KITAP*)malloc(sizeof(KITAP));
    if(kit == NULL){
        exit(-1);
    } 


    kit->next = NULL;
    kit->adet = 2;
    strcpy(kit->ISBN,ISBN);
    strcpy(kit->kitapAdi,kitapAdi);
    kit->head = NULL;
    takeOrnek(&kit->head);
    if(*kitap==NULL){
        *kitap=kit;
        printf("%s %s %d %s", kit->kitapAdi, kit->ISBN, kit->adet, kit->head->EtiketNo);
        return;
    }

    KITAP *curr = *kitap;
    while(curr->next != NULL){
        curr = curr->next;
        }
    curr->next = kit;
   
    printf("%s %s %d %s", kit->kitapAdi, kit->ISBN, kit->adet, kit->head->EtiketNo);
    return;
}


int main(){
        
    KITAP *kitap = NULL;
    KITAPORNEK *kitapOrnek = NULL;



    takeKitap(&kitap);
}