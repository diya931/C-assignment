// Diya Pawar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member{
    char name[35];
    int age;
    char sex;
    int amount;
    char date[15];
}input1;

FILE *ptr, *ptr_copy;

void add_member(){
    ptr= fopen("gym.txt", "ab");

    printf("Enter name: ");
    fflush(stdin);
    gets(input1.name);
    printf("Enter Age: ");
    scanf("%d", &input1.age);
    printf("Enter sex: ");
    fflush(stdin);
    gets(input1.sex);
    printf("Enter amount: ");
    scanf("%d", &input1.amount);
    printf("Enter date: ");
    fflush(stdin);
    gets(input1.date);

    fprintf(ptr, "%s\n%d\n%s\n%d\n%s", input1.name, input1.age, input1.sex, input1.amount, input1.date);

    fclose(ptr);
}

void display_all(){
    ptr= fopen("gym.txt", "rb");
    char str[100];

    printf("<== MEMBER DETAILS ==>\n\n");

    int a=0; //line number inside file for a struct
    while(fgets(str, 100, ptr)!=NULL)
    {
        if(a==0)
        {
            printf("--------------------\n");
            printf("Name : %s\n",str);
            a++;
        }
        else if(a==1)
        {
            printf("Age : %s",str);
            a++;
        }
        else if(a==2)
        {
            printf("Sex : %s",str);
            a++;
        }
        else if(a==3)
        {
            printf("Amount : %s",str);
            a++;
        }
        else if(a==4)
        {
            printf("Date : %s",str);
            a=0;
            printf("\n--------------------\n");
            printf("\n--------------------\n");
        }
    }

    fclose(ptr);
}

void delete(){
    ptr = fopen("gym1.txt", "r+");
    ptr_copy = fopen("gym_copy.txt", "w+");

    char str[100];
    char roll[100];
    printf("Enter the roll number to be deleted: ");
    scanf("%s",&roll);

    while(fgets(str, 100, ptr)!=NULL)
    {
        if(strcmp(roll, str)==0)
        {
            fgets(str, 100, ptr);
            fgets(str, 100, ptr);
            fgets(str, 100, ptr);
            fgets(str, 100, ptr);
        }

        fputs(str, ptr_copy);
    }
    fclose(ptr);
    fclose(ptr_copy);
    remove("gym.txt");
    rename("gym_copy.txt", "gym.txt");
    printf("Data Successfully deleted!");


}

void modify(){
    ptr = fopen("gym1.txt", "r+");
    ptr_copy = fopen("gym_copy.txt", "w+");

    char str[100];
    char roll[100];
    printf("Enter the roll number to be modified: ");
    scanf("%s",&roll);

    while(fgets(str, 100, ptr)!=NULL)
    {
        if(strcmp(roll, str)==0)
        {
            fgets(str, 100, ptr);
            fgets(str, 100, ptr);
            fgets(str, 100, ptr);
            fgets(str, 100, ptr);
        }

        fputs(str, ptr_copy);
    }

    printf("Enter new details: \n\n");

    printf("Enter name: ");
    fflush(stdin);
    gets(input1.name);
    printf("Enter Age: ");
    scanf("%d", &input1.age);
    printf("Enter sex: ");
    fflush(stdin);
    gets(input1.sex);
    printf("Enter amount: ");
    scanf("%d", &input1.amount);
    printf("Enter date: ");
    fflush(stdin);
    gets(input1.date);

    fprintf(ptr, "%s\n%d\n%s\n%d\n%s", input1.name, input1.age, input1.sex, input1.amount, input1.date);

    fclose(ptr);
    fclose(ptr_copy);
    remove("gym.txt");
    rename("gym_copy.txt", "gym.txt");
    printf("Data Successfully Modified!");


}

int main()
{
    int choice;
    while(1)
    {
        printf("<== GYM MANAGEMENT SYSTEM ==>\n\n");
        printf("1. ADD A MEMBER\n");
        printf("2. DISPLAY MEMBERS\n");
        printf("3. DELETE A MEMBER\n");
        printf("4. MODIFY A MEMBER\n");
        printf("5. EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice==1)
        {
            add_member();
        }
        else if(choice==2)
        {
            display_all();
        }
        else if(choice==3)
        {
            delete();
        }
        else if(choice==4)
        {
            modify();
        }
        else if(choice==5)
        {
            exit(1);
        }
    }

    return 0;
}