# ev_miko — current-state audit and partial decompilation

Starting HEAD 224b8a2 on ai-decomp. GameCube was read-only. Existing dirty research
logs are preserved. No tunahiki_npc0 or unrelated actor source was read/changed.

## Identity and exact boundaries

- Source/header: `src/overlays/actors/ovl_Ev_Miko/ac_ev_miko.{c,h}`.
- Function ASM: `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Miko/ac_ev_miko/*.s`.
- Data/BSS/reloc ASM: `asm/jp/data/overlays/actors/ovl_Ev_Miko/ac_ev_miko{.data,.bss,_reloc.data}.s`.
- Config: `animalforest-jp.yaml:3619`, C/data/BSS at 3627..3629;
  relocation entry at 3630..3637.
- Ev_Miko_Profile: ACTOR_EV_MIKO 0x84, NPC category 3, flags 0, fgName 0xD03D,
  GAMEPLAY_KEEP 3, size 0x948; ctor/dtor/init/none_proc1/save callbacks.
  Destructor sends event-3 actor-dying message: New Year's Day, matching GC.
- Text ROM [0x8C8F10,0x8C9A30), VRAM [0x809E5740,0x809E6260), size 0xB20.
  22 functions / 2848 bytes, zero text padding.
- Data ROM [0x8C9A30,0x8C9AC0), VRAM [0x809E6260,0x809E62F0), size 0x90.
- No rodata. BSS at 0x809E62F0, size 0x10; first ten bytes are used by the
  string loader, trailing six bytes are preserved unknown/padding storage.
- Reloc ROM [0x8C9AC0,0x8C9BB0), VRAM [0x809E6300,0x809E63F0), size 0xF0.
  Entire ROM overlay range [0x8C8F10,0x8C9BB0) is 0xCA0 bytes.

## Every-function classification

Fresh baseline: 2 already matched; 10 immediately attemptable; 10 target-local
layout blocked, with ctor/talk-end also blocked on clip +10C prototype.
No structural, jump-table, unsafe or uninitialized-value blockers found.
The shared local layout/prototype fix unlocks all 20 remaining functions.
Final: 20 matched; 2 otherwise attemptable routines stopped for codegen at budget.

| Address / symbol | Bytes | Baseline | Final | Attempts |
|---|---:|---|---|---:|
| 809E5740 / aEMK_actor_ct | 264 | target-local fields/types + clip prototype | matched | 1 |
| 809E5848 / aEMK_actor_save | 44 | already matched | matched | 0 |
| 809E5874 / aEMK_actor_dt | 64 | attemptable | matched | 1 |
| 809E58B4 / aEMK_actor_init | 44 | already matched | matched | 0 |
| 809E58E0 / func_809E58E0_jp | 156 | target-local fields/types | matched | 1 |
| 809E597C / func_809E597C_jp | 72 | attemptable | matched | 1 |
| 809E59C4 / func_809E59C4_jp | 208 | attemptable | assembly, best 10 | 3 |
| 809E5A94 / func_809E5A94_jp | 232 | attemptable | matched | 1 |
| 809E5B7C / func_809E5B7C_jp | 72 | attemptable | matched | 2 |
| 809E5BC4 / func_809E5BC4_jp | 308 | attemptable | assembly, best 15 | 5 |
| 809E5CF8 / func_809E5CF8_jp | 248 | attemptable | matched | 1 |
| 809E5DF0 / func_809E5DF0_jp | 176 | target-local fields/types | matched | 1 |
| 809E5EA0 / func_809E5EA0_jp | 256 | target-local fields/types | matched | 3 |
| 809E5FA0 / func_809E5FA0_jp | 68 | target-local fields/types | matched | 1 |
| 809E5FE4 / func_809E5FE4_jp | 48 | attemptable | matched | 1 |
| 809E6014 / func_809E6014_jp | 52 | target-local fields/types | matched | 1 |
| 809E6048 / func_809E6048_jp | 60 | target-local fields/types | matched | 1 |
| 809E6084 / func_809E6084_jp | 64 | target-local fields/types | matched | 1 |
| 809E60C4 / func_809E60C4_jp | 44 | attemptable | matched | 1 |
| 809E60F0 / func_809E60F0_jp | 216 | target-local fields/types + clip prototype | matched | 1 |
| 809E61C8 / func_809E61C8_jp | 108 | target-local fields/types | matched | 2 |
| 809E6234 / func_809E6234_jp | 44 | attemptable | matched | 1 |

## Shared layout and prototype resolution

EvMikoNpc is a target-local 0x938-byte prefix typed from existing unknown storage.
Shared Npc size/fields remain unchanged. Ev_Miko remains exactly 0x948.
N64 lbu/sb verify action_idx +7C5; priority/index/type +7D4/+7D5/+7D6;
request args at +7D8 are six u16 (12-byte bzero/copy), obj at +0, move_x/z
halfwords at +4/+6. Signature: actor*, u8 prio/idx/type, u16 obj, s16 move_x/z;
argument signedness is visible in lbu/lhu/lh loads from o32 argument slots.
Ctor sb verifies hide_flg +7FC and collision-check kind +911; sw -1 verifies
palActorIgnoreTimer +8AC. Private data: s32 talk_action +938, callback +93C,
s32 omikuji +940, u8 in_front +944. Remaining bytes stay unknown.
Callback calls and state tables establish Actor*/Game_Play* arguments and
four-byte pointer stride. No guessed NPC fields or global storage are introduced.

