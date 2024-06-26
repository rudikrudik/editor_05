#pragma once

#include <string>
#include <vector>

class Color {
public:
    Color();
    Color(const Color& rhs);
    Color(uint8_t r_, uint8_t g_, uint8_t b_);

private:
    int red;
    int green;
    int blue;
};

struct Coordinate {
    int x;
    int y;
};


class Primitive {
public:
    Primitive() = default;
    explicit Primitive(const Color& color_);
    Primitive(const Color& color_, int z_index_);
    void move_to_z_index(int z_index_);
    virtual std::string get_presentation() = 0;

private:
    Color color;
    int z_index = 0;
};

// Фигура Линия
class Line : public Primitive {
public:
    Line(const Color& color_, const Coordinate& point1_, const Coordinate& point2_);
    std::string get_presentation() override;

private:
    Coordinate x;
    Coordinate y;
    };

// Фигура Круг
class Circle : public Primitive {
public:
    Circle(const Color& color_, const Coordinate& center_, double radius_);

    std::string get_presentation() override;

private:
    Coordinate center;
    double radius;
};

// Фигура Прямоугольник/Квадрат
class Rectangle : public Primitive {
public:
    Rectangle(const Color& color_, const Coordinate& left_top_, const Coordinate& right_bottom_);

    std::string get_presentation() override;

private:
    Coordinate x;
    Coordinate y;
};

