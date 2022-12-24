#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person{
    char name[30];
    char surname[30];
    int ID;
    int scor;
}PERSON;

/*void nokta(PERSON *person){
    FILE *fp;
    int i;
    int read = 0;

    fp = fopen("Yazarlar.csv", "r+");

    for(i=0;i<8;i++){
        read = fscanf(fp, "%d,%[^,],%[^,],%d", &person[i].ID, person[i].name, person[i].surname, &person[i].scor);
        printf("%s %s\n", person[i].name, person[i].surname);
    }
    fclose(fp);
}*/

/*void ok(PERSON *person){
    FILE *fp;
    int i;

    fp = fopen("Yazarlar.csv", "r+");

    for(i=0;i<8;i++){
        fscanf(fp, "%d,%s\n,%s \n", &person->ID, person->name, person->surname);
        printf("%s\n%s\n", person->name, person->surname);
        person++;
    }
    fclose(fp);
}*/

void take(PERSON *person){
    FILE *fp;
    int i=0;
    char line[100];
    char *sp;

    fp = fopen("Yazarlar.csv", "r+");

    
    while(fgets(line, 100, fp) != NULL){
        sp = strtok(line, ",");
        person[i].ID = atof(sp);

        sp = strtok(NULL, ",");
        strcpy(person[i].name, sp);

        sp = strtok(NULL, ",");
        strcpy(person[i].surname, sp);

        printf("%d %s %s", person[i].ID, person[i].name, person[i].surname);
        i++;

    }
    
    fclose(fp);
}

void insert_end(PERSON** root, int value){
    PERSON *new_Person = (Node*)malloc(sizeof(Node));
    if(new_Person == NULL){
        exit(1);
    }
    new_Person->next = NULL;
    new_Person->x = value;

    if(*root == NULL){          // ilk eleman olarak root'un ne olduguna karar vermek gerekiyor ilk once 
        *root = new_Person; // ?????????
        return;
    }

    PERSON *curr;  
    curr = *root;  // ?????????
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new_Person;

    return;
}

int main(){
    
    PERSON person[8];
    int secim;
    printf("Ok ile okumak icin 1 nokta ile okumak icin 2 take için 3\n");
    scanf("%d", &secim);

    switch(secim){
        case 1 : ok(person); break;
        case 2 : nokta(person); break;
        case 3 : take(person); break;
    }

    return 0;
}