#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class RangeIterator {
private:
    typename vector<T>::iterator current;
    typename vector<T>::iterator end;

public:
    RangeIterator(typename vector<T>::iterator begin, typename vector<T>::iterator end)
        : current(begin), end(end) {}

    RangeIterator& operator++() {
        ++current;
        return *this;
    }

    RangeIterator& operator--() {
        --current;
        return *this;
    }

    T& operator*() {
        return *current;
    }

    bool operator!=(const RangeIterator& other) const {
        return current != other.current;
    }
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    RangeIterator<int> begin(vec.begin(), vec.end());
    RangeIterator<int> end(vec.end(), vec.end());

    for (RangeIterator<int> it = begin; it != end; ++it) {
        cout << *it << " ";
    }

    return 0;
}