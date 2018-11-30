/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <cmath>

using namespace std;

const double EPSILON = 1.0e-5;


class Expression
{
    
public:
    
    //Test if root
    bool isRoot(double d) const;
    
    //Return a clone of the Expression
    virtual Expression* clone() const = 0;
    
    //Overloaded operators
    //Evaluate // const??
    virtual double operator()( double d) const = 0;

    // ostream
    friend ostream& operator<<(ostream& os, const Expression& E);
    
    //Abstract destructor
    virtual ~Expression() = default;
    
    
protected:
    virtual void display(ostream &os) const = 0;
    
};


#endif
