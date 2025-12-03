#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

int main()
{
    time_t raw = 0;
    struct tm* ptrTime = NULL;
    bool run = true;

    printf("===========Clock===========\n");
    while(run){
        time(&raw);
        ptrTime = localtime(&raw);

        // \r --> carriage return --> in place string edit in the ostream 
        printf("\r%02d:%02d:%02d", ptrTime->tm_hour, ptrTime->tm_min, ptrTime->tm_sec);
        sleep(1);
    }

    return 0;
}