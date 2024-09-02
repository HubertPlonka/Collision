#pragma once

#include "shape.h"
#include <vector>

class ShapeManager
{
public:
	void addShape( std::shared_ptr< MyShape > shape );
	void drawAll( sf::RenderWindow& window );
	const std::vector< std::shared_ptr< MyShape > > getShapes() const;
	std::vector< std::shared_ptr< MyShape > > shapes;
};