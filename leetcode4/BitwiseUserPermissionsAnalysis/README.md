# Problem

[Bitwise User Permissions Analysis](https://leetcode.com/problems/bitwise-user-permissions-analysis/)

# Implementation

```sql
-- 367ms 14.42% 0B 100.00%
SELECT BIT_AND(permissions) AS common_perms,
       BIT_OR(permissions) AS any_perms
  FROM user_permissions     
```
