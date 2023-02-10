#pragma once
#include <cstddef>
#include <string>
#include <vector>

template<>
struct std::vector<bool>: std::basic_string<bool> {
    using std::basic_string<bool>::basic_string, std::basic_string<bool>::operator =;
    explicit vector(std::size_t n): vector(n, false) {}
};
