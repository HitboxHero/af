#include "ac_ev_miko.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

#include "m_mail.h"
#include "unknown_structs.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "m_event.h"
#include "m_private.h"
#include "m_msg_main.h"
#include "m_choice_main.h"
#include "m_handbill.h"
#include "m_string.h"
#include "libc64/qrand.h"
#include "macros.h"

extern struct_809AEFA4 D_809E6284_jp;
extern s32 D_809E62A0_jp[4];
extern u16 D_809E62B0_jp[4];
extern s32 D_809E62B8_jp[4];
extern u8 D_809E62C8_jp[4];
extern ActorFunc D_809E62CC_jp[4];
extern ActorFunc D_809E62DC_jp[4];
extern char B_809E62F0_jp[10];

void func_809E6234_jp(Actor* actorx, Game_Play* game_play);
s32 func_809E60C4_jp(Actor* actorx, Game_Play* game_play);
void func_809E5FE4_jp(Actor* actorx, Game_Play* game_play, s32 action);
void func_809E6014_jp(Actor* actorx, Game_Play* game_play, s32 action);
void func_809E6048_jp(Actor* actorx);
void aEMK_actor_dt(Actor* actorx, Game_Play* game_play);
void func_809E6084_jp(Actor* actorx, Game_Play* game_play);
void func_809E5FA0_jp(Actor* actorx, Game_Play* game_play);
s32 func_809E597C_jp(void);
void func_809E5B7C_jp(s32 price);
void func_809E61C8_jp(Actor* actorx, Game_Play* game_play);
s32 func_809E58E0_jp(Ev_Miko* miko, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z);
void func_809E5DF0_jp(Actor* actorx, Game_Play* game_play);
s32 func_809E59C4_jp(s32 price);
s32 func_809E60F0_jp(Actor* actorx, Game_Play* game_play);
s32 func_809E5A94_jp(s32 money);
void func_809E5CF8_jp(Actor* actorx, Game_Play* game_play);
void func_809E5EA0_jp(Actor* actorx, Game_Play* game_play);
void aEMK_actor_ct(Actor* actorx, Game_Play* game_play);
void func_809E5BC4_jp(Mail_c* mail, s32 idx);

void aEMK_actor_ct(Actor* thisx, Game_Play* game_play);
void aEMK_actor_dt(Actor* thisx, Game_Play* game_play);
void aEMK_actor_init(Actor* thisx, Game_Play* game_play);
void aEMK_actor_save(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Ev_Miko_Profile = {
    /* */ ACTOR_EV_MIKO,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0xD03D,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Ev_Miko),
    /* */ aEMK_actor_ct,
    /* */ aEMK_actor_dt,
    /* */ aEMK_actor_init,
    /* */ (void*)none_proc1,
    /* */ aEMK_actor_save,
};
#endif

void aEMK_actor_ct(Actor* actorx, Game_Play* game_play) {
    if (common_data.clip.unk_040->unk_BC(actorx, game_play) == 1) {
        Ev_Miko* miko = (Ev_Miko*)actorx;

        common_data.clip.unk_040->unk_C0(actorx, game_play, &D_809E6284_jp);
        miko->npc_class.hide_flg = 0;
        miko->npc_class.palActorIgnoreTimer = -1;
        actorx->colStatus.mass = 0xFF;
        miko->npc_class.collision_check_kind = 0;
        actorx->world.pos.y = mCoBG_GetBgY_OnlyCenter_FromWpos2(actorx->world.pos, 0.0f);
        actorx->velocity.y = 0.0f;
        actorx->gravity = 0.0f;
        actorx->terminalVelocity = 0.0f;
        actorx->unk_144 = 78.0f;
        common_data.clip.unk_040->unk_10C(actorx, actorx->world.pos.x + 10.0f, actorx->world.pos.z + 10.0f);
    }
}

void aEMK_actor_save(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C8(thisx, game_play);
}

void aEMK_actor_dt(Actor* actorx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C4(actorx, game_play);
    func_800814B8_jp(3, actorx);
}

void aEMK_actor_init(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(thisx, game_play);
}

s32 func_809E58E0_jp(Ev_Miko* miko, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z) {
    s32 ret = 0;

    if (prio >= miko->npc_class.act_priority) {
        u16 arg_data[6];

        bzero(arg_data, sizeof(arg_data));
        arg_data[0] = obj;
        arg_data[2] = move_x;
        arg_data[3] = move_z;
        miko->npc_class.act_priority = prio;
        miko->npc_class.act_idx = idx;
        miko->npc_class.act_type = type;
        mem_copy((u8*)miko->npc_class.act_args, (u8*)arg_data, sizeof(arg_data));
        ret = 1;
    }
    return ret;
}

