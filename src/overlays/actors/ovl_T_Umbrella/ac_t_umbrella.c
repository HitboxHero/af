#include "ac_t_umbrella.h"
#include "audio.h"
#include "overlays/actors/ovl_Tools/ac_tools.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "sys_matrix.h"
#include "m_rcp.h"
#include "gfx.h"

void aTUMB_actor_ct(Actor* thisx, Game_Play* game_play);
void aTUMB_actor_move(Actor* thisx, Game_Play* game_play);
void aTUMB_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile T_Umbrella_Profile = {
    /* */ ACTOR_T_UMBRELLA,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ OBJECT_28,
    /* */ sizeof(T_Umbrella),
    /* */ aTUMB_actor_ct,
    /* */ (void*)none_proc1,
    /* */ aTUMB_actor_move,
    /* */ aTUMB_actor_draw,
    /* */ NULL,
};
#endif

void func_80A1EF20_jp(Actor* thisx, s32 action);
void func_80A1ED4C_jp(xyz_t* scale, T_Umbrella* this, s32 index);
void func_80A1EE48_jp(T_Umbrella* this);
void func_80A1EE84_jp(T_Umbrella* this);

void aTUMB_actor_ct(Actor* thisx, Game_Play* game_play) {
    ToolActor* this = (ToolActor*)thisx;

    func_80A1EF20_jp(thisx, this->unk1BC);
}

void func_80A1ECD4_jp(Actor* thisx, u16 id) {
    sAdo_OngenTrgStart(id, &thisx->world.pos);
}

void func_80A1ED04_jp(Actor* thisx, s32 action) {
    switch (action) {
        case 0:
            func_80A1ECD4_jp(thisx, 0x139);
            break;
        case 1:
            func_80A1ECD4_jp(thisx, 0x10E);
            break;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Umbrella/ac_t_umbrella/func_80A1ED4C_jp.s")

void func_80A1EE48_jp(T_Umbrella* this) {
    func_80A1ED4C_jp(&this->shaftScale, this, 0);
    func_80A1ED4C_jp(&this->canopyScale, this, 1);
}

void func_80A1EE84_jp(T_Umbrella* this) {
    extern f32 D_FLT_80A1F308_jp[];
    f32 maxFrame;
    f32 frame;

    maxFrame = D_FLT_80A1F308_jp[this->action];
    frame = this->frame;

    frame += 1.0f;
    if (frame >= maxFrame) {
        frame = maxFrame;
    }
    if (this->action == 0) {
        this->openedFully = frame == maxFrame;
    }
    this->frame = frame;
    func_80A1EE48_jp(this);
}

void func_80A1EF00_jp(Actor* thisx) {
    Actor_delete(thisx);
}

void func_80A1EF20_jp(Actor* thisx, s32 action) {
    extern T_UmbrellaActionFunc D_80A1F318_jp[];
    extern T_UmbrellaActionFunc D_80A1F324_jp[];
    f32 frame;

    ((T_Umbrella*)thisx)->actionProc = D_80A1F318_jp[action];
    ((T_Umbrella*)thisx)->action = action;
    func_80A1ED04_jp(thisx, action);
    if (D_80A1F324_jp == &D_80A1F318_jp[action]) {
        frame = 26.0f;
        ((T_Umbrella*)thisx)->openedFully = 1;
    } else {
        frame = 0.0f;
    }
    ((T_Umbrella*)thisx)->frame = frame;
}

void aTUMB_actor_move(Actor* thisx, Game_Play* game_play) {
    T_Umbrella* this = (T_Umbrella*)thisx;

    if (((ToolActor*)thisx)->unk1BC != this->action) {
        func_80A1EF20_jp(thisx, ((ToolActor*)thisx)->unk1BC);
    }
    func_80A1EE84_jp(this);
    this->actionProc(thisx);
}

void aTUMB_actor_draw(Actor* thisx, Game_Play* game_play) {
    extern xyz_t D_80A1F32C_jp;
    extern T_UmbrellaModel D_80A1F338_jp[];
    extern const f32 RO_FLT_80A1F440_jp[];
    T_Umbrella* this = (T_Umbrella*)thisx;
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    s32 toolName = ((ToolActor*)thisx)->toolName;
    T_UmbrellaModel* model;
    Actor* parent = thisx->parent;

    // Keep the native Boolean normalization before testing the draw flag.
    if (((parent->isDrawn != 0) != 0) && ((ToolActor*)thisx)->unk1B8) {
        Matrix_put(&((ToolActor*)thisx)->unk178);
        Matrix_Position(&D_80A1F32C_jp, &thisx->world.pos);
        ((ToolActor*)thisx)->unk1B8 = 0;
        _texture_z_light_fog_prim_npc(gfxCtx);
        OPEN_POLY_OPA_DISP(gfxCtx);
        Matrix_rotateXYZ(0, -0x4000, 0, MTXMODE_APPLY);
        Matrix_scale(this->shaftScale.x, this->shaftScale.y, this->shaftScale.z, MTXMODE_APPLY);
        gSPLoadGeometryMode(__polyOpa++, G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
        gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        model = &D_80A1F338_jp[toolName];
        gSPDisplayList(__polyOpa++, model->shaft);
        Matrix_translate(RO_FLT_80A1F440_jp[0], 0.0f, 0.0f, MTXMODE_APPLY);
        Matrix_rotateXYZ(0, 0, 0, MTXMODE_APPLY);
        Matrix_scale(this->canopyScale.x, this->canopyScale.y, this->canopyScale.z, MTXMODE_APPLY);
        gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(__polyOpa++, model->canopy);
        CLOSE_POLY_OPA_DISP(gfxCtx);
    }
}

const f32 RO_FLT_80A1F440_jp[] = { 4500.0f, 0.0f, 0.0f, 0.0f };
