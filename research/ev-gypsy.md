# ac_ev_gypsy completion (2026-10-29)

Fresh completion-first ranking is recorded separately in ev-gypsy-ranking.md.
No old ranking/spreadsheet was consulted; no excluded/completed target was edited.

## Identity proved before edits

- Source: src/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy.c
- Header: src/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy.h
- Assembly: asm/jp/nonmatchings/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy/
- Data: asm/jp/data/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy.data.s
- Relocation data: same directory, ac_ev_gypsy_reloc.data.s.
- Config: animalforest-jp.yaml:3367 (ovl_Ev_Gypsy), :3377 (relocations).
- Profile: Ev_Gypsy_Profile; actor 0x46 (ACTOR_EV_GYPSY), NPC category 3,
  foreground 0xD00C, GAMEPLAY_KEEP (3), size 0x948, flags zero.
- Text ROM [0x8BFC40,0x8C0260), VRAM [0x809DC450,0x809DCA70).
- Data ROM [0x8C0260,0x8C0320); relocation [0x8C0320,0x8C03E0); no BSS.
- Sixteen functions / 1568 (0x620) bytes; no text padding. Initially two
  matched (88 bytes) and fourteen remaining (1480 bytes), largest 272 bytes.
  The six destiny bytes have two data padding bytes; the process table has
  four final padding bytes. All retained data and padding are checked exactly.

| Symbol | VRAM | Bytes | Initial classification | After fixes / final |
| --- | --- | --- | --- | --- |
| aEGPS_actor_ct | 0x809DC450 | 160 | local fields, ct-data declaration | attemptable / matched |
| aEGPS_actor_save | 0x809DC4F0 | 44 | already matched | unchanged / matched |
| aEGPS_actor_dt | 0x809DC51C | 72 | event prototype | attemptable / matched |
| aEGPS_actor_init | 0x809DC564 | 44 | already matched | unchanged / matched |
| func_809DC590_jp | 0x809DC590 | 120 | string table declaration | attemptable / matched |
| func_809DC608_jp | 0x809DC608 | 220 | local callbacks / message API prototypes | attemptable / matched |
| func_809DC6E4_jp | 0x809DC6E4 | 272 | local fields, tables, message API prototype | attemptable / matched |
| func_809DC7F4_jp | 0x809DC7F4 | 92 | local field / string-helper declaration | attemptable / matched |
| func_809DC850_jp | 0x809DC850 | 48 | callback-table declaration | attemptable / matched |
| func_809DC880_jp | 0x809DC880 | 52 | local fields and callback declarations | attemptable / matched |
| func_809DC8B4_jp | 0x809DC8B4 | 88 | local field | attemptable / matched |
| func_809DC90C_jp | 0x809DC90C | 52 | local callback declaration | attemptable / matched |
| func_809DC940_jp | 0x809DC940 | 80 | local setup callback field | attemptable / matched |
| func_809DC990_jp | 0x809DC990 | 80 | local callback field | attemptable / matched |
| func_809DC9E0_jp | 0x809DC9E0 | 100 | attemptable | matched |
| func_809DCA44_jp | 0x809DCA44 | 44 | attemptable | matched |

No structural, compiler jump-table or unsafe/uninitialized-value blocker
identified in the winner. No draw/matrix implementation remains: the draw
function just forwards to NPC. Four local fields and three verified API
declarations make all fourteen remaining functions attemptable (100%).

## Layout and API evidence

Existing actor-local unknown storage was partitioned only at four verified
word accesses. Actor remains at +0; total size remains 0x948:
- +0x938: s32 talk_action, stored from the setup index and compared with 2.
- +0x93C: Ev_GypsyActionFunc talk_proc, table-selected and called with gypsy/play.
- +0x940: EvGypsyTalkSetupProc setup_talk_proc, called with gypsy/play/action.
- +0x944: s32 fortune_given, assigned 1 after payment and compared with 1.

Existing PrivateInfo fields already cover the required accesses: inventory.wallet
is u32 at +0x38, destiny.type is u8 at +0xA8E, and common_data.privateInfo is
at +0x10138. They were not changed. Temporary compile-time checks confirm
these offsets/types along with actor size and all four tail offsets using
32-bit compilation and N64-compatible scalar alignment.

Declarations refer only to existing assembly symbols:
- D_809DCA94_jp uses the existing 0x1C struct_809AEFA4 constructor-data type.
- D_809DCAB0_jp: four s32 string starts.
- D_809DCAC0_jp / D_809DCACC_jp: three s32 messages / next actions.
- D_809DCAD8_jp / D_809DCAF0_jp: six / five s32 result messages.
- D_809DCB04_jp: six u8 destiny values (0..5), followed by two padding bytes.
- D_809DCB0C_jp / D_809DCB1C_jp: four callback entries each, backed by data.
  The existing generic none_proc1 entries are retained as in the GC callback
  convention. Established N64 symbol names are preserved.

Three existing header placeholders were resolved from direct callee assembly:
- func_8007D42C_jp(void): writes zero to B_8013A0FC_jp, returns without
  setting a result. Declared void(void), preserving the N64-only destructor call.
- func_8009DBA4_jp(MessageWindow*,s32): sw a1,+0x2C4(a0), then return.
  GC counterpart mMsg_Set_continue_msg_num confirms message semantics.
- func_8009E908_jp(MessageWindow*): tests window state at +0x2B4 against 2,
  calls the continuation predicate and returns exactly zero/one. Declared s32;
  GC counterpart mMsg_Check_MainNormalContinue confirms the meaning.

