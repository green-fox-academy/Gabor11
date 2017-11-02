#include <stdio.h>
#include <string.h>

/*
 * Take exercise structures_functions_00.
 * Create an additional structure: Author. This should store Given name and Surname of the author.
 * Rewrite the previous exercise to work with this new structure.
 */

 typedef struct {
    char first_name[256];
    char surname[256];
} auth;

typedef struct {
     char title[256];
     auth author;
     int year_of_publication;
 } book;

book create();
void set_title(book *buk);
void set_author(book *buk);
void set_year(book *buk);

int main()
{

    book book1;
    book1 = create();
    printf("%s %s\n%s\n%d\n", book1.author.first_name, book1.author.surname, book1.title, book1.year_of_publication);
    return 0;
}

book create()
{
    book initial_book;
    set_title(&initial_book);
    set_author(&initial_book);
    set_year(&initial_book);

    return initial_book;
}

void set_title(book *buk)
{
    printf("Please type in the title:\n");
    gets((*buk).title);
}

void set_author(book *buk)
{
    int i = 0;
    int j = 0;
    int counter = 0;
    char input[256] = {'\0'};
    printf("Please type in the author:\n");
    gets(input);

    while (input[i] != '\0') {
        if (input[i] != ' ') {
            switch (counter) {
            case 0:
                (*buk).author.first_name[j] = input [i];
                (*buk).author.first_name[j + 1] = '\0';
                break;
            case 1:
                (*buk).author.surname[j] = input [i];
                (*buk).author.surname[j + 1] = '\0';
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;}
        } else {
            counter++;
            j = -1;
        }
        i++;
        j++;
    }
}

void set_year(book *buk)
{
    printf("Please type in the year of publication:\n");
    scanf("%d", &(*buk).year_of_publication);
}
