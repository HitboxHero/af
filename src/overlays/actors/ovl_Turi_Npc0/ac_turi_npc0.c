#include "ac_turi_npc0.h"
#include "m_lib.h"
#include "overlays/actors/ovl_Tools/ac_tools.h"
#include "unknown_structs.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "m_field_info.h"
#include "m_msg_main.h"
#include "m_npc.h"

void func_805900b0(Actor* thisx, Game_Play* game_play);
void func_805901d8(Actor* thisx, Game_Play* game_play);
void aTR0_actor_init(Actor* thisx, Game_Play* game_play);
void aTR0_actor_save(Actor* thisx, Game_Play* game_play);

void func_809E2EE8_jp(Actor* thisx, Game_Play* game_play);
void func_809E2DAC_jp(Turi_Npc0* actor);
void func_809E2D80_jp(Actor* thisx, Game_Play* game_play);
void func_809E3364_jp(Actor* thisx, Game_Play* game_play);
void func_809E2EFC_jp(Actor* thisx, Game_Play* game_play);
void func_809E2F20_jp(Actor* thisx, Game_Play* game_play);
void func_809E2E30_jp(Turi_Npc0* actor);
void func_809E2D40_jp(Turi_Npc0* actor, s32 action);
void func_809E2F48_jp(Actor* thisx, Game_Play* game_play, s32 type);
void func_809E3000_jp(Actor* thisx, Game_Play* game_play, s32 type);
void func_809E3194_jp(Actor* thisx, Game_Play* game_play, s32 type);
void func_809E2FD0_jp(Actor* thisx, Game_Play* game_play);
s32 func_809E32F8_jp(Actor* thisx, Game_Play* game_play);
s32 func_809E3324_jp(Actor* thisx, Game_Play* game_play);
void func_809E32C4_jp(Actor* thisx, Game_Play* game_play);
void func_809E2DCC_jp(Actor* thisx, Game_Play* game_play);
void func_809E2F78_jp(Actor* thisx, Game_Play* game_play);
void func_809E311C_jp(Actor* thisx, Game_Play* game_play);
void func_809E2E64_jp(Turi_Npc0* actor, s32 action);
void func_809E3030_jp(Actor* thisx, Game_Play* game_play);
void func_809E31C4_jp(Actor* thisx);

extern s32 D_809E3390_jp;
extern Actor* B_809E3460_jp[5];
extern struct_809AEFA4 D_809E33B8_jp;
extern s32 D_809E33D4_jp[1];
extern Turi_Npc0ActProc D_809E33D8_jp[1];
extern s32 D_809E33DC_jp[1];
extern f32 D_FLT_809E33E0_jp[1];
extern ActorFunc D_809E33E4_jp[3];
extern ActorFunc D_809E33F0_jp[2];
extern s16 D_809E33F8_jp[5][7];
extern ActorFunc D_809E3440_jp[2];
extern s32 D_809E3448_jp[6];

#if 0
ActorProfile Turi_Npc0_Profile = {
    /* */ ACTOR_TURI_NPC0,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0x0000,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Turi_Npc0),
    /* */ func_805900b0,
    /* */ func_805901d8,
    /* */ aTR0_actor_init,
    /* */ (void*)none_proc1,
    /* */ aTR0_actor_save,
};
#endif

void func_805900b0(Actor* thisx, Game_Play* game_play) {
    if (D_809E3390_jp == 0) {
        s32 i;
        for (i = 0; i < 5; i++) {
            B_809E3460_jp[i] = NULL;
        }
    }
    if (common_data.clip.unk_040->unk_BC(thisx, game_play) == 1) {
        Turi_Npc0* actor = (Turi_Npc0*)thisx;
        actor->schedule_proc = func_809E3194_jp;
        common_data.clip.unk_040->unk_C0(thisx, game_play, &D_809E33B8_jp);
        {
            s32 idx = thisx->fgName - 0xD049;
            B_809E3460_jp[idx] = thisx;
            D_809E3390_jp++;
        }
    }
}

void aTR0_actor_save(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C8(thisx, game_play);
}

void func_805901d8(Actor* thisx, Game_Play* game_play) {
    s32 idx = thisx->fgName - 0xD049;
    B_809E3460_jp[idx] = NULL;
    if (D_809E3390_jp > 0) {
        D_809E3390_jp--;
    }
    common_data.clip.unk_040->unk_C4(thisx, game_play);
}

void aTR0_actor_init(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(thisx, game_play);
}

void func_809E2D40_jp(Turi_Npc0* actor, s32 action) {
    common_data.clip.unk_040->unk_104(&actor->actor, D_809E33D4_jp[action], 0, action);
}

void func_809E2D80_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_D0(thisx, game_play);
}

void func_809E2DAC_jp(Turi_Npc0* actor) {
    actor->act_priority = 4;
    actor->act_idx = 18;
    actor->act_type = 2;
}

void func_809E2DCC_jp(Actor* thisx, Game_Play* game_play) {
    Turi_Npc0* actor = (Turi_Npc0*)thisx;
    if (actor->item_actor_p == NULL) {
        Actor* sao_actor = (Actor*)common_data.clip.toolClip->aTOL_birth_proc(TOOL_NPC_SAO, 3, (ToolActor*)thisx, game_play, -1, NULL);
        if (sao_actor != NULL) {
            actor->item_actor_p = sao_actor;
        }
    }
}

