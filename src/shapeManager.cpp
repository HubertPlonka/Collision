#include "shapeManager.h"

void ShapeManager::addShape(Shape* shape) {
    shapes.push_back(shape);
}

void ShapeManager::drawAll(sf::RenderWindow& window) {
    for (Shape* shape : shapes) {
        shape->draw(window);
    }
}

const std::vector<Shape*>& ShapeManager::getShapes() const { 
    return shapes;
}