# Fresh completion-first survey — after Tamaire_Npc0 (2026-10-30)

Scanned current C GLOBAL_ASM references and current assembly instruction sizes,
not earlier rankings. Completed units (no remaining pragmas) automatically absent.
Explicit user exclusions filtered by logical overlay and source stem. Selected
Tukimi_Npc0 is its own NPC overlay. Work on one target only.

Cheap counts below do not certify untouched candidates safe: S=compiler-style
jump-table markers found; U=? means full uninitialized-value/ABI audit deferred,
with none established in this cheap scan. No-draw labels use assembly callees as
well as names (Garagara calls graphics/matrix/keyframe draw APIs). A=immediately
attemptable estimate from known direct API declarations, target field accesses
and target data references; target-local type recovery can unlock additional work.
T/P counts may overlap. Full winner audit follows before implementation.
Recent NPC/request/clip/demo work benefits every listed NPC actor; Garagara's
matrix/keyframe work is less closely related. All entries have existing C units.

| Rank | Source stem | Total / asm / C | Remaining bytes | Largest | A estimate | T/P estimate | S / U | Shared fix | Graphics |
| ---: | --- | --- | ---: | ---: | ---: | --- | --- | --- | --- |
| 1 | ac_tukimi_npc0 | 21 / 21 / 0 | 1628 | 256 | 12 | 8/1 | 0 / 0 (audited) | local NPC/request/callback view | no draw API found |
| 2 | ac_tukimi_npc1 | 22 / 22 / 0 | 1868 | 284 | 8 | 14/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 3 | ac_hanabi_npc1 | 28 / 25 / 3 | 2120 | 328 | 7 | 18/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 4 | ac_hanabi_npc0 | 31 / 31 / 0 | 2680 | 332 | 14 | 17/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 5 | ac_tokyoso_npc0 | 32 / 31 / 1 | 3128 | 288 | 18 | 13/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 6 | ovl_Npc_Majin | 25 / 25 / 0 | 2096 | 276 | 9 | 16/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 7 | ac_npc_majin | 31 / 31 / 0 | 2844 | 276 | 11 | 20/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 8 | ac_npc_majin3 | 34 / 34 / 0 | 3280 | 276 | 14 | 20/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 9 | ac_ev_broker | 33 / 31 / 2 | 2616 | 240 | 13 | 18/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 10 | ac_ev_artist | 25 / 23 / 2 | 2284 | 260 | 11 | 12/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 11 | ac_ev_santa | 27 / 25 / 2 | 2736 | 300 | 15 | 10/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 12 | ac_ev_kabuPeddler | 28 / 26 / 2 | 2716 | 336 | 13 | 13/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 13 | ac_ev_dozaemon | 34 / 32 / 2 | 3452 | 340 | 20 | 12/0 | 0 / ? | local NPC/request/callback view | no draw API found |
| 14 | ac_garagara | 26 / 25 / 1 | 3076 | 320 | 9 | 16/0 | 0 / ? | local NPC/request/callback view | yes |
| 15 | ac_ev_carpetPeddler | 38 / 36 / 2 | 3976 | 360 | 16 | 20/0 | 0 / ? | local NPC/request/callback view | no draw API found |

## Exact paths and API risks

1. **ac_tukimi_npc0**: source `src/overlays/actors/ovl_Tukimi_Npc0/ac_tukimi_npc0.c`; header `src/overlays/actors/ovl_Tukimi_Npc0/ac_tukimi_npc0.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Tukimi_Npc0/ac_tukimi_npc0/`; config `animalforest-jp.yaml:3491` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/ac_tukimi_npc0.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

2. **ac_tukimi_npc1**: source `src/overlays/actors/ovl_Tukimi_Npc1/ac_tukimi_npc1.c`; header `src/overlays/actors/ovl_Tukimi_Npc1/ac_tukimi_npc1.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Tukimi_Npc1/ac_tukimi_npc1/`; config `animalforest-jp.yaml:3510` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/ac_tukimi_npc1.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

3. **ac_hanabi_npc1**: source `src/overlays/actors/ovl_Hanabi_Npc1/ac_hanabi_npc1.c`; header `src/overlays/actors/ovl_Hanabi_Npc1/ac_hanabi_npc1.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Hanabi_Npc1/ac_hanabi_npc1/`; config `animalforest-jp.yaml:3414` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/ac_hanabi_npc1.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

4. **ac_hanabi_npc0**: source `src/overlays/actors/ovl_Hanabi_Npc0/ac_hanabi_npc0.c`; header `src/overlays/actors/ovl_Hanabi_Npc0/ac_hanabi_npc0.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Hanabi_Npc0/ac_hanabi_npc0/`; config `animalforest-jp.yaml:3394` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/ac_hanabi_npc0.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

