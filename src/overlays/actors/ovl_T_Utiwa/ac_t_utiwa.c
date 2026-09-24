#include "ac_t_utiwa.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

void aTUT_actor_ct(Actor* thisx, Game_Play* game_play);
void aTUT_actor_move(Actor* thisx, Game_Play* game_play);
void aTUT_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile T_Utiwa_Profile = {
    /* */ ACTOR_T_UTIWA,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ OBJECT_53,
    /* */ sizeof(T_Utiwa),
    /* */ aTUT_actor_ct,
    /* */ (void*)none_proc1,
    /* */ aTUT_actor_move,
    /* */ aTUT_actor_draw,
    /* */ NULL,
};
#endif

void aTUT_actor_ct(Actor* thisx, UNUSED Game_Play* game_play) {
    extern void func_80A1FB8C_jp(Actor* thisx, s32 action);

    func_80A1FB8C_jp(thisx, 0);
}

void func_80A1FAC4_jp(Actor* thisx, s32 index) {
    extern f32 D_80A1FD24_jp[];
    xyz_t* scale = &thisx->scale;
    f32 value = scale->x;

    chase_f(&value, D_80A1FD24_jp[index], 0.1f);
    scale->x = value;
    scale->y = value;
    scale->z = value;
}

void func_80A1FB2C_jp(Actor* thisx) {
    func_80A1FAC4_jp(thisx, 0);
}

void func_80A1FB4C_jp(Actor* thisx) {
    func_80A1FAC4_jp(thisx, 1);
}

void func_80A1FB6C_jp(Actor* thisx) {
    Actor_delete(thisx);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/func_80A1FB8C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/aTUT_actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/aTUT_actor_draw.s")
