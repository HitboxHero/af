#include "bg_police_item.h"
#include "m_lib.h"
#include "gfx.h"
#include "m_rcp.h"
#include "sys_matrix.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

void bPI_actor_move(Actor* thisx, Game_Play* game_play);
void bPI_actor_draw(Actor* thisx, Game_Play* game_play);
void func_808EB854_jp(BgPoliceDrawTable* table, BgPoliceBlock* block, u16* starts);
void func_808EB954_jp(BgPoliceItem* this, BgPoliceDrawTable* table, BgPoliceBlock* block);
void func_808EBB4C_jp(void);
void func_808EBC7C_jp(void);

#if 0
ActorProfile BgPoliceItem_Profile = {
    /* */ ACTOR_BG_POLICE_ITEM,
    /* */ ACTOR_PART_0,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(BgPoliceItem),
    /* */ (void*)none_proc1,
    /* */ (void*)none_proc1,
    /* */ bPI_actor_move,
    /* */ bPI_actor_draw,
    /* */ NULL,
};
#endif

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_BgPoliceItem/bg_police_item/func_808EB720_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_BgPoliceItem/bg_police_item/func_808EB854_jp.s")

void func_808EB954_jp(BgPoliceItem* this, BgPoliceDrawTable* table, BgPoliceBlock* block) {
    BgPoliceDrawPos* pos = table->positions;
    u16 starts[26];
    s32 i;
    u16* dest;
    u16* src;

    for (i = 0; i < 26; i++) {
        starts[i] = 0;
    }
    for (i = -1; i < 256; i++) {
        (pos++)->next = 256;
    }
    func_808EB854_jp(table, block, starts);
    dest = table->startIndex;
    src = starts;
    for (i = 1; i < 27; i++) {
        *dest++ = *src++;
    }
    this->drawTable.drawFlag = 1;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_BgPoliceItem/bg_police_item/func_808EBA24_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_BgPoliceItem/bg_police_item/func_808EBA8C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_BgPoliceItem/bg_police_item/bPI_actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_BgPoliceItem/bg_police_item/func_808EBB4C_jp.s")

void func_808EBC7C_jp(void) {
    extern BgPoliceDrawWork B_808EBEE0_jp;
    extern Gfx* D_808EBD94_jp[];
    extern Gfx* D_808EBE00_jp[];
    u16* starts = B_808EBEE0_jp.table->startIndex;
    s32 i;

    _texture_z_light_fog_prim(B_808EBEE0_jp.gfx);
    for (i = 1; i < 27; i++, starts++) {
        if (*starts != 0) {
            B_808EBEE0_jp.startIndex = *starts;
            B_808EBEE0_jp.material = D_808EBD94_jp[i];
            B_808EBEE0_jp.model = D_808EBE00_jp[i];
            func_808EBB4C_jp();
        }
    }
}

void bPI_actor_draw(Actor* thisx, Game_Play* game_play) {
    extern BgPoliceDrawWork B_808EBEE0_jp;
    extern BgPoliceDrawTable* B_808EBEE8_jp;
    BgPoliceItem* this = (BgPoliceItem*)thisx;

    B_808EBEE0_jp.game = game_play;
    B_808EBEE0_jp.gfx = game_play->state.gfxCtx;
    if (this->drawTable.drawFlag == 1) {
        B_808EBEE8_jp = &this->drawTable;
        func_808EBC7C_jp();
    }
}
