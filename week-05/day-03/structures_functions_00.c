#include <stdio.h>

/*
 * Create a structure representing the data of a book:
 *    * Title
 *    * Author
 *    * Year of publication
 *
 * Create functions for:
 *    * Creating a new book.
 *    * Changeing or setting the Title
 *    * Changeing or setting the Author
 *    * Changeing or setting the Year of publication
 *    * Getting each of these separately by a singel function each.
 *
 * IMPORTANT: The first parameter of each function should be a "Book", a variable of the type of this structure.
 *
 * Create a main where You demonstrate that each of these works and print out the necessary info.
 * IMPORTANT: You should only print from the main function. All other functions should return the info needed.
 */

 typedef struct {
     char title[256];
     char author[256];
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
    printf("%s\n%s\n%d\n", book1.author, book1.title, book1.year_of_publication);
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
    printf("Please type in the author:\n");
    gets((*buk).author);
}

void set_year(book *buk)
{
    printf("Please type in the year of publication:\n");
    scanf("%d", &(*buk).year_of_publication);
}
