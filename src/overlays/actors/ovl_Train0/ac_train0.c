#include "ac_train0.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

#include "overlays/actors/ovl_Structure/ac_structure.h"
#include "m_lib.h"
#include "m_common_data.h"
#include "m_event.h"
#include "m_field_info.h"
#include "c_keyframe.h"
#include "gfx.h"
#include "macros.h"
#include "m_rcp.h"
#include "sys_matrix.h"
#include "libc/math.h"

extern BaseSkeletonR D_6083374;
extern BaseAnimationR D_60834A4;
extern Gfx D_60832E8[];
extern f32 D_FLT_80A0D184_jp[2];
extern s16 D_80A0D18C_jp[2];

f32 func_80A0CB84_jp(Actor* actor);
f32 func_80A0CB14_jp(Actor* actor);
void func_80A0CD20_jp(Actor* actor);
void func_80A0CAA0_jp(Actor* actor, Game_Play* game_play);
void func_80A0CC90_jp(Train0* train0);
void func_80A0CD8C_jp(Actor* actor, Game_Play* game_play);
void func_80A0C7A4_jp(Actor* actor, Game_Play* game_play);
void func_80A0CBC0_jp(Actor* actor);
void func_805bfc28(Actor* actor, Game_Play* game_play);
void func_805bfcdc(Actor* actor, Game_Play* game_play);
void func_805c03ec(Actor* actor, Game_Play* game_play);
void func_80A0C990_jp(Actor* actor, Game_Play* game_play, s32 x_idx);
void func_80A0C874_jp(Actor* actor, Game_Play* game_play);
void func_805c04e0(Actor* actor, Game_Play* game_play);

void func_805bfc28(Actor* thisx, Game_Play* game_play);
void func_805bfcdc(Actor* thisx, Game_Play* game_play);
void func_805c03ec(Actor* thisx, Game_Play* game_play);
void func_805c04e0(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Train0_Profile = {
    /* */ ACTOR_TRAIN0,
    /* */ ACTOR_PART_0,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20000000,
    /* */ 0x580A,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Train0),
    /* */ func_805bfc28,
    /* */ func_805bfcdc,
    /* */ func_805c03ec,
    /* */ func_805c04e0,
    /* */ NULL,
};
#endif

void func_805bfc28(Actor* actor, Game_Play* game_play) {
    Train0* train0 = (Train0*)actor;

    SegmentBaseAddress[6] = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_TRAIN0) - 0x80000000;
    cKF_SkeletonInfo_R_ct(&train0->keyframe, &D_6083374, NULL, train0->work_area, train0->morph_area);
    cKF_SkeletonInfo_R_init(&train0->keyframe, train0->keyframe.skeleton, &D_60834A4, 1.0f, 25.0f, 1.0f, 1.0f, 0.0f, 1, NULL);
    cKF_SkeletonInfo_R_play(&train0->keyframe);
    actor->world.rot.y = 0x4000;
    train0->action = 5;
    actor->uncullZoneScale = 600.0f;
}

void func_805bfcdc(Actor* actor, Game_Play* game_play) {
    Train0* train0 = (Train0*)actor;

    mFI_SetFG_common(0, actor->home.pos, 0);
    if (train0->arg3 != NULL) {
        Actor_delete(train0->arg3);
        train0->arg3 = NULL;
    }
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable, 8, STRUCTURE_TYPE_TRAIN0, actor);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable, 9, STRUCTURE_PALETTE_TRAIN0, actor);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable, 8, STRUCTURE_TYPE_TRAIN0, actor);
    cKF_SkeletonInfo_R_dt(&train0->keyframe);
    common_data.train_exists_flag = 0;
}

void func_80A0C7A4_jp(Actor* actor, Game_Play* game_play) {
    Train0* train0 = (Train0*)actor;
    Game_Play* play = game_play;
    Actor* ac_p;

    ac_p = train0->arg3;
    if (ac_p == NULL) {
        if (common_data.clip.unk_040->setupActor_proc(play, 0xD067, -1, -1, -1, -1, -1, 0, 0) == 1) {
            train0->arg3 = Actor_info_fgName_search(&play->actorInfo, 0xD067, ACTOR_PART_NPC);
        }
    } else {
        ac_p->world.pos.x = actor->world.pos.x + -40.0f;
        ac_p->world.pos.y = actor->world.pos.y + 47.0f;
        ac_p->world.pos.z = actor->world.pos.z + 20.0f;
    }
}

