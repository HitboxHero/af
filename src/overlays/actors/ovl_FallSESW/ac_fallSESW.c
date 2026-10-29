#include "ac_fallSESW.h"
#include "overlays/actors/ovl_Structure/ac_structure.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_lib.h"
#include "audio.h"
#include "m_common_data.h"

void func_80A034A0_jp(Actor* thisx, Game_Play* game_play);
void func_80A034B0_jp(Actor* thisx, Game_Play* game_play);
void aFLEW_actor_move(Actor* thisx, Game_Play* game_play);
void aFLEW_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile FallSESW_Profile = {
    /* */ ACTOR_FALL_SESW,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x580E,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(FallSESW),
    /* */ func_80A034A0_jp,
    /* */ func_80A034B0_jp,
    /* */ aFLEW_actor_move,
    /* */ aFLEW_actor_draw,
    /* */ NULL,
};
#endif

void func_80A034A0_jp(Actor* thisx, Game_Play* game_play) {
}

void func_80A034B0_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable, 8,
                                                        STRUCTURE_TYPE_FALL_SESW, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable, 9,
                                                        STRUCTURE_PALETTE_FALL_SESW, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable, 8,
                                                        STRUCTURE_TYPE_FALL_SESW, thisx);
}

void aFLEW_actor_move(Actor* thisx, Game_Play* game_play) {
    xyz_t pos;

    xyz_t_move(&pos, &thisx->world.pos);
    pos.y += 40.0f;
    sAdo_OngenPos((s32)thisx, 12, &pos);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_FallSESW/ac_fallSESW/aFLEW_actor_draw.s")
