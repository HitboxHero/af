# Animal Forest 64 — Project Roadmap & Verification Register

> **Project:** どうぶつの森 / *Dōbutsu no Mori* (Nintendo 64, Japan, 2001)  
> **Last roadmap revision:** 2026-11-05  
> **Source:** Consolidated from the project's 2026-10-30 roadmap, glitch notes, and transcribed research.  
> **Important:** The bugs below are **research reports, not claims that the Japanese N64 ROM has been tested**. Every issue starts unverified unless linked evidence is added.

## 1. Project vision: two separate games

The aim is to preserve the feel of the original 2001 N64 game while producing two distinct, fully playable releases:

### Edition A — Animal Forest 64: English Edition (`EN`)

**A proper English localization of the original Japanese N64 game, with verified bug fixes.** Imagine an official English N64 release that received careful stability and correctness patches.

- Translate the original script, letters, menus, item descriptions, names, and events; provide readable English input and English-compatible Animalese.
- Preserve original N64 town layout and mechanics, seasonal pacing, visual identity, sound, economic balance, and **four human player slots**.
- Fix crashes, save corruption risks, broken conditions, unintended behavior, and translation-introduced defects **only when verified against the N64 build or demonstrated in the new localization**.
- Do **not** silently add GameCube-exclusive locations, furniture, characters, or convenience systems to this edition. Restore ordinary intended behavior when an original N64 bug is proven, but treat major dormant feature completion as Enhanced work.
- Aim to keep the stock **16 MiB** ROM if feasible; investigate larger layouts rather than imposing a hard limit that blocks a complete translation.
- Support unexpanded original N64 hardware and test saves, RTC, Controller Pak, rendering, and performance on real hardware.

### Edition B — Animal Forest 64: Enhanced Edition (`EX`)

**A superset of the stable English Edition:** the strongest feasible first-generation *Animal Crossing* experience on one N64 cartridge, incorporating selected *Dōbutsu no Mori+*, North American *Animal Crossing*, *Dōbutsu no Mori e+*, recovered N64 concepts, and genuinely useful quality-of-life changes.

- Inherit every accepted localization fix and N64 bug fix from `EN`.
- Add the museum/Blathers, Able Sisters, island/Kapp'n, collection and storage improvements, selected characters/events, and researched unused content, as projects pass feasibility gates.
- Explore 32 MiB ROM packaging, save expansion/migration, assets, performance work, optional Expansion Pak benefits, and—much later—optional network/cartridge-assisted features.
- Preserve a recognizable N64 presentation and playable **offline** experience. No required peripherals for normal gameplay unless a feature is clearly labeled optional.

**Interpretation rule:** “GameCube-like polish” means correctness and usability for `EN`, **not** an unconditional requirement to include every GameCube feature. GameCube and e+ content belongs to `EX` unless explicitly moved by a recorded decision.

### Three parallel code lines

1. **`match` / Japanese reference:** binary-matching decompilation and verified reference ROM; no functional edits.
2. **`english`:** localization plus eligible, validated bug-fix commits.
3. **`enhanced`:** built from stable `english` plus approved QoL/content/technical changes.

Do not mix restoration experiments into `match`. Changes in `english` must be cherry-pickable/mergeable into `enhanced`. Source translation data and master CSVs should be versioned independently of game code.

---

## 2. How issues are tracked

### Required metadata and status vocabulary

| Field | Meaning |
|---|---|
| `ID` | Stable `BUG-###`, `QOL-###`, `CONTENT-###`, `LOC-###`, or `TECH-###`; never recycle IDs. |
| `Target` | `EN`, `EX`, `BOTH`, or `RESEARCH`. `BOTH` means fix in English, inherited by Enhanced. |
| `Origin` | `N64?` requires verification; `GC` reported in one or more GameCube releases; `N64-asset` dormant asset/code; `NEW` proposed addition. |
| `Priority` | `P0` data loss/crash/security, `P1` broken gameplay/progression, `P2` gameplay/visual correctness, `P3` minor/optional. |
| `Status` | `Unverified` → `Reproduced-N64` or `Not-present-N64` → `Code-confirmed` → `Fix-in-progress` → `Fixed` → `Regression-passed`. Also `Blocked`, `Won't fix`, `Deferred`. |
| `Evidence` | ROM variant/hash, emulator/core or console, date/time/RTC, save or town seed, exact instructions, result, video/screenshot, matching code location, and commit/PR. |

`GC` is **not evidence of N64 applicability**. A confirmed GC-only bug may be `Not-present-N64` and closed as **not applicable** to `EN`; reopen against `EX` if the relevant system is imported. Where the notes say an item or feature is absent from N64, first test for its presence instead of inventing an in-game reproduction.

### Standard issue workflow (use for every bug)

1. **Inventory:** search the Japanese ROM/decomp for the relevant item, event, branch, lookup table, messages, and source function; compare GC code only as a reference.
2. **Reproduce on unmodified Japanese N64:** use a disposable save and a precise setup. For RNG bugs, inspect code or run seeded/sampled tests rather than interpreting one failed random roll as proof.
3. **Record actual vs expected:** a null result is valid, especially for features missing from N64.
4. **Patch minimally** in a nonmatching branch; write a deterministic regression test, assertions, or reproducible emulator test case.
5. **Validate:** compare unmodified/patched behavior, verify four-player state, time travel/RTC, save integrity, soft reset, and real hardware when possible.
6. **Close** with observed version(s), code symbols, commit hash, and known remaining caveats.

**Test data discipline:** keep a clean vanilla save, disposable edge-case saves, and before/after snapshots; never test a crash, item injection, save migration, or out-of-bounds glitch on the sole copy of a town. For dates and events, record the year and clock source. For third-party ROM/data tests, use legally obtained assets and distribute patches rather than proprietary ROMs.

### Verification ticket template

```md
### BUG-XXX — Short title
- Target: BOTH | Origin: N64? | Priority: P1 | Status: Unverified
- Reported versions / source:
- Prerequisites: exact save, item, town, date/time, external hardware
- Steps: 1. ... 2. ... 3. ...
- Expected:
- Reported actual:
- Japanese N64 result: NOT TESTED / PRESENT / ABSENT / BLOCKED
- Suspected code/data: symbols, file, table, item IDs (if verified)
- Minimal patch plan:
- Regression: normal path, boundary case, saves, original hardware
- Evidence: save, clip, emulator version, ROM hash, commit/PR
```

---

## 3. Development phases and release gates

- [ ] **Phase 0 — Reference and test harness.** Pin ROM checksums, reproducible toolchain, asset extraction, source translations, save backups, original hardware/emulator smoke tests, and issue registry. Maintain a clean `match` output.
- [ ] **Phase 1 — Matching decompilation.** Keep replacing assembly with byte-identical C, identifying structs/functions/fields, and documenting uncertainties. **Historical snapshot:** source roadmap reported **20.11% matched on 2026-10-30**; this is *not* a current measurement.
- [ ] **Phase 2 — English playable vertical slice.** Start → train/Rover/Nook → town → inventory → dialogue/letters → save/reload → RTC → a holiday. Validate font width, control codes, name insertion, menu layout, item IDs and localized text scores.
- [ ] **Phase 3 — English bug-fix verification.** Work through `BUG` tickets, focusing on P0/P1 and N64-confirmed cases. Disallow unreviewed gameplay expansion. Release a stable faithful English build.
- [ ] **Phase 4 — Enhanced technical foundation.** ROM expansion if necessary, map/object budget, larger assets, save format versions/migration, hardware performance limits, asset compression/loading benchmarks.
- [ ] **Phase 5 — Enhanced core conveniences.** Museum/fossils, multi-select/selling/storage, map/encyclopedia/mail, then optional imported characters/events.
- [ ] **Phase 6 — Expanded first-generation content.** Island/Kapp'n, Able Sisters, selected GC/e+ content, restored dormant features, new NES experiences, improvements to appearance/audio.
- [ ] **Phase 7 — Experimental systems.** In-game GBA-inspired minigame, Controller Pak/SD-style export, custom villagers, optional flashcart/wireless exchange, asynchronous town visits, live visits only if feasible.

