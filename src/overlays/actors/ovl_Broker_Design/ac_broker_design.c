#include "ac_broker_design.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"
#include "m_field_info.h"
#include "m_event.h"

void Broker_Design_Actor_ct(Actor* thisx, Game_Play* game_play);
void Broker_Design_Actor_dt(Actor* thisx, Game_Play* game_play);
void Broker_Design_Actor_move(Actor* thisx, Game_Play* game_play);
void Broker_Design_Actor_draw(Actor* thisx, Game_Play* game_play);

void func_809516E0_jp(Actor* thisx);
u16 func_8095182C_jp(s32 unitX, s32 unitZ);
s32 func_809518D0_jp(s32 unitX, s32 unitZ);


#if 0
ActorProfile Broker_Design_Profile = {
    /* */ ACTOR_BROKER_DESIGN,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Broker_Design),
    /* */ Broker_Design_Actor_ct,
    /* */ Broker_Design_Actor_dt,
    /* */ Broker_Design_Actor_move,
    /* */ Broker_Design_Actor_draw,
    /* */ NULL,
};
#endif

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Broker_Design/ac_broker_design/func_809516E0_jp.s")

void Broker_Design_Actor_ct(Actor* thisx, Game_Play* game_play) {
    Broker_Design* this = (Broker_Design*)thisx;

    if (func_8007D318_jp(2)) {
        func_809516E0_jp(thisx);
    }
    this->clip.getFurniture = func_8095182C_jp;
    this->clip.reportSales = func_809518D0_jp;
    common_data.clip.brokerDesignClip = &this->clip;
}

void Broker_Design_Actor_dt(Actor* thisx, Game_Play* game_play) {
    common_data.clip.brokerDesignClip = NULL;
}

void Broker_Design_Actor_draw(Actor* thisx UNUSED, Game_Play* game_play UNUSED) {
}

void Broker_Design_Actor_move(Actor* thisx UNUSED, Game_Play* game_play UNUSED) {
}

u16 func_8095182C_jp(s32 unitX, s32 unitZ) {
    s32 blockX;
    s32 blockZ;
    s32 localX;
    s32 localZ;
    u16 item;

    blockX = unitX / UT_X_NUM;
    blockZ = unitZ / UT_Z_NUM;
    localX = unitX - blockX * UT_X_NUM;
    localZ = unitZ - blockZ * UT_Z_NUM;
    if (common_data.clip.myRoomClip != NULL) {
        if (common_data.clip.myRoomClip->getFurniture(&item, NULL, localX, localZ, 0) &&
            item >= 0x1000 && item < 0x1ECD) {
            return item;
        }
    }
    return 0xFFFF;
}

s32 func_809518D0_jp(s32 unitX, s32 unitZ) {
    u16 item = func_8095182C_jp(unitX, unitZ);

    if (item >= 0x1000 && item < 0x1ECD && common_data.clip.myRoomClip != NULL) {
        u16 soldItem;
        s32 furnitureId;
        u16* foreground;
        s32 localX;
        s32 localZ;
        s32 unit;

        foreground = mFI_BkNumtoUtFGTop(0, 0);
        localX = unitX & 0xF;
        localZ = unitZ & 0xF;
        unit = localX + localZ * UT_X_NUM;
        if (common_data.clip.myRoomClip->getFurniture(&soldItem, &furnitureId, unitX, unitZ, 0)) {
            s32 i;
            u16* items = common_data.save.eventSaveInfo.brokerItems;

            common_data.clip.myRoomClip->removeFurniture(furnitureId);
            foreground[unit] = 0x1F36;
            for (i = 0; i < 3; i++) {
                if (item == items[i]) {
                    items[i] = 0;
                    return 1;
                }
            }
        }
    }
    return 0;
}
