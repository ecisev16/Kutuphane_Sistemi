#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct yazar{
    char name[30];
    char surname[30];
    int ID;
    struct yazar *next;
}YAZAR;

typedef struct ogrenci{
    char name[30];
    char surname[30];
    char ID[10];
    int scor;
    struct ogrenci *next; 
    struct ogrenci *prev;  
}OGRENCI;

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
    int gun;
    int ay;
    int yil;
}TARIH;

typedef struct kitapOdunc{
    char etiketNo[20];
    char ogrID[10];
    int islemTipi:1;
    struct tarih islemTarihi;
    struct kitapOdunc *next;
}KITAPODUNC;

int takeYazarlar_file(YAZAR **);
void printYazarlar(YAZAR **);
int deleteYazarlar(YAZAR **);
void takeOgrenciler_file(OGRENCI **);
void takeOgrenciler_user(OGRENCI **);
void printOgrenciler(OGRENCI **);
int deleteOgrenciler(OGRENCI **);
void takeKitaplar_file(KITAP **);
void Split_Data_y(YAZAR*,char line[100], int);
void Split_Data_o(OGRENCI*, char line[100]);
void Split_Data_k(KITAP*, char line[100]);
void Split_Data_ky(KITAPYAZAR* , char line[100]);
void takeKitapYazar_file(KITAPYAZAR **kityaz);
void Split_Data_ko(KITAPODUNC*,char line[100]);
void takeKitapOdunc_file(KITAPODUNC **, KITAP**);
void showYazar(YAZAR **, KITAPYAZAR ** , KITAP ** );
void showRaftakiler(KITAPODUNC **);
void showOgrenci(OGRENCI **, KITAPODUNC ** , KITAP **);
void teslimInfo(OGRENCI **, KITAPODUNC **);
void takeKitaplar_user(KITAP **, YAZAR **, KITAPYAZAR **);
void takeYazarlar_user(YAZAR **, char name[30], char surname[30]);
void kitapInfo(KITAP **, KITAPYAZAR **, YAZAR **, char Name[30]);
void takeOrnek(KITAPORNEK **);
void insideLinkedlist(KITAP **);
void matchingKitapYazar(KITAP **, KITAPYAZAR **, YAZAR **);
void KitYazGuncelle(KITAP **, KITAPYAZAR **, YAZAR **);
void kitOduncAl(KITAPODUNC**, KITAP**);

