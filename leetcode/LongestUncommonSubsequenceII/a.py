# -*- coding: utf-8 -*-

# 60ms 72.41%
# O(SN^2) O(1)
class Solution:
    # a is in b
    def isIn(self, a, b):
        i = 0
        j = 0        
        while i < len(a) and j < len(b):
            # print("%d %d %s %s"%(i,j,a,b))
            if (a[i] == b[j]):
                i += 1
            j += 1
            if (i == len(a)):
                return True
        return False
    
    def findLUSlength(self, l_strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        l_strs.sort(key = len, reverse = True)
        for i, a in enumerate(l_strs):
            if all(not self.isIn(a, b) for j, b in enumerate(l_strs) if i != j):
                return len(a)
        return -1
        

def main():
    sln = Solution()
    print(sln.findLUSlength(["aba", "cdc", "eae"]))

if __name__ == "__main__":
    main()
