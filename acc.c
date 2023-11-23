#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUBJECTS 7

void create_account(void);
int login();
void display(char*);
void student_record(char*);
void student_details(char*);
int logout();
int calc();

struct student
{
    char fi_name[50];
    char la_name[50];
    float marks;
    char result[50];
};

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
    printf("******************************* Welcome to School Manager *******************************");
    printf("\n");   
    printf("Enter your choice:");
    printf("\n");
    printf("1:Create account");
    printf("\n");
    printf("2:Login");
    printf("\n");
    printf("*****************************************************************************************");
    printf("\n");
    printf("Enter your choice:");
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
    printf("**************************************Account Login**************************************");
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

void display(char username1[])
{
    int choose;
    char username[50];
    char password[50];
    FILE *fp;
    struct data d1;
    fp = fopen("student.bin", "rb");
    while (fread(&d1, sizeof(d1), 1, fp))
    {
        if(strcmp(username1, d1.username)==0)
        {
            printf("\n");
            printf("######################################### CHOICE ##########################################");
            printf("\n");
            printf("Enter your choice(1 or 2 or 3):");
            printf("\n");
            printf("1:Enter Student Details:");
            printf("\n");
            printf("2:Check Student details:");
            printf("\n");
            printf("3:Logout:");
            printf("\n");
            printf("###########################################################################################");
            printf("\n");
            printf("Enter your choice:");
            scanf("%d", &choose);
            if(choose==1)
            {
                student_record(username1);
                break;
            }
            else if(choose==2)
            {
                student_details(username1);
                break;
            }
            else if(choose==3)
            {
                logout();
            }
            else
            {
                printf("Enter a valid choice!");
            }
        }
    }
    fclose(fp);
}

void student_record(char username2[])
{
    struct student s1;
    FILE *fm, *fp;
    fp = fopen("student.bin", "rb");
    fm = fopen("student.bin", "ab");
    struct data d1;
    printf("Enter student first name:");
    scanf("%s", s1.fi_name);
    printf("\n");
    printf("Enter student last name:");
    scanf("%s", s1.la_name);
    printf("\n");
    printf("Enter student marks:");
    scanf("%f", &s1.marks);
    printf("\n");
    printf("Enter student Result:");
    scanf("%f", &s1.result);
    printf("\n");
}



void student_details(char username2[])
{
    printf("yo");
}

int logout()
{
    printf("yo");
}
