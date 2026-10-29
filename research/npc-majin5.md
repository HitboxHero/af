# npc_majin5 (2026-10-29)

## Exact identity, verified before editing

- Source: src/overlays/actors/ovl_Npc_Majin5/ac_npc_majin5.c
- Header: src/overlays/actors/ovl_Npc_Majin5/ac_npc_majin5.h
- Assembly: asm/jp/nonmatchings/overlays/actors/ovl_Npc_Majin5/ac_npc_majin5/
- Data/relocations: asm/jp/data/overlays/actors/ovl_Npc_Majin5/
  ac_npc_majin5.data.s and ac_npc_majin5_reloc.data.s.
- YAML: animalforest-jp.yaml:17842, ovl_Npc_Majin5 and relocation segment.
- Actor/profile: ACTOR_NPC_MAJIN5 (0xB1), ACTOR_PART_NPC (3),
  foreground 0xD06B, GAMEPLAY_KEEP (3), Npc_Majin5_Profile, size 0x938.
- Text ROM [0x96CCF0,0x96D1B0), VRAM [0x80AACB80,0x80AAD040).
  Data [0x96D1B0,0x96D1F0), relocation [0x96D1F0,0x96D250); no BSS.
- Thirteen functions: 1212 (0x4BC) function bytes and 4 text padding bytes
  at ROM 0x96D1AC / VRAM 0x80AAD03C. Initially one matched function (36
  bytes), twelve remaining functions (1176 bytes). No old ranking used.

| Symbol | VRAM | Bytes | Initial classification | After shared fixes / final |
| --- | --- | --- | --- | --- |
| aNMJ5_actor_ct | 0x80AACB80 | 284 | target fields, effect ABI, ct-data declaration | attemptable / matched |
| aNMJ5_actor_save | 0x80AACC9C | 36 | already matched | unchanged / matched |
| aNMJ5_actor_dt | 0x80AACCC0 | 72 | effect callback prototype | attemptable / matched |
| aNMJ5_actor_init | 0x80AACD08 | 44 | attemptable | matched |
| func_80AACD34_jp | 0x80AACD34 | 156 | request layout/signature | attemptable / matched |
| func_80AACDD0_jp | 0x80AACDD0 | 128 | event-save field/signature | attemptable / matched |
| func_80AACE50_jp | 0x80AACE50 | 16 | attemptable | matched |
| func_80AACE60_jp | 0x80AACE60 | 116 | target fields, animation ABI | attemptable / matched |
| func_80AACED4_jp | 0x80AACED4 | 72 | local callback declarations | attemptable / matched |
| func_80AACF1C_jp | 0x80AACF1C | 64 | think callback field/signature | attemptable / matched |
| func_80AACF5C_jp | 0x80AACF5C | 108 | attemptable | matched |
| func_80AACFC8_jp | 0x80AACFC8 | 72 | local callback declarations | attemptable / matched |
| func_80AAD010_jp | 0x80AAD010 | 44 | attemptable | matched |

No structural, jump-table or unsafe/uninitialized-value blocker found in
any function. Two-case switches compile to branches, not computed tables.
Shared local layouts and callback declarations made all twelve remaining
functions attemptable (100%), satisfying the continuation condition.

## N64 reconstruction and type evidence

The generic af Npc type is 0x93C, larger than this actor's verified 0x938.
It was not embedded or changed. Existing actor-local unknown storage was
partitioned only at verified accesses, keeping unknown gaps and size 0x938:

