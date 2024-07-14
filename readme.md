# XFloat Library

The `XFloat` library is a custom implementation for handling floating-point arithmetic with enhanced precision and custom operations. This library allows users to work with floating-point numbers represented as sequences of integers for both the integer and decimal parts. It supports various arithmetic and comparison operations, as well as input and output operations.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
  - [Constructors](#constructors)
  - [Arithmetic Operators](#arithmetic-operators)
  - [Comparison Operators](#comparison-operators)
  - [Utility Functions](#utility-functions)
- [Example](#example)
- [Methods and Operators](#methods-and-operators)
- [Contributing](#contributing)
- [License](#license)

## Installation

To use the `XFloat` library, simply include the header file in your project:

```cpp
#include "XFloat.h"
```

## Usage

### Constructors

- `XFloat()` - Default constructor.
- `XFloat(const std::string& val)` - Constructs an `XFloat` object from a string.
- `XFloat(const XFloat& xFloat)` - Copy constructor.
- `XFloat(const char* cstr)` - Constructs an `XFloat` object from a C-string.

### Arithmetic Operators

- `XFloat operator+(const XFloat& xFloat) const` - Addition.
- `XFloat operator-(const XFloat& xFloat) const` - Subtraction.
- `XFloat operator*(const XFloat& xFloat) const` - Multiplication.
- `XFloat operator/(const XFloat& xFloat) const` - Division.

### Comparison Operators

- `bool operator==(const XFloat& xFloat) const` - Equality comparison.
- `bool operator!=(const XFloat& xFloat) const` - Inequality comparison.
- `bool operator<(const XFloat& xFloat) const` - Less than comparison.
- `bool operator<=(const XFloat& xFloat) const` - Less than or equal to comparison.
- `bool operator>(const XFloat& xFloat) const` - Greater than comparison.
- `bool operator>=(const XFloat& xFloat) const` - Greater than or equal to comparison.

### Utility Functions

- `std::string toString() const` - Converts the `XFloat` object to a string representation.
- `static void setPrecision(int prec)` - Sets the floating point precision for all `XFloat` objects.
- ```cpp
  XFloat pi;
  // Important! Set precision if result might be a float with infinite decimal digits like pi
  pi.setPrecision(10);
  pi = circumference / diameter;
  ## Example
  ```
```cpp
#include "XFloat.h"
#include <iostream>

int main() {
    XFloat::setPrecision(10); // Set precision to 10 digits

    XFloat num1("123.456");
    XFloat num2("789.012");

    XFloat sum = num1 + num2;
    XFloat difference = num1 - num2;
    XFloat product = num1 * num2;
    XFloat quotient = num1 / num2;

    std::cout << "Sum: " << sum.toString() << std::endl;
    std::cout << "Difference: " << difference.toString() << std::endl;
    std::cout << "Product: " << product.toString() << std::endl;
    std::cout << "Quotient: " << quotient.toString() << std::endl;

    return 0;
}
```

## Methods and Operators

### Private Methods

- `bool isFloat() const` - Checks if the number is a floating point.
- `void integerfyDivider(XFloat& xFloat1, XFloat& xFloat2) const` - Converts the divider to an integer.
- `void appendTo(XFloat& xFloat)` - Appends one `XFloat` to another.
- `bool isZero() const` - Checks if the number is zero.
- `bool isNull() const` - Checks if the number is null.
- `bool noIntPart()` - Checks if there is no integer part.
- `void normalizeParts(XFloat & xFloat1, XFloat& xFloat2) const` - Normalizes the parts of two `XFloat` numbers.
- `void normalizeResult(XFloat& xFloat) const` - Normalizes the result.
- `void integerfyParts(XFloat& xFloat) const` - Converts parts to integers.
- `XFloat add(const XFloat& xFloat1, const XFloat& xFloat2) const` - Adds two `XFloat` numbers.
- `XFloat subtract(const XFloat& xFloat1, const XFloat& xFloat2) const` - Subtracts one `XFloat` from another.

### Public Methods

- `XFloat& operator=(const XFloat& xFloat)` - Assignment operator.
- `XFloat& operator=(const std::string& str)` - Assigns a string to an `XFloat`.
- `XFloat& operator=(const char* cstr)` - Assigns a C-string to an `XFloat`.
- `XFloat& operator+=(const XFloat& xFloat)` - Addition assignment operator.
- `XFloat& operator-=(const XFloat& xFloat)` - Subtraction assignment operator.
- `XFloat& operator*=(const XFloat& xFloat)` - Multiplication assignment operator.
- `XFloat& operator++()` - Prefix increment operator.
- `XFloat operator++(int)` - Postfix increment operator.
- `XFloat& operator--()` - Prefix decrement operator.
- `XFloat operator--(int)` - Postfix decrement operator.

### Friend Functions

- `friend std::ostream& operator<<(std::ostream& out, const XFloat& xf)` - Output stream operator.
- `friend std::istream& operator>>(std::istream& in, XFloat& xf)` - Input stream operator.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
