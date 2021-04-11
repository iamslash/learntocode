# Problem

> [ind Customers With Positive Revenue this Year](https://leetcode.com/problems/find-customers-with-positive-revenue-this-year/)

# Implementation

```sql
--513ms 100.00% 0B 100.00%
  SELECT customer_id 
    FROM Customers
   WHERE year = '2021'
   GROUP BY customer_id  
  HAVING SUM(revenue) > 0
```