void func_809E2E30_jp(Turi_Npc0* actor) {
    if (actor->main_animation_state == 2) {
        if (actor->loop_flag == 0) {
            actor->step = 255;
        } else {
            actor->loop_flag--;
        }
    }
}

void func_809E2E64_jp(Turi_Npc0* actor, s32 action) {
    actor->step = 0;
    actor->action = action;
    actor->act_proc = D_809E33D8_jp[action];
    actor->loop_flag = D_809E33DC_jp[action] + (s32)(fqrand() * D_FLT_809E33E0_jp[action]);
    func_809E2D40_jp(actor, action);
}

void func_809E2EE8_jp(Actor* thisx, Game_Play* game_play) {
    Turi_Npc0* actor = (Turi_Npc0*)thisx;
    actor->act_obj = 1;
}

void func_809E2EFC_jp(Actor* thisx, Game_Play* game_play) {
    func_809E2E64_jp((Turi_Npc0*)thisx, 0);
}

void func_809E2F20_jp(Actor* thisx, Game_Play* game_play) {
    Turi_Npc0* actor = (Turi_Npc0*)thisx;
    actor->act_proc(actor);
}

void func_809E2F48_jp(Actor* thisx, Game_Play* game_play, s32 type) {
    D_809E33E4_jp[type](thisx, game_play);
}

void func_809E2F78_jp(Actor* thisx, Game_Play* game_play) {
    Turi_Npc0* actor = (Turi_Npc0*)thisx;
    if (actor->step == 255) {
        if (actor->action_idx == 18) {
            func_809E2E64_jp(actor, 0);
        }
        actor->demo_flg = 0x137;
        func_809E2DAC_jp(actor);
    }
}

void func_809E2FD0_jp(Actor* thisx, Game_Play* game_play) {
    Turi_Npc0* actor = (Turi_Npc0*)thisx;
    actor->interrupt_flags = 0;
    actor->action_act_proc = func_809E2F48_jp;
    func_809E2DAC_jp(actor);
}

void func_809E3000_jp(Actor* thisx, Game_Play* game_play, s32 type) {
    D_809E33F0_jp[type](thisx, game_play);
}

void func_809E3030_jp(Actor* thisx, Game_Play* game_play) {
    Turi_Npc0* actor = (Turi_Npc0*)thisx;
    actor->think_proc = func_809E3000_jp;
    actor->demo_flg = 0x137;
    actor->check_kind = 1;
    actor->hide_request = 0;
    actor->palActorIgnoreTimer = -1;
    actor->turn = 1;
    actor->default_animation = 0x79;
    thisx->colStatus.mass = 254;
    if (thisx->fgName == 0xD049) {
        thisx->world.pos.x += 20.0f;
        thisx->world.pos.z += 20.0f;
    }
    {
        s32 pool_idx = mFI_GetPuleIdx();
        s32 idx = thisx->fgName - 0xD049;
        s16 angle = D_809E33F8_jp[idx][pool_idx];
        thisx->shape.rot.y = angle;
        thisx->world.rot.y = angle;
        actor->mv_angl = angle;
    }
    common_data.clip.unk_040->unk_110(thisx, game_play, 8, 0);
}

void func_809E311C_jp(Actor* thisx, Game_Play* game_play) {
    if (common_data.clip.unk_040->unk_110(thisx, game_play, -1, 1) == 0) {
        common_data.clip.unk_040->unk_110(thisx, game_play, -1, 2);
    }
    func_809E2DCC_jp(thisx, game_play);
}

void func_809E3194_jp(Actor* thisx, Game_Play* game_play, s32 type) {
    D_809E3440_jp[type](thisx, game_play);
}

void func_809E31C4_jp(Actor* thisx) {
    MessageWindow* msg_p = mMsg_Get_base_window_p();
    char str[ANIMAL_NAME_LEN];
    s32 looks = mNpc_GetNpcLooks(thisx);
    s32 idx = thisx->fgName - 0xD049;
    s32 i;
    for (i = 0; i < 5; i++) {
        if (B_809E3460_jp[i] != NULL) {
            mNpc_GetNpcWorldName(str, (Npc*)B_809E3460_jp[i]);
            mMsg_Set_free_str(msg_p, i + 1, str, sizeof(str));
        }
    }
    mDemo_Set_msg_num(D_809E3448_jp[looks] + (s32)(fqrand() * 3.0f) + idx * 3);
}

void func_809E32C4_jp(Actor* thisx, Game_Play* game_play) {
    mDemo_Request(7, thisx, func_809E31C4_jp);
}

s32 func_809E32F8_jp(Actor* thisx, Game_Play* game_play) {
    mDemo_Set_ListenAble();
    return 1;
}

s32 func_809E3324_jp(Actor* thisx, Game_Play* game_play) {
    s32 ret = 0;
    if (!mDemo_Check(7, thisx)) {
        ret = 1;
    }
    return ret;
}

void func_809E3364_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_E4(thisx, game_play);
}
