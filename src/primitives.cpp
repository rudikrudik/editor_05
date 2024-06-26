#include "primitives.hpp"
#include <sstream>

Color::Color() : red{0}, green{0}, blue{0} {}
Color::Color(const Color& rhs) {red = rhs.red; green = rhs.green; blue = rhs.blue; }
Color::Color(uint8_t r_, uint8_t g_, uint8_t b_) : red{r_}, green{g_}, blue{b_} {}


Primitive::Primitive(const Color& color_) : color{color_} {}


// Методы линии
Line::Line(const Color& color_, const Point& point1_, const Point& point2_) : Primitive(color_), x{point1_}, y{point2_} {}

std::string Line::get_presentation() {
    std::stringstream ss;
    ss << "line from (" << x.x << "," << y.y << ") to (" << x.x << "," << y.y << ")";
    return ss.str();
}

// Методы круга
Circle::Circle(const Color& color_, const Point& center_, double radius_) : Primitive(color_), center{center_}, radius{radius_} {}

std::string Circle::get_presentation() {
    std::stringstream ss;
    ss << "circle with center in (" << center.x << "," << center.y << ") with radius " << radius;
    return ss.str();
}

// Методы прямоугольника
Rectangle::Rectangle(const Color& color_, const Point& left_top_, const Point& right_bottom_) : Primitive(color_), x{left_top_}, y{right_bottom_} {}

std::string Rectangle::get_presentation() {
    std::stringstream ss;
    ss << "rectangle, x: (" << x.x << "," << y.y << "), y: (" << x.x << "," << y.y << ")";
    return ss.str();
}