#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

#pragma region Problem 1 (Number to text)
string NumberToText (int number)
{
	if (number == 0)
		return "Zero";

	if (number >= 1 && number <= 19)
	{
		string numberWords[20] = {
		"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
		"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
		"seventeen", "eighteen", "nineteen"
		};
		 
		return numberWords[number];
	}

	if (number >= 20 && number <= 99)
	{
		string tensWords[10] = { "","",
			"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
		};
		 
		return tensWords[number / 10] + " " + NumberToText(number % 10);
	}

	if (number >= 100 && number <= 199)
	{
		return "one hundreds " + NumberToText(number % 100);
	}

	if (number >= 200 && number <= 999)
	{
		return NumberToText(number / 100) + " hundreds " + NumberToText(number % 100);
	}

	if (number >= 1000 && number <= 1999)
	{
		return "one thousand " + NumberToText(number % 1000);
	}

	if (number >= 2000 && number <= 999999)
	{
		return NumberToText(number / 1000) + " thousands " + NumberToText(number % 1000);
	}

	if (number >= 1000000 && number <= 1999999)
	{
		return NumberToText(number / 1000000) + " million " + NumberToText(number % 1000000);
	}

	if (number >= 2000000 && number <= 9999999)
	{
		return NumberToText(number / 1000000) + " millions " + NumberToText(number % 1000000);
	}

	if (number >= 1000000000 && number <= 1999999999)
	{
		return NumberToText(number / 1000000000) + " billion " + NumberToText(number % 1000000000);
	}

	if (number >= 2000000000 && number <= 999999999)
	{
		return NumberToText(number / 1000000000) + " billions " + NumberToText(number % 1000000000);
	}

}
#pragma endregion

