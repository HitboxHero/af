#include "ac_fallS.h"
#include "overlays/actors/ovl_Structure/ac_structure.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_lib.h"
#include "audio.h"
#include "m_common_data.h"

void func_80A03230_jp(Actor* thisx, Game_Play* game_play);
void func_80A03240_jp(Actor* thisx, Game_Play* game_play);
void aFLS_actor_move(Actor* thisx, Game_Play* game_play);
void aFLS_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile FallS_Profile = {
    /* */ ACTOR_FALL_S,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x580D,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(FallS),
    /* */ func_80A03230_jp,
    /* */ func_80A03240_jp,
    /* */ aFLS_actor_move,
    /* */ aFLS_actor_draw,
    /* */ NULL,
};
#endif

void func_80A03230_jp(Actor* thisx, Game_Play* game_play) {
}

void func_80A03240_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable, 8,
                                                        STRUCTURE_TYPE_FALL_S, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable, 9,
                                                        STRUCTURE_PALETTE_FALL_S, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable, 8,
                                                        STRUCTURE_TYPE_FALL_S, thisx);
}

void aFLS_actor_move(Actor* thisx, Game_Play* game_play) {
    xyz_t pos;

    xyz_t_move(&pos, &thisx->world.pos);
    pos.y += 40.0f;
    sAdo_OngenPos((s32)thisx, 12, &pos);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_FallS/ac_fallS/aFLS_actor_draw.s")
