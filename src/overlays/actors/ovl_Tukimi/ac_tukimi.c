#include "ac_tukimi.h"
#include "overlays/actors/ovl_Structure/ac_structure.h"
#include "m_common_data.h"
#include "m_collision_bg.h"
#include "m_field_info.h"
#include "m_player_lib.h"
#include "m_demo.h"
#include "m_lib.h"
#include "gfx.h"
#include "sys_matrix.h"
#include "m_rcp.h"
#include "unknown_structs.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "macros.h"

void aTUK_actor_ct(Actor* thisx, Game_Play* game_play);
void aTUK_actor_dt(Actor* thisx, Game_Play* game_play);
void aTUK_actor_init(Actor* thisx, Game_Play* game_play);
void aTUK_actor_draw(Actor* thisx, Game_Play* game_play);

void func_80A7FAD0_jp(Actor* thisx, s32 index);
void func_80A7FB2C_jp(Actor* thisx, s32 action);
void func_80A7FBC0_jp(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Tukimi_Profile = {
    /* */ ACTOR_TUKIMI,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x582E,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Tukimi),
    /* */ aTUK_actor_ct,
    /* */ aTUK_actor_dt,
    /* */ aTUK_actor_init,
    /* */ aTUK_actor_draw,
    /* */ NULL,
};
#endif

void aTUK_actor_ct(Actor* thisx, Game_Play* game_play) {
    extern BaseSkeletonR* D_80A80014_jp[];
    StructureActor* this = (StructureActor*)thisx;
    SkeletonInfoR* skeletonInfo = &this->skeletonInfo;

    this->unk_2B8 = thisx->fgName - 0x582E;
    this->structurePalette = this->unk_2B8 + STRUCTURE_PALETTE_TUKIMI_1;
    this->structureType = this->unk_2B8 + STRUCTURE_TYPE_TUKIMI_1;
    SegmentBaseAddress[6] = common_data.clip.structureClip->getObjectSegment(this->structureType) - 0x80000000;
    cKF_SkeletonInfo_R_ct(skeletonInfo, D_80A80014_jp[this->unk_2B8], NULL, this->jointTable, this->morphTable);
    func_80A7FAD0_jp(thisx, this->unk_2B8 + 1);
    func_80A7FB2C_jp(thisx, 0);
    cKF_SkeletonInfo_R_play(skeletonInfo);
}

void aTUK_actor_dt(Actor* thisx, Game_Play* game_play) {
    StructureActor* this = (StructureActor*)thisx;

    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable, 8,
                                                      this->structureType, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable, 9,
                                                      this->structurePalette, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable, 8,
                                                      this->structureType, thisx);
    cKF_SkeletonInfo_R_dt(&this->skeletonInfo);
}

void func_80A7FAD0_jp(Actor* thisx, s32 index) {
    index = index == 0 ? 6 : 6;
    mCoBG_SetPlussOffset(thisx->home.pos, index, 100);
}

void func_80A7FB1C_jp(Actor* thisx, Game_Play* game_play) {
}

void func_80A7FB2C_jp(Actor* thisx, s32 action) {
    extern BaseAnimationR* D_80A8001C_jp[];
    extern ActorFunc D_80A80024_jp[];
    extern const f32 RO_FLT_80A80040_jp[];
    StructureActor* this = (StructureActor*)thisx;

    cKF_SkeletonInfo_R_init(&this->skeletonInfo, this->skeletonInfo.skeleton, D_80A8001C_jp[this->unk_2B8],
                            1.0f, RO_FLT_80A80040_jp[0], 1.0f, 1.0f, 0.0f, ANIMATION_REPEAT, NULL);
    this->process = D_80A80024_jp[action];
    this->unk_2B4 = action;
}

const f32 RO_FLT_80A80040_jp[] = { 271.0f };

void func_80A7FBC0_jp(Actor* thisx, Game_Play* game_play2) {
    Game_Play* game_play = game_play2;
    StructureActor* this = (StructureActor*)thisx;
    Actor* player = (Actor*)get_player_actor_withoutCheck(game_play);
    s32 blockX;
    s32 blockZ;
    s32 playerBlockX;
    s32 playerBlockZ;

    mFI_Wpos2BlockNum(&blockX, &blockZ, thisx->world.pos);
    mFI_Wpos2BlockNum(&playerBlockX, &playerBlockZ, player->world.pos);
    if (!mDemo_Check(DEMO_TYPE_SCROLL, player) && !mDemo_Check(DEMO_TYPE_SCROLL2, player) &&
        ((blockX != playerBlockX) || (blockZ != playerBlockZ))) {
        Actor_delete(thisx);
    } else {
        SegmentBaseAddress[6] = common_data.clip.structureClip->getObjectSegment(this->structureType) - 0x80000000;
        cKF_SkeletonInfo_R_play(&this->skeletonInfo);
        ((ActorFunc)this->process)(thisx, game_play);
    }
}

void aTUK_actor_init(Actor* thisx, Game_Play* game_play) {
    mFI_SetFG_common(0xF0F6, thisx->home.pos, 0);
    func_80A7FBC0_jp(thisx, game_play);
    thisx->update = func_80A7FBC0_jp;
}

s32 func_80A7FD44_jp(Game_Play* game_play, SkeletonInfoR* skeletonInfo, s32 jointIndex, Gfx** dlist,
                       u8* displayBufferFlag, void* arg, s_xyz* rotation, xyz_t* translation) {
    if (jointIndex == 7) {
        *dlist = NULL;
    }
    return 1;
}

s32 func_80A7FD64_jp(Game_Play* game_play, SkeletonInfoR* skeletonInfo, s32 jointIndex, Gfx** dlist,
                       u8* displayBufferFlag, void* arg, s_xyz* rotation, xyz_t* translation) {
    extern Gfx* D_80A80028_jp[];
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    StructureActor* this = (StructureActor*)arg;
    Gfx* gfx;
    s32 object;
    u16* palette;
    Mtx* mtx;

    if (jointIndex == 7) {
        mtx = _Matrix_to_Mtx_new(gfxCtx);
        if (mtx != NULL) {
            object = common_data.clip.structureClip->getObjectSegment(this->structureType);
            palette = common_data.clip.structureClip->getPalSegment(this->structurePalette);
            _texture_z_light_fog_prim_shadow(gfxCtx);
            OPEN_DISPS(gfxCtx);
            gfx = SHADOW_DISP;
            gSPSegment(gfx++, 8, palette);
            gSPSegment(gfx++, 6, object);
            gSPMatrix(gfx++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_80A80028_jp[this->unk_2B8]);
            SHADOW_DISP = gfx;
            CLOSE_DISPS(gfxCtx);
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Tukimi/ac_tukimi/aTUK_actor_draw.s")
