# Problem

[Find All Unique Email Domains](https://leetcode.com/problems/find-all-unique-email-domains/)

# Implementation

```sql
-- 462ms 100.00% 0B 100.00%
WITH cte AS(
  SELECT id,
         SUBSTRING_INDEX(email, '@', -1) AS domain
    FROM Emails
   WHERE email LIKE '%.com' 
)
SELECT domain AS email_domain,
       COUNT(*) AS count
  FROM cte
 GROUP BY domain
 ORDER BY domain ASC;
```
