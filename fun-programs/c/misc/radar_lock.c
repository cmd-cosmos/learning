#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    RADAR_STATE_SEARCH = 0,
    RADAR_STATE_TRACK,
    RADAR_STATE_LOCK
} radar_state_t;

#define LOCK_CONFIRM_TICKS (3U)
#define LOCK_LOSS_TICKS    (4U)

int main(void)
{
    return 0;
}