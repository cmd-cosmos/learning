// built in test logic for sys health

#include <stdio.h>

int main(void)
{
    int cpu_ok = 1;
    int snesor_ok = 1;
    int comms_ok = 0;

    if (!cpu_ok || !snesor_ok || !comms_ok)
    {
        puts("[ALERT] FAULT DETECTED");
        if (!cpu_ok)
        {
            puts("[ERROR] CPU FAULT");
        }
        if (!snesor_ok)
        {
            puts("[ERROR] SENSOR FAULT");
        }
        if (!comms_ok)
        {
            puts("[ERROR] TRANSMITTER FAULT");
        }
    }
    else
    {
        puts("[NOMINAL] SYSTEM NOMINAL");
    }

    return 0;
}