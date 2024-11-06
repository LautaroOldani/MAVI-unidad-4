#include <SFML/Graphics.hpp>

int main() {
   
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana", sf::Style::Resize | sf::Style::Close);
    window.setFramerateLimit(60);

   
    const unsigned int minWidth = 100;
    const unsigned int minHeight = 100;
    const unsigned int maxWidth = 1000;
    const unsigned int maxHeight = 1000;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::Resized) {
             
                unsigned int newWidth = std::max(minWidth, std::min(event.size.width, maxWidth));
                unsigned int newHeight = std::max(minHeight, std::min(event.size.height, maxHeight));
                window.setSize(sf::Vector2u(newWidth, newHeight));
            }
        }

       
        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}
