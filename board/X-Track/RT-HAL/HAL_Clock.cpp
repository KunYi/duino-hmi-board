#include "HAL.h"
#include <time.h>
#include <stdio.h>

#ifdef __RTTHREAD__
#include "rtconfig.h"
#endif

void HAL::Clock_GetInfo(Clock_Info_t* info)
{

#ifdef BSP_USING_ONCHIP_RTC
    struct tm* t;
    time_t tt;
    time(&tt);
    t = localtime(&tt);
    info->year = t->tm_year + 1900;
    info->month = t->tm_mon + 1;
    info->day = t->tm_mday;
    info->week = t->tm_wday;
    info->hour = t->tm_hour;
    info->minute = t->tm_min;
    info->second = t->tm_sec;
    info->millisecond = t->tm_sec;
#else
    info->year = 2024;
    info->month = 10;
    info->day = 25;
    info->week = 35;
    info->hour = 17;
    info->minute = 35;
    info->second = 10;
    info->millisecond = 200;
#endif
}

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
