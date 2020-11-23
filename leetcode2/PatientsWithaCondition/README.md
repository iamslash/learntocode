# Problem

[Patients With a Condition](https://leetcode.com/problems/patients-with-a-condition/)

# Idea

```
Patients
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 1          | Daniel       | YFEV COUGH   |
| 2          | Alice        |              |
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 |
| 5          | Alain        | DIAB201      |
+------------+--------------+--------------+

Result table:
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 | 
+------------+--------------+--------------+
Bob and George both have a condition that starts with DIAB1.
```

# Implementation

```
-- 323ms 100.00% 0B 100.00%
SELECT * 
FROM Patients
WHERE conditions LIKE '%DIAB1%'
```