**English release gate:** complete translation coverage; no known P0s; major P1s addressed or documented; reliable save and RTC on real hardware; no unexplained regressions relative to vanilla.  
**Enhanced milestone gate:** feature remains optional until a proof of concept passes performance, save, input/UI, and return-to-town tests on actual N64 hardware. **No promised launch dates.**

---

# 4. BUG FIXES — separate defect backlog

**Scope rule:** these are faults to *identify*, not blanket claims that Japanese N64 suffers them. A GC-only problem is a **porting regression test** if Enhanced later adds that GC system. Duplicate mentions in the notes have been merged under one ID; distinct failure modes of one subsystem are tested together.

## 4A. World simulation, randomness, calendar, and wildlife

### BUG-001 — Saplings die because a south-edge acre check reads a distant acre
**Target:** BOTH if reproduced | **Origin:** GC report; N64? | **Priority:** P1 | **Status:** Unverified.

- **Reported mechanism:** the bottom-edge-neighbor lookup uses `[acreZ + 1][acreZ]` instead of `[acreZ + 1][acreX]`. In the source example, a sapling at the bottom of **B5** should check **C5** but instead tests **C2**, causing remote obstruction to kill it.
- **Reproduce:** (1) Use a town/save where B5/C5/C2 are accessible and mark the same tile pattern. (2) Plant a sapling on B5's bottom boundary, with the directly adjacent C5 tiles unobstructed. (3) Place/retain an obstruction in the *corresponding checked* location of C2; maintain a control save with it clear. (4) Advance the normal growth tick by one day; compare outcomes. (5) Repeat with another column and a non-boundary tree.
- **Expected:** only the actual adjacent C5 tiles affect B5's sapling. **Reported actual:** remote C2 blockage causes wilting.
- **Verify/fix:** locate acre-edge validity lookup; correct column argument, and check north/east/west boundary handling. Regression: edge and interior plots, legitimate blocked plots, town layouts with different acre arrangements.

### BUG-002 — Light cherry-blossom weather never selected
**Target:** BOTH if present | **Origin:** GC report; N64? | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** the early-April weather selection references **light snow** instead of **light sakura**, rendering the intended light sakura variant unreachable.
- **Reproduce:** (1) Confirm the light-sakura effect and schedule exist in Japanese N64 data. (2) Set/test **April 5–7** under controlled weather RNG; inspect weather-effect enum and spawn branch. (3) Compare normal sakura and forced light-sakura rendering. **Expected:** light sakura can occur on scheduled days. **Reported actual:** it never naturally triggers.
- **Fix/regression:** change the referenced effect/condition if code confirms it; check April 4–8 and all snow/rain seasons. Do not assume that a GameCube seasonal table matches N64.

### BUG-003 — Non-native orange fruit excluded by off-by-one RNG
**Target:** BOTH if present | **Origin:** GC report; N64? | **Priority:** P1 | **Status:** Unverified.

- **Reported mechanism:** fruit IDs `0..4` are selected using an RNG range of `0..3`. The same code increments the selected ID when it matches the native fruit. This can yield orange (ID `4`) via the peach (ID `3`) case, but not normally when native fruit is apples, cherries or pears.
- **Reproduce:** (1) Prepare towns with apple/cherry/pear native fruit plus peach and orange controls. (2) Trigger the non-native fruit reward path from villagers, letters, and balloon gifts **only if each path exists on N64**. (3) Instrument/seed the RNG or exhaustively enumerate input indices. (4) Record which IDs are reachable for each town fruit. **Expected:** every eligible non-native fruit can be selected. **Reported actual:** oranges are unreachable for several native-fruit types.
- **Fix/regression:** select uniformly from a four-element list *excluding* the native fruit, rather than merely changing `RANDOM(4)` to `RANDOM(5)` (which could produce ID `5` after the existing increment). Preserve other fruit reward probabilities if intentional.

### BUG-004 — Tortimer's 16th New Year's diary never awarded
**Target:** BOTH if the reward set exists | **Origin:** GC report; N64? | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** 16 diary variants are indexed `0..15`, but the random-selection expression effectively produces `0..14`; item ID **`0x2B0F`** (reported calligraphy pad) is unreachable.
- **Reproduce:** (1) Confirm the N64 New Year's Tortimer reward table and ID mapping. (2) Set date to New Year's event, collect rewards on disposable saves, or directly enumerate selected indices in a test harness. (3) Show maximum index selected is 14. **Expected:** all 16 table entries have nonzero chance. **Reported actual:** entry 15 is never selected.
- **Fix/regression:** adjust random bound to include all verified entries, then check all item IDs and distribution; test event after save/reload.

### BUG-005 — Cockroach escape jump chooses one fixed, wrong direction
**Target:** BOTH if present | **Origin:** GC report; N64? | **Priority:** P3 | **Status:** Unverified.

- **Reported mechanism:** a random function called with `1` produces only `0` before conversion; a cockroach's intended two-direction jump always uses the same ~22.5° direction, reportedly toward the player.
- **Reproduce:** (1) Load an infested house after sufficient absence (or spawn roaches in a disposable debug save). (2) Approach from several angles; repeat jumps with logged RNG outputs and player-relative angles. (3) Compare observed vs intended two-branch outcome. **Expected:** both escape directions reachable. **Reported actual:** one fixed branch.
- **Fix/regression:** use a correctly bounded random Boolean/index; verify roach motion, collision and despawn.

### BUG-006 — Snail flies away when the inventory is full
**Target:** BOTH if present | **Origin:** Japanese/NA GC report; N64? | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** the special release path for catching a snail with no free pocket slots uses a generic flying-insect release animation instead of the snail's ground-release animation. Reportedly fixed in AU/EU GameCube versions.
- **Reproduce:** (1) Fill all pockets. (2) During rain, net a snail from a flower. (3) Observe immediate automatic release. (4) Compare against releasing a snail manually with free space and against catching an ant at full capacity. **Expected:** snail drops/crawls on ground. **Reported actual:** snail visibly flies away.
- **Fix/regression:** route automatic release through the snail's species-specific animation. Confirm snail availability in N64 before classifying N64 bug.

### BUG-007 — Butterflies land only on white pansies
**Target:** BOTH if proven unintended | **Origin:** GC report; N64? | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** the flower lookup/landing eligibility apparently accepts white pansies alone rather than the intended broader set of flowers. This could be a restrictive rule rather than a coding error; prove intent before fixing.
- **Reproduce:** (1) Lay out equal test patches of each existing flower species/color with matching empty space. (2) Spawn/observe eligible butterflies repeatedly under consistent time/weather. (3) Log resting targets or inspect landing predicate. **Expected (proposal):** butterflies can pause on multiple compatible flowers. **Reported actual:** rest on white pansies only.
- **Fix/regression:** extend eligibility only after reviewing the table and behavioral design. If intentional, move to `EX` as a wildlife enhancement instead of an `EN` bug fix.

### BUG-008 — Released arapaima has an oversized ground shadow
**Target:** BOTH if present | **Origin:** GC report; N64? | **Priority:** P3 | **Status:** Unverified.