int main(){
    YAZAR *yazar = NULL;
    OGRENCI *ogrenci = NULL;
    KITAP *kitap = NULL;
    KITAPYAZAR *kityaz = NULL;
    KITAPODUNC *kitOd = NULL;
    KITAPORNEK *kitOrn = NULL;


    int nextID;
    int option;
    int option2;
    char name[30];
    char surname[30];
    char kitName[50];

    printf("\nYapmak istediginiz islemin numarasini giriniz.\n\nOGRENCI ISLEMLERI\n\n1- Ogrenci Ekle, Sil, GUncelle\n2- Ogrenci Bilgisi Goruntuleme\n3- Kitap Teslim Etmemis Ogrencileri Listele\4- Cezali Ogrencileri Listele\n5- TUm Ogrencileri Listele\n6- Kitap Odunc Al/Teslim Et\n\nKITAP ISLEMLERI\n\n7- Kitap Ekle, Sil, Guncelle\n8- Kitap Bilgisi Goruntuleme\n9- Raftaki Kitaplari Listele\n10- Zamaninda Teslim Edilmeyen Kitaplari Listele\n11- Kitap-Yazar Eslestir \n12- Kitabin Yazarini Guncelle\n\nYAZAR ISLEMLERI\n\n13- Yazar Ekle, Sil, Guncelle\n14- Yazar Bilgisi Goruntuleme\n\n");
    scanf("%d", &option);
    nextID = takeYazarlar_file(&yazar);
    takeOgrenciler_file(&ogrenci);
    takeKitaplar_file(&kitap);
    insideLinkedlist(&kitap);
    takeKitapYazar_file(&kityaz);
    takeKitapOdunc_file(&kitOd,&kitap);

    while(option != 15){

        switch(option){
            case 1 :
                printf("\nHangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                scanf("%d", &option2);
                while(option2!=4){

                    switch(option2){
                        case 1 :
                            //printf("Kaydetmek istediginiz ogrenci ismini giriniz: ");
                            //scanf("%s %s",name, surname);
                            takeOgrenciler_user(&ogrenci);
                            break;
                        case 2 :
                            printf("\n\n\n%d\n\n\n",deleteOgrenciler(&ogrenci));
                            printOgrenciler(&ogrenci);
                        break;
                        case 3 : break;
                    }
                    printf("\nHangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                    scanf("%d", &option2);
                }

                break;           
            break;
            case 2 : 
                showOgrenci(&ogrenci, &kitOd, &kitap);
            break;
            case 3 : 
                teslimInfo(&ogrenci, &kitOd);
            break;
            case 4 : break;
            case 5 :
                printOgrenciler(&ogrenci);
            break;
            case 6 : 
                kitOduncAl(&kitOd, &kitap);
            break;
            case 7 :
                printf("\nHangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                scanf("%d", &option2);
                while(option2!=4){

                    switch(option2){
                        case 1 :
                            //char kitName[50];
                            //gets(kitName);
                            //puts(kitName);
                            
                            takeKitaplar_user(&kitap, &yazar, &kityaz);
                            break;
                        case 2 :
                            //printf("\n\n\n%d\n\n\n",deleteOgrenciler(&ogrenci));
                            //printOgrenciler(&ogrenci);
                        break;
                        case 3 : break;
                    }
                    printf("\nHangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                    scanf("%d", &option2);
                }

                break;     
            break;
            case 8 : 
                
                printf("Aramak istediginiz kitap ismini giriniz: ");
                getchar();
                gets(kitName);
                kitapInfo(&kitap, &kityaz, &yazar, kitName);
            break;
            case 9 : break;
            case 10 : break;
            case 11 : 
                matchingKitapYazar(&kitap, &kityaz, &yazar);
            break;
            case 12 :
                KitYazGuncelle(&kitap, &kityaz, &yazar);
                printYazarlar(&yazar);
            break;
            case 13 : 
                printf("\nHangi islemi gerceklestireceksiniz?\n1- Ekle\n2- Sil\n3-Guncelle\n4-Sekmeden Cik\n\n"); 
                scanf("%d", &option2);
                while(option2!=4){

                    switch(option2){
                        case 1 : 
                            printf("Kaydetmek istediginiz yazar ismini giriniz: ");
                            scanf("%s %s",name, surname);
                            takeYazarlar_user(&yazar, name, surname); 
                            nextID++;
                            break;
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
            case 14 :
                showYazar(&yazar, &kityaz, &kitap);
            break;  // printYazarlar(&yazar);


        }
        printf("\nYapmak istediginiz islemin numarasini giriniz.\n\nOGRENCI ISLEMLERI\n\n1- Ogrenci Ekle, Sil, GUncelle\n2- Ogrenci Bilgisi Goruntuleme\n3- Kitap Teslim Etmemis Ogrencileri Listele\4- Cezali Ogrencileri Listele\n5- TUm Ogrencileri Listele\n6- Kitap Odunc Al/Teslim Et\n\nKITAP ISLEMLERI\n\n7- Kitap Ekle, Sil, Guncelle\n8- Kitap Bilgisi Goruntuleme\n9- Raftaki Kitaplari Listele\n10- Zamaninda Teslim Edilmeyen Kitaplari Listele\n11- Kitap-Yazar Eslestir \n12- Kitabin Yazarini Guncelle\n\nYAZAR ISLEMLERI\n\n13- Yazar Ekle, Sil, Guncelle\n14- Yazar Bilgisi Goruntuleme\n\n");
        scanf("%d", &option);
    }
    

    return 0;
}



int takeYazarlar_file(YAZAR **yazar){
    FILE *fp;
    //int i=0;
    int nextID;
    char line[100];
    char *sp;

    fp = fopen("Yazarlar.csv", "r+");
    YAZAR *yzr = (YAZAR*)malloc(sizeof(YAZAR));

    if(fgets(line, 100, fp) != NULL){
        *yazar = yzr;
    }
    yzr->next = NULL;
    
    Split_Data_y(yzr, line, nextID);
    
    //printf("\n\n\n%d %s %s", yzr->ID, yzr->name, yzr->surname);
    


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

        Split_Data_y(yzr, line, nextID);
        //printf("\n%d %s %s", yzr->ID, yzr->name, yzr->surname);

    }
    
    fclose(fp);
    return nextID;
}

void takeYazarlar_user(YAZAR **yazar, char name[30], char surname[30]){
        FILE *fp;
        YAZAR *yzr = (YAZAR*)malloc(sizeof(YAZAR));
        if(yzr == NULL){
            exit(-1);
        } 
        
        yzr->next = NULL;
        if(*yazar==NULL){
            *yazar=yzr;
            return;
        }
        
        YAZAR *curr = *yazar;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = yzr;
        yzr->ID = curr->ID + 1;

        strcpy(yzr->name, name);
        strcpy(yzr->surname, surname);
        fp = fopen("Yazarlar.csv", "a");
        printf("%d %s %s", yzr->ID, yzr->name, yzr->surname);
        fprintf(fp, "\n%d,%s,%s", yzr->ID, yzr->name, yzr->surname);
        
        fclose(fp);
        return;
}

void printYazarlar(YAZAR **yazar){
    YAZAR *curr = *yazar;
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

int deleteYazarlar(YAZAR **yazar){

    char name[30];
    char surname[30];
    int found = 0;
    printf("silmek istediğiniz yazar adini ve soyadini giriniz: ");
    scanf("%s %s", name, surname);

    YAZAR *curr = *yazar;
    YAZAR *prev = NULL;

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

void showYazar(YAZAR **yazar, KITAPYAZAR ** kityaz, KITAP ** kitap){

    char name[30];
    char surname[30];
    int found = 0;
    int found2 = 0;
    printf("\nAramak istediğiniz yazar adini ve soyadini giriniz: ");
    scanf("%s %s", name, surname);

    YAZAR *curr = *yazar;
    YAZAR *prev = NULL;

    KITAPYAZAR *curr2 = *kityaz;
    KITAPYAZAR *prev2 = NULL;

    KITAP *curr3 = *kitap;
    KITAP *prev3 = NULL;

    while((curr!=NULL) && !found){
        if((strcmp(curr->name, name) == 0)&&(strcmp(curr->surname, surname) == 0)){ //&&(strcmp(curr->surname, surname) == 0)  (strcmp(curr->name, name) == 0)&&
            found = 1;
            //printf("\nbuldum");
            printf("yazarin ID'si: %d\n", curr->ID);
            while(curr2!=NULL){
                if(curr->ID == curr2->yazarID){
                    //printf("\nbuldum2:");
                    
                    curr3 = *kitap;
                    found2 = 0;
                    while((curr3!=NULL) && !found2){
                        if(strcmp(curr3->ISBN, curr2->ISBN) == 0){
                            found2 = 1;
                            printf("%s adli kitabi bulunmakta\n", curr3->kitapAdi);
                            kitapInfo(kitap, kityaz, yazar, curr3->kitapAdi);
                        }
                        prev3 = curr3;
                        curr3 = curr3->next;
                    }
                    
                }
                prev2 = curr2;
                curr2 = curr2->next;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    /*free(curr);
    free(curr2);
    free(curr3);
    free(prev);
    free(prev2);
    free(prev3);*/
    return;
}


void takeOgrenciler_file(OGRENCI **ogrenci){
    FILE *fp;
    OGRENCI *ogr = (OGRENCI*)malloc(sizeof(OGRENCI));
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

    //printf("\n\n%s %s %s %d", ogr->ID, ogr->name, ogr->surname, ogr->scor);

    while(fgets(line, 100, fp) != NULL){

        OGRENCI *ogr = (OGRENCI*)malloc(sizeof(OGRENCI));
        if(ogr == NULL){
            exit(-1);
        }

        ogr->next = NULL;
        OGRENCI *curr = *ogrenci;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = ogr;
        ogr->prev = curr;

        Split_Data_o(ogr, line);

        //printf("\n%s %s %s %d", ogr->ID, ogr->name, ogr->surname, ogr->scor);

    }
}

void takeOgrenciler_user(OGRENCI **ogrenci){
    FILE *fp;
    OGRENCI *ogr = (OGRENCI*)malloc(sizeof(OGRENCI));
    if(ogr == NULL){
        exit(-1);
    } 


    ogr->next = NULL;
    if(*ogrenci==NULL){
        *ogrenci=ogr;
        return;
    }

    OGRENCI *curr = *ogrenci;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ogr;
    ogr->prev = curr;
    ogr->scor = 100;

    printf("Ogrenci bilgilerini giriniz(sirasiyle ad, soyad, numara.): ");
    scanf("%s %s %s", ogr->name, ogr->surname, ogr->ID);
    fp = fopen("Ogrenciler.csv", "a");
    printf("%s %s adli ogrenci kutuphaneye kaydedilmistir", ogr->name, ogr->surname);
    fprintf(fp, "\n%s,%s,%s,%d", ogr->ID, ogr->name, ogr->surname, ogr->scor);

    
    fclose(fp);
}

void printOgrenciler(OGRENCI **ogrenci){
    OGRENCI *curr = *ogrenci;
    FILE *fp;
    fp = fopen("Ogrenciler.csv","w");
    while(curr->next != NULL){
        printf("%s %s %s %d\n", curr->ID, curr->name, curr->surname, curr->scor);
        fprintf(fp, "%s,%s,%s,%d\n", curr->ID, curr->name, curr->surname, curr->scor);
        curr = curr->next;
    }
    printf("%s %s %s %d", curr->ID, curr->name, curr->surname, curr->scor);
    fprintf(fp, "%s,%s,%s,%d", curr->ID, curr->name, curr->surname, curr->scor);
    fclose(fp);
}

int deleteOgrenciler(OGRENCI **ogrenci){

    char name[30];
    char surname[30];
    int found = 0;
    printf("silmek istediğiniz ogrenci adini ve soyadini giriniz: ");
    scanf("%s %s", name, surname);

    OGRENCI *curr = *ogrenci;
    OGRENCI *prev = NULL;

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

void showOgrenci(OGRENCI **ogrenci, KITAPODUNC ** kitOd, KITAP **kitap){

    char name[30];
    char surname[30];
    int found = 0;
    int found2 = 0;
    char *token;
    printf("\nAramak istediğiniz ogrenci adini ve soyadini giriniz: ");
    scanf("%s %s", name, surname);

    OGRENCI *curr = *ogrenci;
    OGRENCI *prev = NULL;

    KITAPODUNC *curr2 = *kitOd;
    KITAPODUNC *prev2 = NULL;

    KITAP *curr3 = *kitap;
    KITAP *prev3 = NULL;

    while((curr!=NULL) && !found){
        if((strcmp(curr->name, name) == 0)&&(strcmp(curr->surname, surname) == 0)){ //&&(strcmp(curr->surname, surname) == 0)  (strcmp(curr->name, name) == 0)&&
            found = 1;
            //printf("\nbuldum");
            printf("Ogrenci numarasi: %s\n", curr->ID);
            printf("Puani: %d\n", curr->scor);
            printf("Aldigi kitaplar: \n");
            while(curr2!=NULL){
                if(strcmp(curr->ID,curr2->ogrID)==0){
                    //printf("\nbuldum2:");
                    found2 = 0;
                    curr3 = *kitap;
                    prev3 = NULL;
                    while((curr3!=NULL) && !found2){
                        strcpy(token,curr2->etiketNo);
                        token = strtok(token,"_");
                        if(strcmp(curr3->ISBN, token) == 0){
                            found2 = 1;
                            printf("%s\n", curr3->kitapAdi);
                        }
                        prev3 = curr3;
                        curr3 = curr3->next;
                    }
                }
                prev2 = curr2;
                curr2 = curr2->next;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}


void takeKitaplar_file(KITAP **kitap){

    FILE *fp;
    //int i=0;
    char line[100];
    char *sp;
    int i=1;
    int j=0;

    fp = fopen("Kitaplar.csv","r+");
    KITAP *ktp = (KITAP*)malloc(sizeof(KITAP));

    if(fgets(line, 100, fp) != NULL){
        *kitap = ktp;
    }
    ktp->next = NULL;
    ktp->head = NULL;
    Split_Data_k(ktp,line); 
    KITAP *currH = *kitap;
    //currH->head = ktp->head;


    currH->head = ktp->head;
    takeOrnek(&ktp->head);

    while(currH->head->next != NULL){
        i++;
        currH->head = currH->head->next;
    }

    strcpy(currH->head->Durum,"rafta");
    sprintf(currH->head->EtiketNo, "%s_%d", ktp->ISBN, i);
    i=1;
    printf("%s", currH->head->EtiketNo);

    //printf("\n\n%s %s %d", ktp->kitapAdi, ktp->ISBN, ktp->adet);

    while(fgets(line, 100, fp) != NULL){

        KITAP *ktp = (KITAP*)malloc(sizeof(KITAP));
        if(ktp == NULL){
            exit(-1);
        }

        ktp->next = NULL;
        ktp->head = NULL;
        KITAP *curr = *kitap;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = ktp;
        Split_Data_k(ktp,line);

        currH = ktp;


        //currH->head = ktp->head;
        takeOrnek(&ktp->head);
        while(currH->head->next != NULL){
            i++;
            currH->head = currH->head->next;
        }
            
        strcpy(currH->head->Durum,"rafta");
        sprintf(currH->head->EtiketNo, "%s_%d", ktp->ISBN, i);
        i=1;
        printf("%s", currH->head->EtiketNo);
    }  
        //i=1;
        //printf("\n%s %s %d", ktp->kitapAdi, ktp->ISBN, ktp->adet);

    
}

void insideLinkedlist(KITAP **kitap){
    KITAP *curr = *kitap;
    KITAP *currH = *kitap;
    int i=1;
    int j;
    while(curr != NULL){
        for(j=1;j<curr->adet;j++){ 
            currH->head = curr->head;
            takeOrnek(&curr->head);
            while(currH->head->next != NULL){
                i++;
                currH->head = currH->head->next;
            }
            strcpy(currH->head->Durum,"rafta");
            sprintf(currH->head->EtiketNo, "%s_%d", curr->ISBN, i);
            printf("\n%s", currH->head->EtiketNo);
            i=1;
        }

        curr = curr->next;

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

void takeKitapOdunc_file(KITAPODUNC **kitOd, KITAP** kitap){
    FILE *fp;
    //int i=0;
    int nextID;
    char line[100];
    char *sp;
    char *token;
    int found = 0;
    int found2 = 0;

    fp = fopen("KitapOdunc.csv", "r+");
    KITAPODUNC *oduc = (KITAPODUNC*)malloc(sizeof(KITAPODUNC));

    if(fgets(line, 100, fp) != NULL){
        *kitOd = oduc;
    }
    oduc->next = NULL;
    
    Split_Data_ko(oduc,line);

    //KITAPODUNC *curr = *kitOd;
    //KITAPODUNC *prev = NULL;

    KITAP *curr2 = *kitap;
    KITAP *prev2 = NULL;
    strcpy(token,oduc->etiketNo);
    token = strtok(token,"_");
    printf("        %s", token);
    if(oduc->islemTipi == 0){
    while((curr2!=NULL)&&(found==0)){
        if(strcmp(curr2->ISBN,token)==0){
            printf("\nbuldum!");
            found = 1;
            while((curr2->head != NULL)&&(found2==0)){
                printf("%s\n", curr2->head->EtiketNo);
                printf("%s\n", oduc->etiketNo);
                if(strcmp(oduc->etiketNo,curr2->head->EtiketNo)==0){
                    printf("\nbuldum2");
                    found2 = 1;
                    strcpy(curr2->head->Durum,oduc->ogrID);
                    printf("Odunc verilen kitap: %s\n", curr2->head->Durum);
                }
                curr2->head=curr2->head->next;
            }
        }
        prev2 = curr2;
        curr2 = curr2->next;
    }
    }
    
    //printf("\n\n\n%s %s %d %d.%d.%d", oduc->etiketNo, oduc->ogrID, oduc->islemTipi, oduc->islemTarihi.gun, oduc->islemTarihi.ay, oduc->islemTarihi.yil);
    


    while(fgets(line, 100, fp) != NULL){

        KITAPODUNC *oduc = (KITAPODUNC*)malloc(sizeof(KITAPODUNC));
        if(oduc == NULL){
            exit(-1);
        }

        oduc->next = NULL;
        KITAPODUNC *curr = *kitOd;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = oduc;

        Split_Data_ko(oduc,line);
        //printf("\n%s %s %d %d.%d.%d", oduc->etiketNo, oduc->ogrID, oduc->islemTipi, oduc->islemTarihi.gun, oduc->islemTarihi.ay, oduc->islemTarihi.yil);
        curr2 = *kitap;
        prev2 = NULL;
        found=0;
        found2=0;
        strcpy(token,oduc->etiketNo);
        token = strtok(token,"_");
        if(oduc->islemTipi == 0){
        while((curr2!=NULL)&&(found==0)){
            if(strcmp(curr2->ISBN,token)==0){
                found = 1;
                while((curr2->head != NULL)&&(found2==0)){
                    if(strcmp(oduc->etiketNo,curr2->head->EtiketNo)==0){
                        found2 = 1;
                        strcpy(curr2->head->Durum,oduc->ogrID);
                        printf("Odunc verilen kitap: %s\n", curr2->head->Durum);
                    }
                    curr2->head=curr2->head->next;
                }
            }
            prev2 = curr2;
            curr2 = curr2->next;
        }
        }
    }
    
    fclose(fp);
}

void showRaftakiler(KITAPODUNC **kitOd){
    
    KITAPODUNC *curr = *kitOd;
    KITAPODUNC *prev = NULL;

    while(curr!=NULL){
        if(curr->islemTipi == 0){
            printf("\nbuldum");
            printf("\n%s", curr->etiketNo);
            
        }
        prev = curr;
        curr = curr->next;
    }
    

    return;
}


void Split_Data_y(YAZAR* yzr, char line[100], int nextID){
	char *sp;

	sp = strtok(line, ",");
    yzr->ID = atof(sp);
    nextID = yzr->ID + 1;

    sp = strtok(NULL, ",");
    strcpy(yzr->name, sp);
    
    sp = strtok(NULL, "\n");
    strcpy(yzr->surname, sp);
}

void Split_Data_o(OGRENCI* ogr, char line[100]){
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

void Split_Data_ko(KITAPODUNC* kitOd, char line[100]){
	char *sp;

	sp = strtok(line, ",");
    strcpy(kitOd->etiketNo, sp);

    sp = strtok(NULL, ",");
    strcpy(kitOd->ogrID, sp); 

    sp = strtok(NULL, ",");
    kitOd->islemTipi = atof(sp); 

    sp = strtok(NULL, ".");
    kitOd->islemTarihi.gun = atof(sp); 

    sp = strtok(NULL, ".");
    kitOd->islemTarihi.ay = atof(sp); 

    sp = strtok(NULL, "\n");
    kitOd->islemTarihi.yil = atof(sp); 

}


void teslimInfo(OGRENCI **ogrenci, KITAPODUNC **kitOd){

    KITAPODUNC *curr = *kitOd;
    KITAPODUNC *prev = NULL;

    KITAPODUNC *curr2 = NULL;
    KITAPODUNC *prev2 = NULL;

    OGRENCI *ogr = *ogrenci;
    OGRENCI *preogr = NULL;

    int teslim = 0;
    int eci = 0;

    while(curr!=NULL){
        if(curr->islemTipi == 0){
            curr2 = curr;
            prev2 = prev;
            prev2 = curr2;
            curr2 = curr2->next;
            while((curr2 != NULL)&& (teslim == 0)){
                if((curr->etiketNo == curr2->etiketNo) && (curr2->islemTipi == 1)){
                    teslim = 1;
                }
                prev2 = curr2;
                curr2 = curr2->next;
            }
            if(teslim == 0){

                printf("\nteslim etmeyen: %s",curr->ogrID);
                ogr = *ogrenci;
                preogr = NULL;
                eci = 0;
                while(ogr != NULL){

                    if((strcmp(curr->ogrID, ogr->ID)==0)&&(eci==0)){  //fp yapabilirsin
                        printf(" %s %s", ogr->name, ogr->surname);    
                        eci = 1;
                    }
                    preogr = ogr;
                    ogr = ogr->next;                                   //fp yapabilirsin

                }

            }
        }
        prev = curr;
        curr = curr->next;

    }
}


void takeOrnek(KITAPORNEK **kitapOrnek){
 
    KITAPORNEK *kitOrn = (KITAPORNEK*)malloc(sizeof(KITAPORNEK));
    if(kitOrn == NULL){
        exit(-1);
    }

    //strcpy(kitOrn->Durum, durum);
    //strcpy(kitOrn->EtiketNo, etiketNo);
    //kitOrn->next = NULL;
    //strcpy(kitOrn->Durum,durum);
    //strcpy(kitOrn->EtiketNo,etiketNo);
    if(*kitapOrnek==NULL){
        *kitapOrnek = kitOrn;
        kitOrn->next = NULL;
        //printf("bbbbbbbb");
        //printf("%s %s", kitOrn->Durum, kitOrn->EtiketNo);
        return;
    }
    KITAPORNEK *curr = *kitapOrnek;
    while(curr->next != NULL){
        curr = curr->next;
        //printf("aaaaaaaaaaaaaaaa");
    }
    curr->next = kitOrn;
    kitOrn->next = NULL;
    //printf("\n11111111");
    //printf("%s %s", kitOrn->Durum, kitOrn->EtiketNo);
    return ;
}

void takeKitaplar_user(KITAP **kitap, YAZAR **yazar, KITAPYAZAR **kityaz){
    FILE *fp;
    int found = 0;
    int i=1;
    char kitName[50];
    char yazName[50];
    char yazSurname[50];
    int yazarID;
    

    printf("Kitap adini giriniz: ");
    getchar();
    gets(kitName);
    puts(kitName);

    printf("Kitap yazarini giriniz: ");
    scanf("%s %s", yazName, yazSurname);

    KITAP *curr = *kitap;
    KITAP *prev = NULL;

    YAZAR *curr2 = *yazar;
    YAZAR *prev2 = NULL;

    KITAP *curr3 = *kitap;
    KITAP *prev3 = NULL; 

    KITAP *currH = *kitap;

    while((curr != NULL)&& (found==0)){               //curr kitabı tutuyo  //kitap başka bi kitabın kopyası mı?
        if(strcmp(kitName, curr->kitapAdi)==0){
            found = 1;
            //curr->head = NULL; // BURAYI Bİ NOKTADA DEĞİŞTİRMEN LAZIM
            currH->head = curr->head;
            
            takeOrnek(&curr->head);
            //strcpy(curr->head->EtiketNo, curr->ISBN);
            while(currH->head->next != NULL){
                i++;
                currH->head = currH->head->next;
            }
            strcpy(curr->head->Durum,"rafta");
            sprintf(currH->head->EtiketNo, "%s_%d", curr->ISBN, i);
            printf("Etiket numarasi: %s\n", currH->head->EtiketNo);
            curr->adet++; //dosyaya geri yazdırma kısmı var burdan sonra.
            //FILE fpkk;
            //fpkk = fopen("Kitaplar.csv", "w");
            printf("%s kopyasi kutuphaneye eklendi.\n", curr->kitapAdi);

        }
        prev = curr;
        curr = curr->next;

    }

    if(found == 0){

    
    FILE *fpk;
    KITAP *kit = (KITAP*)malloc(sizeof(KITAP));
    if(kit == NULL){
        exit(-1);
    }

    KITAP *kitcurr = *kitap;
    while(kitcurr->next!=NULL){
           kitcurr = kitcurr->next;
    }
    kitcurr->next = kit;
    kit->next = NULL;

    printf("Kitabin ISBN nuramarasini giriniz: ");
    scanf("%s", kit->ISBN);
    strcpy(kit->kitapAdi, kitName);
    kit->adet = 1;
    //strcpy(kit->head->EtiketNo, kit->ISBN);
    //strcat(kit->head->EtiketNo, "_1");
    kit->head = NULL;
    takeOrnek(&kit->head);
    strcpy(kit->head->Durum,"rafta");
    //strcpy(kit->head->EtiketNo, kit->ISBN); //'_1' falanlı bi ifade eklenmesi lazım sonuna
    sprintf(kit->head->EtiketNo, "%s_%d", kit->ISBN, 1);
    printf("Etiket numarasi: %s", kit->head->EtiketNo);
    fpk = fopen("Kitaplar.csv", "a");
    //printf("%s %s %d %s %s", kit->kitapAdi, kit->ISBN, kit->adet, kit->head->EtiketNo, kit->head->Durum);
    printf("%s adli kitap kutuphaneye eklendi.\n", kit->kitapAdi);
    fprintf(fpk, "\n%s,%s,%d", kit->kitapAdi, kit->ISBN, kit->adet);
        
    fclose(fpk);

    
    while((curr2 != NULL)&&(found==0)){
        if((strcmp(yazName, curr2->name)==0)&&(strcmp(yazSurname, curr2->surname)==0)){
            found = 1;
            yazarID = curr2->ID;//yazar ID buradan alınabilir
            printf("%s %s yazarin kitaplarina eklendi.\n", curr2->name, curr2->surname);
        }
        prev2 = curr2;
        curr2 = curr2->next;
        
    }
    if(found == 0){
        
        FILE *fpy;
        //FILE *fpk;
        YAZAR *yaz = (YAZAR*)malloc(sizeof(YAZAR));
        if(yaz == NULL){
            exit(-1);
        } 

        YAZAR *yazcurr = *yazar;
        while(yazcurr->next != NULL){
            yazcurr = yazcurr->next;
        }
        yazcurr->next = yaz;
        yaz->next = NULL;
        yaz->ID = yazcurr->ID + 1;
        yazarID = yaz->ID;

        strcpy(yaz->name, yazName);
        strcpy(yaz->surname, yazSurname);
        fpy = fopen("Yazarlar.csv", "a");
        printf("%d %s %s", yaz->ID, yaz->name, yaz->surname);
        fprintf(fpy, "\n%d,%s,%s", yaz->ID, yaz->name, yaz->surname);
        
        fclose(fpy);

        
    }

    FILE *fpky;
    fpky = fopen("KitapYazar.csv","a");
    fprintf(fpky, "\n%s,%d", kit->ISBN,yazarID);
    fclose(fpky);

    }
    


    
}

void kitapInfo(KITAP **kitap, KITAPYAZAR **kityaz, YAZAR **yazar, char kitName[30]){
    //char kitName[30];
    int found = 0;
    int found2 = 0;
    int found3 = 0;
    //printf("Aramak istediginiz kitap ismini giriniz: ");
    //getchar();
    //gets(kitName);
    //puts(kitName);

    KITAP *curr = *kitap;
    KITAP *prev = NULL;

    KITAPYAZAR *curr2 = *kityaz;
    KITAPYAZAR *prev2 = NULL;

    YAZAR *curr3 = *yazar;
    YAZAR *prev3 = NULL;

    KITAP *curr4 = *kitap;
    
    while((curr->next != NULL)&&(found==0)){
        if(strcmp(kitName, curr->kitapAdi)==0){
            found = 1;
            curr4 = curr;
            while(curr4->head->next != NULL){
                printf("\ndurum ve etiket no: %s %s", curr4->head->Durum, curr4->head->EtiketNo);
                curr4->head = curr4->head->next;
            }
            printf("\ndurum ve etiket no: %s %s", curr4->head->Durum, curr4->head->EtiketNo);
            while((curr2->next!= NULL)&&(found2==0)){
                if(strcmp(curr->ISBN,curr2->ISBN)==0){
                    found2 = 1;
                    while((curr3->next!= NULL)&&(found3==0)){
                        if(curr2->yazarID == curr3->ID){
                            found3 = 1;
                            printf("\nyazar adi: %s %s", curr3->name, curr3->surname);
                        }
                        prev3 = curr3;
                        curr3 = curr3->next;
                    }

                }
                prev2 = curr2;
                curr2 = curr2->next;
            }
        }
        prev = curr;
        curr = curr->next;

    }
}

void matchingKitapYazar(KITAP **kitap, KITAPYAZAR **kityaz, YAZAR **yazar){
    char kitName[30];
    int found = 0;
    int found2 = 0;
    int found3 = 0;
    printf("\nEskestirmek istediginiz kitap ismini giriniz: ");
    getchar();
    gets(kitName);
    //puts(kitName);

    KITAP *curr = *kitap;
    KITAP *prev = NULL;

    KITAPYAZAR *curr2 = *kityaz;
    KITAPYAZAR *prev2 = NULL;

    YAZAR *curr3 = *yazar;
    YAZAR *prev3 = NULL;
    
    while((curr->next != NULL)&&(found==0)){
        if(strcmp(kitName, curr->kitapAdi)==0){
            found = 1;
            while((curr2->next!= NULL)){
                if(strcmp(curr->ISBN,curr2->ISBN)==0){
                    //found2 = 1;
                    found3 = 0;
                    while((curr3->next!= NULL)&&(found3==0)){
                        if(curr2->yazarID == curr3->ID){
                            found3 = 1;
                            printf("yazar adi: %s %s\n", curr3->name, curr3->surname);
                        }
                        prev3 = curr3;
                        curr3 = curr3->next;
                    }

                }
                prev2 = curr2;
                curr2 = curr2->next;
            }
        }
        prev = curr;
        curr = curr->next;

    }
}

void KitYazGuncelle(KITAP **kitap, KITAPYAZAR **kityaz, YAZAR **yazar){
    char name[30];
    char surname[30];
    char kitName[30];
    int found = 0;
    int found2 = 0;
    int found3 = 0;
    printf("\nKitap ismini giriniz: ");
    getchar();
    gets(kitName);
    //puts(kitName);

    KITAP *curr = *kitap;
    KITAP *prev = NULL;

    KITAPYAZAR *curr2 = *kityaz;
    KITAPYAZAR *prev2 = NULL;

    YAZAR *curr3 = *yazar;
    YAZAR *prev3 = NULL;
    
    while((curr->next != NULL)&&(found==0)){
        if(strcmp(kitName, curr->kitapAdi)==0){
            found = 1;
            while((curr2->next!= NULL)){
                if(strcmp(curr->ISBN,curr2->ISBN)==0){
                    //found2 = 1;
                    found3 = 0;
                    while((curr3->next!= NULL)&&(found3==0)){
                        if(curr2->yazarID== curr3->ID){
                            found3 = 1;
                            printf("yazar adi: %s %s\n", curr3->name, curr3->surname);
                            printf("Guncel Ismi giriniz: ");
                            scanf("%s %s", curr3->name, curr3->surname);
                            //strcpy(curr3->name, name);
                            //strcpy(curr3->surname, surname);
                            printf("Guncel yazar: %s %s\n", curr3->name, curr3->surname);
                        }
                        prev3 = curr3;
                        curr3 = curr3->next;
                    }

                }
                prev2 = curr2;
                curr2 = curr2->next;
            }
        }
        prev = curr;
        curr = curr->next;

    }
}

void kitOduncAl(KITAPODUNC **kitapOdunc, KITAP** kitap){
    char *kitISBN;
    char *ogrID;
    int gun;
    int ay;
    int yil;
    int found = 0;
    int found2 = 0;
    printf("Odunc almak istediginiz kitabin ISBN bilgisini giriniz: ");
    scanf("%s", kitISBN);
    printf("Ogrenci ID bilginizi giriniz: ");
    scanf("%s", ogrID);
    printf("Aldiginiz tarihin bilgisini giriniz(gg aa yy).: ");
    scanf("%d %d %d", &gun, &ay, &yil);

    FILE *fpo;
    KITAPODUNC *odunc = (KITAPODUNC*)malloc(sizeof(KITAPODUNC));

    KITAPODUNC *curr = *kitapOdunc;
    KITAPODUNC *prev = NULL;

    KITAP *curr2 = *kitap;
    KITAP *prev2 = NULL;

    
    while((curr2!=NULL)&&(found==0)){
        if(strcmp(curr2->ISBN,kitISBN)==0){
            printf("\nbuldum!");
            found = 1;
            while((curr2->head != NULL)&&(found2==0)){
                printf("%s\n", curr2->head->EtiketNo);
                printf("%s\n", kitISBN);
                if(strcmp(curr2->head->Durum,"rafta")==0){
                    printf("\nbuldum2");
                    found2 = 1;
                    strcpy(curr2->head->Durum,ogrID);
                    printf("Odunc verilen kitap: %s\n", curr2->head->EtiketNo);

                    while(curr->next != NULL){
                        curr = curr->next; 
                    }
                    curr->next = odunc;
                    odunc->next = NULL;
                    odunc->islemTipi = 0;
                    strcpy(odunc->ogrID, ogrID);
                    strcpy(odunc->etiketNo, curr2->head->EtiketNo);
                    odunc->islemTarihi.gun = gun;
                    odunc->islemTarihi.ay = ay;
                    odunc->islemTarihi.yil = yil;

                    fpo = fopen("KitapOdunc.scv", "a");
                    fprintf(fpo,"\n%s,%s,%d,%d.%d.%d", curr2->head->EtiketNo, odunc->ogrID, 0, gun, ay, yil);
                    fclose(fpo);

                    

                }
                curr2->head=curr2->head->next;
            }
        }
        prev2 = curr2;
        curr2 = curr2->next;
    }
    
}

// int odunc(){
//    return 0;
// }

// int teslim(){
//    return 1;
// }