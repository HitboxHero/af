#ifndef AC_RIDE_OFF_DEMO_H
#define AC_RIDE_OFF_DEMO_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Ride_Off_Demo;
struct Train1;

typedef void (*Ride_Off_DemoActionFunc)(struct Ride_Off_Demo*, struct Game_Play*);

typedef struct Ride_Off_Demo {
    /* 0x000 */ Actor actor;
    /* 0x174 */ s32 current_action;
    /* 0x178 */ UNK_TYPE1 unk_178[0x4];
    /* 0x17C */ ActorFunc current_proc;
    /* 0x180 */ struct Train1* train_actor;
    /* 0x184 */ Actor* station_master_actor;
    /* 0x188 */ s32 _188;
} Ride_Off_Demo; // size = 0x18C

#endif
