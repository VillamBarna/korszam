#include <vector>
#include <iostream>

template<typename T>
struct polinom {
    std::vector<T> egyutthatok;

    polinom<T> (std::vector<T> e) : egyutthatok{e} {
    };

    polinom<T> () : egyutthatok{std::vector<T> {}} {
    };

    polinom<T> (size_t hossz) : egyutthatok{std::vector<T> (hossz)} {
    };
};

template<typename T>
polinom<T> operator+(polinom<T> const& p1, polinom<T> const& p2);

template<typename T>
polinom<T> operator-(polinom<T> const& p1, polinom<T> const& p2);

template<typename T>
polinom<T> dot(polinom<T> const& p1, polinom<T> const& p2);

template<typename T>
polinom<T> derivative(polinom<T> const& p, int rend);

template<typename T>
T integral(polinom<T> const& p, double also_h, double felso_h);

template<typename T>
std::ostream& operator<<(std::ostream& o, polinom<T> const& p);
