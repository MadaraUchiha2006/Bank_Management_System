#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void create_account();
int login();
void check_bank_balance(char*);
int transfer_money();
void display(char*);
void acc_details(char*);
int logout();
int val_password();

struct money
{
    char usernameto[50];
    char usernamefrom[50];
    int money;
};

struct pass
{
    char f_name[50];
    char l_name[50];
    char father[50];
    char mother[50];
    char username[50];
    int age; 
    int password;
    int date;
    int month;
    int year;
    char mobile_number[100];
};

int main()
{
    int choice;
    char username[50];
    struct pass u1;

    printf("*******************************Welcome to SBI Bank Account*******************************");
    printf("\n");
    printf("Enter your choice:");
    printf("\n");
    printf("1:Create Account:");
    printf("\n");
    printf("2:Login:");
    printf("\n");
    printf("*******************************************************************************************");
    printf("\n");

    printf("Enter your choice:");
    scanf("%d", &choice);

    if(choice == 1)
    {
        create_account();
        
    }

    else if(choice ==2)
    {
        login();
    }

    else
    {
        printf("Enter a valid choice");
    }

    return 0;
}

void create_account(void)
{
    struct pass u1;  
    FILE *fp = NULL;
    fp = fopen("accounts.bin", "ab");
    printf("Enter your age:");
    scanf("%d", &u1.age);
    printf("Enter your first name:");
    scanf("%s", u1.f_name);
    printf("\n");
    printf("Enter your last name:");
    scanf("%s", u1.l_name);
    printf("\n");
    printf("Enter your Father's name:");
    scanf("%s", u1.father);
    printf("\n");
    printf("Enter your Mother's name:");
    scanf("%s", u1.mother);
    printf("\n");
    printf("Enter the date of your birth:");
    scanf("%d", &u1.date);
    printf("\n");
    printf("Enter the month of your birth:");
    scanf("%d", &u1.month);
    printf("\n");
    printf("Enter the year of your birth:");
    scanf("%d", &u1.year);
    printf("\n");
    printf("Enter your mobile number:");
    scanf("%s", &u1.mobile_number);
    printf("\n");
    printf("Enter your Username:");
    scanf("%s", u1.username);
    printf("\n");
    printf("Rules For Choosing Password:");
    printf("\n");
    printf("1:Password must contain only integers.");
    printf("\n");
    printf("2:Password must not be more than 20 digits.");
    printf("\n");
    printf("3:Password must not contain any special case characters.");
    printf("\n");
    printf("Enter your password:");
    scanf("%d", &u1.password);
    fwrite(&u1, sizeof(u1), 1, fp);
    fclose(fp);
    printf("................................Account Created Successfully...............................");
    printf("\n");
    printf("Enter to the login screen!");
    login();
}

int login()
{
    int choice;
    char username1[50];
    char username[50];
    char password[50];
    FILE *fp;
    struct pass u1;
    fp = fopen("accounts.bin", "rb");
    printf("\n**************************************Account Login**************************************");
    printf("\n");
    printf("Enter your Username:");
    scanf("%s", username);
    printf("\n");
    printf("Enter your Password:");
    scanf("%s", password);
    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if(strcmp(username, u1.username)==0)
        {
            display(username);
        }
    }
    fclose(fp);
}

void display(char username1[])
{
    int choice;
    char username[50];
    char password[50];
    FILE *fp;
    struct pass u1;
    fp = fopen("accounts.bin", "rb");
    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if(strcmp(username1, u1.username)==0)
        {
            printf("\n");
            printf("######################################### CHOICE ##########################################");
            printf("\n");
            printf("Make a choice:");
            printf("\n");
            printf("1:Account Details");
            printf("\n");
            printf("2:Transfer Money");
            printf("\n");
            printf("3:Check Balance");
            printf("\n");
            printf("4:Logout");
            printf("\n");
            printf("###########################################################################################");
            printf("\n");
            printf("Enter your choice:");
            scanf("%d", &choice);
            if(choice==1)
            {
                acc_details(username1);
                break;
            }
            if(choice==2)
            {
                transfer_money();
                break;
            }
            else if(choice==3)
            {
                check_bank_balance(username1);
                break;
            }
            else if(choice==4)
            {
                logout();
                login();
                break;
            }
            else
            {
                printf("Enter a valid choice!");
                break;
            }
        }
    }
    fclose(fp);
}

void acc_details(char username2[])
{
    FILE *fp;
    fp = fopen("accounts.bin", "rb");
    struct pass u1;
    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if(strcmp(username2, u1.username)==0)
        {
            printf("\n");
            printf("Details:");
            printf("\n");
            printf("First Name:%s", u1.f_name);
            printf("\n");
            printf("Last Name:%s", u1.l_name);
            printf("\n");
            printf("Age: %d", u1.age);
            printf("\n");
            printf("Father's Name:%s", u1.father);
            printf("\n");
            printf("Mother's Name:%s", u1.mother);
            printf("\n");
            printf("Date Of Birth:%d-%d-%d", u1.date, u1.month, u1.year);
            printf("\n");
            printf("Mobile Number:%s", u1.mobile_number);
            printf("\n");
            printf("Username:%s", u1.username);
            printf("\n");
            printf("Password:%d", u1.password);
            fclose(fp);
            break;
        }
    }
}

int transfer_money()
{
    FILE *fp, *fm;
    struct pass u1;
    struct money m1;
    char username[50];
    char username_to[50];
    char username_from[50];
    fp = fopen("accounts.bin", "rb");
    fm = fopen("money.bin", "ab");
    printf("\n");
    printf("Enter the username you want to send money to:");
    scanf("%s", &username_to);
    printf("\n");
    printf("Enter the username you want to send money from:");
    scanf("%s", &username_from);
    while(fread(&u1, sizeof(u1), 1, fp))
    {
        if(strcmp(username_to, u1.username)==0)
        {
            strcpy(m1.usernameto, u1.username);
            strcpy(m1.usernamefrom, username_from);
        }
    }

    printf("Enter the amount of money to be transferred:");
    scanf("%d", &m1.money);
    fwrite(&m1, sizeof(m1), 1, fm);

    printf("Money being transacted................");
    printf("\n");
    printf("Amount successfully transacted........");

    fclose(fp);
    fclose(fm);
    display(username_from);
}

void check_bank_balance(char username2[])
{
    FILE *fm;
    struct money m1;
    int i=1, sum_of_money=0;
    fm = fopen("money.bin", "rb");
    while(fread(&m1, sizeof(m1), 1, fm))
    {
        if(strcmp(username2, m1.usernameto)==0)
        {
            printf("\n");
            printf("Sr no: %d", i);
            i++;
            printf("\n");
            printf("TRANSACTION ID: %s", m1.usernamefrom);
            printf("\n");
            printf("AMOUNT: %d", m1.money);
            sum_of_money = sum_of_money + m1.money;
        }
    }
    printf("\n");
    printf("Total Amount: %d", sum_of_money);
    fclose(fm);
    display(username2);
}

int logout()
{
    printf("\n");
    printf("please wait, logging out...................................................................");
    printf("\n");
    printf("\n");
    printf("********************************* Sucessfully Logged Out **********************************");
    printf("\n");
}
