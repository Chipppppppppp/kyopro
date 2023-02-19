#pragma once

#define KYOPRO_MATCH1(_1) break; case _1:
#define KYOPRO_MATCH2(_1, _2) break; case _1: case _2:
#define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2: case _3:
#define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case _3: case _4:

#define KYOPRO_OVERLOAD_MATCH(_1, _2, _3, _4, name, ...) name
#define match(...) KYOPRO_OVERLOAD_MATCH(__VA_ARGS__, KYOPRO_MATCH4, KYOPRO_MATCH3, KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)
#define otherwise break; default:
