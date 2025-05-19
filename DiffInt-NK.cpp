#include <iostream>
#include <functional>
#include <cmath>

class Differentiator {
public:
    Differentiator(std::function<double(double)> func, double x, double h = 1e-5)
        : f(func), point(x), step(h) {
        result = (f(point + step) - f(point - step)) / (2 * step);
        std::cout << "Derivative at x = " << point << " is approximately " << result << "\n";
    }

    ~Differentiator() {
        std::cout << "Differentiator object destroyed.\n";
    }

private:
    std::function<double(double)> f;
    double point, step, result;
};

class Integrator {
public:
    Integrator(std::function<double(double)> func, double a, double b, int n = 1000)
        : f(func), lower(a), upper(b), intervals(n) {
        double h = (upper - lower) / intervals;
        double sum = 0.5 * (f(lower) + f(upper));
        for (int i = 1; i < intervals; ++i) {
            sum += f(lower + i * h);
        }
        result = sum * h;
        std::cout << "Integral from " << lower << " to " << upper << " is approximately " << result << "\n";
    }

    ~Integrator() {
        std::cout << "Integrator object destroyed.\n";
    }

private:
    std::function<double(double)> f;
    double lower, upper, result;
    int intervals;
};

int main() {
    // Define any function here, for example f(x) = sin(x)
    auto func = [](double x) { return std::sin(x); };

    // Differentiate at pi/4
    Differentiator d(func, M_PI / 4);

    // Integrate from 0 to pi
    Integrator i(func, 0, M_PI);

    return 0;
}
