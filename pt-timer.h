#ifndef __PT_TIMER_H__
#define __PT_TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    int start, interval;
} pt_timer_t;

extern void timer_set(pt_timer_t *t, int interval);
extern int timer_expired(pt_timer_t *t);

#ifdef __cplusplus
}
#endif
#endif
