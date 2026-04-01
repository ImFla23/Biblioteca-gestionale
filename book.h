#ifndef BOOK_H
#define BOOK_H

#include <string.h>
#include <stdio.h>
typedef struct 
{
    int code;
    char title[100];
    char author[100];
    int release_year;
    int avaible_copies;
    int total_copies;
    float price;
    char genre[50];
} Book;

//check functions 

//quando è char la funzione non puo tornare una stringa intera, quindi non torniamo nulla ma assegnamo la stringa all'array inserito nei parametri
void check_char_cicle(char prompt[], char dest[]){
    while(1)
    {
        printf("%s", prompt);
        scanf("%s", dest);
        if (strlen(dest) > 99) {
            printf("troppi caratteri\n");
            int c;
            while((c = getchar()) != '\n' && c != EOF) {};
            continue;
        }else{
            break;
        }
    }
}

//quando la funzione controlla i numeri torna sempre un float 
float check_float_cicle(char prompt[]){
    float a;
    while(1)
    {
        printf("%s", prompt);
        if (scanf("%f", &a) != 1) {
            printf("\nNon inserire caratteri! Inserisci numeri!");
            int c;
            while((c = getchar()) != '\n' && c != EOF) {};
            continue;
        }
        if(a<=0){
            printf("be positive");
        }else{
            return a;
        }
    }
}

//insert book function 

void insert_book( Book arr[], int c) {
    arr[c].code = c;
    check_char_cicle("\ninsert book title: ", arr[c].title);
    check_char_cicle("\ninsert the book's author: ", arr[c].author);
    arr[c].release_year = check_float_cicle("\ninsert book's release year: ");
    arr[c].avaible_copies=check_float_cicle("\ninsert number of avaible copies: ");
    arr[c].total_copies=check_float_cicle("\ninsert number of total copies: ");
    arr[c].price=check_float_cicle("\ninsert the book's price per unit: ");
    check_char_cicle("\ninsert the book's genre: ", arr[c].genre);
}

//show all book registred function

void showAllBook( Book archive[] , int countArr) {

    if (countArr == 0){
        printf("There isn't any book saved yet");
    }
    
    for(int i =0 ; i<countArr ; i++){

        printf("------ BOOK %d ------ \n", i);
        printf("Code:%d\n ",archive[i].code);
        printf("Title:%s\n ",archive[i].title);
        printf("Autor:%s\n ",archive[i].author);
        printf("Year:%d\n ",archive[i].release_year);
        printf("Genre:%s\n ",archive[i].genre);
        printf("Copies_Avaible:%d\n ",archive[i].avaible_copies);
        printf("Total_copies:%d\n ",archive[i].total_copies);
        printf("Price:%0.2f\n ",archive[i].price);
    }
}

//search book by id code function

void SearchByCode( Book archive[] , int countArr){
    int a = 1; //per ciclo while
    int codeInsert;
    int found = 0; 

    while (a) {
        codeInsert = check_float_cicle("\nEnter the book code : ");
        codeInsert = (int)codeInsert; //trasformo in intero

        for(int i=0 ; i<countArr ; i++){
            if(archive[i].code == codeInsert){
                printf("\n ------ HERE'S THE BOOK %d ------ \n", i);
                printf("Code:%d\n ",archive[i].code);
                printf("Title:%s\n ",archive[i].title);
                printf("Autor:%s\n ",archive[i].author);
                printf("Year:%d\n ",archive[i].release_year);
                printf("Genre:%s\n ",archive[i].genre);
                printf("Copies_Avaible:%d\n ",archive[i].avaible_copies);
                printf("Total_copies:%d\n ",archive[i].total_copies);
                printf("Price:%0.2f\n ",archive[i].price);
                found = 1;
                a = 0;
            }
        }
        if (!found) {
            printf("\nThis book does not exist ?!");
            printf("\nRetry: ");
        }
    }
}

#endif