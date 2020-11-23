
-- 3231ms 23.45%
SELECT id, Company, Salary
FROM Employee e
WHERE 1 >= ABS((SELECT COUNT(*)
                FROM Employee e1
                WHERE e.Company = e1.Company AND
                      e.Salary >= e1.Salary) -
               (SELECT COUNT(*)
                FROM Employee e2
                WHERE e.Company = e2.Company AND
                      e.Salary <= e2.Salary))
GROUP BY Company, Salary
