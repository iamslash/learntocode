# Problem

[Find Candidates for Data Scientist Position](https://leetcode.com/problems/find-candidates-for-data-scientist-position/)

# Implementation

```sql
-- 536ms 100.00% 0B 100.00%
  SELECT candidate_id 
    FROM Candidates
   WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
   GROUP BY candidate_id         
  HAVING COUNT(skill) = 3
   ORDER BY candidate_id ASC;       
```
