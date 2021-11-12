#pragma once

class Date
{
private:
	unsigned year;
	unsigned month;
	unsigned day;
	unsigned hour;
	unsigned minute;
	unsigned second;
public:
	unsigned getYear() { return year; }
	void setYear(unsigned);
	unsigned getMonth() { return month; }
	void setMonth(unsigned);
	unsigned getDay() { return day; }
	void setDay(unsigned);
	unsigned getHour() { return hour; }
	void setHour(unsigned);
	unsigned getMinute() { return minute; }
	void setMinute(unsigned);
	unsigned getSecond() { return second; }
	void setSecond(unsigned);
};
