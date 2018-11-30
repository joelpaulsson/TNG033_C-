/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"



// isRoot
bool Expression::isRoot(double n) const{
    
    if( fabs( (*this)(n) ) < EPSILON ){ return true;}
    
    return false;
}

// operator<<
std::ostream& operator<<(ostream &os, const Expression &E){
    
    // call ostream of subclasses!
    E.display(os);
    return os;
}
