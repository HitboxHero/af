# Fresh target ranking and ac_tunahiki_control completion

2026-10-29, ai-decomp. Inventory was regenerated from current source GLOBAL_ASM
references and assembly nonmatching sizes, without using old rankings. All user
exclusions were filtered before ranking. Search window: 400–2500 remaining
function bytes. Source function definitions plus assembly functions give totals.
No excluded target was edited. Existing research logs are left untouched.

Cheap survey counts below distinguish a conservative immediately-ready lower
bound from full type/signature reconstruction. A low bound does not mean all
other functions are impossible. No unsafe behavior was identified in this cheap
survey; only the winner received a complete control-flow/value audit. No
computed jump-table transfer was found in these candidates. NPC callbacks and
action arrays are ordinary function-pointer dispatch, not jump-table blockers.
Priority favors a tractable complete unit inside the 24-attempt budget over
larger units requiring pervasive NPC layouts or broad API research.

| Rank / target | Total | Remaining | Bytes | Matched | Ready lower bound | Largest | Type/prototype work | Shared local fix |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1. ac_tunahiki_control | 5 | 5 | 520 | 0 | 0 → 5 | 292 | actor tail, save payload, two event API signatures | yes, small and verified |
| 2. ac_broker_design | 7 | 5 | 728 | 2 | 0 | 264 | 8-byte clip interface, local signatures, foreground API | yes; clip plus global payload |
| 3. ac_ride_off_demo | 15 | 13 | 1104 | 2 | 0 | 164 | 0x18 actor tail, action signatures, player APIs | yes; several fields |
| 4. ac_npc_majin5 | 13 | 12 | 1176 | 1 | 1 | 284 | NPC base, callbacks, actor tail/event data | partly; NPC dependencies |
| 5. ac_ev_dokutu | 23 | 20 | 1652 | 3 | 0 | 160 | NPC base, actor tail, action signatures | partly; many callbacks |
| 6. ac_ev_gypsy | 16 | 14 | 1480 | 2 | 2 | 272 | NPC base/tail, dialogue and event prototypes | partly |
| 7. ac_train1 | 11 | 11 | 1936 | 0 | 1 | 292 | skeleton/structure layout and state callbacks | yes; also draw work |
| 8. 720B20 | 7 | 6 | 1044 | 1 | 0 | 440 | instrument state and many audio signatures | not one clear local fix |
| 9. ac_hanabi_npc1 | 28 | 25 | 2120 | 3 | 3 | 328 | NPC base/tail and callbacks; 25 attempts minimum | partly |
| 10. ac_turi_npc0 | 25 | 25 | 2032 | 0 | 4 | 256 | NPC base/tail and callbacks; 25 attempts minimum | partly |
| 11. ovl_Npc_Majin | 25 | 25 | 2096 | 0 | 1 | 276 | NPC base/tail, callbacks/player APIs; 25 attempts minimum | partly |
| 12. ac_ev_artist | 25 | 23 | 2284 | 2 | 3 | 260 | NPC base/tail, dialogue/event APIs; 23 attempts minimum | partly |

Paths and cheap blocker status (zero observed structural/unsafe blockers is not a proof for unselected units):

- `src/overlays/actors/ovl_Tunahiki_Control/ac_tunahiki_control.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Tunahiki_Control/ac_tunahiki_control/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Broker_Design/ac_broker_design.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Broker_Design/ac_broker_design/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Ride_Off_Demo/ac_ride_off_demo.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ride_Off_Demo/ac_ride_off_demo/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Npc_Majin5/ac_npc_majin5.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Npc_Majin5/ac_npc_majin5/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Ev_Dokutu/ac_ev_dokutu.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Dokutu/ac_ev_dokutu/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Train1/ac_train1.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Train1/ac_train1/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/code/720B20.c`; assembly `asm/jp/nonmatchings/code/720B20/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Hanabi_Npc1/ac_hanabi_npc1.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Hanabi_Npc1/ac_hanabi_npc1/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Turi_Npc0/ac_turi_npc0.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Turi_Npc0/ac_turi_npc0/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Npc_Majin/ovl_Npc_Majin.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Npc_Majin/ovl_Npc_Majin/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.
- `src/overlays/actors/ovl_Ev_Artist/ac_ev_artist.c`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Artist/ac_ev_artist/`; structural: none observed; unsafe/uninitialized: none identified, unselected functions remain unverified.

## Winner identity, proved before edits

- Source: src/overlays/actors/ovl_Tunahiki_Control/ac_tunahiki_control.c
- Header: src/overlays/actors/ovl_Tunahiki_Control/ac_tunahiki_control.h
- Function assembly directory: asm/jp/nonmatchings/overlays/actors/ovl_Tunahiki_Control/ac_tunahiki_control/
- Data: asm/jp/data/overlays/actors/ovl_Tunahiki_Control/ac_tunahiki_control.data.s
- Config: animalforest-jp.yaml:15866, ovl_Tunahiki_Control plus relocation entry.
- Text ROM [0x951A70,0x951C80), VRAM [0x80A91800,0x80A91A10).
- Data [0x951C80,0x951CB0), rodata [0x951CB0,0x951CC0), relocation
  [0x951CC0,0x951D10). No BSS; actor/profile size exactly 0x17C.
