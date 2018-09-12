#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************
    DEFINING STRUCTS
************************/

typedef struct Book{
    char name[30];
    int year;
    char author[25];
    char category[25];
    int categoryn;
    struct Book* next;
}Book;

typedef struct area{
    int id;
    char title[20];
    struct Book* bookList;
    struct area* next;

}area;

/*************************
    DEFINING POINTERS AND ROOT NODES
**************************/
    area* heada;
    area* ptra;
    Book* ptrb;
    Book* headb;


int main()
{
    heada = malloc(sizeof(area));
    headb = malloc(sizeof(Book));
    ptra = heada;
    ptrb = headb;



    readFromFile();
    greetings();
    information();
    menu();
    while(1)
    {
        menu();

    }

}

/*******************
    ENTERANCE MESSAGES
******************/
void information()
{
    printf("-WHEN USING THE PROGRAM, IF YOU WILL ENTER ANY VALUE\n-PLEASE BEGIN WITH UPPERCASE AND USE (_) INSTEAD OF SPACE \n");
    printf("Press a key to start using the program...");
    getch();
    system("cls");
}

/*******************
    FILE READER
*******************/
void readFromFile()
{
    FILE* fpa;
    FILE* fpb;
    fpb = fopen("Books.txt", "r");
    fpa = fopen("Areas.txt", "r");

     while(!feof(fpa))
    {
        fscanf(fpa, "%d %s", &ptra->id, ptra->title);
        ptra->next = malloc(sizeof(area));
        ptra = ptra->next;
        ptra -> next = NULL;
    }


    while(!feof(fpb))
    {
        fscanf(fpb,"%s %s %s %d %d" , ptrb->name, ptrb->author, ptrb->category, &ptrb->year, &ptrb->categoryn);
        ptrb->next = malloc(sizeof(Book));
        ptrb = ptrb->next;
        ptrb->next = NULL;
    }
    heada->bookList = headb;
}

/*******************
    ENTERANCE MESSAGES
********************/
void greetings()
{
    printf("------------------------------------------\n");
    printf("|                                        |\n");
    printf("|  Welcome to Library Automation System  |\n");
    printf("|  \t    Powered by OmerG\t         |\n");
    printf("|                                        |\n");
    printf("------------------------------------------");
    getch();
    system("cls");
}

/**********************
    ADDS AN AREA
***********************/
void addArea(area *headNode)
{
    system("cls");
    area * iter = headNode;
    area * previous;

    while(iter->next!=NULL)
    {   previous= iter;
        iter = iter->next;
    }

    iter = malloc(sizeof(area));

    printf("Enter the new title :");
    scanf("%s", iter->title);

    iter->id = previous->id + 1;

    FILE *fp;
    fp= fopen("Areas.txt", "a+");
    fprintf(fp, "\n%d\t%s", iter->id, iter->title);
    fclose(fp);

    readFromFile();
    printf("Press any key continue");
    getch();

}

/********************
    ADDS A BOOK
*****************/
void addBook(area *headNode)
{
    system("cls");
    char answ[20];
    int id;
    area *iter = headNode;
    printf("Which area? (Use numbers) : ");
    scanf("%d", &id);
    while(iter->id!= id)
    {
        iter=iter->next;
    }
    id = iter->id;

    printf("Enter Book's details (Name, Author, Category, Year) : ");
    iter = headNode;
    while(iter->bookList!=NULL)
    {
        iter->bookList = iter->bookList->next;
    }
    iter->bookList = malloc(sizeof(Book));
    scanf("%s %s %s %d", iter->bookList->name, iter->bookList->author, iter->bookList->category, &iter->bookList->year);

    iter->bookList->categoryn = id;
    FILE* fp;
    fp = fopen("Books.txt", "a+");
    fprintf(fp, "\n%s\t%s\t%s\t\%d\t%d", iter->bookList->name, iter->bookList->author, iter->bookList->category, iter->bookList->year, iter->bookList->categoryn);
    fclose(fp);

    readFromFile();
    puts("Press any key to continue");
    getch();
}

/***************
GIVES DETAILED INFORMATION FOR PARTICULAR AREA
****************/
void showArea(area *headNode)
{
    system("cls");
    int answ;
    area *iter;
    iter = headNode;
    printf("Which area do you want to show? (Use Numbers) :");
    scanf("%d", &answ);
    while(iter->id != answ)
    {
        iter = iter->next;
    }
    printf("Area name : %s\nArea id : %d\n", iter->title, iter->id );
    iter = headNode;
    while(iter->bookList->next != NULL)
    {
        if(iter->bookList->categoryn==answ)
        {
            printf("|%-30s|  |%-25s|  |%-25s| |%-4d|\n", iter->bookList->name, iter->bookList->author, iter->bookList->category, iter->bookList->year);
        }
        iter->bookList = iter->bookList->next;
    }
    printf("Press any key to continue..");
    getch();
}

