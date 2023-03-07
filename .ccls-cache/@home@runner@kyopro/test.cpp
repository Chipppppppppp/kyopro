#include "all.hpp"

void kpr::main() {
  auto x = $$(a, 1, b, 2);
  println(x);
  x = $$(a, 2, b, 3);
  println(x);
  x = {3, 4};
  println(x);
  println(get<0>(x), x.b);
}