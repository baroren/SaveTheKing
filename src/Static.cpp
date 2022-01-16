#include "Static.h"


void Static::setDelete()
{
	m_isDeleted = true;
}

bool Static::getDelete() const
{
	return m_isDeleted;
}
void Static::setOpacity(int opacity)
{
	m_sprite.setColor(sf::Color(
		255	, 255, 255, opacity));
}
