---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import re\nimport sys\nimport glob\nfor name in glob.glob(sys.argv[-1] +\
    \ '/*'):\n  res = ''\n  with open(name) as f:\n    s = f.read()\n    t = re.split('\
    \ |\\n|\\t|!|\\\"|#|%|&|\\'|\\(|\\)|\\-|=|\\^|~|\\||\\\\|{|}|;|\\+|:|\\*|\\[|\\\
    ]|,|<|\\.|>|\\/|\\?', s)\n    for i in t:\n      idx = s.find(i)\n      res +=\
    \ s[:idx]\n      s = s[idx + len(i):]\n      if i.startswith('_type'):\n     \
    \   res += i[5:]\n      elif i.startswith('_') and not i.startswith('__') and\
    \ (len(i) == 1 or not i[1].isupper()):\n        res += i[1:]\n      else:\n  \
    \      res += i\n    res += s\n  with open(name, 'w') as f:\n    f.write(res)"
  dependsOn: []
  isVerificationFile: false
  path: formatter.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: formatter.py
layout: document
redirect_from:
- /library/formatter.py
- /library/formatter.py.html
title: formatter.py
---
