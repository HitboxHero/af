# Train0 — current-state audit and partial decompilation

Starting HEAD fb01337 on ai-decomp. Preexisting dirty/untracked research files
are preserved. No Rope/excluded target or GameCube file was modified.

## Exact identity

Source/header: src/overlays/actors/ovl_Train0/ac_train0.{c,h}.
Function ASM: asm/jp/nonmatchings/overlays/actors/ovl_Train0/ac_train0/*.s.
Data/reloc ASM: asm/jp/data/overlays/actors/ovl_Train0/ac_train0{,_reloc}.data.s.
Config: animalforest-jp.yaml:3996; C/data/rodata entries 4004..4006;
relocation entry 4007..4014. Profile Train0_Profile: ACTOR_TRAIN0 0x48,
category 0, flags 0x20000010, fgName 0x580A, GAMEPLAY_KEEP 3, size 0x2D8.
Profile callbacks func_805bfc28/func_805bfcdc/func_805c03ec/func_805c04e0;
no save callback. Established N64 symbol names remain unchanged.

Text ROM [0x8DB2A0,0x8DBE20), VRAM [0x80A0C5E0,0x80A0D160), size 0xB80:
14 functions / 2936 (0xB78) function bytes plus 8 trailing zero padding bytes.
Data ROM [0x8DBE20,0x8DBE50), VRAM [0x80A0D160,0x80A0D190), size 0x30.
Rodata [0x8DBE50,0x8DBE70), VRAM [0x80A0D190,0x80A0D1B0), size 0x20,
including three 0.008f literals, 0.8f, -0.23f, and 12 trailing zero bytes.
BSS zero. Reloc [0x8DBE70,0x8DBF00), VRAM [0x80A0D1B0,0x80A0D240), size 0x90.
Complete ROM overlay range [0x8DB2A0,0x8DBF00), size 0xC60.

## Fresh classification of every function

No functions already matched. Eight are attemptable with current shared
StructureActor/keyframe/actor types (using their verified offsets); six require
local/common fields or callback prototype work. No structural/jump-table or
unsafe/uninitialized-value blocker found. The shared fix unlocks all fourteen.
Final classification: 11 matched; 3 otherwise attemptable, stopped for codegen
at their per-function attempt caps. No remaining type/prototype blocker.

| Address / symbol | Bytes | Initial classification | Final | Attempts |
|---|---:|---|---|---:|
| 80A0C5E0 / func_805bfc28 | 224 | attemptable (verified shared types) | matched | 1 |
| 80A0C6C0 / func_805bfcdc | 228 | local/common fields/types | matched | 1 |
| 80A0C7A4 / func_80A0C7A4_jp | 208 | local/common fields/types + callback prototype | matched | 1 |
| 80A0C874 / func_80A0C874_jp | 284 | effect callback prototype | matched | 4 |
| 80A0C990 / func_80A0C990_jp | 272 | local/common fields/types + callback prototype | assembly; best 1664 | 3 |
| 80A0CAA0 / func_80A0CAA0_jp | 116 | attemptable (verified shared types) | matched | 1 |
| 80A0CB14 / func_80A0CB14_jp | 112 | attemptable (verified shared types) | matched | 1 |
| 80A0CB84 / func_80A0CB84_jp | 60 | attemptable (verified shared types) | matched | 1 |
| 80A0CBC0 / func_80A0CBC0_jp | 208 | attemptable (verified shared types) | assembly; best 10 | 7 |
| 80A0CC90 / func_80A0CC90_jp | 144 | attemptable (verified shared types) | matched | 2 |
| 80A0CD20 / func_80A0CD20_jp | 108 | local/common fields/types | matched | 1 |
| 80A0CD8C / func_80A0CD8C_jp | 196 | local/common fields/types | assembly; best 246 | 3 |
| 80A0CE50 / func_805c03ec | 244 | attemptable (verified shared types) | matched | 1 |
| 80A0CF44 / func_805c04e0 | 532 | attemptable (verified shared types) | matched | 2 |

## Shared types, fields and API evidence

Reuse SkeletonInfoR, FrameControl, s_xyz and existing StructureActor/Train1
common offsets. Train1 and ride-off definitions remain untouched; their action
+2B4 and arg0 +2B8 usage was cross-checked only where relevant. Train0 needs its
own typed unknown storage for saved keyframe, counters and engineer pointer;
it cannot simply alias Train1 (its +2C4 pointer is unknown in Train1). No second
incompatible keyframe/clip/array type was invented.

Train0 stays 0x2D8: s32 keyframe_state +174, SkeletonInfoR keyframe +178,
s32 keyframe_saved_keyframe +1E8, s_xyz work_area[15] +1EC and morph_area[15]
+246; preserve +2A0..2B3 unknown storage. s32 action +2B4, unknown +2B8,
s32 arg1 +2BC (smoke interval), s32 arg2 +2C0 (steam modulo counter),
Actor* arg3 +2C4 (engineer lookup/delete/update), f32 arg0_f +2C8 and arg1_f
+2CC (back-car position/speed). Unknown +2D0..2D7 stays unchanged.
N64 lw/sw, lwc1/swc1, signed comparisons, pointer call usage, constructor
argument addresses and current shared keyframe types prove these accesses.
Pointer typing of arg3 follows actual N64 pointer behavior, avoiding GC's
integer-to-pointer storage casts; arg3 name is established GC terminology.

CommonData types existing storage without shifting anything: u8 train_exists_flag
+10A3F, u8 train_action +10A44, f32 train_speed +10A4C, xyz_t train_position
+10A50. Existing train_coming_flag +10A3E stays intact. N64 byte accesses and
three-float copy verify widths/extent; GameCube corroborates names. N64 copies
train_position.y too (GC only copies x/z). CommonData stays 0x10AB8.

NPC clip +0 is installed as func_80980328_jp by func_8053a354 assembly.
Callee masks name u16, reads idx s8 and arg s16 from o32 stack slots, and uses
integer move-list/block/unit arguments; forwards an integer birth-success return.
Verified signature: s32(Game_Play*,u16,s8,s32,s16,s32,s32,s32,s32).
Type only the existing four bytes as setupActor_proc; next +4 and clip size stay.
GC aNPC_SETUP_ACTOR_PROC corroborates this exact terminology/signature.

Effect pointer common+1009C is Clip +90 (clip base is common+1000C), not Clip
+9C. Its +0 callback is installed as func_80A181B8_jp by func_80A187F8_jp.
Callee saves xyz_t by-value a1/a2/a3, reads priority s32, angle s16, Game*,
item-name u16 and two s16 arguments from the o32 slots. Correct existing
Clip_unk_090_unk_00 typedef to void(s32,xyz_t,s32,s16,Game*,u16,s16,s16).
Preserve established field/type names. An initial failed candidate's wrong clip
slot mapping was corrected before retaining effect C; no change to Clip +9C
survives. No API implementation was modified or external prototype fabricated.

Layout assertions pass for Train0/Train1 sizes, all new Train0 offsets,
CommonData size/train fields, Clip size, NPC callback +0/+4 and effect +0/+4.
Current Game_Play unk_00E4/unk_00E5 are already s8 block coordinates and are
reused without renaming. Existing field, event, matrix, and structure APIs suffice.

## Behavior and GameCube terminology

Read-only GC: src/actor/ac_train0.c, ac_train0_move.c_inc,
ac_train0_draw.c_inc and include/ac_train0.h; directly required NPC/effect API
typedefs. Relevant current Train1 header and ride-off train-field accesses were
cross-checked. No other matching af function implementation was needed.

- func_805bfc28 = aTR0_actor_ct; func_805bfcdc = aTR0_actor_dt
- 80A0C7A4 = aTR0_ctrl_engineer
- 80A0C874 = aTR0_set_effect
- 80A0C990 = aTR0_steam_work_sub
- 80A0CAA0 = aTR0_steam_work
- 80A0CB14/80A0CB84 = calc_speed1/calc_speed2
- 80A0CBC0 = aTR0_ctrl_back_car
- 80A0CC90 = aTR0_animation
- 80A0CD20 = aTR0_move
- 80A0CD8C = aTR0_delcheck
- func_805c03ec/func_805c04e0 = aTR0_actor_move/aTR0_actor_draw

Reuse train0, keyframe/state/saved-keyframe, work_area/morph_area, action,
arg1/arg2/arg3/arg0_f/arg1_f, ac_p, calc, pos, av/cur_frame, speed, graph/keyf/
mtx/object/pal, and common train_* names where proven. Uncertain storage stays
unk_*. Established address-style symbols are unchanged.

Keep N64 differences: constructor animation speed 1 (GC 0.5); actor move animation
speed cap 1 (GC 0.5); back-car integration full arg1_f (GC half), chase 0.005
(GC 0.0025); set common position includes y; dtor removes object/palette/shadow
instances. Draw loads object segment 6 and N64 pal16 TLUT in addition to palette
segment 8; retain exact matrix/display-list ordering. Two f32 X offsets at
D_FLT_80A0D184 are 15/22; two s16 angles D_80A0D18C are -0x3000/0x400.
No union or additional semantic field is evidenced/needed.

## Attempts and remaining exact differences

29 compiled candidates, per-function counts above. Eight first-pass matches;
animation and draw on second; smoke emission on fourth (narrow score 26 after
third qualifies for extension). Eleven new/total matches, 2260/2936 function bytes.
Three original assembly functions totaling 676 bytes remain.

- Deletion check: 1695,246,246. Removing an aggregate position copy fixes much
  of the stack/instruction difference. Best still has x/z stack slots four bytes
  low and uses a0 instead of target v0 for engineer deletion. A pointer temporary
  did not fix allocation. Three ordinary attempts exhausted; no extension.
- Steam subroutine: 1743,1754,1664. Diff includes frame 50 vs 48, position/counter
  stack lifetimes, early counter load/register allocation and aggregate argument
  reload order. Counter initialization/reducing the actor alias did not reach a
  narrow diff. Three ordinary attempts exhausted; no unsafe forcing retained.
- Back-car controller: 1304,10,34,120,34,1270,34. Best candidate's instruction
  body/spill offsets match, but frame is 30 vs target 28. Removing aliases or
  changing scope shifts float spill slots; removing named diff lets IDO simplify
  subtraction<=0 into a different float comparison. Focused attempts varied
  local lifetime, typed actor parameter, explicit f32 expression casts and reused
  zero threshold; none match both arithmetic and stack. Seven-attempt cap hit.

Retained fixes: direct float branching in speed2; typed animation parameter removes
redundant actor alias for original frame 20; draw declaration order puts graph at
sp+68 rather than +6C; smoke's single-use integer cast/local ordering restores
sp+40 position and target temporaries. No forcing or unsafe expressions retained.

All candidate bodies require asm-differ 0, exact linked bytes, complete text/
rodata/padding and effective relocations. Late-rodata named-symbol vs section
HI/LO addends alone are canonicalized by the existing verified tool; final raw
ROM overlay relocation bytes are compared separately. Original assembly/data
files are unmodified. Artifacts/results/diffs: build/train0 (untracked).

Final checks passed: all eleven retained replacements reverified at score 0 on
final source, exact linked bytes/effective object relocations and complete object
text/rodata/padding. Complete ROM range [0x8DB2A0,0x8DBF00), 0xC60 bytes, equals
the base ROM, including retained functions, data, relocation records and padding.
BSS remains zero. git diff --check, full make -j4 and make compress passed.
Decompressed MD5: d7ae64f2f47a9fa3f87686a3c5ce09af.
Compressed MD5: a4f7c57c180297b2e7ba5a5feb44fe0b.
