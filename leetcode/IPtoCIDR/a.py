# -*- coding: utf-8 -*-

# 40ms 82.28% 13.1MB 9.09%
class Solution(object):

    def ipToInt(self, ip):
        rslt = 0
        for x in ip.split('.'):
            rslt = (rslt<<8) + int(x)
        return rslt

    def intToIP(self, x):
        return ".".join(str((x>>i)&0xFF) for i in (24, 16, 8, 0))
    
    def ipToCIDR(self, ip, n):
        # start ip
        nip  = self.ipToInt(ip)
        rslt = []
        while n:
            mask = max(33 - (nip & -nip).bit_length(),
                       33 - n.bit_length())
            rslt.append(self.intToIP(nip) + '/' + str(mask))
            nip += 1 << (32 - mask)
            n -= 1 << (32 - mask)
            # print(f'{mask:6d} {bin(mask):20s} {nip:20d} {n:2d}')
        return rslt        

if __name__ == "__main__":
    ip   = "255.0.0.7"
    n    = 10
    sln  = Solution()
    rslt = sln.ipToCIDR(ip, n)
    print(*rslt)
    
