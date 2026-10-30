# Tukimi_Npc0 matching work — 2026-10-30

## Identity before editing

Source/header `src/overlays/actors/ovl_Tukimi_Npc0/ac_tukimi_npc0.c` / `.h`.
Assembly `asm/jp/nonmatchings/overlays/actors/ovl_Tukimi_Npc0/ac_tukimi_npc0/`.
Data `asm/jp/data/overlays/actors/ovl_Tukimi_Npc0/ac_tukimi_npc0.data.s`.
Config `animalforest-jp.yaml:3483` ovl_Tukimi_Npc0; C entry line 3491.
Text ROM [0x8C3210,0x8C3870), VRAM [0x809DFA20,0x809E0080):
21 function symbols, 1628 function bytes + 4 zero-padding bytes at 0x809E007C.
Data ROM [0x8C3870,0x8C3930), 192 bytes; no BSS or rodata.
Relocation segment [0x8C3930,0x8C3A00), next Tukimi_Npc1 begins 0x8C3A00.
Profile Tukimi_Npc0_Profile at 0x809E0080: actor ID 0x8D, NPC part 3,
flags/item zero, object 3, size 0x938; established ctor/dtor/update/save callbacks;
draw none_proc1. All functions initially assembly; zero matched.

## Initial function classification

12 attemptable, 8 target-local layout blocked, 1 prototype blocked. No compiler
jump tables or uninitialized-value blockers. Explicit data callback dispatches.
One shared layout fix unlocks the eight; animation API cast already established
by Tamaire_Npc0's N64 callee/dispatch audit handles the legacy extra-argument type.

| Symbol | VRAM | Bytes | Initial class |
| --- | --- | ---: | --- |
| aTM0_actor_ct | 0x809DFA20 | 112 | target-local layout |
| aTM0_actor_save | 0x809DFA90 | 44 | attemptable |
| aTM0_actor_dt | 0x809DFABC | 44 | attemptable |
| aTM0_actor_init | 0x809DFAE8 | 44 | attemptable |
| func_809DFB14_jp | 0x809DFB14 | 52 | prototype |
| func_809DFB48_jp | 0x809DFB48 | 44 | attemptable |
| func_809DFB74_jp | 0x809DFB74 | 32 | target-local layout |
| func_809DFB94_jp | 0x809DFB94 | 20 | target-local layout |
| func_809DFBA8_jp | 0x809DFBA8 | 36 | target-local layout |
| func_809DFBCC_jp | 0x809DFBCC | 48 | attemptable |
| func_809DFBFC_jp | 0x809DFBFC | 88 | target-local layout |
| func_809DFC54_jp | 0x809DFC54 | 48 | target-local layout |
| func_809DFC84_jp | 0x809DFC84 | 48 | attemptable |
| func_809DFCB4_jp | 0x809DFCB4 | 212 | target-local layout |
| func_809DFD88_jp | 0x809DFD88 | 248 | target-local layout |
| func_809DFE80_jp | 0x809DFE80 | 48 | attemptable |
| func_809DFEB0_jp | 0x809DFEB0 | 256 | attemptable |
| func_809DFFB0_jp | 0x809DFFB0 | 52 | attemptable |
| func_809DFFE4_jp | 0x809DFFE4 | 44 | attemptable |
| func_809E0010_jp | 0x809E0010 | 64 | attemptable |
| func_809E0050_jp | 0x809E0050 | 44 | attemptable |

## Shared layout and API evidence

