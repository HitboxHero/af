# train1 — fresh audit and complete decompilation

Starting HEAD 151a15b on ai-decomp. Existing dirty research files are preserved.
No excluded target or ac-decomp file was modified. No changes to Train0 code/layout.

## Identity, profile and boundaries

Source/header: `src/overlays/actors/ovl_Train1/ac_train1.{c,h}`.
Function ASM: `asm/jp/nonmatchings/overlays/actors/ovl_Train1/ac_train1/*.s`.
Data/reloc ASM: `asm/jp/data/overlays/actors/ovl_Train1/ac_train1{,_reloc}.data.s`.
Config: `animalforest-jp.yaml:4016`, C/data/rodata at 4024..4026;
reloc entry 4027..4034. Train1_Profile: ACTOR_TRAIN1 0x49, category 0,
flags 0x20000010, fgName 0x580B, GAMEPLAY_KEEP 3, size 0x2D8.
Ctor/dtor/move/draw callbacks, no save callback.

Text ROM [0x8DBF00,0x8DC690), VRAM [0x80A0D240,0x80A0D9D0), size 0x790:
11 functions / 1936 bytes, zero text padding. Data [0x8DC690,0x8DC720),
VRAM [0x80A0D9D0,0x80A0DA60), size 0x90, including 8 trailing zero bytes.
Rodata [0x8DC720,0x8DC730), VRAM [0x80A0DA60,0x80A0DA70), size 0x10:
four float literals, including two separate 0.008f values. BSS size zero.
Reloc [0x8DC730,0x8DC7D0), VRAM [0x80A0DA70,0x80A0DB10), size 0xA0.
Complete ROM overlay [0x8DBF00,0x8DC7D0) is 0x8D0 bytes.

## Every-function classification

Initially zero matched; four immediately attemptable using current actor,
StructureActor, sound/event/collision APIs; seven target-local layout blocked.
Passenger control additionally needs the player callback declaration/layout.
No structural/jump-table or unsafe/uninitialized-value blockers found.
Resolving the shared layouts unlocks all eleven; final classification all matched.

| Address / symbol | Bytes | Initial classification | Final | Attempts |
|---|---:|---|---|---:|
| 80A0D240 / aTR1_actor_ct | 160 | target-local fields/types | matched | 1 |
| 80A0D2E0 / aTR1_actor_dt | 196 | target-local fields/types | matched | 1 |
| 80A0D3A4 / func_80A0D3A4_jp | 48 | attemptable | matched | 1 |
| 80A0D3D4 / func_80A0D3D4_jp | 112 | attemptable | matched | 1 |
| 80A0D444 / func_80A0D444_jp | 60 | target-local fields/types | matched | 2 |
| 80A0D480 / func_80A0D480_jp | 216 | attemptable | matched | 4 |
| 80A0D558 / func_80A0D558_jp | 156 | attemptable | matched | 1 |
| 80A0D5F4 / func_80A0D5F4_jp | 276 | target-local fields/types + player callback | matched | 1 |
| 80A0D708 / func_80A0D708_jp | 292 | target-local fields/types | matched | 2 |
| 80A0D82C / aTR1_actor_move | 164 | target-local fields/types | matched | 2 |
| 80A0D8D0 / aTR1_actor_draw | 256 | target-local fields/types | matched | 1 |

## Existing definitions reused and shared layout resolution

Current Train1 action s32 +2B4 and arg0 s32 +2B8 were already verified by
ac_ride_off_demo; preserve both names/types/offsets, size 0x2D8. Read only that
actor's demonstrated train lookup, action==5 and arg0=1/0 usage to corroborate.
No duplicate Train1/clip definitions or changes to ride-off code.

Type existing unknown Train1 storage: keyframe_state s32 +174 (play result),
SkeletonInfoR keyframe +178 (size 70), work_area s_xyz[15] +1EC,
morph_area s_xyz[15] +246. Existing StructureActor and keyframe API provide the
verified common capacity/offsets; ctor N64 argument addresses independently
confirm them. Preserve unknown +1E8 and +2A0..2B3 storage, not guessed fields.
arg1 s32 +2BC is loaded and compared to 1; arg0_f f32 +2C8 is initialized to
1, compared during action setup and cleared by move; arg1_f f32 +2CC supplies
speed. Preserve all remaining unknown storage. No union is needed/evidenced.
Signed integer terminology is corroborated by GC's common STRUCTURE_ACTOR.

Train0 accesses use existing StructureActor fields unk_2B4/unk_2C8/unk_2CC at
the exact N64 parent offsets. Reuse their verified types rather than inventing
or modifying a separate Train0 layout. GC corroborates those as action,
arg0_f/arg1_f. Parent linkage/player existence are actor lifecycle invariants;
no new uninitialized values or unchecked paths were introduced.

