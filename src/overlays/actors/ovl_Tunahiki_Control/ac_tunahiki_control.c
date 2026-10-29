#include "ac_tunahiki_control.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_event.h"

void aTNC_actor_ct(Actor* thisx, Game_Play* game_play);
void aTNC_actor_dt(Actor* thisx, Game_Play* game_play);
void aTNC_actor_move(Actor* thisx, Game_Play* game_play);

void func_80A919E8_jp(Tunahiki_Control* this, s32 action);
void func_80A918C4_jp(Tunahiki_Control* this, Game_Play* game_play);
extern Tunahiki_ControlActionFunc D_80A91A34_jp[];

#if 0
ActorProfile Tunahiki_Control_Profile = {
    /* */ ACTOR_TUNAHIKI,
    /* */ ACTOR_PART_7,
    /* */ ACTOR_FLAG_10,
    /* */ 0x0000,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Tunahiki_Control),
    /* */ aTNC_actor_ct,
    /* */ aTNC_actor_dt,
    /* */ aTNC_actor_move,
    /* */ (void*)none_proc1,
    /* */ NULL,
};
#endif

void aTNC_actor_ct(Actor* thisx, Game_Play* game_play) {
    Tunahiki_Control* this = (Tunahiki_Control*)thisx;
    TunahikiControlSave* save = (TunahikiControlSave*)mEv_get_save_area(9, 9);

    func_80A919E8_jp(this, 0);
    if (save == NULL) {
        save = (TunahikiControlSave*)func_80080080_jp(9, 9);
        if (save != NULL) {
            save->rope = 0.0f;
            save->ropeBase = 0.0f;
            save->flags = 0;
            save->npcState = 0;
            save->unk_14 = 0;
        }
    }
}

void aTNC_actor_dt(Actor* thisx, Game_Play* game_play) {
    func_800814B8_jp(9, thisx);
}

void aTNC_actor_move(Actor* thisx, Game_Play* game_play) {
    Tunahiki_Control* this = (Tunahiki_Control*)thisx;

    this->process(this, game_play);
}

void func_80A918C4_jp(Tunahiki_Control* this, Game_Play* game_play) {
    TunahikiControlSave* save = (TunahikiControlSave*)mEv_get_save_area(9, 9);
    f32 shake = 0.0f;

    if (save->flags & 0x8000) {
        if (game_play->unk_1EA0 & 1) {
            shake = 0.3f;
        } else {
            shake = -0.3f;
        }
        if ((save->flags & 0x3E0) == 0) {
            save->ropeBase += save->speed * 0.05f;
            if (save->ropeBase < -10.0f) {
                save->ropeBase = -10.0f;
                save->speed = 0.0f;
            } else if (save->ropeBase > 10.0f) {
                save->ropeBase = 10.0f;
                save->speed = 0.0f;
            }
        }
    }
    {
        TunahikiControlSave* output = (TunahikiControlSave*)mEv_get_save_area(9, 9);
        output->rope = save->ropeBase + shake;
    }
    save->counter++;
    if (save->counter >= 37) {
        save->counter = 1;
    }
}

void func_80A919E8_jp(Tunahiki_Control* this, s32 action) {
    this->action = action;
    this->process = D_80A91A34_jp[action];
}