s32 func_809E597C_jp(void) {
    if (common_data.privateInfo != NULL && mMl_chk_mail_free_space(common_data.privateInfo->mail, mPr_INVENTORY_MAIL_COUNT) != -1) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ev_Miko/ac_ev_miko/func_809E59C4_jp.s")

s32 func_809E5A94_jp(s32 money) {
    s32 i;
    s32 num;
    s32 idx;

    for (i = 0; i < 4; i++) {
        num = mPr_GetPossessionItemSumWithCond(common_data.privateInfo, D_809E62B0_jp[i], 0);
        while (num != 0) {
            idx = mPr_GetPossessionItemIdxWithCond(common_data.privateInfo, D_809E62B0_jp[i], 0);
            mPr_SetPossessionItem(common_data.privateInfo, idx, 0, 0);
            money += D_809E62A0_jp[i];
            num--;
            if (money >= 0) {
                return money;
            }
        }
    }
    return 0;
}

void func_809E5B7C_jp(s32 price) {
    s32 money = common_data.privateInfo->inventory.wallet;

    money -= price;

    if (money < 0) {
        money = func_809E5A94_jp(money);
    }
    common_data.privateInfo->inventory.wallet = money;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ev_Miko/ac_ev_miko/func_809E5BC4_jp.s")

void func_809E5CF8_jp(Actor* actorx, Game_Play* game_play) {
    if (func_8009E908_jp(mMsg_Get_base_window_p())) {
        switch (mChoice_Get_ChoseNum(mChoice_Get_base_window_p())) {
            case 0:
                if (!func_809E597C_jp()) {
                    func_8009DBA4_jp(mMsg_Get_base_window_p(), 0x190F);
                    func_809E6014_jp(actorx, game_play, 0);
                } else if (func_809E59C4_jp(50)) {
                    func_809E6014_jp(actorx, game_play, 2);
                } else {
                    func_8009DBA4_jp(mMsg_Get_base_window_p(), 0x190E);
                    func_809E6014_jp(actorx, game_play, 0);
                }
                break;
            case 1:
                func_809E6014_jp(actorx, game_play, 0);
                break;
        }
    }
}

void func_809E5DF0_jp(Actor* actorx, Game_Play* game_play) {
    s32 order = mDemo_Get_OrderValue(4, 9);
    Ev_Miko* miko = (Ev_Miko*)actorx;

    if (func_8009E908_jp(mMsg_Get_base_window_p()) && order == 1) {
        mDemo_Set_OrderValue(4, 9, 0);
        func_8009DBA4_jp(mMsg_Get_base_window_p(), 0x1911 + miko->omikuji);
        func_809E6014_jp(actorx, game_play, 3);
        common_data.privateInfo->destiny.type = D_809E62C8_jp[miko->omikuji];
        func_809E5B7C_jp(50);
    }
}

void func_809E5EA0_jp(Actor* actorx, Game_Play* game_play) {
    s32 order = mDemo_Get_OrderValue(4, 9);
    Mail_c mail;
    s32 idx;

    if (order == 1) {
        mDemo_Set_OrderValue(4, 9, 0);
        mDemo_Set_OrderValue(4, 1, 2);
        mDemo_Set_OrderValue(5, 0, 0x2513);
        mDemo_Set_OrderValue(5, 1, 7);
        mDemo_Set_OrderValue(5, 2, 0);
        func_809E6014_jp(actorx, game_play, 0);
        mMl_clear_mail(&mail);
        func_809E5BC4_jp(&mail, ((Ev_Miko*)actorx)->omikuji);
        if (common_data.privateInfo != NULL) {
            idx = mMl_chk_mail_free_space(common_data.privateInfo->mail, mPr_INVENTORY_MAIL_COUNT);
            if (idx != -1) {
                mail.content.paperType = 25;
                mMl_copy_mail(&common_data.privateInfo->mail[idx], &mail);
            }
        }
    }
}

void func_809E5FA0_jp(Actor* actorx, Game_Play* game_play) {
    Ev_Miko* miko = (Ev_Miko*)actorx;

    miko->omikuji = (s32)(fqrand() * 4.0f);
}

void func_809E5FE4_jp(Actor* actorx, Game_Play* game_play, s32 action) {
    D_809E62CC_jp[action](actorx, game_play);
}

void func_809E6014_jp(Actor* actorx, Game_Play* game_play, s32 action) {
    Ev_Miko* miko = (Ev_Miko*)actorx;

    miko->talk_action = action;
    miko->talk_proc = D_809E62DC_jp[action];
    func_809E5FE4_jp(actorx, game_play, action);
}

void func_809E6048_jp(Actor* actorx) {
    s32 msg_no;
    Ev_Miko* miko = (Ev_Miko*)actorx;

    if (miko->in_front == 1) {
        msg_no = 0x190C;
    } else {
        msg_no = 0x1916;
    }
    mDemo_Set_msg_num(msg_no);
}

void func_809E6084_jp(Actor* actorx, Game_Play* game_play) {
    Ev_Miko* miko = (Ev_Miko*)actorx;

    if (miko->npc_class.action_idx == 0) {
        mDemo_Request(DEMO_TYPE_TALK, actorx, func_809E6048_jp);
    }
}

s32 func_809E60C4_jp(Actor* actorx, Game_Play* game_play) {
    Ev_Miko* miko = (Ev_Miko*)actorx;
    Game_Play* play = game_play;

    func_809E6014_jp(actorx, play, 1);
    mDemo_Set_ListenAble();
    return 1;
}

s32 func_809E60F0_jp(Actor* actorx, Game_Play* game_play) {
    Ev_Miko* miko = (Ev_Miko*)actorx;
    Game_Play* play = game_play;
    s32 ret = 0;

    miko->talk_proc(actorx, play);
    if (!mDemo_Check(DEMO_TYPE_TALK, actorx)) {
        ret = 1;
        common_data.clip.unk_040->unk_10C(actorx, actorx->world.pos.x + 10.0f, actorx->world.pos.z + 10.0f);
        func_809E58E0_jp(miko, 4, 3, 3, 0, actorx->world.pos.x + 10.0f, actorx->world.pos.z + 10.0f);
    }
    return ret;
}

void func_809E61C8_jp(Actor* actorx, Game_Play* game_play) {
    Ev_Miko* miko = (Ev_Miko*)actorx;

    if (ABS((s16)(actorx->yawTowardsPlayer - actorx->shape.rot.y)) < 0x1800) {
        miko->in_front = 1;
    } else {
        miko->in_front = 0;
    }
    common_data.clip.unk_040->unk_D0(actorx, game_play);
}

void func_809E6234_jp(Actor* actorx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_E4(actorx, game_play);
}
