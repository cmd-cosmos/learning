#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static uint32_t heartbeat_ctr  = 0U;
static uint32_t watchdog_timer = 0U;

#define WATCHDOG_TIMEOUT (3U)

void watchdog_task(bool flight_controls_ok)
{
    if (flight_controls_ok == true)
    {
        heartbeat_ctr++;
        watchdog_timer = 0U;
    }
    else
    {
        watchdog_timer++;
    }
}

uint32_t watchdog_get_heartbeat(void)
{
    return heartbeat_ctr;
}

int main(void)
{
    uint32_t i;
    bool flight_ok;

    for(i = 0U; i < 10U; i++)
    {
        if (i > 2U)
        {
            flight_ok = false;
        }
        else
        {
            flight_ok = true;
        }
    
        watchdog_task(flight_ok);
        printf("TICK: %u | HEARTBEAT: %u | WATCHDOG_TIMER: %u\n",
               i,
               watchdog_get_heartbeat(),
               watchdog_timer);

        if (watchdog_timer >= WATCHDOG_TIMEOUT)
        {
            puts("SYSTEM RESET");
            break;
        }
    }

    return 0;
}