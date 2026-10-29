#ifndef AC_TRAIN1_H
#define AC_TRAIN1_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Train1;

typedef void (*Train1ActionFunc)(struct Train1*, struct Game_Play*);

typedef struct Train1 {
    /* 0x000 */ Actor actor;
    /* 0x174 */ UNK_TYPE1 unk_174[0x140];
    /* 0x2B4 */ s32 action;
    /* 0x2B8 */ s32 arg0;
    /* 0x2BC */ UNK_TYPE1 unk_2BC[0x1C];
} Train1; // size = 0x2D8

#endif
