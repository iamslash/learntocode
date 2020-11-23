# Problem

[Customer Who Visited but Did Not Make Any Transactions](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/)

# Implementation

```sql
-- 1200ms 100.00% 0B 100.00%
SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN 
  (SELECT DISTINCT visit_id FROM Transactions)
GROUP BY customer_id;
```
