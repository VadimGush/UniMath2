
// Задание 5: Квадратура круга методом Монте-Карло
#include <cmath>
#include <iostream>
#include <ctime>
using namespace std;

double ran() {
  // Используем стандартную функцию rand(), которая генерирует
  // целое число от нуля до заданной константы RAND_MAX (данная константа задана
  // в стандартной библиотеке языка C++)
  return (double)rand() / RAND_MAX;
}

// Проводим испытания
// n - количество испытаний
double function(int n) {
  double x;
  double y;
  int g = 0; // число успешных испытаний
  for (int i=0;i<n;i++) {
    // Генерируем случайную точку в диапазонах от 0 до 1 по X и Y
    x = ran();
    y = ran();
    // Проверяем, попала ли точка в окружность
    if (sqrt(pow(x,2)+pow(y,2))<=1.0) {
      g++;
    }
  }
  // Возвращаем число
  return 4 * ((double)g / (double)n);
}

int main() {
  // Генератор случайных чисел работает с использованием некоторого seed (ключ)
  // который мы задаём в начале как текущее время в секундах
  srand(time(0));
  // Проводим испытание
  cout << "Число Пи: " << function(100000) << endl;
  return 0;
}