- Five functions, 520 (0x208) bytes, plus 8 text padding bytes after setup.
  Data contains the profile and one-element callback table with trailing
  padding. Rodata has three floats and 4 padding bytes.

| Function | VRAM | Bytes | Before shared fixes | After fixes / final |
| --- | --- | --- | --- | --- |
| func_80A919E8_jp | 0x80A919E8 | 32 | local type/signature | attemptable / matched |
| aTNC_actor_move | 0x80A918A0 | 36 | local callback field | attemptable / matched |
| aTNC_actor_dt | 0x80A91874 | 44 | API prototype | attemptable / matched |
| aTNC_actor_ct | 0x80A91800 | 116 | local/save types, API prototype | attemptable / matched |
| func_80A918C4_jp | 0x80A918C4 | 292 | save type/signature | attemptable / matched |

No initial matches. After shared fixes 5/5 (100%) attemptable. Zero structural,
jump-table or unsafe/uninitialized-value blockers in the winner.

## Shared evidence and reconstruction

Actor tail: setup stores a1 (s32 action index) at +0x178 and a callback loaded
from D_80A91A34_jp[action] at +0x174. Move invokes that callback with original
actor and Game_Play pointers. Replaced existing unknown 8 bytes with the
existing Tunahiki_ControlActionFunc and s32 action; retained total size 0x17C.
The table declaration is backed by the existing one-word assembly table.

Save payload: ctor/update instructions establish f32 at +0/+4/+8, halfword
stores at +0x10/+0x12/+0x14, and an unsigned halfword counter at +0x16.
+0x12 is loaded unsigned and tested with masks 0x8000 and 0x3E0. +0x0C stays
unknown storage. The local type records an accessed extent of 0x18, not an
invented allocator size. Names are behavioral labels cross-checked against GC;
no unobserved GC field at +0x0C was adopted.

Directly required API assembly in asm/jp/code/6A0DE0.s:
- func_80080080_jp: a0 event index, a1 masked to 8 bits; returns a pointer
  to a 0x28-byte memset-zeroed save payload or NULL. Declared u8*(s32,u8),
  consistent with the existing mEv_get_save_area byte-storage API. N64
  return paths at 0x800801E0..0x800801EC prove pointer/NULL result.
- func_800814B8_jp: a0 event, a1 Actor pointer: reads fgName (+6) and world
  position (+0x28..+0x30), records actor state, and sets event status. Its
  behavioral API is void(s32,Actor*); no result is consumed by the target.
  Added prototypes to existing m_event.h placeholders, with Actor forward tag.

Update: save->flags selects +/-0.3f from Game_Play.unk_1EA0 bit 0. Without
NPC-talk bits, adds speed*0.05f to ropeBase, clamps to [-10,10] and zeros
speed when clamped. A second save lookup receives ropeBase+shake. Unsigned
counter increments and wraps at 37 to 1. N64 uses 0.05f and 37/1; GC's
0.025f and 65/2 were explicitly not copied. Constructor initializes save
storage only if absent, then always installs action 0. Reserve API zeros
payload; update reads no uninitialized fields. Callback lifecycle assumes
successful event-save allocation as in the original game; no new unsafe
operations or recovery behavior introduced.

Smallest-first attempts used workspace copies of research/tools/
attempt_candidate.py and dependencies under build/tunahiki-control/tools/.
Setup, move, destructor, constructor each passed first attempt with score 0,
exact linked bytes, object text/relocations/padding. Update's first C
candidate also scored 0. Two verification reruns were required: original
verifier compared named float symbols against IDO .rodata section relocations
without accounting for REL addends. No C adjustments were made for update.
The final verifier resolves HI16/LO16 pairs in relocation-record order to
section offsets, requires identical offsets/types/effective targets, compares
text with only those literal relocation addends normalized, and compares raw
rodata including padding. All non-rodata relocations remain compared exactly.
It also verifies linked function and migrated constant bytes against assembly.
The .late_rodata preamble is excluded from the text instruction count, not
from constant-byte checks. Full overlay relocation bytes are checked separately.
Seven attempt-tool invocations total (5 distinct C candidates, 2 verifier reruns).
All five functions retained at score 0; no remaining function blockers.
No graphics implementation or matching reference function was needed.

Final build/hash and complete overlay checks recorded below after completion.

Final validation PASS: git diff --check; full make; make compress.
Complete overlay [0x951A70,0x951D10) matches original text, data, rodata,
relocation data and all padding exactly. All function linked bytes are exact.
MD5 d7ae64f2f47a9fa3f87686a3c5ce09af (decompressed) and
a4f7c57c180297b2e7ba5a5feb44fe0b (compressed): both PASS.
