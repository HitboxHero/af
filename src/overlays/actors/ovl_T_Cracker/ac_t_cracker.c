#include "ac_t_cracker.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "sys_matrix.h"
#include "m_rcp.h"

void aTCR_actor_ct(Actor* thisx, Game_Play* game_play);
void aTCR_actor_move(Actor* thisx, Game_Play* game_play);
void aTCR_actor_draw(Actor* thisx, Game_Play* game_play);
void func_80A20154_jp(Actor* thisx, s32 action);
void func_80A2021C_jp(Actor* thisx, s32 action);

#if 0
ActorProfile T_Cracker_Profile = {
    /* */ ACTOR_T_CRACKER,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ OBJECT_395,
    /* */ sizeof(T_Cracker),
    /* */ aTCR_actor_ct,
    /* */ (void*)none_proc1,
    /* */ aTCR_actor_move,
    /* */ aTCR_actor_draw,
    /* */ NULL,
};
#endif

void aTCR_actor_ct(Actor* thisx, Game_Play* game_play) {
    func_80A2021C_jp(thisx, 0);
}

void func_80A20154_jp(Actor* thisx, s32 action) {
    extern f32 D_80A203B4_jp[2];
    xyz_t* scale = &thisx->scale;
    f32 value = scale->x;

    chase_f(&value, D_80A203B4_jp[action], 0.1f);
    scale->x = value;
    scale->y = value;
    scale->z = value;
}

void func_80A201BC_jp(Actor* thisx) {
    func_80A20154_jp(thisx, 0);
}

void func_80A201DC_jp(Actor* thisx) {
    func_80A20154_jp(thisx, 1);
}

void func_80A201FC_jp(Actor* thisx) {
    Actor_delete(thisx);
}

void func_80A2021C_jp(Actor* thisx, s32 action) {
    extern T_CrackerActionFunc D_80A203BC_jp[5];
    extern f32 D_FLT_80A203D0_jp[5];
    T_Cracker* this = (T_Cracker*)thisx;
    f32 scale;

    this->process = D_80A203BC_jp[action];
    this->action = action;
    scale = D_FLT_80A203D0_jp[action];
    thisx->scale.x = scale;
    thisx->scale.y = scale;
    thisx->scale.z = scale;
}

void aTCR_actor_move(Actor* thisx, Game_Play* game_play) {
    T_Cracker* this = (T_Cracker*)thisx;

    if (this->toolActor.unk1BC != this->action) {
        func_80A2021C_jp(thisx, this->toolActor.unk1BC);
    }
    this->process(thisx);
}

void aTCR_actor_draw(Actor* thisx, Game_Play* game_play) {
    extern xyz_t D_80A203E4_jp;
    extern const f32 RO_FLT_80A203F0_jp[];
    extern Gfx tol_cracker_1T_model[];
    T_Cracker* this = (T_Cracker*)thisx;
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;

    if (this->toolActor.unk1B8 == 1) {
        Matrix_put(&this->toolActor.unk178);
        Matrix_Position(&D_80A203E4_jp, &thisx->world.pos);
        this->toolActor.unk1B8 = 0;
    } else {
        Matrix_translate(thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, MTXMODE_NEW);
        Matrix_scale(RO_FLT_80A203F0_jp[0], RO_FLT_80A203F0_jp[0], RO_FLT_80A203F0_jp[0], MTXMODE_APPLY);
    }
    Matrix_scale(thisx->scale.x, thisx->scale.y, thisx->scale.z, MTXMODE_APPLY);
    _texture_z_light_fog_prim_npc(gfxCtx);
    OPEN_POLY_OPA_DISP(gfxCtx);
    gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(__polyOpa++, tol_cracker_1T_model);
    CLOSE_POLY_OPA_DISP(gfxCtx);
}

const f32 RO_FLT_80A203F0_jp[] = { 0.01f, 0.0f, 0.0f, 0.0f };
