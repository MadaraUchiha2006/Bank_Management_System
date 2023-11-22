#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50

struct Book
{
    char title[100];
    char author[50];
    int available;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook()
{
    if (bookCount < MAX_BOOKS) 
	{
        struct Book newBook;
        
        printf("Enter book title: ");
        scanf("%s", newBook.title);
        printf("Enter author name: ");
        scanf("%s", newBook.author);
        printf("Enter quantity available: ");
        scanf("%d", &newBook.available);

        library[bookCount] = newBook;
        bookCount++;

        printf("Book added successfully.\n");
    } 

	else 
	{
        printf("Library full! Cannot add more books.\n");
    }
}

void displayBooks()
{
    for (int i = 0; i < bookCount; i++) 
	{
        printf("Library Books:");
	    printf("\n");
        printf("Title: %s", library[i].title);
        printf("\n");
        printf("Author: %s", library[i].author);
        printf("\n");
        printf("Available: %d", library[i].available);
	    printf("\n");
    }
}

void searchBook() 
{
    char searchTitle[100];
    int found = 0;

    printf("Enter book title to search: ");
    scanf("%s", searchTitle);

    printf("Search Results:");
	printf("\n");
    for (int i = 0; i < bookCount; i++) 
	{
        if (strcmp(searchTitle, library[i].title) == 0) 
		{
            printf("Title: %s", library[i].title);
            printf("\n");
            printf("Author: %s", library[i].author);
            printf("\n");
            printf("Available: %d", library[i].available);
	        printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) 
	{
        printf("Book not found.\n");
    }
}

int main() 
{
    int choice;

    do 
	{
        printf("Library Management System");
		printf("\n");
        printf("1. Add Book");
		printf("\n");
        printf("2. Display Books");
		printf("\n");
        printf("3. Search Book");
		printf("\n");
        printf("4. Exit");
		printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
		{
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                printf("Exiting the program.");
                break;

            default:
                printf("Invalid choice!");
        }
    } while (choice != 4);

	return 0;
}
