#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// Варіант 10 (студент №25 у списку).
// Іменований функціональний об'єкт (функтор) IsEven без внутрішнього стану.
class IsEven {
public:
    bool operator()(int x) const {
        return x % 2 == 0;
    }
};

int main() {
    const std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8};

    // 1. Застосування функтора IsEven
    std::vector<int> evenWithFunctor;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenWithFunctor), IsEven{});

    // 2. Застосування еквівалентного лямбда-виразу
    auto isEvenLambda = [](int x) { return x % 2 == 0; };
    std::vector<int> evenWithLambda;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenWithLambda), isEvenLambda);

    std::cout << "Результат (функтор IsEven): ";
    std::for_each(evenWithFunctor.begin(), evenWithFunctor.end(), [](int x) { std::cout << x << ' '; });
    std::cout << "\nРезультат (лямбда-вираз): ";
    std::for_each(evenWithLambda.begin(), evenWithLambda.end(), [](int x) { std::cout << x << ' '; });
    std::cout << '\n';

    return 0;
}
