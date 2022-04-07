#pragma once
#include <iostream>

using namespace std;

class Point{
private:    
    int x;
    int y;
public: 
    Point(){

    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    void input(){
        cout << "x: "; cin >> x;
        cout << "y: "; cin >> y;
    }

    void output(){
        cout << "Point: " << "(" << x << "," << y << ")" << endl;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void setX(int x){
        this->x = x;
    }

    void setY(int y){
        this->y = y;
    }

    void translate(int a, int b){
        x = x + a;
        y = y + b;
    }
};
