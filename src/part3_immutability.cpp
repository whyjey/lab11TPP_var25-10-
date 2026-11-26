#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Варіант 10 (студент №25 у списку).
// Чиста функція: приймає вхідний вектор за const&, не змінює його і повертає новий вектор.
std::vector<int> incrementGreaterThanTen(const std::vector<int>& source) {
    std::vector<int> result(source.size());
    std::transform(
        source.begin(),
        source.end(),
        result.begin(),
        [](int x) { return (x > 10) ? (x + 1) : x; }
    );
    return result;
}

void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << "[ ";
    std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << ' '; });
    std::cout << "]\n";
}

int main() {
    const std::vector<int> original{5, 10, 11, 20, -4, 15};

    printVector("До виклику (original):    ", original);
    std::vector<int> transformed = incrementGreaterThanTen(original);
    printVector("Після виклику (original): ", original);
    printVector("Новий вектор (result):    ", transformed);

    // Перевірка коректності роботи на порожньому векторі
    const std::vector<int> emptyVec{};
    std::vector<int> emptyResult = incrementGreaterThanTen(emptyVec);
    printVector("Порожній вектор (result): ", emptyResult);

    return 0;
}
