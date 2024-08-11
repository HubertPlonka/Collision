#pragma once

#include "shape.h"
#include <vector>

class ShapeManager {
public:
	void addShape(std::shared_ptr<Shape> shape);
	void drawAll(sf::RenderWindow& window);
	const std::vector<std::shared_ptr<Shape>> getShapes() const;
//private:
	std::vector<std::shared_ptr<Shape>> shapes;
};