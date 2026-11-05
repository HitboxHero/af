# Enhanced Edition — complete implementation specification

The Enhanced Edition inherits the approved English localization and N64 bug fixes, then adds first-generation GameCube ideas and deliberate new features. It is **not** a GameCube ROM port and does not require GameCube/GBA connectivity. The goal is the richest *Animal Forest* experience feasible **on one N64 cartridge**, offline and ideally on stock 4 MiB N64 hardware; Expansion Pak-specific improvements remain optional unless documented otherwise.

**Edition boundaries:** The English Edition receives none of the features listed below by accident. Every addition requires an explicitly accepted proposal, isolated changeset, unique IDs, a save schema review, a performance measurement and real-hardware test. The descriptions below are design targets—not claims already implemented or promised for a release date.

**Out of scope:** physical e-Reader cards, scanning card data, card promotion/reward bugs, GameCube memory card or SD adapter compatibility. Content known from `e+` may be adapted *natively* without importing those card mechanisms.

## Recommended delivery slices

1. **Foundation:** stable English build, isolated feature branches, profiled memory and safe save ID/version plan.
2. **Flagship core:** museum/Blathers + local fossil assessment; Able Sisters; house upgrades; import a small set of complete furniture/animals.
3. **Playability:** safe storage/selling/stacking, collection journal, map and mail, while preserving the original slow-paced feel.
4. **Travel and events:** Kapp’n + island, seasonal/GC events and island minigame, correctness checks on weather/calendar.
5. **Optional novelty:** NES growth, prototype objects, extra wildlife/NPCs, audiovisual enhancements and `e+` features.
6. **Experiments:** town export, networking and advanced ROM/RAM work if the benefits justify it.

## Enhanced feature specifications

