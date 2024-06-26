#include <memory>
#include <iostream>

#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"
#include "primitives.hpp"


int main() {
    std::cout << "New document" << std::endl;
    GraphicDocument model{};
    MainView view{model};
    CanvasController controller(model, view);

    std::cout << "Loading document from file" << std::endl;
    controller.import_document("document.txt");

    std::cout << "Add line" << std::endl;
    auto line = std::shared_ptr<Primitive>(
            new Line{Color{125, 255, 125}, Point{0, 0}, Point{10, 10}});
    controller.add_primitive(line);


    std::cout << "Add circle" << std::endl;
    auto circle = std::shared_ptr<Primitive>(
            new Circle{Color{0, 125, 0}, Point{20, 20}, 20});
    controller.add_primitive(circle);


    std::cout << "Add rectangle" << std::endl;
    auto rectangle = std::shared_ptr<Primitive>(
            new Rectangle{Color{0, 125, 0}, Point{20, 20}, Point{100, 100}});
    controller.add_primitive(rectangle);

    std::cout << "Remove line" << std::endl;
    controller.remove_primitive(line);

    std::cout << "Remove circle" << std::endl;
    controller.remove_primitive(circle);

    std::cout << "Saving document to file" << std::endl;
    controller.export_document("document.txt");

    return 0;
}
