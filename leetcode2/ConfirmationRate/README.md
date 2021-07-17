# Problem

[Confirmation Rate](https://leetcode.com/problems/confirmation-rate/)

# Implementation

```sql
-- 994ms 100.00% 0B 100.00%
   SELECT a.user_id AS user_id,
          ROUND(COUNT(CASE WHEN b.action = 'confirmed' THEN 1 ELSE NULL END) /
           CAST(COUNT(*) AS float), 2) AS confirmation_rate
     FROM Signups a
LEFT JOIN Confirmations b
       ON a.user_id = b.user_id
 GROUP BY a.user_id;     
```
