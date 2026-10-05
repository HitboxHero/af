#ifndef AC_T_NPC_SAO_H
#define AC_T_NPC_SAO_H

#include "ultra64.h"
#include "m_actor.h"
#include "overlays/actors/ovl_Tools/ac_tools.h"
#include "unk.h"

struct Game_Play;
struct T_NpcSao;

typedef void (*T_NpcSaoActionFunc)(Actor*);

typedef struct T_NpcSao {
    /* 0x000 */ ToolActor toolActor;
    /* 0x1C0 */ UNK_TYPE1 unk_1C0[0x8];
    /* 0x1C8 */ T_NpcSaoActionFunc process;
    /* 0x1CC */ u8 action;
    /* 0x1CE */ s16 rotationY;
    /* 0x1D0 */ xyz_t bobberPos;
} T_NpcSao; // size = 0x1DC

#endif
