#include <bits/stdc++.h>
using namespace std;

class Vec {
public:
    double x, y, z;
    Vec(double x, double y, double z = 0): x(x), y(y), z(z){}

    Vec operator+(Vec const& v2){
        return Vec(this->x + v2.x, this->y + v2.y, this->z + v2.z);
    }
    Vec operator-(Vec const& v2){
        return Vec(this->x - v2.x, this->y - v2.y, this->z - v2.z);
    }

    /**
     * Perform the 3d cross product
    */
    Vec cross(Vec p2) const{
        double nx = this->y * p2.z - this->z * p2.y;
        double ny = -this->x * p2.z + this->z * p2.x;
        double nz = this->x * p2.y - this->y * p2.x;

        return Vec(nx, ny, nz);
    }

    /**
     * Perform the 3d dot product
    */
    double dot(Vec p2) const{
        return this->x * p2.x + this->y * p2.y + this->z * p2.z;
    }

    

    double magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    /**
     * Calculate the angle between two vectors in radians
    */
    friend double angle(const Vec v1, const Vec v2) {
        if (v1.magnitude() == 0 || v2.magnitude() == 0){
            return 0;
        }
        return acos(v1.dot(v2) / (v1.magnitude() * v2.magnitude()));
    }

    friend ostream& operator<<(ostream& os, Vec const& v){
        return os << "{Vector x=" << v.x << ", y=" << v.y << ", z=" << v.z << ", magnitude=" << v.magnitude() << "}";
    }
};

class Point {
public:
    double x, y, z;
    Point(double x, double y, double z = 0): x(x), y(y), z(z) {}

    Vec minus(Point p2){
        return Vec(this->x - p2.x, this->y - p2.y, this->z - p2.z);
    }
    Vec plus(Point p2){
        return Vec(this->x + p2.x, this->y + p2.y, this->z + p2.z);
    }

    friend ostream& operator<<(ostream& os, Point const& pt){
        return os << "{Point x=" << pt.x << ", y=" << pt.y << ", z=" << pt.z << "}";
    }

};


class Segment {
public:
    Point origin, p2;
    Vec vec;
    
    Segment(Point p1, Point p2): origin(p1), p2(p2), vec(p2.minus(p1)){}
    Segment(double x1,  double y1,  double x2, double y2, double z1 = 0, double z2 = 0): origin(x1, y1, z1), p2(x2, y2, z2), vec(x2 - x1, y2 - y1, z2 - z1) {}

    /**
     * Calculates if Vecs intersect (2 dimensions)
     * @returns 1 if intersecting, 0 if collinear, -1 if intersecting outside of segment
    */
    int intersects2d(Segment s2) {
        Point p1(1, 2, 3);
        Point p2(-2, 4, 3);

        if (this->vec.cross(s2.vec).magnitude() == 0){
            return 0;
        }


        double t = s2.origin.minus(this->origin).cross(s2.vec).z / (this->vec.cross(s2.vec)).z;
        double u = s2.origin.minus(this->origin).cross(this->vec).z / (this->vec.cross(s2.vec)).z;

        if (0 <= t && t <= 1 && 0 <= u && u <= 1){
            return 1;
        }
        else {
            return -1;
        }
    }

    friend ostream& operator<<(ostream& os, Segment const& sg){
        return os << "{Segment origin=" << sg.origin << ", vec=" << sg.vec << "}";
    }
};

int main() {

    Point p1(1, 2), p2(-2, 4), p3(-2, 0), p4(4, 2), p5(-3, 0), p6(1, 3), p7(5, -1), p8(2, 1), p9(-3, 2);
    Segment s1(p1, p2), s2(p3, p4), s3(p5, p6), s4(p7, p8), s5(p9, p1);


    // cross products
    Vec v1(2, 0), v2(0, 2), v3(4, 3), v4(2, 2), v5(2, 1), v6(-1, 2);
    assert(v1.cross(v2).magnitude() == 4);
    assert(v2.cross(v1).z == -4);
    assert(v2.cross(v1).magnitude() == 4);
    assert(v1.cross(v3).magnitude() == 6);


    // intersections
    assert(s1.intersects2d(s2) == -1);
    assert(s1.intersects2d(s3) == 1);
    assert(s1.intersects2d(s4) == 0);
    assert(s1.intersects2d(s5) == 1);


    // angles
    assert(angle(v1, v2) == M_PI/2);
    assert(angle(v2, v1) == M_PI/2);
    assert(angle(v5, v6) == M_PI/2);
    assert(angle(v6, v5) == M_PI/2);
    assert((int) (angle(v1, v4) * 1000) == (int) (M_PI/4 * 1000));
    assert((int) (angle(v4, v1) * 1000) == (int) (M_PI/4 * 1000));
}