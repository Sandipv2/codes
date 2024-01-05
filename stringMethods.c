#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int ch=0;
    char s1[100];
    char s2[100];
    
    while(ch != 8)
    {
        printf("\n--------------------\n");
        printf("1. Strlen()\n");
        printf("2. Strcpy()\n");
        printf("3. Strcmp()\n");
        printf("4. Strcat()\n");
        printf("5. Strrev()\n");
        printf("6. Strupr()\n");
        printf("7. Strlwr()\n");
        printf("8. Exit\n\n");
        printf("Your choice : ");

        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                printf("\n--------------\n");
                printf("\nEnter the string : ");
                getchar();
                gets(s1);
                printf("\nSize : %d\n",strlen(s1));
                break;

            case 2:
                printf("\n--------------\n");
                printf("\nEnter string that will copy into s2: ");
                getchar();
                gets(s1);
                strcpy(s2,s1);
                printf("S1 : %s\n",s1);
                printf("S2 : %s",s2);
                break;

            case 3:
                printf("\n--------------\n");
                printf("\nEnter string 1 :");
                getchar();
                gets(s1);
                printf("Enter string 2 :");
                gets(s2);
                int cmp = strcmp(s1,s2);
                if(cmp == 0)
                    puts("\nBoth strings are same !");
                else
                    puts("\nBoth are not same !");
                break;

            case 4:
                printf("\n--------------\n");
                printf("\nEnter string 1 :");
                getchar();
                gets(s1);
                printf("Enter string 2 :");
                gets(s2);
                printf("\n");
                puts(strcat(s1,s2));
                break;

            case 5:
                printf("\n--------------\n");
                printf("\nEnter string :");
                getchar();
                gets(s1);
                printf("\n");
                puts(strrev(s1));
                break;

            case 6:
                printf("\n--------------\n");
                printf("\nEnter string :");
                getchar();
                gets(s1);
                printf("\n");
                puts(strupr(s1));
                break;

            case 7:
                printf("\n--------------\n");
                printf("\nEnter string :");
                getchar();
                gets(s1);
                printf("\n");
                puts(strlwr(s1));
                break;

            case 8:
                printf("\n\n---> Have A Nice Day :) <---\n\n");
                break;
            
            default:
                printf("\n--------------\n");
                printf("\nNot a valid option!!!\n");
                break;
        }
    }
}