Existing Actor size 0x174 and NpcActorInfo at 0x174 reused. The remaining prefix
is typed within target unknown storage; do not embed current Npc (size 0x93C)
inside a target whose profile says 0x938. Signedness of flags/steps/requests follows
lbu/sb. Callback stores/calls establish NPC think at 0x7A4, interrupt flags word
0x7A8, schedule 0x7C0, action index/step/object bytes 0x7C5/0x7C6/0x7C9,
action dispatch 0x7D0, request priority/index/type bytes 0x7D4–0x7D6,
head priority/type 0x7E6/0x7E7, head_pos xyz_t 0x7EC, hide request byte 0x7FD,
demo flags word 0x80C, ignore timer word 0x8AC, movement angle s16 0x8DC,
collision check byte 0x911, talk turn byte 0x92B and animation s16 0x92C.
Head position is explicitly stored x/y/z at 0x7EC/0x7F0/0x7F4 in schedule main;
angle is a signed halfword and sin_s/cos_s use that same value. Actor eye/home/
world/shape and mass fields reuse current verified types.
Local tables: action 3 function pointers, think/schedule 2 each; def_angle s16[8],
def_posX/Z f32[7], msg_base s32[6] plus retained zero alignment word. Constructor
record uses existing struct_809AEFA4. Current NpcEvent/mNpc_GetSameEventNpc and
Actor_info_fgName_search signatures cover event actor lookup and name formatting.
Clip +0x104 consumes actor, animation, mode, confirmed by Tamaire_Npc0's audited
NPC initializer/callee (func_809749D0_jp); use a local three-argument function-pointer
cast, leaving the legacy shared four-argument typedef and completed targets intact.
No duplicate shared layout or invented declaration is needed.

## GC cross-check

References src/actor/npc/ac_tukimi_npc0.c, _anime.c_inc and _talk.c_inc.
N64 does not include GC meteor-shower alternate message table/branch. N64 name
buffer uses ANIMAL_NAME_LEN (6), not GC LAND_NAME_SIZE. Preserve these differences.
Established N64 symbol names remain unchanged; correspondences listed below.

- `func_809DFB94_jp` ↔ `aTM0_act_chg_data_proc` (20 bytes).
- `func_809DFB74_jp` ↔ `aTM0_set_request_act` (32 bytes).
- `func_809DFBA8_jp` ↔ `aTM0_act_init_proc` (36 bytes).
- `aTM0_actor_dt` ↔ `aTM0_actor_dt` (44 bytes).
- `aTM0_actor_init` ↔ `aTM0_actor_init` (44 bytes).
- `func_809DFB48_jp` ↔ `aTM0_actor_move` (44 bytes).
- `func_809DFFE4_jp` ↔ `aTM0_talk_init` (44 bytes).
- `aTM0_actor_save` ↔ `aTM0_actor_save` (44 bytes).
- `func_809E0050_jp` ↔ `aTM0_actor_draw` (44 bytes).
- `func_809DFC54_jp` ↔ `aTM0_think_init_proc` (48 bytes).
- `func_809DFE80_jp` ↔ `aTM0_schedule_proc` (48 bytes).
- `func_809DFC84_jp` ↔ `aTM0_think_proc` (48 bytes).
- `func_809DFBCC_jp` ↔ `aTM0_act_proc` (48 bytes).
- `func_809DFB14_jp` ↔ `aTM0_set_animation` (52 bytes).
- `func_809DFFB0_jp` ↔ `aTM0_talk_request` (52 bytes).
- `func_809E0010_jp` ↔ `aTM0_talk_end_chk` (64 bytes).
- `func_809DFBFC_jp` ↔ `aTM0_think_main_proc` (88 bytes).
- `aTM0_actor_ct` ↔ `aTM0_actor_ct` (112 bytes).
- `func_809DFCB4_jp` ↔ `aTM0_schedule_init_proc` (212 bytes).
- `func_809DFD88_jp` ↔ `aTM0_schedule_main_proc` (248 bytes).
- `func_809DFEB0_jp` ↔ `aTM0_set_talk_info` (256 bytes).

N64 signature refinement: set_animation takes only Actor*. Unlike GC, its entry
overwrites a1 without reading it, and act_init spills its unused game argument
before calling with actor alone. Passing game as an invented second argument
removed that spill (score 200); use the N64 one-argument signature.


## Final classification and naming review

21/21 functions matched (1628 instruction bytes + 4 padding bytes). After the
shared target-local prefix recovery and precise animation signature, all functions
were attemptable; no type/prototype/structural/unsafe blockers remain. Current
Actor, NpcActorInfo, NpcEvent, xyz_t, ActorInfo, constructor-record and clip API
definitions reused. The shared Npc/clip definitions and actor size 0x938 are
unchanged. Retained assembly defines all original data/relocations/alignment.

