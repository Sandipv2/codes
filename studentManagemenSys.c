#include <stdio.h>
#include <string.h>

FILE *fp;
struct Student
{
    int id;
    char name[45];
    int age;
    int marks;
    char grade;
};

void welcomeMsg()
{
    printf("\n\n1. Add Student\n2. Search him/her\n3. All Data\n4. Exit\n");
    printf("Your choice : ");
}

void addStudent()
{
    struct Student s;
    char name[45];
    int isExists = 0;
    int id, age, marks;
    char grade;

    puts("\n\tAdding the student :");
    puts("\nEnter : ID No., Name, Age, Marks, Grade :- \n");
    scanf("%d", &s.id);

    fp = fopen("data.txt", "r");
    if (fp != NULL)
    {
        while (fscanf(fp, "%d %s %d %d %c", &id, name, &age, &marks, &grade) != EOF)
        {
            if (id == s.id)
            {
                isExists = 1;
                fclose(fp);
                printf("\nAlready exits !!\n");
                break;
            }
        }
    }
    
    if (isExists == 0)
    {
        fflush(stdin);
        strcpy(s.name, gets(name));
        scanf("%d %d %c", &s.age, &s.marks, &s.grade);

        fp = fopen("data.txt", "a");

        if (fp == NULL)
        {
            puts("\n*** Data File Missing :(");
        }
        else
        {
            fprintf(fp, "%d %s %d %d %c", s.id, s.name, s.age, s.marks, s.grade);
            fputc('\n', fp);
            puts("\nData Added successfully");
        }

        fclose(fp);
    }
}

void searchStudent() {
    int searchId;
    char name[45];
    int id, age, marks;
    char grade;

    puts("\nEnter the id : ");
    scanf("%d",&searchId);

    fp = fopen("data.txt","r");

    if(fp == NULL) {
        puts("\n** Data file missing !!");
        fclose(fp);
        return;
    }
    else {
        while(fscanf(fp, "%d %s %d %d %c",&id, name, &age, &marks, &grade) != EOF) {
            if(searchId == id) {
                printf("\nFound !!");
                printf("\nID No. : %d\nName : %s\nAge : %d\nMarks : %d\nGrage : %c",id, name, age, marks, grade);
                puts("\n");
                fclose(fp);
                return;
            }
        }

        puts("\nNot Found !!\n");
        fclose(fp);
    }
}

void displayAll()
{
    char name[45];
    int id, age, marks;
    char grade;

    fp = fopen("data.txt","r");

    if(fp == NULL) {
        puts("\n**Nothing to display!!\n");
        fclose(fp);
    }

    puts("\n");

    while (fscanf(fp, "%d %s %d %d %c", &id, name, &age, &marks, &grade) != EOF) {
        printf("%d %s %d %d %c\n",id, name, age, marks, grade);
    }

    fclose(fp);
    
}
void main()
{
    int ch;
    while (1)
    {
        welcomeMsg();
        scanf("%d", &ch);

        if (ch == 1)
        {
            addStudent();
        }
        else if (ch == 2)
        {
            searchStudent();
        }
        else if (ch == 3)
        {
            displayAll();
        }
        else if (ch == 4)
        {
            fclose(fp);
            printf("\n\n\tHave a nice day !!");
            break;
        }
        else
        {
            printf("\nPlease enter valid option !!");
        }
    }
}