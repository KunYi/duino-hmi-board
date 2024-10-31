#include "HAL.h"
#include <rtthread.h>
#include <rtdevice.h>

bool HAL::SD_Init()
{
    return true;
}

bool HAL::SD_GetReady()
{
    return true;
}

float HAL::SD_GetCardSizeMB()
{
    rt_device_t sd = rt_device_find("sd0");
    if( sd == RT_NULL) {
        return 0.0f;
    }

    if (RT_EOK != rt_device_open(sd, RT_DEVICE_FLAG_RDONLY)) {
        return 0.0f;
    }

    struct rt_device_blk_geometry geometry;
    rt_memset(&geometry, 0, sizeof(geometry));
    if (RT_EOK != rt_device_control(sd,
                RT_DEVICE_CTRL_BLK_GETGEOME,
                &geometry)) {
        rt_device_close(sd);
        return 0.0f;
    }
    rt_device_close(sd);
    /*
      return size, unit GiB
      (1000*1000) because storage industry use 1000 not 1024
    */
    return ((geometry.sector_count * geometry.bytes_per_sector)/(1000*1000));

}

const char* HAL::SD_GetTypeName()
{
    return "SDHC";
}

static void SD_Check(bool isInsert)
{

}

void HAL::SD_SetEventCallback(SD_CallbackFunction_t callback)
{

}

void HAL::SD_Update()
{

}
