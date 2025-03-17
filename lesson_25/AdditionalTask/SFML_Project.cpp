#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

// Function for normalize vector
sf::Vector2f normalize(const sf::Vector2f& vector) {
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length != 0) {
		return sf::Vector2f(vector.x / length, vector.y / length);
	}
	return sf::Vector2f(0.f, 0.f);
}

// Function for text creation
sf::Text createText(const sf::Font& font, const std::string& text, sf::Vector2f position, unsigned int size = 20) {
	sf::Text newText(font, text, size);
	newText.setFillColor(sf::Color::White);
	newText.setString(text);
	newText.setPosition(position);

	return newText;
}

// Function for arrow creation
sf::VertexArray createArrow(sf::Vector2f start, sf::Vector2f end, float thikness = 2.f) {
	sf::Vector2f direction = normalize(end - start);
	sf::Vector2f perpendicular(-direction.y, direction.x);

	sf::Vector2f arrBase1 = start + perpendicular * thikness;
	sf::Vector2f arrBase2 = start - perpendicular * thikness;

	sf::VertexArray arrow(sf::PrimitiveType::TriangleStrip);
	arrow.append(sf::Vertex(arrBase1, sf::Color::Green));
	arrow.append(sf::Vertex(arrBase2, sf::Color::Green));
	arrow.append(sf::Vertex(sf::Vector2f(end), sf::Color::Green));

	return arrow;
}

int main() {
	// Create window
	sf::RenderWindow window(sf::VideoMode{ {1366, 720} }, "SFML Project", sf::Style::Close);
	window.setFramerateLimit(60);

	// Create font
	sf::Font font;
	if (!font.openFromFile("arial.ttf")) {
		return -1;
	}

	// Vector for vizualization
	sf::Vector2f vectorA(100.f, 200.f);
	sf::Vector2f vectorB(300.f, 100.f);

	sf::Vector2f origin(400.f, 300.f);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		// Calculate result operation
		sf::Vector2f sum = vectorA + vectorB;
		sf::Vector2f diff = vectorA - vectorB;

		// Clear window
		window.clear();

		// Draw vectors
		window.draw(createArrow(origin, origin + vectorA));
		window.draw(createArrow(origin, origin + vectorB));
		window.draw(createArrow(origin, origin + sum));
		window.draw(createArrow(origin, origin + diff));

		// Draw text
		window.draw(createText(font, "A", origin + vectorA + sf::Vector2f(10.f, 10.f)));
		window.draw(createText(font, "B", origin + vectorB + sf::Vector2f(10.f, 10.f)));
		window.draw(createText(font, "A + B", origin + sum + sf::Vector2f(10.f, 10.f)));
		window.draw(createText(font, "A - B", origin + diff + sf::Vector2f(10.f, 10.f)));

		// Display window
		window.display();
	}



    return 0;
}