#ifndef BOOK_H
#define BOOK_H
#define MAX 100
#define MAX_GENRE 4

#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct  {
    int code;
    char title[MAX];
    char author[MAX];
    int release_year;
    int avaible_copies;
    int total_copies;
    float price;
    char genre[MAX];
} Book;

void fakeLoading() {
    printf("\nLoading. \n");
    sleep(1);
    printf("Loading.. \n");
    sleep(1);
    printf("Loading... \n");
    sleep(1 / 2);
}

//quando è char la funzione non puo tornare una stringa intera, quindi non torniamo nulla ma assegnamo la stringa all'array inserito nei parametri
void checkCharCicle(char prompt[], char dest[]){
    while(1) {
        printf("%s", prompt);
        if (scanf(" %99[^\n]", dest) != 1) {
            // Handle EOF or read error
            dest[0] = '\0';
            break;
        }
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

//lo scnaf torna qualsiasi cosa diversa da 1 quando vi è un errore legato al tipo che si aspetta (se c'è unp scanf che si aspetta un flaot e inserisco un carattere allora tornerà qualcosa != 1)

float checkFloatCicle(char prompt[]){
    float a;
    while(1) {
        printf("%s", prompt);
        if (scanf("%f", &a) != 1) {
            printf("\nNon inserire caratteri! Inserisci numeri!");
            int c;
            while((c = getchar()) != '\n' && c != EOF) {};
            continue;
        }
        if(a<0){
            printf("\nbe positive");
        }else{
            return a;
        }
    }
}

int insertBook( Book arr[], int c, char gen[][10]) {
    arr[c].code = c;
    checkCharCicle("\ninsert book title: ", arr[c].title);
    checkCharCicle("\ninsert the book's author: ", arr[c].author);
    arr[c].release_year = checkFloatCicle("\ninsert book's release year: ");
    arr[c].total_copies=checkFloatCicle("\ninsert number of total copies: ");
    arr[c].avaible_copies=checkFloatCicle("\ninsert number of avaible copies: ");
    while(1) {
        if (arr[c].total_copies < arr[c].avaible_copies) {
            printf("\nYou cannot insert a number of avaible copies higher than the total copies!");
            arr[c].avaible_copies=checkFloatCicle("\ninsert number of avaible copies: ");
        } else {
            break;
        }
    }
    arr[c].price=checkFloatCicle("\ninsert the book's price per unit: ");
    printf("\n--- CHOOSE A GENRE ---\n");
    for (int i = 0; i < MAX_GENRE; i++){
        printf("\n%d. %s", i + 1, gen[i]);
    }
    while (1) {
        int choiceGen = checkFloatCicle("\nYour choice: ");
        if (choiceGen <= 0 || choiceGen > 4 ) {
            printf("\n Choose an appropiate value!");
        } else {
            strcat(arr[c].genre, gen[choiceGen - 1]);
            break;
        }
    }
    fakeLoading();
    printf("\nBook added!");
    return c + 1; 
}


void showAllBook( Book archive[] , int countArr) {
    
    fakeLoading();
    if (countArr == 0) {
        printf("\nThere isn't any book saved yet");
    }

    
    for(int i =0 ; i<countArr ; i++) {

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

void countByGenre(Book archive[], char gen[][10], int countArr) {
    fakeLoading();
    if (countArr == 0) {
        printf("\nThere are no books in the archive!\n");
        return;
    }
    
    int count_genre[MAX_GENRE] = {0};  
    int i,j;


    for ( i = 0; i < MAX_GENRE; i++) {
        for ( j = 0; j < countArr; j++)   {
            if (strcmp(archive[j].genre, gen[i]) == 0) {
                count_genre[i]++;
            }
        }
    }
    for (int i = 0; i < MAX_GENRE; i++) {
    printf("counted genres\n");
    printf("%-10s : %d\n", gen[i], count_genre[i]);
}
    
}

int SearchByCode( Book archive[] , int countArr, int needCode){
    if (countArr == 0) {
        printf("\nThere are no books in the archive!\n");
        return 0;
    }
    
    int a = 1; //per ciclo while
    int codeInsert;
    int found = 0; 

    while (a) {
        codeInsert = checkFloatCicle("\nEnter the book code : ");
        codeInsert = (int)codeInsert; //trasformo in intero

        fakeLoading();

        for(int i=0 ; i<countArr ; i++){
            if(archive[i].code == codeInsert){
                printf("\n ------ HERE'S THE BOOK %d ------ \n", i);
                printf("Code:%d\n ",archive[i].code);
                printf("Title:%s\n ",archive[i].title);
                printf("Autor:%s\n ",archive[i].author);
                printf("Year:%d\n ",archive[i].release_year);
                printf("Genre:%s\n ",archive[i].genre);
                printf("Copies_Available:%d\n ",archive[i].avaible_copies);
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
    if (needCode) //if we need the code we return it, else whe just give a good status and keep going,sry if a made the function an int
        return codeInsert;
    else
        return 1;
}

int ShowAndSelect(Book archive[],int countArr) {
    if (countArr == 0) {
        printf("\nThere are no books in the archive!\n");
        return 0;
    }

    int choice,bookCode;
    while (1) {
        choice = checkFloatCicle("\nDo you wish to view all books or select it by code now?\n 1 - View all books.\n 2 - Select by code.\n 0 - Back to menu'\n");
        switch(choice) {
            case 0:
                return -1;
            case 1:
                showAllBook(archive,countArr);
                continue;
            case 2:
                bookCode=SearchByCode(archive,countArr,1);
                return bookCode;
            default:
                printf("\nPlease insert a valid number\n");
                continue;
        }
    }
}


void updateAvCopies(Book archive[],int countArr, int bookCode) {
    if (countArr == 0) {
        return;
    }
    int index,newCopies;
    if (bookCode == -1){return;}//esce
    while(1) {
        for(int i = 0; i < countArr ; i++){
            if(archive[i].code == bookCode){
                printf("\n ------ HERE'S THE BOOK INFO ------ \n");
                printf("\nIt has: %d of total copies\n ",archive[i].total_copies);
                printf("\nIt has: %d of available copies\n ",archive[i].avaible_copies);
                index=i;
            }
        }
        newCopies = checkFloatCicle("\nInsert the number of new copies: ");
        if(newCopies > archive[index].total_copies) {
            printf("\nNumber of available copies can't be more than the total number of copies, please try again\n");
            continue;
        }
        archive[index].avaible_copies = newCopies;
        fakeLoading();
        printf("\nNumber successfully updated!\n");
        return;
    }
    
}

void updateUnitCost(Book archive[],int countArr, int bookCode) {
    if (countArr == 0) {
        return;
    }
    int index;
    float newPrice;
    if (bookCode == -1) {return;} //esce
    while(1) {
        for(int i = 0 ; i < countArr ; i++) {
            if(archive[i].code == bookCode){
                printf("\n ------ HERE'S THE BOOK INFO ------ \n");
                printf("\nIt has a price of :%0.2f\n for unit",archive[i].price);
                index=i;
            }
        }
        newPrice = checkFloatCicle("\nInsert the new price: ");
        archive[index].price=newPrice;
        fakeLoading();
        printf("\nPrice successfully updated!\n");
        return;
    }
}

// void registerLoanOrReturn (Book archive[], int countArr, int loanReturn) {
//     //se loanregister è 1 allora registrerà un return, se -1 registerà un loan
//     printf("\nWhich book's loan do you want to register?");
//     int bookCode = ShowAndSelect(archive, countArr);
//     updateAvCopies(archive, countArr, bookCode, loanReturn);
//     if (loanReturn == -1) {
//         printf("\nLoan registred!");
//     } else {
//         printf("\nReturn registred!");
//     }
// }

void registerLoan(Book archive[], int countArr) {
    if (countArr == 0) {
        printf("\nThere are no books in the archive!\n");
        return;
    }

    int newCopies, index;
    printf("\nWhich book's loan do you want to register?");
    int bookCode = ShowAndSelect(archive, countArr);
    while (1) {
        for(int i = 0; i < countArr ; i++){
            if(archive[i].code == bookCode){
                    printf("\n ------ HERE'S THE BOOK INFO ------ \n");
                    printf("\nIt has: %d of total copies\n ",archive[i].total_copies);
                    printf("\nIt has: %d of available copies\n ",archive[i].avaible_copies);
                    index=i;
                }
            }
        newCopies = checkFloatCicle("\nInsert the number of copies to be loaned, they will be removed: ");
        if((archive[index].avaible_copies - newCopies) < 0) {
            printf("\nNumber of available copies can't be negative, please try again\n");
            continue;
        }
        archive[index].avaible_copies -= newCopies;
        fakeLoading();
        printf("\nLoan registred!");
        return;
    }
}

void registerReturn (Book archive[], int countArr) {
    if (countArr == 0) {
        printf("\nThere are no books in the archive!\n");
        return;
    }

    int newCopies, index;
    printf("\nWhich book's return do you want to register?");
    int bookCode = ShowAndSelect(archive, countArr);
    while (1) {
        for(int i = 0; i < countArr ; i++){
            if(archive[i].code == bookCode) {
                printf("\n ------ HERE'S THE BOOK INFO ------ \n");
                printf("\nIt has: %d of total copies\n ",archive[i].total_copies);
                printf("\nIt has: %d of available copies\n ",archive[i].avaible_copies);
                index=i;
            }
        }
        newCopies = checkFloatCicle("\nInsert the number of copies returned, they will be added back: ");
        if((newCopies + archive[index].avaible_copies) > archive[index].total_copies) {
            printf("\nNumber of available copies can't be more than the total number of copies, please try again\n");
            continue;
        }
        archive[index].avaible_copies += newCopies;
        fakeLoading();
        printf("\nReturn registred!");
        return;
    }
}

void findBookWithHighestNumberOfCopies(Book archive[], int countArr) {
    fakeLoading();

    if (countArr == 0) {
        printf("\nThere are no books in the archive!\n");
        return;
    }
    
    int max = archive[0].total_copies;
    int bookIndex = 0;
    for (int i = 0; i <= countArr; i++) {
        if (max < archive[i].total_copies) {
            max = archive[i].total_copies;
            bookIndex = i;
        }
    }
    
    printf("\n------ TOP HIGHEST BOOK BY NUMBER OF COPIES IS: %d ------\n", bookIndex);
    printf("Code   : %d\n", archive[bookIndex].code);
    printf("Title  : %s\n", archive[bookIndex].title);
    printf("Author : %s\n", archive[bookIndex].author);
    printf("Total copies    : %d\n", archive[bookIndex].total_copies);
    printf("Available copies: %d\n", archive[bookIndex].avaible_copies);
}

void totalArchiveValue(Book archive[], int countArr) {
    if (countArr == 0) {
        printf("\nThere are no books in the archive!\n");
        return;
    }
    float totalValue = 0.0;

    for (int i = 0; i < countArr; i++) {
        totalValue += archive[i].price * archive[i].total_copies;
    }
    fakeLoading();
    printf("\n------ TOTAL VALUE ARCHIVE ------\n");
    printf("Total number of books (titles): %d\n", countArr);
    printf("Total value archive: %.2f EUR\n", totalValue);
}

void calculateAverageYear(Book archive[],int countArr)  {
    if (countArr == 0){                                     //controle se non ci sono libri
        printf("\n No books available to calculate the average\n");
    } else {
        int sum = 0 ;                                       //variabile per sommare tutti gli anni di pubblicazione
        for (int i =0;i < countArr; i++) {
            sum+=archive[i].release_year;                   //aggiungiamo l anno di pubblicazione del libro corrente alla somma 
        } 
        float avg= sum / countArr;
        fakeLoading();                        
        printf("\n Average of years of public is : %0.2f",avg); 
    }
}

void printMenu(Book bookArchive[], char gen[][10]) {
    int choice = 0;
    int globalCounter = 0;
    int cicleVar = 1;

    while (cicleVar) {
        printf("\n\n--- LIBRARY MANAGEMENT ---\n");
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
            if (globalCounter >= MAX) {
                printf("\nYou can't add books anymore, limit reached! ");
                break;
            }
            globalCounter = insertBook(bookArchive, globalCounter, gen);
            break;
        case 2: 
            printf("\nYou choose to ---SHOW ALL BOOKS---");
            showAllBook(bookArchive, globalCounter);
            break;
        case 3: 
            printf("\nYou choose to ---SEARCH BOOKS BY CODE---");
            SearchByCode(bookArchive, globalCounter,0);
            break;
        case 4:
            printf("\nYou choose to ---UPDATE AVAILABLE COPIES---");
            updateAvCopies(bookArchive, globalCounter,ShowAndSelect(bookArchive,globalCounter));
            break;
        case 5:
            printf("\nYou choose to ---UPDATE UNIT PRICE---");
            updateUnitCost(bookArchive,globalCounter,ShowAndSelect(bookArchive,globalCounter));
            break;
        case 6:
            printf("\nYou choose to ---REGISTER A LOAN---");
            registerLoan(bookArchive, globalCounter);
            break;
        case 7:
            printf("\nYou choose to ---REGISTER A RETURN---");
            registerReturn(bookArchive, globalCounter);
            break;
        case 8: 
            printf("\nYou choose to --- CALCULATE TOTAL ARCHIVE VALUE ---");
            totalArchiveValue(bookArchive, globalCounter);
            break;
        case 9:
            printf("\nYou choose to ---COUNT BOOKS BY GENRE---");
            countByGenre(bookArchive, gen, globalCounter);
            break;
        case 10:
            printf("\nYou choose to ---FIND THE HIGHEST NUMBER OF COPIES'S BOOK---");
            findBookWithHighestNumberOfCopies(bookArchive, globalCounter);
            break;
        case 11:
            printf("\nYou choose to ---CALCULTE AVARAGE PUBLICATION YEAR---");
            calculateAverageYear(bookArchive, globalCounter);
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