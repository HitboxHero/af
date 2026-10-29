# FallSESW (2026-10-29)

Identity verified before editing:
- Source: src/overlays/actors/ovl_FallSESW/ac_fallSESW.c
- Header: src/overlays/actors/ovl_FallSESW/ac_fallSESW.h
- Assembly: asm/jp/nonmatchings/overlays/actors/ovl_FallSESW/ac_fallSESW/*.s
- Data: asm/jp/data/overlays/actors/ovl_FallSESW/ac_fallSESW.data.s
- Relocations: same directory, ac_fallSESW_reloc.data.s
- Config: animalforest-jp.yaml:3797, ovl_FallSESW / ovl_FallSESW_reloc.
- Logical boundaries: text ROM [0x8D2170,0x8D23A0), data
  [0x8D23A0,0x8D2410), relocation [0x8D2410,0x8D2440).
  VRAM begins 0x80A034A0; no BSS. Actor profile is 0x24 bytes;
  flip matrix starts 0x80A036F4 and is 0x40 bytes with 12 trailing padding
  bytes before the relocation segment. Header/profile both specify 0x2D8.

| Function | VRAM | Function bytes | Initial classification | Final |
| --- | --- | --- | --- | --- |
| func_80A034A0_jp | 0x80A034A0 | 0x10 | attemptable | matched |
| aFLEW_actor_move | 0x80A0353C | 0x54 | attemptable | matched |
| func_80A034B0_jp | 0x80A034B0 | 0x8C | attemptable | matched |
| aFLEW_actor_draw | 0x80A03590 | 0x13C | attemptable | assembly retained |

Four functions, 0x22C = 556 function bytes; 4 additional text padding bytes
at 0x80A036CC. Zero already matched initially. All remaining functions were
attemptable (100%); no missing fields, prototype, structural, jump-table or
unsafe/uninitialized-value blockers. No shared type changes needed. All
existing offsets/sizes preserved; no new declarations retained.

Assembly reconstruction before edits:
- Empty callback saves both arguments and returns.
- Move initializes xyz_t at sp+0x1C by copying Actor.world.pos (+0x28),
  adds 40.0f to y, then sAdo_OngenPos((s32)actor,12,&pos). Verified existing
  API prototypes and Actor fields. No uninitialized reads.
- Destructor calls structureClip.removeInstanceProc (+0xA8) three times,
  reloading the clip pointer at common_data+0x10098 each time; tables
  +0xB0/+0x454/+0x86C, counts 8/9/8, type/palette 0x14/0x3D/0x14.
  Existing StructureClip fields and STRUCTURE_TYPE_FALL_SESW /
  STRUCTURE_PALETTE_FALL_SESW cover those accesses exactly.
- Draw setup uses game->gfxCtx at +0. Actor.fgName (+6) is compared directly
  against 0x580F; bne skips Matrix_mult(flip,MTXMODE_APPLY). The verified
  matrix words encode diag(-1,1,1,1); a temporary extern MtxF declaration
  was backed by that data and Matrix_mult's existing prototype.
  Cursor is polyXlu.p (+0x2A8), with a 0x38 stack frame: context +0x30,
  cursor +0x24, matrix/segment packet pointers +0x1C/+0x18. Matrix allocation
  follows optional multiplication. Two getObjectSegment(0x14) calls serve
  the physical segment base and display-list segment command separately.
  Cursor is published before Lib_SegmentedToVirtual / Evw_Anime_Set,
  reloaded afterward, advanced for the model list, then published again.
  No draw float arithmetic or Boolean normalization; direct unsigned field
  comparison is sufficient. Final display-list stores are w1 before w0.

GC ac_fallSESW.c and its move/draw includes were read only as a behavioral
cross-check: west flip and sound position agree; GC rainbow logic is absent
from N64. Existing af Radio and Koinobori destructor/draw patterns supplied the
matching references (contiguous source excerpts also included surrounding code). Relevant
API/type/global declarations and object header were inspected directly.

Attempts used a workspace copy of research/tools/attempt_candidate.py and
its dependencies under build/fallsesw/tools, with isolated original object
baseline and evidence under build/fallsesw/.
1. Empty: score 0, exact linked bytes, whole object text/padding and relocs.
2. Move: same checks pass, score 0.
3. Destructor: same checks pass, score 0.
4. Draw: score 3512. Direct context accesses and inner cursor acquire saved
   registers; target uses stack locals.
5. Draw: OPEN_DISPS plus separate cursor scopes yields score 2317; inner
   command sequence aligns but context remains s0, stack slots differ,
   final display-list word stores have a different order.
6. Draw: context lifetime contained in OPEN_DISPS scope; score 2112.
   Three ordinary attempts exhausted, never below 100; stop. All failed
   candidates automatically reverted. Best draw score 2112.

Retained progress: 3/4 matched, 240/556 function bytes. Draw remains assembly
with a compiler allocation/scheduling mismatch, not a type/unsafe blocker.
No FallS files were read or modified during this target. Existing research
log edits are preserved and excluded from the target commit.

Final validation: git diff --check, full make, and make compress pass.
Whole overlay ROM range [0x8D2170,0x8D2440) is exact, including retained
assembly/data/relocation data and padding. ROM hashes both pass:
d7ae64f2f47a9fa3f87686a3c5ce09af (decompressed),
a4f7c57c180297b2e7ba5a5feb44fe0b (compressed).
