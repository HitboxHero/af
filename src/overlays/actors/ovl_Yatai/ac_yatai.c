#include "ac_yatai.h"
#include "overlays/actors/ovl_Structure/ac_structure.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_field_info.h"
#include "m_common_data.h"
#include "gfx.h"
#include "sys_matrix.h"
#include "m_rcp.h"
#include "macros.h"
#include "unknown_structs.h"

void aYAT_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A76EC4_jp(Actor* thisx, Game_Play* game_play);
void aYAT_actor_init(Actor* thisx, Game_Play* game_play);
void aYAT_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Yatai_Profile = {
    /* */ ACTOR_YATAI,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x582C,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Yatai),
    /* */ aYAT_actor_ct,
    /* */ func_80A76EC4_jp,
    /* */ aYAT_actor_init,
    /* */ aYAT_actor_draw,
    /* */ NULL,
};
#endif

void func_80A77170_jp(Actor* thisx, s32 action);
void func_80A76F50_jp(Actor* thisx, s32 index);

void aYAT_actor_ct(Actor* thisx, Game_Play* game_play) {
    StructureActor* this = (StructureActor*)thisx;

    this->unk_2B8 = thisx->fgName - 0x582C;
    func_80A77170_jp(thisx, 0);
    func_80A76F50_jp(thisx, this->unk_2B8 + 2);
}

void func_80A76EC4_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable, 8,
                                                        STRUCTURE_TYPE_YATAI, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable, 9,
                                                        STRUCTURE_PALETTE_YATAI, thisx);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable, 8,
                                                        STRUCTURE_TYPE_YATAI, thisx);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Yatai/ac_yatai/func_80A76F50_jp.s")

void func_80A77160_jp(Actor* thisx, Game_Play* game_play) {
}

extern ActorFunc D_80A77530_jp[];

void func_80A77170_jp(Actor* thisx, s32 action) {
    StructureActor* this = (StructureActor*)thisx;

    this->process = D_80A77530_jp[action];
    this->unk_2B4 = action;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Yatai/ac_yatai/func_80A77190_jp.s")

void func_80A77190_jp(Actor* thisx, Game_Play* game_play);

void aYAT_actor_init(Actor* thisx, Game_Play* game_play) {
    mFI_SetFG_common(0xF0F6, thisx->home.pos, 0);
    func_80A77190_jp(thisx, game_play);
    thisx->update = func_80A77190_jp;
}

extern ShadowData* D_80A77534_jp[];
extern Gfx* D_80A7753C_jp[];

void aYAT_actor_draw(Actor* thisx, Game_Play* game_play) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    StructureActor* this = (StructureActor*)thisx;
    s32 objectSegment = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_YATAI);
    u16* paletteSegment = common_data.clip.structureClip->getPalSegment(STRUCTURE_PALETTE_YATAI);
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
        gSPDisplayList(gfx++, D_80A7753C_jp[this->unk_2B8]);
        POLY_OPA_DISP = gfx;
        CLOSE_DISPS(gfxCtx);
        common_data.clip.unk_074->unk_04(game_play, D_80A77534_jp[this->unk_2B8], STRUCTURE_TYPE_YATAI);
    }
}
