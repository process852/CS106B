/*
Extend the calendar.h interface from Chapter 2, exercise 11 so that it also 
exports a Date class that exports the following methods:
• A default constructor that sets the date to January 1, 1900.
• A constructor that takes a month, day, and year and initializes the Date to 
contain those values. For example, the declaration
Date moonLanding(JULY, 20, 1969);
should initialize moonLanding so that it represents July 20, 1969.
An overloaded version of the constructor that takes the first two parameters 
in the opposite order, for the benefit of clients in other parts of the world. 
This change allows the declaration of moonLanding to be written as
Date moonLanding(20, JULY, 1969);
• The getter methods getDay, getMonth, and getYear.
• A toString method that returns the date in the form dd-mmm-yyyy,
where dd is a one- or two-digit date, mmm is the three-letter English 
abbreviation for the month, and yyyy is the four-digit year. Thus, calling 
toString(moonLanding) should return the string "20-Jul-1969".
*/
#include <iostream>
#include <string>
#include <cctype>
#include <map>

using namespace std;


const map<string, int> Month{
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"October", 10},
    {"November", 11},
    {"December", 12},
};


class Date{
public:
    Date(){
        this->day = 1;
        this->month = "January";
        this->year = 1900;
    }
    Date(string monthArg, int dayArg, int yearArg){
        day = dayArg;
        month = this->capitialLetter(monthArg);
        year = yearArg;
    }
    Date(int dayArg, string monthArg, int yearArg){
        day = dayArg;
        month = this->capitialLetter(monthArg);
        year = yearArg;
    }
    string capitialLetter(string str){
        for(int i = 0; i < str.length(); i++){
            if(i == 0)
                str[i] = toupper(str[i]);
            else
                str[i] = tolower(str[i]);
        }
        return str;
    }
    string getMonth(){
        return this->month;
    }
    int getDay(){
        return this->day;
    }
    int getYear(){
        return this->year;
    }
    string toString(){
        string shortMonth;
        if(month.length() <= 3){
            shortMonth = month;
        }
        else{
            shortMonth = month.substr(0, 3);
            shortMonth[0] = toupper(shortMonth[0]);
        }
        return to_string(day) + string("-") + shortMonth + 
                string("-") + to_string(year);
    }
    friend ostream& operator<<(ostream& output, Date& d);
    bool operator==(const Date& other){
        if(other.day == day && other.month == month && year == other.year)
            return true;
        return false;
    }
    bool operator!=(const Date& other){
        return !(*this == other);
    }
    bool operator<(const Date& other){
        if(year < other.year){
            return true;
        }
        else if (year == other.year){
            if(Month.at(month) < Month.at(other.month)){
                return true;
            }
            else if(Month.at(month) == Month.at(other.month)){
                if (day < other.day) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
    bool operator>=(const Date& other){
        return !(*this < other);
    }
    bool operator>(const Date& other){
        if(*this == other) return false;
        return !(*this < other);
    }
    bool operator<=(const Date& other){
        return !(*this > other);
    }

private:
    int day;
    string month;
    int year;
};

ostream& operator<<(ostream& output, Date& d){
    output << d.toString() << endl;
    return output;
}

void test(){
    Date moonLanding(20, "JULY", 1969);
    Date electionDay(6, "NOVEMBER", 2012);
    Date inaugurationDay(21, "JANUARY", 2013);
    cout << moonLanding.getDay() << moonLanding.getMonth() << moonLanding.getYear() << endl;
    cout << moonLanding.toString() << endl;
    cout << moonLanding << endl;
    cout << (electionDay == inaugurationDay) << endl;
    cout << (electionDay != inaugurationDay) << endl;
    cout << (electionDay < inaugurationDay) << endl;
    cout << (electionDay >= inaugurationDay) << endl;
    cout << (electionDay > inaugurationDay) << endl;
    cout << (electionDay <= inaugurationDay) << endl;

}

int main(){
    test();
    return 0;
}