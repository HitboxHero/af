#include "ac_tamaire_npc0.h"
#include "m_lib.h"
#include "unknown_structs.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "m_npc.h"
#include "m_field_info.h"
#include "audio.h"

void aTMN0_actor_ct(Actor* thisx, Game_Play* game_play);
void aTMN0_actor_dt(Actor* thisx, Game_Play* game_play);
void aTMN0_actor_init(Actor* thisx, Game_Play* game_play);
void aTMN0_actor_save(Actor* thisx, Game_Play* game_play);

void func_80A86850_jp(Actor* thisx, Game_Play* game_play);
void func_80A87068_jp(Actor* thisx, Game_Play* game_play);
s32 func_80A8687C_jp(Tamaire_Npc0* actor, s32 talk_idx);
void func_80A8689C_jp(Actor* thisx);
void func_80A868F4_jp(Actor* thisx);
void func_80A86934_jp(Actor* thisx, Game_Play* game_play);
s32 func_80A86980_jp(Actor* thisx, Game_Play* game_play);
s32 func_80A869C0_jp(Actor* thisx, Game_Play* game_play);
void func_80A86A3C_jp(Tamaire_Npc0* actor);
void func_80A86AD0_jp(Tamaire_Npc0* actor, Game_Play* game_play);
void func_80A86B24_jp(Tamaire_Npc0* actor, Game_Play* game_play);
void func_80A86B70_jp(Tamaire_Npc0* actor, Game_Play* game_play);
void func_80A86C20_jp(Tamaire_Npc0* actor, Game_Play* game_play);
void func_80A86C84_jp(Actor* thisx, Game_Play* game_play);
void func_80A86CEC_jp(Actor* thisx, Game_Play* game_play);
void func_80A86D28_jp(Tamaire_Npc0* actor, Game_Play* game_play);
void func_80A86D60_jp(Tamaire_Npc0* actor, Game_Play* game_play);
void func_80A86DAC_jp(Tamaire_Npc0* actor, Game_Play* game_play);
void func_80A86DF4_jp(Tamaire_Npc0* actor, Game_Play* game_play);
void func_80A86E80_jp(Tamaire_Npc0* actor, Game_Play* game_play, u8 think_idx);
void func_80A86F2C_jp(Actor* thisx, Game_Play* game_play, s32 type);
void func_80A87020_jp(Actor* thisx, Game_Play* game_play, s32 type);
void func_80A86F74_jp(Actor* thisx, Game_Play* game_play);
void func_80A86FB4_jp(Actor* thisx, Game_Play* game_play);
s32 func_80A867B4_jp(Tamaire_Npc0* actor, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z);

// NPC clip +0x104 consumes three arguments; see research/tamaire-npc0.md.
typedef void (*Tamaire_Npc0AnimationInitProc)(Actor*, s32, s32);

typedef struct aTMN0_think_data_c {
    u8 think_proc_idx;
    u8 think_init_idx;
    u8 talk_request_idx;
    u8 talk_idx;
    u8 think_idx_after_talk;
} aTMN0_think_data_c;

extern struct_809AEFA4 D_80A870C4_jp;
extern Tamaire_Npc0ActionFunc D_80A870E0_jp[1];
extern s32 D_80A870E4_jp[6];
extern aTMN0_think_data_c D_80A870FC_jp[9];
extern Tamaire_Npc0ActionFunc D_80A8712C_jp[5];
extern Tamaire_Npc0ActionFunc D_80A87140_jp[5];
extern ActorFunc D_80A87154_jp[3];

#if 0
ActorProfile Tamaire_Npc0_Profile = {
    /* */ ACTOR_TAMAIRE_NPC0,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0xD053,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Tamaire_Npc0),
    /* */ aTMN0_actor_ct,
    /* */ aTMN0_actor_dt,
    /* */ aTMN0_actor_init,
    /* */ (void*)none_proc1,
    /* */ aTMN0_actor_save,
};
#endif

void aTMN0_actor_ct(Actor* thisx, Game_Play* game_play) {
    if (common_data.clip.unk_040->unk_BC(thisx, game_play) == 1) {
        Tamaire_Npc0* actor = (Tamaire_Npc0*)thisx;
        actor->schedule_proc = func_80A87020_jp;
        common_data.clip.unk_040->unk_C0(thisx, game_play, &D_80A870C4_jp);
        actor->palActorIgnoreTimer = -1;
        actor->change_flag = 0;
        actor->check_kind = 0;
        thisx->world.pos.y = mCoBG_GetBgY_OnlyCenter_FromWpos2(thisx->world.pos, 0.0f);
        thisx->velocity.y = 0.0f;
        thisx->gravity = 0.0f;
        thisx->terminalVelocity = 0.0f;
    }
}

