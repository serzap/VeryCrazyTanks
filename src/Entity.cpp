#include "Entity.h"

Entity::Entity() = default;

Entity::Entity(int x, int y, int hp, DrawingStrategy* ds) : m_x(x), m_y(y), m_hitPoints(hp), m_ds(ds) {}

Entity::~Entity() 
{
	delete m_ds;
}

void Entity::draw(Map & map)
{
	m_ds->execute(map, m_x, m_y);
}



