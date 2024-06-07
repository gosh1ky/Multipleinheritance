#include <iostream>

// Класс описания точки на плоскости
class Point2D {
public:
    // Конструктор с параметрами для задания координат
    Point2D(int x, int y) : x(x), y(y) {}

    // Метод для вывода информации о координатах точки
    void display() {
        std::cout << "Point coordinates: (" << x << ", " << y << ")" << std::endl;
    }

protected:
    int x, y;
};

// Класс описания точки вдоль оси Z
class Z {
public:
    // Конструктор с параметром для задания значения z
    Z(int z) : z(z) {}

protected:
    int z;
};

// Класс описания однородной координаты
class H {
public:
    // Конструктор с параметром для задания значения h
    H(double h) : h(h) {}

protected:
    double h;
};

// Класс описания трехмерной точки в однородных координатах
class Point3Dh : public Point2D, public Z, public H {
public:
    // Конструктор для задания четырех координат точки
    Point3Dh(int x, int y, int z, double h) : Point2D(x, y), Z(z), H(h) {
        // Проверяем, что значение h не равно нулю
        if (h == 0) {
            std::cerr << "Error: Homogeneous coordinate (h) cannot be zero!" << std::endl;
            error = true; // Устанавливаем флаг ошибки
        } else {
            error = false;
        }
    }

    // Метод для вывода информации о реальных координатах точки
    void display() {
        // Проверяем флаг ошибки
        if (!error) {
            // Вычисляем реальные координаты
            double real_x = x / h;
            double real_y = y / h;
            double real_z = z / h;
            std::cout << "Real coordinates: (" << real_x << ", " << real_y << ", " << real_z << ")" << std::endl;
        } else {
            std::cerr << "Cannot display coordinates. Error detected." << std::endl;
        }
    }

private:
    bool error; // Флаг для отслеживания ошибки
};

int main() {
    // Создание объектов Point3Dh и вывод их реальных координат
    Point3Dh point1(3, 4, 5, 2);
    Point3Dh point2(6, 8, 10, 0); // Ошибка: четвертая координата равна нулю

    point1.display();
    point2.display();

    return 0;
}
