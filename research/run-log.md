ac_reserve func_80A093FC_jp: 16 bytes; 1 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.
ac_reserve func_80A09580_jp: 32 bytes; 2 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.
ac_reserve func_80A095A0_jp: 36 bytes; 1 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.
ac_reserve aRSV_actor_ct: 64 bytes; 1 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.
ac_reserve aRSV_actor_init: 104 bytes; 1 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.
ac_reserve func_80A09370_jp: 140 bytes; 1 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.
ac_reserve func_80A094EC_jp: 148 bytes; 2 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.
ac_reserve func_80A0940C_jp: 224 bytes; 2 attempt(s); BLOCKED: reverted; final asm-differ score 105.
ac_reserve aRSV_actor_draw: 336 bytes; 2 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.

ac_reserve verification: 9 functions / 1100 bytes + 4 padding; existing C TU; no cross-function local-label/jump-table references; ROM span 0x8D8000..0x8D8450, data through 0x8D84A0, relocations through 0x8D8510. Entire overlay and relocations match original; object text/padding and text relocations exact. 8/9 functions (876 bytes + 4 padding) matched in 13 attempts. Full build and make compress passed; MD5 d7ae64f2f47a9fa3f87686a3c5ce09af / a4f7c57c180297b2e7ba5a5feb44fe0b.
ac_ride_off_demo aROD_actor_dt: 40 bytes; 1 attempt(s); BLOCKED: reverted; demo pointer common_data+0x100AC lacks verified declaration (score 10).
ac_ride_off_demo func_80953C60_jp: 48 bytes; 1 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.
ac_ride_off_demo func_80953AE8_jp: 72 bytes; 1 attempt(s); PASS: score 0, linked bytes/relocations/full text and padding exact.

ac_ride_off_demo verification: existing C TU, 15 functions / 1224 bytes + 8 padding; no cross-function local labels. Text 0x848600..0x848AD0, data through 0x848B30, rodata through 0x848B40, relocations through 0x848BF0; BSS 16 bytes unchanged. Entire overlay bytes, object text/rodata/padding and text relocations exact. 2/15 functions (120 bytes) matched in 3 attempts; 13 blocked by missing verified declarations. Full build, make compress and diff --check passed; MD5 d7ae64f2f47a9fa3f87686a3c5ce09af / a4f7c57c180297b2e7ba5a5feb44fe0b.
ac_npc_sleep_obaba func_809CF138_jp: B, 20 bytes; 0 attempts; undeclared NPC byte +0x7C9; original assembly retained.
ac_npc_sleep_obaba func_809CF058_jp: B, 32 bytes; 0 attempts; undeclared NPC bytes +0x7D4/+0x7D5/+0x7D6; original assembly retained.
ac_npc_sleep_obaba func_809CF0AC_jp: B, 32 bytes; 0 attempts; undeclared NPC word +0x188 and byte +0x7C6; original assembly retained.
ac_npc_sleep_obaba func_809CF170_jp: B, 40 bytes; 0 attempts; undeclared actor callback +0x93C; original assembly retained.
ac_npc_sleep_obaba func_809CF240_jp: B, 48 bytes; 0 attempts; undeclared NPC word +0x7A8 and callback +0x7D0; original assembly retained.
ac_npc_sleep_obaba func_809CF024_jp: B, 52 bytes; 0 attempts; undeclared NPC demo flags word +0x80C; original assembly retained.
ac_npc_sleep_obaba func_809CF078_jp: B, 52 bytes; 0 attempts; undeclared NPC word +0x188 and bytes +0x72B/+0x7C6; original assembly retained.
ac_npc_sleep_obaba func_809CF2A0_jp: B, 68 bytes; 0 attempts; undeclared NPC callback +0x7A4 and byte +0x7FD; original assembly retained.
ac_npc_sleep_obaba func_809CF0CC_jp: B, 108 bytes; 0 attempts; undeclared NPC bytes +0x7C6/+0x72B and actor state/callback +0x938/+0x93C; original assembly retained.
ac_npc_sleep_obaba func_809CF1C8_jp: B, 120 bytes; 0 attempts; undeclared NPC action bytes +0x7C5/+0x7C6; original assembly retained.
ac_npc_sleep_obaba aNSO_actor_ct: B, 160 bytes; 0 attempts; undeclared NPC schedule callback +0x7C0; original assembly retained.
ac_npc_sleep_obaba func_809CF14C_jp: A, 36 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba aNSO_actor_dt: A, 44 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba aNSO_actor_init: A, 44 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba aNSO_actor_save: A, 44 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba func_809CF380_jp: A, 44 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba func_809CF198_jp: A, 48 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba func_809CF270_jp: A, 48 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba func_809CF350_jp: A, 48 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba func_809CEFE4_jp: A, 64 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_npc_sleep_obaba func_809CF2E4_jp: A, 108 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.

