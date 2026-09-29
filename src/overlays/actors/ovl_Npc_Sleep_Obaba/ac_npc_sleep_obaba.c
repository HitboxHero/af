#include "ac_npc_sleep_obaba.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"

void aNSO_actor_ct(Actor* thisx, Game_Play* game_play);
void aNSO_actor_dt(Actor* thisx, Game_Play* game_play);
void aNSO_actor_init(Actor* thisx, Game_Play* game_play);
void aNSO_actor_save(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Npc_Sleep_Obaba_Profile = {
    /* */ ACTORNPC_SLEEP_OBABA,
    /* */ ACTOR_PART_NPC,
    /* */ 0,
    /* */ 0xD038,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Npc_Sleep_Obaba),
    /* */ aNSO_actor_ct,
    /* */ aNSO_actor_dt,
    /* */ aNSO_actor_init,
    /* */ (void*)none_proc1,
    /* */ aNSO_actor_save,
};
#endif

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/aNSO_actor_ct.s")

void aNSO_actor_save(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C8(thisx, game_play);
}

void aNSO_actor_dt(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_C4(thisx, game_play);
}

void aNSO_actor_init(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_CC(thisx, game_play);
}

extern s32 D_809CF3F0_jp[];

void func_809CEFE4_jp(Actor* thisx, s32 action) {
    common_data.clip.unk_040->unk_104(thisx, D_809CF3F0_jp[action], 0, action);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF024_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF058_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF078_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF0AC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF0CC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF138_jp.s")

void func_809CF0CC_jp(Actor* thisx, s32 action);

void func_809CF14C_jp(Actor* thisx, Game_Play* game_play) {
    func_809CF0CC_jp(thisx, 0);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF170_jp.s")

extern ActorFunc D_809CF400_jp[];

void func_809CF198_jp(Actor* thisx, Game_Play* game_play, s32 proc_type) {
    D_809CF400_jp[proc_type](thisx, game_play);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF1C8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF240_jp.s")

extern ActorFunc D_809CF414_jp[];

void func_809CF270_jp(Actor* thisx, Game_Play* game_play, s32 proc_type) {
    D_809CF414_jp[proc_type](thisx, game_play);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Npc_Sleep_Obaba/ac_npc_sleep_obaba/func_809CF2A0_jp.s")

void func_809CF2E4_jp(Actor* thisx, Game_Play* game_play) {
    if (common_data.clip.unk_040->unk_110(thisx, game_play, -1, 1) == 0) {
        common_data.clip.unk_040->unk_110(thisx, game_play, -1, 2);
    }
}

extern ActorFunc D_809CF41C_jp[];

void func_809CF350_jp(Actor* thisx, Game_Play* game_play, s32 proc_type) {
    D_809CF41C_jp[proc_type](thisx, game_play);
}

void func_809CF380_jp(Actor* thisx, Game_Play* game_play) {
    common_data.clip.unk_040->unk_E4(thisx, game_play);
}
