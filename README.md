# Animal Forest [![Build Status][gha-badge]][gha] ![Code jp Progress] [![Discord Channel][discord-badge]][discord]

[gha]: https://github.com/zeldaret/af/actions/workflows/ci.yml?query=branch%3Amain+event%3Apush
[gha-badge]: https://img.shields.io/github/actions/workflow/status/zeldaret/af/ci.yml

[Code jp Progress]: https://img.shields.io/badge/Code%20jp-20.11%25-blue

[discord]: https://discord.zelda.deco.mp/
[discord-badge]: https://img.shields.io/discord/688807550715560050?color=%237289DA&logo=discord&logoColor=%23FFFFFF

This is a work-in-progress decompilation project for the Nintendo 64 game *Animal Forest*, also known as どうぶつの森 (*Doubutsu no Mori*).
There is a decompilation project for the GameCube versions (*Animal Crossing*, etc.) [here](https://github.com/Prakxo/ac-decomp/).

This fork builds upon the original [zeldaret/af](https://github.com/zeldaret/af) project, with additional matching decompilation work and longer-term goals for localization, bug fixes, and improvements inspired by the GameCube releases.

**Progress:** The code badge reflects this fork’s latest local progress report: 505,840 of 2,515,744 code bytes matched (20.11%). The build badge reflects the upstream project.

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

The long-term goal of this fork is to preserve and improve the original Nintendo 64 version of *Animal Forest* while maintaining compatibility with original hardware.

* **Complete the decompilation:** Reconstruct the original Japanese game's code in readable, maintainable C, with matching assembly and identical ROM output.
* **English translation:** Develop a complete English localization, including dialogue, menus, item names, interface text, and other Japanese-language content.
* **Bug fixes:** Identify and patch known bugs and glitches in the original N64 release while preserving the intended gameplay experience.
* **GameCube feature parity:** Bring selected features, improvements, and refinements from the GameCube releases of *Animal Crossing* to the Nintendo 64 version where technically feasible.
* **Quality-of-life improvements:** Explore optional enhancements to menus, controls, usability, and gameplay without losing the original game's identity.
* **Hardware compatibility:** Ensure modified builds remain playable on original Nintendo 64 hardware, including appropriate cartridge and save/RTC support.

Matching decompilation remains the immediate priority. Translation, bug fixes, and gameplay modifications will be developed separately so that the original matching build can continue to reproduce the reference ROM exactly.

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
