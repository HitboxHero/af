#include "ac_ev_gypsy.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "m_event.h"
#include "m_msg_main.h"
#include "m_choice_main.h"
#include "m_string.h"
#include "unknown_structs.h"

void aEGPS_actor_ct(Actor* thisx, Game_Play* game_play);
void aEGPS_actor_dt(Actor* thisx, Game_Play* game_play);
void aEGPS_actor_init(Actor* thisx, Game_Play* game_play);
void aEGPS_actor_save(Actor* thisx, Game_Play* game_play);

enum {
    aEGPS_ACTION_TALK_END_WAIT,
    aEGPS_ACTION_CALL_IN,
    aEGPS_ACTION_DECIDE_RESULT,
    aEGPS_ACTION_DECIDE_RESULT2,
    aEGPS_ACTION_NUM
};

enum {
    aEGPS_STR_TYPE_ADJECTIVE,
    aEGPS_STR_TYPE_NOUN,
    aEGPS_STR_TYPE_VERB,
    aEGPS_STR_TYPE_PLACE,
    aEGPS_STR_TYPE_NUM
};

void func_809DCA44_jp(Actor* actorx, Game_Play* play);
void func_809DC850_jp(Ev_Gypsy* gypsy, Game_Play* play, s32 action);
void func_809DC880_jp(Ev_Gypsy* gypsy, Game_Play* play, s32 action);
void func_809DC90C_jp(Actor* actorx, Game_Play* play);
s32 func_809DC940_jp(Actor* actorx, Game_Play* game_play);
s32 func_809DC990_jp(Actor* actorx, Game_Play* game_play);
void func_809DC8B4_jp(Actor* actorx);
void func_809DC7F4_jp(Ev_Gypsy* gypsy, Game_Play* play);
void func_809DC9E0_jp(Actor* actorx, Game_Play* play);
void func_809DC590_jp(s32 type);
void func_809DC608_jp(Ev_Gypsy* gypsy, Game_Play* play);
void func_809DC6E4_jp(Ev_Gypsy* gypsy, Game_Play* play);
extern struct struct_809AEFA4 D_809DCA94_jp;
extern s32 D_809DCAB0_jp[];
extern s32 D_809DCAC0_jp[];
extern s32 D_809DCACC_jp[];
extern s32 D_809DCAD8_jp[];
extern s32 D_809DCAF0_jp[];
extern u8 D_809DCB04_jp[];
extern Ev_GypsyActionFunc D_809DCB0C_jp[];
extern Ev_GypsyActionFunc D_809DCB1C_jp[];

#if 0
ActorProfile Ev_Gypsy_Profile = {
    /* */ ACTOR_EV_GYPSY,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0xD00C,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Ev_Gypsy),
    /* */ aEGPS_actor_ct,
    /* */ aEGPS_actor_dt,
    /* */ aEGPS_actor_init,
    /* */ (void*)none_proc1,
    /* */ aEGPS_actor_save,
};
#endif

void aEGPS_actor_ct(Actor* actorx, Game_Play* play) {
    Ev_Gypsy* gypsy = (Ev_Gypsy*)actorx;

    if (common_data.clip.unk_040->unk_BC(actorx, play) == 1) {
        common_data.clip.unk_040->unk_C0(actorx, play, &D_809DCA94_jp);
        actorx->unk_144 = 80.0f;
        actorx->colStatus.mass = 255;
        actorx->world.pos.x += 20.0f;
        gypsy->setup_talk_proc = func_809DC880_jp;
    }
}

void aEGPS_actor_save(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C8(thisx, game_play);
}

void aEGPS_actor_dt(Actor* actorx, Game_Play* play) {
    common_data.clip.unk_040->unk_C4(actorx, play);
    func_8007D42C_jp();
    func_800814B8_jp(0x40, actorx);
}

void aEGPS_actor_init(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(thisx, game_play);
}

void func_809DC590_jp(s32 type) {
    char str[10];
    s32 str_no = D_809DCAB0_jp[type] + (s32)(fqrand() * 32.0f);

    mString_Load_StringFromRom(str, sizeof(str), str_no);
    mMsg_Set_item_str(mMsg_Get_base_window_p(), type, str, sizeof(str));
}

void func_809DC608_jp(Ev_Gypsy* gypsy, Game_Play* play) {
    MessageWindow* msg_p = mMsg_Get_base_window_p();

    if (func_8009E908_jp(msg_p) == 1) {
        s32 type = -1;

        switch (mChoice_Get_ChoseNum(mChoice_Get_base_window_p())) {
            case Choice_CHOICE0:
                if (common_data.privateInfo->inventory.wallet >= aEGPS_FORTUNE_PRICE) {
                    type = 1;
                } else {
                    type = 2;
                }
                break;
            case Choice_CHOICE1:
                type = 0;
                break;
        }
        if (type != -1) {
            func_8009DBA4_jp(msg_p, D_809DCAC0_jp[type]);
            gypsy->setup_talk_proc(gypsy, play, D_809DCACC_jp[type]);
        }
    }
}