/***********************
PRINTS BOOKS WHICH ARE IN PARTICULAR AUTHOR
***********************/
void showAuthor(area *headNode)
{
    system("cls");
    char *answ;
    area *iter;
    int cmp;
    iter = headNode;
    printf("Which Author Do You Want? :");
    scanf("%s", answ);

    while(iter->bookList->next != NULL)
    {
        cmp =strcmp(answ , iter->bookList->author);
        if(cmp==0){
            printf("|%-30s|  |%-25s|  |%-25s| |%-4d| |%-2d|\n", iter->bookList->name, iter->bookList->author, iter->bookList->category, iter->bookList->year, iter->bookList->categoryn);
        }
        iter->bookList = iter->bookList->next;
    }

    printf("Press any key to continue...");
    getch();
}

/***********************
PRINTS BOOKS WHICH ARE IN PARTICULAR YEAR
***********************/
void showYear(area *headNode)
{
    system("cls");
    int answ;
    area *iter;
    int cmp;
    iter = headNode;
    printf("Which Year Do You Want? :");
    scanf("%d", &answ);

    while(iter->bookList->next != NULL)
    {
        cmp = cmpint(answ, iter->bookList->year);
        if(cmp==1)
        {
            printf("|%-30s|  |%-25s|  |%-25s| |%-2d|\n", iter->bookList->name, iter->bookList->author, iter->bookList->category, iter->bookList->categoryn);
        }
        iter->bookList = iter->bookList->next;
    }
    printf("Press any key to return menu...");
    getch();

}
/**********************
PRINTS BOOKS WHICH ARE IN PARTICULAR CATEGORY
**********************/
void showCategory(Book *headNode)
{
    system("cls");
    char answ[40];
    Book *iter;
    iter = headNode;
    int cmp;


    printf("Which Category Do You Want? :");
    scanf("%s", answ);


    while(iter->next!= NULL)
    {

        cmp = strcmp(answ,iter->category);
        if(cmp==0)
        {
            printf("|%-30s| |%-25s| |%-25s| |%-4d| |%-2d|\n", iter->name, iter->author, iter->category, iter->year, iter->categoryn);
        }

        iter = iter->next;
    }
    printf("Press any key to return menu..");
    getch();



}
/*****************
    COMPARES TWO INTEGERS
 *******************/
int cmpint(int a , int b)
{
    if(a==b)
    {
        return 1;
    }

}
/******************
    SORTS BOOKS IN ALPHABETICAL ORDER
******************/
void sortBook(Book *headNode)
{
    Book *temp;
    Book *current;
    Book *previous;
    current = headNode;
    while(current->next!=NULL)
    {
        if(strcmp(current->name,previous->name)>0)
        {
            strcpy(temp->next->name, current->next->name);
            strcpy(current->next->name, temp);
        }
        current = current->next;

    }
}
/*********************
    PRINTS BOOKS
*********************/
void printBooks(Book *headNode)
{
    Book *iter;
    iter = headNode;
    while(iter->next!=NULL)
    {
        printf("|%-30s|  |%-25s|  |%-25s| |%-4d| |%-2d|\n", iter->name, iter->author, iter->category, iter->year, iter->categoryn);
        iter = iter->next;
    }
    printf("Press any key to return menu");
    getch();
    system("cls");

}
/**********************
    PRINTS AREAS
**********************/
void printAreas(area *headNode)
{
    area *iter;
    iter = headNode;
    while(iter->next!=NULL)
    {
        printf("%d %-20s\n", iter->id, iter->title);
        iter = iter->next;
    }
    printf("Press any key to return menu");
    getch();
    system("cls");
}
/********************
    CHOOSING MENU
*******************/
void quest()
{
    switch(getch())
    {
    case '1':
        break;
    case '2':
        addArea(heada);
        break;
    case '3':
        addBook(heada);
        break;
    case '4':
        showArea(heada);
        break;
    case '5':
        break;
    case '6':
        showAuthor(heada);
        break;
    case '7':
        showYear(heada);
        break;
    case '8':
        showCategory(headb);
        break;
    case '0':
        exit(1);
        break;
    case 'm':
        menu();
        break;
    case 'M':
        menu();
        break;
    case 'A':
        printAreas(heada);
        break;
    case 'a':
        printAreas(heada);
        break;
    case 'b':
        printBooks(headb);
        break;
    case 'B':
        printBooks(headb);
        break;
    default:
        menu();
        break;
    }

}
/*********************
    CHOOSING MENU
*********************/
void menu()
{
    system("cls");

    printf("Select one of them\n");
    puts("1-Alphabetical Book List\n");
    puts("2-Add an Area\n");
    puts("3-Add a Book\n");
    puts("4-Show Particular Areas\n");
    puts("5-Remove an Area\n");
    puts("6-List Books for Particular Authors\n");
    puts("7-List Books for Particular Years\n");
    puts("8-List Books for Particular Categories\n");
    puts("0-Exit\n");
    puts("Press 'B' to see Book List");
    puts("Press 'A' to see Area List");
    puts("If you press any button instead of upwards you will return to main menu");

    quest();

}
