#include "XFloat.h"
int XFloat::precision = 10;
using namespace std;
// Constructors 
XFloat::XFloat()
{
    integerPart = {};
    decimalPart = {};
    isNegative = false;

    
}
XFloat::XFloat(const string& stringNumber)
{
    isNegative = false;
    if (stringNumber.find("-") != std::string::npos)
    {
        isNegative = true;
    }
    int i;
    if (isNegative)
    {
        i = 1;
    }
    else
    {
        i = 0;
    }
    bool is_float = false;
    for (i; i < stringNumber.size(); i++)
    {
        if (stringNumber[i] == '.')
        {
            i++;
            is_float = true;
        }
        if (!is_float)
        {
            integerPart.push_back(stoi(stringNumber.substr(i, 1)));
        }
        else
        {
            decimalPart.push_back(stoi(stringNumber.substr(i, 1)));
        }
    }
}
XFloat::XFloat(const XFloat& xFloat)
{
    integerPart = xFloat.integerPart;
    decimalPart = xFloat.decimalPart;
    isNegative = xFloat.isNegative;

}
XFloat::XFloat(const char* cstr)
{
    string str = cstr;
    *this = str;
}
XFloat::~XFloat()
{
    integerPart.clear();
    decimalPart.clear();

}
// Friend functions for I/O operations
std::ostream& operator<<(std::ostream& out, const XFloat& xFloat)
{
    if(xFloat.isNegative)
    {
        out << "-";
    }
    for(int i = 0; i < xFloat.integerPart.size(); i++)
    {
        out << xFloat.integerPart[i];
    }
    if(xFloat.isFloat())
    {
        out << ".";
        for(int i = 0; i < xFloat.decimalPart.size(); i++)
        {
            out << xFloat.decimalPart[i];
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, XFloat& xFloat)
{
    string str;
    in >> str;
    xFloat = str;
    return in;
}



//Assignment operator
XFloat& XFloat::operator=(const XFloat& xFloat)
{
    integerPart = xFloat.integerPart;
    decimalPart = xFloat.decimalPart;
    isNegative = xFloat.isNegative;
    return *this;
}

XFloat& XFloat::operator=(const std::string& str)
{
    XFloat temp(str);
    *this = temp;
    return *this;
}

XFloat& XFloat::operator=(const char* cstr)
{
    string str = cstr;
    *this = str;
    return *this;
}

// Comparison operators
bool XFloat::operator==(const XFloat& xFloat) const
{
    XFloat temp1 = *this;
    XFloat temp2 = xFloat;
    normalizeParts(temp1, temp2);
    for (int i = 0; i < temp1.integerPart.size(); i++)
    {
        if (temp1.integerPart[i] != temp2.integerPart[i])
        {
            return false;
        }
    }
    for (int i = 0; i < temp1.decimalPart.size(); i++)
    {
        if (temp1.decimalPart[i] != temp2.decimalPart[i])
        {
            return false;
        }
    }
    return true;
}
bool XFloat::operator!=(const XFloat& xFloat) const
{
    XFloat temp1 = *this;
    XFloat temp2 = xFloat;
    normalizeParts(temp1, temp2);
    for (int i = 0; i < temp1.integerPart.size(); i++)
    {
        if (temp1.integerPart[i] != temp2.integerPart[i])
        {
            return true;
        }
    }
    for (int i = 0; i < temp1.decimalPart.size(); i++)
    {
        if (temp1.decimalPart[i] != temp2.decimalPart[i])
        {
            return true;
        }
    }   
    return false;
}
bool XFloat::operator<(const XFloat& xFloat) const
{
    XFloat temp1 = *this;
    XFloat temp2 = xFloat;
    normalizeParts(temp1, temp2);
    for (int i = 0; i < temp1.integerPart.size(); i++)
    {
        if (temp1.integerPart[i] < temp2.integerPart[i])
        {
            return true;
        }
        else if (temp1.integerPart[i] > temp2.integerPart[i])
        {
            return false;
        }
    }
    for (int i = 0; i < temp1.decimalPart.size(); i++)
    {
        if (temp1.decimalPart[i] < temp2.decimalPart[i])
        {
            return true;
        }
        else if (temp1.decimalPart[i] > temp2.decimalPart[i])
        {
            return false;
        }
    }   
    return false;
}
bool XFloat::operator<=(const XFloat& xFloat) const
{
    XFloat temp1 = *this;
    XFloat temp2 = xFloat;
    normalizeParts(temp1, temp2);
    for (int i = 0; i < temp1.integerPart.size(); i++)
    {
        if (temp1.integerPart[i] < temp2.integerPart[i])
        {
            return true;
        }
        else if (temp1.integerPart[i] > temp2.integerPart[i])
        {
            return false;
        }
    }
    for (int i = 0; i < temp1.decimalPart.size(); i++)
    {
        if (temp1.decimalPart[i] < temp2.decimalPart[i])
        {
            return true;
        }
        else if (temp1.decimalPart[i] > temp2.decimalPart[i])
        {
            return false;
        }
    }   
    return true;
}
bool XFloat::operator>(const XFloat& xFloat) const
{
    XFloat temp1 = *this;
    XFloat temp2 = xFloat;
    normalizeParts(temp1, temp2);
    for (int i = 0; i < temp1.integerPart.size(); i++)
    {
        if (temp1.integerPart[i] > temp2.integerPart[i])
        {
            return true;
        }
        else if (temp1.integerPart[i] < temp2.integerPart[i])
        {
            return false;
        }
    }
    for (int i = 0; i < temp1.decimalPart.size(); i++)
    {
        if (temp1.decimalPart[i] > temp2.decimalPart[i])
        {
            return true;
        }
        else if (temp1.decimalPart[i] < temp2.decimalPart[i])
        {
            return false;
        }
    }
    return false;
}
bool XFloat::operator>=(const XFloat& xFloat) const
{
    XFloat temp1 = *this;
    XFloat temp2 = xFloat;
    normalizeParts(temp1, temp2);
    for (int i = 0; i < temp1.integerPart.size(); i++)
    {
        if (temp1.integerPart[i] > temp2.integerPart[i])
        {
            return true;
        }
        else if (temp1.integerPart[i] < temp2.integerPart[i])
        {
            return false;
        }
    }
    for (int i = 0; i < temp1.decimalPart.size(); i++)
    {
        if (temp1.decimalPart[i] > temp2.decimalPart[i])
        {
            return true;
        }
        else if (temp1.decimalPart[i] < temp2.decimalPart[i])
        {
            return false;
        }
    }
    return true;
}
XFloat XFloat::operator+(const XFloat& xFloat) const 
{
    XFloat result;
    XFloat operand1 = *this;
    XFloat operand2 = xFloat;

    normalizeParts(operand1, operand2);
    
    if (operand1.isNegative == operand2.isNegative)
    {
        result = add(operand1, operand2);
        result.isNegative = isNegative;
    }
    else
    {
        //Modulus of the operands
        if (operand1 < operand2)
        {
            result = operand2 + operand1;
            return result;
        }
        result = subtract(operand1, operand2);
        
        if (isNegative)
        {
            result.isNegative = !result.isNegative;
        }
        normalizeResult(result);
    }

    return result;
}

XFloat XFloat::operator-(const XFloat& other) const
{
    XFloat result;
    XFloat operand1 = *this;
    XFloat operand2 = other;
    normalizeParts(operand1, operand2);
    if (operand1.isNegative != operand2.isNegative)
    {
        result = add(operand1, operand2);
        result.isNegative = operand1.isNegative;
    }
    else
    {
        if (operand1 < operand2)
        {
            result = subtract(operand2, operand1);
            result.isNegative = !operand1.isNegative;
        }
        else
        {
            result = subtract(operand1, operand2);
            result.isNegative = operand1.isNegative;
        }
        normalizeResult(result);
    }
    return result;
}

XFloat XFloat::operator*(const XFloat& xFloat) const
{
    XFloat result;
    XFloat operand1 = *this;
    XFloat operand2 = xFloat;
    int totalDecimalDigits = operand1.decimalPart.size() + operand2.decimalPart.size();
    integerfyParts(operand1);
    integerfyParts(operand2);
    vector<XFloat> partialResults;
    
    int k = 0;
    for (int i = operand1.integerPart.size()-1; i >= 0; i--)
    {
        int carry = 0;
        string partialResult = "";
        for (int j = operand2.integerPart.size()-1; j >= 0; j--)
        {
            
            int product = (operand1.integerPart[i]) * operand2.integerPart[j];
            product += carry;
            partialResult.insert(0, to_string(product%10));
            carry = product / 10;
        }
        if (carry > 0)
        {
            partialResult.insert(0, to_string(carry));
        }
        partialResult.append(k++, '0');
        XFloat temp(partialResult);
        partialResults.push_back(temp);

    }
    for (int i = 0; i < partialResults.size(); i++)
    {
        integerfyParts(partialResults[i]);
        result += partialResults[i];
    }
    
    if (operand1.isFloat() || operand2.isFloat())
    {
        for (totalDecimalDigits; totalDecimalDigits > 0; totalDecimalDigits--)
        {
            result.decimalPart.push_front(result.integerPart.back());
            result.integerPart.pop_back();
        }
        normalizeResult(result);
    }
    if (operand1.isNegative != operand2.isNegative)
    {
        result.isNegative = true;
    }
    else
    {
        result.isNegative = false;
    }
    return result;

}

XFloat XFloat::operator/(const XFloat& xFloat) const
{

    XFloat result;
    XFloat divident = *this;
    XFloat divisor = xFloat;
    if (divident.isNegative || divisor.isNegative)
    {
       result.isNegative = true;
    }
    XFloat reminder = "0";
    bool is_float = false;
    int i = 0;
    integerfyDivider(divisor, divident);
    int floatPoint = divident.integerPart.size() - divisor.integerPart.size();
    int prec = 0;
    while(reminder < divisor)
    {
        if(!divident.noIntPart())
        { 
            divident.appendTo(reminder);
            normalizeResult(reminder);
            
        }
        else
        {
            break;
        }
    }
    
    
    integerfyParts(divident);
    while (true)
    {

        XFloat product = "0";
        XFloat quatient = "0";
        while (product + divisor <= reminder)
        {
            product += divisor;
            quatient++;
        }
        reminder-= product;

        if (is_float)
        {
            prec++;
            result.decimalPart.push_back(quatient.integerPart.front());
            
        }
        else
        {
            result.integerPart.push_back(quatient.integerPart.front());
        }
        if (divident.isNull() && reminder.isZero())
        {
            break;
        }
        if (prec >= precision)
        {
            break;
        }

        if (divident.isNull())
        {
            is_float = true;
            reminder.integerPart.push_back(0);
        }
        else
        {
            reminder.integerPart.push_back(divident.integerPart.front());
            divident.integerPart.pop_front();
            normalizeResult(reminder);
        }

        

        if (i == floatPoint)
        {
            is_float = true;
        }
        i++; 
    }
        return result;
}
XFloat& XFloat::operator+=(const XFloat& xFloat)
{
    *this = *this + xFloat;
    return *this;
}
XFloat& XFloat::operator-=(const XFloat& xFloat)
{
    *this = *this - xFloat;
    return *this;
}

XFloat& XFloat::operator*=(const XFloat& xFloat)
{
    *this = *this * xFloat;
    return *this;
}

XFloat& XFloat::operator++()
{
    if (this->isFloat())
    {
        throw "Increment operator is not supported for floating point numbers";
    }
    XFloat one("1");
    *this += one;
    return *this;
}

XFloat XFloat::operator++(int)
{
    XFloat temp = *this;
    ++(*this);
    return temp;
}

XFloat& XFloat::operator--()
{
    if (this->isFloat())
    {
        throw "Decrement operator is not supported for floating point numbers";
    }
    XFloat one("1");
    *this -= one;
    return *this;
}
XFloat XFloat::operator--(int)
{
    XFloat temp = *this;
    --(*this);
    return temp;
}

std::string XFloat::toString() const
{
    string result = ""; 
    if (isNegative)
    {
        result += "-";
    }
    for (int i = 0; i < integerPart.size(); i++)
    {
        result+= to_string(integerPart[i]);
    }
    if (isFloat())
    {
        result += ".";
        for (int i = 0; i < decimalPart.size(); i++)
        {
            result += to_string(decimalPart[i]);
        }
    }
    return result;
}




