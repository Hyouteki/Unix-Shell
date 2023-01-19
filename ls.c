#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int ls()
{
    struct dirent *ent;
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("## Error> Can not open current directory ##\n");
        return 1;
    }
    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") && strcmp(ent->d_name, "..") && ent->d_name[0] != '.')
        {
            printf("%s ", ent->d_name);
        }
    }
    printf("\n");
    closedir(dir);
    return 0;
}

int ls_a()
{
    // for listing hidden files
    struct dirent *ent;
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("## Error> Can not open current directory ##\n");
        return 1;
    }
    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") && strcmp(ent->d_name, ".."))
        {
            printf("%s ", ent->d_name);
        }
    }
    printf("\n");
    closedir(dir);
    return 0;
}

int ls_m()
{
    // for listing files seperated by commas
    struct dirent *ent;
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("## Error> Can not open current directory ##\n");
        return 1;
    }
    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") && strcmp(ent->d_name, "..") && ent->d_name[0] != '.')
        {
            printf("%s, ", ent->d_name);
        }
    }
    printf("\n");
    closedir(dir);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ls();
    }
    else if (argc == 2)
    {
        if (!strcmp(argv[1], "-a"))
        {
            ls_a();
        }
        else if (!strcmp(argv[1], "-m"))
        {
            ls_m();
        }
        else
        {
            perror("## Error> Something went wrong ##\n");
        }
    }
    else
    {
        perror("## Error> Something went wrong ##\n");
    }
    return 0;
}