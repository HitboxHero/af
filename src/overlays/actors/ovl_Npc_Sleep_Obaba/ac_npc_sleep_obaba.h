#ifndef AC_NPC_SLEEP_OBABA_H
#define AC_NPC_SLEEP_OBABA_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Npc_Sleep_Obaba;

typedef void (*Npc_Sleep_ObabaActionFunc)(Actor*);
typedef void (*Npc_Sleep_ObabaDispatchFunc)(Actor*, struct Game_Play*, s32);

typedef struct Npc_Sleep_Obaba {
    /* 0x000 */ Actor actor;
    /* 0x174 */ UNK_TYPE1 unk_174[0x14];
    /* 0x188 */ s32 animationState;
    /* 0x18C */ UNK_TYPE1 unk_18C[0x59F];
    /* 0x72B */ u8 loopCount;
    /* 0x72C */ UNK_TYPE1 unk_72C[0x78];
    /* 0x7A4 */ Npc_Sleep_ObabaDispatchFunc thinkProc;
    /* 0x7A8 */ u32 interruptFlags;
    /* 0x7AC */ UNK_TYPE1 unk_7AC[0x14];
    /* 0x7C0 */ Npc_Sleep_ObabaDispatchFunc scheduleProc;
    /* 0x7C4 */ UNK_TYPE1 unk_7C4;
    /* 0x7C5 */ u8 actionIndex;
    /* 0x7C6 */ u8 actionStep;
    /* 0x7C7 */ UNK_TYPE1 unk_7C7[2];
    /* 0x7C9 */ u8 actionObject;
    /* 0x7CA */ UNK_TYPE1 unk_7CA[6];
    /* 0x7D0 */ Npc_Sleep_ObabaDispatchFunc actionDispatch;
    /* 0x7D4 */ u8 requestPriority;
    /* 0x7D5 */ u8 requestAction;
    /* 0x7D6 */ u8 requestType;
    /* 0x7D7 */ UNK_TYPE1 unk_7D7[0x26];
    /* 0x7FD */ u8 hideRequest;
    /* 0x7FE */ UNK_TYPE1 unk_7FE[0xE];
    /* 0x80C */ u32 demoFlags;
    /* 0x810 */ UNK_TYPE1 unk_810[0x128];
    /* 0x938 */ s32 action;
    /* 0x93C */ Npc_Sleep_ObabaActionFunc actionProc;
} Npc_Sleep_Obaba; // size = 0x940

#endif
