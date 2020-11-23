
-- Events.event_type 의 Events.occurences 가
-- Events.occurences 별 Events.occurences 의 평균보다 커야 한다.
-- 그러한 record 들 중 Events.business_id 의 개수가 1 이상이어야 한다.
-- Events.occurences 별 Events.occurences 의 평균이 필요하다.
SELECT business_id
FROM Events as E1
...
GROUP BY business_id
HAVING COUNT(business_id) > 1


-- Events.occurences 별 Events.occurences 의 평균 테이블과
-- RIGHT JOIN 한다.
FROM Events as E1
  RIGHT JOIN (
    SELECT event_type, AVG(occurences) as avgevt
    FROM Events
    GROUP BY event_type
  ) E2
  ON E1.event_type = E2.event_type AND
     E1.occurences > E2.avgevt

-- 629ms 76.29%
SELECT business_id
FROM Events as E1
  RIGHT JOIN (
    SELECT event_type, AVG(occurences) as avgevt
    FROM Events
    GROUP BY event_type
  ) E2
  ON E1.event_type = E2.event_type AND
     E1.occurences > E2.avgevt
GROUP BY business_id
HAVING COUNT(business_id) > 1  
