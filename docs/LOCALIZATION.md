# Localization specification — English Edition and inherited Enhanced base

English Edition is **not** the North American GameCube game backported wholesale. It is the original Japanese N64 game, naturally translated into English, with original holidays, four human residents, gameplay pacing, and no imported museum, island, tailor or new events.

## Nonnegotiable rules

1. Preserve a byte-for-byte reproducible **Japanese matching reference**. Translate only in the nonmatching English build.
2. Preserve N64 message identities and all functional control tags. A translation may become longer, but must not move an event trigger or change a branching condition accidentally.
3. Measure N64 text count and engine behavior directly. The notes cite **>20,000 message offsets / ~450,000 English words** for a GameCube build, **not confirmed counts for N64**.
4. Reuse the project's protected, reviewed JP/EN master catalog. Never use raw machine translation output as a final release entry without checking event context.
5. All accepted localization work passes to Enhanced automatically; Enhanced-only dialogue IDs and items remain in their own namespace.

## Implementation tasks

### LOC-001 — Canonical Japanese message inventory
- **Requirement:** Extract every N64 message and text source (dialogue, event, items, menus, prompts, letters, save/error/RTC screens, NES descriptions) with stable ID, address/offset, callsite/context, and raw control bytes. Label unknown or unused records; do not guess ownership from adjacent GameCube IDs.
- **Definition of done:** Every referenced text ID accounted for; dump→encode→dump round-trip byte-exact with untouched original; orphan/invalid references reported.
- **Status:** Planned / review current project tooling. **Priority:** P0.

### LOC-002 — English translation and editorial policy
- **Requirement:** Translate the *original N64* dialogue, item names, menus, holiday lines, greetings, letters, post office, title and error text. Reuse recognizable official GameCube names/phrasing when they accurately correspond; preserve Japanese-original scenes absent from GC and retain distinct snarky personality tone. Maintain translator notes on wordplay, names, pronouns, honorifics and cultural references.
- **Definition of done:** 100% of reachable N64 Japanese text reviewed by context, with gloss, EN final text, reviewer and proof; intentional untranslated labels documented.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-003 — Message control commands and conditional flow
- **Requirement:** Decode and validate embedded bytes for speakers, expression/animation, music and sound, color, pauses, page breaks, choice branching, variable substitutions, quest flags and message chains. Specify syntax, protected spans, widths and legal command positions; some claimed GC controls may not exist on N64.
- **Definition of done:** Identical control semantics for each translated message; no malformed control bytes, wrong branches or dialogue softlocks; first-time vs repeat paths tested.
- **Status:** Planned / review current project tooling. **Priority:** P0.


**Additional retained research / test methods (previous README; unverified):**
- **Mechanism to watch:** first-generation dialogue uses embedded commands for names, expressions, pauses, color, music, scene/quest branching and variable insertion. English expansion can overrun message capacity, corrupt a control sequence, or misalign pointer/offset tables.
- **Reproduce:** (1) For each translated message, round-trip decode/encode and compare preserved control-tag types/order. (2) Inject longest legal player/town/villager/item names and multiple variables. (3) Test pagination/window widths and branching dialogue during events, saves, and interrupts. **Expected:** valid parser and complete text rendering; no truncated commands or wrong branches.
- **Fix/regression:** explicit control-code schema, bounded encoder/decoder, message index/offset validator, font-width layout tests, and smoke-test all classes of scripted conversations. Track exact message IDs rather than inventing visible English text.

### LOC-004 — English font, wrapping and dialog layouts
- **Requirement:** Inventory N64 glyphs and texture/font RAM, add Latin upper/lowercase, numerals, punctuation, apostrophes, accents/symbols as budget permits. Test proportional width or conservative character metrics, word-breaks, descenders, page overflow, choice-box height, tiny HUD and full-screen labels.
- **Definition of done:** No clipping or unreadable glyphs at max legal names and longest messages; rendering stays within stock RAM/frame budgets.
- **Status:** Planned / review current project tooling. **Priority:** P0.

### LOC-005 — English keyboard and text entry
- **Requirement:** Provide N64-controller-friendly A–Z/a–z input, space/punctuation, delete/cancel/confirm and length limits for player name, town name, letters, diary and other native writable fields. Store an unambiguous encoding and handle original JP save strings without corruption.
- **Definition of done:** Round-trip each input type through save/RTC/reset; reject invalid bytes cleanly; four residents retain distinct names, diaries and letters.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-006 — Dynamic names, grammar and variable injection
- **Requirement:** Audit text commands that splice player/town/villager/item names, prices, plurals, articles, gender-neutral terms, day/month, weather, town tune, friendship, personalities and event flags. Avoid replacing variable tokens with plain English text. Define format-aware grammatical variants where necessary.
- **Definition of done:** Max-length substitutions and nested variable messages render correctly for all four human residents; no wrong item/person name or overflow.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-007 — English Animalese and speech timing
- **Requirement:** Inspect how original Japanese speech samples/character mapping work; compare GameCube English Animalese phoneme logic and sample availability. Implement equivalent English character-to-voice behavior if technically feasible with N64 audio storage, timing and bank constraints.
- **Definition of done:** Spoken text aligns with printed text, punctuation/pause speed and mute behavior; no audio underruns; real N64 verified; documented fallback if direct GC-style method is infeasible.
- **Status:** Planned / review current project tooling. **Priority:** P2.

