SELECT DISTINCT Count(V.Vehicle_Display_Name) as NumOfVehicles FROM VehicleDetails V

SELECT * FROM VehicleMasterDetails VD where Make like '%che%';

SELECT Vehicle_Display_Name FROM VehicleMasterDetails VD WHERE VD.ID = 77000

SELECT Count(*) FROM VehicleDetails VD

SELECT * FROM Makes ORDER BY MakeID DESC

DELETE FROM Makes
WHERE MakeID in (420);

IF EXISTS (SELECT 1 FROM Makes WHERE MakeID = 55)
BEGIN
	SELECT 1
END
ELSE 
BEGIN 
	SELECT 0
END
