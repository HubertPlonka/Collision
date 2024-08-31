#include "shapeManager.h"

void ShapeManager::addShape( std::shared_ptr< MyShape > shape )
{
	shapes.push_back( shape );
}

void ShapeManager::drawAll( sf::RenderWindow& window )
{
	for( const auto& shape : shapes )
	{
		shape->draw( window );
	}
}

const std::vector< std::shared_ptr< MyShape > > ShapeManager::getShapes() const
{
	return shapes;
}