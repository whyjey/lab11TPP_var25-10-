#include <algorithm>
#include <cstddef>
#include <iostream>
#include <optional>
#include <ranges>
#include <vector>

// Допоміжна функція для Завдання 3
std::vector<int> make() {
    return {3, 1, 4};
}

// Виправлена функція average для Завдання 4
template <std::ranges::input_range R>
std::optional<double> average(R&& r) {
    double sum = 0.0;
    std::size_t n = 0;
    for (auto&& x : r) {
        sum += static_cast<double>(x);
        ++n;
    }
    if (n == 0) {
        return std::nullopt;
    }
    return sum / static_cast<double>(n);
}

int main() {
    // --- Завдання 1. Ідіома erase-remove для std::remove_if ---
    {
        std::vector<int> v{1, -2, 3, -4, 5};
        v.erase(
            std::remove_if(v.begin(), v.end(), [](int x) { return x < 0; }),
            v.end()
        );
        std::cout << "[Завдання 1] Розмір: " << v.size() << ", елементи: ";
        for (int x : v) std::cout << x << ' ';
        std::cout << '\n';
    }

    // --- Завдання 2. Захоплення змінних за значенням та посиланням ---
    {
        int k = 2;
        auto byValue = [k](int x) { return x * k; };
        auto byRef = [&k](int x) { return x * k; };
        k = 10;
        std::cout << "[Завдання 2] byValue(3) = " << byValue(3)
                  << ", byRef(3) = " << byRef(3) << '\n';
    }

    // --- Завдання 3. Подовження часу життя тимчасового вектора (std::ranges::dangling) ---
    {
        const auto numbers = make();
        auto it = std::ranges::max_element(numbers);
        if (it != numbers.end()) {
            std::cout << "[Завдання 3] Максимум: " << *it << '\n';
        }
    }

    // --- Завдання 4. Передавання views у функцію через R&& ---
    {
        auto r = std::views::iota(1, 31)
            | std::views::filter([](int x) { return x % 3 == 0; })
            | std::views::transform([](int x) { return x * x; });

        if (auto avg = average(r)) {
            std::cout << "[Завдання 4] Середнє значення: " << *avg << '\n';
        } else {
            std::cout << "[Завдання 4] Діапазон порожній\n";
        }
    }

    return 0;
}
