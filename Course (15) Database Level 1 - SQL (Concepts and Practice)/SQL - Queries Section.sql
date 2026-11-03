EXEC sp_changedbowner 'sa';

Restore Database HR_Database 
from disk ='G:\Programming\Fundementals Of Programming\Mohamed Abu-hadhoud\All Courses\Fundamental Courses\(15) Database Level 1 - SQL (Concepts and Practice) (12.25h)\Databases\HR_Database.bak';

SELECT name, state_desc, create_date 
FROM sys.databases 
WHERE name = 'HR_DB';

-- Queries

SELECT * FROM Employees AS E
INNER JOIN Departments AS D
ON E.DepartmentID = D.ID;

SELECT * FROM Employees
WHERE ExitDate IS NOT NULL;

SELECT * FROM Departments
WHERE ID BETWEEN 3 AND 5;

-- IN OPERATOR
SELECT * FROM Departments
WHERE ID IN (1,2,3);

select Departments.Name from Departments where
ID in ( select DepartmentID from Employees where MonthlySalary <= 210 );

select Departments.Name from Departments where 
ID not in ( select DepartmentID from Employees where MonthlySalary <=210 );

-- ORDER BY
SELECT ID, FirstName,MonthlySalary FROM Employees
WHERE DepartmentID=1
ORDER BY MonthlySalary DESC;

SELECT * FROM Departments
ORDER BY ID DESC;

SELECT ID, FirstName,MonthlySalary FROM Employees
WHERE DepartmentID=1
ORDER BY FirstName ASC, MonthlySalary DESC;

-- TOP

-- This will show top 5 employees.
Select top 5 * from Employees;


-- This will show top 10% of the data.
select top 10 percent * from Employees;

-- this will show employees with the heighest 3 salaries.
select ID , FirstName, MonthlySalary from Employees where MonthlySalary In
(
	select  distinct  top 3 MonthlySalary from employees
	order by MonthlySalary Desc
)
Order By MonthlySalary Desc


-- this will show employees with the heighest 2 BonusPerc.
SELECT * FROM Employees
WHERE BonusPerc IN
(
	SELECT DISTINCT TOP 3 E.BonusPerc FROM Employees AS E ORDER BY BonusPerc DESC
)
ORDER BY BonusPerc DESC;

-- AS
SELECT E.ID, Name = E.FirstName +' '+  E.LastName, Age = DATEDIFF(YEAR, E.DateOfBirth, GETDATE()) 
FROM Employees AS E
ORDER BY Age ASC 

-- BETWEEN
SELECT * FROM Departments
WHERE ID BETWEEN 3 AND 5;

-- Count, Sum, Avg, Min, Max Functions

SELECT COUNT(*) AS NumberOfDepartments FROM Departments;
SELECT SUM(MonthlySalary) AS SUM_Salary FROM Employees;
SELECT AVG(MonthlySalary) AS AVG_Salary FROM Employees;
SELECT MAX(MonthlySalary) AS MAX_Salary FROM Employees;
SELECT MIN(MonthlySalary) AS MIN_Salary FROM Employees;

SELECT * FROM Employees GROUP BY ID HAVING MonthlySalary = MIN(MonthlySalary);

-- GROUP BY
/*
1 - اعرض عدد الموظفين في كل قسم
2 - اعرض مجموع الرواتب في كل قسم
3 - اعرض اقل راتب في كل قسم
4 - اعرض اكبر راتب في كل قسم
5 - اعرض اكبر او احدث تاريخ تعيين في كل قسم
6 - اعرض اصغر او اقدم تاريخ تعيين في كل قسم
7 - اعرض عدد الموظفين الذين تم تعيينهم في كل سنة
8 - اعرض عدد الموظفين و متوسط الرواتب لهم في كل قسم
9 - اعرض اقل راتب واكبر راتب في كل قسم
10 - اعرض عدد الموظفين في كل مدينة
11 - لكل قسم Bonusperc اعرض مجموع ال 
*/

SELECT DepartmentID, COUNT(*) AS NumberOfEmployees FROM Employees GROUP BY DepartmentID ORDER BY DepartmentID;
SELECT DepartmentID, SUM(MonthlySalary) AS SUM_OF_SALARIES FROM Employees GROUP BY DepartmentID ORDER BY DepartmentID;
SELECT DepartmentID, MIN(MonthlySalary) AS MIN_SALARY_IN_DEPT FROM Employees GROUP BY DepartmentID ORDER BY DepartmentID;
SELECT DepartmentID, MAX(MonthlySalary) AS MAX_SALARY_IN_DEPT FROM Employees GROUP BY DepartmentID ORDER BY DepartmentID;
SELECT DepartmentID, MIN(HireDate) AS MIN_HIREDATE_IN_DEPT FROM Employees GROUP BY DepartmentID ORDER BY DepartmentID;
SELECT DepartmentID, MAX(HireDate) AS MAX_HIREDATE_IN_DEPT FROM Employees GROUP BY DepartmentID ORDER BY DepartmentID;

SELECT YEAR(CONVERT(date,E.HireDate)) AS DATE , COUNT(ID) AS NUMBER_OF_EMPLOYEES_HIRE_IN_THIS_DATE
FROM Employees AS E
GROUP BY YEAR(CONVERT(date,E.HireDate))
ORDER BY DATE;

SELECT DepartmentID, COUNT(*) AS NumberOfEmployees, AVG(MonthlySalary) AS AVG_OF_SALARIES 
FROM Employees GROUP BY DepartmentID ORDER BY DepartmentID;

SELECT DepartmentID, MAX(MonthlySalary) AS MAX_SALARY, MIN(MonthlySalary) AS MIN_SALARY 
FROM Employees GROUP BY DepartmentID ORDER BY DepartmentID;

