# ac_ride_off_demo — current-state audit and completion

Branch: ai-decomp; starting HEAD cf190fb. GameCube tree was read-only.

## Identity and boundaries

Source/header: `src/overlays/actors/ovl_Ride_Off_Demo/ac_ride_off_demo.{c,h}`.
Function assembly: `asm/jp/nonmatchings/overlays/actors/ovl_Ride_Off_Demo/ac_ride_off_demo/*.s`.
Data/BSS and relocation assembly: `asm/jp/data/overlays/actors/ovl_Ride_Off_Demo/ac_ride_off_demo{.data,.bss,_reloc.data}.s`.
Config: `animalforest-jp.yaml:2198` ovl_Ride_Off_Demo, relocation entry at 2210.
Profile: Ride_Off_Demo_Profile, ACTOR_RIDE_OFF_DEMO (0x17), category 7,
flags 0x20000010, fgName 0, GAMEPLAY_KEEP (3), instance size 0x18C.
Text ROM [0x848600,0x848AD0), VRAM [0x80953820,0x80953CF0).
15 functions / 1224 bytes, plus 8 trailing zero text-padding bytes.
Data ROM [0x848AD0,0x848B30), rodata [0x848B30,0x848B40),
BSS at 0x80953D60 size 0x10; relocation ROM [0x848B40,0x848BF0).
B_80953D60_jp uses the verified 8-byte DemoClip prefix; trailing BSS stays intact.

## Fresh classification versus historical audit

Historical commit 4feb048 labeled all 13 remaining functions type-blocked.
The target source/header and relevant actor/demo/Train1 definitions were unchanged
between that audit and starting HEAD. Player API addition func_800B5B1C_jp and
other shared clip/common-data additions did not resolve this target's unknown slots.
Fresh classification: two already matched, ten local/shared-layout blocked,
three prototype-only blocked (8095388C, 80953B30, 80953C24); no structural,
jump-table, unsafe, or uninitialized-value blockers. Thus there was no relevant
preexisting unblock; this session resolved the shared issue, unlocking all 13.

| Address | Symbol | Bytes | Initial classification | Final | Attempts |
|---|---|---:|---|---|---:|
| 80953820 | aROD_actor_ct | 68 | missing/unverified fields/types | matched | 1 |
| 80953864 | aROD_actor_dt | 40 | missing/unverified fields/types | matched | 1 |
| 8095388C | func_8095388C_jp | 64 | prototype/declaration | matched | 1 |
| 809538CC | func_809538CC_jp | 68 | missing/unverified fields/types | matched | 1 |
| 80953910 | func_80953910_jp | 100 | missing/unverified fields/types | matched | 3 |
| 80953974 | func_80953974_jp | 88 | missing/unverified fields/types | matched | 3 |
| 809539CC | func_809539CC_jp | 120 | missing/unverified fields/types | matched | 1 |
| 80953A44 | func_80953A44_jp | 164 | missing/unverified fields/types | matched | 2 |
| 80953B30 | func_80953B30_jp | 104 | prototype/declaration | matched | 2 |
| 80953B98 | func_80953B98_jp | 140 | missing/unverified fields/types | matched | 3 |
| 80953C24 | func_80953C24_jp | 60 | prototype/declaration | matched | 1 |
| 80953C90 | func_80953C90_jp | 52 | missing/unverified fields/types | matched | 1 |
| 80953CC4 | aROD_actor_move | 36 | missing/unverified fields/types | matched | 1 |
| 80953AE8 | func_80953AE8_jp | 72 | already matched | matched | 0 |
| 80953C60 | func_80953C60_jp | 48 | already matched | matched | 0 |

## Verified layouts and APIs

