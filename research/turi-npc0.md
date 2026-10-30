# Turi_Npc0 — 2026-10-30

## Identity before edits

Source/header: `src/overlays/actors/ovl_Turi_Npc0/ac_turi_npc0.c` / `.h`.
Assembly: `asm/jp/nonmatchings/overlays/actors/ovl_Turi_Npc0/ac_turi_npc0/`.
Data/BSS: `asm/jp/data/overlays/actors/ovl_Turi_Npc0/ac_turi_npc0.{data,bss}.s`.
Config: `animalforest-jp.yaml:3560`, `ovl_Turi_Npc0`.
ROM text [0x8C6390,0x8C6B80), VRAM [0x809E2BA0,0x809E3390).
Data ROM [0x8C6B80,0x8C6C50), BSS VRAM [0x809E3460,0x809E3480).
Separate reloc segment ROM [0x8C6C50,0x8C6D80).
Profile `Turi_Npc0_Profile` at 0x809E3394, actor ID 0x92,
part NPC (3), flags zero, item zero, object 3, instance size 0x940.
Constructor `func_805900b0`, destructor `func_805901d8`, update
`aTR0_actor_init`, draw `none_proc1`, save `aTR0_actor_save`.
All 25 functions initially GLOBAL_ASM: 2032 function bytes, zero text padding.

## Classification before edits

No structural/jump-table or unsafe/uninitialized-value blockers found.
Dispatches use explicit data function-pointer tables, not compiler jump tables.
Existing clip slots BC/C0/C4/C8/CC/D0/E4/104/110 and tool/demo/message APIs
cover the calls. Target-local fields are still unknown storage in the header.
After recovering this shared layout all functions are attemptable (100%).

| Symbol | VRAM | Bytes | Initial classification |
| --- | --- | ---: | --- |
| func_805900b0 | 0x809E2BA0 | 228 | target-local layout blocked |
| aTR0_actor_save | 0x809E2C84 | 44 | attemptable |
| func_805901d8 | 0x809E2CB0 | 100 | attemptable |
| aTR0_actor_init | 0x809E2D14 | 44 | attemptable |
| func_809E2D40_jp | 0x809E2D40 | 64 | attemptable |
| func_809E2D80_jp | 0x809E2D80 | 44 | attemptable |
| func_809E2DAC_jp | 0x809E2DAC | 32 | target-local layout blocked |
| func_809E2DCC_jp | 0x809E2DCC | 100 | target-local layout blocked |
| func_809E2E30_jp | 0x809E2E30 | 52 | target-local layout blocked |
| func_809E2E64_jp | 0x809E2E64 | 132 | target-local layout blocked |
| func_809E2EE8_jp | 0x809E2EE8 | 20 | target-local layout blocked |
| func_809E2EFC_jp | 0x809E2EFC | 36 | target-local layout blocked |
| func_809E2F20_jp | 0x809E2F20 | 40 | target-local layout blocked |
| func_809E2F48_jp | 0x809E2F48 | 48 | attemptable |
| func_809E2F78_jp | 0x809E2F78 | 88 | target-local layout blocked |
| func_809E2FD0_jp | 0x809E2FD0 | 48 | target-local layout blocked |
| func_809E3000_jp | 0x809E3000 | 48 | attemptable |
| func_809E3030_jp | 0x809E3030 | 236 | target-local layout blocked |
| func_809E311C_jp | 0x809E311C | 120 | target-local layout blocked |
| func_809E3194_jp | 0x809E3194 | 48 | attemptable |
| func_809E31C4_jp | 0x809E31C4 | 256 | attemptable |
| func_809E32C4_jp | 0x809E32C4 | 52 | attemptable |
| func_809E32F8_jp | 0x809E32F8 | 44 | attemptable |
| func_809E3324_jp | 0x809E3324 | 64 | attemptable |
| func_809E3364_jp | 0x809E3364 | 44 | attemptable |

## Layout reconstruction