| Offset | Type / name | Evidence |
| --- | --- | --- |
| 0x1AC | AnimationMode main_animation_mode | sw 1; established ANIMATION_REPEAT; GC frame-control mode |
| 0x7A4 | think_proc | address stored by schedule init; three-argument dispatcher |
| 0x7C0 | schedule_proc | address stored by constructor; three-argument dispatcher |
| 0x7C5 | u8 action_idx | sb zero in think init; GC action.idx |
| 0x7D4 | u8 request.act_priority | lbu comparison, sb prio |
| 0x7D5 | u8 request.act_idx | sb idx |
| 0x7D6 | u8 request.act_type | sb type |
| 0x7D7 | unknown byte | preserved as padding/unknown |
| 0x7D8 | u16 request.act_args[6] | 12-byte zero/copy, sh argument slots |
| 0x7FD | u8 hide_request | sb zero in think init |
| 0x80C | u32 demo_flg | sw all bits set; NPC core bit tests and GC u32 bitmask |
| 0x85E | u8 umbrella_disabled_flag | sb 1 |
| 0x8AC | s32 palActorIgnoreTimer | sw signed -1 timer sentinel |
| 0x911 | u8 check_kind | sb zero |

NpcMajin5Request models only the accessed 0x10-byte prefix; it is not a
claim about the entire generic NPC request structure. NpcMajin5EventSave
models only two unknown bytes and u16 bitfield at +2 (accessed extent 4),
not a guessed full event payload. All new callback/data declarations are
backed by existing N64 instructions or data words.

Request ABI: lbu reads prio/idx/type from the low bytes of a1/a2/a3 slots;
lhu reads obj from argument 4, lh reads signed move_x/move_z from arguments
5/6. Result is s32 0/1. It zeroes all six u16 args, assigns slots 0/2/3,
updates request metadata only when priority permits, and copies all 12 bytes.
Every copied byte is initialized. The save-area deletion branch is guarded
by a NULL check before the bitfield is read; clearing and deletion happen
only for bit 0x2000. Shape rotation uses existing Actor.shape.rot.y; shadow
suppression uses existing drawShadow, not a guessed actor field.

Constructor checks birth result ==1, installs schedule_proc and calls NPC
ct via existing clip slot 0xC0 with existing struct_809AEFA4 data type.
D_80AAD064_jp is backed by two callback words, schedule type 4, and four
zero words (0x1C bytes) at 0x80AAD064. It then sets NPC flags/sentinels,
places world X at home X-80.0f and Z at home Z+480.0f, and makes effect
0x5E at that position with priority 3, angle 31000, item 0xFFFF and zero
extra args. Destructor invokes NPC dt then kills that same effect/item.
Think init sets MASS_HEAVY, unhides, requests wait at priority 4, initializes
animation 0x4E, and sets ANIMATION_REPEAT. Schedule init installs the think
dispatcher and calls NPC think with N64 index 8/type 0; main checks type 1
and falls back to type 2 only if the result is zero. GC's index 9 was not copied.

Directly required NPC/effect callback assembly established the actual ABIs:
- NPC clip initialization (func_8053a354.s) maps slot +0x104 to
  func_809749D0_jp. That callee consumes a0/a1/a2, never an incoming a3;
  GC's aNPC_ANIMATION_INIT_PROC is also void(ACTOR*,int,int). Existing af's
  legacy slot typedef expects four arguments. A target-local verified
  NpcMajin5AnimationInitProc conversion calls the real three-argument ABI
  without changing other matching users of the legacy declaration.
- NPC clip +0x110 maps to func_8097E7F4_jp; its 0/1/2 selector and return
  value agree with the existing s32 four-argument declaration.
- Effect initializer func_80A187F8_jp publishes actor+0x174 at
  common_data+0x1009C, so the correct field is Clip.unk_090 (common Clip
  begins at +0x1000C). Slots 0/4 map to func_80A181B8_jp / func_80A18344_jp.
  The make ABI is void(s32,xyz_t,s32,s16,Game*,u16,s16,s16): callee saves
  aggregate words and reads the signed halfword angle/args, u16 item and
  game pointer from their exact ABI slots. A target-local correct type
  converts the existing approximate make callback declaration.
  Kill consumes s32 effect ID and masks a1 to u16. Its typed field replaces
  exactly four bytes of existing Clip_unk_090.unk_04 storage; following
  fields and modeled size 0x40 are preserved. Clip_unk_09C was not changed.

