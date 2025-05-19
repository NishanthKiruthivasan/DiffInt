# Differentiator and Integrator in C++

This project demonstrates how to perform **numerical differentiation and integration** of any user-defined function in C++ using **object-oriented programming**. It utilizes **constructors** for computation and **destructors** for lifecycle tracing.

## Features

- Differentiate any mathematical function using the **central difference method**
- Integrate a function over an interval using the **trapezoidal rule**
- Accepts lambda or `std::function<double(double)>` as input
- Demonstrates usage of constructors and destructors in practical numerical tasks

## Methods Used

### Numerical Differentiation
Uses the **central difference formula**:
\[
f'(x) \approx \frac{f(x + h) - f(x - h)}{2h}
\]

### Numerical Integration
Uses the **trapezoidal rule**:
\[
\int_a^b f(x)\,dx \approx h \left[ \frac{f(a) + f(b)}{2} + \sum_{i=1}^{n-1} f(a + ih) \right]
\]
where \( h = \frac{b - a}{n} \)

## 🧾 Code Overview

```cpp
auto func = [](double x) { return std::sin(x); };

// Differentiate sin(x) at x = π/4
Differentiator d(func, M_PI / 4);

// Integrate sin(x) from 0 to π
Integrator i(func, 0, M_PI);
