# Problem

[The Users That Are Eligible for Discount](https://leetcode.com/problems/the-users-that-are-eligible-for-discount/)

# Implementation

```sql
-- 641ms 38.89% 0B 100.00%
CREATE PROCEDURE getUserIDs(startDate DATE, endDate DATE, minAmount INT)
BEGIN
	# Write your MySQL query statement below.
	SELECT DISTINCT(user_id)
      FROM Purchases
     WHERE time_stamp BETWEEN startDate AND endDate AND amount >= minAmount
  ORDER BY user_id;
END
```