The first destructor candidate mistakenly used Clip.unk_09C (offset
common_data+0x100A8). The score-5 diff exposed that arithmetic mistake;
it was corrected to the verified +0x1009C mapping before retaining code.

Temporary 32-bit compile-time layout checks, with N64-compatible 8-byte
aggregate scalar alignment, pass for every offset above, actor size 0x938,
request prefix size 0x10, effect clip size 0x40/kill slot +4, and effect
clip global offset +0x1009C. Checks/logs are under build/npc-majin5/.

## GameCube correspondence and naming review

Only the corresponding GC actor, schedule include and headers were used for
behavior/terminology, plus directly required NPC/effect APIs and their types.
No already-matching af reference function was needed. No excluded target was
revisited or edited; all pre-existing research-log edits were preserved.

| N64 address-style name | GameCube counterpart |
| --- | --- |
| func_80AACD34_jp | aNMJ5_set_request_act |
| func_80AACDD0_jp | aNMJ5_actor_move |
| func_80AACE50_jp | aNMJ5_think_main_proc |
| func_80AACE60_jp | aNMJ5_think_init_proc |
| func_80AACED4_jp | aNMJ5_think_proc |
| func_80AACF1C_jp | aNMJ5_schedule_init_proc |
| func_80AACF5C_jp | aNMJ5_schedule_main_proc |
| func_80AACFC8_jp | aNMJ5_schedule_proc |
| func_80AAD010_jp | aNMJ5_actor_draw |

Existing N64 symbols and Actor field names remain. Corresponding locals
actorx, play, majin5_actor, majin, save_area, res, args, prio, idx, type,
obj, move_x, move_z, think_proc_idx and sched_idx reuse GC terminology.
Request metadata, think_proc, schedule_proc, hide_request, demo_flg,
umbrella_disabled_flag, palActorIgnoreTimer and check_kind also reuse GC
names only at verified offsets. main_animation_mode and action_idx flatten
verified GC field paths because the intervening N64 structures are not yet
modeled. Unknown bytes stay neutral. Effect kill uses effect_kill_proc.
Final naming review found no unnecessary AI synonym requiring a rename;
no matching implementation was restructured for cosmetic similarity.

## Attempts and exact verification

Used workspace copies of research/tools/attempt_candidate.py and dependencies
under build/npc-majin5/tools/ with an isolated original object baseline.
The verifier is unchanged; no relaxation of byte, relocation or padding checks.

Smallest-first: empty, actor init, draw, schedule init, destructor, think
switch, schedule switch, schedule main, think init, move, request, constructor.
Ten functions matched on their first attempt. Destructor: score 5 then 0
following the effect-offset correction. Constructor: score 300 then 0 after
the verified demo_flg type became u32. The initial signed type made IDO reuse
one -1 constant for two fields; the correct unsigned bitmask yields the two
separate materializations in the target. NPC core accesses to +0x80C use
andi bit tests (e.g. func_8097703C_jp and func_80977A00_jp), corroborating
GC's u32 declaration. No register/volatile forcing was used.

Total 14 candidate attempts. All 12 replacements require asm-differ score 0,
exact linked bytes, identical whole-object text/padding, and exact object text
relocation offsets/types/symbol values/targets. Final re-verification of all
12 replacements against the original baseline follows the naming review.
The existing save callback is unchanged and covered by the whole-object
comparison. Profile/constructor data and relocation data remain assembly.
Final result: 12 newly matched / 13 total; 1176 new / 1212 total function bytes;
4 text padding bytes exact; no remaining blockers.

Full build/compression/hash and complete-overlay results recorded below.

Final PASS: all twelve final exact verifications, layout checks,
git diff --check, full make and make compress. Entire overlay range
[0x96CCF0,0x96D250) exactly matches original text/data/relocations/padding.
ROM MD5 d7ae64f2f47a9fa3f87686a3c5ce09af and compressed MD5
a4f7c57c180297b2e7ba5a5feb44fe0b both PASS.
