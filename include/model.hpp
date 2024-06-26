#pragma once

#include <string>
#include <vector>
#include <memory>
#include "primitives.hpp"
class GraphicDocument {
public:
    GraphicDocument() = default;
    explicit GraphicDocument(const std::string& path);
    void load_document(const std::string& path);
    void add_primitive_to_document(std::shared_ptr<Primitive>& primitive);
    void remove_primitive_from_document(std::shared_ptr<Primitive>& primitive);
    void save_document(const std::string& path);

    std::vector<std::string> get_elements_presentations() const;

private:
    std::vector<std::shared_ptr<Primitive>> elements;
};