### LOC-008 — Japanese-to-English letter tokenizer and policy
- **Requirement:** Measure N64 Japanese letter-scoring and event response systems first. Specify English words/spaces/punctuation/case/length rules and correspondence to intended villager understanding; use American GC as a behavioral reference, not a direct code copy. Avoid surprising rewards from arbitrary bytes.
- **Definition of done:** Deterministic test corpus of meaningful/garbage/empty/long letters; stable, explainable scores; all four residents and attachments respected.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-009 — Bounds-safe English trigram scoring
- **Requirement:** Research GC English use of the first three letters of words. Source notes report 776 intended trigrams and an NA GameCube missing-terminator overread that interpreted >23k accidental matches; these figures are not N64 facts. Store a known-size, explicitly terminated/length-checked trigram table and normalize character input before lookup.
- **Definition of done:** Unit test every 26^3 three-letter combination plus fuzzed nonletters; no read outside table under ASAN/native test harness; exact expected scores; stable under different RAM contents.
- **Status:** Planned / review current project tooling. **Priority:** P0.


**Additional retained research / test methods (previous README; unverified):**
- **Reported mechanism:** English/GC scoring recognizes leading three-letter sequences (“trigrams”). A missing table terminator/bounds condition means search proceeds past the intended **776** trigrams and can interpret thousands of unrelated memory combinations as valid. The transcript cites over **23,000** apparent combinations and ~**5.8 MB** of inspected bytes; these are GC research figures, **not validated N64 memory sizes**.
- **Reproduce in reference:** (1) Score a valid three-letter prefix and an invalid/artificial prefix in NA GameCube. (2) Log lookup range/end pointer. (3) Check whether matching continues beyond the trigram table; repeat with different memory contents/save states. **Expected:** only explicit table entries score. **Reported actual:** out-of-bounds matches and inconsistent letter ranking.
- **EN implementation:** the **Japanese N64 algorithm is not a drop-in English scorer**. Specify English tokenization, punctuation, case normalization, word length and phrase/attachment rules. Implement bounds-checked trigram arrays with explicit lengths and unit-test all 26³ candidate trigrams plus adversarial letter lengths/characters. **Preserve intentional special letter-quest scoring** (see `LOC-006`) rather than conflating it with this defect.

### LOC-010 — Villager-request letter quests and gift categories
- **Requirement:** Check if the N64 has an analogue of the later GC request-for-letter quest. GC notes describe temporary quest active until bedtime/reset and distinct rank 0–11 using non-space length, three-word/nonrepetition check (+3) and present attachment (+6), yielding predictable category rewards. Implement/adapt only the paths actually present or explicitly approved.
- **Definition of done:** Regular and quest scoring are separate; test 0–2 versus ≥3 words, repeated characters, attachment yes/no, quest expiry/reset, each rank/category and inventory-full responses.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-011 — Mail/post office, letter formatting and persistence
- **Requirement:** Translate stationery variants, recipient selection, addresses, saved drafts, sending, incoming mail, gifts/attachments, villager replies, mailbox-full/errors and any Controller Pak-related pathways. Protect control chars within the letter body and validate string terminators.
- **Definition of done:** Mail opens and responds correctly; attached item ownership preserved; save/reload and four-player mailboxes tested; no ghost or lost gifts.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-012 — Holidays, calendar and culturally specific names
- **Requirement:** Keep original N64 holiday dates, characters, music, gifts and Japanese cultural identity in the English Edition. Explain unfamiliar celebrations in fluent English rather than silently replacing them with North American GameCube events. Optional new/regional holidays belong exclusively in Enhanced.
- **Definition of done:** Every original scheduled event has localized names and text; date, weekday, seasonal/weather branches tested against Japanese N64; untranslated holidays explicitly flagged.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-013 — Catalog item IDs, item labels, and text-to-object maps
- **Requirement:** Map N64 item IDs to English names, descriptions, categories, furniture/diary/clothing/fish/bug labels, tools, NES collectibles and special/unused IDs. Version the table rather than inferring item type from text positions.
- **Definition of done:** Inventory/shop/gift/letter/item display use consistent labels; no wrong object due to reordered strings; invalid IDs show safe fallback in development builds.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-014 — Intro, title, RTC, save, and uncommon paths
- **Requirement:** Include train/Rover and Nook tutorial, K.K. or N64 title startup, clock drift/battery, damaged save/Controller Pak, player switch, reset, travel, game over/exception/error prompts and less common conditional dialogue. GC memory-card-only text is not assumed to exist on N64.
- **Definition of done:** Cold start, first day, all original valid failures and long-idle sessions tested; no Japanese fallback on reachable paths.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-015 — Closed-loop translation QA and controlled batch workflow
- **Requirement:** Track each record with original JP, literal gloss, canonical English, protected bytes, source location, speaker, context edges, status/reviewer/version, screenshot and last tested commit. Use batches of ~50 for human/AI review while retaining a single protected canonical master. Search adjacent ±16 records and call-graph context on disagreement; never allow an agent to overwrite the master without review.
- **Definition of done:** Rebuild manifests show exact modified IDs; script diffs independent of compiled ROM; duplicate strings resolved consistently; no unapproved translation master changes.
- **Status:** Planned / review current project tooling. **Priority:** P1.

