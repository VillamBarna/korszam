#include "polinom.h"
#include <algorithm>
#include <cmath>

template<typename T>
polinom<T> operator+(polinom<T> const& p1, polinom<T> const& p2) {
        polinom<T> eredmeny{std::max(p1.egyutthatok.size(), p2.egyutthatok.size())};
        if (p1.egyutthatok.size() >= p2.egyutthatok.size()){
            polinom<T> eredmeny{p1.egyutthatok.size()};
            std::transform(p1.egyutthatok.begin(),
                            p1.egyutthatok.end(),
                            p2.egyutthatok.begin(),
                            eredmeny.egyutthatok.begin(),
                            [](T const& x, T const& y) { return x+y; });
        }
        else {
            polinom<T> eredmeny{p2.egyutthatok.size()};
            std::transform(p2.egyutthatok.begin(),
                            p2.egyutthatok.end(),
                            p1.egyutthatok.begin(),
                            eredmeny.egyutthatok.begin(),
                            [](T const& x, T const& y) { return x+y; });
        }
        return eredmeny;
}

template<typename T>
polinom<T> operator-(polinom<T> const& p1, polinom<T> const& p2) {
        polinom<T> eredmeny{std::max(p1.egyutthatok.size(), p2.egyutthatok.size())};
        if (p1.egyutthatok.size() >= p2.egyutthatok.size()){
            std::transform(p1.egyutthatok.begin(),
                            p1.egyutthatok.end(),
                            p2.egyutthatok.begin(),
                            eredmeny.egyutthatok.begin(),
                            [](T const& x, T const& y) { return x-y; });
        }
        else {
            polinom<T> eredmeny{p2.egyutthatok.size()};
            std::transform(p2.egyutthatok.begin(),
                            p2.egyutthatok.end(),
                            p1.egyutthatok.begin(),
                            eredmeny.egyutthatok.begin(),
                            [](T const& x, T const& y) { return y-x; });
        };
        return eredmeny;
}

template<typename T>
polinom<T> dot(polinom<T> const& p1, polinom<T> const& p2) {
    polinom<T> eredmeny{std::vector<T>(p1.egyutthatok.size() + 
            p2.egyutthatok.size()-1, 0)};
    for (size_t i=0; i < p1.egyutthatok.size(); i++) {
        for (size_t j=0; j < p2.egyutthatok.size(); j++) {
            eredmeny.egyutthatok[i+j] += p1.egyutthatok[i]*p2.egyutthatok[j];
        }
    }
    return eredmeny;
}

template<typename T>
polinom<T> derivative(polinom<T> const& p, int rend) {
    if (rend >= p.egyutthatok.size()) {
        return polinom<T> {std::vector<T> {0}};
    }
    polinom<T> eredmeny;
    auto egyutthato_szamlalo = [](int j, int d) { 
        int e=1; 
        for (int k=j; k>(j-d); k--) {
            e *= k;
        } 
    return e;
    };
    for (int i=rend; i < p.egyutthatok.size(); i++) {
        eredmeny.egyutthatok.push_back(p.egyutthatok[i]*egyutthato_szamlalo(i, rend));
    }
    return eredmeny;
}

template<typename T>
T integral(polinom<T> const& p, double also_h, double felso_h) {
    T eredmeny = 0;
    T egyutthato;
    for (size_t i=0; i<p.egyutthatok.size(); i++) {
        egyutthato = p.egyutthatok[i]/(i+1);
        eredmeny += egyutthato*std::pow(felso_h, i+1) - egyutthato*std::pow(also_h, i+1);
    }
    return eredmeny;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, polinom<T> const& p) {
    o << "( ";
    for (T e: p.egyutthatok) {
        o << e << " ";
    }
    o << ")"; 
    return o;
}

int main() {
    polinom<double> p{std::vector<double> {1.1,2.2, 3, 4}};
    polinom<int> p2{std::vector<int> {1, 0, 0}};
    double p3 = integral(p, 0, 2);
    std::cout << p3 << std::endl;
}
