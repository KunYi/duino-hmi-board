#include "HAL.h"
#include <time.h>
#include <stdio.h>

#ifdef __RTTHREAD__
#include <rtthread.h>
#include <rtdevice.h>
#include <time.h>
#include <rtconfig.h>

#define DBG_TAG "CLOCK"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "string.h"
#endif

#if defined(__RTTHREAD__) && (defined(RT_USING_SOFT_RTC) || defined(BSP_USING_ONCHIP_RTC))
void HAL::Clock_Init() {
    time_t now;
    now = time(RT_NULL);
    LOG_I("Clock initial success, now time is %s\n", ctime(&now));
}

void HAL::Clock_GetInfo(Clock_Info_t* info)
{
    time_t now = time(RT_NULL);
    struct tm* t;
    t = localtime(&now);

    info->year = t->tm_year + 1900;
    info->month = t->tm_mon + 1;
    info->day = t->tm_mday;
    info->week = t->tm_wday;
    info->hour = t->tm_hour;
    info->minute = t->tm_min;
    info->second = t->tm_sec;
}
#else
void HAL::Clock_Init() {

}

void HAL::Clock_GetInfo(Clock_Info_t* info) {
    info->year = 2024;
    info->month = 10;
    info->day = 25;
    info->week = 35;
    info->hour = 17;
    info->minute = 35;
    info->second = 10;
    info->millisecond = 200;
}

#endif /* End of BSP_USING_ONCHIP_RTC */

void HAL::Clock_SetInfo(const Clock_Info_t* info)
{
    printf(
        "\nClock set: %04d-%02d-%02d %02d:%02d:%02d\n",
        info->year,
        info->month,
        info->day,
        info->hour,
        info->minute,
        info->second
    );
}
