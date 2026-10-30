#include "ac_tukimi_npc0.h"
#include "m_lib.h"
#include "unknown_structs.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "m_npc.h"
#include "m_field_info.h"
#include "m_msg_main.h"

void aTM0_actor_ct(Actor* thisx, Game_Play* game_play);
void aTM0_actor_dt(Actor* thisx, Game_Play* game_play);
void aTM0_actor_init(Actor* thisx, Game_Play* game_play);
void aTM0_actor_save(Actor* thisx, Game_Play* game_play);

void func_809DFB48_jp(Actor* thisx, Game_Play* game_play);
void func_809E0050_jp(Actor* thisx, Game_Play* game_play);
void func_809DFB14_jp(Actor* thisx);
void func_809DFB74_jp(Tukimi_Npc0* actorx);
void func_809DFB94_jp(Actor* thisx, Game_Play* game_play);
void func_809DFBA8_jp(Actor* thisx, Game_Play* game_play);
void func_809DFBCC_jp(Actor* thisx, Game_Play* game_play, s32 act_idx);
void func_809DFC84_jp(Actor* thisx, Game_Play* game_play, s32 think_idx);
void func_809DFE80_jp(Actor* thisx, Game_Play* game_play, s32 sche_proc_idx);
void func_809DFBFC_jp(Actor* thisx, Game_Play* game_play);
void func_809DFC54_jp(Actor* thisx, Game_Play* game_play);
void func_809DFCB4_jp(Actor* thisx, Game_Play* game_play);
void func_809DFD88_jp(Actor* thisx, Game_Play* game_play);
void func_809DFFB0_jp(Actor* thisx, Game_Play* game_play);
s32 func_809DFFE4_jp(Actor* thisx, Game_Play* game_play);
s32 func_809E0010_jp(Actor* thisx, Game_Play* game_play);
void func_809DFEB0_jp(Actor* thisx);

// Verified NPC animation callback takes three arguments; see research/tukimi-npc0.md.
typedef void (*Tukimi_Npc0AnimationInitProc)(Actor*, s32, s32);

extern struct_809AEFA4 D_809E00A4_jp;
extern ActorFunc D_809E00C0_jp[3];
extern ActorFunc D_809E00CC_jp[2];
extern s16 D_809E00D4_jp[8];
extern f32 D_FLT_809E00E4_jp[7];
extern f32 D_FLT_809E0100_jp[7];
extern ActorFunc D_809E011C_jp[2];
extern s32 D_809E0124_jp[6];

#if 0
ActorProfile Tukimi_Npc0_Profile = {
    /* */ ACTOR_TUKIMI_NPC0,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0x0000,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Tukimi_Npc0),
    /* */ aTM0_actor_ct,
    /* */ aTM0_actor_dt,
    /* */ aTM0_actor_init,
    /* */ (void*)none_proc1,
    /* */ aTM0_actor_save,
};
#endif

void aTM0_actor_ct(Actor* thisx, Game_Play* game_play) {
    Tukimi_Npc0* tukimi_npc0_actor = (Tukimi_Npc0*)thisx;
    if (common_data.clip.unk_040->unk_BC(thisx, game_play) == 1) {
        tukimi_npc0_actor->schedule_proc = func_809DFE80_jp;
        common_data.clip.unk_040->unk_C0(thisx, game_play, &D_809E00A4_jp);
    }
}

void aTM0_actor_save(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C8(thisx, game_play);
}

void aTM0_actor_dt(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C4(thisx, game_play);
}

void aTM0_actor_init(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(thisx, game_play);
}

void func_809DFB14_jp(Actor* thisx) {
    ((Tukimi_Npc0AnimationInitProc)common_data.clip.unk_040->unk_104)(thisx, 0x4D, 0);
}

void func_809DFB48_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_D0(thisx, game_play);
}

void func_809DFB74_jp(Tukimi_Npc0* actorx) {
    actorx->act_priority = 4;
    actorx->act_idx = 18;
    actorx->act_type = 2;
}

void func_809DFB94_jp(Actor* thisx, Game_Play* game_play) {
    Tukimi_Npc0* actorx = (Tukimi_Npc0*)thisx;
    actorx->act_obj = 1;
}

void func_809DFBA8_jp(Actor* thisx, Game_Play* game_play) {
    Tukimi_Npc0* actorx = (Tukimi_Npc0*)thisx;
    actorx->step = 0;
    func_809DFB14_jp(thisx);
}

void func_809DFBCC_jp(Actor* thisx, Game_Play* game_play, s32 act_idx) {
    D_809E00C0_jp[act_idx](thisx, game_play);
}