void aTMN0_actor_save(Actor* thisx, Game_Play* game_play UNUSED) {
    mNpc_RenewalSetNpc(thisx);
}

void aTMN0_actor_dt(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C4(thisx, game_play);
}

void aTMN0_actor_init(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(thisx, game_play);
}

s32 func_80A867B4_jp(Tamaire_Npc0* actor, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z) {
    s32 res = 0;
    if (prio >= actor->act_priority) {
        u16 args[6];
        bzero(args, sizeof(args));
        args[0] = obj;
        args[2] = move_x;
        args[3] = move_z;
        actor->act_priority = prio;
        actor->act_idx = idx;
        actor->act_type = type;
        mem_copy((u8*)actor->act_args, (u8*)args, sizeof(args));
        res = 1;
    }
    return res;
}

void func_80A86850_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_D0(thisx, game_play);
}

s32 func_80A8687C_jp(Tamaire_Npc0* actor, s32 talk_idx) {
    actor->talk_proc = D_80A870E0_jp[talk_idx];
    return 1;
}

void func_80A8689C_jp(Actor* thisx) {
    s32 msg_no = D_80A870E4_jp[mNpc_GetNpcLooks(thisx)] + (s32)(fqrand() * 3.0f);
    mDemo_Set_msg_num(msg_no);
}

void func_80A868F4_jp(Actor* thisx) {
    Tamaire_Npc0* actor = (Tamaire_Npc0*)thisx;
    func_80A8689C_jp(thisx);
    mDemo_Set_talk_turn(1);
    mDemo_Set_camera(3);
    func_80A8687C_jp(actor, 0);
}

void func_80A86934_jp(Actor* thisx, Game_Play* game_play) {
    Tamaire_Npc0* actor = (Tamaire_Npc0*)thisx;
    if (!actor->change_flag) {
        mDemo_Request(7, thisx, func_80A868F4_jp);
    } else {
        actor->change_flag = 0;
    }
}

s32 func_80A86980_jp(Actor* thisx, Game_Play* game_play) {
    Tamaire_Npc0* actor = (Tamaire_Npc0*)thisx;
    actor->talk_request_proc = (ActorFunc)none_proc1;
    mDemo_Set_ListenAble();
    mDemo_Start(thisx);
    return 1;
}

s32 func_80A869C0_jp(Actor* thisx, Game_Play* game_play) {
    Tamaire_Npc0* actor = (Tamaire_Npc0*)thisx;
    Game_Play* play = game_play;
    s32 ret = 0;
    actor->talk_proc(actor, play);
    if (!mDemo_Check(8, thisx) && !mDemo_Check(7, thisx)) {
        func_80A86E80_jp(actor, play, actor->next_think_idx);
        ret = 1;
    }
    return ret;
}

void func_80A86A3C_jp(Tamaire_Npc0* actor) {
    switch (actor->think_idx) {
        case 1:
            actor->move_pos[0] = actor->yasiro_pos[0] + 80;
            actor->move_pos[1] = actor->yasiro_pos[1] + 160;
            break;
        case 3:
            actor->move_pos[0] = actor->yasiro_pos[0] + 200;
            actor->move_pos[1] = actor->yasiro_pos[1] + 40;
            break;
        case 5:
            actor->move_pos[0] = actor->yasiro_pos[0] - 40;
            actor->move_pos[1] = actor->yasiro_pos[1] + 160;
            break;
        default:
            actor->move_pos[0] = actor->yasiro_pos[0] - 160;
            actor->move_pos[1] = actor->yasiro_pos[1] + 40;
            break;
    }
}

void func_80A86AD0_jp(Tamaire_Npc0* actor, Game_Play* game_play) {
    s16 yasiro_pos[3];
    if (func_8008E8E0_jp(yasiro_pos)) {
        actor->yasiro_pos[0] = yasiro_pos[0];
        actor->yasiro_pos[1] = yasiro_pos[1];
        func_80A86E80_jp(actor, game_play, 1);
    }
}

void func_80A86B24_jp(Tamaire_Npc0* actor, Game_Play* game_play) {
    if (actor->action_idx == 3 && actor->step == 255) {
        func_80A86E80_jp(actor, game_play, ++actor->think_idx);
    }
}

void func_80A86B70_jp(Tamaire_Npc0* actor, Game_Play* game_play) {
    if (actor->action_idx == 1 && actor->step == 255) {
        func_80A86E80_jp(actor, game_play, ++actor->think_idx);
    } else if ((s16)actor->dst_pos_x != actor->move_pos[0] || (s16)actor->dst_pos_z != actor->move_pos[1]) {
        func_80A86E80_jp(actor, game_play, --actor->think_idx);
    }
}

