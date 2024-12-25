#ifndef __PT_PORT_H__
#define __PT_PORT_H__

#include "main.h"

/**
 * @brief Function called to read the current micro second
 * @param None
 * @retval None
 */
__STATIC_INLINE uint32_t getCurrentMicros(void)
{
    uint32_t m0 = HAL_GetTick();
    __IO uint32_t u0 = SysTick->VAL;
    uint32_t m1 = HAL_GetTick();
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

/**
 * @brief Function called wto read the current millisecond
 * @param None
 * @retval None
 */
__STATIC_INLINE uint32_t getCurrentMillis(void)
{
    return HAL_GetTick();
}

__STATIC_INLINE uint32_t millis(void)
{
    // ToDo: ensure no interrupts
    return getCurrentMillis();
}

// Interrupt-compatible version of micros
__STATIC_INLINE uint32_t micros(void)
{
    return getCurrentMicros();
}

#endif