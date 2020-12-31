# Problem

[Number of Calls Between Two Persons](https://leetcode.com/problems/number-of-calls-between-two-persons/)

# Implementation

```
-- 692ms 17.04% 0B 100.00%
-- subquery
SELECT from_id person1,
       to_id person2,
       COUNT(duration) call_count,
       SUM(duration) total_duration
  FROM (SELECT * 
          FROM Calls
        UNION  ALL 
        SELECT to_id, 
               from_id,
               duration
          FROM Calls) t
  WHERE from_id < to_id
  GROUP BY from_id, to_id;
```

```
-- 675ms 19.55% 0B 100.00%
-- LEAST, GREATEST
  SELECT LEAST(from_id, to_id) AS person1,
         GREATEST(from_id, to_id) AS person2,
         COUNT(*) AS call_count,
         SUM(duration) AS total_duration
    FROM Calls
GROUP BY person1, person2;
```

```
-- 607ms 30.33% 0B 100.00%
-- CASE WHEN THEN ELSE END
  SELECT (CASE 
            WHEN from_id < to_id 
              THEN from_id 
            ELSE to_id
          END) AS person1,
         (CASE
            WHEN from_id < to_id 
              THEN to_id
            ELSE from_id
          END) AS person2,
         COUNT(duration) AS call_count,
         SUM(duration) AS total_duration
    FROM Calls
GROUP BY person1, person2;  
```
