# broker_design (2026-10-29)

## Identity verified before editing

- Source: src/overlays/actors/ovl_Broker_Design/ac_broker_design.c
- Header: src/overlays/actors/ovl_Broker_Design/ac_broker_design.h
- Function assembly: asm/jp/nonmatchings/overlays/actors/ovl_Broker_Design/ac_broker_design/
- Data/relocations: asm/jp/data/overlays/actors/ovl_Broker_Design/ac_broker_design.data.s
  and ac_broker_design_reloc.data.s.
- Config: animalforest-jp.yaml:2138 (ovl_Broker_Design) and :2148 (relocations).
- Text ROM [0x8464D0,0x8467D0), data [0x8467D0,0x846810),
  relocation data [0x846810,0x846860). VRAM begins 0x809516E0, no BSS.
- Profile confirms actor size 0x17C. Function assembly plus original built
  object symbols confirm seven functions, 760 bytes (0x2F8), and 8 text
  padding bytes at ROM 0x8467C8 / VRAM 0x809519D8.

| Function | VRAM | Bytes | Initial classification | After shared fixes | Final |
| --- | --- | --- | --- | --- | --- |
| Broker_Design_Actor_draw | 0x8095180C | 16 | already matched | matched | matched |
| Broker_Design_Actor_move | 0x8095181C | 16 | already matched | matched | matched |
| Broker_Design_Actor_dt | 0x809517F4 | 24 | missing clip type | attemptable | matched |
| Broker_Design_Actor_ct | 0x80951794 | 96 | local clip layout, API/local signatures | attemptable | matched |
| func_8095182C_jp | 0x8095182C | 164 | room callback prototype | attemptable | matched |
| func_809516E0_jp | 0x809516E0 | 180 | saved-item/table typing, local signature | attemptable | assembly retained |
| func_809518D0_jp | 0x809518D0 | 264 | room callback prototypes, saved-item type | attemptable | matched |

Initial remaining: 5 functions / 728 bytes; largest 264 bytes. Shared fixes
made all five attemptable, satisfying the continuation threshold. No structural,
jump-table or unsafe/uninitialized-value blocker was identified. Existing
matched callbacks were not changed.

## Shared layout and API evidence

Constructor stores query/sales function addresses at actor+0x174/+0x178,
then publishes actor+0x174 at common_data+0x100A4. Destructor clears that
same global pointer. Query takes two signed coordinate ints (signed division
by 16) and returns a u16 item or 0xFFFF; sales takes those coordinates and
returns s32 0/1. Typed existing actor unknown[8] as BrokerDesignClip; typed
existing Clip unknown[4] at +0x98 as BrokerDesignClip*. Actor stays 0x17C,
clip tail 8 bytes, Clip stays 0x100.

The room callback table is directly required by query and sales. Read-only
N64 func_80939050_jp proves global common_data+0x1008C points at actor+0x2E8,
with func_80945ED8_jp / func_8094601C_jp at table+0x1C/+0x20. Callee assembly
proves signatures s32(u16*,s32*,s32,s32,s16) and void(s32): the fifth argument
is loaded with lh from its ABI halfword slot; outputs are sh/sw. Importantly,
lookup writes the u16 output on both success and failure, and writes the id
when its pointer is non-NULL. Thus query's delay-slot lhu after a false return
is not an uninitialized-value problem; the C uses short-circuit evaluation.
The two callback fields replace exactly 8 bytes within MyRoomClip.unk_08;
MyRoomClip's 0x6C modeled size and all subsequent offsets are preserved.

Three lhu/sh item slots occupy common_data+[0xEDE0,0xEDE6), within existing
Save.eventSaveInfo at +0xEDA4. Typed only that 6-byte portion, offset +0x3C,
as u16 brokerItems[3], preserving unknown bytes before/after and size 0x9C.
No other event payloads were inferred or changed.

Required event predicate func_8007D318_jp in asm/jp/code/6A0DE0.s takes one
32-bit event encoding, uses logical bit extraction, and returns exactly 0/1.
Replaced its existing header placeholder with s32(u32). mFI_BkNumtoUtFGTop's
existing u16*(s32,s32) declaration was sufficient. The placement table in data
is three pairs of 32-bit x/z values {2,2},{4,2},{2,4}, with 4 trailing padding
bytes. A candidate-only typed table declaration was removed when placement
remained assembly. No speculative fields/declarations are retained.

