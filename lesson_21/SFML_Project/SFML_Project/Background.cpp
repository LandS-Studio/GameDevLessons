#include "Background.h"

Background::Background(sf::RenderWindow* window) : m_window(window), m_texture("resource/background.png"), m_sprite(m_texture)
{
	
	sf::Vector2u windowSize = m_window->getSize();

	m_texture.setRepeated(true);
	m_sprite.setTextureRect(sf::IntRect({ 0, 0 }, { static_cast<int>(windowSize.x), static_cast<int>(windowSize.y) }));

}

void Background::draw()
{
	m_window->draw(m_sprite);
}