void func_80A86C20_jp(Tamaire_Npc0* actor, Game_Play* game_play) {
    Actor* actorx = &actor->actor;
    if (actor->timer > 0) {
        actor->timer--;
    } else {
        func_80A86E80_jp(actor, game_play, ++actor->think_idx);
    }
    if (actor->animation_id == 0x43) {
        sAdo_OngenPos((s32)actorx, 0x2F, &actorx->world.pos);
    }
}

void func_80A86C84_jp(Actor* thisx, Game_Play* game_play) {
    Tamaire_Npc0* actor = (Tamaire_Npc0*)thisx;
    if (mDemo_Check(7, thisx) == 1) {
        return;
    }
    if (actor->step == 255) {
        actor->demo_flg = 0x17;
    }
    actor->think_proc(actor, game_play);
}

void func_80A86CEC_jp(Actor* thisx, Game_Play* game_play) {
    Tamaire_Npc0* actor = (Tamaire_Npc0*)thisx;
    thisx->colStatus.mass = 254;
    actor->hide_request = 0;
    func_80A86E80_jp(actor, game_play, 0);
    actor->interrupt_flags = 0;
    actor->demo_flg = 0x17;
}

void func_80A86D28_jp(Tamaire_Npc0* actor, Game_Play* game_play) {
    func_80A867B4_jp(actor, 4, 0, 0, 0, 0, 0);
}

void func_80A86D60_jp(Tamaire_Npc0* actor, Game_Play* game_play) {
    func_80A86A3C_jp(actor);
    func_80A867B4_jp(actor, 4, 3, 3, 0, actor->move_pos[0], actor->move_pos[1]);
}

void func_80A86DAC_jp(Tamaire_Npc0* actor, Game_Play* game_play) {
    actor->timer = 350;
    func_80A867B4_jp(actor, 4, 1, 3, 0, actor->move_pos[0], actor->move_pos[1]);
}

void func_80A86DF4_jp(Tamaire_Npc0* actor, Game_Play* game_play) {
    actor->action_idx = 0;
    func_80A86D28_jp(actor, game_play);
    actor->main_animation.frameControl.mode = ANIMATION_REPEAT;
    if (fqrand() < 0.5f) {
        ((Tamaire_Npc0AnimationInitProc)common_data.clip.unk_040->unk_104)(&actor->actor, 0x43, 0);
    } else {
        ((Tamaire_Npc0AnimationInitProc)common_data.clip.unk_040->unk_104)(&actor->actor, 0x42, 0);
    }
}

void func_80A86E80_jp(Tamaire_Npc0* actor, Game_Play* game_play, u8 think_idx) {
    aTMN0_think_data_c* dt;
    if (think_idx > 8) {
        think_idx = 1;
    }
    dt = &D_80A870FC_jp[think_idx];
    actor->think_idx = think_idx;
    actor->think_proc = D_80A8712C_jp[dt->think_proc_idx];
    actor->talk_request_proc = D_80A87154_jp[dt->talk_request_idx];
    actor->talk_idx = dt->talk_idx;
    actor->next_think_idx = dt->think_idx_after_talk;
    D_80A87140_jp[dt->think_init_idx](actor, game_play);
    actor->change_flag = 1;
}

void func_80A86F2C_jp(Actor* thisx, Game_Play* game_play, s32 type) {
    switch (type) {
        case 0:
            func_80A86CEC_jp(thisx, game_play);
            break;
        case 1:
            func_80A86C84_jp(thisx, game_play);
            break;
    }
}

void func_80A86F74_jp(Actor* thisx, Game_Play* game_play) {
    Tamaire_Npc0* actor = (Tamaire_Npc0*)thisx;
    actor->npc_think_proc = func_80A86F2C_jp;
    common_data.clip.unk_040->unk_110(thisx, game_play, 8, 0);
}

void func_80A86FB4_jp(Actor* thisx, Game_Play* game_play) {
    if (!common_data.clip.unk_040->unk_110(thisx, game_play, -1, 1)) {
        common_data.clip.unk_040->unk_110(thisx, game_play, -1, 2);
    }
}

void func_80A87020_jp(Actor* thisx, Game_Play* game_play, s32 type) {
    switch (type) {
        case 0:
            func_80A86F74_jp(thisx, game_play);
            break;
        case 1:
            func_80A86FB4_jp(thisx, game_play);
            break;
    }
}

void func_80A87068_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_E4(thisx, game_play);
}
