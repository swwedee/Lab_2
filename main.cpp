#include <iostream>
#include "triangle.h"

using namespace std;

int main()
{
    Point A,B,C,P;

    cout << "Enter triangle:\n";

    cout << "A (x y): ";
    cin >> A.x >> A.y;

    cout << "B (x y): ";
    cin >> B.x >> B.y;

    cout << "C (x y): ";
    cin >> C.x >> C.y;

   
    double S1 = heronArea(A,B,C);
    cout << "Area (Heron) = " << S1 << endl;

    
    double S2 = gaussArea(A,B,C);
    cout << "Area (Gauss) = " << S2 << endl;

    
    if(degenerate(A,B,C))
    {
        cout << "Triangle is degenerate\n";
        return 0;
    }

    int n;
    cout << "How many points: ";
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cout << "Point (x y): ";
        cin >> P.x >> P.y;

        int r = checkPoint(A,B,C,P);

        if(r==1)
            cout << "Inside\n";
        else if(r==0)
            cout << "On border\n";
        else
            cout << "Outside\n";
    }

    return 0;
}
