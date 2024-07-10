#ifndef FUNCTIONS_H


inline std::string Calander(std::string inputDate) {
	std::string month;
	std::string days;
	std::string year;

	// seperates the inputted date into month, days, and year
	for (int i = 0; i < inputDate.size(); i++) {
		if (inputDate.at(i) != '/') {
			if ((i == 0 || i == 1)) { //i of 0 or 1 is the possibilites for the month. Shouldnt trigger if the char is /
				month.push_back(inputDate.at(i));
			}
			else if (month.size() == 1) { // month is one char 1/...
				if ((i == 2 || i == 3)) {
					days.push_back(inputDate.at(i));
				}
				else {
					year.push_back(inputDate.at(i));
				}
			}
			else { // month is two chars 10/...
				if ((i == 3 || i == 4)) {
					days.push_back(inputDate.at(i));
				}
				else {
					year.push_back(inputDate.at(i));
				}
			}
		}
	}

	if (month.size() == 1) {
		month = "0" + month;
	}
	if (days.size() == 1) {
		days = "0" + days;
	}

	return month + days + year;
}

inline int NumberOfDays(int monthNumber, int year)
{
	// January
	if (monthNumber == 1) {
		return (31);
	}

	// February
	else if (monthNumber == 2)
	{
		// If the year is leap then February has
		// 29 days
		if (year % 400 == 0 ||
			(year % 4 == 0 && year % 100 != 0))
			return (29);
		else
			return (28);
	}

	// March
	else if (monthNumber == 3) {
		return (31);
	}

	// April
	else if (monthNumber == 4) {
		return (30);
	}

	// May
	else if (monthNumber == 5) {
		return (31);
	}

	// June
	else if (monthNumber == 6) {
		return (30);
	}

	// July
	else if (monthNumber == 7) {
		return (31);
	}

	// August
	else if (monthNumber == 8) {
		return (31);
	}

	// September
	else if (monthNumber == 9) {
		return (30);
	}

	// October
	else if (monthNumber == 10) {
		return (31);
	}

	// November
	else if (monthNumber == 11)
		return (30);

	// December
	else if (monthNumber == 12) {
		return (31);
	}

	return -1;
}

// adds the days to the date
// wouldve solved recursivly, but will not be possible to get a book for over 14 days
// cannot spill over more than one month
// so it would be unnecessary
inline std::string DateAfterChange(std::string date, int daysToAdd) {
	int month = std::stoi(date.substr(0, 2));
	int days = std::stoi(date.substr(2, 2));
	int year = std::stoi(date.substr(4, 2));

	int daysInMonth = NumberOfDays(month, 2000 + year); // gets the days in the current month
	//returns nothing if there is no days to add
	if (daysToAdd == 0) {
		return date;
	}
	if (daysToAdd > 0) {
		if (daysToAdd + days > daysInMonth) { // if there are more days to be added then days left in the month
			if (month < 12) { // checking it isnt december (then goes to new year)

				int monthInt = month + 1; // adds one to the month
				month = monthInt;

				daysToAdd = daysToAdd + days - daysInMonth;
				days = daysToAdd;
			}
			else { // month is december, goes to new year
				month = 1;
				int YearInt = year + 1; // adds one to the year
				year = YearInt;
				daysToAdd = daysToAdd + days - daysInMonth;
				days = daysToAdd;
			}
		}
		else {
			days += daysToAdd;
		}
	}
	else {
		days -= daysToAdd;
		if (days < 0) {
			month -= 1;
			if (month == 0) {
				month = 12;
				year -= 1;
			}
			days = NumberOfDays(month, 2000 + year) - days;
		}
	}
	date = std::to_string(month) + "/" + std::to_string(days) + "/" + std::to_string(year);

	return date;
}

inline int DateToInt(std::string date) {
	date = Calander(date);
	int months = (date[0] + date[1]) * 100; // assigns a value of 100 to each month
	int days = (date[2] + date[3]); //assigns a value of 1 to each day
	int years = (date[4] + date[5]) * 10000; //assigns a value of 10000 to each year
	return days + months + years;
}

#endif !FUNCTIONS_H