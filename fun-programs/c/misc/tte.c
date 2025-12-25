// time triggered executives

#include <stdio.h>

void task10ms(void){
    puts("[10 ms] CONTROL LOOP");
}

void task500ms(void){
    puts("[500 ms] VEHICLE HEALTH MONITOR");
}

int main(void)
{
    for (int tick = 1; tick <= 100; tick++)
    {
        task10ms();

        if (tick % 5 == 0)
        {
            task500ms();
        }

    }
}