#include "ac_ev_dokutu.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "unknown_structs.h"

void aEVD_actor_ct(Actor* thisx, Game_Play* game_play);
void aEVD_actor_dt(Actor* thisx, Game_Play* game_play);
void aEVD_actor_init(Actor* thisx, Game_Play* game_play);
void aEVD_actor_save(Actor* thisx, Game_Play* game_play);

s32 func_80AAEB90_jp(Actor* actorx, s32 idx);
void func_80AAEB64_jp(Actor* actorx, Game_Play* play);
void func_80AAEE04_jp(Actor* actorx, Game_Play* play);
void func_80AAF084_jp(Actor* actorx, Game_Play* play);
void func_80AAEE30_jp(Actor* actorx, Game_Play* play);
s32 func_80AAED08_jp(Actor* actorx, Game_Play* play);
void func_80AAEDC4_jp(Actor* actorx, Game_Play* play);
void func_80AAEE68_jp(Actor* actorx, Game_Play* play);
void func_80AAEF90_jp(Actor* actorx, Game_Play* play);
void func_80AAEF48_jp(Actor* actorx, Game_Play* play, s32 think_proc_idx);
void func_80AAF03C_jp(Actor* actorx, Game_Play* play, s32 sched_idx);
void func_80AAEC10_jp(Actor* actorx, Game_Play* play);
void func_80AAECBC_jp(Actor* actorx, Game_Play* play);
void func_80AAEBB0_jp(Actor* actorx);
void func_80AAEC5C_jp(Actor* actorx);
void func_80AAEFD0_jp(Actor* actorx, Game_Play* play);
s32 func_80AAED48_jp(Actor* actorx, Game_Play* play);
s32 func_80AAEAC8_jp(Ev_Dokutu* actorx, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z);
void func_80AAEEA8_jp(Actor* actorx, Game_Play* play, u8 idx);
extern struct struct_809AEFA4 D_80AAF0D4_jp;
extern ActorFunc D_80AAF0F0_jp[];
extern EvDokutuTalkData D_80AAF0F4_jp[];
extern EvDokutuTalkData D_80AAF0FC_jp[];
extern EvDokutuStateData D_80AAF104_jp[];
extern ActorFunc D_80AAF114_jp[];
extern ActorFunc D_80AAF118_jp[];
extern ActorFunc D_80AAF124_jp[];

#if 0
ActorProfile Ev_Dokutu_Profile = {
    /* */ ACTOR_EV_DOKUTU,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0xD06C,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Ev_Dokutu),
    /* */ aEVD_actor_ct,
    /* */ aEVD_actor_dt,
    /* */ aEVD_actor_init,
    /* */ (void*)none_proc1,
    /* */ aEVD_actor_save,
};
#endif

void aEVD_actor_ct(Actor* actorx, Game_Play* play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    if (common_data.clip.unk_040->unk_BC(actorx, play) == 1) {
        actor->schedule_proc = func_80AAF03C_jp;
        common_data.clip.unk_040->unk_C0(actorx, play, &D_80AAF0D4_jp);
        actor->umbrella_disabled_flag = 1;
        actor->palActorIgnoreTimer = -1;
        actor->unk_94A = 0;
    }
}

void aEVD_actor_save(Actor* thisx, Game_Play* game_play UNUSED) {
    mNpc_RenewalSetNpc(thisx);
}

void aEVD_actor_dt(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C4(thisx, game_play);
}

void aEVD_actor_init(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(thisx, game_play);
}

s32 func_80AAEAC8_jp(Ev_Dokutu* actorx, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z) {
    s32 res = 0;

    if (prio >= actorx->request.act_priority) {
        u16 args[6];

        bzero(args, sizeof(args));
        args[0] = obj;
        args[2] = move_x;
        args[3] = move_z;
        actorx->request.act_priority = prio;
        actorx->request.act_idx = idx;
        actorx->request.act_type = type;
        mem_copy((u8*)actorx->request.act_args, (u8*)args, sizeof(args));
        res = 1;
    }
    return res;
}

void func_80AAEB64_jp(Actor* actorx, Game_Play* play) {
    common_data.clip.unk_040->unk_D0(actorx, play);
}

s32 func_80AAEB90_jp(Actor* actorx, s32 idx) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    actor->unk_93C = D_80AAF0F0_jp[idx];
    return 1;
}

void func_80AAEBB0_jp(Actor* actorx) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;
    EvDokutuTalkData* data = &D_80AAF0F4_jp[actor->unk_949];

    mDemo_Set_msg_num(data->msg_no);
    mDemo_Set_talk_turn(data->turn);
    mDemo_Set_camera(data->camera);
    func_80AAEB90_jp(actorx, data->unk_04);
}

