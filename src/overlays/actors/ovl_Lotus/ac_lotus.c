#include "ac_lotus.h"
#include "overlays/actors/ovl_Structure/ac_structure.h"
#include "objects/object_00D5E000/obj_s_lotus/obj_s_lotus.h"
#include "m_common_data.h"
#include "m_collision_bg.h"
#include "m_field_info.h"
#include "m_lib.h"
#include "m_rcp.h"
#include "gfx.h"
#include "macros.h"
#include "m_collision_obj.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

void aLOT_actor_ct(Actor* thisx, Game_Play* game_play);
void aLOT_actor_dt(Actor* thisx, Game_Play* game_play);
void aLOT_actor_init(Actor* thisx, Game_Play* game_play);
void aLOT_actor_draw(Actor* thisx, Game_Play* game_play);

s32 func_80A9EE40_jp(void);
void func_80A9EF6C_jp(Actor* thisx, s32 action);
void func_80A9F004_jp(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Lotus_Profile = {
    /* */ ACTOR_LOTUS,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x5840,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Lotus),
    /* */ aLOT_actor_ct,
    /* */ aLOT_actor_dt,
    /* */ aLOT_actor_init,
    /* */ aLOT_actor_draw,
    /* */ NULL,
};
#endif

extern CollisionCheck_Status_Init lotus_StatusData;
extern ClObjPipe_Init lotus_CoInfoData;
#if 0
CollisionCheck_Status_Init lotus_StatusData = { 0, 0, 0, 0, 10, };
ClObjPipe_Init lotus_CoInfoData = { { OC1_1 | OC1_4 | OC1_TYPE_8 | OC1_TYPE_10 | OC1_TYPE_20, OC2_TYPE_10, COLSHAPE_PIPE }, { ELEM_FLAG_1 }, { { 0x46, 6, 0, { 0, 0, 0 } } }, };
#endif

extern ClObjPipe pipeinfo;
#if 0
ClObjPipe pipeinfo;
#endif

void aLOT_actor_ct(Actor* thisx, Game_Play* game_play) {
    extern const char RO_STR_80A9F4D0_jp[];
    StructureActor* this = (StructureActor*)thisx;
    f32 waterHeight;
    s32 palette;

    waterHeight = mCoBG_GetWaterHeight_File(thisx->world.pos, (char*)RO_STR_80A9F4D0_jp, 227);
    SegmentBaseAddress[6] = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_LOTUS) - 0x80000000;
    cKF_SkeletonInfo_R_ct(&this->skeletonInfo, &cKF_bs_r_obj_s_lotus, NULL, this->jointTable, this->morphTable);
    ClObjPipe_ct(game_play, &pipeinfo);
    ClObjPipe_set5(game_play, &pipeinfo, thisx, &lotus_CoInfoData);
    CollisionCheck_Status_set3(&thisx->colStatus, &lotus_StatusData);
    thisx->world.pos.y = waterHeight;
    palette = func_80A9EE40_jp();
    this->unk_2B8 = palette;
    func_80A9EF6C_jp(thisx, 0);
    cKF_SkeletonInfo_R_play(&this->skeletonInfo);
}

const char RO_STR_80A9F4D0_jp[] = "../ac_lotus.c";

void aLOT_actor_dt(Actor* thisx, Game_Play* game_play) {
    StructureActor* this = (StructureActor*)thisx;

    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable, 8,
                                                      STRUCTURE_TYPE_LOTUS, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable, 9,
                                                      STRUCTURE_PALETTE_LOTUS, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable, 8,
                                                      STRUCTURE_TYPE_LOTUS, thisx);
    cKF_SkeletonInfo_R_dt(&this->skeletonInfo);
}

