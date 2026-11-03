USE VehicleMakesDB;

GO;

-- Problem 1: Create Master View
CREATE VIEW VehicleMasterDetails AS
SELECT V.ID, V.Vehicle_Display_Name,
V.ModelID, MM.ModelName, 
V.SubModelID, SM.SubModelName,
V.FuelTypeID , FT.FuelTypeName,
V.BodyID, B.BodyName,
V.DriveTypeID, DT.DriveTypeName,
V.MakeID, M.Make,
V.Engine, V.Engine_CC, V.Engine_Cylinders, V.Engine_Liter_Display,
V.NumDoors, V.Year
FROM VehicleDetails V
LEFT JOIN MakeModels MM ON V.ModelID = MM.ModelID
LEFT JOIN SubModels SM ON V.SubModelID = SM.SubModelID
LEFT JOIN FuelTypes FT ON V.FuelTypeID = FT.FuelTypeID
LEFT JOIN Bodies B ON V.BodyID  = B.BodyID
LEFT JOIN DriveTypes DT ON V.DriveTypeID = DT.DriveTypeID
LEFT JOIN Makes M ON V.MakeID = M.MakeID;

GO;

SELECT * FROM VehicleMasterDetails;

-- Problem 2: Get all vehicles made between 1950 and 2000
SELECT * FROM VehicleMasterDetails
WHERE Year BETWEEN 1950 AND 2000;

-- Problem 3 : Get number vehicles made between 1950 and 2000
SELECT COUNT(ID) NUMBER_OF_VEHICLES FROM VehicleMasterDetails
WHERE Year BETWEEN 1950 AND 2000;

-- Problem 4 : Get number vehicles made between 1950 and 2000 per make and order them by Number Of Vehicles Descending
SELECT Make, COUNT(ID) NUMBER_OF_VEHICLES FROM VehicleMasterDetails
WHERE Year BETWEEN 1950 AND 2000
GROUP BY Make
ORDER BY NUMBER_OF_VEHICLES DESC;

--	Problem 5 : Get All Makes that have manufactured more than 12000 Vehicles in years 1950 to 2000
SELECT Make, COUNT(*) NUMBER_OF_VEHICLES FROM VehicleMasterDetails
WHERE Year BETWEEN 1950 AND 2000 
GROUP BY Make
HAVING COUNT(ID) > 12000
ORDER BY NUMBER_OF_VEHICLES DESC;
-- ANOTHER TYPE TO SOLVE
SELECT Make, COUNT(ID) NUMBER_OF_VEHICLES FROM VehicleMasterDetails
WHERE Year BETWEEN 1950 AND 2000
AND MAKE 
IN (SELECT MAKE FROM VehicleMasterDetails WHERE Year BETWEEN 1950 AND 2000 GROUP BY Make HAVING COUNT(*) > 12000)
GROUP BY Make
ORDER BY NUMBER_OF_VEHICLES DESC;
-- WITHOUT USING => HAVING
SELECT * FROM
(
	SELECT Make, COUNT(ID) NUMBER_OF_VEHICLES FROM VehicleMasterDetails
	WHERE Year BETWEEN 1950 AND 2000
	GROUP BY Make
) R1
WHERE R1.NUMBER_OF_VEHICLES > 12000;

-- Problem 6: Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside
-- TYPE 1
SELECT Make, COUNT(*) NUMBER_OF_VEHICLES, 
TOTAL_VEHICLES = (SELECT COUNT(*) FROM VehicleDetails) FROM VehicleMasterDetails
WHERE Year BETWEEN 1950 AND 2000 
GROUP BY Make
ORDER BY NUMBER_OF_VEHICLES DESC;
-- TYPE 2
SELECT *, TOTAL_VEHICLES = (SELECT COUNT(*) FROM VehicleDetails) FROM
(
	SELECT Make, COUNT(ID) NUMBER_OF_VEHICLES FROM VehicleMasterDetails
	WHERE Year BETWEEN 1950 AND 2000
	GROUP BY Make
) R1
ORDER BY NUMBER_OF_VEHICLES DESC;