- **Reported mechanism:** the release animation lacks a correct shadow-scale index for the game's sole “huge” fish class; the arapaima casts an excessively wide oval.
- **Reproduce:** (1) Obtain an arapaima and a large comparison fish (for example, coelacanth). (2) Release them from pockets at similar camera positions and capture their brief shadow projections. (3) Compare the species-to-shadow-size lookup. **Expected:** shadow proportional to released fish. **Reported actual:** arapaima's shadow scale is wrong.
- **Fix/regression:** add the correct huge-fish shadow entry; confirm other fish classes and catch/release animation unaffected.

### BUG-009 — Train audio attenuation wrong in a three-tier town
**Target:** BOTH if present | **Origin:** GC report; N64? | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** vertical/Y-coordinate mapping isn't updated for three-layer town terrain, reportedly making the train much quieter than intended.
- **Reproduce:** (1) Compare equivalent train arrival/departure scenes in verified two-tier and three-tier town layouts. (2) Capture audio at fixed output gain, player position and train phase. (3) Log emitter and listener Y coordinates if available. **Expected:** sound attenuation follows actual spatial positions. **Reported actual:** disproportionate quietness in three-tier maps.
- **Fix/regression:** correct the vertical-coordinate reference or map-height conversion; check other positional audio sources and both layouts.

### BUG-010 — Town rating incorrectly penalizes trash in the dump at startup
**Target:** RESEARCH; EX if museum/town-rating system ported | **Origin:** GC report; N64 applicability unproven | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** startup rating reads dump coordinates from the title-screen/demo town (reportedly an N64-derived town without the GC dump), not the player's town. A manual assessment at the wishing well uses the correct coordinates.
- **Reproduce:** (1) In a GC reference or port containing a dump, place trash **inside** the legal dump bounds; ensure all other rating inputs are controlled. (2) Save and restart; record the startup rating/effects. (3) Recheck at the wishing well. (4) Compare calculations with trash removed and trash outside the dump. **Expected:** dump trash exempt in both paths. **Reported actual:** startup-only penalty, corrected by manual evaluation.
- **Fix/regression:** defer assessment until player town data/dump coordinates are initialized or pass the actual town state explicitly. Original N64 may not have this GC dump configuration; establish applicability first.

### BUG-011 — Harvest Moon event uses incorrect precomputed dates
**Target:** BOTH if the event/calendar exists | **Origin:** GC report; N64? | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** stored lunisolar-derived festival dates through **2030** can be off by one or two days, despite intending the 15th day of the eighth lunar month. The research notes state more than half of the GC dates are wrong; do not assume the N64 table is identical.
- **Reproduce:** (1) Locate the N64 holiday scheduling table/date algorithm. (2) Enumerate all supported calendar years and map in-game dates to the defined target holiday. (3) Compare against an authoritative date table with timezone/calendar convention documented. (4) Boot one correct and one incorrect year to validate the actual festival. **Expected:** event on intended annual date. **Reported actual:** some event dates shifted.
- **Fix/regression:** correct actual wrong entries or use a properly bounded computation. Protect the supported clock range, leap years and year rollover. **Post-2030 support is a separate Enhanced feature, not an automatic bug-fix assumption.**

### BUG-012 — Morning aerobics weather/event state becomes stale
**Target:** RESEARCH / EX on port | **Origin:** NA GC, reportedly fixed AU/EU; N64? | **Priority:** P2 | **Status:** Unverified.

- **Reported failure A (island reload):** during a rainy aerobics day, visit sunny island; enter island cabana to reload map; event initializes as if clear; return immediately to mainland and aerobics runs in rain until a later reload. **This reproduction requires the GC island and cannot be run unchanged in vanilla N64.**
- **Reported failure B (midnight ordering):** load **11:59 p.m.**, remain outside through midnight and until **6 a.m.** without any map reload. If weather changes after the midnight scheduling check, aerobics can be scheduled under rain (station announcement but villagers idle, Tortimer/Copper/radio missing), or incorrectly canceled on a clear day. Use scripted RTC/weather changes rather than waiting six hours during every development run.
- **Expected:** weather and event schedule agree; no partially populated event. **Fix/regression:** use authoritative daily weather state when scheduling, not stale live-rendered weather; rerun event initialization consistently. Verify event actually exists in N64 and what its N64 cancellation rules are.

### BUG-013 — Coconut beach-spawn table excludes its last item / coconuts count as shells
**Target:** EX only if island implemented | **Origin:** GC island report; vanilla N64 has no island | **Priority:** P1 for island | **Status:** Unverified.

- **Reported mechanism:** copied “rare shell island” table is declared with **two** entries rather than **three**; the final coconut entry is never selected. A separate linked behavior counts dropped coconuts toward a reported four-shell-per-acre spawn cap.
- **Reproduce A:** (1) In the GC reference/EX island, safely harvest and remove all naturally spawned coconut trees/coconuts; (2) trigger repeated beach respawns or enumerate the table; (3) confirm coconut never selected despite text promising wash-ups. **Expected:** finite chance of a replacement coconut. **Reported actual:** none.
- **Reproduce B:** drop four coconuts within each test beach acre; advance normal shell-spawn checks; compare to an empty beach control. **Expected:** shell cap should account for intended object types. **Reported actual:** shells stop spawning because coconuts consume the quota.
- **Fix/regression:** correct table length, verify coconut pickup/planting and shell quota. Decide explicitly whether coconuts should count as beach objects for cap logic (a separate gameplay policy), then test no-coconut recovery and full-beach conditions.

## 4B. Player state, collisions, crashes, items, and exploits

### BUG-014 — Axe durability changes when an interaction cancels the swing
**Target:** BOTH if present | **Origin:** GC report; N64? | **Priority:** P1 | **Status:** Unverified.

- **Reported mechanism:** pressing `A` with an axe increments a hidden hit counter *before* the full swing/durability check. A bulletin board, town-tune board, or doorway takes priority and cancels the swing, leaving the counter incremented. Non-tree collision adds **3**; normal tree hit adds **1**; durability update normally runs at **9**. A signed one-byte counter can cross `127`, be treated as negative, or overflow after `255`, affecting breakage.
- **Reproduce (premature wear):** equip new axe; read bulletin board **three** times with axe out; then hit a tree; compare durability with a control axe that never interacted. Reported result: new axe wears far faster (can break after about nine real tree hits if repeatedly manipulated).
- **Reproduce (extended wear):** prepare an axe close to breakage; trigger ~**40** board interactions, then use it on trees. Instrument hit-counter byte and compare its signed interpretation. Reported result: extended/infinite practical durability is possible by repeating the trick. Check board, tune board, and door separately.
- **Expected:** only a completed swing changes wear. **Fix/regression:** increment or commit wear only after animation/collision completion, or roll back on interaction cancellation; test tree hits, misses, hard-object hits, sign/door/menu interaction, reset, and counter limits. Keep intended base durability.

### BUG-015 — Paper airplane prototype duplicates, crashes, and softlocks control
**Target:** RESEARCH; EX if restored | **Origin:** unused/beta item, reported in GC | **Priority:** P0 if obtainable; otherwise P3 | **Status:** Unverified.

- **Merged reports:** (a) an injected airplane duplicates each map reload, eventually crashing; (b) it can be picked up/thrown, with stick influence over flight; (c) throwing enters an input-refusal state that never properly restores player control; (d) substituting an axe-like player state prevents the lock but permits throwing during dialogue/boat sequences, causing camera/music/interaction corruption. Also noted: letter-writing behavior and transparent/incomplete object visuals.
- **Reproduce:** (1) Find whether airplane object/actor/textures exist in Japanese N64. (2) In a **throwaway** hacked/debug save, place **one** airplane, reload map repeatedly, and count instances/memory. (3) Pick it up, throw and wait for landing; attempt movement/menu/tool actions. (4) If testing an experimental state workaround, try throwing during an NPC conversation and a cutscene; check return of input/camera/audio. **Expected:** single persistent item and full return to a valid idle state. **Reported actual:** replication/crash or softlock/state corruption.
- **Fix/regression:** if not accessible in normal N64, do *not* add to `EN`. For `EX`, give airplane an explicit lifecycle, ownership/persistence rules, throw-state guard, cleanup callback, disallowed-action checks and complete render/interaction data. Never rely solely on assigning a random existing player state.

