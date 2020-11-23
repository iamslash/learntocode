-- 149ms 66.05%
UPDATE
  salary
SET
  sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex))
;  
  