-- Problem 7: Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside it, then calculate it's percentage
-- MY SOLVE
SELECT Make, COUNT(*) NUMBER_OF_VEHICLES,
TOTAL_VEHICLES = (SELECT COUNT(*) FROM VehicleDetails),
CAST(COUNT(*) AS float)/ (SELECT COUNT(*) FROM VehicleDetails) AS Percentage
FROM VehicleMasterDetails
WHERE Year BETWEEN 1950 AND 2000
GROUP BY Make
ORDER BY NUMBER_OF_VEHICLES DESC;
-- DOCTOR SOLVE
SELECT *, CAST(NUMBER_OF_VEHICLES AS float) / TOTAL_VEHICLES AS Percentage FROM
(
	SELECT Make, COUNT(*) NUMBER_OF_VEHICLES,
	TOTAL_VEHICLES = (SELECT COUNT(*) FROM VehicleDetails)
	FROM VehicleMasterDetails
	WHERE Year BETWEEN 1950 AND 2000
	GROUP BY Make
) R1
ORDER BY NUMBER_OF_VEHICLES DESC;

-- Problem 8: Get Make, FuelTypeName and Number of Vehicles that made between 1950 and 2000 per FuelType per Make
SELECT Make, FuelTypeName, COUNT(*) NUMBER_OF_VECICLES FROM VehicleMasterDetails
WHERE Year BETWEEN 1950 AND 2000
GROUP BY Make, FuelTypeName
ORDER BY Make;

-- Problem 9: Get all vehicles that runs with GAS
SELECT * FROM VehicleMasterDetails
WHERE FuelTypeName = 'GAS'
ORDER BY Make;

-- Problem 10: Get all Makes that runs with GAS
SELECT DISTINCT Make, FuelTypeName FROM VehicleMasterDetails
WHERE FuelTypeName = 'GAS'
ORDER BY Make;

-- Problem 11: Get Total Makes that runs with GAS
SELECT COUNT(*) TotalMakesRunsOnGas FROM
(
	SELECT DISTINCT MakeID FROM VehicleMasterDetails
	WHERE FuelTypeName = 'GAS'
) R1

-- Problem 12: Count Vehicles by make and order them by NumberOfVehicles from high to low.
SELECT Make, COUNT(*) NUMBER_OF_VEHICLES FROM VehicleMasterDetails
GROUP BY Make
ORDER BY COUNT(*) DESC;

-- Problem 13: Get all Makes/Count Of Vehicles that manufactures more than 20K Vehicles.
SELECT Make, COUNT(*) NUMBER_OF_VEHICLES FROM VehicleMasterDetails
GROUP BY Make
HAVING COUNT(*) > 20000
ORDER BY COUNT(*) DESC;

-- Problem 14: Write a query to get all Makes with make starts with 'B'.
SELECT Makes.Make 
FROM Makes
where Makes.Make like 'B%';

-- Problem 13: Write a query to get all Makes with make ends with 'W'.
SELECT Makes.Make 
FROM Makes
where Makes.Make like '%W';

-- Problem 16: Get all Makes that manufactures DriveTypeName = FWD
SELECT DISTINCT M.Make, DT.DriveTypeName
FROM
Makes M 
JOIN VehicleDetails VD ON M.MakeID = VD.MakeID  
JOIN DriveTypes DT ON VD.DriveTypeID = DT.DriveTypeID
where DT.DriveTypeName like 'FWD';

-- Problem 17: Get total Makes that Mantufactures DriveTypeName = FWD
SELECT COUNT(*) MakeWithFWD FROM
(
	SELECT DISTINCT M.Make
	FROM
	Makes M 
	JOIN VehicleDetails VD ON M.MakeID = VD.MakeID  
	JOIN DriveTypes DT ON VD.DriveTypeID = DT.DriveTypeID
	where DT.DriveTypeName like 'FWD'
) T1

-- Problem 18: Get total vehicles per DriveTypeName Per Make and order them per make asc then per total Desc
SELECT DISTINCT M.Make, DT.DriveTypeName, COUNT(*) AS COUNT
FROM
Makes M 
JOIN VehicleDetails VD ON M.MakeID = VD.MakeID  
JOIN DriveTypes DT ON VD.DriveTypeID = DT.DriveTypeID
GROUP BY M.Make, DT.DriveTypeName
ORDER BY Make, COUNT DESC;

-- Problem 19: Get total vehicles per DriveTypeName Per Make then filter only results with total > 10,000
SELECT DISTINCT M.Make, DT.DriveTypeName, COUNT(*) AS COUNT_PER_TYPES
FROM
Makes M 
JOIN VehicleDetails VD ON M.MakeID = VD.MakeID  
JOIN DriveTypes DT ON VD.DriveTypeID = DT.DriveTypeID
GROUP BY M.Make, DT.DriveTypeName
HAVING COUNT(*) > 10000
ORDER BY Make, COUNT_PER_TYPES DESC;

