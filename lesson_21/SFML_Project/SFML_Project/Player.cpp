#include "Player.h"

Player::Player(sf::RenderWindow* window)
	: m_window(window), m_texture("resource/player.png"), m_sprite(m_texture), m_orientation(PlayerOrientation::Right)
{
	m_sprite.setOrigin({ m_sprite.getLocalBounds().size.x / 2.0f, m_sprite.getLocalBounds().size.y / 5.0f });
	
	const sf::Vector2u windowSize = m_window->getSize();
	const sf::Vector2u textureSize = m_texture.getSize();
	const float targetHeightRatio = 0.2f;
	const float playerScale = windowSize.y * targetHeightRatio / textureSize.y;

	m_sprite.setScale({ playerScale, playerScale });
	m_spriteScale = m_sprite.getScale();

	m_sprite.setPosition(sf::Vector2f{ windowSize.x / 2.0f, 
		windowSize.y - m_sprite.getGlobalBounds().size.y});

	m_position = m_sprite.getPosition();
}

void Player::update() {
	handleInput();
	m_sprite.setPosition(m_position);

	if (m_orientation != m_newOrientation) {
		m_orientation = m_newOrientation;
		switch (m_orientation)
		{
		case PlayerOrientation::Left:
			m_sprite.setScale({ m_spriteScale.x * -1, m_spriteScale.y });
			break;
		case PlayerOrientation::Right:
			m_sprite.setScale({ m_spriteScale.x, m_spriteScale.y });
			break;
		}
	}
}

void Player::draw() {
	m_window->draw(m_sprite);
}

void Player::handleInput() {
	const float SPEED_X = 8.0f;

	float deltaX = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		deltaX += -SPEED_X;
		m_newOrientation = PlayerOrientation::Left;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		deltaX += SPEED_X;
		m_newOrientation = PlayerOrientation::Right;
	}

	const float offsetByPlayerWidth = m_sprite.getGlobalBounds().size.x / 2.0f;
	const float leftBound = offsetByPlayerWidth;
	const float rightBound = m_window->getSize().x - offsetByPlayerWidth;
	float newPosX = m_position.x + deltaX;
	
	// Check if the player is within the bounds of the window
	if (newPosX < leftBound) m_position.x = leftBound;
	else if (newPosX > rightBound) m_position.x = rightBound;
	else m_position.x += deltaX;
}

