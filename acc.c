#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_account(void);
int login();

struct data
{
    char first_name[50];
    char last_name[50];
    char email[50];
    char username[50];
    int password;
};

int main()
{
    int choice;
    struct data d1;
    printf("Enter your choice:");
    printf("\n");
    printf("1:Create account");
    printf("\n");
    printf("2:Login");
    scanf("%d", &choice);
    if(choice==1)
    {
        create_account();
    }
    else if(choice==2)
    {
        login();
    }
    else
    {
        printf("Enter a valid choice!");
    }
    return 0;
}

void create_account(void)
{
    char username[50];
    int password;
    struct data d1;
    FILE *fp=NULL;
    fp = fopen("student.bin", "ab");
    printf("Enter your first name:");
    scanf("%s", d1.first_name);
    printf("Enter your last name:");
    scanf("%s", d1.last_name);
    printf("Enter your Email:");
    scanf("%s", d1.email);
    printf("Enter your username:");
    scanf("%s", d1.username);
    printf("Enter your password:");
    scanf("%d", &d1.password);
    fwrite(&d1, sizeof(d1), 1, fp);
    fclose(fp);
    //fwrite(&d1, sizeof(d1), 1, fp);
    login();
}

int login()
{
    char username[50];
    char password[50];
    FILE *fp;
    struct data d1;
    fp = fopen("student.bin", "rb");
    printf("\n**************************************Account Login**************************************");
    printf("\n");
    printf("Enter your Username:");
    scanf("%s", username);
    printf("\n");
    printf("Enter your Password:");
    scanf("%s", password);
    while (fread(&d1, sizeof(d1), 1, fp))
    {
        if(strcmp(username, d1.username)==0)
        {
            display(username);
        }
    }
    fclose(fp);
}

