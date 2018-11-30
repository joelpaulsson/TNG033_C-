/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>      

#include "expression.h"


class Polynomial : public Expression
{
    
public:
    /* --- CONSTRUCTORS ---*/
    
    // Default Constructor
    Polynomial();
    
    // Single element Constructor
    Polynomial(double d);
    
    // Constructor from array of doubles
    Polynomial(int d, double *A);
    
    // Copy Constructor
    Polynomial(const Polynomial& P);
    
    
     /* --- DESTRUCTORS ---*/
    ~Polynomial();
    
    
    /*--- OPERATORS ---*/
    
    // Assingment: =
    Polynomial& operator=(const Polynomial &P);
    
    // Addition, two poly: +
    friend Polynomial operator+(const Polynomial &P1, const Polynomial &P2 );
    
    // Addition, double to poly: +
    Polynomial operator+(const double n);
    
    // Subscript: []
    double operator[](int i) const;
    
    double& operator[](int i);
    
    double operator()(double x) const override;
    
    
    /*--- FUNCTIONS ---*/
    
    Polynomial* clone() const override;
    
    void display(ostream& os) const override;
    
protected:
    
    int degree;
    double* coeff;
    
};


#endif
