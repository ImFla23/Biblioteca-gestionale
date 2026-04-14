#include "book.h"
#include <stdio.h>
#define MAX 100

char genres[4][10]= {"romance ", "fantasy ", "thriller ","sci-fi "};
Book archive[MAX];
//il counter globale è dentro al ciclo while del menu, altrimenti non si puo aggiornare.


int main () {
    printMenu(archive,genres);
}