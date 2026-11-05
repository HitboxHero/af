# Animal Forest [![Upstream CI][gha-badge]][gha] ![Fork code jp — 2026-10-30][Code jp Progress] [![Discord Channel][discord-badge]][discord]

[gha]: https://github.com/zeldaret/af/actions/workflows/ci.yml?query=branch%3Amain+event%3Apush
[gha-badge]: https://img.shields.io/github/actions/workflow/status/zeldaret/af/ci.yml

[Code jp Progress]: https://img.shields.io/badge/Code%20jp-20.11%25-blue

[discord]: https://discord.zelda.deco.mp/
[discord-badge]: https://img.shields.io/discord/688807550715560050?color=%237289DA&logo=discord&logoColor=%23FFFFFF

This is a work-in-progress decompilation project for the Nintendo 64 game *Animal Forest*, also known as どうぶつの森 (*Doubutsu no Mori*).
There is a decompilation project for the GameCube versions (*Animal Crossing*, etc.) [here](https://github.com/Prakxo/ac-decomp/).

This fork builds upon the original [zeldaret/af](https://github.com/zeldaret/af) project, with additional matching decompilation work and longer-term goals for localization, bug fixes, and improvements inspired by the GameCube releases.

**Fork progress snapshot (October 30, 2026):** 505,840 / 2,515,744 matched code bytes (20.11%). This dated local report is not upstream progress. The build badge represents **upstream CI**. See [progress provenance](docs/TECHNICAL.md#fork-progress-provenance).

```diff
- WARNING! -

This repository is a work in progress, and while it can be used to make certain changes, it is
still constantly evolving. If you wish to use it for modding purposes in its current state,
please be aware that the codebase could drastically change at any time. Also note that some
parts of the ROM may not be 'shiftable' yet, so modifying them could currently be difficult.
```

**Note:** This project is currently a matching Nintendo 64 decompilation, not a PC port.
It takes a Nintendo 64 ROM, extracts assets from it, and combines them with C code reverse-engineered from the ROM to produce an identical ROM.
The objective of the matching phase is to preserve the original game's behavior and binary output while recovering readable source code.

## Project Goals

Preserve the original matching decompilation while developing two separate future editions for original N64 hardware:

- **Japanese matching reference:** readable C reproducing the original Japanese ROM byte-for-byte; no gameplay or text modifications.
- **Animal Forest 64 — English Edition:** complete technical localization and verified N64 bug fixes, preserving original content, events, balance, visual identity and four human residents.
- **Animal Forest 64 — Enhanced Edition:** inherits English and adds approved QoL, museum/Blathers, Animal Island and selected GameCube/e+ content as hardware and save constraints permit.

Physical e-Reader functionality is outside both editions. Planned editions and build separation are development goals, not released features.

## Development roadmap and documentation

Matching preservation → English playable slice → complete localization and verified fixes → stable English milestone → Enhanced save/hardware foundation → incremental content and QoL. No release date is promised.

| Document | Contents |
|---|---|
| [Roadmap](docs/ROADMAP.md) | Phases, priorities, edition boundaries and milestone gates |
| [Localization](docs/LOCALIZATION.md) | Message system, fonts/input, Animalese, letter scoring and translation QA |
| [Bugs](docs/BUGS.md) | Version-gated reports, reproduction methods, proposed fixes and regressions |
| [Quality of life](docs/QUALITY_OF_LIFE.md) | Optional Enhanced usability improvements |
| [Enhanced Edition](docs/ENHANCED_EDITION.md) | Content specifications, dependencies and feasibility decisions |
| [Technical plan](docs/TECHNICAL.md) | Matching workflow, ROM/RAM, saves, hardware and performance |
| [Testing](docs/TESTING.md) | Emulator, original N64, translation and save acceptance |
| [References](docs/REFERENCES.md) | Sources, mechanics research and provenance |
| [Issue tracker](docs/ISSUE_TRACKER.csv) | Stable IDs, status, applicability, dependencies and acceptance |

GameCube observations are research evidence, not confirmed Japanese N64 bugs. Every fix needs version applicability and before/after evidence; museum and island integration checks belong to Enhanced.

## Setup

### Linux

#### 1. Install build dependencies

The build process has the following package requirements:

* make
* git
* build-essential
* clang
* binutils-mips-linux-gnu
* python3
* python3-pip
* python3-venv

Under Debian / Ubuntu (which we recommend using), you can install them with the following commands:

```bash
sudo apt update
sudo apt install make git build-essential clang binutils-mips-linux-gnu python3 python3-pip python3-venv
```

#### 2. Install Python dependencies

The build process has a few Python packages required that are located in `requirements.txt`.

To install them, simply run in a terminal:

```bash
make venv
```

#### 3. Prepare a base ROM

Copy your ROM to inside `baseroms/` in the version folder corresponding to your ROM's version, and rename the file of the baserom to `baserom.z64`.

Example: `baseroms/jp/baserom.z64`

#### 4. Make and Build the ROM

To start the extraction/build process, run the following commands:

```bash
make setup
make extract
make
make compress
```

## Note about licensing

The contents of the `src` and `include` folders are, as far as possible, licensed under CC0.

Other folders and files in the repository are CC0 unless they specify another license.

The licensing of this repository does not cover subrepos, namely:

* `tools/asm-differ`
* `tools/asm-processor`
* `tools/fado`
* `lib/ultralib`
* `tools/z64compress`
