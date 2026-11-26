#include <cstddef>
#include <iostream>
#include <numeric>
#include <optional>
#include <ranges>

// Частина 6 
// Чиста функція для обчислення середнього арифметичного будь-якого вхідного діапазону
template <std::ranges::input_range R>
std::optional<double> computeAverage(R&& range) {
    struct Acc {
        double sum = 0.0;
        std::size_t count = 0;
    };

    Acc res = std::accumulate(
        range.begin(),
        range.end(),
        Acc{},
        [](Acc acc, auto x) {
            acc.sum += static_cast<double>(x);
            ++acc.count;
            return acc;
        }
    );

    if (res.count == 0) {
        return std::nullopt;
    }
    return res.sum / static_cast<double>(res.count);
}

int main() {
    auto pipeline = std::views::iota(1, 101)
        | std::views::filter([](int x) { return x % 3 == 0; })
        | std::views::transform([](int x) { return x * x; });

    long long sumOfSquares = std::accumulate(pipeline.begin(), pipeline.end(), 0LL);
    std::optional<double> avgOfSquares = computeAverage(pipeline);

    std::cout << "Сума квадратів кратних 3 у [1..100]: " << sumOfSquares << '\n';
    if (avgOfSquares) {
        std::cout << "Середнє арифметичне квадратів:       " << *avgOfSquares << '\n';
    }

    return 0;
}
