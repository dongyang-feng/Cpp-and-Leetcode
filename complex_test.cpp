#include<iostream>
#include"complex.h"

using namespace std;


int main()
{
    complex c1(9, 8);
    double c = 3;
    cout << c+c1 << endl;
    cout << conj(c1) << endl;
    return 0;
    
}