void func_809DC6E4_jp(Ev_Gypsy* gypsy, Game_Play* play) {
    s32 selected;

    if (mDemo_Get_OrderValue(DEMO_ORDER_NPC0, 9) != 0) {
        MessageWindow* msg_p = mMsg_Get_base_window_p();

        mDemo_Set_OrderValue(DEMO_ORDER_NPC0, 9, 0);
        if (gypsy->talk_action == aEGPS_ACTION_DECIDE_RESULT) {
            selected = (s32)(fqrand() * 10.0f);
            if (selected < 4) {
                selected = 4;
            }
            selected -= 4;
            common_data.privateInfo->destiny.type = D_809DCB04_jp[selected];
            func_8009DBA4_jp(msg_p, D_809DCAD8_jp[selected]);
        } else {
            selected = common_data.privateInfo->destiny.type - 1;
            func_8009DBA4_jp(msg_p, D_809DCAF0_jp[selected]);
        }
        gypsy->setup_talk_proc(gypsy, play, aEGPS_ACTION_TALK_END_WAIT);
    }
}

void func_809DC7F4_jp(Ev_Gypsy* gypsy, Game_Play* play) {
    u32 wallet = common_data.privateInfo->inventory.wallet;

    wallet -= aEGPS_FORTUNE_PRICE;
    common_data.privateInfo->inventory.wallet = wallet;
    func_809DC590_jp(aEGPS_STR_TYPE_ADJECTIVE);
    func_809DC590_jp(aEGPS_STR_TYPE_NOUN);
    func_809DC590_jp(aEGPS_STR_TYPE_VERB);
    func_809DC590_jp(aEGPS_STR_TYPE_PLACE);
    gypsy->fortune_given = 1;
}

void func_809DC850_jp(Ev_Gypsy* gypsy, Game_Play* play, s32 action) {
    D_809DCB0C_jp[action](gypsy, play);
}

void func_809DC880_jp(Ev_Gypsy* gypsy, Game_Play* play, s32 action) {
    gypsy->talk_action = action;
    gypsy->talk_proc = D_809DCB1C_jp[action];
    func_809DC850_jp(gypsy, play, action);
}

void func_809DC8B4_jp(Actor* actorx) {
    Ev_Gypsy* gypsy = (Ev_Gypsy*)actorx;
    s32 msg_num;

    if (gypsy->fortune_given == 1) {
        msg_num = 0x982;
    } else if (common_data.privateInfo->destiny.type == 0) {
        msg_num = 0x970;
    } else {
        msg_num = 0x97B;
    }
    mDemo_Set_msg_num(msg_num);
}

void func_809DC90C_jp(Actor* actorx, Game_Play* play) {
    mDemo_Request(DEMO_TYPE_TALK, actorx, func_809DC8B4_jp);
}

s32 func_809DC940_jp(Actor* actorx, Game_Play* game_play) {
    Ev_Gypsy* gypsy = (Ev_Gypsy*)actorx;
    Game_Play* play = game_play;
    s32 next_act_idx;

    if (common_data.privateInfo->destiny.type == 0) {
        next_act_idx = aEGPS_ACTION_CALL_IN;
    } else {
        next_act_idx = aEGPS_ACTION_DECIDE_RESULT2;
    }
    gypsy->setup_talk_proc(gypsy, play, next_act_idx);
    mDemo_Set_ListenAble();
    return 1;
}

s32 func_809DC990_jp(Actor* actorx, Game_Play* game_play) {
    Ev_Gypsy* gypsy = (Ev_Gypsy*)actorx;
    Game_Play* play = game_play;
    s32 res = 0;

    gypsy->talk_proc(gypsy, play);
    if (mDemo_Check(DEMO_TYPE_TALK, actorx) == 0) {
        res = 1;
    }
    return res;
}

void func_809DC9E0_jp(Actor* actorx, Game_Play* play) {
    common_data.clip.unk_040->unk_D0(actorx, play);
    if (mDemo_Check(DEMO_TYPE_TALK, actorx) == 0) {
        chase_angle(&actorx->shape.rot.y, 0, 0x400);
        actorx->world.rot.y = actorx->shape.rot.y;
    }
}

void func_809DCA44_jp(Actor* actorx, Game_Play* play) {
    common_data.clip.unk_040->unk_E4(actorx, play);
}