A temporary compile-time layout check passed using 32-bit host compilation
with eight-byte double/long-long alignment matching N64 (-malign-double).
It checks actor/Clip/MyRoomClip/EventSaveInfo sizes, the callback slots, the
actor tail, EventSaveInfo+0x3C, Save+0xEDA4, and absolute common-data offsets
0xEDE0 and 0x100A4. Initial checks without the matching host ABI failed on
pre-existing aggregate alignment differences; no source changes were made
in response. Final checks and logs are under build/broker-design/.

## Control flow reconstructed before attempts

- Destructor clears broker clip pointer, no other effects.
- Constructor checks event 2, optionally calls the placement helper, then
  always installs and publishes the two callbacks.
- Query computes signed coordinate remainders by division/subtraction (not
  unsigned masks), checks room clip, queries layer 0 with a NULL id output,
  accepts [0x1000,0x1ECD), otherwise returns 0xFFFF. Division/product/subtract
  remain defined for the entire s32 domain.
- Placement gets block (0,0) foreground, performs an empty three-element
  induction loop, then iterates the three saved items and three x/z pairs.
  Index is x+z*16; empty items write 0x1F36; furniture-range items copy through.
  Others are untouched. The observed empty loop was preserved in attempts;
  no volatile/register/assembly forcing was used.
- Sales queries first, rejects non-furniture or absent room clip, gets
  foreground, queries the original coordinates with item/id outputs, removes
  the furniture by id on success, marks the masked 16x16 tile as 0x1F36,
  then scans saved items, clearing the first matching item and returning 1.
  Returns 0 otherwise. Outputs are used only after successful lookup.

Only corresponding GC broker_design source/header were used for behavioral
cross-check. Directly required room/event API assembly and type/global
headers were read. No matching af reference function was needed; unrelated
target sources were not modified. ac-decomp remained read-only. Existing
research/blocked-candidates.md and research/run-log.md edits are preserved.

## Smallest-first attempts and results

Used workspace copies of research/tools/attempt_candidate.py and dependencies
under build/broker-design/tools/. The original verifier was used unchanged;
no relocation normalization or relaxed checks were needed.

- Destructor: first attempt PASS, score 0.
- Constructor: first attempt PASS, score 0.
- Query: first attempt PASS, score 0.
- Placement attempt 1: score 1045, empty loop used integer induction;
  address calculation's equivalent sum order also differed.
- Sales: first attempt PASS, score 0.
- Placement attempt 2: score 1318, pointer lifetime crossed the foreground
  call and bound expression produced additional address arithmetic.
- Placement attempt 3: score 55, local bound/initialization after the call
  restored the frame and loop; two address instructions and sum order differed.
- Placement focused attempt 4: score 30, equivalent sum reordering matched
  data-register allocation; two addiu address instructions remained reordered.
- Placement focused attempt 5: score 10, end-pointer-first initialization
  matched the low halves but reversed the order of two lui instructions.
- Placement focused attempt 6: score 410, ordered pointer comparison added
  instructions; automatically reverted.
- Placement focused attempt 7: score 725, do/while spelling differed further;
  automatically reverted. Four extra focused attempts exhausted; stop.

All four retained replacements require score 0, exact linked function bytes,
exact whole-object text and padding, and identical relocation offsets/types/
values/targets against the original object. Final re-verification after removing
unused candidate declarations passed. Placement retains its original assembly.
Best placement score 10; blocker is compiler scheduling, not type or unsafe
behavior. Total 11 attempts; 4 newly matched functions / 548 bytes; final
6/7 matched functions / 580 bytes. Eight text padding bytes remain exact.

Final full-build/compression/hash and whole-overlay checks follow below.

Final PASS: git diff --check, full make, make compress. Entire overlay
ROM [0x8464D0,0x846860) exactly matches original, including retained
assembly/data/relocation data and all padding. MD5 hashes both PASS:
d7ae64f2f47a9fa3f87686a3c5ce09af (decompressed),
a4f7c57c180297b2e7ba5a5feb44fe0b (compressed).
