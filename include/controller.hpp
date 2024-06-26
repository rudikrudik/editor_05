#pragma once

#include <string>
#include "model.hpp"
#include "view.hpp"

class CanvasController {
public:
    CanvasController(GraphicDocument& model_, MainView& view_);
    void import_document(const std::string& path);
    void export_document(const std::string& path);
    void add_primitive(std::shared_ptr<Primitive>& primitive);
    void remove_primitive(std::shared_ptr<Primitive>& primitive);

private:
    GraphicDocument& model;
    MainView view;
};