### BUG-016 — Snowball/signboard interactions push the player outside valid collision bounds
**Target:** BOTH if present | **Origin:** GC exploit; N64? | **Priority:** P1 | **Status:** Unverified.

- **Reported mechanism:** snowball movement during item pickup/other animations, possibly combined with signboard positioning, pushes a character through boundaries or into unintended acre coordinates.
- **Reproduce:** (1) On snow day, position a snowball beside a signboard, wall, acre edge or blocking object. (2) Start item pickup/interaction while snowball contacts/pushes player; repeat at all relevant facings. (3) Log player coordinate, collision flag and current acre when movement resumes. (4) Test signboard collision separately from snowball push. **Expected:** collision stops at valid geometry, interaction completes normally. **Reported actual:** player exits walkable bounds.
- **Fix/regression:** enforce collision/position validation after scripted movement and before restoring movement; avoid overcorrecting legitimate snowball pushing. Link to downstream `BUG-017`.

### BUG-017 — Opening the map while outside valid acres can crash
**Target:** BOTH if present | **Origin:** GC exploit; N64? | **Priority:** P0 | **Status:** Unverified.

- **Reported mechanism:** map view assumes a valid acre index; an out-of-bounds player position can index invalid map/town data.
- **Reproduce:** (1) On disposable save, use `BUG-016` or a safe developer/debug warp to set invalid acre coordinates. (2) Open the map. (3) Observe crash/lock; record exact invalid row/column and game state. (4) Test normal boundary acres. **Expected:** reject/clamp invalid location or recover safely. **Reported actual:** crash.
- **Fix/regression:** validate index in the map *and* fix underlying OOB movement; test negative coordinates, above-maximum indices, transitions, and legal borders.

### BUG-018 — Mortgage payoff / Spring Sports Fair cutscene crash
**Target:** BOTH if present | **Origin:** external glitch video; N64? | **Priority:** P0 | **Status:** Unverified.

- **Reported symptom:** paying off home debt in conjunction with the Spring Sports Fair cutscene/storage sequence can crash the game. The user's notes do not specify the exact timing and inputs; **the source clip must be converted into reproducible steps before implementation**.
- **Reproduce candidate:** use duplicate saves immediately before paying the final installment; test final payment at the fair's event start, during its cutscene, before/after any home-storage interaction, and on ordinary days. Record cutscene state, debt stage, involved NPC, save event and crash point. **Expected:** debt cleared, house-upgrade dialogue completes, save remains usable. **Reported actual:** crash in the described overlap.
- **Fix/regression:** inspect scene transition, debt completion and storage/menu callbacks once exact conditions are identified. Do not treat the candidate sequence as a confirmed reproduction recipe.
- **Source:** https://www.youtube.com/watch?v=VB0kLldqid0

### BUG-019 — Diary message open/close on the same instant softlocks
**Target:** BOTH if present | **Origin:** glitch report; N64? | **Priority:** P1 | **Status:** Unverified.

- **Reported mechanism:** overlapping open and close message events leave diary/modal state invalid. Exact input/frame timing is not documented.
- **Reproduce:** (1) Open a diary/message in a disposable save. (2) Generate quick consecutive confirm/cancel inputs or frame-stepped simultaneous transition at the moment the message opens. (3) Repeat while closing and opening again with different game/input frame timing. (4) Check whether control and normal dialogue return. **Expected:** one valid message state, no permanent lock. **Reported actual:** softlock at a particular timing boundary.
- **Fix/regression:** serialize message state transitions, debounce duplicate events or enforce one ownership token per modal; test repeated and buffered input.

### BUG-020 — Nook code gift is permanently unopenable
**Target:** RESEARCH; EX if Nook codes added | **Origin:** GC-specific Nook-code system | **Priority:** P1 for port | **Status:** Unverified.

- **Reported symptom:** a gift generated by a secret Nook code may have an invalid wrapping/item state and cannot be opened.
- **Reproduce:** (1) Locate the *specific code* and resulting item/present ID from the original demonstration; none was provided in the notes. (2) On GC or an EX code-system test build, redeem it, pick up gift, attempt opening, saving/reloading and storing. (3) Compare to a normal wrapped gift. **Expected:** valid opening and inventory item. **Reported actual:** stuck present.
- **Fix/regression:** validate code-to-item mapping, wrapped-state flags and invalid item handling. **Vanilla Japanese N64 has no North American Nook-code feature**, so do not label as an N64 fix.

### BUG-021 — Nook password/control-code interpreter can execute unintended code
**Target:** RESEARCH; EX if password system added | **Origin:** GC code-path report | **Priority:** P0 if ported | **Status:** Unverified.

- **Reported symptom:** malformed Nook codes can cross data/control boundaries rather than cleanly reject invalid strings.
- **Reproduce safely:** in an isolated GC reference or development build, feed a corpus of invalid lengths, symbols, control bytes, checksum errors and boundary values to the decoder under a debugger. Confirm rejection vs unexpected jumps, memory writes, hangs or crashes; **do not place exploit payloads in production or users' saves**. **Expected:** invalid input rejected without unsafe memory access.
- **Fix/regression:** strict input size/charset, index bounds, decoder state, checksum verification and defensive error return. Include fuzz/regression tests. Not in stock N64 unless a matching interpreter exists.

### BUG-022 — An absent NES/Famicom ROM is selectable and crashes on launch
**Target:** BOTH if an invalid furniture/game path exists | **Origin:** GC/NES research; N64? | **Priority:** P1 | **Status:** Unverified.

- **Reported symptom:** certain catalogued test titles (notes mention a missing **second Zelda** game and a “20th NES ROM”) lack their binary; forcing playback can crash. The identity, count and release version need validation.
- **Reproduce:** (1) Inventory actual NES/Famicom furniture IDs, supported mapper/game table and embedded ROM resources in N64. (2) Distinguish a title omitted on purpose from an invalid selectable pointer. (3) Inject/select a missing ID **only in a disposable test**; observe whether missing-data check rejects it. (4) Compare available built-in games and Controller Pak-loaded games. **Expected:** absent ROM cannot launch; explanatory error. **Reported actual:** crash when forced.
- **Fix/regression:** never dereference missing game data; only expose playable games with verified image/memory constraints. Additional games belong to `EX`/`CONTENT-007`, not automatic English restorations.

### BUG-023 — Winter igloo reward table can produce dummy item `0x33C4`
**Target:** BOTH only if N64 igloo/reward exists; otherwise EX | **Origin:** GC igloo report; N64? | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** a leftover/dummy entry (`0x33C4`, **verify ID against target ROM**) was not removed from the igloo gift table, so campers can award it despite incomplete model/behavior.
- **Reproduce:** (1) Determine whether igloo visits/reward pool exist on N64. (2) In winter, accept igloo NPC item rewards, instrument selected table indices or enumerate the reward pool. (3) Check whether the dummy item can enter inventory and display. **Expected:** only valid rewards. **Reported actual:** dummy item is awarded.
- **Fix/regression:** remove/replace invalid entry and update effective table length; preserve intentional souvenir behavior. If N64 has no igloo, target EX when added.

