#include <iostream>

// ����� �������� ����� �� ���������
class Point2D {
public:
    // ����������� � ����������� ��� ������� ���������
    Point2D(int x, int y) : x(x), y(y) {}

    // ����� ��� ������ ���������� � ����������� �����
    void display() {
        std::cout << "Point coordinates: (" << x << ", " << y << ")" << std::endl;
    }

protected:
    int x, y;
};

// ����� �������� ����� ����� ��� Z
class Z {
public:
    // ����������� � ���������� ��� ������� �������� z
    Z(int z) : z(z) {}

protected:
    int z;
};

// ����� �������� ���������� ����������
class H {
public:
    // ����������� � ���������� ��� ������� �������� h
    H(double h) : h(h) {}

protected:
    double h;
};

// ����� �������� ���������� ����� � ���������� �����������
class Point3Dh : public Point2D, public Z, public H {
public:
    // ����������� ��� ������� ������� ��������� �����
    Point3Dh(int x, int y, int z, double h) : Point2D(x, y), Z(z), H(h) {
        // ���������, ��� �������� h �� ����� ����
        if (h == 0) {
            std::cerr << "Error: Homogeneous coordinate (h) cannot be zero!" << std::endl;
            error = true; // ������������� ���� ������
        } else {
            error = false;
        }
    }

    // ����� ��� ������ ���������� � �������� ����������� �����
    void display() {
        // ��������� ���� ������
        if (!error) {
            // ��������� �������� ����������
            double real_x = x / h;
            double real_y = y / h;
            double real_z = z / h;
            std::cout << "Real coordinates: (" << real_x << ", " << real_y << ", " << real_z << ")" << std::endl;
        } else {
            std::cerr << "Cannot display coordinates. Error detected." << std::endl;
        }
    }

private:
    bool error; // ���� ��� ������������ ������
};

int main() {
    // �������� �������� Point3Dh � ����� �� �������� ���������
    Point3Dh point1(3, 4, 5, 2);
    Point3Dh point2(6, 8, 10, 0); // ������: ��������� ���������� ����� ����

    point1.display();
    point2.display();

    return 0;
}
