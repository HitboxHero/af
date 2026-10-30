# Tamaire_Npc0 — 2026-10-30

## Identity before editing

Source/header: `src/overlays/actors/ovl_Tamaire_Npc0/ac_tamaire_npc0.c` / `.h`.
Assembly: `asm/jp/nonmatchings/overlays/actors/ovl_Tamaire_Npc0/ac_tamaire_npc0/`.
Data: `asm/jp/data/overlays/actors/ovl_Tamaire_Npc0/ac_tamaire_npc0.data.s`.
Config `animalforest-jp.yaml:15555`, `ovl_Tamaire_Npc0`:
ROM text [0x946900,0x947330), VRAM [0x80A86670,0x80A870A0).
Data ROM [0x947330,0x9473F0); separate reloc [0x9473F0,0x9474F0).
No rodata or BSS. Text extent 2608 bytes = 2596 function bytes + 12 zero padding
bytes at 0x80A87094–0x80A8709F following func_80A87068_jp.
Profile at 0x80A870A0: actor 0x96 ACTOR_TAMAIRE_NPC0 (table entry 0x96),
NPC part 3, flags zero, item 0xD053, object 3, actor size 0x950. Constructor,
destructor, update and save use established aTMN0 symbols; draw is none_proc1.
Already matched aTMN0_actor_save at 0x80A86738, 36 bytes.
29 total functions; 28 remaining, 2560 bytes. No structural/jump-table or unsafe
uninitialized-value blockers found. Switches use branches; data dispatch tables
have explicit entries and bounds. Shared local layout recovery unlocks most work.

| Symbol | VRAM | Bytes | Initial classification |
| --- | --- | ---: | --- |
| aTMN0_actor_save | 0x80A86738 | 36 | already matched |
| aTMN0_actor_ct | 0x80A86670 | 200 | target-local type/layout blocked |
| aTMN0_actor_dt | 0x80A8675C | 44 | attemptable now |
| aTMN0_actor_init | 0x80A86788 | 44 | attemptable now |
| func_80A867B4_jp | 0x80A867B4 | 156 | target-local type/layout blocked |
| func_80A86850_jp | 0x80A86850 | 44 | attemptable now |
| func_80A8687C_jp | 0x80A8687C | 32 | target-local type/layout blocked |
| func_80A8689C_jp | 0x80A8689C | 88 | attemptable now |
| func_80A868F4_jp | 0x80A868F4 | 64 | target-local type/layout blocked |
| func_80A86934_jp | 0x80A86934 | 76 | target-local type/layout blocked |
| func_80A86980_jp | 0x80A86980 | 64 | target-local type/layout blocked |
| func_80A869C0_jp | 0x80A869C0 | 124 | target-local type/layout blocked |
| func_80A86A3C_jp | 0x80A86A3C | 148 | target-local type/layout blocked |
| func_80A86AD0_jp | 0x80A86AD0 | 84 | target-local type/layout blocked; prototype/declaration blocked |
| func_80A86B24_jp | 0x80A86B24 | 76 | target-local type/layout blocked |
| func_80A86B70_jp | 0x80A86B70 | 176 | target-local type/layout blocked |
| func_80A86C20_jp | 0x80A86C20 | 100 | target-local type/layout blocked |
| func_80A86C84_jp | 0x80A86C84 | 104 | target-local type/layout blocked |
| func_80A86CEC_jp | 0x80A86CEC | 60 | target-local type/layout blocked |
| func_80A86D28_jp | 0x80A86D28 | 56 | target-local type/layout blocked |
| func_80A86D60_jp | 0x80A86D60 | 76 | target-local type/layout blocked |
| func_80A86DAC_jp | 0x80A86DAC | 72 | target-local type/layout blocked |
| func_80A86DF4_jp | 0x80A86DF4 | 140 | target-local type/layout blocked; prototype/declaration blocked |
| func_80A86E80_jp | 0x80A86E80 | 172 | target-local type/layout blocked |
| func_80A86F2C_jp | 0x80A86F2C | 72 | attemptable now |
| func_80A86F74_jp | 0x80A86F74 | 64 | target-local type/layout blocked |
| func_80A86FB4_jp | 0x80A86FB4 | 108 | attemptable now |
| func_80A87020_jp | 0x80A87020 | 72 | attemptable now |
| func_80A87068_jp | 0x80A87068 | 44 | attemptable now |

## Shared type and ABI reconstruction

