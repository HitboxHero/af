#include "ac_t_pistol.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "sys_matrix.h"
#include "m_rcp.h"

void aTPT_actor_ct(Actor* thisx, Game_Play* game_play);
void aTPT_actor_move(Actor* thisx, Game_Play* game_play);
void aTPT_actor_draw(Actor* thisx, Game_Play* game_play);
void func_80A20494_jp(Actor* thisx, s32 action);
void func_80A2055C_jp(Actor* thisx, s32 action);

#if 0
ActorProfile T_Pistol_Profile = {
    /* */ ACTOR_T_PISTOL,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ OBJECT_16,
    /* */ sizeof(T_Pistol),
    /* */ aTPT_actor_ct,
    /* */ (void*)none_proc1,
    /* */ aTPT_actor_move,
    /* */ aTPT_actor_draw,
    /* */ NULL,
};
#endif

void aTPT_actor_ct(Actor* thisx, Game_Play* game_play) {
    func_80A2055C_jp(thisx, 0);
}

void func_80A20494_jp(Actor* thisx, s32 action) {
    extern f32 D_80A206F4_jp[2];
    xyz_t* scale = &thisx->scale;
    f32 value = scale->x;

    chase_f(&value, D_80A206F4_jp[action], 0.1f);
    scale->x = value;
    scale->y = value;
    scale->z = value;
}

void func_80A204FC_jp(Actor* thisx) {
    func_80A20494_jp(thisx, 0);
}

void func_80A2051C_jp(Actor* thisx) {
    func_80A20494_jp(thisx, 1);
}

void func_80A2053C_jp(Actor* thisx) {
    Actor_delete(thisx);
}

void func_80A2055C_jp(Actor* thisx, s32 action) {
    extern T_PistolActionFunc D_80A206FC_jp[5];
    extern f32 D_FLT_80A20710_jp[5];
    T_Pistol* this = (T_Pistol*)thisx;
    f32 scale;

    this->process = D_80A206FC_jp[action];
    this->action = action;
    scale = D_FLT_80A20710_jp[action];
    thisx->scale.x = scale;
    thisx->scale.y = scale;
    thisx->scale.z = scale;
}

void aTPT_actor_move(Actor* thisx, Game_Play* game_play) {
    T_Pistol* this = (T_Pistol*)thisx;

    if (this->toolActor.unk1BC != this->action) {
        func_80A2055C_jp(thisx, this->toolActor.unk1BC);
    }
    this->process(thisx);
}

void aTPT_actor_draw(Actor* thisx, Game_Play* game_play) {
    extern xyz_t D_80A20724_jp;
    extern const f32 RO_FLT_80A20730_jp[];
    extern Gfx tol_kenjyu_1T_model[];
    T_Pistol* this = (T_Pistol*)thisx;
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;

    if (this->toolActor.unk1B8 == 1) {
        Matrix_put(&this->toolActor.unk178);
        Matrix_Position(&D_80A20724_jp, &thisx->world.pos);
        this->toolActor.unk1B8 = 0;
    } else {
        Matrix_translate(thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, MTXMODE_NEW);
        Matrix_scale(RO_FLT_80A20730_jp[0], RO_FLT_80A20730_jp[0], RO_FLT_80A20730_jp[0], MTXMODE_APPLY);
    }
    Matrix_scale(thisx->scale.x, thisx->scale.y, thisx->scale.z, MTXMODE_APPLY);
    _texture_z_light_fog_prim_npc(gfxCtx);
    OPEN_POLY_OPA_DISP(gfxCtx);
    gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(__polyOpa++, tol_kenjyu_1T_model);
    CLOSE_POLY_OPA_DISP(gfxCtx);
}

const f32 RO_FLT_80A20730_jp[] = { 0.01f, 0.0f, 0.0f, 0.0f };
