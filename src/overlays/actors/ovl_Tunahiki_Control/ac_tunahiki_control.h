#ifndef AC_TUNAHIKI_CONTROL_H
#define AC_TUNAHIKI_CONTROL_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Tunahiki_Control;

typedef void (*Tunahiki_ControlActionFunc)(struct Tunahiki_Control*, struct Game_Play*);

typedef struct Tunahiki_Control {
    /* 0x000 */ Actor actor;
    /* 0x174 */ Tunahiki_ControlActionFunc process;
    /* 0x178 */ s32 action;
} Tunahiki_Control; // size = 0x17C

// Event 9 save payload: offsets verified from this overlay's N64 loads/stores.
typedef struct TunahikiControlSave {
    /* 0x00 */ f32 rope;
    /* 0x04 */ f32 ropeBase;
    /* 0x08 */ f32 speed;
    /* 0x0C */ u8 unk_0C[4];
    /* 0x10 */ s16 npcState;
    /* 0x12 */ u16 flags;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ u16 counter;
} TunahikiControlSave; // accessed extent = 0x18

#endif
