#include "ac_train1.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

#include "overlays/actors/ovl_Structure/ac_structure.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_lib.h"
#include "m_common_data.h"
#include "m_event.h"
#include "m_field_info.h"
#include "m_collision_bg.h"
#include "m_player_lib.h"
#include "c_keyframe.h"
#include "audio.h"
#include "macros.h"
#include "gfx.h"
#include "m_rcp.h"
#include "libc/math.h"

extern BaseSkeletonR D_60857F0;
extern xyz_t D_80A0D9F4_jp;
extern BaseAnimationR* D_80A0DA00_jp[2];
extern f32 D_FLT_80A0DA08_jp[2];
extern s32 D_80A0DA10_jp[9];
extern f32 D_FLT_80A0DA34_jp[9];
extern s_xyz D_8010F4AC_jp;

void func_80A0D3A4_jp(Actor* actor, u16 id);
f32 func_80A0D444_jp(Actor* actor);
f32 func_80A0D3D4_jp(Actor* actor0, Actor* actor1);
void func_80A0D558_jp(s32 station);
void aTR1_actor_ct(Actor* actor, Game_Play* game_play);
void aTR1_actor_move(Actor* actor, Game_Play* game_play);
void aTR1_actor_dt(Actor* actor, Game_Play* game_play);
void func_80A0D480_jp(Actor* actor);
void func_80A0D5F4_jp(Actor* actor);
void func_80A0D708_jp(Actor* actor, s32 action);
void aTR1_actor_draw(Actor* actor, Game_Play* game_play);

void aTR1_actor_ct(Actor* thisx, Game_Play* game_play);
void aTR1_actor_dt(Actor* thisx, Game_Play* game_play);
void aTR1_actor_move(Actor* thisx, Game_Play* game_play);
void aTR1_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Train1_Profile = {
    /* */ ACTOR_TRAIN1,
    /* */ ACTOR_PART_0,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20000000,
    /* */ 0x580B,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Train1),
    /* */ aTR1_actor_ct,
    /* */ aTR1_actor_dt,
    /* */ aTR1_actor_move,
    /* */ aTR1_actor_draw,
    /* */ NULL,
};
#endif

void aTR1_actor_ct(Actor* actor, Game_Play* game_play) {
    Train1* train1 = (Train1*)actor;

    SegmentBaseAddress[6] = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_TRAIN1) - 0x80000000;
    cKF_SkeletonInfo_R_ct(&train1->keyframe, &D_60857F0, NULL, train1->work_area, train1->morph_area);
    func_80A0D708_jp(actor, 5);
    train1->keyframe_state = cKF_SkeletonInfo_R_play(&train1->keyframe);
    actor->world.rot.y = 0x4000;
    train1->arg0_f = 1.0f;
}

void aTR1_actor_dt(Actor* actor, Game_Play* game_play) {
    Train1* train1 = (Train1*)actor;

    mFI_SetFG_common(0, actor->home.pos, 0);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->objectSegmentTable, 8, STRUCTURE_TYPE_TRAIN1, actor);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->paletteSegmentTable, 9, STRUCTURE_PALETTE_TRAIN1, actor);
    common_data.clip.structureClip->removeInstanceProc(common_data.clip.structureClip->shadowSegmentTable, 8, STRUCTURE_TYPE_TRAIN1, actor);
    cKF_SkeletonInfo_R_dt(&train1->keyframe);
}

void func_80A0D3A4_jp(Actor* actor, u16 id) {
    sAdo_OngenTrgStart(id, &actor->world.pos);
}

f32 func_80A0D3D4_jp(Actor* actor0, Actor* actor1) {
    StructureActor* train0 = (StructureActor*)actor0;
    Train1* train1 = (Train1*)actor1;

    if (IS_ZERO(actor1->speed)) {
        return train0->unk_2CC + 0.8f;
    }
    if (actor1->speed < train0->unk_2CC) {
        return -(actor1->speed - train0->unk_2CC) * 0.5f + train0->unk_2CC;
    }
    return train0->unk_2CC;
}

f32 func_80A0D444_jp(Actor* actor) {
    Train1* train1 = (Train1*)actor;
    f32 speed;

    if (!IS_ZERO(train1->arg1_f)) {
        speed = train1->arg1_f;
    } else {
        speed = -0.23f;
    }
    return speed;
}

