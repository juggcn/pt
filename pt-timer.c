#include "pt-timer.h"
#include "stdint.h"

extern uint32_t HAL_GetTick(void);

static unsigned int timer_get_tick(void)
{
    return HAL_GetTick();
}

void timer_set(pt_timer_t *t, int interval)
{
    t->interval = interval;
    t->start = timer_get_tick();
}

int timer_expired(pt_timer_t *t)
{
    return (int)(timer_get_tick() - t->start) >= (int)t->interval;
}

