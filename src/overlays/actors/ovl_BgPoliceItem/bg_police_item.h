#ifndef BG_POLICE_ITEM_H
#define BG_POLICE_ITEM_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct BgPoliceItem;

typedef void (*BgPoliceItemActionFunc)(struct BgPoliceItem*, struct Game_Play*);

typedef struct BgPoliceDrawPos {
    s32 next;
    MtxF matrix;
} BgPoliceDrawPos;

typedef struct BgPoliceDrawTable {
    s32 drawFlag;
    u16 startIndex[26];
    BgPoliceDrawPos positions[257];
} BgPoliceDrawTable;

typedef struct BgPoliceBlock {
    UNK_TYPE1 unk_0[4];
    f32 x;
    f32 z;
    u16* items;
} BgPoliceBlock;

typedef struct BgPoliceItem {
    /* 0x0000 */ Actor actor;
    /* 0x0174 */ BgPoliceDrawTable drawTable;
    /* 0x45F0 */ s32 blockCount;
    /* 0x45F4 */ BgPoliceBlock blocks[4];
} BgPoliceItem; // size = 0x4634

typedef struct BgPoliceDrawWork {
    struct Game_Play* game;
    struct GraphicsContext* gfx;
    BgPoliceDrawTable* table;
    s32 startIndex;
    Gfx* material;
    Gfx* model;
    UNK_TYPE1 unk_18[8];
} BgPoliceDrawWork;

#endif
