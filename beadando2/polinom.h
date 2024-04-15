#include <vector>
#include <algorithm>

template<typename T>
struct polinom {
    std::vector<T> egyutthatok;

    polinom (std::vector<T> e) : egyutthatok{e} {
    };

    polinom operator+(polinom<T> const& p2) const {
        polinom<T> eredmeny{this->egyutthatok};

        std::transform(this->egyutthatok.begin(),
                        this->egyutthatok.end(),
                        p2.egyutthatok.begin(),
                        eredmeny.egyutthatok.begin(),
                        [](T const& x, T const& y) { return x+y; });
        return eredmeny;
    }
};
