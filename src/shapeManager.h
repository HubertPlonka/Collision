#pragma once

#include "shape.h"
#include <vector>

class ShapeManager
{
public:
	void addShape( std::shared_ptr< MyShape > shape );// const std::shared_ptr< MyShape >& instead copy https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#fcall-parameter-passing
	void drawAll( sf::RenderWindow& window );
	const std::vector< std::shared_ptr< MyShape > > getShapes() const; // maybe std::vector< std::shared_ptr< MyShape > >& reference? 
	std::vector< std::shared_ptr< MyShape > > shapes; // why it is public? I think it should be private for class
};