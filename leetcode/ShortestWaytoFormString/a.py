
# Hello 56ms 42.00% 14.1MB 40.57%
class Solution:
    def shortestWay(self, s: str, t: str) -> int:
        i, j, ans = 0, 0, 0            
        while j < len(t) and ans <= j:
            while i < len(s) and s[i] != t[j]:
                i += 1
            if i == len(s):
                i, ans = 0, ans+1
            else:
                i, j = i+1, j+1
        return ans + 1 if ans <= j else -1

# 28ms 98.83% 14.3MB 17.43%
class Solution:
    def shortestWay(self, s:str, t:str) -> int:
        i, j, ans = 0, 0, 1
        for j in range(len(t)):
            i = s.find(t[j], i)
            if i == -1:
                i = s.find(t[j])
                if i == -1:
                    return -1
                ans += 1
            i += 1
        return ans
