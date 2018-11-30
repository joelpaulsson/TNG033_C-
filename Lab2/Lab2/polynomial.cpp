/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"

/* --- CONSTRUCTORS ---*/

// Default Constructor
Polynomial::Polynomial() : degree{ 0 }{
}

// Single element Constructor
Polynomial::Polynomial(double d) :
degree{ 0 } , coeff{ new double[degree + 1]}{
        
    coeff[0] = d;

}

// Constructor from array of doubles
Polynomial::Polynomial(int d, double *A) :
degree{ d }, coeff{new double[degree + 1]}{
    
    for( int i = 0 ; i < degree + 1; i++){
        coeff[i] = A[i];
    }
}

// Copy Constructor
Polynomial::Polynomial(const Polynomial& P) :
degree{ P.degree }, coeff{ new double[degree + 1]}{
    
    for( int i = 0 ; i < degree + 1; i++){
        coeff[i] = P.coeff[i];
    }
}

/* --- DESTRUCTORS ---*/
Polynomial::~Polynomial(){
    
    delete[] coeff;
    coeff = nullptr;
    degree = 0; // maybe not neccisary as any int take the same amount of bytes
    
}


/*--- OPERATORS ---*/

//// Assingment: =
Polynomial& Polynomial::operator=(const Polynomial &P){

    // Determine if they are already the same
    if( this != &P){
        
        // replace LH-side with P
        degree = P.degree;
        coeff = new double[degree + 1];
        
        for (int i = 0; i < degree + 1 ; i++) {
            coeff[i] = P.coeff[i];
        }
    }
    return *this;
}

//Addition, two poly: +
Polynomial operator+(const Polynomial &P1, const Polynomial &P2){

    int tempDeg = max(P1.degree, P2.degree);

    double* tempCoef = new double[tempDeg + 1];

    for (int i = 0; i < tempDeg + 1 ; i++) {

        tempCoef[i] = 0;

        if (i <= P1.degree) {tempCoef[i] += P1.coeff[i];}
        if (i <= P2.degree) {tempCoef[i] += P2.coeff[i];}
    }

    return Polynomial(tempDeg, tempCoef);
}


// Addition, double to poly: +
Polynomial Polynomial::operator+(const double n){
    
    coeff[0] += n;
    
    return *this ;
}

//// Subscript: []
//double Polynomial::operator[](int i) const{
//    return coeff[i];
//}

//int i on left side, return coefficient on index i
double Polynomial::operator[](int i) const {
    return coeff[i];
}

//int i on right side, modify coefficient on index i with double
double& Polynomial::operator[](int i) {
    return coeff[i];
}


//Evaluate
double Polynomial::operator()(double x) const{
    
    double res = 0;
    
    for (int i = 0; i < degree + 1; i++) {
        res += coeff[i] * pow(x , i);
    }

    return res;
}



/*--- FUNCTIONS ---*/
Polynomial *Polynomial::clone() const{
    
    Polynomial *temp = new Polynomial(*this);
    return temp;

}


void Polynomial::display(ostream &os) const{


    for (int i = 0 ; i < degree + 1; i++) {
        
        // is it better to use isRoot?
        if(coeff[i] != 0){
            if(i != 0){
                if (coeff[i] > 0) {
                     os << fixed << setprecision(2) << " + " << coeff[i] << " * X^" << i ;
                }
            }else
                os << coeff[i];
        }
    }
}
