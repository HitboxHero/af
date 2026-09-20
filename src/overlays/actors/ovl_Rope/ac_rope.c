#include "ac_rope.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

void aRP_actor_ct(Actor* thisx, Game_Play* game_play);
void aRP_actor_dt(Actor* thisx, Game_Play* game_play);
void aRP_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Rope_Profile = {
    /* */ ACTOR_ROPE,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ OBJECT_394,
    /* */ sizeof(Rope),
    /* */ aRP_actor_ct,
    /* */ aRP_actor_dt,
    /* */ (void*)none_proc1,
    /* */ aRP_actor_draw,
    /* */ NULL,
};
#endif

void aRP_actor_ct(Actor* thisx, Game_Play* game_play UNUSED) {
    xyz_t world;
    s32 i;

    mFI_Wpos2UtCenterWpos(&world, thisx->world.pos);
    world.x -= 40.0f;
    for (i = 0; i < 3; i++) {
        mCoBG_SetPlussOffset(world, 2, 100);
        world.x += 40.0f;
    }
}

void aRP_actor_dt(Actor* thisx, Game_Play* game_play UNUSED) {
    xyz_t world;
    s32 i;

    mFI_Wpos2UtCenterWpos(&world, thisx->world.pos);
    world.x -= 40.0f;
    for (i = 0; i < 3; i++) {
        mCoBG_SetPlussOffset(world, 0, 100);
        world.x += 40.0f;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Rope/ac_rope/func_8096D920_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Rope/ac_rope/aRP_actor_draw.s")
