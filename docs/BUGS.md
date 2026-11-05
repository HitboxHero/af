# Bug investigation and fix register

**Applies to:** English Edition only after verification on the **original Japanese N64 ROM**. Accepted fixes are inherited by Enhanced Edition. No listed GameCube report is automatically evidence that the defect exists on N64.

**Status for every ticket:** `Reported / N64 not checked` → `N64 reproduced` or `N64 absent` → `Code confirmed` → `Patched` → `Regression passed`. Do not change a ticket to `Patched` merely after confirming the code; the ROM must build and the reproduction must pass. If a prerequisite feature is absent, close as `N64 absent / not applicable`, not “fixed.”

**Per-ticket evidence to add:** ROM version/hash; symbol/function and file/line; reproduction save state and town layout; clock/RTC; emulator or real console; exact input sequence; expected/actual screenshots or clip; patch commit; before/after regression. Use disposable saves for all OOB, save/RTC, and crash tests. For random bugs, inspect code or enumerate/seed RNG: one unsuccessful attempt is not proof of unreachability.

**Severity:** `P0` crash/data loss/corruption; `P1` unfair progression or exploitable gameplay correctness; `P2` ordinary incorrect mechanics; `P3` cosmetic/low impact. Severity is provisional until verified.

## N64-candidate defects — investigate in English, inherit verified patches in Enhanced

The bug descriptions below derive from the supplied transcriptions and previous tracker. **“Reported actual” describes a referenced version, often GameCube**, not a proven result from the Japanese N64 ROM.

### BUG-001 — Saplings die because a south-edge acre check reads a distant acre

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P1. **N64 status:** Not tested (candidate).

- **Reported mechanism:** the bottom-edge-neighbor lookup uses `[acreZ + 1][acreZ]` instead of `[acreZ + 1][acreX]`. In the source example, a sapling at the bottom of **B5** should check **C5** but instead tests **C2**, causing remote obstruction to kill it.
- **Reproduce:** (1) Use a town/save where B5/C5/C2 are accessible and mark the same tile pattern. (2) Plant a sapling on B5's bottom boundary, with the directly adjacent C5 tiles unobstructed. (3) Place/retain an obstruction in the *corresponding checked* location of C2; maintain a control save with it clear. (4) Advance the normal growth tick by one day; compare outcomes. (5) Repeat with another column and a non-boundary tree.
- **Expected:** only the actual adjacent C5 tiles affect B5's sapling. **Reported actual:** remote C2 blockage causes wilting.
- **Verify/fix:** locate acre-edge validity lookup; correct column argument, and check north/east/west boundary handling. Regression: edge and interior plots, legitimate blocked plots, town layouts with different acre arrangements.


### BUG-002 — Light cherry-blossom weather never selected

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P2. **N64 status:** Not tested (candidate).

- **Reported mechanism:** the early-April weather selection references **light snow** instead of **light sakura**, rendering the intended light sakura variant unreachable.
- **Reproduce:** (1) Confirm the light-sakura effect and schedule exist in Japanese N64 data. (2) Set/test **April 5–7** under controlled weather RNG; inspect weather-effect enum and spawn branch. (3) Compare normal sakura and forced light-sakura rendering. **Expected:** light sakura can occur on scheduled days. **Reported actual:** it never naturally triggers.
- **Fix/regression:** change the referenced effect/condition if code confirms it; check April 4–8 and all snow/rain seasons. Do not assume that a GameCube seasonal table matches N64.


### BUG-003 — Non-native orange fruit excluded by off-by-one RNG

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P1. **N64 status:** Not tested (candidate).

- **Reported mechanism:** fruit IDs `0..4` are selected using an RNG range of `0..3`. The same code increments the selected ID when it matches the native fruit. This can yield orange (ID `4`) via the peach (ID `3`) case, but not normally when native fruit is apples, cherries or pears.
- **Reproduce:** (1) Prepare towns with apple/cherry/pear native fruit plus peach and orange controls. (2) Trigger the non-native fruit reward path from villagers, letters, and balloon gifts **only if each path exists on N64**. (3) Instrument/seed the RNG or exhaustively enumerate input indices. (4) Record which IDs are reachable for each town fruit. **Expected:** every eligible non-native fruit can be selected. **Reported actual:** oranges are unreachable for several native-fruit types.
- **Fix/regression:** select uniformly from a four-element list *excluding* the native fruit, rather than merely changing `RANDOM(4)` to `RANDOM(5)` (which could produce ID `5` after the existing increment). Preserve other fruit reward probabilities if intentional.