void func_80A0C874_jp(Actor* actor, Game_Play* game_play) {
    Train0* train0 = (Train0*)actor;
    xyz_t pos;

    if (train0->arg1 <= 0) {
        if (actor->speed >= 1.0f) {
            train0->arg1 = (s32)(12.0f / actor->speed);
        } else {
            train0->arg1 = 12;
        }
        xyz_t_move(&pos, &actor->world.pos);
        pos.x += 36.0f;
        pos.y += 110.0f;
        if (mEv_CheckTitleDemo() == 0) {
            common_data.clip.unk_090->unk_00(0x23, pos, 1, 0, (Game*)game_play, actor->fgName, 0, 0);
        }
    } else {
        train0->arg1--;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Train0/ac_train0/func_80A0C990_jp.s")

void func_80A0CAA0_jp(Actor* actor, Game_Play* game_play) {
    Train0* train0 = (Train0*)actor;

    if (train0->keyframe_state == 1) {
        if (train0->keyframe_saved_keyframe >= 2 && train0->keyframe_saved_keyframe <= 5) {
            func_80A0C990_jp(actor, game_play, 0);
        }
        if (train0->keyframe_saved_keyframe >= 13 && train0->keyframe_saved_keyframe <= 16) {
            func_80A0C990_jp(actor, game_play, 1);
        }
    }
}

f32 func_80A0CB14_jp(Actor* actor) {
    Train0* train0 = (Train0*)actor;

    if (IS_ZERO(train0->arg1_f)) {
        return actor->speed + 0.8f;
    }
    if (train0->arg1_f < actor->speed) {
        return -(train0->arg1_f - actor->speed) * 0.5f + actor->speed;
    }
    return actor->speed;
}

f32 func_80A0CB84_jp(Actor* actor) {
    f32 speed;

    if (!IS_ZERO(actor->speed)) {
        speed = actor->speed;
    } else {
        speed = -0.23f;
    }
    return speed;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Train0/ac_train0/func_80A0CBC0_jp.s")

void func_80A0CC90_jp(Train0* train0) {
    s32 av = 0;
    s32 cur_frame = train0->keyframe.frameControl.currentFrame;

    SegmentBaseAddress[6] = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_TRAIN0) - 0x80000000;
    cKF_SkeletonInfo_R_play(&train0->keyframe);
    if (cur_frame != train0->keyframe_saved_keyframe) {
        train0->keyframe_saved_keyframe = cur_frame;
        av = 1;
    }
    train0->keyframe_state = av;
}

void func_80A0CD20_jp(Actor* actor) {
    Train0* train0 = (Train0*)actor;
    xyz_t pos;

    if (train0->action != common_data.train_action) {
        train0->action = common_data.train_action;
    }
    pos = common_data.train_position;
    actor->world.pos.x = pos.x;
    actor->world.pos.y = pos.y;
    actor->world.pos.z = pos.z;
    actor->speed = common_data.train_speed;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Train0/ac_train0/func_80A0CD8C_jp.s")

void func_805c03ec(Actor* actor, Game_Play* game_play) {
    Train0* train0 = (Train0*)actor;
    Game_Play* play = game_play;
    f32 speed;

    func_80A0CC90_jp(train0);
    func_80A0CD20_jp(actor);
    if (!IS_ZERO(actor->speed)) {
        func_80A0C874_jp(actor, game_play);
        func_80A0CAA0_jp(actor, game_play);
    }
    if (mEv_CheckTitleDemo() == 1) {
        train0->arg0_f = actor->world.pos.x + -125.0f;
    } else {
        func_80A0CBC0_jp(actor);
    }
    func_80A0C7A4_jp(actor, game_play);
    speed = actor->speed / 40.0f * 10.0f;
    if (speed >= 1.0f) {
        speed = 1.0f;
    }
    train0->keyframe.frameControl.speed = speed;
    func_80A0CD8C_jp(actor, game_play);
}

void func_805c04e0(Actor* actor, Game_Play* game_play) {
    s32 object = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_TRAIN0);
    u16* pal = common_data.clip.structureClip->getPalSegment(STRUCTURE_PALETTE_TRAIN0);
    Train0* train0 = (Train0*)actor;
    GraphicsContext* graph = game_play->state.gfxCtx;
    SkeletonInfoR* keyf;
    Mtx* mtx;

    keyf = &train0->keyframe;
    mtx = GRAPH_ALLOC_NO_ALIGN(graph, keyf->skeleton->unk01 * sizeof(Mtx));
    if (mtx != NULL) {
        _texture_z_light_fog_prim_npc(graph);
        Matrix_push();
        Matrix_translate(train0->arg0_f, actor->world.pos.y, actor->world.pos.z, MTXMODE_NEW);
        Matrix_scale(actor->scale.x, actor->scale.y, actor->scale.z, MTXMODE_APPLY);
        OPEN_POLY_OPA_DISP(graph);
        gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(graph), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        SegmentBaseAddress[6] = object - 0x80000000;
        gSPSegment(__polyOpa++, 6, object);
        gSPSegment(__polyOpa++, 8, pal);
        gDPLoadTLUT_pal16(__polyOpa++, 15, pal);
        gSPDisplayList(__polyOpa++, D_60832E8);
        CLOSE_POLY_OPA_DISP(graph);
        Matrix_pull();
        cKF_Si3_draw_R_SV(game_play, keyf, mtx, NULL, NULL, train0);
    }
}
