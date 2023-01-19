#include <stdio.h>
#include <time.h>

int date()
{
    time_t raw_time;
    time(&raw_time);
    struct tm * time_info = localtime(&raw_time);
    printf("%s", asctime(time_info));
    return 0;
}

int main()
{
    date();
    return 0;
}