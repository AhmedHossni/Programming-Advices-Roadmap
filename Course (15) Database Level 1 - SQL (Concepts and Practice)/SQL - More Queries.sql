-- EXISTS

/*
EXISTS Practice Questions for HR Database

1️⃣ Employees in a specific department

List all employees who belong to the “IT” department.
Use EXISTS to check the department.

2️⃣ Employees with high bonus

List all employees who have a BonusPerc greater than 20%.
Use EXISTS to filter employees.

3️⃣ Employees working in certain countries

List all employees who work in countries whose name starts with “U”.
Use EXISTS to check the country.

4️⃣ Departments with female employees

List all departments that have at least one female employee.
Use EXISTS to check for employees in each department.

5️⃣ Currently employed employees

List all employees who are still employed (ExitDate IS NULL).
Use EXISTS to filter employees.
*/

SELECT * FROM Employees E
WHERE EXISTS
(
	SELECT * FROM Departments D WHERE E.DepartmentID = D.ID AND D.Name = 'IT'
);

SELECT * FROM Employees E
WHERE EXISTS
(
	SELECT MAX(EN.BonusPerc) FROM Employees EN HAVING MAX(EN.BonusPerc) = E.BonusPerc
);

SELECT * FROM Employees E
WHERE EXISTS
(
	SELECT * FROM Countries C WHERE C.Name LIKE 'U%' AND E.CountryID = C.ID
);

SELECT * FROM Departments D
WHERE EXISTS
(
	SELECT * FROM Employees E WHERE E.Gendor = 'F' AND DepartmentID = D.ID
);

SELECT * FROM Employees E
WHERE EXISTS
(
	SELECT * FROM Employees EN WHERE EN.ExitDate IS NULL AND E.ID = EN.ID
);

-- UNION
SELECT * FROM ActiveEmployees
UNION ALL
SELECT * FROM Employees WHERE ExitDate IS NOT NULL

-- UNION vs UNION ALL
SELECT * FROM Departments
UNION
SELECT * FROM Departments;

SELECT * FROM Departments
UNION ALL
SELECT * FROM Departments;

-- CASE
-----------------------------------------------------
/*
5 Questions To Practise on HR Database : 

🟢 Question 1 – Salary Category
Classify employees based on their salary.
Rules:
< 1000 → Low
1000–2000 → Medium
> 2000 → High

Expected columns:
ID
FirstName
MonthlySalary
SalaryCategory

🔵 Question 2 – Age Group
Categorize employees based on age (use DateOfBirth).
Rules:
< 25 → Young
25–40 → Adult
40 → Senior

Expected columns:
ID
FirstName
DateOfBirth
AgeGroup

🟡 Question 3 – Employee Status (Improved)
Determine employee status more clearly.
Rules:
ExitDate IS NULL → Active
ExitDate IS NOT NULL → Inactive
Expected columns:
ID
FirstName
ExitDate
Status

🔴 Question 4 – Bonus Level
Categorize employees based on BonusPerc.
Rules:
NULL → No Bonus
< 10 → Low Bonus
10–20 → Medium Bonus
20 → High Bonus

Expected columns:
ID
FirstName
BonusPerc
BonusLevel

🟣 Question 5 – Country + Department Label
Create a custom label combining logic from Countries and Departments.
Rules:
If Country is "USA" → 'Local Employee'
If Country is not "USA" → 'Foreign Employee'
If Department name contains "IT" → 'Tech'
Otherwise → 'Non-Tech'
Expected columns:
ID
FirstName
CountryName
DepartmentName
EmployeeType
DepartmentType
*/
-----------------------------------------------------
SELECT ID, FirstName, LastName, MonthlySalary, SalaryCategory =
CASE
	WHEN MonthlySalary < 1000 THEN 'LOW'
	WHEN MonthlySalary BETWEEN 1000 AND 2000 THEN 'MEDIUM'
	WHEN MonthlySalary > 2000 THEN 'HIGH'
END
FROM Employees
ORDER BY MonthlySalary

SELECT ID, FirstName, LastName, DateOfBirth, YEAR(GETDATE()) - YEAR(DateOfBirth) AS Age , AgeGroup =
CASE
	WHEN YEAR(GETDATE()) - YEAR(DateOfBirth) < 25 THEN 'Young'
	WHEN YEAR(GETDATE()) - YEAR(DateOfBirth) BETWEEN 25 AND 40 THEN 'Adult'
	WHEN YEAR(GETDATE()) - YEAR(DateOfBirth) > 40 THEN 'Senior'
END
FROM Employees
-----------------------------------------------------
SELECT ID, FirstName, LastName, DateOfBirth, ExitDate, Status =
CASE
	WHEN ExitDate IS NULL THEN 'ACTIVE'
	WHEN ExitDate IS NOT NULL THEN 'IN_ACTIVE'
END
FROM Employees
-----------------------------------------------------
SELECT ID, FirstName, LastName, CAST((BonusPerc * 100) AS CHAR(2)) AS 'BonusPerc (%)', BonusLevel =
CASE
	WHEN BonusPerc IS NULL THEN 'No Bonus'
	WHEN BonusPerc * 100 < 10 THEN 'Low Bonus'
	WHEN BonusPerc * 100 BETWEEN 10 AND 20 THEN 'Medium Bonus'
	WHEN BonusPerc * 100 > 20 THEN 'High Bonus'
END
FROM Employees
-----------------------------------------------------
SELECT E.ID, FirstName, C.Name, D.Name, EmployeeType =
CASE
	WHEN C.Name = 'USA' THEN 'Local Employee'
	WHEN NOT (C.Name = 'USA') THEN 'Foreign Employee'
END,
DepartmentType =
CASE
	WHEN D.Name = 'IT' THEN 'Tech'
	WHEN NOT (D.Name = 'IT') THEN 'Non-Tech'
END
FROM Employees E
JOIN Countries C ON E.CountryID = C.ID
JOIN Departments D ON E.DepartmentID = D.ID
ORDER BY DepartmentType;