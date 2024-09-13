#pragma once

#include "shape.h"
#include <vector>
#include <memory>

class ShapeManager {
public:
    void addShape(std::shared_ptr<Shape> shape);
    void drawAll(sf::RenderWindow& window);
    const std::vector<std::shared_ptr<Shape>>& getShapes() const;
    std::vector<std::shared_ptr<Shape>>& getShapes();

private:
    std::vector<std::shared_ptr<Shape>> shapes;
};