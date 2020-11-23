# https://leetcode.com/problems/duplicate-emails/
# Write your MySQL query statement below
SELECT distinct(p0.Email) FROM Person p0, Person p1 
WHERE p0.Id <> p1.Id 
AND p0.Email = p1.Email;