### CONTENT-001 — Museum, Blathers and donated collections
- **Source / nature:** GameCube core. **Status:** Proposed / not confirmed implemented. **Priority:** P1.
- **Implementation target:** Build a usable museum entrance/interior and Blathers NPC; create separate fish, insects, fossil, and art ledgers, displays and donation dialogues, accept no duplicated or impossible submissions, and preserve exhibition state across all four residents. Design a safe placement for the building on original N64 acreage.
- **Acceptance:** Walk in, donate each type, view exhibit, reload, receive distinct already-owned and invalid-legacy art responses; performance/save stable.
- **Prerequisites / porting checks:** TECH-003;TECH-007;LOC-013. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-002 — Able Sisters and custom-pattern service
- **Source / nature:** GameCube core. **Status:** Proposed / not confirmed implemented. **Priority:** P1.
- **Implementation target:** Add shop placement/interior, Sable/Mabel routines and localized dialogue, clothes and original first-generation pattern editing/shopping. Save pattern ownership and protect existing N64 clothing item IDs.
- **Acceptance:** Purchase/change a shirt, create/reuse a design, visit on different days, save/reload; no unsupported design corruption.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-003 — Animal Island and Kapp’n boat
- **Source / nature:** GameCube core. **Status:** Proposed / not confirmed implemented. **Priority:** P1.
- **Implementation target:** Add island acreage, dock/boat travel/return scenes and Kapp’n dialogue/music, sunny island weather rules, island resident and house activities, native island-only items and coconuts. Treat all GC island bugs as integration regression tests, never assume N64 originals.
- **Acceptance:** Depart/return without save loss, continue from disconnect/cancel, island coconut recovery works, events and weather remain correct on mainland.
- **Prerequisites / porting checks:** TECH-002;TECH-003;TECH-007. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-004 — In-game island handheld minigame
- **Source / nature:** Original N64 adaptation of GC/GBA feature. **Status:** Proposed / not confirmed implemented. **Priority:** P2.
- **Implementation target:** Recreate the island resident minigame inside the N64 experience, accessible through an in-world GBA-like object or menu. **Do not attempt general GBA emulation**; implement the relevant actions, rewards, and state natively.
- **Acceptance:** Start, play, save, quit, return to island, synchronize resident rewards; playable without a GBA cable.
- **Prerequisites / porting checks:** CONTENT-003. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-005 — Expanded first-generation item catalog
- **Source / nature:** GC/NA/e+ curated imports. **Status:** Proposed / not confirmed implemented. **Priority:** P1.
- **Implementation target:** Port compatible furniture, clothing, wallpapers, carpets, tools, fish/bugs and collectibles incrementally. Allocate stable unique IDs and string/graphics references; add shop/reward/season spawn sources, not only menu art.
- **Acceptance:** Every introduced item can be obtained, displayed, stored/sold/dropped or explicitly restricted without crashing.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-006 — Villagers, personality and dialogue expansion
- **Source / nature:** GC/NA/e+. **Status:** Proposed / not confirmed implemented. **Priority:** P2.
- **Implementation target:** Add selected villagers with models/animation/voices/houses, distinct personalities and more dialogue/requests. Carry original early-series snark and friendship dynamics; preserve varied moving-in/out rather than letting every town become the same.
- **Acceptance:** Introduce and depart a new resident through ordinary town simulation; correct friendship, diary, letter and schedule saves.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-007 — Additional playable NES/Famicom furniture
- **Source / nature:** Original N64 capability plus safe growth. **Status:** Proposed / not confirmed implemented. **Priority:** P2.
- **Implementation target:** Inventory the existing N64 Famicom emulator/games and Controller Pak support. Keep shipped ROMs working; explore additional compatible games in furniture/optional Pak data only after validating ROM legality, memory, mapper, input, and unload behavior. Do not expose missing slots.
- **Acceptance:** All selectable games enter and exit back into town safely; unsupported ROM never loads.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-008 — Functional paper airplane prototype
- **Source / nature:** Cut-content restoration. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Identify N64 versus GC assets and exact item lifecycle: creating/writing a letter, holding, throwing, steering and landing. Prevent GC-reported auto-duplication and player input suppression, and forbid item action during cutscenes/boat/NES modes.
- **Acceptance:** Spawn one; reload without clones; write/throw/land/recover; regain player control; cannot interrupt dialogs or corrupt save.
- **Prerequisites / porting checks:** EBUG-008. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-009 — Catchable whale with correct species text
- **Source / nature:** Cut-content/new wildlife. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Investigate source whale item/species ID and actual N64 model availability. Add an intentional ocean encounter, rarity and hitbox, catch/escape animation, inventory category and unique localized quip; reported hacked ID currently indexes unrelated dialogue in later GC script.
- **Acceptance:** Ocean whale can be encountered/caught/released or sold; no Able Sisters dialogue or collection index collision.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-010 — Shaki as a gardening visitor
- **Source / nature:** New feature inspired by cut/character research. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Confirm identity/assets for Shaki before claiming original content. Create an appropriate traveling gardening NPC with distinct schedule, themed goods and dialogue plus a paid, bounded weed-clearing service.
- **Acceptance:** Purchases charge once, weeds removed only from intended town, town rating and save updated with no phantom cleanup.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-011 — Water-bottle trash fish-up
- **Source / nature:** Unused item art / new fishing loot. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Check for the water bottle texture in N64; add a safe river/ocean junk catch with separate shadow/rarity and unique English text. Decide disposal, resale, recycling and town-rating implications.
- **Acceptance:** Fishing can return bottle from planned waters, inventory/category correct, collection and trash flags consistent.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-012 — Recovered scared and purple-mist reactions
- **Source / nature:** Unused first-generation reactions. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Locate existing reaction IDs and graphics in N64/GC and distinguish actual N64 code from GC leftovers. Add complete trigger, animation and state cleanup, with English NPC reactions where appropriate.
- **Acceptance:** Animation renders, sound/timing work, event finishes, player/NPC controls restored.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-013 — Expanded holidays and seasonal events
- **Source / nature:** GC/NA/e+ curated imports. **Status:** Proposed / not confirmed implemented. **Priority:** P2.
- **Implementation target:** Select which original GameCube holidays and seasonal events to add without erasing Japanese N64 events; examples from supplied notes: winter igloos, morning aerobics, Spring Sports Fair, North American celebratory days, new seasonal gifts. Support independent calendar entries and event-specific dialog.
- **Acceptance:** Each added event spawns on its documented date and cleans up; rain/clock rollovers, gift reward pools and building transitions pass tests.
- **Prerequisites / porting checks:** TECH-008. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-014 — Golden tools and progression rewards
- **Source / nature:** GC core. **Status:** Proposed / not confirmed implemented. **Priority:** P2.
- **Implementation target:** Add individually approved golden tools and appropriate first-generation unlock goals/reward conversations. Ensure original durability/tool behaviors and economy remain coherent.
- **Acceptance:** Tool can be earned legitimately, used/saved correctly, with unlocks documented and no free unintended duplication.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-015 — More home renovations/upgrades
- **Source / nature:** GC core. **Status:** Proposed / not confirmed implemented. **Priority:** P2.
- **Implementation target:** Introduce selected GameCube-era house expansion tiers and interiors while respecting N64 acre footprint and save RAM. Assess roof/exterior upgrades, additional room layouts, furniture capacity, mortgage balance and debt payoff event correctness.
- **Acceptance:** Upgrade, pay, exit/enter rooms, furnish and reload without floor/slot clipping; no conflict with event cutscenes.
- **Prerequisites / porting checks:** TECH-003;EBUG-004. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-016 — Improved town visuals with N64 art direction
- **Source / nature:** Enhanced presentation. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Refine trees, foliage, grass, building and terrain textures, object details, palette and baked-light appearance; optionally add geometry where strict RSP/RDP/frame benchmarks allow. Keep low-poly readability and original silhouettes.
- **Acceptance:** Side-by-side screenshot comparisons, same gameplay hitboxes, steady budget on stock N64.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-017 — e+ style deep friendships, sickness and fleas
- **Source / nature:** e+ gameplay imports. **Status:** Proposed / not confirmed implemented. **Priority:** P2.
- **Implementation target:** Add meaningful friend stages and dialogue unlocking, villager sickness with medicine gifts, flea catches using the net, and related NPC requests. Make the states time-bound and not punitive to infrequent players.
- **Acceptance:** Illness/medicine/flea events have valid start/end and unique dialog, no infinite loops; move-in/out still diverse.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-018 — After-hours Nook shop knock
- **Source / nature:** e+ gameplay import. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Let the player knock with a shovel when shop is closed and interact with sleepy Nook at a deliberate price penalty; recorded video claims +20% shop sales and −30% purchasing, verify numbers against the reference before encoding.
- **Acceptance:** Opens only eligible nights, penalty displays correctly, preserves clock/event/shop saves and original daytime economy.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-019 — Reset Surveillance Center
- **Source / nature:** e+ location import. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Add a discoverable rock/hole entrance, basement map, Resetti brothers, themed furniture and special event dialogue. Reserve map/actor/save identifiers without impacting original acres.
- **Acceptance:** Entrance unlock, visit and leave with correct reset accounting; no inaccessible map, save or camera break.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-020 — Additional title-theme and K.K. audio options
- **Source / nature:** GC/e+ audio import. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Investigate alternative title music recordings, e+ percussion arrangement and suitable new songs. Separate optional selection from soundtrack replacement; maintain N64 instrument banks, compression and audio-memory budget.
- **Acceptance:** Track selection and time of day transitions work; no audio dropout or extra frame stutter on hardware.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-021 — Optional local town export / lending
- **Source / nature:** Concept inspired by e+ SD town sharing. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Explore flashcart/Controller Pak-compatible export of a versioned town snapshot for offline exchange. Do not transplant GC SD adapter. If lending is attempted, protect simultaneous divergent edits with a clear lock/restore/cancel flow.
- **Acceptance:** Export/import checksums and migrations safe, player cannot overwrite primary town accidentally; fully optional.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-022 — Unused/gigaleak asset catalog and safe prototypes
- **Source / nature:** Historical research only. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Catalog soldier models, OBA, early Blathers/Wisp, sickle, unused dungeon, test textures, golden cube, debug gyroid and prototype clothing; label source: retail N64, GC, or leaked development-only. Do not redistribute leak-only data or unrelated trademarks as if licensed.
- **Acceptance:** For each candidate: evidence, image/prototype screenshot, provenance, availability and go/no-go decision.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-023 — Controller Pak Famicom/Ice Climber compatibility
- **Source / nature:** Original N64 research. **Status:** Proposed / not confirmed implemented. **Priority:** P2.
- **Implementation target:** Document base N64 Famicom furniture, memory note format and NESINFO/Yay0/iNES assumptions from research. Test an authorized compatible Pak note and graceful invalid/oversized rejection; separate support from adding copyrighted game ROMs.
- **Acceptance:** Stock furniture and eligible Pak note load/exit consistently on hardware; bad note does not crash or corrupt town.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-024 — New minigames and townside activities
- **Source / nature:** Original enhancements. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Prototype small first-generation-styled competitions and interactions using existing movement/animation, distinct from a full handheld emulator. Prioritize events players can repeatedly access.
- **Acceptance:** Activity has setup, scoring/reward, ending and persistent state without performance problems.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-025 — Optional letters/presents exchange over network
- **Source / nature:** Long-term hardware experiment. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Investigate a custom flashcart or cartridge interface for basic N64↔server exchange; exchange queued letters and presents first, then designs/selected records, then asynchronous town data. Consider live visits only after a genuine performance/network prototype.
- **Acceptance:** Offline game never needs a network; validated packets cannot overflow or corrupt saves; interrupted exchange recovers.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-026 — Seasonal wildlife/plant animation refinements
- **Source / nature:** New optional behavior. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Expand resting flower eligibility for butterflies **only if the source rule is intentional**, add subtle nature behaviors and improved feedback. Keep original rarity/time tables unless an explicit design choice changes them.
- **Acceptance:** Multiple eligible flowers with no invisible or uncatchable states, documented spawning differences.
- **Prerequisites / porting checks:** TECH-004;TECH-007;LOC-016 as applicable. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