### BUG-024 — Two legacy paintings never reach their special rejection dialogue
**Target:** EX museum import | **Origin:** *Dōbutsu no Mori+* / NA GC report | **Priority:** P2 | **Status:** Unverified.

- **Reported mechanism:** original N64 **Novel Painting** (Mondrian) and **Dreadful Painting** (Munch) persist as legacy IDs in later GC data; special Blathers refusal dialogue exists in GC/English, but the global “valid artwork” range checks only the normal first **15** paintings before the special case can run.
- **Reproduce:** (1) In GC reference/EX museum test, inject a valid legacy painting ID into a spare inventory. (2) Attempt to donate it. (3) Check that special “cannot accept this painting” dialogue is used instead of generic invalid-item dialogue. (4) Repeat with normal art. **Expected:** special branch reached for both legacy IDs. **Reported actual:** generic rejection.
- **Fix/regression:** make the two special legacy IDs eligible to reach the *refusal handler*, without marking them donatable normal paintings. **Do not remove or replace original N64 paintings from EN as a bug fix**; original N64 has no Blathers museum. If legally/distribution-relevant, handle art choices separately.

### BUG-025 — e-Reader card rewards bass fish instead of bass instrument
**Target:** RESEARCH; EX only if compatible card system added | **Origin:** GC e-Reader card report | **Priority:** P3 | **Status:** Unverified.

- **Reported mechanism:** Anicotti's card data points to a fish item ID rather than intended bass instrument.
- **Reproduce:** (1) Decode/scan the specific card in a compatible reference setup; compare card image/item ID and delivered inventory ID. (2) Repeat in EX import, if any. **Expected:** musical bass. **Reported actual:** bass fish.
- **Fix/regression:** correct item ID within licensed/owned test card data or compatibility mapping. N64 has no original e-Reader system.

### BUG-026 — Debug/cut collision object or golden cube duplicates in certain locations
**Target:** RESEARCH; EX if restored | **Origin:** unused asset report; version not identified | **Priority:** P3 | **Status:** Unverified.

- **Reported symptom:** “unused golden collision cube” duplicates in unspecified spots. Neither object ID nor reproducible coordinates were supplied.
- **Reproduce:** (1) Identify actor/model ID by decomp/assets and log original stage spawn conditions. (2) Place exactly one instance in a test acre; reload across transitions. (3) compare object count and ownership. (4) Test any originally reachable debug map. **Expected:** at most the authored instances. **Reported actual:** unintended multiple instances.
- **Fix/regression:** resolve spawner/ownership only if content is made accessible. Catalog as cut/debug asset otherwise, not a shipping N64 bug.

## 4C. Localization, dialogue, and imported feature correctness

### BUG-027 — English letter trigram lookup reads past its table into other data/RAM
**Target:** EN (prevent in new English implementation), EX inherits | **Origin:** NA GC letter-score bug; Japanese N64 scoring differs | **Priority:** P0 | **Status:** Unverified on N64; prevention required.

- **Reported mechanism:** English/GC scoring recognizes leading three-letter sequences (“trigrams”). A missing table terminator/bounds condition means search proceeds past the intended **776** trigrams and can interpret thousands of unrelated memory combinations as valid. The transcript cites over **23,000** apparent combinations and ~**5.8 MB** of inspected bytes; these are GC research figures, **not validated N64 memory sizes**.
- **Reproduce in reference:** (1) Score a valid three-letter prefix and an invalid/artificial prefix in NA GameCube. (2) Log lookup range/end pointer. (3) Check whether matching continues beyond the trigram table; repeat with different memory contents/save states. **Expected:** only explicit table entries score. **Reported actual:** out-of-bounds matches and inconsistent letter ranking.
- **EN implementation:** the **Japanese N64 algorithm is not a drop-in English scorer**. Specify English tokenization, punctuation, case normalization, word length and phrase/attachment rules. Implement bounds-checked trigram arrays with explicit lengths and unit-test all 26³ candidate trigrams plus adversarial letter lengths/characters. **Preserve intentional special letter-quest scoring** (see `LOC-006`) rather than conflating it with this defect.

### BUG-028 — Faraway fossil-assessment letter only triggers for inventory-held fossils
**Target:** RESEARCH in EN; EX UX redesign | **Origin:** user-reported N64-style event condition | **Priority:** P2 | **Status:** Unverified.

- **Reported concern:** a special faraway museum letter may depend on loading a game with a fossil currently in pockets. If the fossil was dug up and reburied before the next boot, the discovery/letter flag might never set.
- **Reproduce:** (1) Start fresh comparable saves. (2) Unearth a fossil and save/restart *with fossil in pockets* in save A. (3) Unearth/rebury the fossil before save/restart in save B. (4) Compare letter/event flags, mailbox arrival, and dates over the documented trigger window. (5) Test storage, transfer and several human characters. **Expected:** determine original intended eligibility before labeling behavior defective. **Reported actual:** letter missing for the reburied path, per project note; not yet confirmed.
- **Fix policy:** if a genuine discovery-flag oversight, correct the flag in `EN` without changing original event text. `EX` should provide direct Blathers fossil evaluation (see `QOL-008`) and adapt/remove obsolete mailing dependencies with a migration test.

### BUG-029 — Text/message control characters break when localized or when dynamic strings grow
**Target:** BOTH | **Origin:** localization regression-prevention ticket | **Priority:** P0 | **Status:** Unverified (preventive).

- **Mechanism to watch:** first-generation dialogue uses embedded commands for names, expressions, pauses, color, music, scene/quest branching and variable insertion. English expansion can overrun message capacity, corrupt a control sequence, or misalign pointer/offset tables.
- **Reproduce:** (1) For each translated message, round-trip decode/encode and compare preserved control-tag types/order. (2) Inject longest legal player/town/villager/item names and multiple variables. (3) Test pagination/window widths and branching dialogue during events, saves, and interrupts. **Expected:** valid parser and complete text rendering; no truncated commands or wrong branches.
- **Fix/regression:** explicit control-code schema, bounded encoder/decoder, message index/offset validator, font-width layout tests, and smoke-test all classes of scripted conversations. Track exact message IDs rather than inventing visible English text.

---

### BUG-030 — GameCube debug/beta objects use incompatible N64 texture references
**Target:** RESEARCH; EX only if importing affected GC/debug objects | **Origin:** GC debug-map regression; N64 object reportedly renders correctly | **Priority:** P3 | **Status:** Unverified.

- **Reported mechanism:** debug gyroid and an unused clothing-display rectangle in GC beta maps still reference N64-era texture/draw pathways, creating garbled models in the GC engine. The transcript explicitly says the original **N64 debug gyroid renders correctly**: therefore this is **not** an N64 defect to “fix.”
- **Reproduce:** (1) Identify the debug/beta map assets and associated draw functions in original N64. (2) Render them in a controlled developer map and capture their correct N64 appearance. (3) In a GC reference, render the counterparts and compare missing/garbled textures. **Expected:** correct textures on the target engine. **Reported actual:** corrupted GC beta textures.
- **Fix/regression:** document the correct renderer-to-texture mapping when porting/debugging content; do not transplant GC-specific renderer fixes into N64 code. If these objects remain unused, close as documentation only.

### BUG-031 — Turnips can reportedly evade normal spoilage in rare setups
**Target:** RESEARCH; BOTH only if N64 exploit verified | **Origin:** passing mention in GC Stalk Market transcript | **Priority:** P2 | **Status:** Unverified; reproduction unknown.

