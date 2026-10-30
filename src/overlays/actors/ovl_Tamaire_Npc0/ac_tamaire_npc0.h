#ifndef AC_TAMAIRE_NPC0_H
#define AC_TAMAIRE_NPC0_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "c_keyframe.h"
#include "overlays/actors/ovl_Npc/ac_npc.h"

struct Game_Play;
struct Tamaire_Npc0;

typedef void (*Tamaire_Npc0ActionFunc)(struct Tamaire_Npc0*, struct Game_Play*);

typedef void (*Tamaire_Npc0StateProc)(Actor*, struct Game_Play*, s32);

typedef struct Tamaire_Npc0 {
    /* 0x000 */ Actor actor;
    /* 0x174 */ NpcActorInfo npcInfo;
    /* 0x17C */ UNK_TYPE1 unk_17C[0x1C];
    /* 0x198 */ SkeletonInfoR main_animation;
    /* 0x208 */ UNK_TYPE1 unk_208[0x4FC];
    /* 0x704 */ s32 animation_id;
    /* 0x708 */ UNK_TYPE1 unk_708[0x9C];
    /* 0x7A4 */ Tamaire_Npc0StateProc npc_think_proc;
    /* 0x7A8 */ s32 interrupt_flags;
    /* 0x7AC */ UNK_TYPE1 unk_7AC[0x14];
    /* 0x7C0 */ Tamaire_Npc0StateProc schedule_proc;
    /* 0x7C4 */ UNK_TYPE1 unk_7C4;
    /* 0x7C5 */ u8 action_idx;
    /* 0x7C6 */ u8 step;
    /* 0x7C7 */ UNK_TYPE1 unk_7C7[0xD];
    /* 0x7D4 */ u8 act_priority;
    /* 0x7D5 */ u8 act_idx;
    /* 0x7D6 */ u8 act_type;
    /* 0x7D7 */ UNK_TYPE1 unk_7D7;
    /* 0x7D8 */ u16 act_args[6];
    /* 0x7E4 */ UNK_TYPE1 unk_7E4[0x19];
    /* 0x7FD */ u8 hide_request;
    /* 0x7FE */ UNK_TYPE1 unk_7FE[0xE];
    /* 0x80C */ s32 demo_flg;
    /* 0x810 */ UNK_TYPE1 unk_810[0x9C];
    /* 0x8AC */ s32 palActorIgnoreTimer;
    /* 0x8B0 */ UNK_TYPE1 unk_8B0[0xC];
    /* 0x8BC */ f32 dst_pos_x;
    /* 0x8C0 */ f32 dst_pos_z;
    /* 0x8C4 */ UNK_TYPE1 unk_8C4[0x4D];
    /* 0x911 */ u8 check_kind;
    /* 0x912 */ UNK_TYPE1 unk_912[0xA];
    /* 0x91C */ ActorFunc talk_request_proc;
    /* 0x920 */ UNK_TYPE1 unk_920[0x18];
    /* 0x938 */ Tamaire_Npc0ActionFunc think_proc;
    /* 0x93C */ Tamaire_Npc0ActionFunc talk_proc;
    /* 0x940 */ s16 timer;
    /* 0x942 */ s16 yasiro_pos[2];
    /* 0x946 */ s16 move_pos[2];
    /* 0x94A */ u8 think_idx;
    /* 0x94B */ u8 next_think_idx;
    /* 0x94C */ UNK_TYPE1 unk_94C;
    /* 0x94D */ u8 talk_idx;
    /* 0x94E */ u8 change_flag;
    /* 0x94F */ UNK_TYPE1 unk_94F;
} Tamaire_Npc0; // size = 0x950

#endif
