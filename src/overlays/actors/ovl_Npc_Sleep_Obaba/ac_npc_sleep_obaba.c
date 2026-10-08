#include "ac_npc_sleep_obaba.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_common_data.h"
#include "sys_math.h"
#include "unknown_structs.h"

void aNSO_actor_ct(Actor* thisx, Game_Play* game_play);
void aNSO_actor_dt(Actor* thisx, Game_Play* game_play);
void aNSO_actor_init(Actor* thisx, Game_Play* game_play);
void aNSO_actor_save(Actor* thisx, Game_Play* game_play);
void func_809CF058_jp(Actor* thisx);
void func_809CF198_jp(Actor* thisx, Game_Play* game_play, s32 proc_type);
void func_809CF270_jp(Actor* thisx, Game_Play* game_play, s32 proc_type);
void func_809CF350_jp(Actor* thisx, Game_Play* game_play, s32 proc_type);

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

void aNSO_actor_ct(Actor* thisx, Game_Play* game_play) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    extern struct_809AEFA4 D_809CF3D4_jp;

    if (common_data.clip.unk_040->unk_BC(thisx, game_play) == 1) {
        this->scheduleProc = func_809CF350_jp;
        common_data.clip.unk_040->unk_C0(thisx, game_play, &D_809CF3D4_jp);
        thisx->world.pos.x -= 6.0f;
        thisx->world.pos.z -= 24.0f;
    }
}

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

void func_809CF024_jp(Actor* thisx, Game_Play* game_play) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    this->demoFlags = 0x3BF;
    common_data.clip.unk_040->unk_D0(thisx, game_play);
}

void func_809CF058_jp(Actor* thisx) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    this->requestPriority = 4;
    this->requestAction = 16;
    this->requestType = 2;
}

void func_809CF078_jp(Actor* thisx) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    if (this->animationState == 2) {
        if (this->loopCount == 0) {
            this->actionStep = 255;
        } else {
            this->loopCount--;
        }
    }
}

void func_809CF0AC_jp(Actor* thisx) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    if (this->animationState == 1) {
        this->actionStep = 255;
    }
}

void func_809CF0CC_jp(Actor* thisx, s32 action) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    extern Npc_Sleep_ObabaActionFunc D_809CF3F8_jp[];

    this->actionStep = 0;
    this->action = action;
    this->actionProc = D_809CF3F8_jp[action];
    this->loopCount = 2 + RANDOM(3);
    func_809CEFE4_jp(thisx, action);
}

void func_809CF138_jp(Actor* thisx, Game_Play* game_play) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    this->actionObject = 1;
}

void func_809CF0CC_jp(Actor* thisx, s32 action);

void func_809CF14C_jp(Actor* thisx, Game_Play* game_play) {
    func_809CF0CC_jp(thisx, 0);
}

void func_809CF170_jp(Actor* thisx, Game_Play* game_play) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    this->actionProc(thisx);
}

extern ActorFunc D_809CF400_jp[];

void func_809CF198_jp(Actor* thisx, Game_Play* game_play, s32 proc_type) {
    D_809CF400_jp[proc_type](thisx, game_play);
}

void func_809CF1C8_jp(Actor* thisx, Game_Play* game_play) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    extern s32 D_809CF40C_jp[];
    f32 random;

    if (this->actionStep == 255) {
        if (this->actionIndex == 16) {
            random = fqrand();
            func_809CF0CC_jp(thisx, D_809CF40C_jp[(s32)(random + random)]);
        }
        func_809CF058_jp(thisx);
    }
}

void func_809CF240_jp(Actor* thisx, Game_Play* game_play) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    this->interruptFlags = 0;
    this->actionDispatch = func_809CF198_jp;
    func_809CF058_jp(thisx);
}

extern ActorFunc D_809CF414_jp[];

void func_809CF270_jp(Actor* thisx, Game_Play* game_play, s32 proc_type) {
    D_809CF414_jp[proc_type](thisx, game_play);
}

void func_809CF2A0_jp(Actor* thisx, Game_Play* game_play) {
    Npc_Sleep_Obaba* this = (Npc_Sleep_Obaba*)thisx;

    this->thinkProc = func_809CF270_jp;
    this->hideRequest = 0;
    common_data.clip.unk_040->unk_110(thisx, game_play, 6, 0);
}

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
