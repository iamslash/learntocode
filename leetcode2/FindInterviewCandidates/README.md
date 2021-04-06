# Problem

> [Find Interview Candidates](https://leetcode.com/problems/find-interview-candidates/)

# Implementation

```sql
-- 1185ms 23.74% 0B 100.00%
WITH t0 AS (
   SELECT gold_medal AS user, contest_id
     FROM Contests
UNION ALL 
   SELECT silver_medal AS user, contest_id
     FROM Contests
UNION ALL
   SELECT bronze_medal AS user, contest_id
     FROM Contests
),   t1 AS (
   SELECT user, contest_id, row_number() 
          over(partition by user
                   order by contest_id) AS rn
     FROM t0                   
),   t2 AS (
   SELECT user as user_id
     FROM t1
 GROUP BY user, contest_id - rn
   HAVING COUNT(*) >= 3
UNION ALL  
   SELECT gold_medal AS user_id
     FROM Contests
 GROUP BY gold_medal
   HAVING COUNT(*) >= 3
) 
    SELECT DISTINCT u.name, u.mail
      FROM t2
INNER JOIN Users u
        ON t2.user_id = u.user_id;
```
