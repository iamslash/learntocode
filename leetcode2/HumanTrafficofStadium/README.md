# Problem

[Human Traffic of Stadium](https://leetcode.com/problems/human-traffic-of-stadium/)

하루에 100 명 이상 방문한 날이 3 일 이상 연속으로 지속되었을 때를
구하라.

# Idea

```
stadium table

+------+------------+-----------+
| id   | visit_date | people    |
+------+------------+-----------+
| 1    | 2017-01-01 | 10        |
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 99        |
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-08 | 188       |
+------+------------+-----------+

+------+------------+-----------+
| id   | visit_date | people    |
+------+------------+-----------+
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-08 | 188       |
+------+------------+-----------+
```

# Implementation

```
-- 293ms 98.77% 0B 100.00%
SELECT s1.* 
FROM stadium AS s1, stadium AS s2, stadium AS s3
WHERE ((s1.id + 1 = s2.id AND s1.id + 2 = s3.id)
       OR
       (s1.id - 1 = s2.id AND s1.id + 1 = s3.id)
       OR
       (s1.id - 2 = s2.id AND s1.id - 1 = s3.id))
       AND
       s1.people >= 100
       AND
       s2.people >= 100
       AND
       s3.people >= 100
GROUP BY s1.id
ORDER BY s1.id    
```
