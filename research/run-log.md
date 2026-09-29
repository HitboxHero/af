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
