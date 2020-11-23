SELECT CONCAT(Name, '(', SUBSTR(Occupation, 1, 1), ')') FROM OCCUPATIONS ORDER BY Name ASC;

SELECT CONCAT('There are total ', COUNT(Name), ' ', LOWER(Occupation), 's.')
FROM OCCUPATIONS 
GROUP BY Occupation
ORDER BY COUNT(Occupation) ASC, Name DESC;