- **Reported symptom:** the research describes very limited, difficult exploits that cause turnips to **never spoil**, without supplying the actual steps or code branch. This is an investigation ticket, **not a reproduction claim**.
- **Reproduce candidate:** (1) Find the game's turnip age/expiration and save/RTC state logic. (2) Prepare fresh turnips with known purchase date, plus controls in pockets, storage, on ground and during travel if supported. (3) Advance time past the legitimate expiry and compare state transitions, including resets/clock changes and transfer actions. (4) If a reference exploit video/source is located, replace this candidate protocol with its exact deterministic sequence. **Expected:** turnips spoil according to the documented original rule. **Reported actual:** unspecified rare nonspoiling scenario.
- **Fix/regression:** preserve intended turnip strategy and price randomness; prevent a demonstrated missed expiration transition without retroactively spoiling legitimate items or breaking clock changes.

## 4D. Bug-fix triage summary

| Test order | IDs | Why |
|---|---|---|
| First | `BUG-017`, `018`, `019`, `027`, `029` | crashes, softlocks, memory safety, translation risk |
| Next | `BUG-001`, `003`, `014`, `016`, `028` | game correctness, progression, exploit behavior |
| Then | `BUG-002`, `004`, `005`, `006`, `007`, `008`, `009`, `011` | RNG, weather, animation, audio/calendar correctness |
| Feature-gated | `BUG-010`, `012`, `013`, `015`, `020`–`026`, `030`–`031` | often GC-only, cut content, or dependent on an Enhanced import |

**No fixes are marked complete by this document.** Do not use “Fixed” until the relevant code is changed, the specific failure is reproduced or statically proven, and regression evidence exists.

---

# 5. QUALITY-OF-LIFE IMPROVEMENTS — separate non-bug roadmap

These are **intentional behavioral changes**, not evidence of broken original code. **Default target: Enhanced only**. Each ticket has a user-visible acceptance test and prerequisite.

### QOL-001 — Item stacking (where safe)
- **Design:** stack genuinely equivalent items with clear count indicators; keep unique furniture, tools with wear, special quest items, wrapped gifts and letters distinct. Define stack maxima, splitting, overflow and sale values deliberately.
- **Acceptance:** add/pick up/sell/drop/store partial and full stacks without duping or losing items; save/reload, four residents, and Controller Pak travel preserve counts.
- **Depends on:** inventory schema and save migration (`TECH-003`). **Status:** Proposed.

### QOL-002 — Multi-select and bulk inventory operations
- **Design:** mark multiple pockets and sell, store, transfer, release or discard only the applicable group; keep a one-item flow for familiar play. Batch confirmations show total quantity/value and disallow incompatible actions.
- **Acceptance:** bulk sale yields identical Bells to individually selling the same items; no silent destructive action; cancellation rolls back entire transaction. **Status:** Proposed.

### QOL-003 — Faster Nook selling and depositing
- **Design:** streamlined dialog, fewer repetitive prompts and faster eligible deposit/sale interaction without altering prices or NPC personalities.
- **Acceptance:** bulk actions are atomic, dialogue does not skip important quest warnings, and totals match original. **Status:** Proposed.

### QOL-004 — Expanded and organized home storage
- **Design:** larger storage with optional categories/filters (clothes, furniture, fossils, collectibles, tools); preserve household/player ownership and original storage semantics where possible.
- **Acceptance:** full capacity, sorting, cancel, all four players, power interruption and version migration pass without duplication/loss. **Depends on:** `TECH-003`. **Status:** Proposed.

### QOL-005 — Collection encyclopedia and museum checklist
- **Design:** discovered/caught/donated progress for fish, insects, fossils, and other appropriate discoveries; use separate flags for *seen*, *owned*, *donated*. Show missing entries only to the extent desired for exploration.
- **Acceptance:** collection counts match inventory/capture/museum events across seasons; migration does not pretend undonated items were donated. **Depends on:** `CONTENT-001`. **Status:** Proposed.

### QOL-006 — More informative town map
- **Design:** improve wayfinding for civic buildings, shops, key locations and optionally villager residences/visited points without removing the original acre-map feel.
- **Acceptance:** icons update after moves and layout changes; no out-of-range crash (`BUG-017`); low memory footprint on console. **Status:** Proposed.

### QOL-007 — Mail organization and batch correspondence
- **Design:** quicker letter selection, archiving/organizing, safe attachment previews, composing/sending multiple letters, clear recipient status; retain original letter-writing charm and scoring rules.
- **Acceptance:** no invalid wrapping, lost attachments or message table breakage; proper scoring/quest letters; Controller Pak/letter capacity and migration checked. **Depends on:** `LOC-006`, `BUG-027`. **Status:** Proposed.

### QOL-008 — Museum fossil assessment by Blathers, no required distant mail
- **Design:** once museum exists, take fossils directly to Blathers for identification and eligible donation. The legacy “faraway museum” letter/event is adapted so it can still be encountered if desired; fossil **discovery** should not depend on leaving a fossil in pockets across a boot.
- **Acceptance:** dig → assess → donate in one session, including full-pockets handling and previously reburied fossils; original fossil discovery/mailing save flags migrate correctly; no double rewards. **Depends on:** `CONTENT-001`, `BUG-028`. **Status:** Proposed.

### QOL-009 — Better feedback for rare collection/quest conditions
- **Design:** contextual hints and readable status for submissions, special item eligibility, museum progress and letters where they reduce confusion without turning the game into a modern quest log.
- **Acceptance:** indicators reflect truth and cannot spoil hidden interactions unless explicitly enabled. **Status:** Candidate (not committed).

### QOL-010 — Optional faster recurring interactions
- **Design:** investigate skip/fast text for already-read repetitive responses, quick tool/item selection, and less menu friction while leaving first-time interactions intact.
- **Acceptance:** cannot skip a branch choice, advance an event twice, or softlock modal state. **Status:** Candidate (not committed).

**QoL release order:** Blathers/museum foundation (`CONTENT-001` + `QOL-008`), safe storage, bulk inventory, mail, encyclopedia, map; optional speed-ups last. Never add a convenience solely because a later game had it if the change erodes the original rhythm.

---

# 6. ENGLISH LOCALIZATION BACKLOG

| ID | Task and concrete definition of done | Status |
|---|---|---|
| `LOC-001` | Complete versioned JP→EN message catalog; translate dialogue, branching NPC text, events, menus, item descriptions, house/mail text and less-visible error/debug paths that the game may show. Preserve exact IDs and control characters. | In progress / coverage to measure |
| `LOC-002` | English font/glyph atlas, punctuation and special symbols; kerning or width measurement, wrapping, name-length limits, multiline dialogs, choice boxes and UI clipping tests. | Planned |
| `LOC-003` | English text entry: player/town names, diaries, letters and other prompts; keyboard UI, backspace, validation, save encoding and conversion from JP values if applicable. | Planned |
| `LOC-004` | Names, honorifics and culturally specific terminology policy: distinguish literal translation from official GameCube localization; document regional holidays/items not represented in original N64. | Planned |
| `LOC-005` | English Animalese: research GC phoneme sample mapping, playback timing and N64 sound-bank feasibility; fallback must be coherent if exact GC behavior is unavailable. | Research |
| `LOC-006` | Letter scoring: separate **regular English letter grammar/trigram scoring** and **special villager “send me a letter” quest ranking** (reported rank 0–11, length/three-word/repeated-character/attached-present checks). No OOB trigram reads. Test reward categories and original JP behavior as reference. | Planned |
| `LOC-007` | Event localization without unrequested event replacement: preserve original Japanese N64 calendar and traditional content in `EN`; evaluate localized regional holidays separately for `EX`. | Planned |
| `LOC-008` | Dynamic messages: test inserted player name, town, item, villager, mood, friendship, weather, time, town tune and event flags; keep rude/snarky personality distinctions instead of homogenizing dialogue. | Planned |
| `LOC-009` | Translation QA closed loop: record visual/in-game parity findings → search ±16/script graph/code context → propose protected versioned master changes → human review → incremental rebuild; prevent unapproved writes to original masters. | In progress (reported workflow; current integration to verify) |
| `LOC-010` | Train and title/save/error text audit: rover/Nook introduction, RTC/battery faults, Controller Pak warnings, N64 NES errors, Japanese-only strings, title-screen transitions. | Planned |
| `LOC-011` | Release matrix of string ID, font bounds, speaker, context, text/voice proof, gameplay proof, reviewer, and commit. Ensure four human residents and saved letters survive updates. | Planned |

