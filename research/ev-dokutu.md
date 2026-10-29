# ev_dokutu (2026-10-29)

## Exact identity, verified before edits

- Source: src/overlays/actors/ovl_Ev_Dokutu/ac_ev_dokutu.c
- Header: src/overlays/actors/ovl_Ev_Dokutu/ac_ev_dokutu.h
- Function assembly: asm/jp/nonmatchings/overlays/actors/ovl_Ev_Dokutu/ac_ev_dokutu/
- Data/relocations: asm/jp/data/overlays/actors/ovl_Ev_Dokutu/
  ac_ev_dokutu.data.s and ac_ev_dokutu_reloc.data.s.
- Config: animalforest-jp.yaml:17920 (ovl_Ev_Dokutu), :17930 (relocations).
- Profile: Ev_Dokutu_Profile, actor 0xB3 (ACTOR_EV_DOKUTU), NPC category 3,
  flags zero, foreground 0xD06C, GAMEPLAY_KEEP (3), instance size 0x94C.
- Text ROM [0x96EB20,0x96F210), VRAM [0x80AAE9C0,0x80AAF0B0).
- Data [0x96F210,0x96F290), relocation data [0x96F290,0x96F360); no BSS.
- 23 functions / 1776 (0x6F0) function bytes; no text padding. Three already
  matched functions account for 124 bytes; twenty remaining total 1652 bytes.
  Largest remaining function is 160 bytes. Counts were recomputed from actual
  function assembly, source definitions, profile pointers and text boundaries.

| Function | VRAM | Bytes | Initial classification | After shared fixes / final |
| --- | --- | --- | --- | --- |
| aEVD_actor_ct | 0x80AAE9C0 | 140 | target-local fields/callback declarations | attemptable / matched |
| aEVD_actor_save | 0x80AAEA4C | 36 | already matched | unchanged / matched |
| aEVD_actor_dt | 0x80AAEA70 | 44 | already matched | unchanged / matched |
| aEVD_actor_init | 0x80AAEA9C | 44 | already matched | unchanged / matched |
| func_80AAEAC8_jp | 0x80AAEAC8 | 156 | request layout and ABI | attemptable / matched |
| func_80AAEB64_jp | 0x80AAEB64 | 44 | attemptable | matched |
| func_80AAEB90_jp | 0x80AAEB90 | 32 | local callback field/table | attemptable / matched |
| func_80AAEBB0_jp | 0x80AAEBB0 | 96 | message table type/local declarations | attemptable / matched |
| func_80AAEC10_jp | 0x80AAEC10 | 76 | flag field/callback declaration | attemptable / matched |
| func_80AAEC5C_jp | 0x80AAEC5C | 96 | message table type/local declarations | attemptable / matched |
| func_80AAECBC_jp | 0x80AAECBC | 76 | flag field/callback declaration | attemptable / matched |
| func_80AAED08_jp | 0x80AAED08 | 64 | NPC talk-request field type | attemptable / matched |
| func_80AAED48_jp | 0x80AAED48 | 124 | local callback/next-state fields | attemptable / matched |
| func_80AAEDC4_jp | 0x80AAEDC4 | 64 | action fields/local callback | attemptable / matched |
| func_80AAEE04_jp | 0x80AAEE04 | 44 | hide-request field/local declaration | attemptable / matched |
| func_80AAEE30_jp | 0x80AAEE30 | 56 | request declaration | attemptable / matched |
| func_80AAEE68_jp | 0x80AAEE68 | 64 | signed coordinate fields/request declaration | attemptable / matched |
| func_80AAEEA8_jp | 0x80AAEEA8 | 160 | state table/local fields and callback tables | attemptable / matched |
| func_80AAEF48_jp | 0x80AAEF48 | 72 | local declarations | attemptable / matched |
| func_80AAEF90_jp | 0x80AAEF90 | 64 | think-proc field/local declaration | attemptable / matched |
| func_80AAEFD0_jp | 0x80AAEFD0 | 108 | attemptable | matched |
| func_80AAF03C_jp | 0x80AAF03C | 72 | local declarations | attemptable / matched |
| func_80AAF084_jp | 0x80AAF084 | 44 | attemptable | matched |

No structural/jump-table or unsafe/uninitialized-value blocker identified.
The callback tables are ordinary data, not compiler-generated jump tables;
two-case dispatchers use direct branches. Shared local types/declarations
made all twenty remaining functions attemptable (100%), satisfying the
continuation condition. No shared helper or unrelated target was changed.

