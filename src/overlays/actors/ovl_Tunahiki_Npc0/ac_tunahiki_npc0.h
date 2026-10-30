#ifndef AC_TUNAHIKI_NPC0_H
#define AC_TUNAHIKI_NPC0_H

#include "ultra64.h"
#include "m_actor.h"
#include "m_collision_obj.h"
#include "unk.h"

struct Game_Play;
struct Tunahiki_Npc0;

typedef void (*Tunahiki_Npc0ActionFunc)(struct Tunahiki_Npc0*, struct Game_Play*);
typedef void (*Tunahiki_Npc0StateFunc)(Actor*, struct Game_Play*, s32);

// NPC prefix accesses verified in this target; shared Npc layout remains unchanged.
typedef struct TunahikiNpc0Npc {
    /* 0x000 */ Actor actor;
    /* 0x174 */ UNK_TYPE1 unk_174[0x630];
    /* 0x7A4 */ Tunahiki_Npc0StateFunc think_proc;
    /* 0x7A8 */ UNK_TYPE1 unk_7A8[0x18];
    /* 0x7C0 */ Tunahiki_Npc0StateFunc schedule_proc;
    /* 0x7C4 */ UNK_TYPE1 unk_7C4[1];
    /* 0x7C5 */ u8 action_idx;
    /* 0x7C6 */ u8 action_step;
    /* 0x7C7 */ UNK_TYPE1 unk_7C7[0xD];
    /* 0x7D4 */ u8 act_priority;
    /* 0x7D5 */ u8 act_idx;
    /* 0x7D6 */ u8 act_type;
    /* 0x7D7 */ UNK_TYPE1 unk_7D7[1];
    /* 0x7D8 */ u16 act_args[6];
    /* 0x7E4 */ UNK_TYPE1 unk_7E4[0x19];
    /* 0x7FD */ u8 hide_request;
    /* 0x7FE */ UNK_TYPE1 unk_7FE[0xE];
    /* 0x80C */ u32 demo_flg;
    /* 0x810 */ UNK_TYPE1 unk_810[0x50];
    /* 0x860 */ Actor* right_hand_item_actor_p;
    /* 0x864 */ UNK_TYPE1 unk_864[0x12];
    /* 0x876 */ u8 head_lock_flag;
    /* 0x877 */ UNK_TYPE1 unk_877[0x35];
    /* 0x8AC */ s32 palActorIgnoreTimer;
    /* 0x8B0 */ UNK_TYPE1 unk_8B0[0x40];
    /* 0x8F0 */ ClObjPipe collider;
    /* 0x90C */ UNK_TYPE1 unk_90C[5];
    /* 0x911 */ u8 collision_check_kind;
    /* 0x912 */ UNK_TYPE1 unk_912[0xA];
    /* 0x91C */ ActorFunc talk_request_proc;
    /* 0x920 */ UNK_TYPE1 unk_920[0xB];
    /* 0x92B */ u8 talk_turn;
    /* 0x92C */ s16 default_animation;
    /* 0x92E */ UNK_TYPE1 unk_92E[0xA];
} TunahikiNpc0Npc; // verified NPC prefix extent = 0x938

typedef struct Tunahiki_Npc0 {
    /* 0x000 */ TunahikiNpc0Npc npc_class;
    /* 0x938 */ ActorFunc think_proc;
    /* 0x93C */ ActorFunc talk_proc;
    /* 0x940 */ Actor* rope_p;
    /* 0x944 */ s32 base_msg;
    /* 0x948 */ UNK_TYPE1 unk_948[2];
    /* 0x94A */ u8 think_idx;
    /* 0x94B */ u8 next_think_idx;
    /* 0x94C */ u8 talk_idx;
    /* 0x94D */ u8 change_flag;
    /* 0x94E */ UNK_TYPE1 unk_94E[2];
} Tunahiki_Npc0; // size = 0x950

#endif
