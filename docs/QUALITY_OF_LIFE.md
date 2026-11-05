# Quality-of-life improvements — Enhanced Edition only

These are **deliberate changes to user experience**, not existing N64 bugs. The English Edition does **not** receive item stacking, extra storage, new maps or altered fossil workflows. Each QoL feature can be switched off/removed without invalidating the base English localization, and each needs real-hardware input, performance and save tests.

### QOL-001 — Conservative item stacking
- **Plan:** Stack only eligible consumables/resources; never collapse unique furniture, letters, turnips with differing states, or items whose metadata differs. Decide max stack count and split/merge behavior.
- **Definition of done:** A stack can split, transfer, sell, mail and survive reload without dupes.
- **Status:** Proposed. **Priority:** P2.

### QOL-002 — Multi-select pockets
- **Plan:** Provide select range/toggle and clear action preview for tools, clothes, fossils, storage and trash. Preserve item identities and existing input affordances.
- **Definition of done:** Cancel/confirm correctly; no ghost items or mismatched counts.
- **Status:** Proposed. **Priority:** P2.

### QOL-003 — Bulk sell, deposit and withdrawal
- **Plan:** Combine valid selected items into one Nook transaction and one storage transfer. Safely reject protected/invalid items and handle insufficient capacity or bell cap.
- **Definition of done:** Totals and bell balance exact, no lost items or double sale.
- **Status:** Proposed. **Priority:** P2.

### QOL-004 — Expanded organized home storage
- **Plan:** More storage capacity with categorized tabs/search or simple sorting; audit save payload and wardrobe/furniture ownership. Add migration from baseline without implicit deleting.
- **Definition of done:** Four residents’ stores isolated; 100% item persistence in save/reload tests.
- **Status:** Proposed. **Priority:** P2.

### QOL-005 — Collection encyclopedia
- **Plan:** Track caught fish, bugs, fossils/art and donated versus merely obtained items separately; integrate museum exhibit data only once museum exists.
- **Definition of done:** Lists are accurate, complete and do not unlock by invalid item ID.
- **Status:** Proposed. **Priority:** P2.

### QOL-006 — Detailed town map
- **Plan:** Show resident homes, shops, important NPC buildings, key event locations and current position with icons that fit N64 memory/UI.
- **Definition of done:** No wrong markers in different generated layouts; proper acre bounds.
- **Status:** Proposed. **Priority:** P3.

### QOL-007 — Mailbox and draft management
- **Plan:** Organize, archive and send multiple letters safely, preview attachments and reply states. Reuse bounded English score and original delivery semantics.
- **Definition of done:** Repeated send/cancel/reload keeps attachment ownership; no wrong recipient.
- **Status:** Proposed. **Priority:** P2.

### QOL-008 — Blathers assesses fossils locally
- **Plan:** Replace obligatory distant fossil assessment with visit-to-Blathers, identify and donate in one loop. Preserve a deliberate translated faraway museum letter event if chosen; discovery flag must trigger even when fossil was reburied before next boot.
- **Definition of done:** Dig, rebury, restart, assess, donate, check mail all work and flag occurs once.
- **Status:** Proposed. **Priority:** P1.

### QOL-009 — Better quest and collection feedback
- **Plan:** Contextual non-spoiler messages for eligible rewards, donation progress, full pockets, mailed gifts and rare items; no intrusive modern task list by default.
- **Definition of done:** Truthful feedback under edge cases without accidental item/quest state changes.
- **Status:** Proposed. **Priority:** P3.

### QOL-010 — Faster repeat interactions
- **Plan:** Offer optional quicker text and fewer redundant menu steps for repeated visits while protecting first-time scenes, branch choices and quest flags.
- **Definition of done:** No scene skipping, twice-paid events or missing gifts at high input speed.
- **Status:** Proposed. **Priority:** P3.

## Baseline and dependency matrix

Current-behavior descriptions are design baselines to verify on the original N64, not newly measured results. Each proposal above includes its intended acceptance test. Optional QoL belongs to Enhanced; only a documented requirement for functional English text/input may enter English.

| Task | Current baseline / affected system | Required gates |
|---|---|---|
| QOL-001 | Individual inventory item records; pockets, transfers, sales | TECH-003; TECH-007 |
| QOL-002 | Single-item actions; inventory input and ownership | TECH-003; QOL-001 compatibility |
| QOL-003 | Repeated sale/storage dialogues; shop economy | QOL-002; TECH-003 |
| QOL-004 | Original limited storage; save payload and ownership | TECH-003; TECH-004 |
| QOL-005 | Original collection tracking; new encyclopedia UI | TECH-007; CONTENT-001 for donation data |
| QOL-006 | Original acre map; layout/icons/bounds | TECH-004; BUG-017 applicability |
| QOL-007 | Original individual letter flow; post office/Pak | LOC-009; LOC-011; TECH-003 |
| QOL-008 | Original distant fossil correspondence; no local museum | CONTENT-001; EBUG-007; TECH-003 |
| QOL-009 | Original contextual dialogue; quests/collections | LOC-003; LOC-006; related content |
| QOL-010 | Original text/menu pacing; modal and quest state | LOC-003; LOC-016 |