void func_809DFBFC_jp(Actor* thisx, Game_Play* game_play) {
    Tukimi_Npc0* actorx = (Tukimi_Npc0*)thisx;
    if (actorx->step == 255) {
        if (actorx->action_idx == 18) {
            actorx->step = 0;
            func_809DFB14_jp(thisx);
        }
        actorx->demo_flg = 0x137;
        func_809DFB74_jp(actorx);
    }
}

void func_809DFC54_jp(Actor* thisx, Game_Play* game_play) {
    Tukimi_Npc0* actorx = (Tukimi_Npc0*)thisx;
    actorx->interrupt_flags = 0;
    actorx->act_proc = func_809DFBCC_jp;
    func_809DFB74_jp(actorx);
}

void func_809DFC84_jp(Actor* thisx, Game_Play* game_play, s32 think_idx) {
    D_809E00CC_jp[think_idx](thisx, game_play);
}

void func_809DFCB4_jp(Actor* thisx, Game_Play* game_play) {
    Tukimi_Npc0* actorx = (Tukimi_Npc0*)thisx;
    actorx->think_proc = func_809DFC84_jp;
    actorx->demo_flg = 0x137;
    actorx->check_kind = 1;
    actorx->hide_request = 0;
    actorx->palActorIgnoreTimer = -1;
    actorx->turn = 1;
    actorx->default_animation = 0x4D;
    thisx->colStatus.mass = 254;
    {
        s32 puleIdx;
        s16 ang;
        puleIdx = mFI_GetPuleIdx();
        ang = D_809E00D4_jp[puleIdx];
        thisx->shape.rot.y = ang;
        thisx->world.rot.y = ang;
        actorx->mv_angl = ang;
        thisx->world.pos.x += D_FLT_809E00E4_jp[puleIdx];
        thisx->world.pos.z += D_FLT_809E0100_jp[puleIdx];
    }
    common_data.clip.unk_040->unk_110(thisx, game_play, 8, 0);
}

void func_809DFD88_jp(Actor* thisx, Game_Play* game_play) {
    Tukimi_Npc0* actorx = (Tukimi_Npc0*)thisx;
    Game_Play* play = game_play;
    xyz_t* head_pos;
    s16 yRot;
    if (!common_data.clip.unk_040->unk_110(thisx, play, -1, 1)) {
        common_data.clip.unk_040->unk_110(thisx, play, -1, 2);
    }
    if (actorx->action_idx == 18) {
        yRot = thisx->shape.rot.y;
        head_pos = &actorx->head_pos;
        head_pos->x = sin_s(yRot) * 40.0f + thisx->eye.pos.x;
        head_pos->y = thisx->eye.pos.y - 30.0f;
        head_pos->z = cos_s(yRot) * 40.0f + thisx->eye.pos.z;
        actorx->head_priority = 3;
        actorx->head_type = 2;
    }
}

void func_809DFE80_jp(Actor* thisx, Game_Play* game_play, s32 sche_proc_idx) {
    D_809E011C_jp[sche_proc_idx](thisx, game_play);
}

void func_809DFEB0_jp(Actor* thisx) {
    MessageWindow* msg_p = mMsg_Get_base_window_p();
    char worldName[ANIMAL_NAME_LEN];
    NpcEvent* eventNpc;
    Actor* actorRet;
    s32 looks;
    s32 i;
    looks = mNpc_GetNpcLooks(thisx);
    for (i = 0; i < 5; i++) {
        eventNpc = mNpc_GetSameEventNpc(i + 0xD03F);
        if (eventNpc != NULL) {
            actorRet = Actor_info_fgName_search(&((Game_Play*)gamePT)->actorInfo, eventNpc->eventId, ACTOR_PART_NPC);
            mNpc_GetNpcWorldName(worldName, (Npc*)actorRet);
            mMsg_Set_free_str(msg_p, i + 1, worldName, sizeof(worldName));
        }
    }
    mDemo_Set_msg_num(D_809E0124_jp[looks] + (s32)(fqrand() * 3.0f));
}

void func_809DFFB0_jp(Actor* thisx, Game_Play* game_play) {
    mDemo_Request(7, thisx, func_809DFEB0_jp);
}

s32 func_809DFFE4_jp(Actor* thisx, Game_Play* game_play) {
    mDemo_Set_ListenAble();
    return 1;
}

s32 func_809E0010_jp(Actor* thisx, Game_Play* game_play) {
    s32 res = 0;
    if (!mDemo_Check(7, thisx)) {
        res = 1;
    }
    return res;
}

void func_809E0050_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_E4(thisx, game_play);
}
