/*
Enter your query here.
*/

SELECT W.id, P.age, W.coins_needed, W.power
FROM Wands W INNER JOIN Wands_Property P
ON W.code = P.code AND P.is_evil = 0
WHERE W.coins_needed = 
(SELECT MIN(W1.coins_needed) 
    FROM Wands W1 
    INNER JOIN Wands_Property P1
    ON W1.code = P1.code
    WHERE W1.power = W.power
    AND P1.age = P.age)
ORDER BY W.power DESC, P.age DESC;

