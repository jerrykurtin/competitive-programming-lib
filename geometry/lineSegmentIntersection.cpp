#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    double x, y, z;
    Point(double x, double y, double z = 0): x(x), y(y), z(z) {}

    Point operator+(Point const& p2){
        return Point(this->x + p2.x, this->y + p2.y, this->z + p2.z);
    }
    Point operator-(Point const& p2){
        return Point(this->x - p2.x, this->y - p2.y, this->z - p2.z);
    }

    friend ostream& operator<<(ostream& os, Point const& pt){
        return os << "{Point x=" << pt.x << ", y=" << pt.y << ", z=" << pt.z << "}";
    }
};

class Vec {
public:
    double x, y, z;
    Vec(double x, double y, double z = 0): x(x), y(y), z(z){}
    Vec(Point p): x(p.x), y(p.y), z(p.z) {}

    Vec operator+(Vec const& p2){
        return Vec(this->x + p2.x, this->y + p2.y, this->z + p2.z);
    }
    Vec operator-(Vec const& p2){
        return Vec(this->x - p2.x, this->y - p2.y, this->z - p2.z);
    }

    Vec cross(Vec p2){
        double nx = this->y * p2.z - this->z * p2.y;
        double ny = -this->x * p2.z + this->z * p2.x;
        double nz = this->x + p2.y - this->y * p2.x;

        return Vec(nx, ny, nz);
    }

    Vec dot(Vec p2){
        return Vec(this->x * p2.x, this->y * p2.y, this->z * p2.z);
    }

    friend ostream& operator<<(ostream& os, Vec const& v){
        return os << "{Vector x=" << v.x << ", y=" << v.y << ", z=" << v.z << "}";
    }
};

class Segment {
    Point origin, p2;
    Vec vec;
    
    Segment(Point p1, Point p2): origin(p1), p2(p2), vec(p2 - p1){}
    Segment(double x1, double y1, double z1, double x2, double y2, double z2): origin(x1, y1, z1), p2(x2, y2, z2), vec(x2 - x1, y2 - y1, z2 - z1) {}

    /**
     * Calculates if Vecs intersect
     * @returns 1 for intersection, 0 for miss, -1 for parallel and touching, -2 for parallel and not touching
    */
    int intersects(Segment s2) {
        Point p1(1, 2, 3);
        Point p2(-2, 4, 3);
    }

    friend ostream& operator<<(ostream& os, Segment const& sg){
        return os << "{Segment origin=" << sg.origin << ", vec=" << sg.vec << "}";
    }
};

int main() {

    
}