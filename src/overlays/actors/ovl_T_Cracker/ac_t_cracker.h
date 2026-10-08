#ifndef AC_T_CRACKER_H
#define AC_T_CRACKER_H

#include "ultra64.h"
#include "m_actor.h"
#include "overlays/actors/ovl_Tools/ac_tools.h"
#include "unk.h"

struct Game_Play;
struct T_Cracker;

typedef void (*T_CrackerActionFunc)(Actor*);

typedef struct T_Cracker {
    /* 0x000 */ ToolActor toolActor;
    /* 0x1C0 */ UNK_TYPE1 unk_1C0[0x8];
    /* 0x1C8 */ T_CrackerActionFunc process;
    /* 0x1CC */ s32 action;
} T_Cracker; // size = 0x1D0

#endif
