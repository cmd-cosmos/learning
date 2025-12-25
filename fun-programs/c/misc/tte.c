// time triggered executives

#include <stdio.h>
#include <windows.h>

void task10ms(void){
    puts("[10 ms] CONTROL LOOP");
}

void task500ms(void){
    puts("[500 ms] VEHICLE HEALTH MONITOR");
}

int main(void)
{
    LARGE_INTEGER freq, next, now;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&next);

    double tick = 0.010;
    LONGLONG tick_count = (LONGLONG)(tick * freq.QuadPart);

    for (int i = 1; i <= 100; i++)
    {
        task10ms();

        if (i % 5 == 0)
        {
            task500ms();
        }
        next.QuadPart += tick_count;

        do {
            QueryPerformanceCounter(&now);
            Sleep(0);
        } while (now.QuadPart < next.QuadPart);        
    }
}