NPC initialization assembly func_8053a354 installs func_809774A0_jp at clip +10C.
That callee consumes a0 Actor*, a1/a2 as f32 coordinates, stores +8BC/+8C0,
then updates movement. GC set_dst_pos_proc corroborates void return and roles.
Type the existing four bytes at +10C as Clip_unk_040_unk_10C, splitting old
unk_108[8] without shifting +110 or changing size. Caller asm in ctor and
end-check confirms the ABI. Existing event, message, choice, private, mail,
handbill and string APIs suffice; no fabricated API declarations.

Compile-time assertions passed for actor/prefix sizes, every accessed field,
clip +10C/+110, Mail_c size 0xA4 and header/body/footer +2A/+34/+94,
PrivateInfo wallet +38, mail +40A, destiny.type +A8E; existing types preserved.
All assembly data/BSS stay in place. Cost table is four s32 at 809E62A0,
item table four u16 at 809E62B0; string-index table four s32 at 809E62B8;
destiny table four u8 at 809E62C8. Init/process tables each four pointers;
last data word is preserved padding. B_809E62F0 uses ten verified bytes only.

## GameCube terminology / correspondence

Read-only GC: src/actor/npc/event/ac_ev_miko.c and ac_ev_miko_move.c_inc,
include/ac_ev_miko.h. No other matching af actor implementations were needed.

809E58E0 = aEMK_set_request_act; 809E597C = aEMK_mail_free_space;
809E5BC4 = aEMK_get_omikuji; 809E5CF8 = aEMK_talk_select;
809E5DF0 = aEMK_talk_omikuji; 809E5EA0 = aEMK_talk_give;
809E5FA0 = aEMK_talk_omikuji_init; 809E5FE4 = aEMK_init_proc;
809E6014 = aEMK_setupAction; 809E6048 = aEMK_set_talk_info;
809E6084 = aEMK_talk_request; 809E60C4 = aEMK_talk_init;
809E60F0 = aEMK_talk_end_chk; 809E61C8 = aEMK_actor_move;
809E6234 = aEMK_actor_draw. Local N64 money routines 809E59C4/5A94/5B7C
provide the roles GC calls mSP_money_check/mSP_get_sell_price.

Retain all established N64 symbols. Reuse miko, actorx, play, arg_data, ret,
order, mail, idx and demonstrated talk_action/talk_proc/omikuji/in_front terms;
NPC prefix uses GC request/hide/pal-actor/collision terminology. Existing af
wallet, mail content and destiny names remain authoritative. B_809E62F0 maps
to GC pf_string. N64 omikuji string selection uses 0x2C1 + idx directly;
GC's kekka_table permutation is absent and was not copied. N64 profile flags
remain zero despite GC differences.

## Attempts, precise remaining codegen, and retained work

30 compiled candidates total. 15 new functions matched first-pass. Payment and
move matched on second attempt; give-mail matched on third: 18 new / 20 total,
2244 new / 2332 total function bytes. Remaining assembly totals 516 bytes.
Every retained replacement requires score 0, exact object relocations, complete
object text/padding and exact linked function bytes; no equivalence-only pass.

Payment: initialize money from wallet, then subtract price, preserving a1 reuse.
Move: the first candidate lacked macros.h and emitted an implicit ABS call;
including the existing verified ABS macro fixed it. Constructor and request
helper matched directly from the reconstructed N64 layout/signatures.
Give-mail: extra cast pointer local enlarged frame to 0xD0 (mail +24);
removing that alias yields original frame 0xC8 and mail +20. No forcing used.

Money check 809E59C4: 3 attempts; scores 10, 796, 1458. Best candidate differs
only in end-pointer symbol: target uses HI/LO(D_809E62B0), C uses
HI(D_809E62A0)/LO(D_809E62A0+0x10), two physically equal addresses. Required
score/relocation identity was not met; no verifier relaxation. Explicit table
boundary/index and pointer traversals worsened register/control-flow selection.
No candidate retained. First candidate and exact diff are in results JSON/artifacts.

Mail generation 809E5BC4: 5 attempts; scores 15, 39, 39, 54, 50. First candidate
has original frame 0x58 and header_back_start +54, but uses table t6/random t8
where target uses table t8/random t7. Reversing addition operands fixes those
registers but shrinks frame to 0x50/header +4C; splitting load_idx and moving
addition into call or using a table-index temporary did not match both properties.
All changes were focused expression/temporary/lifetime factors. No C retained.
Five attempts are within the ordinary three plus narrow-below-100 extension.
Stop at total budget 30; original assembly and data remain untouched.

Build/attempt/diff/layout verification artifacts: build/ev-miko (untracked).

Final verification: all 18 retained replacements rechecked at score 0 with exact
object relocation offset/type/symbol/addend records, complete object text/padding,
and linked function bytes. Full overlay ROM [0x8C8F10,0x8C9BB0) matches the base
byte-for-byte, including retained functions, data, relocation records and padding.
BSS remains NOBITS size 0x10/alignment 16, linked at 0x809E62F0.
git diff --check, full make -j4, and make compress passed.
MD5 decompressed: d7ae64f2f47a9fa3f87686a3c5ce09af.
MD5 compressed: a4f7c57c180297b2e7ba5a5feb44fe0b.
