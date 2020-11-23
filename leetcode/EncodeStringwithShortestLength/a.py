# -*- coding: utf-8 -*-

# 352ms 45.22% 14.6MB 33.33%
class Solution:
    def encode(self, s: str, C: dict={}) -> str:
        if s not in C:
            n    = len(s)
            i    = (s+s).find(s, 1)
            one  = '%d[%s]'%(n/i, self.encode(s[:i], C)) if i < n else s
            mlt  = [self.encode(s[:i], C) + self.encode(s[i:], C) for i in range(1, n)]
            C[s] = min([s, one] + mlt, key=len)
        return C[s]

if __name__ == "__main__":
    sln = Solution()
    print(sln.encode('aaaaaaaaaaaaa'))
