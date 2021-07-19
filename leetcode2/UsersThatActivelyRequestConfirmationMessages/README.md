# Problem

[Users That Actively Request Confirmation Messages](https://leetcode.com/problems/users-that-actively-request-confirmation-messages/)

# Idea

```
+---------+---------------------+-----------+
| user_id | time_stamp          | action    |
+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   |
| 3       | 2021-01-06 03:37:45 | timeout   |

After self join

+---------+---------------------+-----------+---------+---------------------+-----------+
| user_id | time_stamp          | action    | user_id | time_stamp          | action    |
+---------+---------------------+-----------+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   | 3       | 2021-01-06 03:30:46 | timeout   |
|         |                     | timeout   | 3       | 2021-01-06 03:37:45 | timeout   |
| 3       | 2021-01-06 03:37:45 | timeout   | 3       | 2021-01-06 03:30:46 | timeout   |
|         |                     | timeout   | 3       | 2021-01-06 03:37:45 | timeout   |

```

# Implementation

```sql
-- 576ms 100.00% 0B 100.00%
SELECT DISTINCT c1.user_id AS user_id
  FROM Confirmations c1
  JOIN Confirmations c2
    ON c1.user_id = c2.user_id AND
       TIMESTAMPDIFF(second, c1.time_stamp, c2.time_stamp) 
       BETWEEN 1 AND 86400
```
