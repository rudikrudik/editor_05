#include "controller.hpp"

CanvasController::CanvasController(GraphicDocument& model_, MainView& view_) :
    model{model_}, view{view_} {}

void CanvasController::import_document(const std::string& path) {
    model.load_document(path);
    view.draw();
}

void CanvasController::export_document(const std::string& path) {
    model.save_document(path);
}

void CanvasController::add_primitive(std::shared_ptr<Primitive>& primitive) {
    model.add_primitive_to_document(primitive);
    view.draw();
}

void CanvasController::remove_primitive(std::shared_ptr<Primitive>& primitive) {
    model.remove_primitive_from_document(primitive);
    view.draw();
}

