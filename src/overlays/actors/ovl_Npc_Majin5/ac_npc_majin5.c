#include "ac_npc_majin5.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"
#include "m_event.h"
#include "unknown_structs.h"

void aNMJ5_actor_ct(Actor* thisx, Game_Play* game_play);
void aNMJ5_actor_dt(Actor* thisx, Game_Play* game_play);
void aNMJ5_actor_init(Actor* thisx, Game_Play* game_play);
void aNMJ5_actor_save(Actor* thisx, Game_Play* game_play);

void func_80AACE50_jp(Npc_Majin5* actorx, Game_Play* play);
void func_80AAD010_jp(Actor* actorx, Game_Play* game_play);
void func_80AACF1C_jp(Npc_Majin5* actorx, Game_Play* play);
void func_80AACED4_jp(Npc_Majin5* actorx, Game_Play* play, s32 think_proc_idx);
void func_80AACFC8_jp(Npc_Majin5* actorx, Game_Play* play, s32 sched_idx);
void func_80AACF5C_jp(Npc_Majin5* actorx, Game_Play* play);
void func_80AACE60_jp(Npc_Majin5* actorx, Game_Play* play);
void func_80AACDD0_jp(Actor* actorx, Game_Play* game_play);
s32 func_80AACD34_jp(Npc_Majin5* actorx, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z);
extern struct struct_809AEFA4 D_80AAD064_jp;

#if 0
ActorProfile Npc_Majin5_Profile = {
    /* */ ACTOR_NPC_MAJIN5,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0xD06B,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Npc_Majin5),
    /* */ aNMJ5_actor_ct,
    /* */ aNMJ5_actor_dt,
    /* */ aNMJ5_actor_init,
    /* */ (void*)none_proc1,
    /* */ aNMJ5_actor_save,
};
#endif

void aNMJ5_actor_ct(Actor* actorx, Game_Play* game_play) {
    Npc_Majin5* majin5_actor = (Npc_Majin5*)actorx;

    if (common_data.clip.unk_040->unk_BC(actorx, game_play) == 1) {
        majin5_actor->schedule_proc = func_80AACFC8_jp;
        common_data.clip.unk_040->unk_C0(actorx, game_play, &D_80AAD064_jp);
        majin5_actor->umbrella_disabled_flag = 1;
        majin5_actor->palActorIgnoreTimer = -1;
        majin5_actor->check_kind = 0;
        majin5_actor->demo_flg = -1;
        majin5_actor->actor.world.pos.x = majin5_actor->actor.home.pos.x - 80.0f;
        majin5_actor->actor.world.pos.z = majin5_actor->actor.home.pos.z + 480.0f;
        ((NpcMajin5EffectMakeProc)common_data.clip.unk_090->unk_00)(0x5E, majin5_actor->actor.world.pos, 3, 31000,
                                                 &game_play->state, 0xFFFF, 0, 0);
    }
}

void aNMJ5_actor_save(Actor* thisx, Game_Play* game_play UNUSED) {
    mNpc_RenewalSetNpc(thisx);
}

void aNMJ5_actor_dt(Actor* actorx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C4(actorx, game_play);
    common_data.clip.unk_090->effect_kill_proc(0x5E, 0xFFFF);
}

void aNMJ5_actor_init(Actor* actorx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(actorx, game_play);
}

s32 func_80AACD34_jp(Npc_Majin5* actorx, u8 prio, u8 idx, u8 type, u16 obj, s16 move_x, s16 move_z) {
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

void func_80AACDD0_jp(Actor* actorx, Game_Play* game_play) {
    NpcMajin5EventSave* save_area;

    save_area = (NpcMajin5EventSave*)mEv_get_save_area(0x21, 10);
    common_data.clip.unk_040->unk_D0(actorx, game_play);
    actorx->shape.rot.y = 31000;
    if (save_area != NULL && (save_area->bitfield & 0x2000)) {
        save_area->bitfield &= ~0x2000;
        Actor_delete(actorx);
    }
    actorx->shape.drawShadow = 0;
}

void func_80AACE50_jp(Npc_Majin5* actorx, Game_Play* play) {
}

void func_80AACE60_jp(Npc_Majin5* actorx, Game_Play* play) {
    Npc_Majin5* majin = actorx;

    majin->actor.colStatus.mass = MASS_HEAVY;
    actorx->hide_request = 0;
    actorx->action_idx = 0;
    func_80AACD34_jp(majin, 4, 0, 0, 0, 0, 0);
    ((NpcMajin5AnimationInitProc)common_data.clip.unk_040->unk_104)(&majin->actor, 0x4E, 0);
    actorx->main_animation_mode = ANIMATION_REPEAT;
}

void func_80AACED4_jp(Npc_Majin5* actorx, Game_Play* play, s32 think_proc_idx) {
    switch (think_proc_idx) {
        case 0:
            func_80AACE60_jp(actorx, play);
            break;
        case 1:
            func_80AACE50_jp(actorx, play);
            break;
    }
}

void func_80AACF1C_jp(Npc_Majin5* actorx, Game_Play* play) {
    actorx->think_proc = func_80AACED4_jp;
    common_data.clip.unk_040->unk_110(&actorx->actor, play, 8, 0);
}

void func_80AACF5C_jp(Npc_Majin5* actorx, Game_Play* play) {
    if (common_data.clip.unk_040->unk_110(&actorx->actor, play, -1, 1) == 0) {
        common_data.clip.unk_040->unk_110(&actorx->actor, play, -1, 2);
    }
}

void func_80AACFC8_jp(Npc_Majin5* actorx, Game_Play* play, s32 sched_idx) {
    switch (sched_idx) {
        case 0:
            func_80AACF1C_jp(actorx, play);
            break;
        case 1:
            func_80AACF5C_jp(actorx, play);
            break;
    }
}

void func_80AAD010_jp(Actor* actorx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_E4(actorx, game_play);
}
