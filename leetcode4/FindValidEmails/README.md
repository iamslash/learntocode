# Problem

[Find Valid Emails](https://leetcode.com/problems/find-valid-emails/description/)

# Implementation

```sql
-- 576ms 100.00%
SELECT user_id,
       email
  FROM users
 WHERE email REGEXP '[a-zA-Z0-9_]+@[a-zA-Z0-9_]+\.com$'
 ORDER BY user_id
```