5. **ac_tokyoso_npc0**: source `src/overlays/actors/ovl_Tokyoso_Npc0/ac_tokyoso_npc0.c`; header `src/overlays/actors/ovl_Tokyoso_Npc0/ac_tokyoso_npc0.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Tokyoso_Npc0/ac_tokyoso_npc0/`; config `animalforest-jp.yaml:13896` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/ac_tokyoso_npc0.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

6. **ovl_Npc_Majin**: source `src/overlays/actors/ovl_Npc_Majin/ovl_Npc_Majin.c`; header `src/overlays/actors/ovl_Npc_Majin/ovl_Npc_Majin.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Npc_Majin/ovl_Npc_Majin/`; config `animalforest-jp.yaml:2919` (C entry; enclosing overlay entry immediately above). GC `address-named C unit; GC Majin identity needs separate audit`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

7. **ac_npc_majin**: source `src/overlays/actors/ovl_Npc_Majin2/ac_npc_majin.c`; header `src/overlays/actors/ovl_Npc_Majin2/ac_npc_majin.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Npc_Majin2/ac_npc_majin/`; config `animalforest-jp.yaml:2939` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/ac_npc_majin.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

8. **ac_npc_majin3**: source `src/overlays/actors/ovl_Npc_Majin3/ac_npc_majin3.c`; header `src/overlays/actors/ovl_Npc_Majin3/ac_npc_majin3.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Npc_Majin3/ac_npc_majin3/`; config `animalforest-jp.yaml:2959` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/ac_npc_majin3.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

9. **ac_ev_broker**: source `src/overlays/actors/ovl_Ev_Broker/ac_ev_broker.c`; header `src/overlays/actors/ovl_Ev_Broker/ac_ev_broker.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Broker/ac_ev_broker/`; config `animalforest-jp.yaml:3296` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/event/ac_ev_broker.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

10. **ac_ev_artist**: source `src/overlays/actors/ovl_Ev_Artist/ac_ev_artist.c`; header `src/overlays/actors/ovl_Ev_Artist/ac_ev_artist.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Artist/ac_ev_artist/`; config `animalforest-jp.yaml:3277` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/event/ac_ev_artist.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

11. **ac_ev_santa**: source `src/overlays/actors/ovl_Ev_Santa/ac_ev_santa.c`; header `src/overlays/actors/ovl_Ev_Santa/ac_ev_santa.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Santa/ac_ev_santa/`; config `animalforest-jp.yaml:3666` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/event/ac_ev_santa.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

12. **ac_ev_kabuPeddler**: source `src/overlays/actors/ovl_Ev_KabuPeddler/ac_ev_kabuPeddler.c`; header `src/overlays/actors/ovl_Ev_KabuPeddler/ac_ev_kabuPeddler.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_KabuPeddler/ac_ev_kabuPeddler/`; config `animalforest-jp.yaml:3608` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/event/ac_ev_kabuPeddler.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

13. **ac_ev_dozaemon**: source `src/overlays/actors/ovl_Ev_Dozaemon/ac_ev_dozaemon.c`; header `src/overlays/actors/ovl_Ev_Dozaemon/ac_ev_dozaemon.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Dozaemon/ac_ev_dozaemon/`; config `animalforest-jp.yaml:16403` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/event/ac_ev_dozaemon.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

14. **ac_garagara**: source `src/overlays/actors/ovl_Garagara/ac_garagara.c`; header `src/overlays/actors/ovl_Garagara/ac_garagara.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Garagara/ac_garagara/`; config `animalforest-jp.yaml:15543` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/ac_garagara.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

15. **ac_ev_carpetPeddler**: source `src/overlays/actors/ovl_Ev_CarpetPeddler/ac_ev_carpetPeddler.c`; header `src/overlays/actors/ovl_Ev_CarpetPeddler/ac_ev_carpetPeddler.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_CarpetPeddler/ac_ev_carpetPeddler/`; config `animalforest-jp.yaml:3336` (C entry; enclosing overlay entry immediately above). GC `../ac-decomp/src/actor/npc/event/ac_ev_carpetPeddler.c`. Unresolved direct API declarations from cheap scan: none flagged (callback prototypes/local globals still require review).

## Selection

Tukimi_Npc0 wins on fewer functions than the other leading NPC candidates, small
maximum size, known APIs, one shared NPC-prefix recovery, and no graphics. Direct
full assembly audit finds no unsafe/structural blockers. Other candidates remain
surveyed rather than approved for editing. Merchant/Majin actors involve more
message/player/inventory prototypes and have less certainty; Garagara has drawing;
carpet peddler already needs 36 first attempts before retries, exceeding practical
headroom under the 36-attempt budget. No excluded target was opened or modified.