void func_80AAEC10_jp(Actor* actorx, Game_Play* play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    if (actor->unk_94A == 0) {
        mDemo_Request(DEMO_TYPE_SPEAK, actorx, func_80AAEBB0_jp);
    } else {
        actor->unk_94A = 0;
    }
}

void func_80AAEC5C_jp(Actor* actorx) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;
    EvDokutuTalkData* data = &D_80AAF0FC_jp[actor->unk_949];

    mDemo_Set_msg_num(data->msg_no);
    mDemo_Set_talk_turn(data->turn);
    mDemo_Set_camera(data->camera);
    func_80AAEB90_jp(actorx, data->unk_04);
}

void func_80AAECBC_jp(Actor* actorx, Game_Play* play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    if (actor->unk_94A == 0) {
        mDemo_Request(DEMO_TYPE_TALK, actorx, func_80AAEC5C_jp);
    } else {
        actor->unk_94A = 0;
    }
}

s32 func_80AAED08_jp(Actor* actorx, Game_Play* play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    actor->talk_request_proc = (ActorFunc)none_proc1;
    mDemo_Set_ListenAble();
    mDemo_Start(actorx);
    return 1;
}

s32 func_80AAED48_jp(Actor* actorx, Game_Play* game_play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;
    Game_Play* play = game_play;
    s32 res = 0;

    actor->unk_93C(actorx, play);
    if (mDemo_Check(DEMO_TYPE_SPEAK, actorx) == 0 && mDemo_Check(DEMO_TYPE_TALK, actorx) == 0) {
        func_80AAEEA8_jp(actorx, play, actor->unk_947);
        res = 1;
    }
    return res;
}

void func_80AAEDC4_jp(Actor* actorx, Game_Play* play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    if (actor->action_step == 0xFF || actor->action_idx == 0) {
        actor->unk_938(actorx, play);
    }
}

void func_80AAEE04_jp(Actor* actorx, Game_Play* play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    actorx->colStatus.mass = MASS_HEAVY;
    actor->hide_request = 0;
    func_80AAEEA8_jp(actorx, play, 0);
}

void func_80AAEE30_jp(Actor* actorx, Game_Play* play) {
    func_80AAEAC8_jp((Ev_Dokutu*)actorx, 4, 0, 0, 0, 0, 0);
}

void func_80AAEE68_jp(Actor* actorx, Game_Play* play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    func_80AAEAC8_jp(actor, 4, 2, 3, 0, actor->unk_942, actor->unk_944);
}

void func_80AAEEA8_jp(Actor* actorx, Game_Play* play, u8 idx) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;
    EvDokutuStateData* data = &D_80AAF104_jp[idx];

    actor->unk_946 = idx;
    actor->unk_938 = D_80AAF114_jp[data->unk_00];
    actor->talk_request_proc = D_80AAF124_jp[data->unk_02];
    actor->unk_949 = data->unk_03;
    actor->unk_947 = data->unk_04;
    D_80AAF118_jp[data->unk_01](actorx, play);
    actor->unk_94A = 1;
}

void func_80AAEF48_jp(Actor* actorx, Game_Play* play, s32 think_proc_idx) {
    switch (think_proc_idx) {
        case 0:
            func_80AAEE04_jp(actorx, play);
            break;
        case 1:
            func_80AAEDC4_jp(actorx, play);
            break;
    }
}

void func_80AAEF90_jp(Actor* actorx, Game_Play* play) {
    Ev_Dokutu* actor = (Ev_Dokutu*)actorx;

    actor->think_proc = func_80AAEF48_jp;
    common_data.clip.unk_040->unk_110(actorx, play, 8, 0);
}

void func_80AAEFD0_jp(Actor* actorx, Game_Play* play) {
    if (common_data.clip.unk_040->unk_110(actorx, play, -1, 1) == 0) {
        common_data.clip.unk_040->unk_110(actorx, play, -1, 2);
    }
}

void func_80AAF03C_jp(Actor* actorx, Game_Play* play, s32 sched_idx) {
    switch (sched_idx) {
        case 0:
            func_80AAEF90_jp(actorx, play);
            break;
        case 1:
            func_80AAEFD0_jp(actorx, play);
            break;
    }
}

void func_80AAF084_jp(Actor* actorx, Game_Play* play) {
    common_data.clip.unk_040->unk_E4(actorx, play);
}
