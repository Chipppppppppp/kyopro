#pragma once

#define pushf(...) emplace_front(__VA_ARGS__)
#define popf(...) pop_front(__VA_ARGS__)
#define pushb(...) emplace_back(__VA_ARGS__)
#define popb(...) pop_back(__VA_ARGS__)
#define push(...) emplace(__VA_ARGS__)
