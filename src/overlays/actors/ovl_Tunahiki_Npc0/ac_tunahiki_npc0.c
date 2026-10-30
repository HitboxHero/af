#include "ac_tunahiki_npc0.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

#include "overlays/actors/ovl_Tools/ac_tools.h"
#include "overlays/actors/ovl_Tunahiki_Control/ac_tunahiki_control.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "m_event.h"
#include "m_npc.h"
#include "unknown_structs.h"
#include "libc64/qrand.h"

typedef struct TunahikiNpc0TalkData {
    s32 msg_no;
    u8 turn;
    u8 camera;
} TunahikiNpc0TalkData;

typedef struct TunahikiNpc0ThinkData {
    u8 think_proc_idx;
    u8 think_init_idx;
    u8 talk_request_idx;
    u8 talk_idx;
    u8 think_idx_after_talk;
} TunahikiNpc0ThinkData;

extern struct_809AEFA4 D_80A92394_jp;
extern s32 D_80A923B0_jp[];
extern TunahikiNpc0TalkData D_80A923C8_jp[];
extern TunahikiNpc0ThinkData D_80A923D0_jp[];
extern ActorFunc D_80A923DC_jp[];
extern ActorFunc D_80A923E4_jp[];
extern ActorFunc D_80A923EC_jp[];

void aTNN0_actor_init(Actor* actorx, Game_Play* game_play);
void func_80A92338_jp(Actor* actorx, Game_Play* game_play);
void func_80A920C4_jp(Actor* actorx, Game_Play* game_play);
void func_80A92088_jp(Actor* actorx, Game_Play* game_play);
s32 func_80A91E98_jp(Actor* actorx, Game_Play* game_play);
void func_80A92244_jp(Actor* actorx, Game_Play* game_play);
void func_80A91D6C_jp(Actor* actorx, Game_Play* game_play);
void func_80A921FC_jp(Actor* actorx, Game_Play* game_play, s32 type);
void func_80A922F0_jp(Actor* actorx, Game_Play* game_play, s32 type);
void func_80A91E4C_jp(Actor* actorx, Game_Play* game_play);
void func_80A920FC_jp(Actor* actorx, Game_Play* game_play);
void func_80A91D08_jp(Actor* actorx, Game_Play* game_play);
void func_80A92284_jp(Actor* actorx, Game_Play* game_play);
void aTNN0_actor_dt(Actor* actorx, Game_Play* game_play);
s32 func_80A91ED8_jp(Actor* actorx, Game_Play* game_play);
void func_80A91DB4_jp(Actor* actorx);
s32 func_80A91C6C_jp(Tunahiki_Npc0* actor, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z);
void func_80A9215C_jp(Actor* actorx, Game_Play* game_play, u8 think_idx);
void aTNN0_actor_ct(Actor* actorx, Game_Play* game_play);
void func_80A91F54_jp(Actor* actorx, Game_Play* game_play);

void aTNN0_actor_save(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Tunahiki_Npc0_Profile = {
    /* */ ACTOR_TUNAHIKI_NPC0,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0xD05F,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Tunahiki_Npc0),
    /* */ aTNN0_actor_ct,
    /* */ aTNN0_actor_dt,
    /* */ aTNN0_actor_init,
    /* */ (void*)none_proc1,
    /* */ aTNN0_actor_save,
};
#endif

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0/aTNN0_actor_ct.s")

void aTNN0_actor_save(Actor* thisx, Game_Play* game_play UNUSED) {
    mNpc_RenewalSetNpc(thisx);
}

void aTNN0_actor_dt(Actor* actorx, Game_Play* game_play) {
    TunahikiControlSave* tunahiki = (TunahikiControlSave*)mEv_get_save_area(9, 9);
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;

    if (tunahiki != NULL) {
        tunahiki->flags = 0;
        tunahiki->npcState = 2;
    }
    if (actor->rope_p != NULL) {
        Actor_delete(actor->rope_p);
    }
    common_data.clip.unk_040->unk_C4(actorx, game_play);
}

void aTNN0_actor_init(Actor* actorx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(actorx, game_play);
}

s32 func_80A91C6C_jp(Tunahiki_Npc0* actor, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z) {
    s32 res = 0;

    if (prio >= actor->npc_class.act_priority) {
        u16 args[6];

        bzero(args, sizeof(args));
        args[0] = obj;
        args[2] = move_x;
        args[3] = move_z;
        actor->npc_class.act_priority = prio;
        actor->npc_class.act_idx = idx;
        actor->npc_class.act_type = type;
        mem_copy((u8*)actor->npc_class.act_args, (u8*)args, sizeof(args));
        res = 1;
    }
    return res;
}

void func_80A91D08_jp(Actor* actorx, Game_Play* game_play) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;

    if (actor->npc_class.right_hand_item_actor_p == NULL) {
        ToolActor* flag = common_data.clip.toolClip->aTOL_birth_proc(TOOL_FLAG, 3, (ToolActor*)actorx, game_play, -1, NULL);

        if (flag != NULL) {
            actor->npc_class.right_hand_item_actor_p = (Actor*)flag;
        }
    }
}

void func_80A91D6C_jp(Actor* actorx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_D0(actorx, game_play);
    func_80A91D08_jp(actorx, game_play);
}

void func_80A91DB4_jp(Actor* actorx) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;
    TunahikiNpc0TalkData* data_p = &D_80A923C8_jp[actor->talk_idx];

    mDemo_Set_msg_num(actor->base_msg + (s32)(fqrand() * 3.0f) + data_p->msg_no);
    mDemo_Set_talk_turn(data_p->turn);
    mDemo_Set_camera(data_p->camera);
    actor->talk_proc = (ActorFunc)none_proc1;
}

void func_80A91E4C_jp(Actor* actorx, Game_Play* game_play) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;

    if (!actor->change_flag) {
        mDemo_Request(DEMO_TYPE_TALK, actorx, func_80A91DB4_jp);
    } else {
        actor->change_flag = 0;
    }
}

s32 func_80A91E98_jp(Actor* actorx, Game_Play* game_play) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;

    actor->npc_class.talk_request_proc = (ActorFunc)none_proc1;
    mDemo_Set_ListenAble();
    mDemo_Start(actorx);
    return 1;
}

s32 func_80A91ED8_jp(Actor* actorx, Game_Play* game_play) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;
    Game_Play* play = game_play;
    s32 ret = 0;

    actor->talk_proc(actorx, play);
    if (!mDemo_Check(DEMO_TYPE_SPEAK, actorx) && !mDemo_Check(DEMO_TYPE_TALK, actorx)) {
        func_80A9215C_jp(actorx, play, actor->next_think_idx);
        ret = 1;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0/func_80A91F54_jp.s")

void func_80A92088_jp(Actor* actorx, Game_Play* game_play) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;

    if (actor->npc_class.action_step == 0xFF) {
        actor->npc_class.demo_flg = 0x14;
    }
    actor->think_proc(actorx, game_play);
}

void func_80A920C4_jp(Actor* actorx, Game_Play* game_play) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;

    actorx->colStatus.mass = 0xFF;
    actor->npc_class.hide_request = 0;
    func_80A9215C_jp(actorx, game_play, 1);
    actor->npc_class.demo_flg = 0x14;
}

void func_80A920FC_jp(Actor* actorx, Game_Play* game_play) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;

    // Clip +0x104 points to func_809749D0_jp: three arguments, no game pointer.
    ((void (*)(Actor*, s32, s32))common_data.clip.unk_040->unk_104)(actorx, 0x70, 0);
    actor->npc_class.action_idx = 0;
    func_80A91C6C_jp(actor, 4, 0, 0, 0, 0, 0);
}

void func_80A9215C_jp(Actor* actorx, Game_Play* game_play, u8 think_idx) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;
    TunahikiNpc0ThinkData* dt;

    dt = &D_80A923D0_jp[think_idx];
    actor->think_idx = think_idx;
    actor->think_proc = D_80A923DC_jp[dt->think_proc_idx];
    actor->npc_class.talk_request_proc = D_80A923EC_jp[dt->talk_request_idx];
    actor->talk_idx = dt->talk_idx;
    actor->next_think_idx = dt->think_idx_after_talk;
    D_80A923E4_jp[dt->think_init_idx](actorx, game_play);
    actor->change_flag = 1;
}

void func_80A921FC_jp(Actor* actorx, Game_Play* game_play, s32 type) {
    switch (type) {
        case 0:
            func_80A920C4_jp(actorx, game_play);
            break;
        case 1:
            func_80A92088_jp(actorx, game_play);
            break;
    }
}

void func_80A92244_jp(Actor* actorx, Game_Play* game_play) {
    Tunahiki_Npc0* actor = (Tunahiki_Npc0*)actorx;

    actor->npc_class.think_proc = func_80A921FC_jp;
    common_data.clip.unk_040->unk_110(actorx, game_play, 8, 0);
}

void func_80A92284_jp(Actor* actorx, Game_Play* game_play) {
    if (!common_data.clip.unk_040->unk_110(actorx, game_play, -1, 1)) {
        common_data.clip.unk_040->unk_110(actorx, game_play, -1, 2);
    }
}

void func_80A922F0_jp(Actor* actorx, Game_Play* game_play, s32 type) {
    switch (type) {
        case 0:
            func_80A92244_jp(actorx, game_play);
            break;
        case 1:
            func_80A92284_jp(actorx, game_play);
            break;
    }
}

void func_80A92338_jp(Actor* actorx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_E4(actorx, game_play);
}