**Localization is not just word replacement.** The notes describe first-generation scripts that use extensive embedded commands, >20,000 GC message offsets and dynamic branching. These GC measurements inform the *testing approach*, but the Japanese N64 message/offset counts must be measured directly.

---

# 7. ENHANCED CONTENT & RESTORATION — separate from bugs and QoL

These are additions or recovered experiences, **not original-N64 bug fixes**. Order them by readiness and keep anything introduced only as a research-video example in `Candidate` status until explicitly approved.

| ID | Feature | Planned use / acceptance target | Status |
|---|---|---|---|
| `CONTENT-001` | **Museum and Blathers** | Import/recreate museum building, working donation catalogs for fish/bugs/fossils/art, displays and Blathers dialog; integrate direct fossil assessment (`QOL-008`) and legacy-painting rules (`BUG-024`). | **Priority proposal** |
| `CONTENT-002` | **Able Sisters** | Shop/characters, clothing purchase/design behavior, location/town placement, schedules, dialogue, save rules; preserve original clothing mechanics where possible. | Proposed |
| `CONTENT-003` | **Animal Island and Kapp'n** | Boat route, boarding/return scenes, dedicated island acres, island resident, coconut recovery, island-only items/activities and weather transitions. Must leave mainland save valid (`BUG-012/013`). | Proposed; high complexity |
| `CONTENT-004` | **In-game “GBA island” recreation** | Dedicated embedded island minigame with a Game Boy Advance-style prop/UI rather than full GBA hardware emulation; self-contained minigame state and rewards. | Experimental |
| `CONTENT-005` | **More first-generation inventory** | Port selected GC/e+ furniture, clothing, fish, bugs, art, decorative items and special rewards; create item-ID namespace/mapping and UI text per entry. | Proposed |
| `CONTENT-006` | **More villagers and dialogue** | Selected GC/e+ residents, personalities, house data, dialogue, friendship/temper variety, move-in/out weights and interactions. Preserve personality variety and original spicier tone. | Proposed |
| `CONTENT-007` | **NES/Famicom support** | Preserve built-ins; research loading verified additional compatible games through collectible furniture, Controller Pak data or expanded ROM; reject missing/oversized data safely (`BUG-022`). | Proposed research |
| `CONTENT-008` | **Paper airplane, fully restored** | A working, rendered, throwable, nonduplicating object with player state/flight and safe cutscene restrictions; optional letter interaction if genuinely supported (`BUG-015`). | Candidate restoration |
| `CONTENT-009` | **Whale as catchable sea creature** | Research existing fish/whale ID, spawn/rarity, ocean position, hitbox, shadow, model/texture and dedicated catch text: currently hacked whale IDs may point to unrelated Able Sisters dialogue. | Candidate restoration |
| `CONTENT-010` | **Shaki gardening visitor** | Research “Shaki” asset/identity and feasibility of a Leif-like visiting gardening NPC; offer special gardening dialogue and paid weed removal. This is a new design, **not** confirmed N64 cut content. | Proposed |
| `CONTENT-011` | **Water bottle/trash item** | Identify referenced unused bottle texture; create fish-up-from-river/ocean pickup path, proper name/disposal/rarity rules and effects on town rating. | Proposed restoration |
| `CONTENT-012` | **Cut emotions/reactions** | Investigate “scared”/cut reaction and purple-mist effect retained in GC data; catalog animation IDs and reactivate only with complete actor/trigger/cleanup code. | Candidate restoration |
| `CONTENT-013` | **Additional K.K./title audio** | Research alternative title-song recordings and e+ percussion arrangement; adapt selectable or edition-specific tracks only if music banks, compression and CPU budget permit. | Candidate |
| `CONTENT-014` | **Visual refinements** | Tree/foliage/grass/buildings, decorative furniture, terrain, colors/baked lighting, modest geometry and texture handling; preserve N64-like silhouettes and predictable FPS. | Proposed |
| `CONTENT-015` | **Events and seasonal activities** | Port selected GC/NA/e+ events, holidays, seasonal items and dialogue without rewriting the original N64 calendar in `EN`. Date/time validation required. | Proposed |
| `CONTENT-016` | **Golden tools and other GC milestones** | Research GC tool/item mechanics absent from original N64 and choose self-contained, balanced additions. | Candidate |
| `CONTENT-017` | **e+ friendship, ailments, fleas** | Stronger friendship tiers, sick villagers requiring medicine, flea-catching with net, additional requests/dialogue; avoid disrupting original move-out/personality diversity. | Candidate |
| `CONTENT-018` | **e+ after-hours Nook** | Shovel knock to awaken Nook, altered movement and a documented late-night pricing penalty; verify 20%-buy/30%-sale figures against e+ code before porting. | Candidate |
| `CONTENT-019` | **Reset Surveillance Center** | e+ style rock entrance, hidden rooms and Resetti dialogue; requires robust acre/interior/resource allocation. | Candidate |
| `CONTENT-020` | **e+ custom villagers/card-equivalent content** | Optional tool for importing resident appearance/name/personality/clothes, with strict save/asset validation; do not presume real e-Reader hardware connectivity on N64. | Long-term experiment |
| `CONTENT-021` | **Town export/loan/screenshot ideas** | Investigate e+ SD-card town-exchange/limbo behavior and screenshots as inspirations. N64 storage/export hardware differs and needs an optional adapter/flashcart feature. | Long-term experiment |
| `CONTENT-022` | **Gigaleak/development leftovers** | Make a catalog of `SOLDIER1`, `SOLDIER2`, `OBA`, old Blathers/Wisp, dungeon map, sickle, unused clothes/media textures and beta objects; identify ROM-vs-leaked-only assets, copyright and feasibility before electing to restore. | Research only |
| `CONTENT-023` | **Ice Climber Controller Pak recreation** | Preserve/test N64 blank Famicom furniture reading a valid `NAFJ01` Pak note, NESINFO, iNES header, Yay0 and filesystem checks; document safe compatibility with Ice Climber and other tiny ROMs. | Research / documentation |
| `CONTENT-024` | **Expanded minigames and side activities** | Small native-N64 activities using existing actors/assets; separate from porting entire NES/GBA emulators. | Candidate |
| `CONTENT-025` | **Optional remote exchange** | Letters/presents first; then patterns/selected town data, asynchronous visits, live travel only after technical proof. Offline unaffected. | Long-term experimental |

### Enhanced content decisions requiring explicit approval

- **Original art vs replacement art:** retain the N64 originals in `EN`; for `EX` assess adding GC replacements and how museums classify original/alternate paintings. This is a content choice; `BUG-024` is specifically about unreachable refusal dialogue.
- **Regional holidays:** importing North American holidays and e+ events should be modular; English language does not automatically imply replacing every Japanese holiday.
- **Recovered prototype material:** a leaked object/texture or string is not proof of a complete playable feature. Maintain asset provenance and legal/distribution review before using leak-only resources.
- **“Best version on one cartridge”:** prioritize complete, polished features over accumulating incompatible or unstable features; retain optional fallback to normal N64 RAM.

