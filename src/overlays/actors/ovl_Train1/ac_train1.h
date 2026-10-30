#ifndef AC_TRAIN1_H
#define AC_TRAIN1_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "c_keyframe.h"

struct Game_Play;
struct Train1;

typedef void (*Train1ActionFunc)(struct Train1*, struct Game_Play*);

typedef struct Train1 {
    /* 0x000 */ Actor actor;
    /* 0x174 */ s32 keyframe_state;
    /* 0x178 */ SkeletonInfoR keyframe;
    /* 0x1E8 */ UNK_TYPE1 unk_1E8[4];
    /* 0x1EC */ s_xyz work_area[15];
    /* 0x246 */ s_xyz morph_area[15];
    /* 0x2A0 */ UNK_TYPE1 unk_2A0[0x14];
    /* 0x2B4 */ s32 action;
    /* 0x2B8 */ s32 arg0;
    /* 0x2BC */ s32 arg1;
    /* 0x2C0 */ UNK_TYPE1 unk_2C0[8];
    /* 0x2C8 */ f32 arg0_f;
    /* 0x2CC */ f32 arg1_f;
    /* 0x2D0 */ UNK_TYPE1 unk_2D0[8];
} Train1; // size = 0x2D8

#endif
