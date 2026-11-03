-- Problem 55: Get all vehicles whose Engine_CC is greater than the average Engine_CC of their respective Make
SELECT * FROM VehicleDetails VOUT
WHERE Engine_CC > 
(
	SELECT AVG(Engine_CC) AS MaxEngineCC FROM VehicleDetails V
	WHERE VOUT.MakeID = V.MakeID
);

-- Problem 56: Get all vehicles whose Engine_CC is equals the max Engine_CC of their respective Make
SELECT * FROM VehicleDetails VOUT
WHERE Engine_CC = 
(
	SELECT MAX(Engine_CC) AS MaxEngineCC FROM VehicleDetails V
	WHERE VOUT.MakeID = V.MakeID
);

/*
المهمة الأولى:
استعلم عن جميع المركبات المصنعة في الفترة ما بين سنة 2010 وسنة 2024 (شاملة السنتين).

المهمة الثانية:
احسب إجمالي عدد المركبات المصنعة لكل شركة (Make) 
خلال الفترة من 2010 إلى 2024، مع ترتيب النتائج تنازلياً حسب عدد المركبات.

المهمة الثالثة:
استخرج فقط الشركات (Make) التي قامت بتصنيع أكثر من 5,000 مركبة في الفترة بين 2010 و 2024 بدون استخدام شرط 
HAVING (استخدم طريقة الاستعلام الفرعي Subquery أو Derived Table بدلاً منها).

المهمة الرابعة:
اعرض اسم الشركة (Make)، ونوع ناقل الحركة أو الجر (DriveTypeName)، وإجمالي عدد المركبات لكل نوع جر لكل شركة،
بحيث يتم فلترة النتائج فقط لعرض الحالات التي يكون فيها المجموع أكبر من 2,000 مركبة.

المهمة الخامسة:
اكتب استعلاماً لإرجاع كافة المركبات التي تحتوي محركاتها على كلمة 'Turbo' وتعمل بنوع وقود 'Diesel'.
*/

-- 1
SELECT VD.Vehicle_Display_Name, VD.Year FROM VehicleDetails VD WHERE VD.Year BETWEEN 2010 AND 2024
ORDER BY VD.Year DESC

-- 2
SELECT M.Make, VD.Year, COUNT(*) AS NumberOfCars FROM VehicleDetails VD 
JOIN Makes M ON VD.MakeID = M.MakeID 
WHERE VD.Year BETWEEN 2010 AND 2024
GROUP BY M.Make, VD.Year
ORDER BY NumberOfCars DESC

