# Problem

[Invalid Tweets](https://leetcode.com/problems/invalid-tweets/)

# Implementation

```sql
-- 497ms 100.00% 0B 100.00%
SELECT tweet_id 
  FROM Tweets
 WHERE CHAR_LENGTH(content) > 15;
```
