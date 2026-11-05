# Technical plan, phase gates, and testing

**Invariant:** the source-matching Japanese build is a preservation baseline. Neither English translation nor gameplay modifications can be committed into that reference branch. English is the stable, faithful variant; Enhanced inherits it and adds isolated features.

## Workstreams

### TECH-001 — Matching reference and clean branch model
- **Work:** Pin JP reference ROM hashes, source compiler/tool wrappers, matching output, and isolate match/english/enhanced branches. All normal decomp commits leave the reference output bit-identical.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-002 — ROM-size/bank/resource expansion
- **Work:** Measure current 16 MiB usage and prototype 32 MiB only when justified; assess DMA tables, relocations, compression, boot compatibility and flashcart/physical cartridge behavior.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-003 — Save versioning and migration
- **Work:** Design version/checksum/backup/upgrade paths for all human residents and town state; preserve original item IDs and letter/Controller Pak data; reject unsupported versions without writing over them.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-004 — Stock RAM/performance budgets
- **Work:** Profile CPU/RSP/RDP, graphics heap, scene maps, actors, audio and 4 MiB behavior; optionally benchmark 8 MiB Expansion Pak if an enhancement benefits.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-005 — Asset and compression pipelines
- **Work:** Version source/asset manifests, validate extracted sizes, compression/decompression and dynamic load/evict timing, and test against constrained memory.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-006 — N64-appropriate rendering optimizations
- **Work:** Research N64 homebrew techniques and adopt only benchmarked wins with consistent lighting, geometry and camera behavior; avoid speculative engine rewrites.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-007 — Stable IDs and map/actor namespace
- **Work:** Allocate consistent IDs to new actors/items/rooms/messages and assert table bounds. No original save-data field may be silently repurposed.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-008 — Clock/calendar/event scheduling
- **Work:** Test N64 cartridge RTC, bad battery/reset behavior, midnight, leap day, seasons and long periods. Improved year ranges or new holidays are separate Enhanced decisions.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-009 — Famicom/NES and Pak loader integrity
- **Work:** Document available original emulator, Pak filesystem data and ROM-size/mapper checks; reject absent/invalid slots safely without bundling unauthorized game assets.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-010 — Optional networking interface
- **Work:** After offline/export works, prototype network round-trip using an optional compatible flashcart; validate all remote input and preserve offline boots.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-011 — Protected localization catalogs and incremental builds
- **Work:** Use reviewed JP↔EN message master, chunk/context lookup and protected writes, versioned manifests, reproducible ROM output and an automated change report.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

### TECH-012 — Regression and original-hardware qualification
- **Work:** Build test matrix for multi-resident save, RTC, game state, full inventory, town boundaries, dialogs, letters, NES, seasonal events and frame pacing.
- **Acceptance:** reproduction/instrumentation logged, any relevant N64 build and original-hardware regression passed.
- **Status:** Planned (reference work may already be in progress; verify against repo).

## Build and compatibility policy

Keep Japanese matching, English and Enhanced outputs, asset manifests and test reports distinct. The code-line names in the roadmap are proposed; inspect current build configuration before adding targets. English and Enhanced must not overwrite reference output or change its expected hashes. Do not run ROM builds for documentation-only changes.

TECH-003 owns version/checksum/backup/migration and unsupported-version rejection. Define original Japanese ↔ English text compatibility explicitly; do not promise reverse conversion. Enhanced migration must preserve original item IDs, town layout, all four residents, house storage, letters and attachments. Never silently write incompatible state into a legacy save.

TECH-008 includes researching post-2030 calendar support as an Enhanced decision, independently of any verified original calendar fix. TECH-009 includes 32 KiB Controller Pak filesystem/reserved-page limits, NESINFO, Yay0, mapper and decompressed-size checks. TECH-006 may evaluate Kaze Emanuar-style optimization concepts only through N64 benchmarks.

## Fork progress provenance

Retained snapshot: **505,840 / 2,515,744 matched code bytes (20.11%), October 30, 2026**. Source: this fork's README at commit `0c9484d` plus the dated supplied All-in-One README and owner instruction. This is local fork progress, not zeldaret/af statistics, and is not a new measurement. Local research logs record individual matching work but do not establish a newer authoritative aggregate. No progress build was run for this documentation change. Upstream CI remains labeled upstream.
