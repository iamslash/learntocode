SET @r1=0, @r2=0, @r3=0, @r4=0;
SELECT min(Doctor), min(Professor), min(Singer), min(Actor)
FROM(
  SELECT CASE
                WHEN Occupation='Doctor' THEN (@r1:=@r1+1)
                WHEN Occupation='Professor' THEN (@r2:=@r2+1)
                WHEN Occupation='Singer' THEN (@r3:=@r3+1)
                WHEN Occupation='Actor' THEN (@r4:=@r4+1)
         END AS RowNumber,
    CASE WHEN Occupation='Doctor' THEN Name END AS Doctor,
    CASE WHEN Occupation='Professor' THEN Name END AS Professor,
    CASE WHEN Occupation='Singer' THEN Name END AS Singer,
    CASE WHEN Occupation='Actor' THEN Name END AS Actor
  FROM OCCUPATIONS
  ORDER BY Name
) Temp
GROUP BY RowNumber;
