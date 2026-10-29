# Fresh completion-first ranking (2026-10-29): ev_gypsy selected

Inventory regenerated from current C GLOBAL_ASM references, assembly function
sizes and current source definitions; no previous ranking/spreadsheet was used.
User's blocked/partial exclusions were filtered before inspection. Completed
units have no remaining functions and were excluded. The scan window was
400–3000 remaining bytes. Direct jump-register scans reject computed transfer
candidates; normal callback dispatch is not itself a structural blocker.

These are cheap survey results, not full reconstructions for fifteen units.
Ready counts are conservative verified lower bounds: unverified layouts/API
signatures are not counted as immediately ready. No unsafe/uninitialized or
structural blocker was identified in these fifteen surveyed candidates, but
only the winner received a complete function/data/ABI audit. In particular,
absence of a reported unsafe blocker is not a proof for an unselected unit.
All fifteen have zero detected compiler jump-table transfers. Shared type/API
work is assessed by the accessed storage, called APIs and existing headers.
Graphics weight includes matrix/particle/skeleton work even when function names
are address-style and do not contain "draw".

| Rank / target | Total funcs | Remaining | Bytes | Matched | Immediately ready >= | Largest | Type/prototype blockers | Shared fix | Graphics |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1. ac_ev_gypsy | 16 | 14 | 1480 | 2 | 2 → 14 | 272 | four tail fields; three API declarations | yes; 14/14 ready after verified fixes | none |
| 2. ac_ride_off_demo | 15 | 13 | 1104 | 2 | 0 | 164 | actor tail/actions; player and camera API declarations | likely; local tail, but broader player ABI work | none |
| 3. ac_tunahiki_npc0 | 21 | 20 | 2208 | 1 | 0 | 308 | NPC tail/request/callbacks and shared event-save payload | likely; save and local layout | none |
| 4. ac_ev_miko | 22 | 20 | 2760 | 2 | 0 | 308 | NPC tail, dialogue, mail and possession APIs | partly; multiple data domains | none |
| 5. ac_train1 | 11 | 11 | 1936 | 0 | 1 | 292 | structure/skeleton layout, action callbacks and event API | likely; skeleton actor base | medium |
| 6. ac_windmil | 9 | 9 | 1912 | 0 | 1 | 512 | skeleton base and wind state fields | likely; local layout | medium |
| 7. ac_house_clock | 17 | 17 | 2520 | 0 | 4 | 572 | clock/skeleton/allocation fields and multiple matrix routines | partly; several systems | high |
| 8. ac_train0 | 14 | 14 | 2936 | 0 | 1 | 532 | train/skeleton state and actor-search data | likely; actor base | medium |
| 9. ac_countdown | 14 | 14 | 2624 | 0 | 1 | 512 | countdown/skeleton state and player proximity fields | likely; actor base | medium |
| 10. ef_room_sunshine_police | 9 | 9 | 1956 | 0 | 1 | 448 | local effect/window state and draw parameters | likely; local effect layout | high |
| 11. ef_room_sunshine_posthouse | 8 | 8 | 1808 | 0 | 1 | 424 | local effect/window state and draw parameters | likely; local effect layout | high |
| 12. ac_birth_control | 6 | 6 | 2132 | 0 | 2 | 556 | birth control actor/NPC APIs and loop state | partly; multiple NPC APIs | none |
| 13. ac_s_car | 7 | 7 | 2140 | 0 | 1 | 596 | vehicle/skeleton state, event-save APIs, draw setup | partly; several systems | medium |
| 14. ac_weather_snow | 9 | 9 | 1776 | 0 | 1 | 508 | particle arrays, player/projection APIs and matrix output | likely; particle layout | high |
| 15. ac_weather_leaf | 9 | 9 | 1744 | 0 | 2 | 468 | particle arrays, projection APIs and matrix output | likely; particle layout | high |

Exact paths from the current scan:

1. Source `src/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy.c`; header `src/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Gypsy/ac_ev_gypsy/`; config `animalforest-jp.yaml:3375`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

2. Source `src/overlays/actors/ovl_Ride_Off_Demo/ac_ride_off_demo.c`; header `src/overlays/actors/ovl_Ride_Off_Demo/ac_ride_off_demo.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ride_Off_Demo/ac_ride_off_demo/`; config `animalforest-jp.yaml:2206`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