### BUG-004 — Tortimer's 16th New Year's diary never awarded

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P2. **N64 status:** Not tested (candidate).

- **Reported mechanism:** 16 diary variants are indexed `0..15`, but the random-selection expression effectively produces `0..14`; item ID **`0x2B0F`** (reported calligraphy pad) is unreachable.
- **Reproduce:** (1) Confirm the N64 New Year's Tortimer reward table and ID mapping. (2) Set date to New Year's event, collect rewards on disposable saves, or directly enumerate selected indices in a test harness. (3) Show maximum index selected is 14. **Expected:** all 16 table entries have nonzero chance. **Reported actual:** entry 15 is never selected.
- **Fix/regression:** adjust random bound to include all verified entries, then check all item IDs and distribution; test event after save/reload.


### BUG-005 — Cockroach escape jump chooses one fixed, wrong direction

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P3. **N64 status:** Not tested (candidate).

- **Reported mechanism:** a random function called with `1` produces only `0` before conversion; a cockroach's intended two-direction jump always uses the same ~22.5° direction, reportedly toward the player.
- **Reproduce:** (1) Load an infested house after sufficient absence (or spawn roaches in a disposable debug save). (2) Approach from several angles; repeat jumps with logged RNG outputs and player-relative angles. (3) Compare observed vs intended two-branch outcome. **Expected:** both escape directions reachable. **Reported actual:** one fixed branch.
- **Fix/regression:** use a correctly bounded random Boolean/index; verify roach motion, collision and despawn.


### BUG-006 — Snail flies away when the inventory is full

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P2. **N64 status:** Not tested (candidate).

- **Reported mechanism:** the special release path for catching a snail with no free pocket slots uses a generic flying-insect release animation instead of the snail's ground-release animation. Reportedly fixed in AU/EU GameCube versions.
- **Reproduce:** (1) Fill all pockets. (2) During rain, net a snail from a flower. (3) Observe immediate automatic release. (4) Compare against releasing a snail manually with free space and against catching an ant at full capacity. **Expected:** snail drops/crawls on ground. **Reported actual:** snail visibly flies away.
- **Fix/regression:** route automatic release through the snail's species-specific animation. Confirm snail availability in N64 before classifying N64 bug.


### BUG-007 — Butterflies land only on white pansies

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P3. **N64 status:** Not tested (candidate).

- **Reported mechanism:** the flower lookup/landing eligibility apparently accepts white pansies alone rather than the intended broader set of flowers. This could be a restrictive rule rather than a coding error; prove intent before fixing.
- **Reproduce:** (1) Lay out equal test patches of each existing flower species/color with matching empty space. (2) Spawn/observe eligible butterflies repeatedly under consistent time/weather. (3) Log resting targets or inspect landing predicate. **Expected (proposal):** butterflies can pause on multiple compatible flowers. **Reported actual:** rest on white pansies only.
- **Fix/regression:** extend eligibility only after reviewing the table and behavioral design. If intentional, move to `EX` as a wildlife enhancement instead of an `EN` bug fix.

**Scope decision:** If white-pansy-only landing proves to be intentional N64 design, close this bug and consider a separate Enhanced wildlife-improvement proposal; do not silently redesign English.



### BUG-008 — Released arapaima has an oversized ground shadow

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P3. **N64 status:** Not tested (candidate).

- **Reported mechanism:** the release animation lacks a correct shadow-scale index for the game's sole “huge” fish class; the arapaima casts an excessively wide oval.
- **Reproduce:** (1) Obtain an arapaima and a large comparison fish (for example, coelacanth). (2) Release them from pockets at similar camera positions and capture their brief shadow projections. (3) Compare the species-to-shadow-size lookup. **Expected:** shadow proportional to released fish. **Reported actual:** arapaima's shadow scale is wrong.
- **Fix/regression:** add the correct huge-fish shadow entry; confirm other fish classes and catch/release animation unaffected.


### BUG-009 — Train audio attenuation wrong in a three-tier town

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P2. **N64 status:** Not tested (candidate).

- **Reported mechanism:** vertical/Y-coordinate mapping isn't updated for three-layer town terrain, reportedly making the train much quieter than intended.
- **Reproduce:** (1) Compare equivalent train arrival/departure scenes in verified two-tier and three-tier town layouts. (2) Capture audio at fixed output gain, player position and train phase. (3) Log emitter and listener Y coordinates if available. **Expected:** sound attenuation follows actual spatial positions. **Reported actual:** disproportionate quietness in three-tier maps.
- **Fix/regression:** correct the vertical-coordinate reference or map-height conversion; check other positional audio sources and both layouts.


