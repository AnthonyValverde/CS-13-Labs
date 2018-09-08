#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   Date();
   Date(unsigned m, unsigned d, unsigned y);


   Date(const string &mn, unsigned d, unsigned y);
   void printNumeric() const;
   void printAlpha() const;

 private:
   bool isLeap(unsigned y) const;

   unsigned daysPerMonth(unsigned m, unsigned y) const;

   string name(unsigned m) const;

   unsigned number(const string &mn) const;
};



Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   }
   else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } 
   else {
      return Date();
   }
}

Date::Date() {
   monthName = "January";
   month = 1;
   day = 1;
   year = 2000;
   return;
}

Date::Date(unsigned m, unsigned d, unsigned y) {
   unsigned tooLarge = 0;
   string monName;
   
   monName = name(m);
   monthName = monName;
   tooLarge = daysPerMonth(m, y);
   
   if (m > 12 && d <= 0) {
      cout << "Invalid date values: Date corrected to 12/1/" << y << "." << endl;
      d = 1;
      m = 12;
   }
   else if (m > 12 && d > tooLarge) {
      cout << "Invalid date values: Date corrected to 12/" << tooLarge << "/" << y << "." << endl;
      d = tooLarge;
      m = 12;
   }
   else if (m <= 0 && d <= 0) {
      cout << "Invalid date values: Date corrected to 1/1/" << y << "." << endl;
      d = 1;
      m = 1;
   }
   else if (m <= 0 && d > tooLarge) {
      cout << "Invalid date values: Date corrected to 1/31/" << y << "." << endl;
      d = 31;
      m = 1;
      monName = "January";
      monthName = monName;
   }
   else if (m > 12) {
      cout << "Invalid date values: Date corrected to 12/" << tooLarge << "/" << y << "." << endl;
      d = tooLarge;
      m = 12;
   }
   else if (d > tooLarge) {
      cout << "Invalid date values: Date corrected to " << m << "/" << tooLarge << "/" << y << "." << endl;
      d = tooLarge;
   }
   month = m;
   day = d;
   year = y;
   return;
}

Date::Date(const string& mn, unsigned d, unsigned y) {
   unsigned TooLarge = 0;
   unsigned numToSend = 0;
   unsigned test = 0;
   string toSend;
   
   if (mn == "January" || mn == "january") {
      toSend = "January";
      test = 1;
   }
   else if (mn == "February" || mn == "february") {
      toSend = "February";
      test = 1;
   }
   else if (mn == "March" || mn == "march") {
      toSend = "March";
      test = 1;
   }
   else if (mn == "April" || mn == "april") {
      toSend = "April";
      test = 1;
   }
   else if (mn == "May" || mn == "may") {
      toSend = "May";
      test = 1;
   }
   else if (mn == "June" || mn == "june") {
      toSend = "June";
      test = 1;
   }
   else if (mn == "July" || mn == "july") {
      toSend = "July";
      test = 1;
   }
   else if (mn == "August" || mn == "august") {
      toSend = "August";
      test = 1;
   }
   else if (mn == "September" || mn == "september") {
      toSend = "September";
      test = 1;
   }
   else if (mn == "October" || mn == "october") {
      toSend = "October";
      test = 1;
   }
   else if (mn == "November" || mn == "november") {
      toSend = "November";
      test = 1;
   }
   else if (mn == "December" || mn == "december") {
      toSend = "December";
      test = 1;
   }
   else if (test == 0) {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      toSend = "January";
      month = 1;
      day = 1;
      year = 2000;
      monthName = toSend;
      return;
   }
   monthName = toSend;
   numToSend = number(monthName);
   TooLarge = daysPerMonth(numToSend, y);
   month = numToSend;
   
   if (d > TooLarge) {
      d = TooLarge;
      day = d;
      cout << "Invalid date values: Date corrected to " << month << "/" << TooLarge << "/" << y << "." << endl;
   }
   else if (d <= 0) {
      d = 1;
      day = d;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << y << "." << endl;
   }
   else { 
      day = TooLarge;
   }
   year = y;
}

void Date::printNumeric() const {
   cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const {
   cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const {
   if (y % 400 == 0 || y % 4 == 0) {
      if (y % 100 == 0) {
         if (y % 400 == 0) {
         return true;
         }
         else {
         return false;
         }
      }
      return true;
   }
   return false;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   if (m == 1) {
      return 31;
   }
   else if (m == 2) {
      if (isLeap(y) == true) {
         return 29;
      }
      else {
         return 28;
      }
   }
   else if (m == 3) {
      return 31;
   }
   else if (m == 4) {
      return 30;
   }
   else if (m == 5) {
      return 31;
   }
   else if (m == 6) {
      return 30;
   }
   else if (m == 7) {
      return 31;
   }
   else if (m == 8) {
      return 31;
   }
   else if (m == 9) {
      return 30;
   }
   else if (m == 10) {
      return 31;
   }
   else if (m == 11) {
      return 30;
   }
   else if (m == 12) {
      return 31;
   }
   return 1;
}
unsigned Date::number(const string &mn) const {
   if (mn == "January" || mn == "january") {
      return 1;
   }
   else if (mn == "February" || mn == "february") {
      return 2;
   }
   else if (mn == "March" || mn == "march") {
      return 3;
   }
   else if (mn == "April" || mn == "april") {
      return 4;
   }
   else if (mn == "May" || mn == "may") {
      return 5;
   }
   else if (mn == "June" || mn == "june") {
      return 6;
   }
   else if (mn == "July" || mn == "july") {
      return 7;
   }
   else if (mn == "August" || mn == "august") {
      return 8;
   }
   else if (mn == "September" || mn == "september") {
      return 9;
   }
   else if (mn == "October" || mn == "october") {
      return 10;
   }
   else if (mn == "November" || mn == "november") {
      return 11;
   }
   else if (mn == "December" || mn == "december") {
      return 12;
   }
   return 0;
}



string Date::name(unsigned m) const {
   string goBack;
   
   if (m == 1) {
      goBack = "January";
   }
   else if (m == 2) {
      goBack = "February";
   }
   else if (m == 3) {
      goBack = "March";
   }
   else if (m == 4) {
      goBack = "April";
   }
   else if (m == 5) {
      goBack = "May";
   }
   else if (m == 6) {
      goBack = "June";
   }
   else if (m == 7) {
      goBack = "July";
   }
   else if (m == 8) {
      goBack = "August";
   }
   else if (m == 9) {
      goBack = "September";
   }
   else if (m == 10) {
      goBack = "October";
   }
   else if (m == 11) {
      goBack = "November";
   }
   else if (m >= 12) {
      goBack = "December";
   }
   return goBack;
}

