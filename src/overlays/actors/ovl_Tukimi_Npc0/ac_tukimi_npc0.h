#ifndef AC_TUKIMI_NPC0_H
#define AC_TUKIMI_NPC0_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "overlays/actors/ovl_Npc/ac_npc.h"

struct Game_Play;
struct Tukimi_Npc0;

typedef void (*Tukimi_Npc0ActionFunc)(struct Tukimi_Npc0*, struct Game_Play*);

typedef void (*Tukimi_Npc0StateProc)(Actor*, struct Game_Play*, s32);

typedef struct Tukimi_Npc0 {
    /* 0x000 */ Actor actor;
    /* 0x174 */ NpcActorInfo npcInfo;
    /* 0x17C */ UNK_TYPE1 unk_17C[0x628];
    /* 0x7A4 */ Tukimi_Npc0StateProc think_proc;
    /* 0x7A8 */ s32 interrupt_flags;
    /* 0x7AC */ UNK_TYPE1 unk_7AC[0x14];
    /* 0x7C0 */ Tukimi_Npc0StateProc schedule_proc;
    /* 0x7C4 */ UNK_TYPE1 unk_7C4;
    /* 0x7C5 */ u8 action_idx;
    /* 0x7C6 */ u8 step;
    /* 0x7C7 */ UNK_TYPE1 unk_7C7[2];
    /* 0x7C9 */ u8 act_obj;
    /* 0x7CA */ UNK_TYPE1 unk_7CA[6];
    /* 0x7D0 */ Tukimi_Npc0StateProc act_proc;
    /* 0x7D4 */ u8 act_priority;
    /* 0x7D5 */ u8 act_idx;
    /* 0x7D6 */ u8 act_type;
    /* 0x7D7 */ UNK_TYPE1 unk_7D7[0xF];
    /* 0x7E6 */ u8 head_priority;
    /* 0x7E7 */ u8 head_type;
    /* 0x7E8 */ UNK_TYPE1 unk_7E8[4];
    /* 0x7EC */ xyz_t head_pos;
    /* 0x7F8 */ UNK_TYPE1 unk_7F8[5];
    /* 0x7FD */ u8 hide_request;
    /* 0x7FE */ UNK_TYPE1 unk_7FE[0xE];
    /* 0x80C */ s32 demo_flg;
    /* 0x810 */ UNK_TYPE1 unk_810[0x9C];
    /* 0x8AC */ s32 palActorIgnoreTimer;
    /* 0x8B0 */ UNK_TYPE1 unk_8B0[0x2C];
    /* 0x8DC */ s16 mv_angl;
    /* 0x8DE */ UNK_TYPE1 unk_8DE[0x33];
    /* 0x911 */ u8 check_kind;
    /* 0x912 */ UNK_TYPE1 unk_912[0x19];
    /* 0x92B */ u8 turn;
    /* 0x92C */ s16 default_animation;
    /* 0x92E */ UNK_TYPE1 unk_92E[0xA];
} Tukimi_Npc0; // size = 0x938

#endif
