# Development roadmap

## Two editions, one matching reference

| Build | Intended result | What belongs in it | What does **not** belong |
|---|---|---|---|
| **Japanese matching reference** | Readable C that reproduces the original Japanese N64 ROM byte-for-byte. | Decompiled C, symbol/struct accuracy, toolchain verification. | Gameplay or text changes. |
| **Animal Forest 64 — English Edition** | The N64 game as if it received an official, technically polished English localization. | Complete English dialogue, menus, letters/input, English Animalese where practical, and **bugs actually verified in N64**. | Museum, Blathers, Able Sisters, island, new house upgrades, expanded items, new QoL mechanics. |
| **Animal Forest 64 — Enhanced Edition** | The fullest coherent first-generation-style Animal Crossing experience feasible on original N64 hardware. | Inherits English, adds curated GameCube/e+ mechanics, museum/island/house/content, QoL, restorations and optional experiments. | Unnecessary peripherals or unstable systems; physical e-Reader card support is not planned. |

**Preservation rules:** keep the original N64 four-human town design, original events and seasonal pacing in English. The Enhanced Edition may add compatible North American/GameCube events, but must not overwrite the original schedule unintentionally. Try for the stock 16 MiB ROM in English where feasible; investigate 32 MiB for Enhanced only if needed. Prioritize stock 4 MiB N64 RAM and cartridge/RTC compatibility; measure optional Expansion Pak gains rather than assuming them.

## Project goals and progress order

- [ ] **Matching decompilation:** reconstruct N64 code in maintainable byte-identical C; fix names/structs and preserve reference hashes.
- [ ] **English localization:** every reachable dialogue, interface string, item/event name, controllable text-entry field, letter scoring and Animalese behavior correctly adapted.
- [ ] **Verified N64 fixes:** document a concrete before/after reproduction and apply minimal bug patches without changing the original game's intent.
- [ ] **Stable English milestone:** playable from train intro through ordinary town life, all four residents, letters, mail, events, RTC and save on real hardware.
- [ ] **Enhanced foundation:** save migration/versioning, ROM budgets, stable item/actor IDs, profile actual N64 frame and memory requirements.
- [ ] **Enhanced flagship features:** museum/Blathers and direct fossil identification, Able Sisters, more house upgrades, island/Kapp’n, curated GameCube/e+ residents, items, holidays and tools.
- [ ] **Enhanced QoL:** stacking, multi-select, bulk selling, expanded storage, encyclopedia, town map and mail improvements.
- [ ] **Optional experiments:** cut content, NES/Famicom additions, native island minigame, additional art/audio, local export and networked letters.

**No fixed release date.** Work is prioritized by feasibility, authenticity, reliability and real-hardware results—not a promise to port every GameCube feature.

## Phase and release gates

1. **Matching baseline:** same Japanese ROM hashes and documented decomp progress, no unreviewed toolchain changes. *Historical snapshot: 20.11% code bytes matched at 2026-10-30, not a live metric.*
2. **English vertical slice:** start/train/Rover/Nook, town creation, four residents, English conversation, inventory, item name, mail and letter scoring, shop, save/RTC, one event.
3. **English release candidate:** all reachable N64 text reviewed; no known unfixed P0 defects; high-priority N64-specific fixes either regression-tested or clearly documented; no GameCube-only new systems.
4. **Enhanced technical foundation:** ROM map and item/actor ID plan, versioned saves and migration, hardware baseline metrics, per-feature flags or branches.
5. **Enhanced playable feature waves:** museum/Blathers, QoL, tailor/house, island/event, side content and experiments in dependencies order.

## Incremental delivery order


1. **Freeze the reference:** capture the verified Japanese ROM fingerprint, decomp status and a disposable save per test fixture.
2. **Identify N64 applicability:** audit `BUG-001`–`014`, `016`–`019`, `022`–`023`, `028`–`031` in decomp/assets before trying to trigger GC-only steps.
3. **Deliver one playable translation loop:** Rover/train intro, Nook, villager dialogue, inventory, mail, save/reload and English sound; run structural control-code validation (`BUG-029`) from day one.
4. **Prioritize real fixes:** tackle reproduced P0/P1 risks, then deterministic RNG/lookup mistakes with small, reviewable commits.
5. **Stabilize English and milestone it:** do not block the first working release on the museum, GBA, whale, online mode or fully matching 100% decomp.
6. **Prototype Enhanced content in vertical slices:** museum + fossils first; inventory/storage second; Able Sisters/island next; follow with the feasible e+/cut-content experiments.
7. **Publish honest progress:** count *confirmed N64 defects*, *patched defects*, *passed regressions*, and *accepted Enhanced features* separately from raw notes or work-in-progress code.


## Documentation and status

The [issue tracker](ISSUE_TRACKER.csv) indexes canonical specifications. Statuses describe plans or reported observations; none of this reorganization verifies gameplay or completes a feature. Preserve identifiers permanently. Proposed `match`, `english`, and `enhanced` code lines are a future separation model, not claims that those branches or build targets currently exist. The documentation was integrated on `ai-decomp`.

P0: crashes/data loss/memory safety; P1: progression or essential functionality; P2: ordinary correctness/usability; P3: optional polish/research. Dependencies are implementation gates, not evidence of completion. English localization and verified fixes precede Enhanced additions; hardware and save feasibility gate every Enhanced milestone.

See [localization](LOCALIZATION.md), [bugs](BUGS.md), [QoL](QUALITY_OF_LIFE.md), [Enhanced](ENHANCED_EDITION.md), [technical work](TECHNICAL.md), [testing](TESTING.md), and [references](REFERENCES.md).

Tracker dependency links include integration planning gates inferred from the specifications (catalogs before translation, parser/font before runtime QA, versioned saves before inventory changes). They are proposals to review during implementation; a mutual test dependency such as QOL-008/EBUG-007 denotes coordinated regression work, not two features blocking each other forever.
