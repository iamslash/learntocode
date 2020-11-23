# Write your MySQL query statement below

# 406ms 41.96%
SELECT a.Name FROM Employee a 
  JOIN Employee b 
  ON a.Id = b.ManagerId
GROUP BY a.Name HAVING COUNT(a.Name) >= 5;

# 200ms 78.66%
SELECT Name from Employee WHERE id in
  (SELECT ManagerId FROM Employee
     GROUP BY ManagerId
     HAVING COUNT(ManagerId) >= 5);
