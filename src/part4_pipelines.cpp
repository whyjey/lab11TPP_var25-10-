#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <optional>
#include <ranges>
#include <string>
#include <vector>

// Варіант 10 
// Спосіб А. Класична реалізація з проміжними контейнерами та алгоритмами STL.
std::optional<int> maxShiftedNegativeClassic(const std::vector<int>& data) {
    std::vector<int> negatives;
    std::copy_if(data.begin(), data.end(), std::back_inserter(negatives), [](int x) {
        return x < 0;
    });

    if (negatives.empty()) {
        return std::nullopt;
    }
    std::vector<int> shifted(negatives.size());
    std::transform(negatives.begin(), negatives.end(), shifted.begin(), [](int x) {
        return x + 10;
    });
    return std::accumulate(
        std::next(shifted.begin()),
        shifted.end(),
        shifted.front(),
        [](int currentMax, int x) { return std::max(currentMax, x); }
    );
}

// Спосіб Б. Реалізація через конвеєр std::ranges / std::views без проміжних контейнерів.
template <std::ranges::input_range R>
std::optional<int> maxShiftedNegativeRanges(R&& range) {
    // Лінивий конвеєр
    auto pipeline = std::forward<R>(range)
        | std::views::filter([](int x) { return x < 0; })
        | std::views::transform([](int x) { return x + 10; });

    // Фактичне виконання фільтрації та перетворення відбувається під час ітерування в std::accumulate
    return std::accumulate(
        pipeline.begin(),
        pipeline.end(),
        std::optional<int>{std::nullopt},
        [](std::optional<int> acc, int x) -> std::optional<int> {
            return acc ? std::max(*acc, x) : x;
        }
    );
}

int main() {
    const std::vector<int> data{4, -15, 0, -3, 8, -20, 12};
    const std::vector<int> noNegatives{1, 5, 10, 0};

    auto resClassic = maxShiftedNegativeClassic(data);
    auto resRanges = maxShiftedNegativeRanges(data);

    std::cout << "Класичний спосіб: " << (resClassic ? std::to_string(*resClassic) : "nullopt") << '\n';
    std::cout << "Ranges конвеєр:   " << (resRanges ? std::to_string(*resRanges) : "nullopt") << '\n';

    auto emptyRanges = maxShiftedNegativeRanges(noNegatives);
    std::cout << "Без від'ємних:    " << (emptyRanges ? std::to_string(*emptyRanges) : "nullopt") << '\n';

    return 0;
}
