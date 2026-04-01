#include "book.h"
#include <stdio.h>
#define MAX 100

char genres[4][10]= {"romance", "fantasy", "thriller","sci-fi"};
Book archive[MAX];
int globalCounter = 0;


int main () {
    insert_book(archive, globalCounter);
    globalCounter++; // VEDERE SE SPOSTARE DAL MAIN (o si fa la funzione che torna sempre il valore incrementanto ed essendo dentro al ciclo lo aggiorna oppure si lascia qua ed idem nel ciclo)
    insert_book(archive, globalCounter);
    globalCounter++; 
    SearchByCode(archive, globalCounter);
    showAllBook(archive, globalCounter);
}