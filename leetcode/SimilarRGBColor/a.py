# -*- coding: utf-8 -*-

# 56ms 13.33% 13.2MB 8.33%
class Solution:
    def similarRGB(self, color: str) -> str:
        def getClosest(s):
            return min(['00', '11', '22', '33', '44',
                        '55', '66', '77', '88', '99',
                        'aa', 'bb', 'cc', 'dd', 'ee', 'ff'],
                       key=lambda x: abs(int(s, 16) - int(x, 16)))
        ans = [getClosest(color[i:i+2]) for i in range(1, len(color), 2)]
        return '#' + ''.join(ans)
    
if __name__ == "__main__":
    color = "#09f166"
    sln = Solution()
    print(sln.similarRGB(color))
