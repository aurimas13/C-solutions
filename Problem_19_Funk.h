//
// Problem_19_Funk.h
//
// Created by Aurimas Nausedas on 9/28/19.
// Updated by Aurimas Nausedas on 10.31/21.

#ifndef PROBLEM_19_FUNK_h
#define PROBLEM_19_FUNK_h

#include <stdio.h>

// deklaruoju klases | declaring classes
// pagrindine | main

class Figure
{
public:
    Figure(int lx, int ly){x = lx; y = ly; c = 1;};
    void move(int ly);
    virtual void show(int lc) = 0;
    virtual void hide() = 0;
protected:
    int x,y,c;
    // spalva | colour
};

// ------------------------------------------------------
// isvestines klases | derived classes

class Circle : public Figure
{
public:
    Circle(int x, int y) : Figure(x,y){};
    void show(int lc);
    void hide();
};

// ------------------------------------------------------
class Square : public Figure
{
public:
    Square(int x, int y) : Figure(x,y){};
    void show(int lc);
    void hide();
};

// ------------------------------------------------------
class Triangle : public Figure
{
public:
    Triangle(int x, int y) : Figure(x,y){};
    void show(int lc);
    void hide();
};

// ------------------------------------------------------
class Smile : public Figure
{
public:
    Smile(int x, int y) : Figure(x,y){};
    void show(int lc);
    void hide();
};



#endif /* P19FUNK_h */