### CONTENT-027 — Regional original art and legacy painting display
- **Source / nature:** Original N64 preservation + museum import. **Status:** Proposed / not confirmed implemented. **Priority:** P3.
- **Implementation target:** Keep all original N64 painting items intact in English. In Enhanced, decide whether they can be displayed in homes only, donated, or refused by Blathers; document a coherent rule for originals vs GC replacement paintings and map all model/item/text IDs.
- **Acceptance:** Original paintings survive save migration, museum art categories remain consistent, deliberate special refusal dialogue tested.
- **Prerequisites / porting checks:** CONTENT-001;EBUG-006. Include baseline N64 save, frame timing, item IDs, object/dialogue ownership and controlled regressions.

## Explicit design decisions to settle before coding

- **Museum geography:** select a safe N64 acre/location and entrance collision, not a late-game variable that overlaps houses or town geography.
- **Cultural timeline:** preserve original Japanese holidays, add GameCube/NA/e+ events only when they have independent scheduling and translation.
- **Island:** implement N64-native travel/minigame. Do not require a physical Game Boy Advance.
- **Painting policy:** preserve original N64 items; special refusal dialogue is an Enhanced museum issue, not an English Edition defect.
- **Save migration:** no changes that silently destroy or reinterpret existing English/JP items, house layout, letter attachments or four human residents.
- **Asset provenance:** retail vs debug vs leak-only references recorded. A named prototype does not demonstrate shipped functionality, and third-party IP is not cleared for redistribution.
- **ROM ceiling:** 16 MiB original, investigate a 32 MiB expansion if necessary. Larger size, custom flashcart/RTC, or Expansion Pak requirements need real-hardware proof and a separate documented decision.