### BUG-011 — Harvest Moon event uses incorrect precomputed dates

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P2. **N64 status:** Not tested (candidate).

- **Reported mechanism:** stored lunisolar-derived festival dates through **2030** can be off by one or two days, despite intending the 15th day of the eighth lunar month. The research notes state more than half of the GC dates are wrong; do not assume the N64 table is identical.
- **Reproduce:** (1) Locate the N64 holiday scheduling table/date algorithm. (2) Enumerate all supported calendar years and map in-game dates to the defined target holiday. (3) Compare against an authoritative date table with timezone/calendar convention documented. (4) Boot one correct and one incorrect year to validate the actual festival. **Expected:** event on intended annual date. **Reported actual:** some event dates shifted.
- **Fix/regression:** correct actual wrong entries or use a properly bounded computation. Protect the supported clock range, leap years and year rollover. **Post-2030 support is a separate Enhanced feature, not an automatic bug-fix assumption.**

**Scope decision:** Before changing any date, confirm the festival exists in N64 and establish the historically intended calendar rule; a localized holiday-name change is not evidence of a code bug.



### BUG-014 — Axe durability changes when an interaction cancels the swing

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P1. **N64 status:** Not tested (candidate).

- **Reported mechanism:** pressing `A` with an axe increments a hidden hit counter *before* the full swing/durability check. A bulletin board, town-tune board, or doorway takes priority and cancels the swing, leaving the counter incremented. Non-tree collision adds **3**; normal tree hit adds **1**; durability update normally runs at **9**. A signed one-byte counter can cross `127`, be treated as negative, or overflow after `255`, affecting breakage.
- **Reproduce (premature wear):** equip new axe; read bulletin board **three** times with axe out; then hit a tree; compare durability with a control axe that never interacted. Reported result: new axe wears far faster (can break after about nine real tree hits if repeatedly manipulated).
- **Reproduce (extended wear):** prepare an axe close to breakage; trigger ~**40** board interactions, then use it on trees. Instrument hit-counter byte and compare its signed interpretation. Reported result: extended/infinite practical durability is possible by repeating the trick. Check board, tune board, and door separately.
- **Expected:** only a completed swing changes wear. **Fix/regression:** increment or commit wear only after animation/collision completion, or roll back on interaction cancellation; test tree hits, misses, hard-object hits, sign/door/menu interaction, reset, and counter limits. Keep intended base durability.


### BUG-016 — Snowball/signboard interactions push the player outside valid collision bounds

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P1. **N64 status:** Not tested (candidate).

- **Reported mechanism:** snowball movement during item pickup/other animations, possibly combined with signboard positioning, pushes a character through boundaries or into unintended acre coordinates.
- **Reproduce:** (1) On snow day, position a snowball beside a signboard, wall, acre edge or blocking object. (2) Start item pickup/interaction while snowball contacts/pushes player; repeat at all relevant facings. (3) Log player coordinate, collision flag and current acre when movement resumes. (4) Test signboard collision separately from snowball push. **Expected:** collision stops at valid geometry, interaction completes normally. **Reported actual:** player exits walkable bounds.
- **Fix/regression:** enforce collision/position validation after scripted movement and before restoring movement; avoid overcorrecting legitimate snowball pushing. Link to downstream `BUG-017`.


### BUG-017 — Opening the map while outside valid acres can crash

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P0. **N64 status:** Not tested (candidate).

- **Reported mechanism:** map view assumes a valid acre index; an out-of-bounds player position can index invalid map/town data.
- **Reproduce:** (1) On disposable save, use `BUG-016` or a safe developer/debug warp to set invalid acre coordinates. (2) Open the map. (3) Observe crash/lock; record exact invalid row/column and game state. (4) Test normal boundary acres. **Expected:** reject/clamp invalid location or recover safely. **Reported actual:** crash.
- **Fix/regression:** validate index in the map *and* fix underlying OOB movement; test negative coordinates, above-maximum indices, transitions, and legal borders.


### BUG-019 — Diary message open/close on the same instant softlocks

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Edition:** English + inherited Enhanced, **only if reproduced or code-confirmed in Japanese N64**. **Priority:** P1. **N64 status:** Not tested (candidate).