-- Problem 20: Get all Vehicles that number of doors is not specified
SELECT * FROM VehicleDetails V
WHERE V.NumDoors IS NULL

-- Problem 21: Get Total Vehicles that number of doors is not specified
SELECT COUNT(*) TotalWithNoSpecifiedDoors
FROM VehicleDetails V
WHERE V.NumDoors IS NULL

-- Problem 22: Get percentage of vehicles that has no doors specified

SELECT CAST((SELECT COUNT(*)  FROM VehicleDetails V WHERE V.NumDoors IS NULL) AS FLOAT)  / COUNT(*)
AS TotalPercentageNoSpecifiedDoors
FROM VehicleDetails V

-- Problem 23: Get MakeID , Make, SubModelName for all vehicles that have SubModelName 'Elite'
SELECT DISTINCT M.MakeID , Make, SubModelName FROM VehicleDetails V
JOIN Makes M ON V.MakeID = M.MakeID
JOIN SubModels SM ON V.SubModelID = SM.SubModelID
WHERE SM.SubModelName = 'Elite';

-- Problem 24: Get all vehicles that have Engines > 3 Liters and have only 2 doors
SELECT * FROM VehicleDetails V
WHERE NumDoors > 2 AND Engine_Liter_Display > 3

-- Problem 25: Get make and vehicles that the engine contains 'OHV' and have Cylinders = 4
SELECT M.Make, V.* FROM VehicleDetails V
JOIN Makes M ON V.MakeID = M.MakeID
WHERE Engine LIKE '%OHV%' AND Engine_Cylinders = 4

-- Problem 26: Get all vehicles that their body is 'Sport Utility' and Year > 2020
SELECT B.BodyName, V.* FROM VehicleDetails V
JOIN Bodies B ON V.BodyID = B.BodyID
WHERE B.BodyName = 'Sport Utility' AND Year > 2020;

-- Problem 27: Get all vehicles that their Body is 'Coupe' or 'Hatchback' or 'Sedan'
SELECT B.BodyName, V.* FROM VehicleDetails V
JOIN Bodies B ON V.BodyID = B.BodyID
WHERE B.BodyName IN ('Coupe', 'Hatchback', 'Sedan');

/*
Problem 28: Get all vehicles that their body is 'Coupe' or 'Hatchback' or 'Sedan' 
and manufactured in year 2008 or 2020 or 2021 
*/
SELECT B.BodyName, V.* FROM VehicleDetails V
JOIN Bodies B ON V.BodyID = B.BodyID
WHERE B.BodyName IN ('Coupe', 'Hatchback', 'Sedan') AND Year IN (2008, 2020, 2021);

-- Problem 29: Return found=1 if there is any vehicle made in year 1950
IF EXISTS (SELECT TOP 1 ID FROM VehicleDetails WHERE Year = 1950)
BEGIN
SELECT FOUND = 1
END;

SELECT FOUND = 1 
WHERE EXISTS (SELECT TOP 1 * FROM VehicleDetails WHERE Year =1950)

/*
Problem 30: Get all Vehicle_Display_Name,
NumDoors and add extra column to describe number of doors by words,
and if door is null display 'Not Set'
*/
SELECT DISTINCT NumDoors
FROM VehicleDetails V
ORDER BY NumDoors

SELECT V.Vehicle_Display_Name, NumDoors, NUM_OF_DOORS_IN_TEXT =
	CASE 
		WHEN NumDoors IS NULL THEN 'Not Set'
		WHEN NumDoors = 0 THEN 'NO-DOORS'
		WHEN NumDoors = 1 THEN '1-DOOR'
		WHEN NumDoors = 2 THEN '2-DOORS'
		WHEN NumDoors = 3 THEN '3-DOORS'
		WHEN NumDoors = 4 THEN '4-DOORS'
		WHEN NumDoors = 5 THEN '5-DOORS'
		WHEN NumDoors = 6 THEN '6-DOORS'
		WHEN NumDoors = 8 THEN '7-DOORS'
		ELSE 'OTHER'
	END
FROM VehicleDetails V
ORDER BY NumDoors

/*
Problem 31: Get all Vehicle_Display_Name,
year and add extra column to calculate the age of the car then sort the results by age desc.
*/
SELECT Vehicle_Display_Name, year, AGE = YEAR(GETDATE()) - year
FROM VehicleDetails
ORDER BY AGE DESC;

