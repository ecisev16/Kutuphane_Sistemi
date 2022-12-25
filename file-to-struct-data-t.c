#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct yazar{
    char name[30];
    char surname[30];
    int ID;
    int scor;
    struct yazar *next;
}YAZAR;

void yazar_e_s_g(YAZAR **);
int takeYazarlar_file(YAZAR **);
int takeYazarlar_user(YAZAR **, int ); 
void printYazarlar(YAZAR **);
void deleteYazarlar(YAZAR **);

int main(){
    
    YAZAR *yazar = NULL;
    int option;
    int option2;
    int nextID;

    printf("Yapmak istediginiz islemin numarasini giriniz.\n\nOGRENCI ISLEMLERI\n\n1- Ogrenci Ekle, Sil, GUncelle\n2- Ogrenci Bilgisi Goruntuleme\n3- Kitap Teslim Etmemis Ogrencileri Listele\4- Cezali Ogrencileri Listele\n5- TUm Ogrencileri Listele\n6- Kitap Odunc Al/Teslim Et\n\nKITAP ISLEMLERI\n\n7- Kitap Ekle, Sil, Guncelle\n8- Kitap Bilgisi Goruntuleme\n9- Raftaki Kitaplari Listele\n10- Zamaninda Teslim Edilmeyen Kitaplari Listele\n11- Kitap-Yazar Eslestir \n12- Kitabin Yazarini Guncelle\n\nYAZAR ISLEMLERI\n\n13- Yazar Ekle, Sil, Guncelle\n14- Yazar Bilgisi Goruntuleme\n\n\n Cikmak icin 15 e basin.\n");
    nextID = takeYazarlar_file(&yazar);
    switch(option){
        case 1 : break;
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
            printf("Hangi islemi yapmak istediginizi seciniz:\n1-Ekle\n2-cikar\n3-güncelle");
            scanf("%d", option2);
            switch(option2){
                case 1 : takeYazarlar_user(&yazar, nextID); break;
                case 2 : deleteYazarlar(&yazar); break;
                case 3 : break;
    }
            break;
        case 14 : printYazarlar(&yazar);
        case 15 :
    }
    
    

    return 0;
}

void yazar_e_s_g(YAZAR **yazar){

    int option;
    int nextID;
    nextID = takeYazarlar_file(&yazar);
    printf("Hangi islemi yapmak istediginizi seciniz:\n1-Ekle\n2-cikar\n3-güncelle");
    scanf("%d", option);

    switch(option){
        case 1 : takeYazarlar_user(&yazar, nextID); break;
        case 2 : deleteYazarlar(&yazar); break;
        case 3 : break;
    }
    

}

int takeYazarlar_file(YAZAR **yazar){
    FILE *fp;
    int i=0;
    int nextID;
    char line[100];
    char *sp;

    fp = fopen("Yazarlar.csv", "r+");
    YAZAR *yzr = (YAZAR*)malloc(sizeof(YAZAR));

    if(fgets(line, 100, fp) != NULL){
        *yazar = yzr;
    }
    yzr->next = NULL;
    sp = strtok(line, ",");
    yzr->ID = atof(sp);
    nextID = yzr->ID + 1;

    sp = strtok(NULL, ",");
    strcpy(yzr->name, sp);
    
    sp = strtok(NULL, ",");
    strcpy(yzr->surname, sp);
    
    printf("%d %s %s", yzr->ID, yzr->name, yzr->surname);
    


    while(fgets(line, 100, fp) != NULL){

        YAZAR *yzr = (YAZAR*)malloc(sizeof(YAZAR));
        if(yzr == NULL){
            exit(-1);
        }

        yzr->next = NULL;
        YAZAR *curr = *yazar;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = yzr;

        sp = strtok(line, ",");
        yzr->ID = atof(sp);
        nextID = yzr->ID + 1;

        sp = strtok(NULL, ",");
        strcpy(yzr->name, sp);

        sp = strtok(NULL, ",");
        strcpy(yzr->surname, sp);
        printf("%d %s %s", yzr->ID, yzr->name, yzr->surname);

    }
    
    fclose(fp);
    return nextID;
}

void takeYazarlar_user(YAZAR **person, int nextID){
        FILE *fp;
        YAZAR *yzr = (YAZAR*)malloc(sizeof(YAZAR));

        if(yzr == NULL){
            exit(-1);
        } 

        yzr->next = NULL;
        YAZAR *curr = *person;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = yzr;

        yzr->ID = nextID;

        printf("Yazar bilfilerini giriniz(sirasiyle ad, soyad.): ");
        scanf("%s %s", yzr->name, yzr->surname);
        fp = fopen("Yazarlar.csv", "a");
        printf("%d %s %s", yzr->ID, yzr->name, yzr->surname);
        fprintf(fp, "\n%d,%s,%s", yzr->ID, yzr->name, yzr->surname);
        fclose(fp);
}

void printYazarlar(YAZAR **yazar){
    YAZAR *curr = *yazar;
    while(curr->next != NULL){
        printf("%d %s %s", curr->ID, curr->name, curr->surname);
        curr = curr->next;
    }
    printf("\n%d %s %s", curr->ID, curr->name, curr->surname);
}

void deleteYazarlar(YAZAR **yazar){
    char name[30];
    char surname[30];
    printf("silmek istediğiniz yazar adini giriniz: ");
    scanf("%s %s", name, surname);

    
}


