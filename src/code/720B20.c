#include "720B20.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/720B20/Na_Inst.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/720B20/func_800FCEEC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/720B20/Na_InstCountGet.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/720B20/func_800FD0D4_jp.s")

s16 func_800FD13C_jp(s16 instrument) {
    if (instrument == 0) {
        return 6;
    } else if (instrument == 255) {
        return 7;
    } else {
        return 15;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/720B20/Na_FurnitureInst.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/720B20/func_800FD280_jp.s")