SELECT E.CountryID, COUNT(*) AS NumberOfEmployees 
FROM Employees AS E GROUP BY E.CountryID ORDER BY E.CountryID;


SELECT 
    DepartmentID, 
    CAST(SUM(BonusPerc) * 100 AS VARCHAR(50)) + '%' AS SUM_OF_BONUSES
FROM Employees 
GROUP BY DepartmentID 
ORDER BY DepartmentID;

-- HAVING

--Having is the where satement for group by
select DepartmentID, TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 
	   
	   from Employees
       Group By DepartmentID
	  having Count(MonthlySalary) > 100
-- Same solution without having :-)
select * from 
(

   select DepartmentID, TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 
	   
	   from Employees
	
       Group By DepartmentID
	  
) R1
where R1.TotalCount> 100;

/*
🏢 1️⃣ Departments with more than 140 employees

💰 2️⃣ Departments where total salaries exceed 20000

📅 3️⃣ Years in which more than 50 employees were hired

💵 4️⃣ Departments where the highest salary is ≥ 3000

🌍 5️⃣ Countries with ≥ 150 employees

🎁 6️⃣ Departments where total BonusPerc is greater than 12

📉 7️⃣ Departments where the lowest salary is < 210

📊 8️⃣ Departments with more employees than the average per department
*/

SELECT DepartmentID, COUNT(ID) AS NUMBER_OF_EMPLOYEES
FROM Employees GROUP BY DepartmentID HAVING COUNT(ID) > 140 ORDER BY DepartmentID;

SELECT DepartmentID, SUM(MonthlySalary) AS SUM_OF_SALARIES
FROM Employees GROUP BY DepartmentID HAVING SUM(MonthlySalary) > 20000 ORDER BY DepartmentID;

SELECT YEAR(HireDate) AS Hire_Date, COUNT(ID) AS COUNT_OF_HIRE_EMPLOYEES
FROM Employees GROUP BY YEAR(HireDate) HAVING COUNT(ID) > 50 ORDER BY Hire_Date;


-- LIKE STATMENT
--Finds any values that start with "a"
select ID, FirstName from Employees
where FirstName like 'a%';


--Finds any values that end with "a"
select ID, FirstName from Employees
where FirstName like '%a';


--Finds any values that have "tell" in any position
select ID, FirstName from Employees
where FirstName like '%tell%';

--	Finds any values that start with "a" and ends with "a"
select ID, FirstName from Employees
where FirstName like 'a%a';

--Finds any values that have "a" in the second position
select ID, FirstName from Employees
where FirstName like '_a%';

--Finds any values that have "a" in the third position
select ID, FirstName from Employees
where FirstName like '__a%';


--Finds any values that start with "a" and are at least 3 characters in length
select ID, FirstName from Employees
where FirstName like 'a__%';

--Finds any values that start with "a" and are at least 4 characters in length
select ID, FirstName from Employees
where FirstName like 'a___%';

--Finds any values that start with "a"
select ID, FirstName from Employees
where FirstName like 'a%' or FirstName like 'b%' ;


-- اعرض الموظفين الذين الحرف الثالث في اسمهم هوm
select ID, FirstName from Employees
where FirstName like '__m%' ;
-- اعرض الموظفين الذين يبدأ اسمهم بـ A أو B.
select ID, FirstName from Employees
where FirstName LIKE 'A%' OR FirstName LIKE 'B%'
ORDER BY FirstName;

/*
اعرض الموظفين الذين:

الحرف الثاني = a
والحرف الرابع = m
*/
select ID, FirstName from Employees
where FirstName LIKE '_a%' OR FirstName LIKE '___m%'
ORDER BY FirstName;

-- WildCards

-- will search form Mohammed or Mohammad
select ID, FirstName, LastName from Employees
Where firstName Not like 'Mohamm[ae]d';

-- search for all employees that their first name start with a or b or c
select ID, FirstName, LastName from Employees
Where firstName like '[abc]%';

-- search for all employees that their first name start with any letter from a to l
select ID, FirstName, LastName from Employees
Where firstName like '[a-l]%';

/*
* **First Query:** `WHERE FirstName LIKE '[SM]%'`
* **Result:** Completely correct;
it will search for all employees whose first names start with the letter `S` or `M`.


* **Second Query:** `WHERE FirstName LIKE '[^YTR]%'`
* **Result:** Completely correct;
using the negation sign `^` inside the brackets excludes names that start with the letters `Y`, `T`, or `R`.


* **Third Query:** `WHERE FirstName LIKE '[M-Z]%' ORDER BY FirstName`
* **Result:** Completely correct; 
it specifies a character range from `M` to `Z` and sorts the results alphabetically using `ORDER BY`.


* **Fourth Query:** `WHERE FirstName LIKE '%[nd]' ORDER BY FirstName`
* **Result:** Completely correct; 
placing the percentage sign `%` before the brackets allows any number of characters at the beginning,
while requiring the name to end with the letter `n` or `d`.


* **Fifth Query:** `WHERE FirstName LIKE '[^A-F]%' ORDER BY FirstName`
* **Result:** Completely correct; it excludes all names that start with letters in the range from `A` to `F`.

*/

SELECT ID, FirstName, LastName FROM Employees WHERE FirstName LIKE '[SM]%'

SELECT ID, FirstName, LastName FROM Employees WHERE FirstName LIKE '[^YTR]%'

SELECT ID, FirstName, LastName FROM Employees WHERE FirstName LIKE '[M-Z]%' ORDER BY FirstName

SELECT ID, FirstName, LastName FROM Employees WHERE FirstName LIKE '%[nd]' ORDER BY FirstName

SELECT ID, FirstName, LastName FROM Employees WHERE FirstName LIKE '[^A-F]%' ORDER BY FirstName




