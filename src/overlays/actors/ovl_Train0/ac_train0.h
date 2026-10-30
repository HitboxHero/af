#ifndef AC_TRAIN0_H
#define AC_TRAIN0_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "c_keyframe.h"

struct Game_Play;
struct Train0;

typedef void (*Train0ActionFunc)(struct Train0*, struct Game_Play*);

typedef struct Train0 {
    /* 0x000 */ Actor actor;
    /* 0x174 */ s32 keyframe_state;
    /* 0x178 */ SkeletonInfoR keyframe;
    /* 0x1E8 */ s32 keyframe_saved_keyframe;
    /* 0x1EC */ s_xyz work_area[15];
    /* 0x246 */ s_xyz morph_area[15];
    /* 0x2A0 */ UNK_TYPE1 unk_2A0[0x14];
    /* 0x2B4 */ s32 action;
    /* 0x2B8 */ UNK_TYPE1 unk_2B8[4];
    /* 0x2BC */ s32 arg1;
    /* 0x2C0 */ s32 arg2;
    /* 0x2C4 */ Actor* arg3;
    /* 0x2C8 */ f32 arg0_f;
    /* 0x2CC */ f32 arg1_f;
    /* 0x2D0 */ UNK_TYPE1 unk_2D0[8];
} Train0; // size = 0x2D8

#endif
