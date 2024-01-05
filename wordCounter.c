#include<stdio.h>
#include<string.h>
void main()
{
    char str[100];
    int word = 0,
        space = 0,
        character = 0;
    int size,i;

    puts("\nType the string : \n");
    gets(str);
    
    size = strlen(str);
    
    for ( i = 0; i < size; i++)
    {
        if(str[i] == ' ')
                space++;

        else
        {
            if(str[i+1] == ' ')
                word++;
        }
    }

    if(str[size-1] != ' ')
        word++;
    
    printf("\nWord : %d ",word);
    printf("\nCharacters : %d ",size-space);
    printf("\nSpace : %d ",space);
    
}