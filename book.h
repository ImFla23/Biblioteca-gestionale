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
void checkCharCicle(char prompt[], char dest[]){
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
float checkFloatCicle(char prompt[]){
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
            printf("\nbe positive");
        }else{
            return a;
        }
    }
}

//insert book function 

int insertBook( Book arr[], int c) {
    arr[c].code = c;
    checkCharCicle("\ninsert book title: ", arr[c].title);
    checkCharCicle("\ninsert the book's author: ", arr[c].author);
    arr[c].release_year = checkFloatCicle("\ninsert book's release year: ");
    arr[c].avaible_copies=checkFloatCicle("\ninsert number of avaible copies: ");
    arr[c].total_copies=checkFloatCicle("\ninsert number of total copies: ");
    arr[c].price=checkFloatCicle("\ninsert the book's price per unit: ");
    checkCharCicle("\ninsert the book's genre: ", arr[c].genre);
    return c + 1; 
}

//show all book registred function

void showAllBook( Book archive[] , int countArr) {

    if (countArr == 0){
        printf("There isn't any book saved yet");
    }
    
    for(int i =0 ; i<countArr ; i++){

        printf("\n------ BOOK %d ------ \n", i);
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
        codeInsert = checkFloatCicle("\nEnter the book code : ");
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

void printMenu(Book bookArchive[]) {
    int choice = 0;
    int globalCounter = 0;
    int cicleVar = 1;

    while (cicleVar) {
        printf("\n--- LIBRARY MANAGEMENT ---\n");
        printf("1. Insert new book\n");
        printf("2. Show all books\n");
        printf("3. Search book by code\n");
        printf("4. Update available copies\n");
        printf("5. Update unit cost\n");
        printf("6. Register loan\n");
        printf("7. Register return\n");
        printf("8. Calculate total archive value\n");
        printf("9. Count books by genre\n");
        printf("10. Find book with highest number of copies\n");
        printf("11. Calculate average publication year\n");
        printf("12. Exit\n");
        choice = checkFloatCicle("\nChoose one operation: ");

        switch (choice) {
        case 1:
            printf("\nYou choose to ---INSERT A NEW BOOK---");
            if (globalCounter >= 100) {
                printf("\nYou can't add books anymore, limit reached! ");
                break;
            }
            globalCounter = insertBook(bookArchive, globalCounter);
            printf ("%d", globalCounter);
            break;
        case 2: 
            printf("\nYou choose to ---SHOW ALL BOOKS---");
            showAllBook(bookArchive, globalCounter);
            break;
        case 3: 
            printf("\nYou choose to ---SEARCH BOOKS BY CODE---");
            SearchByCode(bookArchive, globalCounter);
            break;
        case 12:
            printf("\nThank you for using this management app! See you next time...\n");
            cicleVar = 0;
            break;
        default:
            printf("\nChoice must be from 1 to 12\n");
            break;
        }
    }
    
}

#endif