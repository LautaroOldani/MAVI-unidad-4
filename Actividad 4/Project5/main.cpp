#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mover y Cambiar Forma");
    window.setFramerateLimit(60);

    
    sf::Texture squareTexture, circleTexture;
    if (!squareTexture.loadFromFile("cuad_yellow.png") || !circleTexture.loadFromFile("rCircle.png")) {
        return -1;
    }

    
    sf::Sprite shapeSprite(squareTexture);
    shapeSprite.setPosition(400, 300);

    
    shapeSprite.setScale(0.5, 0.5); 

    bool isSquare = true; 

   
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                
                isSquare = !isSquare;
                shapeSprite.setTexture(isSquare ? squareTexture : circleTexture);
            }
        }

      
        float speed = 5.0f;
        sf::Vector2f position = shapeSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && position.y > 0) {
            position.y -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && position.y + shapeSprite.getGlobalBounds().height < 600) {
            position.y += speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && position.x > 0) {
            position.x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && position.x + shapeSprite.getGlobalBounds().width < 800) {
            position.x += speed;
        }

        shapeSprite.setPosition(position);

        
        window.clear();
        window.draw(shapeSprite);
        window.display();
    }

    return 0;
}
