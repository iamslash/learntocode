# Write your MySQL query statement below

# 자신의 Salary 보다 큰 Salary 가 3 개 미만인 레코드를 구한다.

SELECT e1.Name AS 'Employee', e1.Salary
FROM Employee e1
WHERE 3 >
(
    SELECT COUNT(DISTINCT e2.Salary)
    FROM Employee e2
    WHERE e2.Salary > e1.Salary
)
;

# Deparment.Id 별로 자신의 Salary 보다 큰 Salary 가
# 3 개 미만인 레코드를 구한다.
# 673ms 65.03%
SELECT dep.Name AS Department, emp.Name AS Employee, emp.Salary
FROM Department dep, Employee emp
WHERE emp.DepartmentId=dep.Id
  AND (Select COUNT(DISTINCT Salary)
         FROM Employee
         where DepartmentId=dep.Id
           AND Salary > emp.Salary) < 3;
