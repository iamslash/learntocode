# -*- coding: utf-8 -*-

# 60ms 16.51%
class Solution:
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        def isIPv4(s):
            try:
                return str(int(s)) == s and 0 <= int(s) <= 255
            except:
                pass
            return False
        def isIPv6(s):
            if len(s) > 4:
                return False
            try:
                return int(s, 16) >= 0 and s[0] != '-'
            except:
                pass
            return False
    
        if IP.count(".") == 3 and all(isIPv4(s) for s in IP.split(".")):
            return "IPv4"
        if IP.count(":") == 7 and all(isIPv6(s) for s in IP.split(":")):
            return "IPv6"
        return "Neither"
            
if __name__ == "__main__":
    sln = Solution()
    print(sln.validIPAddress("172.16.254.1"))
    print(sln.validIPAddress("2001:db8:85a3:0:0:8A2E:0370:7334"))
    print(sln.validIPAddress("2001::85a3:0:0:8A2E:0370:7334"))
