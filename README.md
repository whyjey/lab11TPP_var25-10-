# Лабораторна робота №11 — Основи функціонального програмування в C++

## Структура архіву
- `CMakeLists.txt` — конфігурація збірки всіх частин лабораторної роботи під C++23.
- `src/part1_lambdas.cpp` — Частина 1 (Варіант 10): лямбда-вирази та `std::count_if`.
- `src/part2_functors.cpp` — Частина 2 (Варіант 10): функтор `IsEven` та порівняння з лямбда-виразом.
- `src/part3_immutability.cpp` — Частина 3 (Варіант 10): чисті функції та незмінність вхідного вектора.
- `src/part4_pipelines.cpp` — Частина 4 (Варіант 10): порівняння класичного STL-конвеєра та `std::ranges` / `std::views`.
- `src/part5_errors.cpp` — Частина 5: виправлені фрагменти коду (завдання 1–4).
- `src/part6_bonus.cpp` — Частина 6 (Варіант 2): додаткове завдання підвищеної складності.

## Збірка та запуск (CMake + Ninja / GCC)
```bash
cmake -B build -G Ninja
cmake --build build
./build/part1_lambdas
./build/part2_functors
./build/part3_immutability
./build/part4_pipelines
./build/part5_errors
./build/part6_bonus
```
"# lab11TPP_var25-10-" 