- **Reported mechanism:** overlapping open and close message events leave diary/modal state invalid. Exact input/frame timing is not documented.
- **Reproduce:** (1) Open a diary/message in a disposable save. (2) Generate quick consecutive confirm/cancel inputs or frame-stepped simultaneous transition at the moment the message opens. (3) Repeat while closing and opening again with different game/input frame timing. (4) Check whether control and normal dialogue return. **Expected:** one valid message state, no permanent lock. **Reported actual:** softlock at a particular timing boundary.
- **Fix/regression:** serialize message state transitions, debounce duplicate events or enforce one ownership token per modal; test repeated and buffered input.

## Enhanced-only integration regressions — conditional, not inherited N64 defects

These tests are **not** English Edition tickets. They are activated only when the corresponding GameCube/Enhanced feature is actually built. They are not labeled N64 bugs. The supplied notes describe these conditions in later releases.

### EBUG-001 — Startup town-rating dump exemption

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** Town-rating system / dump; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** In a town with a legal dump, put trash inside the dump, record rating immediately on load and after checking at the wishing well, then repeat with trash outside. The two correct evaluations should agree. A GC report describes the startup path using title/demo town dump coordinates.
- **Expected behavior / patch:** Read the current playable town coordinates after save loading before rating. Do not impose this on original N64 if its dump/rating path differs.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-013`.


**Additional retained research / test methods (previous README; unverified):**
- **Reported mechanism:** startup rating reads dump coordinates from the title-screen/demo town (reportedly an N64-derived town without the GC dump), not the player's town. A manual assessment at the wishing well uses the correct coordinates.
- **Reproduce:** (1) In a GC reference or port containing a dump, place trash **inside** the legal dump bounds; ensure all other rating inputs are controlled. (2) Save and restart; record the startup rating/effects. (3) Recheck at the wishing well. (4) Compare calculations with trash removed and trash outside the dump. **Expected:** dump trash exempt in both paths. **Reported actual:** startup-only penalty, corrected by manual evaluation.
- **Fix/regression:** defer assessment until player town data/dump coordinates are initialized or pass the actual town state explicitly. Original N64 may not have this GC dump configuration; establish applicability first.

### EBUG-002 — Island coconuts never wash ashore

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** Animal Island; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** Remove coconut trees/fruit from a disposable island and let rare island-beach items spawn with instrumented RNG; enumerate all entries in the rare island table. A GC report describes a two-entry bound for a three-entry table.
- **Expected behavior / patch:** Use table length that includes the coconut; verify wash-up and tree recovery. Independently test whether dropped coconuts counting as shells is intentional; four coconuts per acre can reportedly suppress shell spawns.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-003`.


**Additional retained research / test methods (previous README; unverified):**
- **Reported mechanism:** copied “rare shell island” table is declared with **two** entries rather than **three**; the final coconut entry is never selected. A separate linked behavior counts dropped coconuts toward a reported four-shell-per-acre spawn cap.
- **Reproduce A:** (1) In the GC reference/EX island, safely harvest and remove all naturally spawned coconut trees/coconuts; (2) trigger repeated beach respawns or enumerate the table; (3) confirm coconut never selected despite text promising wash-ups. **Expected:** finite chance of a replacement coconut. **Reported actual:** none.
- **Reproduce B:** drop four coconuts within each test beach acre; advance normal shell-spawn checks; compare to an empty beach control. **Expected:** shell cap should account for intended object types. **Reported actual:** shells stop spawning because coconuts consume the quota.
- **Fix/regression:** correct table length, verify coconut pickup/planting and shell quota. Decide explicitly whether coconuts should count as beach objects for cap logic (a separate gameplay policy), then test no-coconut recovery and full-beach conditions.