Ride_Off_Demo: s32 current_action +174, existing unknown bytes +178..17B,
ActorFunc current_proc +17C, Train1* train_actor +180, Actor* station_master_actor
+184, s32 _188 +188; size remains 18C. The dispatch uses Actor*/Game_Play*
callbacks, not a guessed incompatible derived-actor callback signature.
Train1: existing storage split into s32 action +2B4 and s32 arg0 +2B8;
size remains 2D8. Ride-off assembly loads action and writes arg0; directly required
Train1 assembly (80A0D708 and 80A0D5F4) confirms those offsets/accesses, and GC
corroborates signed integer types and terminology.
Clip +A0 is DemoClip* (common absolute +100AC), Clip size remains 100.
CommonData +10A3E is u8 train_coming_flag, written with sb; adjacent storage and
size 10AB8 are preserved. DemoClip has pointer +0 and s32 type +4, size 8.
Compile-time size/offset assertions passed with N64-equivalent 32-bit ABI flags.

Callee assembly establishes player APIs 800B2C80 (Game_Play*, three f32, s32),
800B2D18/800B2D74 (Game_Play*), and 800B35E4 (three f32, no game pointer;
hard-float f12/f14/a2). Camera 800628F0 takes Game_Play*, const xyz_t*, three
f32 and priority s32, returning s32. Collision 80073C38 takes xyz_t by value
and s16 attribute; a0/a1/a2 carry the aggregate and the fourth argument is
accessed as a halfword. No API implementation or unrelated actor source changed.

## Behavior and GameCube correspondence

GC references: src/actor/ac_ride_off_demo.c, ac_ride_off_demo_move.c_inc,
and include/ac_ride_off_demo.h. N64 symbols were retained.

- 8095388C = aROD_change_player_demo_standing_train
- 809538CC = aROD_first_set
- 80953910 = aROD_train_birth_wait
- 80953974 = aROD_ride_train
- 809539CC = aROD_ride_off_player
- 80953A44 = aROD_walk_one_unit
- 80953AE8 = aROD_first_set_init
- 80953B30 = aROD_train_birth_wait_init
- 80953B98 = aROD_ride_off_player_init
- 80953C24 = aROD_walk_one_unit_init
- 80953C60 = aROD_init_proc
- 80953C90 = aROD_setupAction

State 0 sets train_coming_flag=3; state 1 finds Train1 and sets arg0=1;
state 2 waits for action 5; state 3 records the station master's speech begin/end;
state 4 waits for player z>=840 and station-master zero speed, then restores
player/camera state and deletes this actor. Initialization requests the fixed
camera, get-off action, stone collision attribute and walk goal as in assembly.
GC terms reused: ride_off, train, station_master, player, play, pos,
current_action/current_proc, train_actor/station_master_actor, train_coming_flag,
action/arg0, demoActor/type. Unknown _188 and +178 storage retain neutral names.
Naming-parity review required no further changes. N64 camera Y remains 235.0f
rather than GC's ground query; ctor does not copy GC's absent-on-N64 bzero.

## Matching and verification

21 attempts: seven first-pass smallest functions, get-off state first-pass,
camera and walk routines two each, three train-pointer routines three each.
Standing-train check preserves N64 Boolean normalization. Camera declaration
order fixes xyz_t stack placement; a station_master pointer local fixes walk's
register reuse. Train-pointer declarations before ride_off place their live
spill at sp+1C in the original 0x20-byte frame, without forcing registers/padding.
All 13 replacements pass asm-differ score 0, exact linked bytes, effective object
relocations, complete text/rodata and padding. Object relocation comparison
canonicalizes only equivalent named-symbol versus section-symbol rodata HI/LO
addends; final raw overlay relocation bytes are compared against the base ROM.
The original two C functions and assembly data/BSS/profile/tables remain unchanged.
Artifacts and attempt results are under build/ride-off-demo (untracked build data).

Final verification passed: all 13 candidates rechecked at score 0 against the
final unit; full 0x5F0-byte overlay ROM range including data, relocation payload,
and all padding equals the base ROM. BSS remains NOBITS size 0x10/alignment 16,
linked at 0x80953D60. git diff --check, full make -j4, and make compress passed.
ROM MD5: d7ae64f2f47a9fa3f87686a3c5ce09af (decompressed),
a4f7c57c180297b2e7ba5a5feb44fe0b (compressed).