No private/NPC/shared layout was changed. Existing message-window declarations
remain opaque prefixes; no unverified window fields were invented.

## N64 behavior reconstructed before attempts

Constructor checks NPC birth result ==1, invokes NPC ct, sets existing
Actor.unk_144 to 80.0f (GC talk_distance), mass 255, world X +=20.0f, and
installs setup_talk_proc. Actor.unk_144's established af name was retained.
Destructor invokes NPC dt, clears the N64 event flag through func_8007D42C,
and reports actor dying for event 0x40. Init/save/draw are NPC forwards.
Move also returns shape/world yaw toward zero by step 0x400 outside TALK.

The string helper uses a ten-byte char buffer (the N64 APIs accept char*),
selects trunc(fqrand()*32.0f)+string_num[type], loads ten bytes and assigns
that item-string slot. Four direct calls supply only valid string types.

Call-in waits for a normal continue state, initializes type=-1, handles
choice 0 as yes and choice 1 as no, uses the existing unsigned wallet to
select sufficient-funds vs insufficient-funds messages, and only indexes
message/action tables when a recognized choice assigned type 0..2.
No uninitialized choice result or invalid table index was introduced.

Fortune initialization subtracts 50 using defined u32 wallet arithmetic,
sets four random string slots and marks fortune_given=1. The normal state
machine reaches it only after the sufficient-funds branch. Result processing
requires demo order NPC0/9, clears the order, and for the initial fortune
selects trunc(fqrand()*10.0f), clamps values below 4 to 4, then subtracts 4.
That produces indices 0..5 for both destiny and message tables. A repeated
fortune uses existing non-normal destiny.type minus one for its five-message
table, matching the pre-existing destiny-state invariant and GC behavior.
It then returns to TALK_END_WAIT via the installed setup callback.

Setup stores the action, installs its talk callback and calls the matching
entry callback. Talk-info chooses 0x982 if a fortune was just given, else
0x970 for normal destiny and 0x97B otherwise. Talk initialization chooses
CALL_IN or DECIDE_RESULT2 from destiny.type, sets the action and enables
listening. Talk-end always invokes the selected talk callback before checking
whether TALK has ended; its result local is initialized false on every path.

## GameCube parity and final naming review

Corresponding GC ac_ev_gypsy.c, its move include and header agree closely with
the entire N64 logical target. GC terminology was adopted only after N64
field/callback roles were verified. Existing N64 names were not renamed.

| N64 symbol | GC counterpart |
| --- | --- |
| func_809DC590_jp | aEGPS_set_string |
| func_809DC608_jp | aEGPS_call_in |
| func_809DC6E4_jp | aEGPS_decide_result |
| func_809DC7F4_jp | aEGPS_decide_result_init |
| func_809DC850_jp | aEGPS_init_proc |
| func_809DC880_jp | aEGPS_setupAction |
| func_809DC8B4_jp | aEGPS_set_talk_info |
| func_809DC90C_jp | aEGPS_talk_request |
| func_809DC940_jp | aEGPS_talk_init |
| func_809DC990_jp | aEGPS_talk_end_chk |
| func_809DC9E0_jp | aEGPS_actor_move |
| func_809DCA44_jp | aEGPS_actor_draw |

All four field names are exact GC terms. Locals gypsy, play, type, str,
str_no, msg_p, selected, wallet, action, msg_num, next_act_idx and res reuse
corresponding GC names. GC's aEGPS_ACTION_* and aEGPS_STR_TYPE_* enum names
and aEGPS_FORTUNE_PRICE are backed by the same N64 values. The order-value
temporary demo_order was eliminated to match N64 stack allocation; no new
synonym was substituted. N64 types and ten-byte string size remain authoritative.
Final naming review found no unnecessary AI-invented synonym to replace.
No matching code was restructured for cosmetic similarity.

## Attempts and verification

Used workspace copies of research/tools/attempt_candidate.py and unchanged
verification dependencies under build/ev-gypsy/tools/ with an original-object
baseline. Smallest-first attempts: draw, entry dispatcher, setup, talk request,
destructor, talk init/end, message selection, fortune init, move, string helper,
constructor, call-in and result processing.

Twelve functions passed their first attempt. String helper first scored 55:
only temporary allocation and the final add operands differed. Reversing the
commutative sum's source operands matched N64 allocation on attempt two.
Result processing first scored 70: all instructions except stack offsets
matched. Removing the single-use demo_order local and testing the API result
directly produced the target 0x20 frame on attempt two. No padding variable,
register/volatile forcing, assembly, guessed field or uninitialized value used.

Total 16 candidate attempts. All fourteen replacements pass score 0, exact
linked function bytes, identical whole-object text/padding and exact object
text relocation offsets/types/symbol values/targets. Final verification repeats
these checks for all fourteen after the naming review. Two original matching
functions remain unchanged and are covered by the whole-object comparison.
All data/profile/callback and relocation tables remain in assembly.

Result: 14 newly matched / 16 total functions; 1480 new / 1568 total function
bytes, no remaining blockers. Full build/compression/overlay/hash checks follow.

Final PASS: layout checks, all fourteen final exact verifications,
git diff --check, full make and make compress. Entire overlay
[0x8BFC40,0x8C03E0) exactly matches original text/data/relocations/padding.
Both requested ROM hashes PASS:
d7ae64f2f47a9fa3f87686a3c5ce09af (decompressed),
a4f7c57c180297b2e7ba5a5feb44fe0b (compressed).
