#ifndef AC_EV_GYPSY_H
#define AC_EV_GYPSY_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Ev_Gypsy;

typedef void (*Ev_GypsyActionFunc)(struct Ev_Gypsy*, struct Game_Play*);

#define aEGPS_FORTUNE_PRICE 50

typedef void (*EvGypsyTalkSetupProc)(struct Ev_Gypsy*, struct Game_Play*, s32);

typedef struct Ev_Gypsy {
    /* 0x000 */ Actor actor;
    /* 0x174 */ UNK_TYPE1 unk_174[0x7C4];
    /* 0x938 */ s32 talk_action;
    /* 0x93C */ Ev_GypsyActionFunc talk_proc;
    /* 0x940 */ EvGypsyTalkSetupProc setup_talk_proc;
    /* 0x944 */ s32 fortune_given;
} Ev_Gypsy; // size = 0x948

#endif