## Verified layouts, declarations and N64 reconstruction

Kept Actor at offset zero; partitioned only existing unknown storage in
Ev_Dokutu. Its size remains exactly 0x94C. Unaccessed bytes stay unknown.
The generic NPC layout was not substituted for the target's verified storage.

| Offset | Verified type/name | N64 evidence |
| --- | --- | --- |
| 0x7A4 | think_proc | stored three-argument dispatcher, NPC think API |
| 0x7C0 | schedule_proc | stored three-argument dispatcher in constructor |
| 0x7C5 | u8 action_idx | lbu compared against zero |
| 0x7C6 | u8 action_step | lbu compared against 0xFF |
| 0x7D4 | request.act_priority, u8 | lbu priority comparison / sb |
| 0x7D5 | request.act_idx, u8 | sb argument 2 |
| 0x7D6 | request.act_type, u8 | sb argument 3 |
| 0x7D7 | unknown byte | preserved |
| 0x7D8 | request.act_args[6], u16 | 12-byte copy; halfword slots 0/2/3 |
| 0x7FD | hide_request, u8 | sb zero during think initialization |
| 0x85E | umbrella_disabled_flag, u8 | sb 1 in constructor |
| 0x8AC | palActorIgnoreTimer, s32 | sw signed -1 sentinel |
| 0x91C | talk_request_proc | NPC request callback replaced by state setup/talk init |
| 0x938 | unk_938, callback | table-selected; invoked after action-end/wait check |
| 0x93C | unk_93C, callback | table-selected; invoked by talk-end check |
| 0x942/0x944 | unk_942/unk_944, s16 | lh into request move_x/move_z arguments |
| 0x946/0x947 | unk_946/unk_947, u8 | current index / table-derived next index |
| 0x949 | unk_949, u8 | message-table index |
| 0x94A | unk_94A, u8 | constructor clears; state setup sets; request callback clears |

The request type models only the accessed 0x10-byte prefix, not a guessed
complete NPC request structure. The first callback argument ABI is Actor*;
the think/schedule dispatchers also take Game_Play* and s32 selector. Existing
ActorFunc and DemoRequestFunc conventions are used for their respective
callback tables. The existing generic none_proc1 symbol remains a no-op
callback in the retained N64 data; its integer result is not consumed.

State/data declarations are backed directly by existing assembly objects:
- D_80AAF0D4_jp: seven words, represented by existing struct_809AEFA4. Its
  move/draw/talk callbacks, schedule value 4 and zero flags are retained data.
- D_80AAF0F0_jp / D_80AAF114_jp: one callback each.
- D_80AAF0F4_jp / D_80AAF0FC_jp: one 8-byte record each. Word +0 goes to
  mDemo_Set_msg_num, byte +4 selects the callback index, byte +5 is turn,
  byte +6 is camera. Unused byte +7 stays unknown. Messages are 0x7DD/0x831;
  no GC message constant was copied over N64 values.
- D_80AAF104_jp: three 5-byte records and one padding byte. Stride 5 is
  established by index*4+index. Record bytes select callbacks at +0/+1/+2,
  message index at +3, and next state at +4. Field names remain neutral.
- D_80AAF118_jp / D_80AAF124_jp: three callbacks each, kept in assembly.

Request setter accepts u8 priority/index/type (lbu from low ABI slots), u16
object (lhu) and s16 move_x/move_z (lh). It initializes all six u16 args via
bzero before assignment/copy, returns zero when priority is insufficient,
and otherwise copies twelve initialized bytes and returns one.

Constructor installs schedule_proc before NPC ct, then disables umbrella,
sets the ignore timer to -1, and clears unk_94A. Move/draw are ordinary NPC
clip forwards. Think init sets existing MASS_HEAVY and clears hide_request
before entering state 0. Think main invokes the selected callback only when
NPC action step is 0xFF or action index is zero. Request action variants
select wait (4,0,0,0,0,0) or the N64 action tuple (4,2,3,0,move_x,move_z).

State setup narrows selector to u8, stores it, reads all five record bytes,
installs the state callback and talk request, stores message/next-state
indices, invokes the entry callback and finally sets unk_94A. Dialogue
request wrappers suppress one request after a state change, otherwise
request SPEAK (8) or TALK (7). Their callback applies message/turn/camera
then installs the selected talk callback. Talk init replaces the NPC talk
request with the no-op, enables listening, starts the demo, and returns one.
Talk-end invokes the selected callback first; it advances state and returns
one only when both SPEAK and TALK checks are zero, otherwise returns zero.
The result variable is initialized on every path.

