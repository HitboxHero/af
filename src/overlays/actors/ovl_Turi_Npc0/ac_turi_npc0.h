#ifndef AC_TURI_NPC0_H
#define AC_TURI_NPC0_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "overlays/actors/ovl_Npc/ac_npc.h"

struct Game_Play;
struct Turi_Npc0;

typedef void (*Turi_Npc0ActionFunc)(struct Turi_Npc0*, struct Game_Play*);

typedef void (*Turi_Npc0StateProc)(Actor*, struct Game_Play*, s32);
typedef void (*Turi_Npc0ActProc)(struct Turi_Npc0*);

typedef struct Turi_Npc0 {
    /* 0x000 */ Actor actor;
    /* 0x174 */ NpcActorInfo npcInfo;
    /* 0x17C */ u8 unk_17C[0xC];
    /* 0x188 */ s32 main_animation_state;
    /* 0x18C */ u8 unk_18C[0x59F];
    /* 0x72B */ u8 loop_flag;
    /* 0x72C */ u8 unk_72C[0x78];
    /* 0x7A4 */ Turi_Npc0StateProc think_proc;
    /* 0x7A8 */ s32 interrupt_flags;
    /* 0x7AC */ u8 unk_7AC[0x14];
    /* 0x7C0 */ Turi_Npc0StateProc schedule_proc;
    /* 0x7C4 */ u8 unk_7C4;
    /* 0x7C5 */ u8 action_idx;
    /* 0x7C6 */ u8 step;
    /* 0x7C7 */ u8 unk_7C7[2];
    /* 0x7C9 */ u8 act_obj;
    /* 0x7CA */ u8 unk_7CA[6];
    /* 0x7D0 */ Turi_Npc0StateProc action_act_proc;
    /* 0x7D4 */ u8 act_priority;
    /* 0x7D5 */ u8 act_idx;
    /* 0x7D6 */ u8 act_type;
    /* 0x7D7 */ u8 unk_7D7[0x26];
    /* 0x7FD */ u8 hide_request;
    /* 0x7FE */ u8 unk_7FE[0xE];
    /* 0x80C */ s32 demo_flg;
    /* 0x810 */ u8 unk_810[0x50];
    /* 0x860 */ Actor* item_actor_p;
    /* 0x864 */ u8 unk_864[0x48];
    /* 0x8AC */ s32 palActorIgnoreTimer;
    /* 0x8B0 */ u8 unk_8B0[0x2C];
    /* 0x8DC */ s16 mv_angl;
    /* 0x8DE */ u8 unk_8DE[0x33];
    /* 0x911 */ u8 check_kind;
    /* 0x912 */ u8 unk_912[0x19];
    /* 0x92B */ u8 turn;
    /* 0x92C */ s16 default_animation;
    /* 0x92E */ u8 unk_92E[0xA];
    /* 0x938 */ s32 action;
    /* 0x93C */ Turi_Npc0ActProc act_proc;
} Turi_Npc0; // size = 0x940

#endif