/*
Problem 32: Get all Vehicle_Display_Name, year,
Age for vehicles that their age between 15 and 25 years old
*/
SELECT Vehicle_Display_Name,
year,
YEAR(GETDATE()) - year AS AGE
FROM VehicleDetails
WHERE YEAR(GETDATE()) - year BETWEEN 15 AND 25;


select * from
( 
	Select VehicleDetails.Vehicle_Display_Name, Year, Age= YEAR(GetDate()) - VehicleDetails.year
	from VehicleDetails
) R1
Where Age between 15 and 25

-- Problem 33: Get Minimum Engine CC , Maximum Engine CC , and Average Engine CC of all Vehicles
SELECT 
	MIN(Engine_CC) as MinimimEngineCC, 
	MAX(Engine_CC) as MaximumEngineCC,
	AVG(Engine_CC) as AverageEngineCC
FROM VehicleDetails

-- Problem 34: Get all vehicles that have the minimum Engine_CC
SELECT *
FROM VehicleDetails
WHERE Engine_CC = (SELECT MIN(Engine_CC) FROM VehicleDetails);

-- Problem 35: Get all vehicles that have the Maximum Engine_CC
SELECT *
FROM VehicleDetails
WHERE Engine_CC = (SELECT MAX(Engine_CC) FROM VehicleDetails);

-- Problem 36: Get all vehicles that have Engin_CC below average
SELECT *
FROM VehicleDetails
WHERE Engine_CC < (SELECT AVG(Engine_CC) FROM VehicleDetails);

--  Problem 37: Get total vehicles that have Engin_CC above average
SELECT *
FROM VehicleDetails
WHERE Engine_CC > (SELECT AVG(Engine_CC) FROM VehicleDetails);

-- Problem 38: Get all unique Engin_CC and sort them Desc
SELECT DISTINCT Engine_CC FROM VehicleDetails
ORDER BY Engine_CC DESC

-- Problem 39: Get the maximum 3 Engine CC
SELECT DISTINCT TOP 3 Engine_CC FROM VehicleDetails
ORDER BY Engine_CC DESC

-- Problem 40: Get all vehicles that has one of the Max 3 Engine CC
SELECT *
FROM VehicleDetails
WHERE Engine_CC IN (SELECT DISTINCT TOP 3 Engine_CC FROM VehicleDetails ORDER BY Engine_CC DESC);

-- Problem 41: Get all Makes that manufactures one of the Max 3 Engine CC
SELECT DISTINCT Make
FROM VehicleDetails V
JOIN Makes M ON V.MakeID = M.MakeID
WHERE Engine_CC IN (SELECT DISTINCT TOP 3 Engine_CC FROM VehicleDetails ORDER BY Engine_CC DESC);

-- Problem 42: Get a table of unique Engine_CC and calculate tax per Engine CC
/*
	-- 0 to 1000    Tax = 100
	-- 1001 to 2000 Tax = 200
	-- 2001 to 4000 Tax = 300
	-- 4001 to 6000 Tax = 400
	-- 6001 to 8000 Tax = 500
	-- Above 8000   Tax = 600
	-- Otherwise    Tax = 0
*/
SELECT DISTINCT Engine_CC, TAX =
CASE
	WHEN Engine_CC BETWEEN 0 AND 1000 THEN 100
	WHEN Engine_CC BETWEEN 1001 AND 2000 THEN 200
	WHEN Engine_CC BETWEEN 2001 AND 4000 THEN 300
	WHEN Engine_CC BETWEEN 4001 AND 6000 THEN 400
	WHEN Engine_CC BETWEEN 6001 AND 8000 THEN 500
	WHEN Engine_CC > 8000 THEN 600
	ELSE 0
END
FROM (SELECT DISTINCT Engine_CC FROM VehicleDetails) T1
ORDER BY Engine_CC

-- Problem 43: Get Make and Total Number Of Doors Manufactured Per Make
SELECT M.Make, 
(SELECT SUM(NumDoors) FROM VehicleDetails V WHERE V.MakeID = M.MakeID) TotalNumberOfDoors
FROM Makes M
ORDER BY TotalNumberOfDoors DESC;

-- Problem 44: Get Total Number Of Doors Manufactured by 'Ford'
SELECT M.Make,
(SELECT SUM(NumDoors) FROM VehicleDetails V WHERE V.MakeID = M.MakeID) TotalNumberOfDoors
FROM Makes M
WHERE Make = 'Ford';