Player +123C is installed by func_808DD398_jp as func_808B606C_jp. That callee
accepts Game*, nullable const xyz_t*, nullable const s_xyz*, u8 flags: it masks
a3 to eight bits, reads three floats/three signed halfwords and conditionally
stores forced position/angles. GC Set_force_position_angle_proc corroborates
name/void result. Replace only four bytes of existing unk_123C[8], retain
unk_1240[4]; Player remains 0x12D8, next verified getEndPos remains +1244.
Train1 callsite flags are 0x2E and 0x0E, with NULL rotation in second branch.
D_8010F4AC_jp's first three halfwords are zero; declare only the accessed
s_xyz prefix, preserving existing symbol/storage. No duplicate global definition.

Compile-time assertions passed for Train1 size and every new/accessed offset,
existing StructureActor parent offsets, Player size, callback and next field.
All APIs already declared except typing that existing callback storage.
Asset D_60857F0 is the existing segmented linker symbol passed as BaseSkeletonR*.
Animation table D_80A0DA00 has two four-byte pointers; D_FLT_80A0DA08 two f32;
D_80A0DA10 nine s32 indices; D_FLT_80A0DA34 nine f32 speeds plus eight preserved
zero padding bytes. Doorway position D_80A0D9F4 is xyz_t, three f32 words.

## GameCube naming parity and N64 differences

Read-only GC: src/actor/ac_train1.c, ac_train1_move.c_inc,
ac_train1_draw.c_inc; include/ac_train1.h and required player callback definition.
N64 symbols retained. Correspondence:

- 80A0D3A4 = aTR1_OngenTrgStart
- 80A0D3D4 = calc_speed1
- 80A0D444 = calc_speed2
- 80A0D480 = aTR1_position_move
- 80A0D558 = aTR1_chg_station_attr
- 80A0D5F4 = aTR1_passenger_ctrl
- 80A0D708 = aTR1_setupAction

Reused train1/train0, keyframe/keyframe_state, work_area/morph_area,
action/arg0/arg1/arg0_f/arg1_f, tr_back_calc/base_x_pos/diff, pos/rot,
anime_pt/seq_no/speed/end/tr_speed, graph/keyf/mtx/pal. Existing parent
StructureActor unk_* names remain established af names. Naming review required
no cosmetic restructuring or further identifier changes.

Keep proven N64 differences: position advances by full speed (GC uses half);
chase delta 0.005 (GC 0.0025); arg1 passenger x is unchanged (GC +2);
action 4/6 animation speed table is 1.0 (GC 0.5). Dtor additionally removes
object/palette/shadow instances; draw sets both object segment 6 and palette 8.
Do not copy GC flags or omit N64 segment setup.

## Exact matching process

17 compiled attempts: seven first-pass matches; speed2/move/action setup two
attempts each; position move four, within below-100 narrow-diff extension.
Speed2 first score 800 arose specifically from storing the floating comparison
as an integer Boolean; direct float branches match. Move first score 10 was
comparison operand order. Action setup first 90 had frame 48 vs 50 and spills
four bytes low; Actor* parameter plus used derived-pointer local restores ABI
stack layout. Necessary caller pointer typing change was reverified exact.
Position initial score 10 was frame 38 vs 30; narrowing local lifetime then
left only float spills four bytes low (24). Declaring parent after the float
locals gives original frame 30, base +24 and tr_back_calc +28. No padding,
register/volatile forcing, assembly, UB workaround or cosmetic restructuring.

Draw specifically verified object/palette call order, graph allocation cursor,
mtx lifetime at sp+24, display-list cursor load/update, segment 6/8 ordering,
and keyframe call arguments. First attempt matched complete 0x100-byte function.
Reference af patterns limited to Lotus ctor/move/draw segment/keyframe usage
(three matching functions); no unrelated blocked implementation was used.

All eleven replacements pass asm-differ 0, exact linked bytes, complete object
text/rodata/padding and effective object relocations. Late-rodata verifier
canonicalizes only named-literal versus .rodata-section HI/LO addends; remaining
relocation offsets/types/symbols/addends are compared exactly. Original data
and relocation assembly remain unchanged; final raw overlay comparison checks
the actual linked relocation payload. Artifacts: build/train1 (untracked).

Final verification passed for all eleven functions on the final source. Entire
ROM overlay [0x8DBF00,0x8DC7D0), including text, data, all four rodata constants,
raw relocation records and padding, equals the base ROM byte-for-byte. BSS stays
zero-sized. git diff --check, full make -j4 and make compress passed.
Decompressed MD5: d7ae64f2f47a9fa3f87686a3c5ce09af.
Compressed MD5: a4f7c57c180297b2e7ba5a5feb44fe0b.
