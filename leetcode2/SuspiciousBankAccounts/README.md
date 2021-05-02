# Problem

> [Suspicious Bank Accounts](https://leetcode.com/problems/suspicious-bank-accounts/)

문제의 내용을 명확히 이해하는 것이 중요하다.  계정의 특정 달의 총
입금액을 `mon_income` 이라고 하자. `mon_income` 이 `max_income`
보다 큰 달이 연속으로 2 개 혹은 그 이상일때 그 계정을 구하는 것이다.

`mon_income` 은 그달의 총입금액이다. 연속된 달의 총 입금액이 아니다.

먼저 다음과 같은 `tmp` table 을 제작한다.

```
account_id |    date | mon_income | max_income
         3 | 2021-06 |     300100 |      21000
         3 | 2021-07 |      64900 |      21000
```

`tmp` 를 JOIN 하여 다음과 같은 table 을 제작한다.

- In 5-2021, the user had an income of 49300.
- In 7-2021, the user had an income of 56300.

```
 account_id |    date | mon_income | max_income | account_id |    date | mon_income | max_income
          3 | 2021-06 |     300100 |      21000 |          3 | 2021-06 |     300100 |      21000
*           |         |            |            |          3 | 2021-07 |      64900 |      21000
          3 | 2021-07 |      64900 |      21000 |          3 | 2021-06 |     300100 |      21000
            |         |            |            |          3 | 2021-07 |      64900 |      21000
          4 | 2021-05 |      49300 |      10400 |          4 | 2021-05 |      49300 |      10400
            |         |            |            |          4 | 2021-07 |      56300 |      10400
          4 | 2021-07 |      56300 |      10400 |          4 | 2021-05 |      49300 |      10400
            |         |            |            |          4 | 2021-07 |      56300 |      10400
```

# Implementation

```sql
-- 701ms 94.44% 0B 100.00%
WITH tmp AS (
   SELECT t.account_id,
          DATE_FORMAT(t.day, '%Y%m') AS date,
          SUM(t.amount) AS 'income',
          a.max_income
     FROM Transactions t
LEFT JOIN Accounts a
       ON a.account_id = t.account_id
    WHERE t.type='Creditor'
 GROUP BY t.account_id, 
          DATE_FORMAT(t.day, '%Y%m')
   HAVING SUM(t.amount) > a.max_income)
   
  SELECT t1.account_id
    FROM tmp t1, tmp t2
   WHERE t1.account_id = t2.account_id AND
         PERIOD_DIFF(t1.date, t2.date)=1
GROUP BY t1.account_id
ORDER BY t1.account_id   
```
