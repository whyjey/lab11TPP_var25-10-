#include <algorithm>
#include <iostream>
#include <vector>

// Варіант 10 (студент №25 у списку).
// Чиста функція для підрахунку елементів, більших за 10.
// Вибір алгоритму: std::count_if оптимально підходить для підрахунку елементів за предикатом
// без модифікації вхідного контейнера та без створення проміжних копій.
std::size_t countGreaterThanTen(const std::vector<int>& data) {
    return static_cast<std::size_t>(std::count_if(
        data.begin(),
        data.end(),
        [](int x) { return x > 10; } // Лямбда-предикат визначає умову відбору
    ));
}

int main() {
    const std::vector<int> numbers{4, 12, 10, 25, -3, 18, 7};
    const std::vector<int> emptyVec{};

    std::cout << "Початковий вектор: ";
    std::for_each(numbers.begin(), numbers.end(), [](int x) { std::cout << x << ' '; });
    std::cout << '\n';

    std::cout << "Кількість елементів > 10: " << countGreaterThanTen(numbers) << '\n';
    std::cout << "Кількість елементів > 10 (порожній вектор): " << countGreaterThanTen(emptyVec) << '\n';

    return 0;
}
