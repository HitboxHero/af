#ifndef AC_EV_DOKUTU_H
#define AC_EV_DOKUTU_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Ev_Dokutu;

typedef void (*Ev_DokutuActionFunc)(struct Ev_Dokutu*, struct Game_Play*);

typedef void (*EvDokutuThinkProc)(Actor*, struct Game_Play*, s32);

typedef struct EvDokutuRequest {
    /* 0x00 */ u8 act_priority;
    /* 0x01 */ u8 act_idx;
    /* 0x02 */ u8 act_type;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 act_args[6];
} EvDokutuRequest; // accessed prefix size = 0x10

typedef struct EvDokutuTalkData {
    /* 0x00 */ s32 msg_no;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 turn;
    /* 0x06 */ u8 camera;
    /* 0x07 */ u8 unk_07;
} EvDokutuTalkData; // size = 0x8

typedef struct EvDokutuStateData {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
} EvDokutuStateData; // size = 0x5

typedef struct Ev_Dokutu {
    /* 0x000 */ Actor actor;
    /* 0x174 */ UNK_TYPE1 unk_174[0x630];
    /* 0x7A4 */ EvDokutuThinkProc think_proc;
    /* 0x7A8 */ UNK_TYPE1 unk_7A8[0x18];
    /* 0x7C0 */ EvDokutuThinkProc schedule_proc;
    /* 0x7C4 */ UNK_TYPE1 unk_7C4;
    /* 0x7C5 */ u8 action_idx;
    /* 0x7C6 */ u8 action_step;
    /* 0x7C7 */ UNK_TYPE1 unk_7C7[0xD];
    /* 0x7D4 */ EvDokutuRequest request;
    /* 0x7E4 */ UNK_TYPE1 unk_7E4[0x19];
    /* 0x7FD */ u8 hide_request;
    /* 0x7FE */ UNK_TYPE1 unk_7FE[0x60];
    /* 0x85E */ u8 umbrella_disabled_flag;
    /* 0x85F */ UNK_TYPE1 unk_85F[0x4D];
    /* 0x8AC */ s32 palActorIgnoreTimer;
    /* 0x8B0 */ UNK_TYPE1 unk_8B0[0x6C];
    /* 0x91C */ ActorFunc talk_request_proc;
    /* 0x920 */ UNK_TYPE1 unk_920[0x18];
    /* 0x938 */ ActorFunc unk_938;
    /* 0x93C */ ActorFunc unk_93C;
    /* 0x940 */ UNK_TYPE1 unk_940[2];
    /* 0x942 */ s16 unk_942;
    /* 0x944 */ s16 unk_944;
    /* 0x946 */ u8 unk_946;
    /* 0x947 */ u8 unk_947;
    /* 0x948 */ UNK_TYPE1 unk_948;
    /* 0x949 */ u8 unk_949;
    /* 0x94A */ u8 unk_94A;
    /* 0x94B */ UNK_TYPE1 unk_94B;
} Ev_Dokutu; // size = 0x94C

#endif
