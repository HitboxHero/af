#include "ac_ride_off_demo.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_scene.h"
#include "m_bgm.h"
#include "overlays/actors/ovl_Train1/ac_train1.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "m_player_lib.h"
#include "683030.h"
#include "m_collision_bg.h"
#include "libc/math.h"

void aROD_actor_ct(Actor* thisx, Game_Play* game_play);
void aROD_actor_dt(Actor* thisx, Game_Play* game_play);
void aROD_actor_move(Actor* thisx, Game_Play* game_play);

void func_80953C90_jp(Actor* actor, Game_Play* game_play, s32 idx);
void func_80953C24_jp(Actor* actor, Game_Play* game_play);
void func_8095388C_jp(Game_Play* game_play);
void func_809538CC_jp(Actor* actor, Game_Play* game_play);
void func_80953974_jp(Actor* actor, Game_Play* game_play);
void func_80953910_jp(Actor* actor, Game_Play* game_play);
void func_80953B30_jp(Actor* actor, Game_Play* game_play);
void func_809539CC_jp(Actor* actor, Game_Play* game_play);
void func_80953B98_jp(Actor* actor, Game_Play* game_play);
void func_80953A44_jp(Actor* actor, Game_Play* game_play);
void func_80953C60_jp(Actor* thisx, Game_Play* game_play, s32 action);
extern ActorFunc D_80953D34_jp[];
extern xyz_t D_80953D14_jp;
extern struct DemoClip B_80953D60_jp;

#if 0
ActorProfile Ride_Off_Demo_Profile = {
    /* */ ACTOR_RIDE_OFF_DEMO,
    /* */ ACTOR_PART_7,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20000000,
    /* */ 0x0000,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Ride_Off_Demo),
    /* */ aROD_actor_ct,
    /* */ aROD_actor_dt,
    /* */ aROD_actor_move,
    /* */ (void*)none_proc1,
    /* */ NULL,
};
#endif

void aROD_actor_ct(Actor* actor, Game_Play* game_play) {
    common_data.clip.demo_clip = &B_80953D60_jp;
    common_data.clip.demo_clip->demoActor = actor;
    common_data.clip.demo_clip->type = DEMO_CLIP_TYPE_RIDE_OFF_DEMO;
    func_80953C90_jp(actor, game_play, 0);
}

void aROD_actor_dt(Actor* actor, Game_Play* game_play) {
    if (common_data.clip.demo_clip != NULL) {
        common_data.clip.demo_clip = NULL;
    }
}

void func_8095388C_jp(Game_Play* game_play) {
    s32 res = mPlib_get_player_actor_main_index(game_play) == 0x4E;

    if (res != 1) {
        func_800B2D74_jp(game_play);
    }
}

void func_809538CC_jp(Actor* actor, Game_Play* game_play) {
    common_data.train_coming_flag = 3;
    func_8095388C_jp(game_play);
    func_80953C90_jp(actor, game_play, 1);
}

void func_80953910_jp(Actor* actor, Game_Play* game_play) {
    Train1* train;
    Ride_Off_Demo* ride_off = (Ride_Off_Demo*)actor;

    train = (Train1*)Actor_info_fgName_search(&game_play->actorInfo, 0x580B, ACTOR_PART_0);

    func_8095388C_jp(game_play);
    if (train != NULL) {
        ride_off->train_actor = train;
        train->arg0 = 1;
        func_80953C90_jp(actor, game_play, 2);
    }
}

void func_80953974_jp(Actor* actor, Game_Play* game_play) {
    Train1* train;
    Ride_Off_Demo* ride_off = (Ride_Off_Demo*)actor;

    train = ride_off->train_actor;

    func_8095388C_jp(game_play);
    if (train->action == 5) {
        func_80953C90_jp(actor, game_play, 3);
    }
}

void func_809539CC_jp(Actor* actor, Game_Play* game_play) {
    Ride_Off_Demo* ride_off = (Ride_Off_Demo*)actor;
    Actor* station_master = ride_off->station_master_actor;

    if (ride_off->_188 == 0) {
        if (mDemo_Check(DEMO_TYPE_SPEAK, station_master) == 1) {
            ride_off->_188 = 1;
        }
    } else if (!mDemo_Check(DEMO_TYPE_SPEAK, station_master)) {
        func_80953C90_jp(actor, game_play, 4);
    }
}

void func_80953A44_jp(Actor* actor, Game_Play* game_play) {
    Ride_Off_Demo* ride_off = (Ride_Off_Demo*)actor;
    Game_Play* play = game_play;
    Player* player = get_player_actor_withoutCheck(game_play);

    if (player != NULL) {
        if (player->actor.world.pos.z >= 840.0f) {
            Actor* station_master = ride_off->station_master_actor;

            if (IS_ZERO(station_master->speed)) {
                mPlib_request_main_wait_type3(game_play);
                Camera2_request_main_normal(play, 0, 9);
                Actor_delete(actor);
            }
        } else {
            func_800B35E4_jp(2220.0f, 840.0f, 2.5f);
        }
    }
}

void func_80953AE8_jp(Actor* thisx, Game_Play* game_play) {
    ActorEntry* entry = game_play->unk_1EA8;

    mBGMPsComp_make_ps_happening(0x2F, 0x168);
    entry->pos.x = 1970;
    entry->pos.z = 760;
}

void func_80953B30_jp(Actor* actor, Game_Play* game_play) {
    xyz_t pos;
    Game_Play* play = game_play;

    pos.x = 2180.0f;
    pos.z = 820.0f;
    pos.y = 235.0f;
    func_800628F0_jp(play, &pos, 0.0f, 0.0f, 0.0f, 9);
}

void func_80953B98_jp(Actor* actor, Game_Play* game_play) {
    Train1* train;
    Ride_Off_Demo* ride_off = (Ride_Off_Demo*)actor;

    train = ride_off->train_actor;

    ride_off->station_master_actor = Actor_info_fgName_search(&game_play->actorInfo, 0xD00E, ACTOR_PART_NPC);
    train->arg0 = 0;
    func_800B2D18_jp(game_play);
    ride_off->_188 = 0;
    func_80073C38_jp(D_80953D14_jp, 7);
}

void func_80953C24_jp(Actor* actor, Game_Play* game_play) {
    func_800B2C80_jp(game_play, 2220.0f, 840.0f, 2.5f, 0);
}

extern ActorFunc D_80953D20_jp[];

void func_80953C60_jp(Actor* thisx, Game_Play* game_play, s32 action) {
    D_80953D20_jp[action](thisx, game_play);
}

void func_80953C90_jp(Actor* actor, Game_Play* game_play, s32 idx) {
    Ride_Off_Demo* ride_off = (Ride_Off_Demo*)actor;

    ride_off->current_proc = D_80953D34_jp[idx];
    ride_off->current_action = idx;
    func_80953C60_jp(actor, game_play, idx);
}

void aROD_actor_move(Actor* actor, Game_Play* game_play) {
    Ride_Off_Demo* ride_off = (Ride_Off_Demo*)actor;

    ride_off->current_proc(actor, game_play);
}
