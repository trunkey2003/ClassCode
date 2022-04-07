#include <iostream>
#include "Triangle.cpp"
#include "Point.cpp"

using namespace std;

class Polygon{
private: 
    Point* points;
public:
    int length; //number of points

    ~Polygon(){
        delete points;
    }

    bool validated3Point(Point a, Point b, Point c){
        double x1 = b.getX() - a.getX(); //1
        double x2 = c.getX() - a.getX(); //2
        double y1 = b.getY() - a.getY(); // 1
        double y2 = c.getY() - a.getY(); // 2
        return (x1 * y2 != y1 * x2);
    }

    bool isPolygon(){
        if (length <= 2) return false;
        for (int i = 0; i < length - 2; i++){
            if (!validated3Point(points[i], points[i+1], points[i+2])) return false;
        }
        return true;
    }

    void input(){
        cout << "input number of points : ";
        cin >> length;
        points = new Point[length];
        for (int i = 0; i < length; i++){
            points[i].input();
        }

        if (!isPolygon()){
            cout << "Please input the validated triangle!" << endl;
            input();
        }
    }

    void output(){
        cout << "Polygon : " << endl;
        for (int i = 0; i < length; i++){
            points[i].output();
        }
    }

    void translate(double a, double b){
        for (int i = 0; i < length; i ++){
            points[i].translate(a, b);
        }
    }

    void zoom(double k){
        for (int i = 0; i < length; i ++){
            points[i].zoom(k);
        }
    }

    void spin(double alpha){
        for (int i = 0; i < length; i ++){
            points[i].spin(alpha);
        }
    }
};


int main(){
    Polygon p;
    p.input();
    p.output();
    return 0;
}
