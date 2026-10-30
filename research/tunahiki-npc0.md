# tunahiki_npc0 — fresh audit and partial decompilation

Starting HEAD e9ca0cb, branch ai-decomp. Only this target's source/header and this
new research note are changed. Existing dirty research logs were preserved.

## Exact identity

- Source: `src/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0.c`
- Header: `src/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0.h`
- Function assembly: `asm/jp/nonmatchings/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0/*.s`
- Data/relocation assembly: `asm/jp/data/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0{,_reloc}.data.s`
- Config: `animalforest-jp.yaml:15886`, C entry 15894; reloc entry 15896/15903.
- Tunahiki_Npc0_Profile: actor 0xA1 (ACTOR_TUNAHIKI_NPC0), NPC category 3,
  flags 0, fgName 0xD05F, GAMEPLAY_KEEP 3, instance size 0x950.
- Text ROM [0x951D10,0x9525E0), VRAM [0x80A91AA0,0x80A92370).
  21 functions, 2244 (0x8C4) function bytes, 12 trailing zero padding bytes.
- Data ROM [0x9525E0,0x952670), VRAM [0x80A92370,0x80A92400), size 0x90.
  No rodata/BSS. Relocations [0x952670,0x952730), size 0xC0.
  Complete overlay ROM span [0x951D10,0x952730), size 0xA20.
- Event save: event 9, area 9; existing TunahikiControlSave matches this target's
  f32 rope +0/ropeBase +4, s16 npcState +10, u16 flags +12 accesses.

## Every-function classification

Fresh baseline: 1 already matched, 6 immediately attemptable, 14 dependent on
unverified local NPC/actor fields; wait-init additionally needs the correct
three-argument animation ABI. No jump tables, structural blockers, unsafe or
uninitialized-value blockers. The shared local layout fix unlocks all 20.
After fixing types/API use: all 20 attemptable; final 19 matched and 2 still
attemptable but stopped at the per-function attempt cap (codegen differences).

| Symbol/address | Bytes | Fresh baseline | Final | Compiled attempts |
|---|---:|---|---|---:|
| aTNN0_actor_ct / 80A91AA0 | 264 | local fields/types | score 390, assembly retained | 3 |
| aTNN0_actor_save / 80A91BA8 | 36 | already matched | matched | 0 |
| aTNN0_actor_dt / 80A91BCC | 116 | local fields/types | matched | 1 |
| aTNN0_actor_init / 80A91C40 | 44 | attemptable | matched | 1 |
| func_80A91C6C_jp / 80A91C6C | 156 | local fields/types | matched | 3 |
| func_80A91D08_jp / 80A91D08 | 100 | local fields/types | matched | 1 |
| func_80A91D6C_jp / 80A91D6C | 72 | attemptable | matched | 1 |
| func_80A91DB4_jp / 80A91DB4 | 152 | local fields/types | matched | 1 |
| func_80A91E4C_jp / 80A91E4C | 76 | local fields/types | matched | 1 |
| func_80A91E98_jp / 80A91E98 | 64 | local fields/types | matched | 1 |
| func_80A91ED8_jp / 80A91ED8 | 124 | local fields/types | matched | 1 |
| func_80A91F54_jp / 80A91F54 | 308 | local fields/types | score 105, assembly retained | 3 |
| func_80A92088_jp / 80A92088 | 60 | local fields/types | matched | 1 |
| func_80A920C4_jp / 80A920C4 | 56 | local fields/types | matched | 1 |
| func_80A920FC_jp / 80A920FC | 96 | local fields/types + API ABI | matched | 1 |
| func_80A9215C_jp / 80A9215C | 160 | local fields/types | matched | 1 |
| func_80A921FC_jp / 80A921FC | 72 | attemptable | matched | 1 |
| func_80A92244_jp / 80A92244 | 64 | local fields/types | matched | 1 |
| func_80A92284_jp / 80A92284 | 108 | attemptable | matched | 1 |
| func_80A922F0_jp / 80A922F0 | 72 | attemptable | matched | 1 |
| func_80A92338_jp / 80A92338 | 44 | attemptable | matched | 1 |

## Shared layout and ABI evidence

All field offsets are direct target N64 lb/lbu/lh/lhu/lw/sb/sh/sw or address
arithmetic evidence. Current shared Npc is size 0x93C, but this actor's first
private callback is at +0x938; embedding that shared type would overlap it.
Preserve shared Npc and its offsets/size. Type this target's existing storage as
TunahikiNpc0Npc, a verified 0x938-byte prefix, plus private state through 0x950.
No other actor/layout implementation is changed.