void func_80A0D480_jp(Actor* actor) {
    f32 diff;
    f32 tr_back_calc;
    f32 base_x_pos;
    StructureActor* train0 = (StructureActor*)actor->parent;

    tr_back_calc = actor->world.pos.x;
    base_x_pos = train0->unk_2C8 + -125.0f;
    tr_back_calc += actor->speed;
    diff = tr_back_calc - base_x_pos;
    if (tr_back_calc <= base_x_pos) {
        actor->speed = func_80A0D3D4_jp(actor->parent, actor);
        actor->world.pos.x = base_x_pos;
    } else if (diff > 2.0f) {
        actor->speed = func_80A0D444_jp(actor->parent);
        actor->world.pos.x = base_x_pos + 2.0f;
    } else {
        chase_f(&actor->speed, 0.0f, 0.005f);
        actor->world.pos.x = tr_back_calc;
    }
}

void func_80A0D558_jp(s32 station) {
    if (mEv_CheckFirstIntro() == 0) {
        if (station == 5) {
            func_80073C38_jp(D_80A0D9F4_jp, 7);
        } else if (station == 6) {
            func_80073C38_jp(D_80A0D9F4_jp, 0x20);
        }
    }
}

void func_80A0D5F4_jp(Actor* actor) {
    Train1* train1 = (Train1*)actor;
    xyz_t pos;
    s_xyz rot;

    if (train1->arg0 == 1) {
        pos.x = actor->world.pos.x + 60.0f;
        pos.y = actor->world.pos.y + 20.0f;
        pos.z = actor->world.pos.z + 20.0f;
        rot.x = D_8010F4AC_jp.x;
        rot.y = D_8010F4AC_jp.y;
        rot.z = D_8010F4AC_jp.z;
        get_player_actor_withoutCheck((Game_Play*)gamePT)->Set_force_position_angle_proc(gamePT, &pos, &rot, 0x2E);
    } else if (train1->arg1 == 1) {
        pos.x = actor->world.pos.x;
        pos.y = actor->world.pos.y + 16.0f;
        pos.z = actor->world.pos.z + 20.0f;
        get_player_actor_withoutCheck((Game_Play*)gamePT)->Set_force_position_angle_proc(gamePT, &pos, NULL, 0xE);
    }
}

void func_80A0D708_jp(Actor* actor, s32 action) {
    Train1* train1 = (Train1*)actor;
    BaseAnimationR* anime_pt;
    f32 speed;
    f32 end;
    f32 tr_speed;
    s32 seq_no = D_80A0DA10_jp[action];

    anime_pt = D_80A0DA00_jp[seq_no];
    speed = D_FLT_80A0DA34_jp[action];
    end = D_FLT_80A0DA08_jp[seq_no];
    train1->action = action;
    tr_speed = 1.0f;
    if (train1->action == 6 || train1->action == 4) {
        if (mEv_CheckTitleDemo() == 0 && 1.0f != train1->arg0_f) {
            func_80A0D3A4_jp((Actor*)train1, 43);
        } else {
            tr_speed = end;
        }
    }
    cKF_SkeletonInfo_R_init(&train1->keyframe, train1->keyframe.skeleton, anime_pt, 1.0f, end, tr_speed, speed, 0.0f, 0, NULL);
    func_80A0D558_jp(action);
}

void aTR1_actor_move(Actor* actor, Game_Play* game_play) {
    Train1* train1 = (Train1*)actor;
    StructureActor* train0 = (StructureActor*)actor->parent;

    SegmentBaseAddress[6] = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_TRAIN1) - 0x80000000;
    train1->keyframe_state = cKF_SkeletonInfo_R_play(&train1->keyframe);
    if (mEv_CheckTitleDemo() <= 0) {
        func_80A0D480_jp(actor);
    }
    func_80A0D5F4_jp(actor);
    if (train0->unk_2B4 != train1->action) {
        func_80A0D708_jp(actor, train0->unk_2B4);
    }
    train1->arg0_f = 0.0f;
}

void aTR1_actor_draw(Actor* actor, Game_Play* game_play) {
    s32 object = common_data.clip.structureClip->getObjectSegment(STRUCTURE_TYPE_TRAIN1);
    u16* pal = common_data.clip.structureClip->getPalSegment(STRUCTURE_PALETTE_TRAIN1);
    Train1* train1 = (Train1*)actor;
    GraphicsContext* graph = game_play->state.gfxCtx;
    SkeletonInfoR* keyf;
    Mtx* mtx;

    keyf = &train1->keyframe;
    mtx = GRAPH_ALLOC_NO_ALIGN(graph, keyf->skeleton->unk01 * sizeof(Mtx));
    if (mtx != NULL) {
        _texture_z_light_fog_prim_npc(graph);
        OPEN_POLY_OPA_DISP(graph);
        SegmentBaseAddress[6] = object - 0x80000000;
        gSPSegment(__polyOpa++, 6, object);
        gSPSegment(__polyOpa++, 8, pal);
        CLOSE_POLY_OPA_DISP(graph);
        cKF_Si3_draw_R_SV(game_play, keyf, mtx, NULL, NULL, train1);
    }
}