-- BETTER PERFORMANCE
SELECT Makes.Make, 
SUM(VehicleDetails.NumDoors) AS TotalNumberOfDoors
FROM 
VehicleDetails INNER JOIN Makes ON VehicleDetails.MakeID = Makes.MakeID
WHERE Makes.Make = 'Ford' -- التصفية مبكراً لتسريع الاستعلام
GROUP BY Makes.Make;

-- Problem 45: Get Number of Models Per Make
SELECT M.Make,
COUNT(ModelID) AS NumberOfModels
FROM 
Makes M INNER JOIN MakeModels MM ON M.MakeID = MM.MakeID
GROUP BY M.Make
ORDER BY NumberOfModels DESC;

-- Problem 46: Get the highest 3 manufacturers that make the highest number of models
SELECT TOP 3 M.Make,
COUNT(ModelID) AS NumberOfModels FROM
Makes M INNER JOIN MakeModels MM ON M.MakeID = MM.MakeID
GROUP BY M.Make
ORDER BY NumberOfModels DESC;

-- Problem 47: Get the highest number of models manufactured
SELECT TOP 1
COUNT(ModelID) AS MaxNumberOfModels FROM
Makes M INNER JOIN MakeModels MM ON M.MakeID = MM.MakeID
GROUP BY M.Make
ORDER BY MaxNumberOfModels DESC;	

-- Problem 48: Get the highest Manufacturers manufactured the highest number of models

-- RETURN ONE ROW IF THER IF MORE THAN ONE MANUFACTURED (ME)
SELECT Make FROM 
(
	SELECT TOP 1 M.Make,
	COUNT(ModelID) AS MaxNumberOfModels FROM
	Makes M INNER JOIN MakeModels MM ON M.MakeID = MM.MakeID
	GROUP BY M.Make
	ORDER BY MaxNumberOfModels DESC
) T1;

-- RETURN ALL (DOCTOR SOLUTION)
SELECT Makes.Make, COUNT(*) AS NumberOfModels
FROM Makes 
INNER JOIN MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
having COUNT(*) = (
    select Max(NumberOfModels) as MaxNumberOfModels
    from (
        SELECT MakeID, COUNT(*) AS NumberOfModels
        FROM MakeModels
        GROUP BY MakeID
    ) R1
);

-- (ME)
SELECT M.Make, COUNT(ModelID) AS NumberOfModels
FROM MakeModels MM JOIN Makes M ON MM.MakeID = M.MakeID
GROUP BY M.Make
HAVING COUNT(ModelID) =
(
	SELECT TOP 1
	COUNT(ModelID) AS MaxNumberOfModels FROM
	Makes M INNER JOIN MakeModels MM ON M.MakeID = MM.MakeID
	GROUP BY M.Make
	ORDER BY MaxNumberOfModels DESC
)

-- Problem 49: Get the Lowest Manufacturers manufactured the lowest number of models
SELECT M.Make, COUNT(ModelID) AS NumberOfModels
FROM MakeModels MM JOIN Makes M ON MM.MakeID = M.MakeID
GROUP BY M.Make
HAVING COUNT(ModelID) =
(
	SELECT TOP 1
	COUNT(ModelID) AS MaxNumberOfModels FROM
	Makes M INNER JOIN MakeModels MM ON M.MakeID = MM.MakeID
	GROUP BY M.Make
	ORDER BY MaxNumberOfModels ASC
)

-- Problem 50: Get all Fuel Types , each time the result should be showed in random order
SELECT * FROM FuelTypes
ORDER BY NEWID()

----------------------------------------------------------------------------------------------------------------
-- Self Referential Queries
GO;

USE EmployeesDB;

-- Problem 51: Get all employees that have manager along with Manager's name.
SELECT E.*, EM.Name FROM Employees E
JOIN Employees EM ON E.ManagerID = EM.EmployeeID

-- Get all employees that have manager or does not have manager along with Manager's name, incase no manager name show null
SELECT E.*, EM.Name FROM Employees E
LEFT JOIN Employees EM ON E.ManagerID = EM.EmployeeID

/* 
Problem 53: Get all employees that have manager or does not have manager along with Manager's name,
incase no manager name the same employee name as manager to himself
*/
SELECT E.*,
CASE
	WHEN EM.Name IS NULL THEN E.Name
	ELSE EM.Name
END AS ManagerName
FROM Employees E
LEFT JOIN Employees EM ON E.ManagerID = EM.EmployeeID


-- Problem 54: Get All Employees managed by 'Mohammed'
SELECT E.*, EM.Name FROM Employees E
JOIN Employees EM ON E.ManagerID = EM.EmployeeID
WHERE E.ManagerID = 1;
