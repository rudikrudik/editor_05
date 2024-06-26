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

struct Point {
    int x;
    int y;
};


class Primitive {
public:
    Primitive() = default;
    explicit Primitive(const Color& color_);
    virtual std::string get_presentation() = 0;

private:
    Color color;
};

// Фигура Линия
class Line : public Primitive {
public:
    Line(const Color& color_, const Point& point1_, const Point& point2_);
    std::string get_presentation() override;

private:
    Point x;
    Point y;
    };

// Фигура Круг
class Circle : public Primitive {
public:
    Circle(const Color& color_, const Point& center_, double radius_);

    std::string get_presentation() override;

private:
    Point center;
    double radius;
};

// Фигура Прямоугольник/Квадрат
class Rectangle : public Primitive {
public:
    Rectangle(const Color& color_, const Point& left_top_, const Point& right_bottom_);

    std::string get_presentation() override;

private:
    Point x;
    Point y;
};

