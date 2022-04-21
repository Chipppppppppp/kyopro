import re
import sys
import glob
for name in glob.glob(sys.argv[-1] + '/*'):
  res = ''
  with open(name) as f:
    s = f.read()
    t = re.split(' |\n|\t|!|\"|#|%|&|\'|\(|\)|\-|=|\^|~|\||\\|{|}|;|\+|:|\*|\[|\]|,|<|\.|>|\/|\?', s)
    for i in t:
      idx = s.find(i)
      res += s[:idx]
      s = s[idx + len(i):]
      if i.startswith('_type'):
        res += i[5:]
      elif i.startswith('_') and not i.startswith('__') and (len(i) == 1 or not i[1].isupper()):
        res += i[1:]
      else:
        res += i
    res += s
  with open(name, 'w') as f:
    f.write(res)