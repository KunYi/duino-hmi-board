/*
   source code from https://club.rt-thread.org/ask/article/3ab411229774cf77.html
*/

#include <rtthread.h>
#include <rtdevice.h>
#include <time.h>

#define BUILD_MONTH_IS_JAN (__DATE__[0] == 'J' && __DATE__[1] == 'a')
#define BUILD_MONTH_IS_FEB (__DATE__[0] == 'F')
#define BUILD_MONTH_IS_MAR (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r')
#define BUILD_MONTH_IS_APR (__DATE__[0] == 'A' && __DATE__[1] == 'p')
#define BUILD_MONTH_IS_MAY (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y')
#define BUILD_MONTH_IS_JUN (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_JUL (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l')
#define BUILD_MONTH_IS_AUG (__DATE__[0] == 'A' && __DATE__[1] == 'u')
#define BUILD_MONTH_IS_SEP (__DATE__[0] == 'S')
#define BUILD_MONTH_IS_OCT (__DATE__[0] == 'O')
#define BUILD_MONTH_IS_NOV (__DATE__[0] == 'N')
#define BUILD_MONTH_IS_DEC (__DATE__[0] == 'D')

#define BUILD_MONTH \
    (BUILD_MONTH_IS_JAN ? 1 : \
     BUILD_MONTH_IS_FEB ? 2 : \
     BUILD_MONTH_IS_MAR ? 3 : \
     BUILD_MONTH_IS_APR ? 4 : \
     BUILD_MONTH_IS_MAY ? 5 : \
     BUILD_MONTH_IS_JUN ? 6 : \
     BUILD_MONTH_IS_JUL ? 7 : \
     BUILD_MONTH_IS_AUG ? 8 : \
     BUILD_MONTH_IS_SEP ? 9 : \
     BUILD_MONTH_IS_OCT ? 10 : \
     BUILD_MONTH_IS_NOV ? 11 : \
     12)

#define BUILD_YEAR \
    (((__DATE__[7] - '0') * 1000) + \
     ((__DATE__[8] - '0') * 100) + \
     ((__DATE__[9] - '0') * 10) + \
     (__DATE__[10] - '0'))

#define BUILD_DAY \
    (((__DATE__[4] == ' ' ? 0 : __DATE__[4] - '0') * 10) + \
     (__DATE__[5] - '0'))

#define BUILD_HOUR \
    (((__TIME__[0] - '0') * 10) + \
     (__TIME__[1] - '0'))

#define BUILD_MIN \
    (((__TIME__[3] - '0') * 10) + \
     (__TIME__[4] - '0'))

#define BUILD_SEC \
    (((__TIME__[6] - '0') * 10) + \
     (__TIME__[7] - '0'))

#define DBG_LEVEL DBG_LOG
#define DBG_SECTION_NAME "rtc"
#include <rtdbg.h>

#define RTC_NAME "rtc" /* rt_hw_rtc_register("rtc") in rtc_drv.c*/

rt_sem_t rtc_init_sem = RT_NULL;

int user_rtc_init(void)
{
    rt_err_t ret = RT_EOK;
    time_t now;
    rt_device_t device = RT_NULL;

    /*创建初始化完成信号量*/
    rtc_init_sem = rt_sem_create("rtc init flag", 0, 0);

    if(rtc_init_sem == RT_NULL)
    {
        rt_kprintf("rtc sem init failed!\n");
        return RT_ERROR;
    }
    /*寻找设备*/
    device = rt_device_find(RTC_NAME);
    if (!device)
    {
        rt_kprintf("find %s failed!\n", RTC_NAME);
        return RT_ERROR;
    }
    /*初始化RTC设备*/
    if(rt_device_open(device, 0) != RT_EOK)
    {
        rt_kprintf("open %s failed!\n", RTC_NAME);
        return RT_ERROR;
    }

    /* set time and date */
    struct tm tm_new = {0};
    tm_new.tm_year = BUILD_YEAR - 1900;
    tm_new.tm_mon = BUILD_MONTH - 1; /* .tm_min's range is [0-11] */
    tm_new.tm_mday = BUILD_DAY;
    tm_new.tm_hour = BUILD_HOUR; /* time zone */
    tm_new.tm_min = BUILD_MIN;
    tm_new.tm_sec = BUILD_SEC;
    now = mktime(&tm_new);
    set_timestamp(now);

    rt_device_close(device);
    rt_sem_release(rtc_init_sem);
    /* 获取时间 */
    now = time(RT_NULL);
    rt_kprintf("RTC device init success,now time is %s\n", ctime(&now));
    return ret;
}

INIT_ENV_EXPORT(user_rtc_init);
