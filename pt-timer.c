#include "stdint.h"

#define GET_TICK HAL_GetTick

static uint32_t getCurrentMicros(void)
{
    uint32_t m0 = GET_TICK();
    __IO uint32_t u0 = SysTick->VAL;
    uint32_t m1 = GET_TICK();
    __IO uint32_t u1 = SysTick->VAL;
    const uint32_t tms = SysTick->LOAD + 1;

    if (m1 != m0)
    {
        return (m1 * 1000 + ((tms - u1) * 1000) / tms);
    }
    else
    {
        return (m0 * 1000 + ((tms - u0) * 1000) / tms);
    }
}

static uint32_t getCurrentMillis(void)
{
    return GET_TICK();
}

uint32_t millis(void)
{
    return getCurrentMillis();
}

uint32_t micros(void)
{
    return getCurrentMicros();
}