s32 func_80A9EE40_jp(void) {
    extern s32 D_80A9F300_jp[];
    return D_80A9F300_jp[common_data.time.termIdx];
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Lotus/ac_lotus/func_80A9EE60_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Lotus/ac_lotus/func_80A9EF04_jp.s")

void func_80A9EF6C_jp(Actor* thisx, s32 action) {
    extern ActorFunc D_80A9F348_jp[];
    StructureActor* this = (StructureActor*)thisx;

    if (action == 0) {
        cKF_SkeletonInfo_R_init(&this->skeletonInfo, this->skeletonInfo.skeleton, &cKF_ba_r_obj_s_lotus,
                               1.0f, 129.0f, 1.0f, 1.0f, 0.0f, ANIMATION_REPEAT, NULL);
    }
    this->process = D_80A9F348_jp[action];
    this->unk_2B4 = action;
}

void func_80A9F004_jp(Actor* thisx, Game_Play* game_play) {
    StructureActor* this = (StructureActor*)thisx;

    SegmentBaseAddress[6] = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_LOTUS) - 0x80000000;
    cKF_SkeletonInfo_R_play(&this->skeletonInfo);
    ((ActorFunc)this->process)(thisx, game_play);
    CollisionCheck_Uty_ActorWorldPosSetPipeC(thisx, &pipeinfo);
    CollisionCheck_setOC(game_play, &game_play->unk_2138, &pipeinfo.base);
}

void aLOT_actor_init(Actor* thisx, Game_Play* game_play) {
    mFI_SetFG_common(0xF107, thisx->home.pos, 0);
    func_80A9F004_jp(thisx, game_play);
    thisx->update = func_80A9F004_jp;
}

s32 func_80A9F0F8_jp(Game_Play* game_play, SkeletonInfoR* skeletonInfo, s32 jointIndex, Gfx** dlist,
                       u8* displayBufferFlag, void* arg, s_xyz* rotation, xyz_t* translation) {
    extern s32 D_80A9F470_jp[];
    s32 draw;
    s32 month;
    s32 day;
    Gfx* gfx;
    GraphicsContext* gfxCtx;
    lbRTC_time_c* rtcTime;

    gfxCtx = game_play->state.gfxCtx;
    rtcTime = &common_data.time.rtcTime;
    month = rtcTime->month;
    day = rtcTime->day;
    draw = D_80A9F470_jp[month];
    OPEN_DISPS(gfxCtx);
    gfx = POLY_OPA_DISP;
    if (jointIndex == 18) {
        switch (month) {
            case 5:
                if (day < 26) {
                    draw = 0;
                }
                break;
            case 8:
                if (day < 26) {
                    draw = 1;
                }
                break;
        }
        if (draw == 0) {
            *dlist = NULL;
        }
    }
    POLY_OPA_DISP = gfx;
    CLOSE_DISPS(gfxCtx);
    return 1;
}

void aLOT_actor_draw(Actor* thisx, Game_Play* game_play) {
    extern u16* D_80A9F4A4_jp[];
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    StructureActor* this = (StructureActor*)thisx;
    SkeletonInfoR* skeletonInfo = &this->skeletonInfo;
    Mtx* mtx;
    s32 object;

    if (this->unk_2B8 >= 0) {
        mtx = GRAPH_ALLOC_NO_ALIGN(gfxCtx, skeletonInfo->skeleton->unk01 * sizeof(Mtx));
        if (mtx != NULL) {
            object = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_LOTUS);
            _texture_z_light_fog_prim_npc(gfxCtx);
            OPEN_POLY_OPA_DISP(gfxCtx);
            gSPSegment(__polyOpa++, 8, Lib_SegmentedToVirtual(D_80A9F4A4_jp[this->unk_2B8]));
            SegmentBaseAddress[6] = object - 0x80000000;
            gSPSegment(__polyOpa++, 6, object);
            CLOSE_POLY_OPA_DISP(gfxCtx);
            cKF_Si3_draw_R_SV(game_play, skeletonInfo, mtx, func_80A9F0F8_jp, NULL, this);
        }
    }
}
