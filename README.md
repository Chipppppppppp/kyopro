# 概要
C++の競技プログラミングライブラリです。

MIT License ですが、競技プログラミングのためにこのライブラリの一部をジャッジサーバなどに送信するとき、著作権表示および許諾表示を省略することができます。

# 特徴
- 簡潔に記述可能
- 汎用性が高い

この二つを達成すること目指した競プロライブラリです。ライブラリというよりはいわゆるテンプレートに近く、より安全で便利な競プロテンプレートとして使用することができます。

具体的には、

- `kpr::main` 内にコードを記述することによる `using namespace std;` との両立
- named tupleやlambdaなどの便利なマクロ
- 拡張性の高いioライブラリ

などを取り入れています。(以下コード例)

```cpp
#include "kyopro/all.hpp"

namespace kpr {
    void main() {
        // named tuple macro
        auto named_tuple = $$(a, 42, b, "Hello");
        println(named_tuple); // 42 Hello
    }
}
```

# 要件
[Language Test 202001](https://atcoder.jp/contests/language-test-202001)で更新されたバージョンであるgcc9.2.1以上であることと、posix準拠であることが前提です。

# Verify Status
[![Actions Status](https://github.com/Chipppppppppp/kyopro/workflows/verify/badge.svg)](https://github.com/Chipppppppppp/kyopro/actions)

# Link
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://Chipppppppppp.github.io/kyopro/)
