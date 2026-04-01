#ifndef BOOK_H
#define BOOK_H
typedef struct 
{
    int code;
    char title[50];
    char author[50];
    int release_year;
    int copies_avaible;
    int total_copies;
    float price;
    char genre[10];
} Book;
#endif