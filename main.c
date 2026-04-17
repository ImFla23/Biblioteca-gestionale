#include "book.h"
#include <stdio.h>
#define MAX_BOOKS 100
#define MAX_GENRE 4

char genres[MAX_GENRE][10]= {"romance ", "fantasy ", "thriller ","sci-fi "};
Book archive[MAX_BOOKS];
//il counter globale è dentro al ciclo while del menu, altrimenti non si puo aggiornare.


int main () {
    printMenu(archive,genres);
}