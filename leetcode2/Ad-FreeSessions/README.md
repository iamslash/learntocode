# Problem

> [Ad-Free Sessions](https://leetcode.com/problems/ad-free-sessions/)

# Implementation

```sql
-- 735ms 100.00% 0B 100.00%
   SELECT p.session_id AS session_id
     FROM Playback p
LEFT JOIN Ads a
       ON p.customer_id = a.customer_id AND
          a.timestamp BETWEEN p.start_time AND p.end_time
    WHERE a.customer_id IS NULL;
```