Only existing unknown target storage is typed. Actor remains at 0, size 0x174;
NpcActorInfo at 0x174 reuses its current verified definition. Main animation state
is loaded as a word at 0x188, loop flag as unsigned byte at 0x72B. Callback
stores/calls prove think proc 0x7A4 (three arguments), interrupt flags 0x7A8,
schedule proc 0x7C0 (three arguments), action index/step/object bytes
0x7C5/0x7C6/0x7C9, action dispatch proc 0x7D0 (three arguments), request bytes
0x7D4/0x7D5/0x7D6, demo flags word 0x80C, hide request byte 0x7FD,
right-hand actor pointer 0x860, palActorIgnoreTimer word 0x8AC, movement angle
halfword 0x8DC, collision check byte 0x911, talk turn byte 0x92B/default animation
halfword 0x92C, action index word 0x938, act_proc pointer 0x93C (one argument).
Unused gaps remain unknown. Read/write-only words have no inferred signedness
beyond their demonstrated integer use; pointers and callbacks follow callsites.
Action dispatch table has 3 pointers, think/schedule 2 each; action process,
animation number/base/random tables 1 each; angles are s16[5][7]; message bases
s32[6]; BSS actor list uses 5 pointers with 12 bytes trailing retained storage.
The current generic Npc header still has unknown storage at these offsets;
it is not enlarged, repurposed, or changed. Target size remains 0x940.

## N64 ↔ GameCube correspondences

GameCube references: `src/actor/npc/ac_turi_npc0.c`, `_anime.c_inc`, `_move.c_inc`.
N64 has no GC animation-speed extension: only animation_init_proc is called.
Established N64 symbols are preserved. The names below establish terminology;
constants are the N64 values from assembly/data, not copied GC numeric enums.

- `func_809E2EE8_jp` ↔ `aTR0_act_chg_data_proc` (20 bytes).
- `func_809E2DAC_jp` ↔ `aTR0_set_request_act` (32 bytes).
- `func_809E2EFC_jp` ↔ `aTR0_act_init_proc` (36 bytes).
- `func_809E2F20_jp` ↔ `aTR0_act_main_proc` (40 bytes).
- `aTR0_actor_save` ↔ `aTR0_actor_save` (44 bytes).
- `aTR0_actor_init` ↔ `aTR0_actor_init` (44 bytes).
- `func_809E2D80_jp` ↔ `aTR0_actor_move` (44 bytes).
- `func_809E32F8_jp` ↔ `aTR0_talk_init` (44 bytes).
- `func_809E3364_jp` ↔ `aTR0_actor_draw` (44 bytes).
- `func_809E2F48_jp` ↔ `aTR0_act_proc` (48 bytes).
- `func_809E2FD0_jp` ↔ `aTR0_think_init_proc` (48 bytes).
- `func_809E3000_jp` ↔ `aTR0_think_proc` (48 bytes).
- `func_809E3194_jp` ↔ `aTR0_schedule_proc` (48 bytes).
- `func_809E2E30_jp` ↔ `aTR0_wait` (52 bytes).
- `func_809E32C4_jp` ↔ `aTR0_talk_request` (52 bytes).
- `func_809E2D40_jp` ↔ `aTR0_set_animation` (64 bytes).
- `func_809E3324_jp` ↔ `aTR0_talk_end_chk` (64 bytes).
- `func_809E2F78_jp` ↔ `aTR0_think_main_proc` (88 bytes).
- `func_805901d8` ↔ `aTR0_actor_dt` (100 bytes).
- `func_809E2DCC_jp` ↔ `aTR0_make_npc_sao` (100 bytes).
- `func_809E311C_jp` ↔ `aTR0_schedule_main_proc` (120 bytes).
- `func_809E2E64_jp` ↔ `aTR0_setupAction` (132 bytes).
- `func_805900b0` ↔ `aTR0_actor_ct` (228 bytes).
- `func_809E3030_jp` ↔ `aTR0_schedule_init_proc` (236 bytes).
- `func_809E31C4_jp` ↔ `aTR0_set_talk_info` (256 bytes).

## Final implementation and naming review

