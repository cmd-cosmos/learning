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

static radar_state_t radar_state = RADAR_STATE_SEARCH;
static uint32_t lock_timer = 0U;
static uint32_t loss_timer = 0U;

static void radar_update(bool target_detected)
{
    switch (radar_state)
    {
    case RADAR_STATE_SEARCH:
        if (target_detected == true)
        {
            radar_state = RADAR_STATE_TRACK;
            lock_timer = 0U;
        }
        break;
    case RADAR_STATE_TRACK:
        if (target_detected == true)
        {
            lock_timer++;
            if (lock_timer >= LOCK_CONFIRM_TICKS)
            {
                radar_state = RADAR_STATE_LOCK;
                loss_timer  = 0U;
            }
        }
        else
        {
            radar_state = RADAR_STATE_SEARCH;
        }
        break;
    case RADAR_STATE_LOCK:
        if (target_detected == false)
        {
            loss_timer++;
            if (loss_timer >= LOCK_LOSS_TICKS)
            {
                radar_state = RADAR_STATE_SEARCH;
            }
        }
        else
        {
            loss_timer = 0U;
        }
        break;
    default:
        radar_state = RADAR_STATE_SEARCH;
        break;
    }
}

int main(void)
{
    return 0;
}