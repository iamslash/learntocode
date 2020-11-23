# -*- coding: utf-8 -*-

import re

# abcde
# 11000
# 01100
#     
# 11100 1 0 0 0 0
# 11000 1 1 0 0 0
# 01100 1 0 0 0 0
# 01000 1 1 0 0 0
class Solution:
    def minAbbreviation(self, tgt, dic):
        n = len(tgt)
        diffs = {sum(2**i for i, c in enumerate(word) if tgt[i] != c)
                 for word in dic if len(word) == n}
        # for d in diffs: print(f'{d} {bin(d)}')
        if not diffs:
            return str(n)
        # bits = 0b01100
        # print(bits >> i) & 3 == 0 for i in range(n-1)))
        bits = max((i for i in range(2**n) if all(d & i for d in diffs)),
                   key=lambda bits: sum((bits >> i) & 3 == 0 for i in range(n-1)))
        
        s = ''.join(tgt[i] if bits & 2**i else '#' for i in range(n))
        return re.sub('#+', lambda m: str(len(m.group())), s)
        
if __name__ == "__main__":
    sln = Solution()
    print(sln.minAbbreviation('abcde', ['xxcde','axxde']))
