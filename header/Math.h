//
// Created by trung on 4/11/2024.
//

#ifndef GAMELEARN_MATH_H
#define GAMELEARN_MATH_H
#include <iostream>
using namespace std;
struct Vector2f{
    Vector2f():x(0),y(0)
    {

    }
    Vector2f(float p_x, float p_y):x(p_x),y(p_y)
    {

    }
    void print()
    {
        cout << "x: " << x << " y: " << y << endl;
    }
    
    float  x,y;
};

#endif //GAMELEARN_MATH_H
