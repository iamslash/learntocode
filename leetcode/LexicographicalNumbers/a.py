
# # Recursive way
# # 320ms 22.65%
# class Solution:
#     def __init__(self):
#         self.m_rslt = []
#         self.m_n = 0
        
#     def dfs(self):
#         last = self.m_rslt[-1] * 10

#         # base
#         if last > self.m_n:
#             return

#         # recursion
#         for i in range(last, last+10):
#             self.m_rslt.append(i)
#             if i >= self.m_n:
#                 break
#             self.dfs()
    
#     def lexicalOrder(self, n):
#         """
#         :type n: int
#         :rtype: List[int]
#         """
#         self.m_n = n
#         for i in range(1, 10):
#             self.m_rslt.append(i)
#             if i >= n:
#                 break
#             self.dfs()
#         return self.m_rslt

# iterative way
# 144ms 100.00%
class Solution:
    def lexicalOrder(self, n):
        a = list(range(1, n+1))
        a.sort(key=str)
        return a
        
if __name__ == '__main__':
    sln = Solution()
    print(sln.lexicalOrder(13))