## Feature pull request checklist

- [ ] Approved design/scope, branch and dependencies.
- [ ] Source edition/ROM ID and original screenshots recorded.
- [ ] New item/actor/message/room IDs allocated and collisions checked.
- [ ] Original and migrated save versions tested with four residents.
- [ ] Performance profiled in a worst-case busy town on actual N64.
- [ ] Feature entry, normal loop, failure/exit and reload behavior verified.
- [ ] English text / Animalese / control-code rules included.

## Additional retained requirements

- CONTENT-018: verify reported e+ after-hours price adjustments (20% buying / 30% selling) against its code before choosing Enhanced balance.
- CONTENT-021: investigate optional screenshots and e+ town-exchange/limbo behavior alongside local export; N64 storage hardware needs separate proof.
- CONTENT-023: verify `NAFJ01` Controller Pak note, NESINFO, iNES header, Yay0, 32 KiB Pak formatting and reserved filesystem pages; preserve existing compatibility in English.

### CONTENT-028 — Optional custom villager import
- **Scope:** Enhanced only; long-term experiment retained from the previous README's CONTENT-020; the All-in-One uses CONTENT-020 for music. Use CONTENT-028 for custom villagers going forward.
- **Current behavior:** no custom import capability verified by this documentation.
- **Proposal:** an optional tool imports validated resident appearance, name, personality and clothing, without physical card support.
- **Dependencies:** TECH-003; TECH-005; TECH-007; LOC-016.
- **Acceptance:** reject invalid assets/IDs/text; retain four residents and existing villagers across save migration; measure RAM/frame costs and test offline recovery.
- **Status:** Proposed. **Priority:** P3.
