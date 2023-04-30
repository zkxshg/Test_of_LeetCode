#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <climits>
#include <utility> 
#include <iomanip>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

#define MaxValue 9999999

int gcd(int m, int n) {
    int t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

int lcm(int m, int n) {
    return m * n / gcd(m, n);
}

double pDist(int x1, int y1, int x2, int y2) {
    double distance = 0;
    distance = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
    return distance;
}

double get_angle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double theta = atan2(x1 - x3, y1 - y3) - atan2(x2 - x3, y2 - y3);

    if (theta > M_PI) theta -= 2 * M_PI;

    if (theta < -M_PI) theta += 2 * M_PI;

    theta = abs(theta * 180.0 / M_PI);
    return theta;
}

pair<double, double> get_CircleCenter(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a, b, c, d, e, f, x, y;
    a = 2 * (x2 - x1);
    b = 2 * (y2 - y1);
    c = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;
    d = 2 * (x3 - x2);
    e = 2 * (y3 - y2);
    f = x3 * x3 + y3 * y3 - x2 * x2 - y2 * y2;
    x = (b * f - e * c) / (b * d - e * a);
    y = (d * c - a * f) / (b * d - e * a);
    // cout << "圆心为(" << x << "," << y << ")" << endl;
    return make_pair(x, y);
}

int main() {
    double area = 0;

    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // 求边长
    double a = pDist(x1, y1, x2, y2);
    double b = pDist(x1, y1, x3, y3);
    double c = pDist(x3, y3, x2, y2);

    // 求圆心
    pair<double, double> CC = get_CircleCenter(x1, y1, x2, y2, x3, y3);
    double x0 = CC.first, y0 = CC.second;
    double r = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)); // 半径

    // 求弧度
    double ang1, ang2, ang3;
    ang1 = get_angle(x1, y1, x2, y2, x0, y0); 
    ang2 = get_angle(x2, y2, x3, y3, x0, y0); 
    ang3 = get_angle(x1, y1, x3, y3, x0, y0); 
    //cout << ang1 << ", " << ang2 << ", " << ang3 << endl;

    double angleP = ang1;
    while (abs(angleP - ang2) > 0.01) {
        if (ang2 > angleP) ang2 -= angleP;
        else angleP -= ang2;
    }
    while (abs(angleP - ang3) > 0.01) {
        if (ang3 > angleP) ang3 -= angleP;
        else angleP -= ang3;
    }

    // 求最小公倍数 -> 边数
    double angle = 360 / angleP; // cout << angle << ",";

    if (abs(angle - round(angle)) > 0.1) {
        int mul = 1;
        while (abs(mul * angle - round(mul * angle)) > 0.001) mul++;
        angle *= mul;
    }

    // 面积 = 边数 * (r * cos * r * sin)
    // area = angle * r * cos(M_PI / angle) * (r * sin(M_PI / angle));
    area = angle / 2 * r * r * sin(2 * M_PI / angle);
    
    cout << setprecision(8) << area << endl;

    return 0;
}