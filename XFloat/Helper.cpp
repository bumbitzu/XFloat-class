#include "XFloat.h"



bool XFloat::isFloat() const
{
    if (decimalPart.size() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void XFloat::integerfyDivider(XFloat& divisor, XFloat& divident) const
{
    while (divisor.isFloat())
    {
        if (divisor.isFloat())
        {
            divisor.integerPart.push_back(divisor.decimalPart.front());
            divisor.decimalPart.pop_front();
        }
        if (divident.isFloat())
        {
            divident.integerPart.push_back(divident.decimalPart.front());
            divident.decimalPart.pop_front();
        }
        else
        {
            divident.integerPart.push_back(0);
        }
    }
}

void XFloat::appendTo(XFloat& xFloat)
{
    if (integerPart.size() > 0)
    {
        xFloat.integerPart.push_back(integerPart.front());
        integerPart.pop_front();
    }
    else if(decimalPart.size() > 0)
    {
        xFloat.integerPart.push_back(decimalPart.front());
        decimalPart.pop_front();
    }
}

bool XFloat::isZero() const
{
    if (integerPart.size() == 1 && decimalPart.size() == 1)
    {
        if (integerPart[0] == 0 && decimalPart[0] == 0)
        {
            return true;
        }
    }
    if (integerPart.size() == 0 && decimalPart.size() == 1)
    {
        if (decimalPart[0] == 0)
        {
            return true;
        }
    }
    if(integerPart.size() == 1 && decimalPart.size() == 0)
    {
        if (integerPart[0] == 0)
        {
            return true;
        }
    }
    if (isNull())
    {
        return true;
    }
    return false;
}
bool XFloat::isNull() const
{
    if (integerPart.size() == 0 && decimalPart.size() == 0)
    {
        return true;
    }
    return false;
}

bool XFloat::noIntPart()
{
    if (integerPart.size() == 0)
    {
        return true;
    }
    return false;
}

void XFloat::normalizeParts(XFloat& xFloat1, XFloat& xFloat2) const
{
    if (xFloat1.integerPart.size() > xFloat2.integerPart.size())
    {
        xFloat2.integerPart.insert(xFloat2.integerPart.begin(), xFloat1.integerPart.size() - xFloat2.integerPart.size(), 0);
    }
    else if (xFloat1.integerPart.size() < xFloat2.integerPart.size())
    {
        xFloat1.integerPart.insert(xFloat1.integerPart.begin(), xFloat2.integerPart.size() - xFloat1.integerPart.size(), 0);
    }

    if (xFloat1.decimalPart.size() > xFloat2.decimalPart.size())
    {
        xFloat2.decimalPart.insert(xFloat2.decimalPart.end(), xFloat1.decimalPart.size() - xFloat2.decimalPart.size(), 0);
    }
    else if (xFloat1.decimalPart.size() < xFloat2.decimalPart.size())
    {
        xFloat1.decimalPart.insert(xFloat1.decimalPart.end(), xFloat2.decimalPart.size() - xFloat1.decimalPart.size(), 0);
    }
   
}

void XFloat::normalizeResult(XFloat& result) const
{
    while (result.integerPart[0] == 0 && result.integerPart.size() > 1)
    {
        result.integerPart.erase(result.integerPart.begin());
    }
    
    while (result.isFloat() && result.decimalPart[result.decimalPart.size() - 1] == 0)
    {
        result.decimalPart.pop_back();
    }
}
void XFloat::integerfyParts(XFloat& xFloat) const
{
    
    while (xFloat.decimalPart.size() > 0)
    {
        xFloat.integerPart.push_back(xFloat.decimalPart.front());
        xFloat.decimalPart.pop_front();
    }
}

XFloat XFloat::add(const XFloat& operand1, const XFloat& operand2) const
{
    XFloat result;
    int carry = 0;
    if (operand1.isFloat() || operand2.isFloat())
    {
        for (int i = operand1.decimalPart.size() - 1; i >= 0; i--)
        {
            int sum = operand1.decimalPart[i] + operand2.decimalPart[i] + carry;
            result.decimalPart.insert(result.decimalPart.begin(), sum % 10);
            carry = sum / 10;
        }
    }
    
    for (int i = operand1.integerPart.size() - 1; i >= 0; i--)
    {
        int sum = operand1.integerPart[i] + operand2.integerPart[i] + carry;
        result.integerPart.insert(result.integerPart.begin(), sum % 10);
        carry = sum / 10;
        if (i == 0 && sum > 9)
        {
            result.integerPart.insert(result.integerPart.begin(), 1);
        }
    }
    return result;
}

XFloat XFloat::subtract(const XFloat& operand1, const XFloat& operand2) const
{
    XFloat result;
    int carry = 0;
    for (int i = operand1.decimalPart.size() - 1; i >= 0; i--)
    {
        int diff = operand1.decimalPart[i] - operand2.decimalPart[i] - carry;
        if (diff < 0)
        {
            diff += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result.decimalPart.insert(result.decimalPart.begin(), diff);
    }
    for (int i = operand1.integerPart.size() - 1; i >= 0; i--)
    {
        int diff = operand1.integerPart[i] - operand2.integerPart[i] - carry;
        if (diff < 0)
        {
            diff += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result.integerPart.insert(result.integerPart.begin(), diff);
    }
    return result;
}