#pragma region Problem 2 and 3 (is leap year)
bool isLeapYear(short year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
#pragma endregion

#pragma region Problem 4 
short DaysInYear(short year)
{
	return isLeapYear(year) ? 366 : 365;
}

int HoursInYear(short year)
{
	return (int)DaysInYear(year) * 24;
}

int MinutesInYear(short year)
{
	return HoursInYear(year) * 60;
}

int SecondsInYear(short year)
{
	return MinutesInYear(year) * 60;
}
#pragma endregion

#pragma region Problem 5 Number of (days hours minutes seconds) in month in year
short DaysInMonth(short year,short month)
{
	const int daysInMonth[2][13] = {
			{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 0: Non-Leap
			{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // 1: Leap
	};

	return isLeapYear(year) ? daysInMonth[1][month] : daysInMonth[0][month];
}

int HoursInInMonth(short year, short month)
{
	return (int)DaysInMonth(year, month) * 24;
}

int MinutesInMonth(short year, short month)
{
	return HoursInInMonth(year, month) * 60;
}

int SecondsInMonth(short year, short month)
{
	return MinutesInMonth(year, month) * 60;
}
#pragma endregion

#pragma region Problem 7 (Name of day)
string NumberOfDayToNameOfDay(short day)
{
	if (day < 0 || day > 6)
		return "Not valid day";

	switch (day)
	{
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	}
}

string NameOfDay(short year, short month, short day)
{
	short a = (14 - month) / 12;

	short y = year - a;
	short m = month + (12 * a) - 2;

	short DayInGregorianCalender = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return NumberOfDayToNameOfDay(DayInGregorianCalender);
}

#pragma endregion

#pragma region Problem 8 (Print calender by year and month)
short DayOfWeekOrder(short year, short month, short day)
{
	short a = (14 - month) / 12;

	short y = year - a;
	short m = month + (12 * a) - 2;

	short DayInGregorianCalender = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return DayInGregorianCalender;
}
string getMonthName(int monthNum)
{
	// مصفوفة تحتوي على اختصارات الأشهر
	// نضع عنصراً فارغاً في البداية "" لكي يتطابق رقم الشهر مباشرة مع الـ index (اختياري)
	const std::string months[] = {
		"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};

	// التأكد من أن الرقم يقع بين 1 و 12
	if (monthNum >= 1 && monthNum <= 12) {
		return months[monthNum];
	}

	return "Invalid"; // في حال إدخال رقم خاطئ
}
void printCalendarHeader(short month) 
{
	std::cout << "_______________"<< getMonthName(month) <<"_______________" << std::endl;

	std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << std::endl;
}
void printCalendarFooter() 
{
	std::cout << "_________________________________" << std::endl;

}

void printCalendarInfo(short year, short month) 
{
	short current = DayOfWeekOrder(year, month, 1);
	short numberOfDaysInMonth = DaysInMonth(year, month);

	int j;
	for (j = 0; j < current; j++)
		printf("     ");

	short breakLineDayNumber = current;
	for (short i = 1; i <= numberOfDaysInMonth; i++)
	{
		printf("%5d", i);

		if (++j == 7)
		{
			j = 0;
			printf("\n");
		}
	}

	cout << endl;

}



void printCalendar(short year, short month)
{
	printCalendarHeader(month);

	printCalendarInfo(year, month);

	printCalendarFooter();
}

#pragma endregion

#pragma region Problem 9 (Print calender of all year)
void printCalendarOfAllYear(short year)
{
	cout << "_________________________________" << std::endl;
	cout << "         Calender - " << year << " " << endl;

	std::cout << "_________________________________" << std::endl;
	for (short i = 1; i < 13; i++)
	{
		printCalendar(year,i);
		cout << endl;
	}
}
#pragma endregion

#pragma region Problem 10 (number of days to specific day and specific month)
short NumberOfDaysFromTheBeginingOfTheYear(short year, short month, short day)
{
	short TotalOfDays = 0;

	for (short i = 1; i < month; i++)
		TotalOfDays += DaysInMonth(year, i);

	return TotalOfDays + day;
}
#pragma endregion

#pragma region Problem 11 (Full date by number of days and target year)
struct sDate
{
	short Day = 0;
	short Month = 0;
	int Year = 0;
};

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

sDate FullDateByYearAndNumberOfDays(short year, short numberOfDays)
{
	sDate FullDate;

	short DaysInTargetMonth = 0;

	for (short i = 0; i < 12; i++)
	{
		DaysInTargetMonth = DaysInMonth(year, i+1);

		if ((numberOfDays - DaysInTargetMonth) > 0)
		{
			numberOfDays = numberOfDays - DaysInTargetMonth;
		}
		else
		{
			FullDate.Day = numberOfDays;
			FullDate.Month = i + 1;
			FullDate.Year = year;
			return FullDate;
		}
		
	}

}
#pragma endregion

#pragma region Problem 12 (Full date by number of days and target year)

sDate AddDaysToDate (sDate date, int addedDays)
{
	sDate FullDate;

	int RemainderDays = addedDays + NumberOfDaysFromTheBeginingOfTheYear(date.Year, date.Month, date.Day);

	date.Month = 1;
	short daysInMonth = 0;

	while (true)
	{
		daysInMonth = DaysInMonth(date.Year, date.Month);

		if (RemainderDays > daysInMonth)
		{
			if (date.Month == 12)
			{
				date.Year++;
				date.Month = 1;

				RemainderDays -= daysInMonth;
				continue;
			}

			date.Month++;
			RemainderDays -= daysInMonth;
		}
		else
		{
			date.Day = RemainderDays;
			break;
		}
	}

	return date;

}
#pragma endregion

#pragma region Problem 13 (Compare two dates)

string CompareToDates (sDate dateOne, sDate dateTwo)
{

	if (dateOne.Year == dateTwo.Year)
	{
		if (dateOne.Month == dateTwo.Month)
		{
			if (dateOne.Day == dateTwo.Day)
			{
				return "Date one is equals date two";

			}
			else if (dateOne.Day > dateTwo.Day)
			{
				return "Date one is bigger than date two";
			}
			else
			{
				return "Date two is bigger than date one";

			}
		}
		else if (dateOne.Month > dateTwo.Month)
		{
			return "Date one is bigger than date two";
		}
		else
		{
			return "Date two is bigger than date one";

		}
	}
	else if (dateOne.Year > dateTwo.Year)
	{
		return "Date one is bigger than date two";
	}
	else
	{
		return "Date two is bigger than date one";

	}

}
#pragma endregion

#pragma region Problem 14 (Is date one equals date Two)

bool IsDateOneEqualsDateTwo(sDate dateOne, sDate dateTwo)
{

	if (dateOne.Year == dateTwo.Year)
	{
		if (dateOne.Month == dateTwo.Month)
		{
			if (dateOne.Day == dateTwo.Day)
			{
				return true;
			}
		}
	}
	else
	{
		return false;

	}

	return false;

}
#pragma endregion

#pragma region Problem 15 (Is last day in month and last month in year)

bool IsLastDayInMonth(sDate date)
{
	return date.Day == DaysInMonth(date.Year, date.Month);
}
bool IsLastMonthInYear(short month)
{
	return month == 12;
}
#pragma endregion

#pragma region Problem 16 (Increase the date by one day)

sDate IncreaseDateByOneDay(sDate date)
{
	if (IsLastMonthInYear(date.Month))
	{
		if (IsLastDayInMonth(date))
		{
			date.Year++;
			date.Month = 1;
			date.Day = 1;
		}
	}
	else
	{
		if (IsLastDayInMonth(date))
		{
			date.Month++;
			date.Day = 1;
		}
		else
		{
			date.Day++;
		}
	}

	return date;

}
#pragma endregion

#pragma region Problem 17 (Diff between two dates)
bool IsDate1BeforeDate2(sDate dateOne, sDate dateTwo);

int GetDifferenceInDays(sDate dateOne, sDate dateTwo,bool includeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(dateOne, dateTwo))
	{
		Days++;
		dateOne = IncreaseDateByOneDay(dateOne);
	}

	return includeEndDay ? ++Days : Days;
}
#pragma endregion

#pragma region Problem 18 (Your age in days)
sDate GetSystemDate()
{
	sDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
}

short AgeInDays(sDate birthDate)
{
	sDate DateOfNow = GetSystemDate();
	return GetDifferenceInDays(birthDate, DateOfNow);
}
#pragma endregion

#pragma region Problem 20-32 (Functions in date)
sDate IncreaseDateByXDays(short Days, sDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	// التحقق من أن اليوم لا يتجاوز الحد الأقصى لأيام الشهر الحالي الجديد
	// مثال: 31/1/2022 عند إضافة شهر تصبح 28/2/2022 وليس 31/2/2022
	short NumberOfDaysInCurrentMonth = DaysInMonth( Date.Year, Date.Month );
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

sDate IncreaseDateByXMonths(short Months, sDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
	Date.Year++;
	return Date;
}

sDate IncreaseDateByXYears(short Years, sDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year += Years;
	return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
	// إضافة عقد واحد (10 سنوات)
	Date.Year += 10;
	return Date;
}

sDate IncreaseDateByXDecades(short Decades, sDate Date)
{
	for (short i = 1; i <= Decades * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXDecadesFaster(short Decades, sDate Date)
{
	Date.Year += Decades * 10;
	return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
	// إضافة قرن واحد (100 سنة)
	Date.Year += 100;
	return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
	// إضافة ألفية واحدة (1000 سنة)
	Date.Year += 1000;
	return Date;
}

#pragma endregion

#pragma region Problem 33 - 46 (Functions in date)
sDate DecreaseDateByOneDay(sDate date)
{
	if (date.Month == 1)
	{
		if (date.Day == 1)
		{
			date.Year--;
			date.Month = 12;
			date.Day = DaysInMonth(date.Year,date.Month);
		}
	}
	else
	{
		if (date.Day == 1)
		{
			date.Month--;
			date.Day = DaysInMonth(date.Year, date.Month);
		}
		else
		{
			date.Day--;
		}
	}

	return date;
}

sDate DecreaseDateByXDays(short Days, sDate date)
{
	for (int i = 1; i <= Days; i++)
	{
		date = DecreaseDateByOneDay(date);
	}
	return date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (int i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	// التحقق من أن اليوم لا يتجاوز الحد الأقصى لأيام الشهر الحالي الجديد
	// مثال: 31/1/2022 عند إضافة شهر تصبح 28/2/2022 وليس 31/2/2022
	short NumberOfDaysInCurrentMonth = DaysInMonth( Date.Year, Date.Month );
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

sDate DecreaseDateByXMonths(short Months, sDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
	Date.Year--;
	return Date;
}

sDate DecreaseDateByXYears(short Years, sDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year -= Years;
	return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
	Date.Year -= 10;
	return Date;
}

sDate DecreaseDateByXDecades(short Decades, sDate Date)
{
	for (short i = 1; i <= Decades * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXDecadesFaster(short Decades, sDate Date)
{
	Date.Year -= Decades * 10;
	return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
	// إضافة قرن واحد (100 سنة)
	Date.Year -= 100;
	return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
	// إضافة ألفية واحدة (1000 سنة)
	Date.Year -= 1000;
	return Date;
}

#pragma endregion

#pragma region Problem 47 - 53
bool IsEndOfTheWeek(sDate date)
{
	// Sun  Mon  Tue  Wed  Thu  Fri  Sat
	return (DayOfWeekOrder(date.Year, date.Month, date.Day) == 4);
		
}

bool IsWeekend(sDate date)
{
	// Sun  Mon  Tue  Wed  Thu  Fri  Sat
	short numberOfDay = DayOfWeekOrder(date.Year, date.Month, date.Day);
	return (numberOfDay == 6 || numberOfDay == 5);
}

bool IsBusinessDay(sDate date)
{
	return !IsWeekend(date);
}

short DaysUntilTheEndOfWeek(sDate date)
{
	// Sun  Mon  Tue  Wed  Thu  Fri  Sat
	short numberOfDay = DayOfWeekOrder(date.Year, date.Month, date.Day);
	return 7 - (numberOfDay + 1);
}

short DaysUntilTheEndOfMonth(sDate date)
{
	return (DaysInMonth(date.Year, date.Month) + 1) - date.Day;
}

short DaysUntilTheEndOfYear(sDate date)
{
	return (DaysInYear(date.Year) + 1) -  NumberOfDaysFromTheBeginingOfTheYear(date.Year, date.Month, date.Day);
}

#pragma endregion

#pragma region Problem 54 (Calculate vacation days)
int CalculateVacationDays(sDate startDate, sDate endDate)
{
	int TotalVacationDays = 0;
	int DiffBetweenDates = GetDifferenceInDays(startDate, endDate);

	for (int i = 0; i < DiffBetweenDates; i++)
	{
		if (IsBusinessDay(startDate))
			TotalVacationDays++;

		startDate = IncreaseDateByOneDay(startDate);
	}

	return TotalVacationDays;
}
#pragma endregion

#pragma region Problem 55 (Calculate The End Of Vacation)
sDate CalculateTheEndOfVacation(sDate startDate, int vacationDays)
{
	while(vacationDays != 0)
	{
		if (IsBusinessDay(startDate))
			vacationDays--;

		startDate = IncreaseDateByOneDay(startDate);
	}

	return (startDate);
}
#pragma endregion

#pragma region Problem 56 (Calculate The End Of Vacation)
bool IsDate1AfterDate2(sDate dateOne, sDate dateTwo)
{
	if (dateOne.Year > dateTwo.Year) return true;
	if (dateOne.Year < dateTwo.Year) return false;

	// إذا وصلنا هنا، فهذا يعني أن السنوات متساوية
	if (dateOne.Month > dateTwo.Month) return true;
	if (dateOne.Month < dateTwo.Month) return false;

	// إذا وصلنا هنا، فهذا يعني أن السنوات والأشهر متساوية
	return dateOne.Day > dateTwo.Day;
}

bool IsDate1BeforeDate2(sDate dateOne, sDate dateTwo)
{
	return (!IsDate1AfterDate2(dateOne, dateTwo) && !IsDateOneEqualsDateTwo(dateOne, dateTwo));
}
#pragma endregion

#pragma region Problem 57 (relation between two dates)
int CompareDates(sDate dateOne, sDate dateTwo)
{
	if (IsDate1BeforeDate2(dateOne, dateTwo))
		return -1;
	else if (IsDateOneEqualsDateTwo(dateOne, dateTwo))
		return 0;
	else
		return 1;
}
#pragma endregion

#pragma region Problem 58 (Overlap periods)
struct stPeriod
{
	sDate StartDate;
	sDate EndDate;
};

stPeriod ReadPeriod()
{
	stPeriod Period;
	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}

bool IsOverlapPeriods(stPeriod periodOne, stPeriod periodTwo)
{
	return !(CompareDates(periodTwo.EndDate, periodOne.StartDate) == -1 ||
		CompareDates(periodTwo.StartDate, periodOne.EndDate) == 1);
}
#pragma endregion

#pragma region Problem 59 (Period Length In Days)

int PeriodLengthInDays(stPeriod period, bool includeLastDay = false)
{
	return GetDifferenceInDays(period.StartDate, period.EndDate, includeLastDay);
}
#pragma endregion

#pragma region Problem 60 (Is date in period)

int IsDateInPeriod(sDate date, stPeriod period)
{
	return !(IsDate1AfterDate2(date, period.EndDate) || IsDate1BeforeDate2(date, period.StartDate));
}
#pragma endregion

#pragma region Problem 61 (Count overlaped days)

int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverlapDays = 0;
	
	if (!IsOverlapPeriods(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateInPeriod(Period1.StartDate, Period2))
				OverlapDays++;
			Period1.StartDate =
				IncreaseDateByOneDay(Period1.StartDate);
		}

		if (IsDateInPeriod(Period1.StartDate, Period2))
			OverlapDays++;
	}
	else
	{
		while (IsDate1BeforeDate2(Period2.StartDate,Period2.EndDate))
		{
			if (IsDateInPeriod(Period2.StartDate, Period1))
				OverlapDays++;
			Period2.StartDate =
				IncreaseDateByOneDay(Period2.StartDate);
		}
		if (IsDateInPeriod(Period2.StartDate, Period1))
			OverlapDays++;

	}
	return OverlapDays;
}
#pragma endregion

#pragma region Problem 62 (Is valid date)

bool IsValidDate(sDate date)
{
	if ((date.Day > 31 || date.Day < 1) || (date.Month > 12 || date.Month < 1))
		return false;

	if (date.Day > DaysInMonth(date.Year, date.Month))
		return false;

	return true;
}
#pragma endregion

#pragma region Problem 63-64 (String to date and the oposite)

#include <sstream>

vector<string> split(const string& str, char delimiter) 
{
	vector<string> tokens;
	string token;
	stringstream ss(str); // تحويل النص إلى دفق نصوص (Stream)

	// تقطيع النص بناءً على الـ delimiter وضخه في الـ vector
	while (getline(ss, token, delimiter))
	{
		tokens.push_back(token);
	}

	return tokens;
}

string ReadStringDate(string Message)
{
	string DateString;
	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}

sDate StringToDate(string stringDate)
{
	vector<string> DateParts = split(stringDate, '/');
	sDate Date;

	if (DateParts.size() == 3)
	{
		Date.Day = stoi(DateParts[0]);
		Date.Month = stoi(DateParts[1]);
		Date.Year = stoi(DateParts[2]);
	}
	return Date;
}

string DateToString(sDate date)
{
	return to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);
}
#pragma endregion

#pragma region Problem 65 (Date format)
string ReplaceWordInString(string str, string wordToReplace, string newValue)
{
	size_t pos = str.find(wordToReplace);

	while (pos != string::npos) 
	{
		str.replace(pos, wordToReplace.length(), newValue);

		pos = str.find(wordToReplace, pos + newValue.length());
	}

	return str;
}

string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";
	FormattedDateString = ReplaceWordInString(DateFormat, "dd",to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString,"mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString,"yyyy", to_string(Date.Year));
	return FormattedDateString;
}
#pragma endregion

int ReadNumber(string message)
{
	cout << message << endl;
	int number = 0;

	cin >> number;
	
	return number;
}

void FirstTenProblems()
{
	// Problem 1
	//cout << NumberToText(ReadNumber("Please enter your number : ")) << endl;

	// Problem 2 and 3
	//if (isLeapYear(ReadNumber("Please enter your year you what to check if it leap or not :")))
	//	cout << "Year is leap" << endl;
	//else
	//	cout << "Year is not leap" << endl;

	// Problem 4
	//int year = ReadNumber("Please enter your year : ");
	//cout << "Number of days in year [" << year << "] : " << DayesInYear(year) << endl;
	//cout << "Number of hours in year [" << year << "] : " << HoursInYear(year) << endl;
	//cout << "Number of minutes in year [" << year << "] : " << MinutesInYear(year) << endl;
	//cout << "Number of seconds in year [" << year << "] : " << SecondsInYear(year) << endl;

	// Problem 5
	//int year = ReadNumber("Please enter your year : ");
	//int month = ReadNumber("Please enter your month : ");
	//cout << "Number of days in month [" << month << "] " << "in year [" << year << "] : " <<  DayesInMonth(year,month) << endl;
	//cout << "Number of hours in year [" << month << "] " << "in year [" << year << "] : " << HoursInInMonth(year, month) << endl;
	//cout << "Number of minutes in year [" << month << "] " << "in year [" << year << "] : " << MinutesInMonth(year, month) << endl;
	//cout << "Number of seconds in year [" << month << "] " << "in year [" << year << "] : " << SecondsInMonth(year, month) << endl;

	// Problem 7
	//int year = ReadNumber("Please enter your year : ");
	//int month = ReadNumber("Please enter your month : ");
	//int day = ReadNumber("Please enter your day : ");
	//cout << "\nfull date : " << day << "/" << month << "/" << year << endl;
	//cout << "Name of day in month [" << month << "] " << "in year [" << year << "] " << "in day [" << day << "] : " << NameOfDay(year,month,day) << endl;

	// Problem 8
	//int year = ReadNumber("Please enter your year : ");
	//int month = ReadNumber("Please enter your month : ");
	//printCalendar(year, month);

	// Problem 9
	//int year = ReadNumber("Please enter your year : ");
	//printCalendarOfAllYear(year);

	// Problem 10
	int year = ReadNumber("Please enter your year : ");
	int month = ReadNumber("Please enter your month : ");
	int day = ReadNumber("Please enter your day : ");
	cout << "\nfull date : " << day << "/" << month << "/" << year << endl;
	cout << "Number of days to this date : " << NumberOfDaysFromTheBeginingOfTheYear(year, month, day);
}

void SecondTenProblems()
{
	// Problem 11
	//sDate FDate=  FullDateByYearAndNumberOfDays(2022, 263);
	//cout << "\nfull date : " << FDate.Day << "/" << FDate.Month << "/" << FDate.Year << endl;

	// Problem 12
	//sDate FDate;
	//FDate.Day = 10;
	//FDate.Month = 11;
	//FDate.Year = 2022;
	//FDate= AddDaysToDate(FDate, 150);
	//cout << "\nfull date : " << FDate.Day << "/" << FDate.Month << "/" << FDate.Year << endl;

	//sDate DateOne = ReadFullDate();
	//sDate DateTwo = ReadFullDate();

	// Problem 13
	//cout << "full date of date one : " << DateOne.Day << "/" << DateOne.Month << "/" << DateOne.Year << endl;
	//cout << "full date of date two : " << DateTwo.Day << "/" << DateTwo.Month << "/" << DateTwo.Year << endl;
	//cout << CompareToDates(DateOne, DateTwo) << endl;

	// Problem 14
	//cout << "full date of date one : " << DateOne.Day << "/" << DateOne.Month << "/" << DateOne.Year << endl;
	//cout << "full date of date two : " << DateTwo.Day << "/" << DateTwo.Month << "/" << DateTwo.Year << endl;
	//cout << "is date one equals date two : " << isDateOneEqualsDateTwo(DateOne,DateTwo) << endl;

	// Problem 15
	// Is solved but not use

	// Problem 16
	//cout << "full date of date one : " << DateOne.Day << "/" << DateOne.Month << "/" << DateOne.Year << endl;
	//sDate DateAfterIncrease = IncreateDateByOneDay(DateOne);
	//cout << "full date of date one : " << DateAfterIncrease.Day << "/" << DateAfterIncrease.Month << "/" << DateAfterIncrease.Year << endl;

	// Problem 17
	//sDate DateOne = ReadFullDate();
	//sDate DateTwo = ReadFullDate();
	//cout << "Difference between this two dates is : " << DiffBetweenTwoDates(DateOne, DateTwo) << endl;
	//cout << "Difference between this two dates is (include last day) : " << DiffBetweenTwoDates(DateOne, DateTwo, true) << endl;

	// Problem 18
	//cout << "Enter your birth date" << endl;
	//sDate birthDate = ReadFullDate();
	//cout << "Your age is : " << AgeInDays(birthDate) << " Day(s)" << endl;

	// Problem 19
	sDate DateOne = ReadFullDate();
	sDate DateTwo = ReadFullDate();
	cout << "Difference between this two dates is : " << GetDifferenceInDays(DateOne, DateTwo) << endl;
	cout << "Difference between this two dates is (include last day) : " << GetDifferenceInDays(DateOne, DateTwo, true) << endl;

}

void ProblemsFrom20To32()
{
	sDate Date1 = ReadFullDate();

	cout << "\nDate After: \n";

	Date1 = IncreaseDateByOneDay(Date1);
	cout << "\n01-Adding one day is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDays(10, Date1);
	cout << "\n02-Adding 10 days is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneWeek(Date1);
	cout << "\n03-Adding one week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXWeeks(10, Date1);
	cout << "\n04-Adding 10 weeks is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMonth(Date1);
	cout << "\n05-Adding one month is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXMonths(5, Date1);
	cout << "\n06-Adding 5 months is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneYear(Date1);
	cout << "\n07-Adding one year is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYears(10, Date1);
	cout << "\n08-Adding 10 Years is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Adding 10 Years (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneDecade(Date1);
	cout << "\n10-Adding one Decade is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = IncreaseDateByXDecades(10, Date1);
	cout << "\n11-Adding 10 Decades is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Adding 10 Decade (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding One Century is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMillennium(Date1);
	cout << "\n14-Adding One Millennium is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;


	system("pause>0");
}

void ProblemsFrom33To46()
{
	sDate Date1 = ReadFullDate();
	cout << "\nDate After: \n";

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n01-Subtracting one day is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDays(10, Date1);
	cout << "\n02-Subtracting 10 days is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting one week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXWeeks(10, Date1);
	cout << "\n04-Subtracting 10 weeks is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting one month is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXMonths(5, Date1);
	cout << "\n06-Subtracting 5 months is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "\n07-Subtracting one year is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYears(10, Date1);
	cout << "\n08-Subtracting 10 Years is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Subtracting 10 Years (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting one Decade is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecades(10, Date1);
	cout << "\n11-Subtracting 10 Decades is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Subtracting 10 Decade (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting One Century is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Subtracting One Millennium is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
}

void ProblemsFrom47To53()
{
	sDate Date1 = GetSystemDate();

	// 1. طباعة اليوم والتاريخ
	cout << "\nToday is " << NameOfDay(Date1.Year, Date1.Month, Date1.Day) << " , " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << "\n\n";

	// 2. السؤال عن نهاية الأسبوع الإداري
	cout << "Is it End of Week?\n";
	cout << (IsEndOfTheWeek(Date1) ? "Yes it is end of week.\n\n" : "No Not end of week.\n\n");

	// 3. السؤال عن الـ Weekend
	cout << "Is it Weekend?\n";
	cout << (IsWeekend(Date1) ? "Yes it is a week end.\n\n" : "No it is NOT a week end.\n\n");

	// 4. السؤال عن يوم العمل
	cout << "Is it Business Day?\n";
	cout << (IsBusinessDay(Date1) ? "Yes it is a business day.\n\n" : "No it is NOT a business day.\n\n");

	// 5. طباعة الأيام المتبقية (لنهاية الأسبوع، الشهر، السنة)
	cout << "Days until end of week : " << DaysUntilTheEndOfWeek(Date1) << " Day(s).\n";
	cout << "Days until end of month : " << DaysUntilTheEndOfMonth(Date1) << " Day(s).\n";
	cout << "Days until end of year : " << DaysUntilTheEndOfYear(Date1) << " Day(s).\n";
}

void Problem54()
{
	cout << "Vacation Starts :" << endl;
	sDate StartVacationDate = ReadFullDate();
	cout << "Vacation Ends :" << endl;
	sDate EndVacationDate = ReadFullDate();

	cout << "\nVaction From: " <<
		NameOfDay(StartVacationDate.Year, StartVacationDate.Month, StartVacationDate.Day) << " , "
		<< StartVacationDate.Day << "/" << StartVacationDate.Month << "/" <<
		StartVacationDate.Year << endl;

	cout << "Vaction To: " << NameOfDay(EndVacationDate.Year, EndVacationDate.Month, EndVacationDate.Day)
		<< " , "
		<< EndVacationDate.Day << "/" << EndVacationDate.Month << "/" << EndVacationDate.Year
		<< endl;
	cout << "\n\nActucal Vacation Days is: " <<
		CalculateVacationDays(StartVacationDate, EndVacationDate);

	system("pause>0");

}

void Problem55()
{
	cout << "Vacation Starts :" << endl;
	sDate StartVacationDate = ReadFullDate();
	cout << "Number of vacation days :" << endl;
	int VacationDays = ReadNumber("Pleasse enter number of vacation days : ");

	sDate EndVacationDate = CalculateTheEndOfVacation(StartVacationDate, VacationDays);

	cout << "\nVaction From: " <<
		NameOfDay(StartVacationDate.Year, StartVacationDate.Month, StartVacationDate.Day) << " , "
		<< StartVacationDate.Day << "/" << StartVacationDate.Month << "/" <<
		StartVacationDate.Year << endl;

	cout << "Actucal Vacation Days is: " <<
		VacationDays;

	cout << "\nReturn Date: " << NameOfDay(EndVacationDate.Year, EndVacationDate.Month, EndVacationDate.Day)
		<< " , "
		<< EndVacationDate.Day << "/" << EndVacationDate.Month << "/" << EndVacationDate.Year
		<< endl;
	system("pause>0");

}

void Problem56()
{
	cout << "\nEnter Date1:";
	sDate Date1 = ReadFullDate();
	
	cout << "\nEnter Date2:";
	sDate Date2 = ReadFullDate();
	
	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\nYes, Date1 is After Date2.";
	else
		cout << "\nNo, Date1 is NOT After Date2.";
	
	system("pause>0");

}

void Problem57()
{
	cout << "\nEnter Date1:";
	sDate Date1 = ReadFullDate();
	cout << "\nEnter Date2:";
	sDate Date2 = ReadFullDate();
	cout << "\nCompare Result = " << CompareDates(Date1, Date2);
	system("pause>0");

}

void Problem58()
{
	cout << "\nEnter Period 1:";
	stPeriod Period1 = ReadPeriod();
	cout << "\nEnter Period 2:";
	stPeriod Period2 = ReadPeriod();
	if (IsOverlapPeriods(Period1, Period2))
		cout << "\nYes, Periods Overlap\n";
	else
		cout << "\nNo, Periods do not Overlap\n";
	system("pause>0");

}

void Problem59()
{
	cout << "\nEnter Period 1:";
	stPeriod Period1 = ReadPeriod();
	
	cout << "\nPeriod Length is: " << PeriodLengthInDays(Period1);
	cout << "\nPeriod Length (Including End Date) is: " <<
		PeriodLengthInDays(Period1, true);
	
	system("pause>0");
}

void Problem60()
{
	cout << "\nEnter Period :";
	stPeriod Period = ReadPeriod();

	cout << "\nEnter Date to check:\n";
	sDate Date = ReadFullDate();

	if (IsDateInPeriod(Date, Period))
		cout << "\nYes, Date is within period\n";
	else
		cout << "\nNo, Date is NOT within period\n";
	system("pause>0");
}

void Problem61()
{
	cout << "\nEnter Period 1 :";
	stPeriod Period1 = ReadPeriod();

	cout << "\nEnter Period 2 :";
	stPeriod Period2 = ReadPeriod();

	cout << "\nOverlap Days Count Is: " <<
		CountOverlapDays(Period1, Period2);
	
	system("pause>0");
}

void Problem62()
{
	sDate Date1 = ReadFullDate();

	if (IsValidDate(Date1))
		cout << "\nYes, Date is a valide date.\n";
	else
		cout << "\nNo, Date is a NOT valide date\n";
	
	system("pause>0");
}

void Problem63To64()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd / mm / yyyy ? ");

	sDate Date = StringToDate(DateString);
	cout << "\nDay:" << Date.Day << endl;
	cout << "Month:" << Date.Month << endl;
	cout << "Year:" << Date.Year << endl;
	cout << "\nYou Entered: " << DateToString(Date) << "\n";

	system("pause>0");
}

void Problem65()
{
	string DateString = ReadStringDate("\nPlease Enter Date (dd/mm/yyyy) ? ");
	sDate Date = StringToDate(DateString);

	cout << "\n" << FormateDate(Date) << "\n";
	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm,Year:yyyy") << "\n";

	system("pause>0");
}

int main()
{
	//FirstTenProblems();
	
	//SecondTenProblems();

	//ProblemsFrom20To32();

	//ProblemsFrom33To46();

	//ProblemsFrom47To53();

	//Problem54();

	//Problem55();

	//Problem56();

	//Problem57();
	
	//Problem58();

	//Problem59();

	//Problem60();

	//Problem61();

	//Problem62();

	//Problem63To64();

	Problem65();
}