### LOC-016 — Localization acceptance suite and release coverage
- **Requirement:** Automate message parsing, pointer/address bounds, font width, prohibited control changes, all name/variable extremes, letter score corpus, item mapping and versioned report; sample each type in an emulator and original N64. Add English save conversion and backward compatibility decisions.
- **Definition of done:** Coverage report shows reachable IDs translated/verified, screenshot proof, no known P0/P1 localization regressions, and testable English version in a fresh four-human-resident town.
- **Status:** Planned / review current project tooling. **Priority:** P0.

## Letter scoring: concrete design and verification

### What the original research does—and does not—establish

- The original **Japanese** letter systems use Japanese kana and different spacing/word assumptions. Do **not** blindly reuse them for English. Japanese scoring was described as relying on trigram tables, but confirm the N64 implementation directly.
- The **North American GameCube** system reportedly scores leading three-character word prefixes against a language-specific trigram table and considers other grammar/length checks. The attached research describes an unbounded scan because a stop sentinel was missing, allowing unrelated memory to count as valid trigrams. This is a cautionary precedent, **not a claim that N64 reads into RAM**.
- In reported **GameCube special villager letter quests**, the letter is ranked by a different path (reported 0–11) based on non-space length, number of words/adjacent repeats, and attached gift; a return-gift category follows that rank. Do not merge that mechanic with ordinary grammar scoring. Determine whether the N64 has this quest before adding it to `EN`.

### Safe implementation outline (not a claim of existing N64 code)

```c
// Proposed design: adapt field types to the project's actual decomp.
bool english_trigram_is_known(const char prefix[3]) {
    // Normalize letters; reject unsupported characters.
    // Search only within the explicitly declared table length.
    // Never follow a missing terminator into adjacent symbols or RAM.
    return bounded_trigram_lookup(prefix, english_trigrams, english_trigram_count);
}
```

### Repeatable letter tests

| Case | Setup | Expected test outcome |
|---|---|---|
| Real English | Three meaningful words, punctuation and an item name | Scored according to documented English rules, no clipping. |
| Nonsense | Clearly invalid prefixes and repeated gibberish | No accidental memory-derived trigram validity. |
| Prefix boundary | First known, first absent and last known trigram | Only in-range elements can match. |
| All combos | Enumerate all 17,576 A–Z trigrams | Observed matches exactly equal approved table set. |
| Nonletters | Mixed case, spaces, digits, punctuation, unusual bytes | Normalization/rejection deterministic and safe. |
| Long word | Maximum input and an overlong word if allowed | Correct penalty/cap; no buffer overrun. |
| Quest words | Zero, one, two, then three eligible words | Quest score change only if the original event exists/was approved. |
| Quest repetition | Repeated adjacent letters versus clean message | Correct quest check, no unpredictable bonus. |
| Attachment | Same body with and without present | Only intended quest/regular branch changes. |
| Quest expiration | Send before bedtime, after bedtime, after reset | No stale quest state or duplicate rewards. |
| Four residents | Different humans sending to same/different villagers | No aliasing of sender, letter or reply flags. |

**Test oracle:** maintain a standalone score function with checked expected cases and compare it with emulated game behavior. Capture the relevant villager reward category as well as numeric score. If GC and N64 differ, write the reason rather than forcing GC parity.

## Translation record template

```yaml
id: N64_MESSAGE_ID
jp_raw: "..."           # Keep control bytes in a separate protected field.
literal_gloss: "..."
en_candidate: "..."
control_signature: "..."
speaker: "..."
branch_context: "..."
source_symbol: "..."
status: draft            # draft/reviewed/approved/in-game-verified
reviewer: ""
proof: ""                # Screenshot + ROM/commit information
```

## Release definition

- [ ] All **reachable** Japanese text inventory IDs mapped and translated.
- [ ] Automated message format/control checks pass, with no pointer/array overread.
- [ ] All English input, letter body, and variable insertion paths checked.
- [ ] Standard and quest letter systems tested separately for source applicability and safe English behavior.
- [ ] Representative NPC personalities, events, errors, and rare paths reviewed in-game.

## Hardware release gate

- [ ] Full town gameplay and saving tested on original N64 hardware with four human save slots.

## Formatting and consistency decisions

LOC-005 must record exact measured byte/glyph limits per player/town/name and writable field before coding; no guessed larger limits. LOC-012 must specify English month/day/year and weekday presentation, unambiguous numeric date formatting, plural/ordinal conventions, while preserving original event dates. Maintain a shared terminology glossary and test the longest legal substitutions.