### EBUG-003 — Rain and morning aerobics disagree after map/clock changes

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** GameCube-style morning aerobics + island; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** Case A (reported GC): on a rainy summer morning use the island’s sunny weather and an interior map reload, then return to find aerobics scheduled in rain. Case B: remain outdoors from just before midnight to 6 AM as rain begins/ends at date rollover; observe unmoving participants or missed event.
- **Expected behavior / patch:** Schedule from mainland saved weather after date/weather resolution, not the transient island weather; revalidate on travel and reload. Preserve normal rainy-day cancellation.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-003;CONTENT-013`.


**Additional retained research / test methods (previous README; unverified):**
- **Reported failure A (island reload):** during a rainy aerobics day, visit sunny island; enter island cabana to reload map; event initializes as if clear; return immediately to mainland and aerobics runs in rain until a later reload. **This reproduction requires the GC island and cannot be run unchanged in vanilla N64.**
- **Reported failure B (midnight ordering):** load **11:59 p.m.**, remain outside through midnight and until **6 a.m.** without any map reload. If weather changes after the midnight scheduling check, aerobics can be scheduled under rain (station announcement but villagers idle, Tortimer/Copper/radio missing), or incorrectly canceled on a clear day. Use scripted RTC/weather changes rather than waiting six hours during every development run.
- **Expected:** weather and event schedule agree; no partially populated event. **Fix/regression:** use authoritative daily weather state when scheduling, not stale live-rendered weather; rerun event initialization consistently. Verify event actually exists in N64 and what its N64 cancellation rules are.

### EBUG-004 — Debt payoff and Spring Sports Fair event conflict

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** Imported Spring Sports Fair scene; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** With a disposable GC-style sports-fair day save, arrange mortgage payoff and entry into the referenced scene on the same period; run repeated cutscene/house-storage transitions and compare against a no-payoff control. Exact exploit timing still needs source video verification.
- **Expected behavior / patch:** Serialize mortgage/storage state transitions around event scene; ensure no crash or corrupt save. Only activate if importing this event.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-013`.


**Additional retained research / test methods (previous README; unverified):**
- **Reported symptom:** paying off home debt in conjunction with the Spring Sports Fair cutscene/storage sequence can crash the game. The user's notes do not specify the exact timing and inputs; **the source clip must be converted into reproducible steps before implementation**.
- **Reproduce candidate:** use duplicate saves immediately before paying the final installment; test final payment at the fair's event start, during its cutscene, before/after any home-storage interaction, and on ordinary days. Record cutscene state, debt stage, involved NPC, save event and crash point. **Expected:** debt cleared, house-upgrade dialogue completes, save remains usable. **Reported actual:** crash in the described overlap.
- **Fix/regression:** inspect scene transition, debt completion and storage/menu callbacks once exact conditions are identified. Do not treat the candidate sequence as a confirmed reproduction recipe.
- **Source:** https://www.youtube.com/watch?v=VB0kLldqid0

### EBUG-005 — Igloo reward pool may produce dummy item

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** Imported winter igloo events; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** On an imported winter igloo event, enumerate every possible reward index; verify whether reported `0x33C4` resolves to a valid item. Do not rely on random repeated runs only.
- **Expected behavior / patch:** Remove/replace invalid entry and correct table length, or deliberately turn it into a complete valid collectible with art/name.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-013`.


**Additional retained research / test methods (previous README; unverified):**
- **Reported mechanism:** a leftover/dummy entry (`0x33C4`, **verify ID against target ROM**) was not removed from the igloo gift table, so campers can award it despite incomplete model/behavior.
- **Reproduce:** (1) Determine whether igloo visits/reward pool exist on N64. (2) In winter, accept igloo NPC item rewards, instrument selected table indices or enumerate the reward pool. (3) Check whether the dummy item can enter inventory and display. **Expected:** only valid rewards. **Reported actual:** dummy item is awarded.
- **Fix/regression:** remove/replace invalid entry and update effective table length; preserve intentional souvenir behavior. If N64 has no igloo, target EX when added.

### EBUG-006 — Legacy paintings bypass special Blathers dialogue

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** Museum + painting catalog; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** Using debug-only inventory injection on a test save, attempt to donate the original N64 Novel and Dreadful painting IDs. Reported GC: an early first-15-art-range test rejects them before special refusal text.
- **Expected behavior / patch:** Route those IDs into explicit non-donatable legacy painting refusal dialogue, not a generic invalid-item path; test all regular paintings and correct catalog completion.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-001`.


**Additional retained research / test methods (previous README; unverified):**
- **Reported mechanism:** original N64 **Novel Painting** (Mondrian) and **Dreadful Painting** (Munch) persist as legacy IDs in later GC data; special Blathers refusal dialogue exists in GC/English, but the global “valid artwork” range checks only the normal first **15** paintings before the special case can run.
- **Reproduce:** (1) In GC reference/EX museum test, inject a valid legacy painting ID into a spare inventory. (2) Attempt to donate it. (3) Check that special “cannot accept this painting” dialogue is used instead of generic invalid-item dialogue. (4) Repeat with normal art. **Expected:** special branch reached for both legacy IDs. **Reported actual:** generic rejection.
- **Fix/regression:** make the two special legacy IDs eligible to reach the *refusal handler*, without marking them donatable normal paintings. **Do not remove or replace original N64 paintings from EN as a bug fix**; original N64 has no Blathers museum. If legally/distribution-relevant, handle art choices separately.

