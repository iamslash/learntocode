
-- 362ms 81.61%
SELECT d.dept_name, COUNT(s.student_id) AS student_number
FROM student s RIGHT OUTER JOIN department d 
  ON s.dept_id = d.dept_id
GROUP BY d.dept_name
ORDER BY student_number DESC, d.dept_name
