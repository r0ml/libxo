/*
 * Copyright (c) 2023, Juniper Networks, Inc.
 * All rights reserved.
 * This SOFTWARE is licensed under the LICENSE provided in the
 * ../Copyright file. By downloading, installing, copying, or otherwise
 * using the SOFTWARE, you agree to be bound by the terms of that
 * LICENSE.
 * Phil Shafer, May 2023
 */

/*
 * This is generated by the code in the "unicode" branch, based on the file
 * UnicodeData.txt from unicode.org:
 *   https://unicode.org/Public/UNIDATA/UnicodeData.txt
 * I've attempted to make it simple, but can't stop it from being ugly.
 */

#include <stdio.h>
#include <wchar.h>

#include "xo_utf8.h"

wchar_t
xo_utf8_wtoupper (wchar_t wc)
{

    if ((0x0101 <= wc && wc <= 0x012f)
            || (0x0133 <= wc && wc <= 0x0137)
            || (0x014b <= wc && wc <= 0x0177)
            || (0x0183 <= wc && wc <= 0x0185)
            || (wc == 0x0199)
            || (0x01a1 <= wc && wc <= 0x01a5)
            || (wc == 0x01ad)
            || (wc == 0x01b9)
            || (wc == 0x01bd)
            || (wc == 0x01c5)
            || (wc == 0x01cb)
            || (0x01df <= wc && wc <= 0x01ef)
            || (wc == 0x01f5)
            || (0x01f9 <= wc && wc <= 0x021f)
            || (0x0223 <= wc && wc <= 0x0233)
            || (0x0247 <= wc && wc <= 0x024f)
            || (0x0371 <= wc && wc <= 0x0373)
            || (wc == 0x0377)
            || (0x03d9 <= wc && wc <= 0x03ef)
            || (wc == 0x03fb)
            || (0x0461 <= wc && wc <= 0x0481)
            || (0x048b <= wc && wc <= 0x04bf)
            || (0x04d1 <= wc && wc <= 0x052f)
            || (0x1e01 <= wc && wc <= 0x1e95)
            || (0x1ea1 <= wc && wc <= 0x1eff)
            || (wc == 0x2c61)
            || (wc == 0x2c73)
            || (0x2c81 <= wc && wc <= 0x2ce3)
            || (wc == 0x2cf3)
            || (0xa641 <= wc && wc <= 0xa66d)
            || (0xa681 <= wc && wc <= 0xa69b)
            || (0xa723 <= wc && wc <= 0xa72f)
            || (0xa733 <= wc && wc <= 0xa76f)
            || (0xa77f <= wc && wc <= 0xa787)
            || (0xa791 <= wc && wc <= 0xa793)
            || (0xa797 <= wc && wc <= 0xa7a9)
            || (0xa7b5 <= wc && wc <= 0xa7c3)
            || (wc == 0xa7d1)
            || (0xa7d7 <= wc && wc <= 0xa7d9)) {
        /* LATIN SMALL LETTER A WITH MACRON */
        /* LATIN SMALL LIGATURE IJ */
        /* LATIN SMALL LETTER ENG */
        /* LATIN SMALL LETTER B WITH TOPBAR */
        /* LATIN SMALL LETTER K WITH HOOK */
        /* LATIN SMALL LETTER O WITH HORN */
        /* LATIN SMALL LETTER T WITH HOOK */
        /* LATIN SMALL LETTER EZH REVERSED */
        /* LATIN SMALL LETTER TONE FIVE */
        /* LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON */
        /* LATIN CAPITAL LETTER N WITH SMALL LETTER J */
        /* LATIN SMALL LETTER A WITH DIAERESIS AND MACRON */
        /* LATIN SMALL LETTER G WITH ACUTE */
        /* LATIN SMALL LETTER N WITH GRAVE */
        /* LATIN SMALL LETTER OU */
        /* LATIN SMALL LETTER E WITH STROKE */
        /* GREEK SMALL LETTER HETA */
        /* GREEK SMALL LETTER PAMPHYLIAN DIGAMMA */
        /* GREEK SMALL LETTER ARCHAIC KOPPA */
        /* GREEK SMALL LETTER SAN */
        /* CYRILLIC SMALL LETTER OMEGA */
        /* CYRILLIC SMALL LETTER SHORT I WITH TAIL */
        /* CYRILLIC SMALL LETTER A WITH BREVE */
        /* LATIN SMALL LETTER A WITH RING BELOW */
        /* LATIN SMALL LETTER A WITH DOT BELOW */
        /* LATIN SMALL LETTER L WITH DOUBLE BAR */
        /* LATIN SMALL LETTER W WITH HOOK */
        /* COPTIC SMALL LETTER ALFA */
        /* COPTIC SMALL LETTER BOHAIRIC KHEI */
        /* CYRILLIC SMALL LETTER ZEMLYA */
        /* CYRILLIC SMALL LETTER DWE */
        /* LATIN SMALL LETTER EGYPTOLOGICAL ALEF */
        /* LATIN SMALL LETTER AA */
        /* LATIN SMALL LETTER TURNED INSULAR G */
        /* LATIN SMALL LETTER N WITH DESCENDER */
        /* LATIN SMALL LETTER B WITH FLOURISH */
        /* LATIN SMALL LETTER BETA */
        /* LATIN SMALL LETTER CLOSED INSULAR G */
        /* LATIN SMALL LETTER MIDDLE SCOTS S */
        wc &= ~1;

    } else if ((wc == 0x0101)
            || (0x013a <= wc && wc <= 0x0148)
            || (0x017a <= wc && wc <= 0x017e)
            || (wc == 0x0188)
            || (wc == 0x018c)
            || (wc == 0x0192)
            || (wc == 0x01a8)
            || (wc == 0x01b0)
            || (0x01b4 <= wc && wc <= 0x01b6)
            || (wc == 0x01c8)
            || (0x01ce <= wc && wc <= 0x01dc)
            || (wc == 0x01f2)
            || (wc == 0x023c)
            || (wc == 0x0242)
            || (wc == 0x03f8)
            || (0x04c2 <= wc && wc <= 0x04ce)
            || (wc == 0x2184)
            || (0x2c68 <= wc && wc <= 0x2c6c)
            || (wc == 0x2c76)
            || (0x2cec <= wc && wc <= 0x2cee)
            || (0xa77a <= wc && wc <= 0xa77c)
            || (wc == 0xa78c)
            || (0xa7c8 <= wc && wc <= 0xa7ca)
            || (wc == 0xa7f6)) {        /* LATIN SMALL LETTER A WITH MACRON */
        /* LATIN SMALL LETTER L WITH ACUTE */
        /* LATIN SMALL LETTER Z WITH ACUTE */
        /* LATIN SMALL LETTER C WITH HOOK */
        /* LATIN SMALL LETTER D WITH TOPBAR */
        /* LATIN SMALL LETTER F WITH HOOK */
        /* LATIN SMALL LETTER TONE TWO */
        /* LATIN SMALL LETTER U WITH HORN */
        /* LATIN SMALL LETTER Y WITH HOOK */
        /* LATIN CAPITAL LETTER L WITH SMALL LETTER J */
        /* LATIN SMALL LETTER A WITH CARON */
        /* LATIN CAPITAL LETTER D WITH SMALL LETTER Z */
        /* LATIN SMALL LETTER C WITH STROKE */
        /* LATIN SMALL LETTER GLOTTAL STOP */
        /* GREEK SMALL LETTER SHO */
        /* CYRILLIC SMALL LETTER ZHE WITH BREVE */
        /* LATIN SMALL LETTER REVERSED C */
        /* LATIN SMALL LETTER H WITH DESCENDER */
        /* LATIN SMALL LETTER HALF H */
        /* COPTIC SMALL LETTER CRYPTOGRAMMIC SHEI */
        /* LATIN SMALL LETTER INSULAR D */
        /* LATIN SMALL LETTER SALTILLO */
        /* LATIN SMALL LETTER D WITH SHORT STROKE OVERLAY */
        /* LATIN SMALL LETTER REVERSED HALF H */
        wc -= 1;
        wc |= 1;

    } else if ((0x0061 <= wc && wc <= 0x007a)
            || (0x00e0 <= wc && wc <= 0x00f6)
            || (0x00f8 <= wc && wc <= 0x00fe)
            || (0x03b1 <= wc && wc <= 0x03c1)
            || (0x03c3 <= wc && wc <= 0x03cb)
            || (0x0430 <= wc && wc <= 0x044f)
            || (0xff41 <= wc && wc <= 0xff5a)
            || (0x118c0 <= wc && wc <= 0x118df)
            || (0x16e60 <= wc && wc <= 0x16e7f)) {
        /* LATIN SMALL LETTER A */
        /* LATIN SMALL LETTER A WITH GRAVE */
        /* LATIN SMALL LETTER O WITH STROKE */
        /* GREEK SMALL LETTER ALPHA */
        /* GREEK SMALL LETTER SIGMA */
        /* CYRILLIC SMALL LETTER A */
        /* FULLWIDTH LATIN SMALL LETTER A */
        /* WARANG CITI SMALL LETTER NGAA */
        /* MEDEFAIDRIN SMALL LETTER M */
        wc -= 0x0020;

    } else if ((0x0561 <= wc && wc <= 0x0586)
            || (0x2c30 <= wc && wc <= 0x2c5f)) {
        /* ARMENIAN SMALL LETTER AYB */
        /* GLAGOLITIC SMALL LETTER AZU */
        wc -= 0x0030;

    } else if ((0xab70 <= wc && wc <= 0xabbf)) {
        /* CHEROKEE SMALL LETTER A */
        wc -= 0x97d0;

    } else if ((0x1f00 <= wc && wc <= 0x1f07)
            || (0x1f10 <= wc && wc <= 0x1f15)
            || (0x1f20 <= wc && wc <= 0x1f27)
            || (0x1f30 <= wc && wc <= 0x1f37)
            || (0x1f40 <= wc && wc <= 0x1f45)
            || (wc == 0x1f51)
            || (wc == 0x1f53)
            || (wc == 0x1f55)
            || (wc == 0x1f57)
            || (0x1f60 <= wc && wc <= 0x1f67)
            || (0x1f80 <= wc && wc <= 0x1f87)
            || (0x1f90 <= wc && wc <= 0x1f97)
            || (0x1fa0 <= wc && wc <= 0x1fa7)
            || (0x1fb0 <= wc && wc <= 0x1fb1)
            || (0x1fd0 <= wc && wc <= 0x1fd1)
            || (0x1fe0 <= wc && wc <= 0x1fe1)) {
        /* GREEK SMALL LETTER ALPHA WITH PSILI */
        /* GREEK SMALL LETTER EPSILON WITH PSILI */
        /* GREEK SMALL LETTER ETA WITH PSILI */
        /* GREEK SMALL LETTER IOTA WITH PSILI */
        /* GREEK SMALL LETTER OMICRON WITH PSILI */
        /* GREEK SMALL LETTER UPSILON WITH DASIA */
        /* GREEK SMALL LETTER UPSILON WITH DASIA AND VARIA */
        /* GREEK SMALL LETTER UPSILON WITH DASIA AND OXIA */
        /* GREEK SMALL LETTER UPSILON WITH DASIA AND PERISPOMENI */
        /* GREEK SMALL LETTER OMEGA WITH PSILI */
        /* GREEK SMALL LETTER ALPHA WITH PSILI AND YPOGEGRAMMENI */
        /* GREEK SMALL LETTER ETA WITH PSILI AND YPOGEGRAMMENI */
        /* GREEK SMALL LETTER OMEGA WITH PSILI AND YPOGEGRAMMENI */
        /* GREEK SMALL LETTER ALPHA WITH VRACHY */
        /* GREEK SMALL LETTER IOTA WITH VRACHY */
        /* GREEK SMALL LETTER UPSILON WITH VRACHY */
        wc += 0x0008;

    } else if ((0x10428 <= wc && wc <= 0x1044f)
            || (0x104d8 <= wc && wc <= 0x104fb)) {
        /* DESERET SMALL LETTER LONG I */
        /* OSAGE SMALL LETTER A */
        wc -= 0x0028;

    } else if ((wc == 0x03cc)
            || (0x10cc0 <= wc && wc <= 0x10cf2)) {
        /* GREEK SMALL LETTER OMICRON WITH TONOS */
        /* OLD HUNGARIAN SMALL LETTER A */
        wc -= 0x0040;

    } else if ((0x10d0 <= wc && wc <= 0x10fa)
            || (0x10fd <= wc && wc <= 0x10ff)) {
        /* GEORGIAN LETTER AN */
        /* GEORGIAN LETTER AEN */
        wc += 0x0bc0;

    } else if ((0x2d00 <= wc && wc <= 0x2d25)
            || (wc == 0x2d27)
            || (wc == 0x2d2d)) {        /* GEORGIAN SMALL LETTER AN */
        /* GEORGIAN SMALL LETTER YN */
        /* GEORGIAN SMALL LETTER AEN */
        wc -= 0x1c60;

    } else if ((0x10597 <= wc && wc <= 0x105a1)
            || (0x105a3 <= wc && wc <= 0x105b1)
            || (0x105b3 <= wc && wc <= 0x105b9)
            || (0x105bb <= wc && wc <= 0x105bc)) {
        /* VITHKUQI SMALL LETTER A */
        /* VITHKUQI SMALL LETTER HA */
        /* VITHKUQI SMALL LETTER SE */
        /* VITHKUQI SMALL LETTER Y */
        wc -= 0x0027;

    } else if ((0x1e922 <= wc && wc <= 0x1e943)) {
        /* ADLAM SMALL LETTER ALIF */
        wc -= 0x0022;

    } else if ((0x24d0 <= wc && wc <= 0x24e9)) {
        /* CIRCLED LATIN SMALL LETTER A */
        wc -= 0x001a;

    } else if ((wc == 0x03f1)
            || (0x0450 <= wc && wc <= 0x045f)) {
        /* GREEK RHO SYMBOL */
        /* CYRILLIC SMALL LETTER IE WITH GRAVE */
        wc -= 0x0050;

    } else if ((0x2170 <= wc && wc <= 0x217f)) {
        /* SMALL ROMAN NUMERAL ONE */
        wc -= 0x0010;

    } else if ((wc == 0x03d7)
            || (0x13f8 <= wc && wc <= 0x13fd)) {
        /* GREEK KAI SYMBOL */
        /* CHEROKEE SMALL LETTER YE */
        wc -= 0x0008;

    } else {
        switch (wc) {
        case 0x00b5: wc = 0x039c; break; /* MICRO SIGN */
        case 0x00ff: wc = 0x0178; break; /* LATIN SMALL LETTER Y WITH DIAERESIS */
        case 0x0131: wc = 0x0049; break; /* LATIN SMALL LETTER DOTLESS I */
        case 0x017f: wc = 0x0053; break; /* LATIN SMALL LETTER LONG S */
        case 0x0180: wc = 0x0243; break; /* LATIN SMALL LETTER B WITH STROKE */
        case 0x0195: wc = 0x01f6; break; /* LATIN SMALL LETTER HV */
        case 0x019a: wc = 0x023d; break; /* LATIN SMALL LETTER L WITH BAR */
        case 0x019e: wc = 0x0220; break; /* LATIN SMALL LETTER N WITH LONG RIGHT LEG */
        case 0x01bf: wc = 0x01f7; break; /* LATIN LETTER WYNN */
        case 0x01c6: wc = 0x01c4; break; /* LATIN SMALL LETTER DZ WITH CARON */
        case 0x01c9: wc = 0x01c7; break; /* LATIN SMALL LETTER LJ */
        case 0x01cc: wc = 0x01ca; break; /* LATIN SMALL LETTER NJ */
        case 0x01dd: wc = 0x018e; break; /* LATIN SMALL LETTER TURNED E */
        case 0x01f3: wc = 0x01f1; break; /* LATIN SMALL LETTER DZ */
        case 0x023f: wc = 0x2c7e; break; /* LATIN SMALL LETTER S WITH SWASH TAIL */
        case 0x0240: wc = 0x2c7f; break; /* LATIN SMALL LETTER Z WITH SWASH TAIL */
        case 0x0250: wc = 0x2c6f; break; /* LATIN SMALL LETTER TURNED A */
        case 0x0251: wc = 0x2c6d; break; /* LATIN SMALL LETTER ALPHA */
        case 0x0252: wc = 0x2c70; break; /* LATIN SMALL LETTER TURNED ALPHA */
        case 0x0253: wc = 0x0181; break; /* LATIN SMALL LETTER B WITH HOOK */
        case 0x0254: wc = 0x0186; break; /* LATIN SMALL LETTER OPEN O */
        case 0x0256: wc = 0x0189; break; /* LATIN SMALL LETTER D WITH TAIL */
        case 0x0257: wc = 0x018a; break; /* LATIN SMALL LETTER D WITH HOOK */
        case 0x0259: wc = 0x018f; break; /* LATIN SMALL LETTER SCHWA */
        case 0x025b: wc = 0x0190; break; /* LATIN SMALL LETTER OPEN E */
        case 0x025c: wc = 0xa7ab; break; /* LATIN SMALL LETTER REVERSED OPEN E */
        case 0x0260: wc = 0x0193; break; /* LATIN SMALL LETTER G WITH HOOK */
        case 0x0261: wc = 0xa7ac; break; /* LATIN SMALL LETTER SCRIPT G */
        case 0x0263: wc = 0x0194; break; /* LATIN SMALL LETTER GAMMA */
        case 0x0265: wc = 0xa78d; break; /* LATIN SMALL LETTER TURNED H */
        case 0x0266: wc = 0xa7aa; break; /* LATIN SMALL LETTER H WITH HOOK */
        case 0x0268: wc = 0x0197; break; /* LATIN SMALL LETTER I WITH STROKE */
        case 0x0269: wc = 0x0196; break; /* LATIN SMALL LETTER IOTA */
        case 0x026a: wc = 0xa7ae; break; /* LATIN LETTER SMALL CAPITAL I */
        case 0x026b: wc = 0x2c62; break; /* LATIN SMALL LETTER L WITH MIDDLE TILDE */
        case 0x026c: wc = 0xa7ad; break; /* LATIN SMALL LETTER L WITH BELT */
        case 0x026f: wc = 0x019c; break; /* LATIN SMALL LETTER TURNED M */
        case 0x0271: wc = 0x2c6e; break; /* LATIN SMALL LETTER M WITH HOOK */
        case 0x0272: wc = 0x019d; break; /* LATIN SMALL LETTER N WITH LEFT HOOK */
        case 0x0275: wc = 0x019f; break; /* LATIN SMALL LETTER BARRED O */
        case 0x027d: wc = 0x2c64; break; /* LATIN SMALL LETTER R WITH TAIL */
        case 0x0280: wc = 0x01a6; break; /* LATIN LETTER SMALL CAPITAL R */
        case 0x0282: wc = 0xa7c5; break; /* LATIN SMALL LETTER S WITH HOOK */
        case 0x0283: wc = 0x01a9; break; /* LATIN SMALL LETTER ESH */
        case 0x0287: wc = 0xa7b1; break; /* LATIN SMALL LETTER TURNED T */
        case 0x0288: wc = 0x01ae; break; /* LATIN SMALL LETTER T WITH RETROFLEX HOOK */
        case 0x0289: wc = 0x0244; break; /* LATIN SMALL LETTER U BAR */
        case 0x028a: wc = 0x01b1; break; /* LATIN SMALL LETTER UPSILON */
        case 0x028b: wc = 0x01b2; break; /* LATIN SMALL LETTER V WITH HOOK */
        case 0x028c: wc = 0x0245; break; /* LATIN SMALL LETTER TURNED V */
        case 0x0292: wc = 0x01b7; break; /* LATIN SMALL LETTER EZH */
        case 0x029d: wc = 0xa7b2; break; /* LATIN SMALL LETTER J WITH CROSSED-TAIL */
        case 0x029e: wc = 0xa7b0; break; /* LATIN SMALL LETTER TURNED K */
        case 0x0345: wc = 0x0399; break; /* COMBINING GREEK YPOGEGRAMMENI */
        case 0x037b: wc = 0x03fd; break; /* GREEK SMALL REVERSED LUNATE SIGMA SYMBOL */
        case 0x037c: wc = 0x03fe; break; /* GREEK SMALL DOTTED LUNATE SIGMA SYMBOL */
        case 0x037d: wc = 0x03ff; break; /* GREEK SMALL REVERSED DOTTED LUNATE SIGMA SYMBOL */
        case 0x03ac: wc = 0x0386; break; /* GREEK SMALL LETTER ALPHA WITH TONOS */
        case 0x03ad: wc = 0x0388; break; /* GREEK SMALL LETTER EPSILON WITH TONOS */
        case 0x03ae: wc = 0x0389; break; /* GREEK SMALL LETTER ETA WITH TONOS */
        case 0x03af: wc = 0x038a; break; /* GREEK SMALL LETTER IOTA WITH TONOS */
        case 0x03c2: wc = 0x03a3; break; /* GREEK SMALL LETTER FINAL SIGMA */
        case 0x03cd: wc = 0x038e; break; /* GREEK SMALL LETTER UPSILON WITH TONOS */
        case 0x03ce: wc = 0x038f; break; /* GREEK SMALL LETTER OMEGA WITH TONOS */
        case 0x03d0: wc = 0x0392; break; /* GREEK BETA SYMBOL */
        case 0x03d1: wc = 0x0398; break; /* GREEK THETA SYMBOL */
        case 0x03d5: wc = 0x03a6; break; /* GREEK PHI SYMBOL */
        case 0x03d6: wc = 0x03a0; break; /* GREEK PI SYMBOL */
        case 0x03f0: wc = 0x039a; break; /* GREEK KAPPA SYMBOL */
        case 0x03f2: wc = 0x03f9; break; /* GREEK LUNATE SIGMA SYMBOL */
        case 0x03f3: wc = 0x037f; break; /* GREEK LETTER YOT */
        case 0x03f5: wc = 0x0395; break; /* GREEK LUNATE EPSILON SYMBOL */
        case 0x04cf: wc = 0x04c0; break; /* CYRILLIC SMALL LETTER PALOCHKA */
        case 0x1c80: wc = 0x0412; break; /* CYRILLIC SMALL LETTER ROUNDED VE */
        case 0x1c81: wc = 0x0414; break; /* CYRILLIC SMALL LETTER LONG-LEGGED DE */
        case 0x1c82: wc = 0x041e; break; /* CYRILLIC SMALL LETTER NARROW O */
        case 0x1c83: wc = 0x0421; break; /* CYRILLIC SMALL LETTER WIDE ES */
        case 0x1c84: wc = 0x0422; break; /* CYRILLIC SMALL LETTER TALL TE */
        case 0x1c85: wc = 0x0422; break; /* CYRILLIC SMALL LETTER THREE-LEGGED TE */
        case 0x1c86: wc = 0x042a; break; /* CYRILLIC SMALL LETTER TALL HARD SIGN */
        case 0x1c87: wc = 0x0462; break; /* CYRILLIC SMALL LETTER TALL YAT */
        case 0x1c88: wc = 0xa64a; break; /* CYRILLIC SMALL LETTER UNBLENDED UK */
        case 0x1d79: wc = 0xa77d; break; /* LATIN SMALL LETTER INSULAR G */
        case 0x1d7d: wc = 0x2c63; break; /* LATIN SMALL LETTER P WITH STROKE */
        case 0x1d8e: wc = 0xa7c6; break; /* LATIN SMALL LETTER Z WITH PALATAL HOOK */
        case 0x1e9b: wc = 0x1e60; break; /* LATIN SMALL LETTER LONG S WITH DOT ABOVE */
        case 0x1f70: wc = 0x1fba; break; /* GREEK SMALL LETTER ALPHA WITH VARIA */
        case 0x1f71: wc = 0x1fbb; break; /* GREEK SMALL LETTER ALPHA WITH OXIA */
        case 0x1f72: wc = 0x1fc8; break; /* GREEK SMALL LETTER EPSILON WITH VARIA */
        case 0x1f73: wc = 0x1fc9; break; /* GREEK SMALL LETTER EPSILON WITH OXIA */
        case 0x1f74: wc = 0x1fca; break; /* GREEK SMALL LETTER ETA WITH VARIA */
        case 0x1f75: wc = 0x1fcb; break; /* GREEK SMALL LETTER ETA WITH OXIA */
        case 0x1f76: wc = 0x1fda; break; /* GREEK SMALL LETTER IOTA WITH VARIA */
        case 0x1f77: wc = 0x1fdb; break; /* GREEK SMALL LETTER IOTA WITH OXIA */
        case 0x1f78: wc = 0x1ff8; break; /* GREEK SMALL LETTER OMICRON WITH VARIA */
        case 0x1f79: wc = 0x1ff9; break; /* GREEK SMALL LETTER OMICRON WITH OXIA */
        case 0x1f7a: wc = 0x1fea; break; /* GREEK SMALL LETTER UPSILON WITH VARIA */
        case 0x1f7b: wc = 0x1feb; break; /* GREEK SMALL LETTER UPSILON WITH OXIA */
        case 0x1f7c: wc = 0x1ffa; break; /* GREEK SMALL LETTER OMEGA WITH VARIA */
        case 0x1f7d: wc = 0x1ffb; break; /* GREEK SMALL LETTER OMEGA WITH OXIA */
        case 0x1fb3: wc = 0x1fbc; break; /* GREEK SMALL LETTER ALPHA WITH YPOGEGRAMMENI */
        case 0x1fbe: wc = 0x0399; break; /* GREEK PROSGEGRAMMENI */
        case 0x1fc3: wc = 0x1fcc; break; /* GREEK SMALL LETTER ETA WITH YPOGEGRAMMENI */
        case 0x1fe5: wc = 0x1fec; break; /* GREEK SMALL LETTER RHO WITH DASIA */
        case 0x1ff3: wc = 0x1ffc; break; /* GREEK SMALL LETTER OMEGA WITH YPOGEGRAMMENI */
        case 0x214e: wc = 0x2132; break; /* TURNED SMALL F */
        case 0x2c65: wc = 0x023a; break; /* LATIN SMALL LETTER A WITH STROKE */
        case 0x2c66: wc = 0x023e; break; /* LATIN SMALL LETTER T WITH DIAGONAL STROKE */
        case 0xa794: wc = 0xa7c4; break; /* LATIN SMALL LETTER C WITH PALATAL HOOK */
        case 0xab53: wc = 0xa7b3; break; /* LATIN SMALL LETTER CHI */
        }
    }

    return wc;
}