Existing Actor offsets and size 0x174 are reused. NpcActorInfo at 0x174 is already
verified in current af. FrameControl mode at 0x1AC corresponds to keyframe +0x14,
so existing SkeletonInfoR at 0x198 ends at 0x208. Animation ID word 0x704,
NPC think dispatch 0x7A4 and interrupt flags 0x7A8, schedule dispatch 0x7C0,
action index/step bytes 0x7C5/0x7C6, request bytes 0x7D4–0x7D6, request args
12 bytes at 0x7D8, hide request byte 0x7FD, demo flags word 0x80C,
palActorIgnoreTimer word 0x8AC, destination x/z floats 0x8BC/0x8C0,
collision check byte 0x911, talk-request callback 0x91C are verified by N64
loads/stores/calls and matching GC behavior. Read-modify timing uses signed lh;
state flags use lbu. Target think/talk callbacks at 0x938/0x93C take actor/play;
timer s16 0x940, yasiro_pos s16[2] 0x942, move_pos s16[2] 0x946,
think_idx/next_think_idx/move_think_idx/talk_idx/change_flag bytes 0x94A–0x94E.
Unused storage remains unknown, exact size 0x950. move_think_idx is only given
GC terminology without use; keep the untouched byte neutral in the N64 header.
Request helper zeros u16[6], fills obj at 0 and x/z at 4/6, then copies 12 bytes.
Think data records stride 5, nine entries plus three alignment bytes. Callback
tables contain respectively 1 talk, 5 think, 5 init, 3 request pointers.

Missing `func_8008E8E0_jp` declaration: its assembly at 0x8008E8E0 returns 0/1,
takes one output pointer, writes signed-converted halfwords x/z/y at offsets 0/2/4
only on success. The calling helper allocates s16[3], reads first two on success.
Declare s32 func_8008E8E0_jp(s16*); GameCube mFI_SetOyasiroPos corroborates meaning.

Animation clip +0x104 is installed as func_809749D0_jp in NPC init assembly
(func_8053a354.s, store at 0x80980F7C). Callee consumes actor, animation number
and third mode argument (saved at sp+0x58); incoming a3 is overwritten before use.
Current Clip_unk_040_unk_104 lists a spurious fourth argument. Use a documented
local cast to the verified three-argument callback signature at this API boundary;
do not alter other targets or supply an arbitrary extra argument. Return is unused.

## N64 ↔ GameCube terminology

References: ac-decomp/src/actor/npc/ac_tamaire_npc0.c, _talk.c_inc,
_schedule.c_inc and include/ac_tamaire_npc0.h. Existing N64 symbols preserved.
N64 move-init timer is 350, not GC 700. N64 state numbers/data tables authoritative.

- `func_80A8687C_jp` ↔ `aTMN0_change_talk_proc` (32 bytes).
- `aTMN0_actor_dt` ↔ `aTMN0_actor_dt` (44 bytes).
- `func_80A87068_jp` ↔ `aTMN0_actor_draw` (44 bytes).
- `func_80A86850_jp` ↔ `aTMN0_actor_move` (44 bytes).
- `aTMN0_actor_init` ↔ `aTMN0_actor_init` (44 bytes).
- `func_80A86D28_jp` ↔ `aTMN0_normal_wait_init` (56 bytes).
- `func_80A86CEC_jp` ↔ `aTMN0_think_init_proc` (60 bytes).
- `func_80A868F4_jp` ↔ `aTMN0_set_norm_talk_info` (64 bytes).
- `func_80A86980_jp` ↔ `aTMN0_talk_init` (64 bytes).
- `func_80A86F74_jp` ↔ `aTMN0_schedule_init_proc` (64 bytes).
- `func_80A86DAC_jp` ↔ `aTMN0_move_init` (72 bytes).
- `func_80A86F2C_jp` ↔ `aTMN0_think_proc` (72 bytes).
- `func_80A87020_jp` ↔ `aTMN0_schedule_proc` (72 bytes).
- `func_80A86D60_jp` ↔ `aTMN0_turn_init` (76 bytes).
- `func_80A86B24_jp` ↔ `aTMN0_turn_next` (76 bytes).
- `func_80A86934_jp` ↔ `aTMN0_norm_talk_request` (76 bytes).
- `func_80A86AD0_jp` ↔ `aTMN0_birth` (84 bytes).
- `func_80A8689C_jp` ↔ `aTMN0_set_nsg` (88 bytes).
- `func_80A86C20_jp` ↔ `aTMN0_timer_next` (100 bytes).
- `func_80A86C84_jp` ↔ `aTMN0_think_main_proc` (104 bytes).
- `func_80A86FB4_jp` ↔ `aTMN0_schedule_main_proc` (108 bytes).
- `func_80A869C0_jp` ↔ `aTMN0_talk_end_chk` (124 bytes).
- `func_80A86DF4_jp` ↔ `aTMN0_kansen_init` (140 bytes).
- `func_80A86A3C_jp` ↔ `aTMN0_set_move_pos` (148 bytes).
- `func_80A867B4_jp` ↔ `aTMN0_set_request_act` (156 bytes).
- `func_80A86E80_jp` ↔ `aTMN0_setup_think_proc` (172 bytes).
- `func_80A86B70_jp` ↔ `aTMN0_move_next` (176 bytes).
- `aTMN0_actor_ct` ↔ `aTMN0_actor_ct` (200 bytes).

