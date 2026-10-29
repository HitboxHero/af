#ifndef AC_NPC_MAJIN5_H
#define AC_NPC_MAJIN5_H

#include "ultra64.h"
#include "m_actor.h"
#include "c_keyframe.h"
#include "unk.h"

struct Game_Play;
struct Npc_Majin5;

typedef void (*Npc_Majin5ActionFunc)(struct Npc_Majin5*, struct Game_Play*);

typedef void (*NpcMajin5ThinkProc)(struct Npc_Majin5*, struct Game_Play*, s32);
typedef void (*NpcMajin5AnimationInitProc)(Actor*, s32, s32);
typedef void (*NpcMajin5EffectMakeProc)(s32 effect_id, xyz_t position, s32 prio, s16 angle,
                                       struct Game* game, u16 item_name, s16 arg0, s16 arg1);

typedef struct NpcMajin5Request {
    /* 0x00 */ u8 act_priority;
    /* 0x01 */ u8 act_idx;
    /* 0x02 */ u8 act_type;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 act_args[6];
} NpcMajin5Request; // size = 0x10

typedef struct NpcMajin5EventSave {
    /* 0x00 */ u8 unk_00[2];
    /* 0x02 */ u16 bitfield;
} NpcMajin5EventSave; // accessed extent = 0x4

typedef struct Npc_Majin5 {
    /* 0x000 */ Actor actor;
    /* 0x174 */ UNK_TYPE1 unk_174[0x38];
    /* 0x1AC */ AnimationMode main_animation_mode;
    /* 0x1B0 */ UNK_TYPE1 unk_1B0[0x5F4];
    /* 0x7A4 */ NpcMajin5ThinkProc think_proc;
    /* 0x7A8 */ UNK_TYPE1 unk_7A8[0x18];
    /* 0x7C0 */ NpcMajin5ThinkProc schedule_proc;
    /* 0x7C4 */ UNK_TYPE1 unk_7C4;
    /* 0x7C5 */ u8 action_idx;
    /* 0x7C6 */ UNK_TYPE1 unk_7C6[0xE];
    /* 0x7D4 */ NpcMajin5Request request;
    /* 0x7E4 */ UNK_TYPE1 unk_7E4[0x19];
    /* 0x7FD */ u8 hide_request;
    /* 0x7FE */ UNK_TYPE1 unk_7FE[0xE];
    /* 0x80C */ u32 demo_flg;
    /* 0x810 */ UNK_TYPE1 unk_810[0x4E];
    /* 0x85E */ u8 umbrella_disabled_flag;
    /* 0x85F */ UNK_TYPE1 unk_85F[0x4D];
    /* 0x8AC */ s32 palActorIgnoreTimer;
    /* 0x8B0 */ UNK_TYPE1 unk_8B0[0x61];
    /* 0x911 */ u8 check_kind;
    /* 0x912 */ UNK_TYPE1 unk_912[0x26];
} Npc_Majin5; // size = 0x938

#endif
