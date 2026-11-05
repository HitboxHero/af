# Testing and release qualification

## Minimum test matrix

| Domain | Cases |
|---|---|
| Boot/save | new town, clean existing town, four humans, save/reload, repeated save, interrupted save/recovery on safe test hardware |
| RTC | correct battery, missing/failed RTC, date rollover, clock adjustment, month/year boundary, in-game events |
| World | legal acre borders, tree/sapling growth, three-tier if generated, room loading, NPC schedules, collision |
| Text | rare event messages, max names, control bytes, early cancel/rapid input, page boundaries, multilingual stray bytes |
| Letters | ordinary score, quest score if supported, attachments, full pockets, mail arrival, Controller Pak paths |
| Items | tool durability, flower/bug behavior, gifts, shops, save item namespaces, invalid IDs and unknown item fallback |
| Additional content | museum/island/house changes, NPC events, menu bulk operations, additional NES catalog enter/exit in Enhanced; shipped N64 Famicom paths in all builds |
| Hardware | original 4 MiB N64 and RTC-capable cartridge/flashcart, sustained audio/video, original controller, optional 8 MiB case |

## Completion template

```md
- [ ] Scope and source release identified (N64 / GC / new Enhanced).
- [ ] Before state with reproducible save or deterministic test.
- [ ] Minimal, code-reviewed change and updated ID/catalog registry.
- [ ] After state proves desired behavior; normal path still passes.
- [ ] Save migration, RTC, four residents and item/letter integrity reviewed.
- [ ] Benchmarks and real N64 test recorded where applicable.
- [ ] Documentation, issue status, source link and commit updated.

```

## Comparison protocol and recorded evidence

Use the exact original Japanese N64 ROM/revision with a recorded hash, matching reference, English, and applicable Enhanced build. Log emulator/core/version, configuration, console model, RAM, cartridge/flashcart and RTC setup. Compare at least two independent emulator implementations where available, then test original hardware; emulator agreement alone is not hardware qualification. Record Pass / Fail / Not applicable / Blocked / Not tested per case.

Keep pristine and disposable saves, town seed, date/time, inputs and before/after snapshots. Exercise two- and three-tier layouts if supported, all four human residents, player switches, full inventory/mailboxes, midnight/month/year/leap-day boundaries, clock changes, bad battery and long idle sessions. Interrupted-save tests use expendable backed-up media. Test legacy-to-English and English-to-Enhanced migration only against documented compatibility rules; unsupported saves must be rejected without writing.

Translation validation follows LOC-016: structural parsing, pointer/control-code parity, maximum-name wrapping, all personalities/event branches, standard and quest letter score corpora, and reviewed screenshot coverage. Bug regression follows each BUG/EBUG ticket's normal, boundary, failure and control cases; no ticket passes merely because RNG did not trigger once.

Hardware acceptance requires stock 4 MiB N64, controller, sustained audio/video/frame pacing, RTC and repeated save/reload; record measurements against the reference under the same busy-town workload. Optional 8 MiB/flashcart/network tests are separate configurations. Every Enhanced feature must enter, operate, cancel/exit, return to town and reload safely, including offline operation. Native shipped Famicom entry/exit remains an English regression requirement; extra games are Enhanced-only.

Phase/release gates live in [Roadmap](ROADMAP.md); system budgets and save decisions live in [Technical](TECHNICAL.md). No gameplay or hardware verification was performed during this documentation reorganization.