### EBUG-007 — Faraway fossil letter misses reburied discoveries

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** Museum + fossil rewrite; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** On two new saves, discover a fossil; A: keep it in pockets until the next startup; B: rebury before shutdown. Inspect original discovery/mail flags and compare letter triggers. This is a proposed test, not yet a confirmed bug.
- **Expected behavior / patch:** Set the relevant discovery flag at the correct event so reburying does not block the intended letter; ensure direct Blathers assessment makes mailing optional and no double reward occurs.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-001;QOL-008`.


**Additional retained research / test methods (previous README; unverified):**
- **Reported concern:** a special faraway museum letter may depend on loading a game with a fossil currently in pockets. If the fossil was dug up and reburied before the next boot, the discovery/letter flag might never set.
- **Reproduce:** (1) Start fresh comparable saves. (2) Unearth a fossil and save/restart *with fossil in pockets* in save A. (3) Unearth/rebury the fossil before save/restart in save B. (4) Compare letter/event flags, mailbox arrival, and dates over the documented trigger window. (5) Test storage, transfer and several human characters. **Expected:** determine original intended eligibility before labeling behavior defective. **Reported actual:** letter missing for the reburied path, per project note; not yet confirmed.
- **Fix policy:** if a genuine discovery-flag oversight, correct the flag in `EN` without changing original event text. `EX` should provide direct Blathers fossil evaluation (see `QOL-008`) and adapt/remove obsolete mailing dependencies with a migration test.

### EBUG-008 — Paper airplane prototype duplicates or locks player control

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** Optional paper-airplane restoration; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** On a debug build only, spawn exactly one paper airplane, reload map, count objects; then hold/throw it and try to regain normal movement. The notes report repeated duplication, a frozen input-suppression state, and conversation/boat-interruption side effects if a naive player-state workaround is used.
- **Expected behavior / patch:** One owned object per spawn, valid pickup/write/throw lifecycle, input restored on landing/cancel, prohibit throws in conversations/cutscenes/boat, save/reload tested.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-008`.


**Additional retained research / test methods (previous README; unverified):**
- **Merged reports:** (a) an injected airplane duplicates each map reload, eventually crashing; (b) it can be picked up/thrown, with stick influence over flight; (c) throwing enters an input-refusal state that never properly restores player control; (d) substituting an axe-like player state prevents the lock but permits throwing during dialogue/boat sequences, causing camera/music/interaction corruption. Also noted: letter-writing behavior and transparent/incomplete object visuals.
- **Reproduce:** (1) Find whether airplane object/actor/textures exist in Japanese N64. (2) In a **throwaway** hacked/debug save, place **one** airplane, reload map repeatedly, and count instances/memory. (3) Pick it up, throw and wait for landing; attempt movement/menu/tool actions. (4) If testing an experimental state workaround, try throwing during an NPC conversation and a cutscene; check return of input/camera/audio. **Expected:** single persistent item and full return to a valid idle state. **Reported actual:** replication/crash or softlock/state corruption.
- **Fix/regression:** if not accessible in normal N64, do *not* add to `EN`. For `EX`, give airplane an explicit lifecycle, ownership/persistence rules, throw-state guard, cleanup callback, disallowed-action checks and complete render/interaction data. Never rely solely on assigning a random existing player state.

### EBUG-009 — Additional NES entry points to absent game data

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
- **Edition:** Enhanced only; **gate:** Optional extra NES/Famicom catalog; **status:** Not activated — prerequisite feature not implemented/verified.
- **Reported failure / how to reproduce:** Enumerate imported NES furniture/selection entries, then launch each on a safe developer build. A supplied report says a 20th/missing Zelda II ROM entry crashes; verify against the actual imported data rather than assuming N64 has it.
- **Expected behavior / patch:** Validate asset presence, size, mapper/region and exit paths; missing games are inaccessible or produce a safe message, never crash.
- **Acceptance:** reproduce a failing before case or identify the faulty source branch, patch it, confirm normal and edge paths on real N64, save/reload and return to town.
- **Dependency:** `CONTENT-007`.


