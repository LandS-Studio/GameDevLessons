#pragma once
#include <SFML/Graphics.hpp>

enum class PlayerOrientation {
	Left,
	Right
};

class Player {
public:
	Player(sf::RenderWindow* window);

	void update();
	void draw();

	const sf::Sprite& getSprite() const { return m_sprite; };

private:
	void handleInput();

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::RenderWindow* m_window = nullptr;

	sf::Vector2f m_spriteScale;
	sf::Vector2f m_position;
	PlayerOrientation m_orientation = PlayerOrientation::Right;
	PlayerOrientation m_newOrientation = PlayerOrientation::Right;
};