#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

int exitfunction() {
    return 1;
}
void readData(const string &filename, vector<double> &fpAngles, vector<double> &coLift) {
    double num;
    ifstream inFS;  
    inFS.open(filename.c_str());
    
    if (!inFS.is_open()) {
     cout << "Could not open file " << filename << ".txt." << endl;      
     exitfunction ();
     }
     
    while(!inFS.eof()) 
    {
    inFS >> num;
    if(inFS.good()) 
    {
    fpAngles.push_back(num);
    }
    inFS >> num;
    if(inFS.good()) 
    {
    coLift.push_back(num);
    }
    }
     inFS.close();
   return;
}
double interpolation(double flightAngle, const vector<double> &fpAngles, const vector<double> &coLift) {
    int i;
    double num;
    for(i = 0; i < fpAngles.size(); ++i) {
        if (fpAngles.at(i) == flightAngle) {
            return coLift.at(i);
        }
    }
    for (i = 0; i < fpAngles.size(); ++i) {
    if ((flightAngle > fpAngles.at(i)) && (flightAngle < fpAngles.at(i +1))) {
    num = coLift.at(i)  + (coLift.at(i +1) - coLift.at(i)) * ( (flightAngle - fpAngles.at(i)) / (fpAngles.at(i+1) - fpAngles.at(i)));  
    return num;
    }
    }
    }
bool isOrdered(const vector<double> &fpAngles) {
    int i = 0;
    if (fpAngles.size() == 0 || fpAngles.size() == 1) {
        return true;
    }
    for (i = 1; i < fpAngles.size(); ++i) {
        if (fpAngles.at(i-1) > fpAngles.at(i)) {
            return false;
        }
        }
        return true;
    }

void reorder(vector<double> &fpAngles, vector<double> &coLift) {
    sort(fpAngles.begin(), fpAngles.end());
    sort(coLift.begin(), coLift.end());
}
int main () {
    string filename;
    double flightAngle;
    ifstream inFS;   
    vector<double> fpAngles;
    vector<double> coLift;
    double number;
    cin >> filename;
    readData(filename,fpAngles,coLift);
    
   isOrdered(fpAngles);
     if (isOrdered == false) 
    {
    reorder(fpAngles, coLift);
    }
    cin >> flightAngle;
    
    
    if ((flightAngle >= fpAngles.at(0)) && (flightAngle <= fpAngles.at(fpAngles.size()-1))) {
    number = interpolation(flightAngle, fpAngles, coLift);
    cout << number;
    }
    
    return 0;
}
