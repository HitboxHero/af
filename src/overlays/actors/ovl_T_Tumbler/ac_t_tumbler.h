#ifndef AC_T_TUMBLER_H
#define AC_T_TUMBLER_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "overlays/actors/ovl_Tools/ac_tools.h"

struct Game_Play;
struct T_Tumbler;

typedef void (*T_TumblerActionFunc)(Actor*);

typedef struct T_Tumbler {
    /* 0x000 */ ToolActor toolActor;
    /* 0x1C0 */ UNK_TYPE1 unk_1C0[0x8];
    /* 0x1C8 */ T_TumblerActionFunc process;
    /* 0x1CC */ s32 action;
} T_Tumbler; // size = 0x1D0

#endif