---

# 8. ENHANCED TECHNICAL ROADMAP

| ID | Workstream | Acceptance / risk gate | Status |
|---|---|---|---|
| `TECH-001` | Reference build and branch isolation | Matching ROM hashes remain unchanged; reproducible local CI and `match` vs `english`/`enhanced` diffs. | In progress |
| `TECH-002` | ROM expansion | Profile 16 MiB usage; prototype 32 MiB mapping/asset tables/flashcart support **only if needed**; validate on real hardware. | Research |
| `TECH-003` | Versioned saves | Version and checksum metadata, original→Enhanced migration, safe fallback/rollback, all four residents, Controller Pak letter/travel files, crash-tolerant writes. | Proposed prerequisite |
| `TECH-004` | RAM and runtime budgets | Profile stock RDRAM and Expansion Pak separately; document heap, graphics pools, audio, scene/actor/entity limits and frame time. No mandatory Expansion Pak without explicit edition decision. | Planned |
| `TECH-005` | Asset loading and compression | Measure decompression time, asset residency and paging; implement changes only with memory/performance gain. | Planned |
| `TECH-006` | Rendering efficiency | Evaluate Kaze Emanuar-style N64 optimization concepts **by benchmark**, not by transplanting unrelated hacks; compare real-hardware FPS, visual parity and CPU/RSP/RDP use. | Research |
| `TECH-007` | Actor, map and content expansion | Allocate stable IDs for new items/actors/areas; validation for town generation, boundary indices, shop catalogs, dialogue references and event flags. | Planned |
| `TECH-008` | RTC/calendar modernization | Fix proven calendar bugs separately; explore post-2030 support with accurate festival rules, battery/RTC failure behavior and save migrations. | Experimental |
| `TECH-009` | Controller Pak NES pipeline | Validate 32 KiB Pak layout and reserved filesystem pages; robust NESINFO/Yay0/loader size and mapper checks; test emulator differences and hardware. | Research |
| `TECH-010` | Optional connected cartridge/wireless | N64↔server proof of concept; authenticate/validate exchanged data and preserve offline behavior; avoid corrupting save with untrusted remote packets. | Long-term |
| `TECH-011` | Localization parity/rebuild tooling | Protected official pair master, graph/context discovery, review approvals, incremental manifests, reproducible builds and source-vs-ROM checksum reports. | In progress |
| `TECH-012` | Hardware and regression test suite | Emulator plus original N64: cold boot, long sessions, save/load, RTC, Controller Pak, boundary acres, dialogs, audio, NES loading, event transitions, full pockets and multiplayer slots. | Planned |

## 9. Test matrix for all releases

Use a clean copy of the reference Japanese ROM, the current English build and (where applicable) Enhanced. For each build, log status as **Pass / Fail / Not applicable / Blocked / Not tested**—never infer pass from inability to reproduce random events once.

| Domain | Minimum checks |
|---|---|
| Boot/time | fresh start; RTC ticking; clock-battery failure; midnight/day/year rollover; event date; long idle session |
| Town | all legal acre boundaries; map access; buildings/tree growth; object budget; 2- vs 3-tier terrain if supported |
| Characters | four human residents; multiple villager personalities; friendship/temper; inventory after player change |
| Inventory | full pockets; sell, discard, give, wrap and store; special items/invalid IDs; save/resume |
| Script | all first-time/quest/event messages; long names; embedded control characters; rapid confirm/cancel |
| Letters | regular English scoring; quest scoring and reward categories; attachments; Controller Pak files |
| Seasonal | cherry blossoms, rain, snow/snowballs, summer aerobics, New Year, lunar holiday, island weather if implemented |
| Museum | assess/submit, repeated donation, legacy painting rejection, encyclopedia flags (Enhanced only) |
| NES | built-in playback, return to town, bad/missing ROM, Controller Pak/loader compatibility |
| Hardware | original console/controller/flashcart as available, stock RAM, cold boot, sustained performance, saves and RTC |

### Definition of Done for every ticket

- [ ] Original behavior and version applicability documented; ROM hash recorded.
- [ ] Reproduction steps and a control case recorded, or ticket closed **Not present on N64** with code evidence.
- [ ] Exact affected symbols/tables/assets identified; patch scope reviewed for edition fit.
- [ ] Minimal implementation with test coverage and before/after evidence.
- [ ] Save, RTC, event, input, rendering and hardware regression performed as applicable.
- [ ] Build, commit/PR, screenshots/clips and test outcome linked in the tracker.

---

## 10. Source index and provenance

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

## 10A. Documented mechanics and uses — not automatically bugs

Several transcript excerpts describe **how systems work or how players use them**, rather than defects. Preserve these as parity/behavior research so they are not accidentally “patched” away:

| Topic | What the research reports | Decision |
|---|---|---|
| Stalk Market price prediction | GC weekly turnip prices are seeded/deterministic; shop inventory can help reconstruct RNG state and predict spikes. Research mentions Sunday purchase prices **70–129**, special **8×** buying spikes, and random/decreasing/spike trends. These figures are GC-specific until compared to N64. | Document and test vanilla N64 pricing. **Do not nerf ordinary predictable RNG** as an English “bug fix.” Keep spoilage exploit under `BUG-031`. |
| Villager letter quests | When a resident specifically asks for a letter, GC uses a **separate rank 0–11** length/words/repetition/attachment scoring path; response item category can be predicted. | Preserve as intentional behavior if present, and adapt for English in `LOC-006`. Do not merge with malformed trigram scanning (`BUG-027`). |
| Controller Pak Famicom loading | N64 blank Famicom furniture can load special Controller Pak ROM notes; historical Ice Climber promotional Pak and 32 KiB formatting are research precedents. | Preserve original compatibility in `EN`; improvements/additional game access under `CONTENT-007/023` and `TECH-009`. |
| Friendship and dialogue diversity | Many conditional lines depend on personality, friendship, temperament, time, weather and town-tune changes. Later GC games try to vary resident personalities via move-in/out selection. | Preserve original N64 branching faithfully, then evaluate imported GC/e+ personality systems as `CONTENT-006/017`. |
| Debug/beta assets and unused text | Unused items, animations, test lines, models and development material may remain in N64 or later versions. | Catalog provenance before restoration. **Unused ≠ broken**; prototypes are `CONTENT` until intentionally made playable. |

---

## 11. Near-term execution order

1. **Freeze the reference:** capture the verified Japanese ROM fingerprint, decomp status and a disposable save per test fixture.
2. **Identify N64 applicability:** audit `BUG-001`–`014`, `016`–`019`, `022`–`023`, `028`–`031` in decomp/assets before trying to trigger GC-only steps.
3. **Deliver one playable translation loop:** Rover/train intro, Nook, villager dialogue, inventory, mail, save/reload and English sound; run structural control-code validation (`BUG-029`) from day one.
4. **Prioritize real fixes:** tackle reproduced P0/P1 risks, then deterministic RNG/lookup mistakes with small, reviewable commits.
5. **Stabilize English and milestone it:** do not block the first working release on the museum, GBA, whale, online mode or fully matching 100% decomp.
6. **Prototype Enhanced content in vertical slices:** museum + fossils first; inventory/storage second; Able Sisters/island next; follow with the feasible e+/cut-content experiments.
7. **Publish honest progress:** count *confirmed N64 defects*, *patched defects*, *passed regressions*, and *accepted Enhanced features* separately from raw notes or work-in-progress code.

**Release principle:** finish an accurate English N64 experience first. Grow Enhanced carefully into the best polished first-generation-inspired game the original N64 hardware can reasonably support.
