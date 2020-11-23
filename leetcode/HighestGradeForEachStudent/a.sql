-- 1112. Highest Grade For Each Student
-- https://leetcode.com/problems/highest-grade-for-each-student/

-- * Schema
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | student_id    | int     |
-- | course_id     | int     |
-- | grade         | int     |
-- +---------------+---------+
-- (student_id, course_id) is the primary key of this table.

-- * Example 1
--
-- Enrollments table:
-- +------------+-------------------+
-- | student_id | course_id | grade |
-- +------------+-----------+-------+
-- | 2          | 2         | 95    |
-- | 2          | 3         | 95    |
-- | 1          | 1         | 90    |
-- | 1          | 2         | 99    |
-- | 3          | 1         | 80    |
-- | 3          | 2         | 75    |
-- | 3          | 3         | 82    |
-- +------------+-----------+-------+

-- Result table:
-- +------------+-------------------+
-- | student_id | course_id | grade |
-- +------------+-----------+-------+
-- | 1          | 2         | 99    |
-- | 2          | 2         | 95    |
-- | 3          | 3         | 82    |
-- +------------+-----------+-------+

-- 학생들 중 최고 점수를 가진 학생의 student_id, course_id, grade 를
-- 출력하라. 이때 grade 점수가 같은 record 에 대해서는 course_id 가
-- 가장 적은 것을 선택한다.

-- 415ms 42.59%
SELECT student_id, MIN(course_id) as course_id, grade
FROM Enrollments
WHERE (student_id, grade) in
  (
     SELECT student_id, MAX(grade)
     FROM Enrollements
     GROUP BY student_id
  )
GROUP BY student_id
ORDER BY student_id;
