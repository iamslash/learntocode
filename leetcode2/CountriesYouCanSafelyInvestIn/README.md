# Problem

[Countries You Can Safely Invest In](https://leetcode.com/problems/countries-you-can-safely-invest-in/)

국가의 평균통화 시간이 글로벌 평균통화 시간보다 크면 그 국가의 목록을
리턴하라.

# Idea

triple join

# Implementation

```sql
-- 1128ms 65.51% 0B 100.00%
SELECT Country.name AS country
  FROM Country 
  JOIN Person ON LEFT(Person.phone_number, 3) = Country.country_code
  JOIN Calls ON Person.id = Calls.caller_id OR Person.id = Calls.callee_id
GROUP BY Country.name
HAVING AVG(Calls.duration) > (SELECT AVG(duration) FROM Calls);
```
