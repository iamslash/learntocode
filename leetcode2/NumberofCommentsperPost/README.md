# Problem

[Number of Comments per Post](https://leetcode.com/problems/number-of-comments-per-post/)

# Idea

```
SQL Schema
Table: Submissions

+---------------+----------+
| Column Name   | Type     |
+---------------+----------+
| sub_id        | int      |
| parent_id     | int      |
+---------------+----------+
There is no primary key for this table, it may have duplicate rows.
Each row can be a post or comment on the post.
parent_id is null for posts.
parent_id for comments is sub_id for another post in the table.
```

```
Submissions table:
+---------+------------+
| sub_id  | parent_id  |
+---------+------------+
| 1       | Null       |
| 2       | Null       |
| 1       | Null       |
| 12      | Null       |
| 3       | 1          |
| 5       | 2          |
| 3       | 1          |
| 4       | 1          |
| 9       | 1          |
| 10      | 2          |
| 6       | 7          |
+---------+------------+

Result table:
+---------+--------------------+
| post_id | number_of_comments |
+---------+--------------------+
| 1       | 3                  |
| 2       | 2                  |
| 12      | 0                  |
+---------+--------------------+

The post with id 1 has three comments in the table with id 3, 4 and 9. The comment with id 3 is repeated in the table, we counted it only once.
The post with id 2 has two comments in the table with id 5 and 10.
The post with id 12 has no comments in the table.
The comment with id 6 is a comment on a deleted post with id 7 so we ignored it.
```

# Implementation

```sql
SELECT 
  sub_id AS post_id,
  () AS number_of_comments
FROM Submissions
WHERE parent_id = NULL
ORDER BY sub_id ASC
```

```sql
-- 3628ms 5.04% 0B 100%
SELECT 
  a.sub_id AS post_id,
  (SELECT COUNT(DISTINCT(b.sub_id))
   FROM Submissions b
   WHERE b.parent_id = a.sub_id) AS number_of_comments
FROM Submissions a
WHERE a.parent_id IS null
GROUP BY a.sub_id
ORDER BY a.sub_id ASC
```
    

