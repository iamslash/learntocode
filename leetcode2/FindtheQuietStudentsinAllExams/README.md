# Problem

[Find the Quiet Students in All Exams](https://leetcode.com/problems/find-the-quiet-students-in-all-exams/)

# Idea

```
SQL Schema

Table: Student

+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| student_id          | int     |
| student_name        | varchar |
+---------------------+---------+
student_id is the primary key for this table.
student_name is the name of the student.

Table: Exam

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| exam_id       | int     |
| student_id    | int     |
| score         | int     |
+---------------+---------+
(exam_id, student_id) is the primary key for this table.
Student with student_id got score points in exam with id exam_id.
```

```
Student table:
+-------------+---------------+
| student_id  | student_name  |
+-------------+---------------+
| 1           | Daniel        |
| 2           | Jade          |
| 3           | Stella        |
| 4           | Jonathan      |
| 5           | Will          |
+-------------+---------------+

Exam table:
+------------+--------------+-----------+
| exam_id    | student_id   | score     |
+------------+--------------+-----------+
| 10         |     1        |    70     |
| 10         |     2        |    80     |
| 10         |     3        |    90     |
| 20         |     1        |    80     |
| 30         |     1        |    70     |
| 30         |     3        |    80     |
| 30         |     4        |    90     |
| 40         |     1        |    60     |
| 40         |     2        |    70     |
| 40         |     4        |    80     |
+------------+--------------+-----------+

Result table:
+-------------+---------------+
| student_id  | student_name  |
+-------------+---------------+
| 2           | Jade          |
+-------------+---------------+

For exam 1: Student 1 and 3 hold the lowest and high score respectively.
For exam 2: Student 1 hold both highest and lowest score.
For exam 3 and 4: Studnet 1 and 4 hold the lowest and high score respectively.
Student 2 and 5 have never got the highest or lowest in any of the exam.
Since student 5 is not taking any exam, he is excluded from the result.
So, we only return the information of Student 2.
```

# Implementation

```sql
SELECT DISTINCT e.student_id, s.student_name
FROM Exam e
JOIN Student s
ON e.student_id = s.student_id
WHERE e.student_id NOT IN ()
ORDER BY 1
```

```sql
SELECT DISTINCT e.student_id, s.student_name
FROM Exam e
JOIN Student s
ON e.student_id = s.student_id
WHERE e.student_id NOT IN (
  SELECT DISTINCT student_id
  FROM Exam
  WHERE (exam_id, score) IN ()
  OR (exam_id, score) IN ()
)
ORDER BY 1
```

```sql
-- 552ms 40.52% 0B 100.00%
SELECT DISTINCT e.student_id, s.student_name
FROM Exam e
JOIN Student s
ON e.student_id = s.student_id
WHERE e.student_id NOT IN (
  SELECT DISTINCT student_id
  FROM Exam
  WHERE (exam_id, score) IN (
    SELECT exam_id, MAX(score) 
    FROM Exam
    GROUP BY exam_id
  )
  OR (exam_id, score) IN (
    SELECT exam_id, MIN(score)
    FROM Exam
    GROUP BY exam_id
  )
)
ORDER BY 1
```
