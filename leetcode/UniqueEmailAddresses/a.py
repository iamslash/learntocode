# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 48ms 83.81% 14.5MB 33.59%
# string, set
# O(N) O(N)
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        email_set = set()
        for email in emails:
            name, domain = email.split('@')
            local = name.split('+')[0].replace('.', '')
            email_set.add(local + '@' + domain)
        return len(email_set)
        
if __name__ == "__main__":
    sln = Solution()
    # 2
    print(sln.numUniqueEmails(["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]))
    
