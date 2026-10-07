#ifndef AC_T_UMBRELLA_H
#define AC_T_UMBRELLA_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct T_Umbrella;

typedef void (*T_UmbrellaActionFunc)(Actor*);

typedef struct T_Umbrella {
    /* 0x000 */ Actor actor;
    /* 0x174 */ UNK_TYPE1 unk_174[0x54];
    /* 0x1C8 */ T_UmbrellaActionFunc actionProc;
    /* 0x1CC */ s32 action;
    /* 0x1D0 */ f32 frame;
    /* 0x1D4 */ xyz_t shaftScale;
    /* 0x1E0 */ xyz_t canopyScale;
    /* 0x1EC */ s32 openedFully;
} T_Umbrella; // size = 0x1F0

typedef struct T_UmbrellaAnimation {
    s32 count;
    f32* sections;
    f32* scales;
} T_UmbrellaAnimation;

typedef struct T_UmbrellaModel {
    Gfx* shaft;
    Gfx* canopy;
} T_UmbrellaModel;

#endif
