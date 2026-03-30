#include "triangle.h"

int main() {
    Point A, B, C;

    cout << "A (x y): ";
    cin >> A.x >> A.y;

    cout << "B (x y): ";
    cin >> B.x >> B.y;

    cout << "C (x y): ";
    cin >> C.x >> C.y;

    if (isDegenerate(A, B, C)) {
        cout << "Triangle is degenerate\n";
        return 0;
    }

    cout << "\nArea (Heron) = " << heron(A, B, C) << endl;
    cout << "Area (Gauss) = " << gauss(A, B, C) << endl;

    int n;
    cout << "How many points: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point P;
        cout << "Point (x y): ";
        cin >> P.x >> P.y;

        int res = checkPoint(A, B, C, P);

        if (res == 1)
            cout << "Inside\n";
        else if (res == 2)
            cout << "On border\n";
        else
            cout << "Outside\n";
    }

    return 0;
}