3. Source `src/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0.c`; header `src/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Tunahiki_Npc0/ac_tunahiki_npc0/`; config `animalforest-jp.yaml:15894`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

4. Source `src/overlays/actors/ovl_Ev_Miko/ac_ev_miko.c`; header `src/overlays/actors/ovl_Ev_Miko/ac_ev_miko.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Ev_Miko/ac_ev_miko/`; config `animalforest-jp.yaml:3627`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

5. Source `src/overlays/actors/ovl_Train1/ac_train1.c`; header `src/overlays/actors/ovl_Train1/ac_train1.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Train1/ac_train1/`; config `animalforest-jp.yaml:4024`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

6. Source `src/overlays/actors/ovl_Windmill/ac_windmil.c`; header `src/overlays/actors/ovl_Windmill/ac_windmil.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Windmill/ac_windmil/`; config `animalforest-jp.yaml:16555`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

7. Source `src/overlays/actors/ovl_House_Clock/ac_house_clock.c`; header `src/overlays/actors/ovl_House_Clock/ac_house_clock.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_House_Clock/ac_house_clock/`; config `animalforest-jp.yaml:15854`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

8. Source `src/overlays/actors/ovl_Train0/ac_train0.c`; header `src/overlays/actors/ovl_Train0/ac_train0.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Train0/ac_train0/`; config `animalforest-jp.yaml:4004`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

9. Source `src/overlays/actors/ovl_Count/ac_countdown.c`; header `src/overlays/actors/ovl_Count/ac_countdown.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Count/ac_countdown/`; config `animalforest-jp.yaml:15522`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

10. Source `src/overlays/actors/ovl_Room_Sunshine_Police/ef_room_sunshine_police.c`; header `src/overlays/actors/ovl_Room_Sunshine_Police/ef_room_sunshine_police.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Room_Sunshine_Police/ef_room_sunshine_police/`; config `animalforest-jp.yaml:2466`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

11. Source `src/overlays/actors/ovl_Room_Sunshine_Posthouse/ef_room_sunshine_posthouse.c`; header `src/overlays/actors/ovl_Room_Sunshine_Posthouse/ef_room_sunshine_posthouse.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Room_Sunshine_Posthouse/ef_room_sunshine_posthouse/`; config `animalforest-jp.yaml:2446`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

12. Source `src/overlays/actors/ovl_Birth_Control/ac_birth_control.c`; header `src/overlays/actors/ovl_Birth_Control/ac_birth_control.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_Birth_Control/ac_birth_control/`; config `animalforest-jp.yaml:2067`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

13. Source `src/overlays/actors/ovl_S_Car/ac_s_car.c`; header `src/overlays/actors/ovl_S_Car/ac_s_car.h`; assembly `asm/jp/nonmatchings/overlays/actors/ovl_S_Car/ac_s_car/`; config `animalforest-jp.yaml:3943`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

14. Source `src/overlays/weather/ac_weather_snow/ac_weather_snow.c`; header `src/overlays/weather/ac_weather_snow/ac_weather_snow.h`; assembly `asm/jp/nonmatchings/overlays/weather/ac_weather_snow/ac_weather_snow/`; config `animalforest-jp.yaml:5932`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

15. Source `src/overlays/weather/ac_weather_leaf/ac_weather_leaf.c`; header `src/overlays/weather/ac_weather_leaf/ac_weather_leaf.h`; assembly `asm/jp/nonmatchings/overlays/weather/ac_weather_leaf/ac_weather_leaf/`; config `animalforest-jp.yaml:5972`. Structural: none observed. Unsafe/uninitialized: none identified in cheap survey; unselected routines remain unverified.

Gypsy wins because all fourteen functions fit comfortably within 28 attempts,
its largest function is 272 bytes, there is no draw/matrix work, existing
private data already models wallet and destiny precisely, and corresponding
GC code closely explains the entire control flow and terminology. Four local
tail fields plus three straightforward API declarations make 100% attemptable.
The higher-byte NPC alternatives have broader mail/player/save interactions;
the graphic alternatives have lower completion confidence. Ride-off demo has
small functions but requires more player/camera ABI research. No loser was
edited. The winner's full identity, classifications and verification are in
research/ev-gypsy.md. Raw fresh inventory and per-function data are in ignored
build/rank-next/inventory.json and ranking.json.
