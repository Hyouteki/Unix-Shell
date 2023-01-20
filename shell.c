#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_CMD_LEN 1000
#define MAX_STR_LEN 100

char *cmds[11] = {"cd", "pwd", "exit", "ls", "cat", "date", "rm", "mkdir", "help", "echo", "clear"};

void clear()
{
    printf("\033[H\033[J");
}

int ls(char *input_space_spr[MAX_STR_LEN])
{
    int pid = fork();
    if (pid == 0) {
        execvp("./ls", input_space_spr);
    } else if ( pid > 0) {
        wait(NULL);
        return 0;
    } else {
        perror("## Error> Process cannot be created ##");
        return 1;
    }
}

int cat(char *input_space_spr[MAX_STR_LEN])
{
    int pid = fork();
    if (pid == 0) {
        execvp("./cat", input_space_spr);
    } else if ( pid > 0) {
        wait(NULL);
        return 0;
    } else {
        perror("## Error> Process cannot be created ##");
        return 1;
    }
}

int date(char *input_space_spr[MAX_STR_LEN])
{
    int pid = fork();
    if (pid == 0) {
        execvp("./date", input_space_spr);
    } else if ( pid > 0) {
        wait(NULL);
        return 0;
    } else {
        perror("## Error> Process cannot be created ##");
        return 1;
    }
}

int mkdir(char *input_space_spr[MAX_STR_LEN])
{
    int pid = fork();
    if (pid == 0) {
        execvp("./mkdir", input_space_spr);
    } else if ( pid > 0) {
        wait(NULL);
        return 0;
    } else {
        perror("## Error> Process cannot be created ##");
        return 1;
    }
}

int rm(char *input_space_spr[MAX_STR_LEN])
{
    int pid = fork();
    if (pid == 0) {
        execvp("./rm", input_space_spr);
    } else if ( pid > 0) {
        wait(NULL);
        return 0;
    } else {
        perror("## Error> Process cannot be created ##");
        return 1;
    }
}

void help()
{
    printf("CUSTOM SHELL made by Chauhan Lakshay\n");
    printf("Commands available: cd, pwd, exit, echo\n");
    printf("    ls, cat, date, mkdir, help, clear\n");
}

void initialize()
{
    clear();
    printf("========================================================================\n");
    printf("========================================================================\n");
    printf("================= CUSTOM SHELL made by Chauhan Lakshay =================\n");
    printf("========================================================================\n");
    printf("========================================================================\n");
}

bool input(char *str)
{
    char *input;
    input = readline("$$ ");
    if (strlen(input) != 0)
    {
        add_history(input);
        strcpy(str, input);
        return false;
    }
    else
    {
        return true;
    }
}

void parse_cmd(char *input_str, char *input_space_spr[MAX_STR_LEN])
{
    for (int i = 0; i < MAX_STR_LEN; i++)
    {
        input_space_spr[i] = strsep(&input_str, " ");
        if (input_space_spr[i] == NULL)
        {
            break;
        }
        if (strlen(input_space_spr[i]) == 0)
        {
            i--;
        }
    }
}

bool exec_cmd(char *input_space_spr[MAX_STR_LEN])
{
    int pid = fork();
    if (pid < 0) // error occured
    {
        return 1;
    }
    if (pid == 0)
    {
        if (execvp(input_space_spr[0], input_space_spr) < 0)
        {
            perror("## Error> Command cannot be executed ##\n");
        }
        exit(0);
    }
    else
    {
        wait(NULL);
        return 0;
    }
}

bool cmd_mngr(char *input_space_spr[MAX_STR_LEN])
{
    if (!strcmp(input_space_spr[0], cmds[0])) // cd
    {
        chdir(input_space_spr[1]);
    }
    else if (!strcmp(input_space_spr[0], cmds[1])) // pwd
    {
        exec_cmd(input_space_spr);
    }
    else if (!strcmp(input_space_spr[0], cmds[2])) // exit
    {
        printf("@@ Thank you for using CUSTOM SHELL made by Chauhan Lakshay @@\n");
        exit(0);
    }
    else if (!strcmp(input_space_spr[0], cmds[3])) // ls
    {
        ls(input_space_spr);
    }
    else if (!strcmp(input_space_spr[0], cmds[4])) // cat
    {
        cat(input_space_spr);
    }
    else if (!strcmp(input_space_spr[0], cmds[5])) // date
    {
        date(input_space_spr);
    }
    else if (!strcmp(input_space_spr[0], cmds[6])) // rm
    {
        rm(input_space_spr);
    }
    else if (!strcmp(input_space_spr[0], cmds[7])) // mkdir
    {
        mkdir(input_space_spr);
    }
    else if (!strcmp(input_space_spr[0], cmds[8]))
    {
        help();
    }
    else if (!strcmp(input_space_spr[0], cmds[9]))
    {
        exec_cmd(input_space_spr);
    }
    else if (!strcmp(input_space_spr[0], cmds[10]))
    {
        exec_cmd(input_space_spr);
    }
    else
    {
        perror("## Error> Invalid Command ##\n");
        printf("@@ Advice> Use help @@\n");
    }
}

