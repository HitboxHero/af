#include "6BA500.h"
#include "m_common_data.h"

void func_80096860_jp(void) {
    lbRTC_time_c* updateTime = SAVE_GET_POINTER(kabuUpdateTime);

    lbRTC_TimeCopy(updateTime, COMMON_GET_POINTER(time.rtcTime));
    updateTime->hour = 0;
    updateTime->min = 0;
    updateTime->sec = 0;
    lbRTC_Sub_DD(updateTime, updateTime->weekday);
    updateTime->weekday = lbRTC_SUNDAY;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/6BA500/func_800968C0_jp.s")

u16 func_80096B2C_jp(void) {
    return SAVE_GET(kabuDailyPrice[COMMON_GET(time.rtcTime.weekday)]);
}

void func_80096B4C_jp(u16 market) {
    SAVE_SET(kabuTradeMarket, market);
}

void Kabu_manager(void) {
    lbRTC_time_c weekAhead;
    lbRTC_time_c weekBehind;
    lbRTC_time_c* rtcTime = COMMON_GET_POINTER(time.rtcTime);
    lbRTC_time_c* updateTime = SAVE_GET_POINTER(kabuUpdateTime);

    lbRTC_TimeCopy(&weekAhead, updateTime);
    lbRTC_Add_DD(&weekAhead, lbRTC_WEEK);
    lbRTC_TimeCopy(&weekBehind, updateTime);
    lbRTC_Sub_DD(&weekBehind, lbRTC_WEEK);
    if (lbRTC_IsOverTime(&weekAhead, rtcTime) == lbRTC_OVER ||
        lbRTC_IsOverTime(&weekBehind, rtcTime) == lbRTC_LESS) {
        func_800968C0_jp();
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/6BA500/func_80096BF0_jp.s")
