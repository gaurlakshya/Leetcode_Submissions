

Select MAX(salary) AS "SecondHighestSalary"
From Employee
WHERE Salary <(SELECT MAX(Salary) From Employee)