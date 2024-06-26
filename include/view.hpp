#pragma once

#include "model.hpp"

class MainView {
public:
    explicit MainView(const GraphicDocument& model_);
    void draw();
private:
    const GraphicDocument& model;
    void render();
};
