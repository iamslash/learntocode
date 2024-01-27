# Problem

[Find Peak Calling Hours for Each City](https://leetcode.com/problems/find-peak-calling-hours-for-each-city/)

# Implementation

```sql
-- 794ms 99.08% 0B 100.00%
SELECT city, 
       peak_calling_hour,
       number_of_calls
  FROM () a
 WHERE a.rnk = 1
 ORDER BY peak_calling_hour DESC,
          city DESC
          
SELECT city, 
       peak_calling_hour,
       number_of_calls
  FROM (SELECT city,
               hour(call_time) peak_calling_hour,
               count(caller_id) number_of_calls,
               rank() over(partition by city order by count(caller_id) DESC) rnk
          FROM Calls
      GROUP BY city,
               hour(call_time)) a
 WHERE a.rnk = 1
 ORDER BY peak_calling_hour DESC,
          city DESC
```