## Final classification and naming review

After verified target-local layout and API signature recovery: all 28 remaining
functions became attemptable. All now matched, alongside the original save helper:
29/29, 2596 function bytes, with 12 additional padding bytes exactly retained.
No remaining local type, declaration, structural or unsafe blockers. Existing save
function body is unchanged. Shared actor/NPC/clip layouts are unchanged. Only the
verified shrine-position API declaration was added to m_field_info.h.

GC names reused for actor, actorx, play, prio, idx, type, obj, move_x, move_z,
res, args, msg_no, ret, talk_idx, yasiro_pos, move_pos, think_idx, timer,
next_think_idx, talk_idx, change_flag, dt and aTMN0_think_data_c's five fields.
The unused target byte 0x94C retains a neutral name. NPC prefix terminology reuses
current-af conventions and GC meanings; npc_think_proc distinguishes the three-
argument NPC dispatcher from the target's two-argument think_proc. No established
N64 function symbol was renamed. GC-only 700-frame timer was not copied; N64
350 is retained. No cosmetic restructuring of matching functions was performed.
Duplicate forward declarations were removed.

## Candidate verification

Canonical tools executed in place, never copied or modified. 29 compiled candidates:
27 functions passed first try; talk-end helper passed second try. Initial score 46
was solely stack offsets/frame size. Restoring the GC Game_Play* play local before
ret, and using it in the callbacks, corrected frame 0x28 to 0x30 and ret slot 0x20
to 0x24. No unused padding locals or forcing used. Every accepted function passed
score 0, exact linked bytes, whole-object text/padding equality and exact text
relocation comparison. Evidence under ignored build/tamaire-npc0/attempt*/.

| Symbol | Attempts | Final score | Function bytes |
| --- | ---: | ---: | ---: |
| func_80A8687C_jp | 1 | 0 | 32 |
| aTMN0_actor_dt | 1 | 0 | 44 |
| func_80A87068_jp | 1 | 0 | 44 |
| func_80A86850_jp | 1 | 0 | 44 |
| aTMN0_actor_init | 1 | 0 | 44 |
| func_80A86D28_jp | 1 | 0 | 56 |
| func_80A86CEC_jp | 1 | 0 | 60 |
| func_80A868F4_jp | 1 | 0 | 64 |
| func_80A86980_jp | 1 | 0 | 64 |
| func_80A86F74_jp | 1 | 0 | 64 |
| func_80A86DAC_jp | 1 | 0 | 72 |
| func_80A86F2C_jp | 1 | 0 | 72 |
| func_80A87020_jp | 1 | 0 | 72 |
| func_80A86D60_jp | 1 | 0 | 76 |
| func_80A86B24_jp | 1 | 0 | 76 |
| func_80A86934_jp | 1 | 0 | 76 |
| func_80A86AD0_jp | 1 | 0 | 84 |
| func_80A8689C_jp | 1 | 0 | 88 |
| func_80A86C20_jp | 1 | 0 | 100 |
| func_80A86C84_jp | 1 | 0 | 104 |
| func_80A86FB4_jp | 1 | 0 | 108 |
| func_80A869C0_jp | 2 | 0 | 124 |
| func_80A86DF4_jp | 1 | 0 | 140 |
| func_80A86A3C_jp | 1 | 0 | 148 |
| func_80A867B4_jp | 1 | 0 | 156 |
| func_80A86E80_jp | 1 | 0 | 172 |
| func_80A86B70_jp | 1 | 0 | 176 |
| aTMN0_actor_ct | 1 | 0 | 200 |


## Final build checks

Final canonical verification after declaration cleanup: score 0, whole-object
text/padding and relocation equality; final helper includes all 12 padding bytes.
Full `make -j4`, explicit `make compress`, and `git diff --check` pass. Target
text including padding (2608 bytes), data (192 bytes), and relocation segment
(256 bytes) match the reference ROM byte-for-byte. Assembly/data/config inputs
are retained unchanged. Both ROM hashes pass:
`d7ae64f2f47a9fa3f87686a3c5ce09af` and
`a4f7c57c180297b2e7ba5a5feb44fe0b`.
Only target source/header, verified m_field_info declaration, and these notes
are included; all preexisting unrelated research changes are preserved.