**Additional retained research / test methods (previous README; unverified):**
- **Reported symptom:** certain catalogued test titles (notes mention a missing **second Zelda** game and a “20th NES ROM”) lack their binary; forcing playback can crash. The identity, count and release version need validation.
- **Reproduce:** (1) Inventory actual NES/Famicom furniture IDs, supported mapper/game table and embedded ROM resources in N64. (2) Distinguish a title omitted on purpose from an invalid selectable pointer. (3) Inject/select a missing ID **only in a disposable test**; observe whether missing-data check rejects it. (4) Compare available built-in games and Controller Pak-loaded games. **Expected:** absent ROM cannot launch; explanatory error. **Reported actual:** crash when forced.
- **Fix/regression:** never dereference missing game data; only expose playable games with verified image/memory constraints. Additional games belong to `EX`/`CONTENT-007`, not automatic English restorations.

## Research-only observations excluded from the active bug backlog

- **Golden collision cube, beta gyroid, unused textures:** dormant/debug content; no shipped-player defect until an asset is deliberately restored. Catalog under `CONTENT-022` instead.
- **Missing/unsafe Nook passwords and unopenable code-generated presents:** these relate to later GameCube password systems not scheduled for either release. They are **retained research records only**, not scheduled implementation tasks; avoid importing any unsafe parser if a future feature is considered.
- **Odd turnip spoilage and deterministic price prediction:** the notes lack a repeatable non-spoilage exploit, and predictable seeded prices are an existing mechanic rather than automatically a bug. Research in `REFERENCES.md`; activate retained BUG-031 only after reproducible evidence.
- **North American GameCube letter trigram overread:** a defect in that game, but **not an inherited Japanese N64 bug**. The English Edition must design safe bounded English letter scoring as `LOC-009` and test it before release.
- **GameCube-only garbled beta textures:** source transcript reports those N64 leftovers render correctly in N64. Nothing to repair in the English Edition.
- **Original N64 museum/painting donation:** no museum is present. All donation checks live here only as Enhanced integration regressions.

## Bug closure template

```md
### BUG-XXX — Title
- Scope: English (confirmed N64) / Enhanced (imported feature)
- Status: Reported | N64 reproduced | N64 absent | Code confirmed | Patched | Regression passed
- Affected ROM(s)/hash and emulator/console:
- Setup (save seed, time, acres, items):
- Reproduction steps: 1. ... 2. ... 3. ...
- Expected / actual / control result:
- C symbols and hypothesis:
- Minimal patch / alternatives considered:
- Before/after proof (screenshots, memory trace, commit):
- Regression (RTC/save/4 residents/performance/real hardware):
```

## Retained research reports from the pre-integration README

These reports remain unverified. They are research or feature-gated checks, not confirmed English Edition defects. Unknown exact inputs remain explicitly unknown.

### BUG-020 — Nook code gift is permanently unopenable

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Target:** RESEARCH only; no password system scheduled | **Origin:** GC-specific Nook-code system | **Priority:** P1 for port | **Status:** Unverified.

- **Reported symptom:** a gift generated by a secret Nook code may have an invalid wrapping/item state and cannot be opened.
- **Reproduce:** (1) Locate the *specific code* and resulting item/present ID from the original demonstration; none was provided in the notes. (2) On GC or an EX code-system test build, redeem it, pick up gift, attempt opening, saving/reloading and storing. (3) Compare to a normal wrapped gift. **Expected:** valid opening and inventory item. **Reported actual:** stuck present.
- **Fix/regression:** validate code-to-item mapping, wrapped-state flags and invalid item handling. **Vanilla Japanese N64 has no North American Nook-code feature**, so do not label as an N64 fix.

### BUG-021 — Nook password/control-code interpreter can execute unintended code

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Target:** RESEARCH only; no password system scheduled | **Origin:** GC code-path report | **Priority:** P0 if ported | **Status:** Unverified.

- **Reported symptom:** malformed Nook codes can cross data/control boundaries rather than cleanly reject invalid strings.
- **Reproduce safely:** in an isolated GC reference or development build, feed a corpus of invalid lengths, symbols, control bytes, checksum errors and boundary values to the decoder under a debugger. Confirm rejection vs unexpected jumps, memory writes, hangs or crashes; **do not place exploit payloads in production or users' saves**. **Expected:** invalid input rejected without unsafe memory access.
- **Fix/regression:** strict input size/charset, index bounds, decoder state, checksum verification and defensive error return. Include fuzz/regression tests. Not in stock N64 unless a matching interpreter exists.

### BUG-026 — Debug/cut collision object or golden cube duplicates in certain locations

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Target:** RESEARCH; EX if restored | **Origin:** unused asset report; version not identified | **Priority:** P3 | **Status:** Unverified.