Names preserve established N64 symbols; local GC names actorx, tukimi_npc0_actor,
puleIdx, ang, yRot, worldName, eventNpc, actorRet, looks, msg_p, i, res and
request/think/talk terminology reused. head_pos is the proven request field's
name and local pointer; play names the Game_Play pointer used by NPC callbacks.
No unused trigVal local retained. GC's meteor-shower messages and 8-byte world
name assumption were not copied: N64 uses six-byte names and one message table.
No cosmetic changes to exact function bodies were needed after naming review.
One matching API implementation was consulted: mNpc_GetNpcWorldName handles NULL
NPC pointers and always copies its fallback/name into the output; therefore an
absent Actor_info_fgName_search result does not leave worldName indeterminate.
The initial survey is separate in completion-next-ranking.md; nonselected targets
remain unmodified, with their deferred safety/type audits explicitly labeled.

## Attempts and verification

30 compiled candidates, within 36 total: act_init 2, schedule_init 3,
schedule_main 7 (3 ordinary + 4 focused retries after reaching score 42), all
other 18 functions 1 each. Every retained function passes canonical score zero,
exact linked bytes, full object text/padding and text relocation equality.

- act_init: first score 200 came from passing the GC-style second argument to
  the N64 one-argument animation wrapper, removing its required unused-a1 spill.
- schedule_init: score 120 was only early scheduling of a2/a3 argument setup.
  Using the actor prefix consistently did not help. Confining puleIdx/ang to the
  coordinate-initialization scope preserved the N64 argument instruction order.
- schedule_main: 1656 initially, 42 with explicit head_pos pointer held across
  cos_s. Additional floating temporary experiments scored 76,60,60,80 and were
  rejected (no forcing or unused padding variables). Final candidate uses direct
  sin/cos expressions, a meaningful play local for both NPC callbacks, head_pos
  pointer and yRot; exact stack frame 0x38, angle slot 0x2A, pointer spill 0x24.

Evidence under ignored build/tukimi-npc0/attempt*/. Verifiers executed in place,
not altered. Duplicate forward declarations removed for the final recheck.

| Symbol | Attempts | Final score | Function bytes |
| --- | ---: | ---: | ---: |
| func_809DFB94_jp | 1 | 0 | 20 |
| func_809DFB74_jp | 1 | 0 | 32 |
| func_809DFBA8_jp | 2 | 0 | 36 |
| aTM0_actor_dt | 1 | 0 | 44 |
| aTM0_actor_init | 1 | 0 | 44 |
| func_809DFB48_jp | 1 | 0 | 44 |
| func_809DFFE4_jp | 1 | 0 | 44 |
| aTM0_actor_save | 1 | 0 | 44 |
| func_809E0050_jp | 1 | 0 | 44 |
| func_809DFC54_jp | 1 | 0 | 48 |
| func_809DFE80_jp | 1 | 0 | 48 |
| func_809DFC84_jp | 1 | 0 | 48 |
| func_809DFBCC_jp | 1 | 0 | 48 |
| func_809DFB14_jp | 1 | 0 | 52 |
| func_809DFFB0_jp | 1 | 0 | 52 |
| func_809E0010_jp | 1 | 0 | 64 |
| func_809DFBFC_jp | 1 | 0 | 88 |
| aTM0_actor_ct | 1 | 0 | 112 |
| func_809DFCB4_jp | 3 | 0 | 212 |
| func_809DFD88_jp | 7 | 0 | 248 |
| func_809DFEB0_jp | 1 | 0 | 256 |


## Final build validation

Final canonical verification after declaration cleanup passes score zero, exact
whole-object text/padding, linked bytes and text relocations. Full `make -j4`,
explicit `make compress`, and `git diff --check` pass. Target text plus padding
(1632 bytes), data (192 bytes) and relocations (208 bytes) match the reference
ROM byte-for-byte. Original assembly/data/config inputs are unchanged. Both ROM
hashes pass: `d7ae64f2f47a9fa3f87686a3c5ce09af` and
`a4f7c57c180297b2e7ba5a5feb44fe0b`. Only the chosen source/header, these notes
and the fresh survey belong to this change; existing research edits are preserved.
