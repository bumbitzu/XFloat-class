#ifndef XFLOAT_H
#define XFLOAT_H
#include <vector>
#include <string>
#include <deque>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

class XFloat {
private:
    static int precision;
    std::deque <int> decimalPart = {};
    std::deque <int> integerPart = {};
    bool isNegative;
    
    //metods
    bool isFloat() const;
    void integerfyDivider(XFloat& xFloat1, XFloat& xFloat2) const;
    void appendTo(XFloat& xFloat);
    bool isZero() const;
    bool isNull() const;    
    bool noIntPart();
    void normalizeParts(XFloat & xFloat1, XFloat& xFloat2) const;
    void normalizeResult(XFloat& xFloat) const;
    void integerfyParts(XFloat& xFloat) const;
    XFloat add(const XFloat& xFloat1, const XFloat& xFloat2) const;
    XFloat subtract(const XFloat& xFloat1, const XFloat& xFloat2) const;

public:
    
    // Constructors

    XFloat() ;
    XFloat(const std::string& val);
    
    XFloat(const XFloat& xFloat);

    XFloat(const char* cstr);
    
    // Destructor
    ~XFloat();
    
    // Friend functions for I/O operations
    friend std::ostream& operator<<(std::ostream& out, const XFloat& xf);
    friend std::istream& operator>>(std::istream& in, XFloat& xf);

    // Assignment operator

    XFloat& operator=(const XFloat& xFloat);
    XFloat& operator=(const std::string& str);
    XFloat& operator=(const char* cstr);
    // Comparison operators
    bool operator==(const XFloat& xFloat) const;
    bool operator!=(const XFloat& xFloat) const;
    bool operator<(const XFloat& xFloat) const;
    bool operator<=(const XFloat& xFloat) const;
    bool operator>(const XFloat& xFloat) const;
    bool operator>=(const XFloat& xFloat) const;

    // Arithmetic operators
    XFloat operator+(const XFloat& xFloat) const;
    XFloat operator-(const XFloat& xFloat) const;
    XFloat operator*(const XFloat& xFloat) const;
    XFloat operator/(const XFloat& xFloat) const;
    //XFloat operator^(const XFloat& xFloat) const;  // Power operator

    // Arithmetic assignment operators
    XFloat& operator+=(const XFloat& xFloat);
    XFloat& operator-=(const XFloat& xFloat);
    XFloat& operator*=(const XFloat& xFloat);
    //XFloat& operator/=(const XFloat& xFloat);
    //XFloat& operator^=(const XFloat& xFloat);  // Power assignment operator

    // Increment and decrement operators
    XFloat& operator++();    // Prefix increment
    XFloat operator++(int);  // Postfix increment
    XFloat& operator--();    // Prefix decrement
    XFloat operator--(int);  // Postfix decrement

    

    // Utility functions
    std::string toString() const;
    static void setPrecision(int prec) // Set the floating point precision for all XFloat objects
    {
        precision = prec;
    }
    // Root extraction
    //XFloat sqrt() const;
};

#endif // XFLOAT_H
