
SELECT DATE_FORMAT(pay_date, '%Y-%m'), AVG(amount)
FROM salary
GROUP BY DATE_FORMAT(pay_date, '%Y-%m')

SELECT department_id, AVG(amount) AS department_avg,
  DATE_FORMAT(pay_date, '%Y-%m') AS pay_month
FROM salary
JOIN employee ON salary.employee_id = employee.employee_id
GROUP BY department_id, pay_month

-- 186ms 67.16%
SELECT department_salary.pay_month, department_id,
  CASE
    WHEN department_avg > company_avg then 'higher'
    WHEN department_avg < company_avg then 'lower'
    ELSE 'same'
  END AS comparison
FROM (SELECT department_id, AVG(amount) AS department_avg,
        DATE_FORMAT(pay_date, '%Y-%m') AS pay_month
      FROM salary
      JOIN employee
        ON salary.employee_id = employee.employee_id
      GROUP BY department_id, pay_month) AS department_salary
JOIN (SELECT AVG(amount) AS company_avg,
        DATE_FORMAT(pay_date, '%Y-%m') AS pay_month
      FROM salary
      GROUP BY DATE_FORMAT(pay_date, '%Y-%m')) AS company_salary
ON department_salary.pay_month = company_salary.pay_month
  
