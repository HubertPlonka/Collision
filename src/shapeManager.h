#pragma once

#include "shape.h"
#include <vector>

class ShapeManager {
public:
	void addShape(Shape* shape);
	void drawAll(sf::RenderWindow& window);
	const std::vector<Shape*>& getShapes() const;
//private:
	std::vector<Shape*> shapes;
};