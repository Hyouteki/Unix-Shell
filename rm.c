#include <stdio.h>
#include <string.h>

int rm(char *file_name)
{
    int flag = remove(file_name);
    if (flag == 0)
    {
        return 0;
    }
    else
    {
        perror("## Error> Non existing file found ##\n");
        return 1;
    }
}

int rm_i(char *file_name)
{
    // for asking confirmation before removing the file
    printf("Are you sure about removing [%s] (y/n)> ", file_name);
    char flag;
    scanf("%c", &flag);
    if (flag == 'y')
    {
        int flag = remove(file_name);
        if (flag == 0)
        {
            return 0;
        }
        else
        {
            perror("## Error> Non existing file found ##\n");
            return 1;
        }
    }
    else if (flag == 'n')
    {
        return 0;
    }
    else
    {
        perror("## Error> Wrong input ##\n");
        return 1;
    }
}

int rm_v(char *file_name)
{
    int flag = remove(file_name);
    if (flag == 0)
    {
        printf("@@ Info> Removed file [%s] @@\n", file_name);
        return 0;
    }
    else
    {
        perror("## Error> Non existing file found ##\n");
        return 1;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        if (!strcmp(argv[1], "-i"))
        {
            for (int i = 2; i < argc; i++)
            {
                rm_i(argv[i]);
            }
        }
        else if (!strcmp(argv[1], "-v"))
        {
            for (int i = 2; i < argc; i++)
            {
                rm_v(argv[i]);
            }
        }
        else
        {
            for (int i = 1; i < argc; i++)
            {
                rm(argv[i]);
            }
        }
    }
    return 0;
}