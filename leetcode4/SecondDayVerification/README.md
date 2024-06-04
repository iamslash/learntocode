# Problem

[Second Day Verification](https://leetcode.com/problems/second-day-verification/)

# Implementation

```sql
-- 1129ms 100.00% 0B 100.00%
SELECT user_id
  FROM emails 
  JOIN texts 
    ON emails.email_id = texts.email_id
 WHERE signup_action = 'Verified' AND
       DATEDIFF(action_date, signup_date) = 1
 ORDER BY user_id     
```
