# Problem

[Number of Accounts That Did Not Stream](https://leetcode.com/problems/number-of-accounts-that-did-not-stream/)
# Implementation

```sql
-- 865ms 100.00% 0B 100.00%
SELECT COUNT(DISTINCT account_id) AS accounts_count
  FROM Subscriptions
 WHERE YEAR(end_date) = 2021 AND
       account_id NOT IN (
         SELECT s.account_id
           FROM Streams s
          WHERE YEAR(stream_date) = 2021
       )
```

```sql
-- 768ms 100.00% 0B 100.00%
   SELECT COUNT(DISTINCT s1.account_id) AS accounts_count
     FROM Subscriptions s1
LEFT JOIN Streams s2 
       ON s1.account_id = s2.account_id AND
          YEAR(s2.stream_date) = '2021'
    WHERE (YEAR(s1.start_date) = '2021' OR
          YEAR(s1.end_date) = '2021') AND
          s2.account_id IS NULL```
```
