# FallS verification (2026-10-29)

Identity: source `src/overlays/actors/ovl_FallS/ac_fallS.c`, header alongside it;
assembly `asm/jp/nonmatchings/overlays/actors/ovl_FallS/ac_fallS/`.
`animalforest-jp.yaml:3778` defines ROM 0x8D1F00, VRAM 0x80A03230;
text ends at ROM 0x8D2110, data ends 0x8D2140, relocation ends 0x8D2170.
The actual functions are:

| Symbol | Address | Bytes | Initial classification | Result |
| --- | --- | --- | --- | --- |
| func_80A03230_jp | 0x80A03230 | 0x10 | attemptable | matched |
| aFLS_actor_move | 0x80A032CC | 0x54 | attemptable | matched |
| func_80A03240_jp | 0x80A03240 | 0x8C | attemptable | matched |
| aFLS_actor_draw | 0x80A03320 | 0x11C | attemptable | retained assembly |

Total 4 functions, 0x20C (524) function bytes and one 4-byte trailing nop at
0x80A0343C. Initially none matched; no missing type, prototype, jump-table,
or unsafe/uninitialized-value blockers. Four of four attemptable, so continue.
Actor profile remains assembly data: verified size 0x2D8; header unchanged.
No new fields, declarations, or layout changes were required.

Assembly reconstruction before attempts:
- Empty callback saves incoming arguments and returns.
- Move copies Actor.world.pos at +0x28 into a fully initialized xyz_t at
  sp+0x1C, adds 40.0f to y, and calls the existing sAdo_OngenPos prototype
  with actor identity converted to s32 and sound 12.
- Destructor reloads structureClip at common_data+0x10098 for each call,
  invokes +0xA8 with table addresses +0xB0/+0x454/+0x86C, counts 8/9/8,
  type/palette 0x13/0x3C/0x13 and actor. Existing StructureClip types and
  STRUCTURE_TYPE_FALL_S / STRUCTURE_PALETTE_FALL_S cover every access.
- Draw calls translucent setup, loads polyXlu cursor (+0x2A8), emits a
  load/no-push modelview matrix via _Matrix_to_Mtx_new, calls getObjectSegment
  (+0xAC) twice (first for physical SegmentBaseAddress[6], second for the
  display-list segment command), publishes cursor before Evw_Anime_Set with
  Lib_SegmentedToVirtual, reloads cursor, emits model list and publishes again.
  Matrix call order has one call; there are no float, Boolean, or branch
  normalization decisions. Its 0x38 stack frame keeps context at +0x30,
  cursor at +0x24 and packet temporaries at +0x1C/+0x18. Cursor lifetime and
  reloads across animation setup must be preserved.

GC FallS main/move/draw were read only for behavior: N64 has additional
structure segment management and no GC rainbow path. Existing af Yatai
functions (destructor and draw only) supplied two matching pattern references;
no other matching function bodies were used.

Attempts through a workspace copy of research/tools/attempt_candidate.py:
1. empty callback: score 0, exact text, linked bytes, relocations and padding.
2. move: same checks pass, score 0.
3. destructor: same checks pass, score 0.
4. draw: score 2160; context held in s0 rather than target stack local.
5. draw: declaration moved into OPEN_DISPS scope; IDO rejected declaration
   after macro statement (no score).
6. draw: nested declaration block compiles, score 2112. Budget exhausted;
   candidate automatically reverted. Best draw score 2112. No extra attempts
   allowed by the below-100 rule. Retain 3/4 matched, 240/524 bytes.

Evidence and tool outputs live in ignored build/falls/. Final verification
also compares the whole original object text/padding and text relocations,
and the complete overlay including retained data, relocation data and padding
against the original decompressed ROM. Full build and compression hashes are
recorded after completion below.

Final: git diff --check passed; full make and make compress passed.
Complete overlay range 0x8D1F00..0x8D2170 matches baserom exactly.
ROM MD5 d7ae64f2f47a9fa3f87686a3c5ce09af; compressed MD5
a4f7c57c180297b2e7ba5a5feb44fe0b: both pass.
