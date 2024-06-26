#include <algorithm>
#include <iostream>

#include "model.hpp"

GraphicDocument::GraphicDocument(const std::string& path) {
    load_document(path);
}

void GraphicDocument::load_document(const std::string& path) {
    std::cout << path << std::endl;
    elements.clear();
}

void GraphicDocument::add_primitive_to_document(std::shared_ptr<Primitive>& primitive) {
    std::cout << "add primitive " << primitive->get_presentation() << std::endl;
    elements.emplace_back(primitive);
}

void GraphicDocument::remove_primitive_from_document(std::shared_ptr<Primitive>& primitive) {
    auto position = std::find(elements.begin(), elements.end(), primitive);
    if (position != elements.end()) {
        std::cout << "remove primitive " << primitive->get_presentation() << std::endl;
        elements.erase(position);
    }
}

void GraphicDocument::save_document(const std::string& path) {
    for (const auto& element: elements) {
        std::cout << element << path << std::endl;
    }
}

std::vector<std::string> GraphicDocument::get_elements_presentations() const {
    std::vector<std::string> presentations;
    for(const auto& element: elements)
        presentations.emplace_back(element->get_presentation());
    return presentations;
}