- **Reported symptom:** “unused golden collision cube” duplicates in unspecified spots. Neither object ID nor reproducible coordinates were supplied.
- **Reproduce:** (1) Identify actor/model ID by decomp/assets and log original stage spawn conditions. (2) Place exactly one instance in a test acre; reload across transitions. (3) compare object count and ownership. (4) Test any originally reachable debug map. **Expected:** at most the authored instances. **Reported actual:** unintended multiple instances.
- **Fix/regression:** resolve spawner/ownership only if content is made accessible. Catalog as cut/debug asset otherwise, not a shipping N64 bug.

### BUG-030 — GameCube debug/beta objects use incompatible N64 texture references

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Target:** RESEARCH; EX only if importing affected GC/debug objects | **Origin:** GC debug-map regression; N64 object reportedly renders correctly | **Priority:** P3 | **Status:** Unverified.

- **Reported mechanism:** debug gyroid and an unused clothing-display rectangle in GC beta maps still reference N64-era texture/draw pathways, creating garbled models in the GC engine. The transcript explicitly says the original **N64 debug gyroid renders correctly**: therefore this is **not** an N64 defect to “fix.”
- **Reproduce:** (1) Identify the debug/beta map assets and associated draw functions in original N64. (2) Render them in a controlled developer map and capture their correct N64 appearance. (3) In a GC reference, render the counterparts and compare missing/garbled textures. **Expected:** correct textures on the target engine. **Reported actual:** corrupted GC beta textures.
- **Fix/regression:** document the correct renderer-to-texture mapping when porting/debugging content; do not transplant GC-specific renderer fixes into N64 code. If these objects remain unused, close as documentation only.

### BUG-031 — Turnips can reportedly evade normal spoilage in rare setups

**Evidence source / affected version:** supplied All-in-One notes and pre-integration README; later-release reports unless explicitly identified. Exact source ROM revision/hash and N64 applicability remain unverified. See [reference index](REFERENCES.md).
**Target:** RESEARCH; BOTH only if N64 exploit verified | **Origin:** passing mention in GC Stalk Market transcript | **Priority:** P2 | **Status:** Unverified; reproduction unknown.

- **Reported symptom:** the research describes very limited, difficult exploits that cause turnips to **never spoil**, without supplying the actual steps or code branch. This is an investigation ticket, **not a reproduction claim**.
- **Reproduce candidate:** (1) Find the game's turnip age/expiration and save/RTC state logic. (2) Prepare fresh turnips with known purchase date, plus controls in pockets, storage, on ground and during travel if supported. (3) Advance time past the legitimate expiry and compare state transitions, including resets/clock changes and transfer actions. (4) If a reference exploit video/source is located, replace this candidate protocol with its exact deterministic sequence. **Expected:** turnips spoil according to the documented original rule. **Reported actual:** unspecified rare nonspoiling scenario.
- **Fix/regression:** preserve intended turnip strategy and price randomness; prevent a demonstrated missed expiration transition without retroactively spoiling legitimate items or breaking clock changes.

## Previous README identifier migration

Retired aliases remain reserved; use the canonical ID for future work. No duplicate implementation tasks are created.

| Previous ID | Canonical ID |
|---|---|
| `BUG-010` | `EBUG-001` |
| `BUG-012` | `EBUG-003` |
| `BUG-013` | `EBUG-002` |
| `BUG-015` | `EBUG-008` |
| `BUG-018` | `EBUG-004` |
| `BUG-022` | `EBUG-009` |
| `BUG-023` | `EBUG-005` |
| `BUG-024` | `EBUG-006` |
| `BUG-027` | `LOC-009` |
| `BUG-028` | `EBUG-007` |
| `BUG-029` | `LOC-003` |
| `BUG-025` | Excluded: physical e-Reader functionality is outside both editions. No implementation task. |

## Reproduction and applicability limits

Each ticket's reported actual behavior and proposed correction are hypotheses until source-version evidence is captured. A candidate protocol is not an exact known exploit sequence. Missing frame timing, code strings, town seed, ROM revision or coordinates must be obtained before claiming reproduction. The shared evidence fields above are mandatory for every ticket. Acceptance requires the specified control and boundary tests, save/reload and four-resident checks, with hardware qualification per [Testing](TESTING.md).

The supplied source scopes EBUG-001 and EBUG-007 to Enhanced integration. This does not establish that similar original N64 rating or fossil-letter behavior is absent: investigate original behavior separately before proposing any English fix, and preserve original letter content and mechanics. No museum system enters English. BUG-022's old forced-missing-ROM test is retained under EBUG-009; shipped original Famicom/Pak safety remains part of TECH-009 verification.
