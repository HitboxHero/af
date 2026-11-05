# Mechanics and research notes — not defects by default

The project notes contain many useful observations about first-generation GameCube code. Preserve them as research references without treating them as defects in the original Japanese N64 cartridge.

## Stalk Market prediction and turnips

The supplied GameCube transcript describes Sunday buying prices reportedly 70–129 bells per turnip, Monday–Saturday prices derived from seeded state, rare 8× Sunday-price spikes, and predictable patterns. These are **GameCube observations**; inspect N64 turnip manager, RNG seed, schedule and clock behavior before using the figures in a patch or guide. Predictable RNG alone is not a bug. The material mentions a nonspoilage exploit but provides **no reproducible sequence**, so this is not an active bug.

## Letters as gameplay

A villager-specific request to receive a letter can use different reward logic from ordinary language scoring in the GameCube research: rank 0–11, a length component, a three-word/nonrepetition component, and an attached-present component. For English, see `LOC-008` through `LOC-011`; test N64 applicability before implementing the GameCube-specific quest behavior.

## Famicom games and Controller Pak

N64 already contains Nintendo/Famicom minigame functionality and research into special Controller Pak notes, including Ice Climber. Existing shipped behavior is to be preserved in English; additional compatible games, safe missing-ROM paths and storage work are Enhanced research. Any reference to sample ROM names/headers is not an instruction to bundle copyrighted games. Original user research included Pak layout/formatting and physical device testing.

## Unused and development material

The notes mention paper airplane, whale, sickle, gold collision cube, debug clothing display, `SOLDIER1`, `SOLDIER2`, `OBA`, early Blathers/Wisp and dungeon maps. Source provenance is crucial: retail N64 assets, later GameCube assets and leak-only developmental data are not interchangeable. Do not call unfinished prototypes 'N64 bugs' until a feature exists in the unmodified playable ROM. The original source material also mentions in-engine developer mode research: https://jamchamb.net/2018/06/09/animal-crossing-developer-mode.html

## Sources from the submitted notes

- Original project vision/notes (2026-10-30) and appended technical transcripts (2026-11-05).
- `https://www.youtube.com/watch?v=EWWu0CNrMds` (later-release glitch descriptions; cross-check exact version before claiming applicability).
- `https://www.youtube.com/watch?v=R7WGwVzlMBk&t=320s` (paper airplane demonstration).
- `https://www.youtube.com/watch?v=VB0kLldqid0` (Spring Sports Fair / mortgage interaction).
- `https://github.com/Prakxo/ac-decomp/` (GameCube decomp, reference only).
- `https://github.com/zeldaret/af` (upstream matching N64 project).
- `https://nookipedia.com/wiki/Doubutsu_no_Mori%2B` (major GC additions absent from original N64).

**Important:** Videos and transcript explanations identify hypotheses, not independently verified N64 code facts. Attach concrete symbol addresses, hashes and test results as work proceeds.

## Additional preserved references and provenance

The source research was a mix of direct project ideas and game-specific transcriptions, not a fully validated set of reports. The documentary data should be treated as **candidate evidence** until reproduced against its specific version. Several transcript blocks duplicate the same cases; they have been consolidated above.

1. **Original project notes:** *Animal Forest 64 — Development Roadmap*, dated 2026-10-30, plus the appended documented bugs, tool ideas and video transcripts provided with this revision.
2. **Hunter R., “Fixing Animal Crossing's Broken Code”** (technical GameCube-focused source, timestamped chapters): https://www.youtube.com/watch?v=EWWu0CNrMds — remote sapling, sakura, flying snails, dump rating, coconut table, wrong item IDs, Tortimer diaries, oranges, lunar dates, prototype airplane.
3. **Paper airplane demonstration** (originally linked in notes): https://www.youtube.com/watch?v=R7WGwVzlMBk&t=320s
4. **Mortgage/Spring Sports Fair demonstration:** https://www.youtube.com/watch?v=VB0kLldqid0
5. **Animal Crossing developer mode/technical notes:** https://jamchamb.net/2018/06/09/animal-crossing-developer-mode.html
6. **N64 content and Controller Pak reference:** https://nookipedia.com/wiki/Doubutsu_no_Mori_%28game%29
7. **First-generation differences/reference features:** https://nookipedia.com/wiki/First_generation
8. **NES furniture/Controller Pak behavior:** https://nookipedia.com/wiki/NES_games

**Source limitations:** Original user notes include transcribed demonstrations without a direct URL for every clip. IDs, date ranges, percentage match, unusual mechanics and numerical claims are **research prompts** until traced to N64 code or an identified GameCube revision. N64 has no vanilla GameCube island, museum, Able Sisters or e-Reader hardware integration; therefore, those dependencies must not be reported as already broken in vanilla Japanese N64.

---

## Integration source

`Animal_Forest_All_In_One_README.md`, supplied from `C:\Users\Alex\Downloads`, integrated November 5, 2026; SHA-256: `890318ac60d002929e7275855398cc5139872d28e2a0cf801477e0017e528356`. Specifications were split without treating reports as verified facts. External links are preserved research citations; their contents were not independently revalidated in this documentation task. The supplied paper-airplane link retains its 320-second timestamp. No additional memory addresses or video timestamps have been invented.

## Previous README content ID migration

The supplied All-in-One establishes the canonical content IDs. Earlier uncommitted README labels map as follows; use subject and source revision when reading old notes.

| Previous README ID | Canonical ID | Subject |
|---|---|---|
| CONTENT-013 | CONTENT-020 | Title/K.K. audio |
| CONTENT-014 | CONTENT-016 | Visual refinements |
| CONTENT-015 | CONTENT-013 | Events |
| CONTENT-016 | CONTENT-014 | Golden tools |
| CONTENT-020 | CONTENT-028 | Custom villager import |

Previous localization IDs were also condensed; current LOC-001 through LOC-016 are defined only by [Localization](LOCALIZATION.md). In particular, old LOC-006 letter-quest references now mean LOC-010; ordinary scoring is LOC-008/009.

## Additional supplied links

- [N64 to GameCube additions](https://nookipedia.com/wiki/Doubutsu_no_Mori%2B).
- [Supplied upstream CI badge endpoint](https://github.com/zeldaret/af/actions/workflows/ci.yml/badge.svg?branch=main) (upstream only; README retains the original badge URL).
