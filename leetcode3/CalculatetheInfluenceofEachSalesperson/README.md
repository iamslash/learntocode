# Problem

[Calculate the Influence of Each Salesperson](https://leetcode.com/problems/calculate-the-influence-of-each-salesperson/)

# Implementation

```
-- 1065ms 67.38% 0B 100.00%
   SELECT p.salesperson_id,
          p.name,
          IFNULL(SUM(price), 0) AS total
     FROM Salesperson p
LEFT JOIN Customer c
       ON p.salesperson_id = c.salesperson_id
LEFT JOIN Sales s
       ON c.customer_id = s.customer_id
 GROUP BY 1;       
```
