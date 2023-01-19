#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
  
int make_dir(char *dir_name)
{
    bool flag = mkdir(dir_name, 777);
    if (flag)
    {
        printf("## Error> Unable to create directory ##\n");
        return 1;
    }
    return 0;
}
  
int make_dir_v(char *dir_name)
{
    // for displaying a message for every directory created. 
    bool flag = mkdir(dir_name, 777);
    if (flag)
    {
        printf("## Error> Unable to create directory ##\n");
        return 1;
    } else {
        printf("@@ Info> Created directory [%s] @@\n", dir_name);
    }
    return 0;
}
  
int make_dir_m(char *dir_name, int mode)
{
    // for creating a directory with specific permissions
    bool flag = mkdir(dir_name, mode);
    if (flag)
    {
        printf("## Error> Unable to create directory ##\n");
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        if (!strcmp(argv[1], "-m"))
        {
            int mode = atoi(argv[2]);
            for (int i = 3; i < argc; i++)
            {
                make_dir_m(argv[i], mode);
            }
        }
        else if (!strcmp(argv[1], "-v"))
        {
            for (int i = 2; i < argc; i++)
            {
                make_dir_v(argv[i]);
            }
        }
        else
        {
            for (int i = 1; i < argc; i++)
            {
                make_dir(argv[i]);
            }
        }
    }
    return 0;
}