#include <iostream>
using namespace std;

int counter = 0;
int GCD (int x, int y) 
{
  int gcd;
  int num1 = x % y;
    
if (x % y == 0) 
{
    gcd = y;
    return gcd;
}
else 
{
    gcd = GCD(y, num1); 
    return  gcd;
}        
}

bool diophantine(int a, int b, int c, int &x, int &y) {
    int random;
    int tempVal;
    int r = a % b;
    random = GCD(a,b);
    int result = c % random;
    
    if (result != 0) 
    {
    return false;
    }
 
   if (a % b == 0) {
        x = 0;
        y = c/b;
        
        return true;
    }
    
    else { 
        counter = 1;
        diophantine(b,r,c,x,y);
    
    }
        if (counter >= 1) { 
            tempVal = x;
           x = y;
            y = tempVal - (a/b) *x;
        }
        return true;
}    
int main() {

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y) == true) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}