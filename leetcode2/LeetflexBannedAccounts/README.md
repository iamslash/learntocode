# Problem

[Leetflex Banned Accounts](https://leetcode.com/problems/leetflex-banned-accounts/)

# Implementation

```sql
-- 362ms 100.00% 0B 100.00%
SELECT DISTINCT a.account_id
  from LogInfo a
  join LogInfo b
    on a.account_id = b.account_id
   and a.ip_address != b.ip_address
 where a.login between (b.login) and (b.logout)  
```
