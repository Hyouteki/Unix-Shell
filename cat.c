#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cat(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file != NULL)
    {
        char itr;
        while ((itr = fgetc(file)) != EOF)
        {
            printf("%c", itr);
        }
        printf("\n");
    }
    else
    {
        perror("## Error> Non existing file found ##\n");
        return 1;
    }
    fclose(file);
    return 0;
}

int cat_E(char *file_name)
{
    // for printing content with highlighting the end of line
    FILE *file = fopen(file_name, "r");
    if (file != NULL)
    {
        char itr;
        while ((itr = fgetc(file)) != EOF)
        {
            if (itr == '\n')
            {
                printf("@\n");
                continue;
            }
            printf("%c", itr);
        }
        printf("\n");
    }
    else
    {
        perror("## Error> Non existing file found ##\n");
        return 1;
    }
    fclose(file);
    return 0;
}

int cat_n(char *file_name)
{
    // for printing content with line number
    FILE *file = fopen(file_name, "r");
    if (file != NULL)
    {
        char itr;
        int line_number = 1;
        printf("1\t");
        while ((itr = fgetc(file)) != EOF)
        {
            if (itr == '\n')
            {
                printf("\n%d\t", ++line_number);
                continue;
            }
            printf("%c", itr);
        }
        printf("\n");
    }
    else
    {
        perror("## Error> Non existing file found ##\n");
        return 1;
    }
    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        cat(argv[1]);
    }
    else if (argc >= 2)
    {
        if (!strcmp(argv[1], "-E"))
        {
            for (int i = 2; i < argc; i++)
            {
                cat_E(argv[i]);
            }
        }
        else if (!strcmp(argv[1], "-n"))
        {
            for (int i = 2; i < argc; i++)
            {
                cat_n(argv[i]);
            }
        }
        else
        {
            for (int i = 1; i < argc; i++)
            {
                cat(argv[i]);
            }
        }
    }
    else
    {
        perror("## Error> Something went wrong ##\n");
    }
    return 0;
}