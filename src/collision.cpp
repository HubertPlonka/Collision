#include "collision.h"
#include "circle.h"
#include "shape.h"

bool Collision::collide(const Circle& circle, const Shape& shape) {
    sf::FloatRect circleBox = circle.shape.getGlobalBounds();
    sf::FloatRect shapeBox = shape.getBounds();

    return circleBox.intersects(shapeBox);
}