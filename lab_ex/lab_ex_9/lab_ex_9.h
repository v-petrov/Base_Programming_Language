#ifndef LAB_EX_9_H_INCLUDED
#define LAB_EX_9_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int month;
    int day;
    int year;
};

typedef struct date Date; // new name for our struct

typedef struct name
{
    char first[30];
    char last[30];
}Name;

typedef struct person
{
    Name name;
    int age;
}Person;

void Print(struct person *p1)
{
    printf("Name: %s %s, age: %d\n", p1->name.first, p1->name.last, p1->age);
}

void build_up()
{
//    struct date today;
//    struct date day1 = {4,8}; // the rest of the members are initialized 0's
//    struct date days[5] = {{2,14,2002},{4,21,2022},{},{},{}};
//    today.month = 4;
//    today.day = 21;
//    today.year = 2022;
//    today = day1; // only possible when the variables are of the same type
//
//    printf("Today's date is: %d.%d.%d", today.day, today.month, today.year);

    Person person1 = {{"Ivan", "Petrov"},20};
    printf("Name: %s %s, age: %d\n", person1.name.first, person1.name.last, person1.age);
    Print(&person1);

    Person *ps;
    ps = &person1;
    printf("Name: %s %s, age: %d\n", ps->name.first, ps->name.last, ps->age);
    ps = (Person *)malloc(1*sizeof(Person));
    ps->age = 20;
}

typedef struct box
{
    float width;
    float length;
    float height;
    float volume;
}Box;

typedef struct book
{
    int year;
    float price;
    char name[20];
    char author_name[30];
}Book;

void book_information(Book *book)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Year of the book: ");
        scanf("%d", &book[i].year);
        printf("Price of the book: ");
        scanf("%f", &book[i].price);
        printf("Name of the book: ");
        scanf("%s", book[i].name);
        printf("Author's name of the book: ");
        scanf("%s", book[i].author_name);
        printf("\n");
    }
}

void book_2005(Book *book)
{
    printf("Year of the book: %d\n", book->year);
    printf("Price of the book: %.2f\n", book->price);
    printf("Name of the book: %s\n", book->name);
    printf("Author's name of the book: %s\n\n", book->author_name);
}

void book_author(Book *book, char *author_name)
{
    for(int i = 0; i < 5; i++)
    {
        if(!strcmp(book[i].author_name, author_name))
        {
            printf("Year of the book: %d\n", book[i].year);
            printf("Price of the book: %.2f\n", book[i].price);
            printf("Name of the book: %s\n", book[i].name);
            printf("Author's name of the book: %s\n\n", book[i].author_name);
        }
    }
}

void ex_1()
{
    Box boxes[10];
    for(int i = 0; i < 5; i++)
    {
        printf("Enter the width: ");
        scanf("%f", &boxes[i].width);
        printf("Enter the length: ");
        scanf("%f", &boxes[i].length);
        printf("Enter the height: ");
        scanf("%f", &boxes[i].height);
        boxes[i].volume = boxes[i].width * boxes[i].length * boxes[i].height;
        printf("\n");
    }

    int i = 0,j = 0;
    float max_volume = boxes[i].volume, min_volume = boxes[i].volume;
    int max = 0, min = 0;

    for(i = 0; i < 4; i++)
    {
        for(j = i + 1; j < 5; j++)
        {
            if(boxes[i].volume > boxes[j].volume)
            {
                min_volume = boxes[j].volume;
                max = j;
            }
            else if(boxes[i].volume < boxes[j].volume)
            {
                max_volume = boxes[j].volume;
                min = j;
            }
        }
    }

    printf("\nThe box with the biggest volume has width: %.2f, length: %.2f, height: %.2f and volume: %.2f\n", boxes[max].width, boxes[max].length, boxes[max].height, max_volume);
    printf("The box with the smallest volume has width: %.2f, length: %.2f, height: %.2f and volume: %.2f\n", boxes[min].width, boxes[min].length, boxes[min].height, min_volume);
}

void ex_2()
{
    Book books[5];

    book_information(books);


    for(int i = 0; i < 5; i++)
    {
        if(books[i].year == 2005)
        {
            book_2005((books + i));
        }
    }

    char author_name[20];
    printf("Enter the author's name books you wish to see: ");
    scanf("%s",author_name);

    book_author(books, author_name);
}
#endif // LAB_EX_9_H_INCLUDED