All 25 functions reclassified attemptable after the target-local header recovery,
then matched: zero remaining type/prototype, structural, or unsafe blockers.
No shared NPC/clip/tool declarations or layouts changed. Data and BSS definitions
remain in their original assembly; extern declarations refer to those verified
symbols, sizes and element types. The owner cast at the existing ToolBirthProc API
boundary adapts the current af declaration; it does not read a ToolActor field.

GC terminology reused: actor, action, sao_actor, ret, idx, i, pool_idx, angle,
msg_p, str, looks; main_animation_state, loop_flag, schedule_proc, think_proc,
interrupt_flags, step, act_obj, act_priority, act_idx, act_type, hide_request,
demo_flg, item_actor_p, palActorIgnoreTimer, mv_angl, check_kind, turn,
default_animation and act_proc. Flattened action_idx/action_act_proc distinguish
the NPC action record from target-local action/act_proc. Established N64 symbol
names and constants are preserved; no GC-only frame-speed behavior added.
Naming review found no unsupported semantic synonym requiring replacement.
Duplicate forward declarations were removed without restructuring function bodies.

## Attempts and exact verification

26 compiled candidates: 24 functions passed first try, setupAction passed second
try. Its first score was 18: multiply operand order and the shared index spill at
sp+0x1C instead of sp+0x18. Changing only `table[action] * fqrand()` to
`fqrand() * table[action]` produced the exact operand order and stack lifetime.
No forcing, padding locals, undefined reads or inline assembly used.
Every accepted function passed the canonical attempt tool: score zero, exact linked
bytes, complete object text/padding equality and exact text relocation comparison.
Evidence is under ignored `build/turi-npc0/attempt*/`; canonical verifier tools
were executed in place, not altered.

| Symbol | Attempts | Final score | Bytes |
| --- | ---: | ---: | ---: |
| func_809E2EE8_jp | 1 | 0 | 20 |
| func_809E2DAC_jp | 1 | 0 | 32 |
| func_809E2EFC_jp | 1 | 0 | 36 |
| func_809E2F20_jp | 1 | 0 | 40 |
| aTR0_actor_save | 1 | 0 | 44 |
| aTR0_actor_init | 1 | 0 | 44 |
| func_809E2D80_jp | 1 | 0 | 44 |
| func_809E32F8_jp | 1 | 0 | 44 |
| func_809E3364_jp | 1 | 0 | 44 |
| func_809E2F48_jp | 1 | 0 | 48 |
| func_809E2FD0_jp | 1 | 0 | 48 |
| func_809E3000_jp | 1 | 0 | 48 |
| func_809E3194_jp | 1 | 0 | 48 |
| func_809E2E30_jp | 1 | 0 | 52 |
| func_809E32C4_jp | 1 | 0 | 52 |
| func_809E2D40_jp | 1 | 0 | 64 |
| func_809E3324_jp | 1 | 0 | 64 |
| func_809E2F78_jp | 1 | 0 | 88 |
| func_805901d8 | 1 | 0 | 100 |
| func_809E2DCC_jp | 1 | 0 | 100 |
| func_809E311C_jp | 1 | 0 | 120 |
| func_809E2E64_jp | 2 | 0 | 132 |
| func_805900b0 | 1 | 0 | 228 |
| func_809E3030_jp | 1 | 0 | 236 |
| func_809E31C4_jp | 1 | 0 | 256 |


## Final build validation

Final canonical verification after declaration cleanup passes score 0, whole-object
text/padding, linked function bytes and text relocation comparison. `git diff
--check`, full `make -j4`, and explicit `make compress` pass. Text (2032 bytes),
data (208 bytes) and the relocation segment (304 bytes) compare byte-for-byte to
the reference ROM. Original BSS size/alignment and all assembly/data inputs remain
unchanged; no text padding exists. Both expected ROM MD5 hashes pass:
`d7ae64f2f47a9fa3f87686a3c5ce09af` and
`a4f7c57c180297b2e7ba5a5feb44fe0b`.
Only the Turi_Npc0 source/header and these notes belong to this change.
