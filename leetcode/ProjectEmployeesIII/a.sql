
-- experience_years 가 project_id 별 최대 experience_years 와 같아야 한다.
-- project_id, MAX(experience_years) 가 필요하다.
SELECT P.project_id, E.employee_id
FROM Project as P
  INNER JOIN Employee as E
  ON P.employee_id = E.employee_id
  WHERE (P.project_id, E.experience_years)
    IN (
       ...
       )

-- 다음은 project_id 별 최대 experience_years 이다.
      SELECT P.project_id, MAX(E.experience_years)
      FROM Project AS P
        INNER JOIN Employee AS E
        ON P.employee_id = E.employee_id
        GROUP BY P.project_id

-- 302ms 76.50%
SELECT P.project_id, E.employee_id
FROM Project as P
  INNER JOIN Employee as E
  ON P.employee_id = E.employee_id
  WHERE (P.project_id, E.experience_years)
    IN (
      SELECT P.project_id, MAX(E.experience_years)
      FROM Project AS P
        INNER JOIN Employee AS E
        ON P.employee_id = E.employee_id
        GROUP BY P.project_id
    )
