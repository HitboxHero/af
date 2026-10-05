#include "ac_t_npc_sao.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "libc64/qrand.h"
#include "objects/tol_umb_25/tol_umb_25.h"
#include "objects/tol_umb_23/tol_umb_23.h"
#include "sys_matrix.h"
#include "m_rcp.h"

void aTNS_actor_ct(Actor* thisx, Game_Play* game_play);
void aTNS_actor_move(Actor* thisx, Game_Play* game_play);
void aTNS_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile T_NpcSao_Profile = {
    /* */ ACTOR_T_NPC_SAO,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ OBJECT_370,
    /* */ sizeof(T_NpcSao),
    /* */ aTNS_actor_ct,
    /* */ (void*)none_proc1,
    /* */ aTNS_actor_move,
    /* */ aTNS_actor_draw,
    /* */ NULL,
};
#endif

void aTNS_actor_ct(Actor* thisx, UNUSED Game_Play* game_play) {
    extern void func_80A20FE4_jp(Actor* thisx, u8 action);

    func_80A20FE4_jp(thisx, 0);
}

void func_80A20FC4_jp(Actor* thisx) {
    Actor_delete(thisx);
}

void func_80A20FE4_jp(Actor* thisx, u8 action) {
    extern T_NpcSaoActionFunc D_80A212D4_jp[];
    T_NpcSao* this = (T_NpcSao*)thisx;

    this->process = D_80A212D4_jp[action];
    this->action = action;
}

void aTNS_actor_move(Actor* thisx, Game_Play* game_play) {
    T_NpcSao* this = (T_NpcSao*)thisx;
    Actor* parent;
    s16 parentRotation;
    s16 rotation;
    xyz_t* pos;

    if (this->toolActor.unk1BC != this->action) {
        func_80A20FE4_jp(thisx, this->toolActor.unk1BC);
    }
    this->process(thisx);
    parent = thisx->parent;
    parentRotation = parent->shape.rot.y;
    rotation = this->rotationY;
    rotation += (s32)(fqrand() * 6.0f + 2.0f) * 256;
    pos = &this->bobberPos;
    pos->x = sin_s(parentRotation) * 100.0f + parent->world.pos.x;
    pos->y = sin_s(rotation) * 1.5f + (parent->world.pos.y + -20.0f);
    pos->z = cos_s(parentRotation) * 100.0f + parent->world.pos.z;
    this->rotationY = rotation;
}

void aTNS_actor_draw(Actor* thisx, Game_Play* game_play) {
    extern xyz_t D_80A212E8_jp;
    extern const f32 RO_FLT_80A21300_jp[];
    extern const f32 RO_FLT_80A21304_jp[];
    T_NpcSao* this = (T_NpcSao*)thisx;
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    xyz_t* pos = &this->bobberPos;

    if (this->toolActor.unk1B8 == 1) {
        Matrix_put(&this->toolActor.unk178);
        Matrix_Position(&D_80A212E8_jp, &thisx->world.pos);
        this->toolActor.unk1B8 = 0;
    } else {
        Matrix_translate(thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, MTXMODE_NEW);
        Matrix_scale(RO_FLT_80A21300_jp[0], RO_FLT_80A21300_jp[0], RO_FLT_80A21300_jp[0], MTXMODE_APPLY);
    }

    _texture_z_light_fog_prim_npc(gfxCtx);
    OPEN_POLY_OPA_DISP(gfxCtx);
    gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    // Preserve the original segmented symbols for the rod and bobber display lists.
    gSPDisplayList(__polyOpa++, e_umb25_model);
    Matrix_translate(pos->x, pos->y, pos->z, MTXMODE_NEW);
    Matrix_scale(RO_FLT_80A21304_jp[0], RO_FLT_80A21304_jp[0], RO_FLT_80A21304_jp[0], MTXMODE_APPLY);
    gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(__polyOpa++, tol_umb_23_kasa_tex_txt);
    CLOSE_POLY_OPA_DISP(gfxCtx);
}

// Arrays keep these separate named constants in rodata with the original relocations.
const f32 RO_FLT_80A21300_jp[] = { 0.01f };
const f32 RO_FLT_80A21304_jp[] = { 0.01f };
