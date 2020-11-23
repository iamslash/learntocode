# 164ms 69.40%
SELECT E.name, B.bonus
  FROM Employee E LEFT OUTER JOIN Bonus B
    ON E.empId = B.empId
  WHERE B.bonus IS NULL OR B.bonus < 1000;
