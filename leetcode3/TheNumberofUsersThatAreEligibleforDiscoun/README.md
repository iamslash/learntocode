# Problem

[The Number of Users That Are Eligible for Discount](https://leetcode.com/problems/the-number-of-users-that-are-eligible-for-discount/)

# Implementation

```sql
-- 638ms 50.00% 0B 100.00%
CREATE FUNCTION getUserIDs(startDate DATE, endDate DATE, minAmount INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT COUNT(DISTINCT user_id) 
        FROM Purchases 
       WHERE time_stamp >= startDate AND 
             time_stamp <= endDate AND 
             amount >= minAmount
  );
END

-- 575ms 65.38% 0B 100.00%
CREATE FUNCTION getUserIDs(startDate DATE, endDate DATE, minAmount INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT COUNT(DISTINCT user_id) 
        FROM Purchases 
       WHERE time_stamp BETWEEN startDate AND endDate AND
             amount >= minAmount
  );
END
```
