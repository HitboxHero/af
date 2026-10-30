#ifndef AC_EV_MIKO_H
#define AC_EV_MIKO_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Ev_Miko;

typedef void (*Ev_MikoActionFunc)(struct Ev_Miko*, struct Game_Play*);

// Verified prefix for this event actor; the shared Npc size is unchanged.
typedef struct EvMikoNpc {
    /* 0x000 */ Actor actor;
    /* 0x174 */ UNK_TYPE1 unk_174[0x651];
    /* 0x7C5 */ u8 action_idx;
    /* 0x7C6 */ UNK_TYPE1 unk_7C6[0xE];
    /* 0x7D4 */ u8 act_priority;
    /* 0x7D5 */ u8 act_idx;
    /* 0x7D6 */ u8 act_type;
    /* 0x7D7 */ UNK_TYPE1 unk_7D7[1];
    /* 0x7D8 */ u16 act_args[6];
    /* 0x7E4 */ UNK_TYPE1 unk_7E4[0x18];
    /* 0x7FC */ u8 hide_flg;
    /* 0x7FD */ UNK_TYPE1 unk_7FD[0xAF];
    /* 0x8AC */ s32 palActorIgnoreTimer;
    /* 0x8B0 */ UNK_TYPE1 unk_8B0[0x61];
    /* 0x911 */ u8 collision_check_kind;
    /* 0x912 */ UNK_TYPE1 unk_912[0x26];
} EvMikoNpc; // verified prefix extent = 0x938

typedef struct Ev_Miko {
    /* 0x000 */ EvMikoNpc npc_class;
    /* 0x938 */ s32 talk_action;
    /* 0x93C */ ActorFunc talk_proc;
    /* 0x940 */ s32 omikuji;
    /* 0x944 */ u8 in_front;
    /* 0x945 */ UNK_TYPE1 unk_945[3];
} Ev_Miko; // size = 0x948

#endif