Verified prefix: think callback +7A4 and schedule callback +7C0 (three arguments),
u8 action index/step +7C5/+7C6; u8 request priority/index/type +7D4/+7D5/+7D6;
six u16 request arguments +7D8 (12-byte zero/copy, obj at +0, move_x/z +4/+6);
u8 hide_request +7FD; u32 demo_flg +80C; right-hand item Actor* +860;
u8 head lock +876; s32 palActorIgnoreTimer +8AC; existing ClObjPipe at +8F0,
whose s16 radius is +8FE; u8 collision kind +911; two-argument talk-request
callback +91C; u8 talk turn +92B and s16 default animation +92C.
Private fields: ActorFunc think_proc +938 and talk_proc +93C, Actor* rope_p +940,
s32 base_msg +944, u8 think/next-think/talk/change indices +94A..94D.
+948..949 remains unknown storage: GC's timer name is not proven by N64 accesses.
N64 stores prove widths and callback/pointer use; GC corroborates flag/signedness
and semantic names where N64 alone does not distinguish signed integer storage.
Compile-time assertions verify full size, prefix and all accessed offsets.

Data tables remain assembly. D_80A923C8 is stride 8 (s32 msg_no, u8 turn/camera,
2 padding bytes). D_80A923D0 is stride 5 (five u8 indices), two rows and 2 padding
bytes. Dispatch tables contain 4-byte function pointers; original padding stays.
Constructor data D_80A92394 uses existing struct_809AEFA4 size 0x1C.

NPC clip +104 is installed as func_809749D0_jp in func_8053a354 assembly.
The callee consumes a0/a1/a2, never a3; GC animation-init signature is void
(Actor*, int, int). Existing shared clip declaration has an extra fourth argument
used by other C units. This target calls through a cast to the verified actual
three-argument function type; no fabricated external API or shared change.
Clip +110 is func_8097E7F4_jp: four arguments with state/type dispatch and integer
result, matching current shared declarations. Other used clip/tool/event/demo
APIs already have declarations. ToolActor*/Actor* conversions preserve established
ToolClip API types. No new global/API declarations are invented.

## GameCube terminology and correspondences

Read-only GC references: src/actor/npc/ac_tunahiki_npc0.c,
ac_tunahiki_npc0_talk.c_inc, ac_tunahiki_npc0_schedule.c_inc,
include/ac_tunahiki_npc0.h and directly required NPC types.

80A91C6C=set_request_act; 80A91D08=make_hata; 80A91D6C=actor_move;
80A91DB4=set_norm_talk_info; 80A91E4C=norm_talk_request; 80A91E98=talk_init;
80A91ED8=talk_end_chk; 80A91F54=birth; 80A92088=think_main_proc;
80A920C4=think_init_proc; 80A920FC=wait_init; 80A9215C=setup_think_proc;
80A921FC=think_proc; 80A92244=schedule_init_proc; 80A92284=schedule_main_proc;
80A922F0=schedule_proc; 80A92338=actor_draw. These are aTNN0_ prefixed GC names;
established N64 symbols remain unchanged. Locals actorx/actor/play, tunahiki,
flag, args, res/ret, data_p/dt and state/table member names follow demonstrated
GC roles. Prefix fields flatten GC's nested NPC groups with recognizable names;
unknown storage keeps neutral names. Existing event-save camelCase stays intact.

## Attempts and remaining differences

26 compiled candidates, plus one tool validation rejection before compilation
(source-relative includes were moved into the source, not the tool's include-only
injection list). No function exceeds three compiled attempts.
17 replacements match first-pass; request helper matches on its third attempt
by accepting Tunahiki_Npc0* directly and removing the redundant cast local.
That places its u16[6] at sp+20 with the original 0x30 frame; moving the array
alone instead produced score 136 versus first score 112.

Constructor: three attempts, best/final 390. Control flow and first 0x94 bytes
match. Remaining scheduling concerns zero-float materialization, base_msg store,
talk turn/default-animation constants and ground-height argument preparation.
Explicit zero local and verified NPC-prefix nesting did not change the score.
No unsafe workaround retained; constructor remains original assembly.

Rope birth: three attempts, best/final 105 (initial 121). Reordering the save
pointer declaration fixes its live slot from sp+50 to sp+54, but a redundant
move v1,v0 remains before the null branch; target retains v0 through the initial
spill. Conditional assignment leaves the same difference. No C candidate retained.
Both scores exceed the below-100 extension threshold, so stop at the ordinary cap.
The remaining two routines total 572 bytes. New matched bytes 1636; total matched
1672/2244 bytes, 19/21 functions. All retained assembly/data are untouched.

Verification artifacts and attempt JSON are under build/tunahiki-npc0.

Final checks: all 18 retained replacements reverified at score 0, exact object
text relocations, complete object text/padding and linked function bytes.
After the prefix callback naming cleanup, another whole-object exact check passed.
The entire 0xA20-byte overlay, including retained code, data, relocation records
and padding, compares byte-for-byte to baseroms/jp/baserom-decompressed.z64.
BSS remains absent. git diff --check, full make -j4 and make compress passed.
MD5 decompressed: d7ae64f2f47a9fa3f87686a3c5ce09af.
MD5 compressed: a4f7c57c180297b2e7ba5a5feb44fe0b.