int check_4_thread(char *input_str, bool *error_flag)
{
    bool thread_flag = false;
    int ret = -1;
    for (int i = 0; input_str[i] != '\0'; i++)
    {
        if (input_str[i + 1] != '\0')
        {
            if (input_str[i] == '&' && input_str[i + 1] == 't')
            {
                if (thread_flag)
                {
                    *error_flag = true;
                }
                else
                {
                    thread_flag = true;
                    ret = i;
                }
            }
        }
    }
    return ret;
}

void *function_thread(void *input)
{
    char *str = (char *)input;
    system(str);
}

int exec_cmd_thread(char *input_str)
{
    pthread_t t1;
    if (pthread_create(&t1, NULL, &function_thread, input_str) != 0)
    {
        return 1;
    }
    if (pthread_join(t1, NULL) != 0)
    {
        return 1;
    }
    return 0;
}

bool cmd_mngr_thread(char *input_str, char *input_space_spr[MAX_STR_LEN])
{
    // printf("cmt ^^  >%s<  ^^\n", input_str);
    // printf("cmt iss 0 ^^  >%s<  ^^\n", input_space_spr[0]);
    // printf("cmt iss 1 ^^  >%s<  ^^\n", input_space_spr[1]);
    if (!strcmp(input_space_spr[0], cmds[0])) // cd
    {
        chdir(input_space_spr[1]);
    }
    else if (!strcmp(input_space_spr[0], cmds[1])) // pwd
    {
        exec_cmd_thread(input_str);
    }
    else if (!strcmp(input_space_spr[0], cmds[2])) // exit
    {
        printf("@@ Thank you for using CUSTOM SHELL made by Chauhan Lakshay @@\n");
        exit(0);
    }https://github.com/Hyouteki/Unix-Shell.git
    else if (!strcmp(input_space_spr[0], cmds[3])) // ls
    {
        exec_cmd_thread(input_str);
    }
    else if (!strcmp(input_space_spr[0], cmds[4])) // cat
    {
        exec_cmd_thread(input_str);
        printf("\n");
    }
    else if (!strcmp(input_space_spr[0], cmds[5])) // date
    {
        exec_cmd_thread(input_str);
    }
    else if (!strcmp(input_space_spr[0], cmds[6])) // rm
    {
        exec_cmd_thread(input_str);
    }
    else if (!strcmp(input_space_spr[0], cmds[7])) // mkdir
    {
        exec_cmd_thread(input_str);
    }
    else if (!strcmp(input_space_spr[0], cmds[8]))
    {
        help();
    }
    else if (!strcmp(input_space_spr[0], cmds[9]))
    {
        exec_cmd_thread(input_str);
    }
    else if (!strcmp(input_space_spr[0], cmds[10]))
    {
        exec_cmd_thread(input_str);
    }
    else
    {
        perror("## Error> Invalid Command ##\n");
        printf("@@ Advice> Get help @@\n");
    }
}

void prompt()
{
    char pwd[1024];
    getcwd(pwd, sizeof(pwd));
    printf("\n@@ Cwd> %s @@\n", pwd);
}

int main()
{
    initialize();

    while (true)
    {
        char input_str[MAX_CMD_LEN];
        char *input_space_spr[MAX_STR_LEN];
        prompt();
        if (input(input_str))
        {
            continue;
        }
        bool error_flag = false;
        int is_thread = check_4_thread(input_str, &error_flag);
        if (error_flag == true)
        {
            perror("## Error> Multiple &t found ##");
            continue;
        }
        if (is_thread != -1)
        {
            if (is_thread == 0)
            {
                perror("## Error> Wrong command ##");
                continue;
            }
            char buffer[is_thread];
            char buffer2[is_thread];
            for (int i = 0; i < is_thread - 1; i++)
            {
                buffer[i] = input_str[i];
                buffer2[i] = input_str[i];
            }
            buffer[is_thread - 1] = '\0';
            buffer2[is_thread - 1] = '\0';
            // printf("^^  >%s<  ^^\n", buffer);
            parse_cmd(buffer, input_space_spr);
            cmd_mngr_thread(buffer2, input_space_spr);
            continue;
        }
        parse_cmd(input_str, input_space_spr);
        cmd_mngr(input_space_spr);
    }
    return 0;
}
