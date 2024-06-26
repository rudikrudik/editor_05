#include "view.hpp"
#include "iostream"

MainView::MainView(const GraphicDocument& model_): model{model_} {
    draw();
}

void MainView::draw() {
    std::cout << "**********" << std::endl;
    std::cout << "draw primitive: ";

    const auto& representations = model.get_elements_presentations();

    if(representations.empty())
        std::cout << "no figures add " << std::endl;
    else {
        std::cout << std::endl;
        for (auto& representation: model.get_elements_presentations())
            std::cout << representation << std::endl;
    }

    std::cout << "end primitive " << std::endl;
    std::cout << "**********" << std::endl;
}