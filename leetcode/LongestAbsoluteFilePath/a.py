# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

#         
#   input: dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext
#                                                i
#          dir  \tsubdir1  \tsubdir2  \t\tfile.ext
#
#    name: dir    subdir1    subdir2      file.ext
#     lvl:   0          1          1             2
#
#  maxlen: 20
# pathlen: 0 1 2 
#          0 4 12

# 28ms 80.68% 14.3MB 38.45%
# hash map
# O(N) O(N)
class Solution:
    def lengthLongestPath(self, input: str) -> int:
        maxlen = 0
        # {lvl: len}
        pathlen = {0: 0}
        for line in input.splitlines():
            name = line.lstrip('\t')
            lvl  = len(line) - len(name)
            if '.' in name:
                maxlen = max(maxlen, pathlen[lvl] + len(name))
            else:
                pathlen[lvl+1] = pathlen[lvl] + len(name) + 1
        return maxlen
        
if __name__ == "__main__":
    sln = Solution()
    # 20
    print(sln.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"))
    # 32
    print(sln.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"))
    # 0
    print(sln.lengthLongestPath("a"))
    # 12
    print(sln.lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt"))
