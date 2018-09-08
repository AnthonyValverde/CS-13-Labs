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
   Date::Date () {
      int day = 1;
      string month = "January";
      int year = 2000;
      return;
   }
   Date::Date(int m, int d, int y) { 
         int m = m;
         int d = d;
         int y = y;
         if (m > 12 || d > 31) {
             m = 12;
            d = 31;
            cout << "Invalid date values: Date corrected to 12/31/" << y << "." << endl;
         }
         if (m < 1|| d < 1) {
            m = 1;
            d = 1;
            cout << "Invalid date values: Date corrected to 1/1/" << y << "." << endl;
         }
         return;
   }
   
   Date::Date(const string &mn, unsigned int d, int unsigned y) {
   vector<string> v (24) {
           v.at(0) = "january";
           v.at(1) = "february";
           v.at(2) = "march";'
           v.at(3) = "april";
           v.at(4) = "may";
           v.at(5) = "june";
           v.at(6) = "july";
           v.at(7) = "august";
           v.at(8) = "september";
           v.at(9) = "october";
           v.at(10) = "november";
           v.at(11) = "december";
           v.at(12) = "January";
           v.at(13) = "February";
           v.at(14) = "March";'
           v.at(15) = "April";
           v.at(16) = "May";
           v.at(17) = "June";
           v.at(18) = "July";
           v.at(19) = "August";
           v.at(20) = "September";
           v.at(21) = "October";
           v.at(22) = "November";
           v.at(23) = "December";
        } 
         for (i = 0; i <=23; ++i) {
            if (m != v.at(i)) {
               cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
               Date();
            }
         }
          if (m > 12 || d > 31) {
             m = 12;
            d = 31;
            cout << "Invalid date values: Date corrected to 12/31/" << y << "." << endl;
         }
         if (m < 1|| d < 1) {
            m = 1;
            d = 1;
            cout << "Invalid date values: Date corrected to 1/1/" << y << "." << endl;
         }
}
   void printNumeric() const {
      cout << m << "/" << d << "/" << y;
   return;
   }
   void printAlpha() const {
      vector<string> (12);
      v.at(0) = "January";
      v.at(1) = "February";
      v.at(2) = "March";'
      v.at(3) = "April";
      v.at(4) = "May";
      v.at(5) = "June";
      v.at(6) = "July";
      v.at(7) = "August";
      v.at(8) = "September";
      v.at(9) = "October";
      v.at(10) = "November";
      v.at(11) = "December";
      cout << v.at(m) << " " << d << ", " << y;
      return;
   }
 private:
   bool isLeap(unsigned y) const;
   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const () {
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

   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-­leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;
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
   } else if (choice == 2) {
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
   } else {
      return Date();
   }
}