Schedule init installs the think dispatcher and calls NPC think with N64
index 8/type 0. Main checks type 1 and calls type 2 only on a zero result.
Both think and schedule dispatchers have exactly two direct cases.

Compile-time layout checks passed for every offset, actor size 0x94C,
request prefix 0x10, dialogue records 8 and state records 5. Temporary checks
and logs are under build/ev-dokutu/. No unrelated API/type layout changed.

## GameCube terminology and final naming review

Read corresponding GC src/actor/npc/event/ac_ev_dokutu.c, its talk include,
and ac_ev_dokutu.h; directly required NPC actor definitions supplied request,
action, think, schedule, umbrella and timer terminology. GC's actor is much
simpler and has no counterpart for most N64 state-table machinery. It also
uses message 0x3146 and a different constructor setup. Those behaviors,
constants and layouts were not imported into N64.

| N64 symbol | Demonstrated GameCube role |
| --- | --- |
| func_80AAEB64_jp | aEVD_actor_move |
| func_80AAF084_jp | aEVD_actor_draw |
| func_80AAECBC_jp | aEVD_talk_request, with N64 state-change suppression |
| func_80AAEBB0_jp / func_80AAEC5C_jp | N64 variants of aEVD_set_talk_info |
| func_80AAED08_jp | aEVD_talk_init, with additional N64 demo start |
| func_80AAED48_jp | aEVD_talk_end_chk, with N64 callbacks/state transition and SPEAK check |

Established N64 names are preserved. Locals actorx, play, res, args, prio,
idx, type, obj, move_x and move_z use corresponding actor/NPC terminology.
The explicit play local adapts the game argument used by NPC callbacks.
Request fields reuse act_priority/act_idx/act_type/act_args. Verified generic
NPC fields reuse think_proc, schedule_proc, hide_request,
umbrella_disabled_flag, palActorIgnoreTimer and talk_request_proc. The flat
action_idx/action_step names express GC action.idx/action.step without
inventing an unverified enclosing layout. State-specific fields/callbacks
remain unk_* because GC does not establish their descriptive names.
Message payload names msg_no, turn and camera follow the directly invoked
APIs; unused bytes stay neutral. Final naming review found no unsupported
AI synonyms to replace, and matching code was not cosmetically restructured.

Only the directly required none_proc1 definition was read as an already-
matching helper; no other matching reference body was needed. ac-decomp
was read-only. No known blocked target was revisited; all pre-existing
research log edits remain untouched and outside the target commit.

## Attempt budget and exact verification

Used workspace copies of research/tools/attempt_candidate.py and its
unchanged dependencies under build/ev-dokutu/tools/ with an original object
baseline. Twenty functions were attempted smallest-first (32, 44, 56, 64,
72, 76, 96, 108, 124, 140, 156, 160-byte size groups).
Nineteen replacements passed their first attempt. The talk-end check
func_80AAED48_jp first scored 46: all non-stack instructions matched, but
its frame was 0x28/res at sp+0x20 rather than target 0x30/res at sp+0x24.
An explicit Game_Play* play local for the game argument produced the target
frame and passed attempt two at score zero. No padding variable, forcing
qualifier, assembly or uninitialized value was used.

Total: 21 candidate attempts. All twenty replacements require score 0,
exact linked bytes, exact whole-object text/padding and identical object
text relocation offsets/types/symbol values/targets. Final verification of
all twenty repeats those checks after the naming review. The three original
matching functions are unchanged and covered by whole-object comparisons.
All profile/data tables/relocation data remain original assembly.

Result: 20 newly matched / 23 total functions; 1652 new / 1776 total function
bytes. No remaining blockers. Text padding is zero; the state-table padding
byte is retained exactly. Full build/compression/ROM checks follow below.

Final PASS: layout checks, all twenty final exact verifications,
git diff --check, full make and make compress. Complete overlay
[0x96EB20,0x96F360) matches original text/data/relocation data/padding.
MD5 d7ae64f2f47a9fa3f87686a3c5ce09af (decompressed) and
a4f7c57c180297b2e7ba5a5feb44fe0b (compressed): both PASS.
