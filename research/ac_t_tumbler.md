# ac_t_tumbler verification

Identity established before implementation on branch ai-decomp.

- N64 source/header: src/overlays/actors/ovl_T_Tumbler/ac_t_tumbler.{c,h}.
- N64 function assembly: asm/jp/nonmatchings/overlays/actors/ovl_T_Tumbler/ac_t_tumbler/*.s.
- N64 data/relocations: asm/jp/data/overlays/actors/ovl_T_Tumbler/ac_t_tumbler{,_reloc}.data.s.
- Config: animalforest-jp.yaml, lines 4280–4298. Text ROM 0x8E8720–0x8E8980 (VRAM 0x80A20C60–0x80A20EC0); data 0x8E8980–0x8E89E0; rodata 0x8E89E0–0x8E89F0; relocation payload 0x8E89F0–0x8E8A60. No BSS; no adjacent actor included.
- Eight functions, 604 instruction bytes, 4 trailing text padding bytes; initially zero matched.
- Read-only GameCube cross-check: ac-decomp/src/actor/tool/ac_t_tumbler.c and include/ac_t_tumbler.h. N64 initializes action 0 and uses chase step 0.1f; GameCube initializes action 1 and uses 0.05f. N64 takes precedence.

Shared layout resolved from N64 loads/stores: existing ToolActor embeds Actor (0x174 bytes), tool ID +0x174, MtxF +0x178, matrix flag +0x1B8, requested action +0x1BC. Preserve unknown +0x1C0–0x1C7; type callback +0x1C8 as void(Actor*) and s32 action +0x1CC. Actor profile confirms size 0x1D0. Dispatch consumes only a0; no game parameter is used by callbacks. Matrix/API declarations are existing project declarations. N64 tables establish 2 chase goals, 5 callbacks, 5 starting scales, and a zero xyz_t. No invented shared fields or declarations.

Only the matched pistol scale, setup, and draw patterns were used as matching-pattern references. No previously blocked target or ac-decomp file was edited.

| Function | Bytes | Initial classification | Final |
|---|---:|---|---|
| aTTB_actor_ct | 36 | attemptable | score 0, first attempt |
| func_80A20C84_jp | 104 | attemptable | score 0, first attempt |
| func_80A20CEC_jp | 32 | attemptable | score 0, first attempt |
| func_80A20D0C_jp | 32 | attemptable | score 0, first attempt |
| func_80A20D2C_jp | 32 | attemptable | score 0, first attempt |
| func_80A20D4C_jp | 56 | missing/unverified target-local layout → resolved, attemptable | score 0, first attempt |
| aTTB_actor_move | 68 | missing/unverified target-local layout → resolved, attemptable | score 0, first attempt |
| aTTB_actor_draw | 244 | missing/unverified target-local layout → resolved, attemptable | score 0, first attempt |

No prototype, structural, unsafe/uninitialized-value, or jump-table blockers. After layout resolution 8/8 were attemptable. Smallest-first: three 32-byte wrappers, 36-byte constructor, 56-byte setup, 68-byte move, 104-byte scale helper, 244-byte draw.

Eight total attempts via research/tools/attempt_candidate.py (copied from existing local verification tooling). Each passed asm-differ score 0, complete object text/rodata and padding identity, linked bytes, and text relocation equality. Final verification additionally compared all object relocation records and the entire ROM overlay range 0x8E8720–0x8E8A60 against the reference, covering retained profile/data, relocation payload and padding. Original assembly/data remain untouched. Local candidate selections, results, tools, baseline object and build logs retained under build/tumbler/.

Full make -j4 and make compress passed; compression required an approved sandbox escalation for Python multiprocessing socket creation. git diff --check passed.

- Decompressed ROM: d7ae64f2f47a9fa3f87686a3c5ce09af — PASS.
- Compressed ROM: a4f7c57c180297b2e7ba5a5feb44fe0b — PASS.

All 8/8 functions newly matched (604 bytes plus 4 bytes text padding). No remaining blockers. Pre-existing research/run-log.md and research/blocked-candidates.md edits preserved and excluded from this commit.
