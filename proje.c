#include<stdio.h>
#include<stdlib.h>

typedef struct students{
    int ID;
    char name[30];
    char surname[30];
    int scor;
}STUDENTS;


int main(){
    FILE *file;
    int i;
    file = fopen("Ogrenciler.csv", "r");

    if (file == NULL){
        printf("error opening file.\n");
        return 1;
    }

    STUDENTS student[30];

    int read = 0;
    int records = 0;
    do{
        read = fscanf(file, "%d,%49[^,],%49[^,],%d",
                    &student[records].ID,
                    student[records].name,
                    student[records].surname,
                    &student[records].scor);

        if(read == 4){
            records++;
        }else if(read != 4 && !feof(file)){
            printf("File format incorrect.\n");
            return 1;
        }

        if(ferror(file)){
            printf("Errror reading file.\n");
            return 1;
        }
    }while(!feof(file));

    fclose(file);

    printf("\n%d records read.\n\n", records);

    for(i=0;i<records;i++){
        printf("%d,%s,%s,%d\n",
                    student[i].ID,
                    student[i].name,
                    student[i].surname,
                    student[i].scor);

    }

    printf("\n");

    return 0;
}