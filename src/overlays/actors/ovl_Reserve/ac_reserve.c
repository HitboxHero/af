#include "ac_reserve.h"
#include "overlays/actors/ovl_Structure/ac_structure.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_field_info.h"
#include "m_common_data.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_player_lib.h"
#include "m_demo.h"
#include "macros.h"
#include "gfx.h"
#include "sys_matrix.h"
#include "m_rcp.h"
#include "m_time.h"
#include "unknown_structs.h"

void aRSV_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A09370_jp(Actor* thisx, Game_Play* game_play);
void aRSV_actor_init(Actor* thisx, Game_Play* game_play);
void aRSV_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Reserve_Profile = {
    /* */ ACTOR_RESERVE,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x5810,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Reserve),
    /* */ aRSV_actor_ct,
    /* */ func_80A09370_jp,
    /* */ aRSV_actor_init,
    /* */ aRSV_actor_draw,
    /* */ NULL,
};
#endif

void func_80A09580_jp(Actor* thisx, s32 action);
void func_80A093FC_jp(Actor* thisx, s32 arg1);

void aRSV_actor_ct(Actor* thisx, Game_Play* game_play) {
    StructureActor* this = (StructureActor*)thisx;

    this->unk_2B8 = thisx->fgName - 0x5810;
    func_80A09580_jp(thisx, 0);
    func_80A093FC_jp(thisx, 1);
}

void func_80A09370_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable, 8,
                                                        STRUCTURE_TYPE_RESERVE, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable, 9,
                                                        STRUCTURE_PALETTE_RESERVE, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable, 8,
                                                        STRUCTURE_TYPE_RESERVE, thisx);
}

void func_80A093FC_jp(Actor* thisx, s32 arg1) {
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Reserve/ac_reserve/func_80A0940C_jp.s")

void func_80A0940C_jp(Actor* thisx);

void func_80A094EC_jp(Actor* thisx, Game_Play* game_play) {
    Player* player = get_player_actor_withoutCheck(game_play);
    s32 angle;

    if (mDemo_Check(DEMO_TYPE_TALK, thisx) != 1 && player != NULL) {
        if (player->actor.world.pos.z >= thisx->world.pos.z) {
            angle = ABS(thisx->yawTowardsPlayer);
            if (angle < 0x2000) {
                mDemo_Request(DEMO_TYPE_TALK, thisx, func_80A0940C_jp);
            }
        }
    }
}

extern ActorFunc D_80A097BC_jp[];

void func_80A09580_jp(Actor* thisx, s32 action) {
    StructureActor* this = (StructureActor*)thisx;

    this->process = D_80A097BC_jp[action];
    this->unk_2B4 = action;
}

void func_80A095A0_jp(Actor* thisx, Game_Play* game_play) {
    StructureActor* this = (StructureActor*)thisx;

    ((ActorFunc)this->process)(thisx, game_play);
}

void aRSV_actor_init(Actor* thisx, Game_Play* game_play) {
    mFI_SetFG_common(0xF0EE, thisx->home.pos, 0);
    func_80A095A0_jp(thisx, game_play);
    thisx->update = func_80A095A0_jp;
}

extern ShadowData D_80A097A8_jp;
extern Gfx* D_80A097C0_jp[];

void aRSV_actor_draw(Actor* thisx, Game_Play* game_play) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    s32 isWinter = common_data.time.season == mTM_SEASON_WINTER;
    s32 objectSegment = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_RESERVE);
    u16* paletteSegment = common_data.clip.structureClip->getPalSegment(STRUCTURE_PALETTE_RESERVE);
    Mtx* mtx = _Matrix_to_Mtx_new(gfxCtx);

    if (mtx != NULL) {
        Gfx* gfx;

        _texture_z_light_fog_prim_npc(gfxCtx);
        OPEN_DISPS(gfxCtx);
        gfx = POLY_OPA_DISP;
        gSPSegment(gfx++, 8, paletteSegment);
        SegmentBaseAddress[6] = objectSegment - 0x80000000;
        gSPSegment(gfx++, 6, objectSegment);
        gSPMatrix(gfx++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, D_80A097C0_jp[isWinter]);
        POLY_OPA_DISP = gfx;
        common_data.clip.unk_074->unk_04(game_play, &D_80A097A8_jp, STRUCTURE_TYPE_RESERVE);
        CLOSE_DISPS(gfxCtx);
    }
}
