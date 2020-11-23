# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

#                 i
#    s:   ) ( ( ) )
# stck:-1 0  
#  ans: 0       2 4

# 40ms 87.05% 14.5MB 5.36%
# stack
# O(N) O(N)
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stck = [-1]
        ans, n = 0, len(s)
        for i in range(n):
            if stck[-1] != -1 and s[i] == ')' and s[stck[-1]] == '(':
                stck.pop()
                ans = max(ans, i - stck[-1])
            else:
                stck.append(i)
        return ans

#                 i
#    s:   ) ( ( ) )
#  ing: 0
#  cnt: 4
#  ans: 4 

# # 84ms 5.07% 14.2MB 5.36%
# # back and forth
# # O(N) O(1)
# class Solution:
#     def longestValidParentheses(self, s:str) -> int:
#         ans, ing, cnt, n = 0, 0, 0, len(s)
#         for i in range(n):
#             if s[i] == '(':
#                 ing, cnt = ing+1, cnt+1
#             else:
#                 if ing > 0:
#                     ing, cnt = ing-1, cnt+1
#                     if ing == 0:
#                         ans = max(ans, cnt)
#                 else:
#                     ing, cnt = 0, 0                    
#         ing, cnt = 0, 0
#         for i in range(n-1, -1, -1):
#             if s[i] == ')':
#                 ing, cnt = ing+1, cnt+1
#             else:
#                 if ing > 0:
#                     ing, cnt = ing-1, cnt+1
#                     if ing == 0:
#                         ans = max(ans, cnt)
#                 else:
#                     ing, cnt = 0, 0
#         return ans
		
if __name__ == "__main__":
    sln = Solution()
    print(sln.longestValidParentheses(''))
    print(sln.longestValidParentheses('(()'))
    print(sln.longestValidParentheses(')()())'))
    print(sln.longestValidParentheses(')())()()'))
