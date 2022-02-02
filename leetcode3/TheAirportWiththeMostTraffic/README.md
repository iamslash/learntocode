# Problem

[The Airport With the Most Traffic](https://leetcode.com/problems/the-airport-with-the-most-traffic/)

# Implementation

```sql
      WITH count AS ()
    SELECT airport_id 
      FROM count
  GROUP BY airport_id
    HAVING SUM(flights_count) = (SELECT SUM(flights_count) 
                                   FROM count
                               GROUP BY airport_id
                               ORDER BY 1 DESC
                                  LIMIT 1)
```

```sql
-- 473ms 36.39% 0B 100.00%
      WITH count AS (SELECT departure_airport AS airport_id,
                            flights_count
                       FROM Flights
                  UNION ALL
                     SELECT arrival_airport AS airport_id,
                            flights_count
                       FROM Flights)
    SELECT airport_id 
      FROM count
  GROUP BY airport_id
    HAVING SUM(flights_count) = (SELECT SUM(flights_count) 
                                   FROM count
                               GROUP BY airport_id
                               ORDER BY 1 DESC
                                  LIMIT 1)
```

GROUP BY 횟수를 줄였다.

```sql
-- 340ms 96.77% 0B 100.00%
      WITH count AS (SELECT departure_airport AS airport_id,
                            flights_count
                       FROM Flights
                  UNION ALL
                     SELECT arrival_airport AS airport_id,
                            flights_count
                       FROM Flights),
           max_count AS (
               SELECT SUM(flights_count) as num,
                      airport_id
                 FROM count
             GROUP BY 2
             ORDER BY 1 DESC
           )
    SELECT airport_id 
      FROM max_count
     WHERE num = (SELECT num from max_count limit 1)
```
