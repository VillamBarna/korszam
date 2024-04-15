#include <vector>
#include <algorithm>

template<typename T>
struct polinom {
    std::vector<T> egyutthatok;

    polinom (std::vector<T> e) : egyutthatok{e} {
    };

    polinom () : egyutthatok{std::vector<T> {}} {
    };

    polinom (size_t hossz) : egyutthatok{std::vector<T> (hossz)} {
    };

    polinom operator+(polinom<T> const& p2) const {
        polinom<T> eredmeny{this->egyutthatok.size()};

        std::transform(this->egyutthatok.begin(),
                        this->egyutthatok.end(),
                        p2.egyutthatok.begin(),
                        eredmeny.egyutthatok.begin(),
                        [](T const& x, T const& y) { return x+y; });
        return eredmeny;
    }

    polinom operator-(polinom<T> const& p2) const {
        polinom<T> eredmeny{this->egyutthatok.size()};

        std::transform(this->egyutthatok.begin(),
                        this->egyutthatok.end(),
                        p2.egyutthatok.begin(),
                        eredmeny.egyutthatok.begin(),
                        [](T const& x, T const& y) { return x-y; });
        return eredmeny;
    };
};