ac_npc_sleep_obaba verification: existing C TU, 21 functions / 1260 bytes + 4 padding; classification A=10/B=11/C=0, no cross-function local labels. Text 0x8B26B0..0x8B2BA0, data through 0x8B2C20, relocations through 0x8B2CE0. Entire overlay bytes and object text/padding/relocations exact. 10/21 functions (528 bytes + 4 padding) matched in 10 attempts; all category B functions remain in assembly. Full build, make compress and diff --check passed; MD5 d7ae64f2f47a9fa3f87686a3c5ce09af / a4f7c57c180297b2e7ba5a5feb44fe0b.
ac_t_umbrella func_80A1EE48_jp: B, 60 bytes; 0 attempts; undeclared umbrella scale vectors +0x1D4/+0x1E0; original assembly retained.
ac_t_umbrella aTUMB_actor_move: B, 80 bytes; 0 attempts; undeclared umbrella action +0x1CC and callback +0x1C8; original assembly retained.
ac_t_umbrella func_80A1EF20_jp: B, 116 bytes; 0 attempts; undeclared umbrella callback/action/frame/opened fields +0x1C8/+0x1CC/+0x1D0/+0x1EC; original assembly retained.
ac_t_umbrella func_80A1EE84_jp: B, 124 bytes; 0 attempts; undeclared umbrella action/frame/opened fields +0x1CC/+0x1D0/+0x1EC; original assembly retained.
ac_t_umbrella func_80A1ED4C_jp: B, 252 bytes; 0 attempts; undeclared umbrella action/frame +0x1CC/+0x1D0 and N64 interpolation-table type; original assembly retained.
ac_t_umbrella aTUMB_actor_draw: B, 448 bytes; 0 attempts; undeclared umbrella scale vectors +0x1D4/+0x1E0; original assembly retained.
ac_t_umbrella func_80A1EF00_jp: A, 32 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_t_umbrella aTUMB_actor_ct: A, 36 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_t_umbrella func_80A1ECD4_jp: A, 48 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.
ac_t_umbrella func_80A1ED04_jp: A, 72 bytes; 1 attempt; PASS score 0, linked bytes/relocations/full text and padding exact.

ac_t_umbrella verification: existing C TU, 10 functions / 1268 bytes + 12 padding; A=4/B=6/C=0, no cross-function local labels. Text 0x8E6770..0x8E6C70, data through 0x8E6F00, rodata through 0x8E6F10, relocations through 0x8E6FD0. Entire overlay bytes, object text/rodata/padding and text relocations exact. 4/10 functions (188 bytes) matched in 4 attempts; six category B functions remain in assembly. Full build, make compress and diff --check passed; MD5 d7ae64f2f47a9fa3f87686a3c5ce09af / a4f7c57c180297b2e7ba5a5feb44fe0b.
ac_yatai func_80A76F50_jp: B (unverified local field value), 528 bytes; 0 attempts; xyz_t pos.y at sp+0x7C is passed without initialization; matching C would require forbidden undefined behavior; original assembly retained.
ac_yatai func_80A77160_jp: A, 16 bytes; 1 attempt(s); PASS score 0, linked bytes/relocations/full text and padding exact.
ac_yatai func_80A77170_jp: A, 32 bytes; 1 attempt(s); PASS score 0, linked bytes/relocations/full text and padding exact.
ac_yatai aYAT_actor_ct: A, 68 bytes; 1 attempt(s); PASS score 0, linked bytes/relocations/full text and padding exact.
ac_yatai aYAT_actor_init: A, 104 bytes; 1 attempt(s); PASS score 0, linked bytes/relocations/full text and padding exact.
ac_yatai func_80A76EC4_jp: A, 140 bytes; 1 attempt(s); PASS score 0, linked bytes/relocations/full text and padding exact.
ac_yatai func_80A77190_jp: A, 232 bytes; 2 attempt(s); BLOCKED; reverted after final asm-differ score 52.
ac_yatai aYAT_actor_draw: A, 328 bytes; 2 attempt(s); PASS score 0, linked bytes/relocations/full text and padding exact.

ac_yatai verification: existing C TU, 8 functions / 1448 bytes + 8 padding; A=7/B=1 (unverified local pos.y initialization, not a shared type gap)/C=0; no cross-function local labels. Text 0x937120..0x9376D0, data through 0x9377F0, rodata through 0x937820, relocations through 0x9378C0. Entire overlay bytes and object text/rodata/padding/relocations exact. 6/8 functions (688 bytes + 8 padding) matched in 9 attempts; movement mismatch and terrain-offset undefined-local-value blocker remain in assembly. Full build, make compress and diff --check passed; MD5 d7ae64f2f47a9fa3f87686a3c5ce09af / a4f7c57c180297b2e7ba5a5feb44fe0b.
