#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>

class Enemy {
public:
    sf::Sprite sprite;
    bool active;

    Enemy(const sf::Texture& texture, int windowWidth, int windowHeight) {
        sprite.setTexture(texture);
        sprite.setScale(0.2f, 0.2f); 
        respawn(windowWidth, windowHeight);
    }

    void respawn(int windowWidth, int windowHeight) {
        active = true;
        int x = rand() % (windowWidth - static_cast<int>(sprite.getGlobalBounds().width));
        int y = rand() % (windowHeight - static_cast<int>(sprite.getGlobalBounds().height));
        sprite.setPosition(x, y);
    }
};

class Crosshair {
public:
    sf::Sprite sprite;

    Crosshair(const sf::Texture& texture) {
        sprite.setTexture(texture);
        sprite.setScale(0.1f, 0.1f); 
    }

    void updatePosition(const sf::Vector2i& mousePosition) {
        sprite.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    sf::RenderWindow window(sf::VideoMode(1050, 800), "Juego de Crosshair");

   
    sf::Texture enemyTexture, crosshairTexture;
    if (!enemyTexture.loadFromFile("et.png") || !crosshairTexture.loadFromFile("crosshair.png")) {
        return -1; 
    }

   
    std::vector<Enemy> enemies;
    for (int i = 0; i < 5; i++) {
        enemies.emplace_back(enemyTexture, 800, 800);
    }
    Crosshair crosshair(crosshairTexture);

    int defeatedEnemies = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (auto& enemy : enemies) {
                    if (enemy.active && enemy.sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        enemy.active = false;
                        defeatedEnemies++;
                        if (defeatedEnemies == 5) {
                            window.close(); 
                        }
                        else {
                            enemy.respawn(800, 800); 
                        }
                    }
                }
            }
        }

        crosshair.updatePosition(sf::Mouse::getPosition(window));

        window.clear();
        for (const auto& enemy : enemies) {
            if (enemy.active) {
                window.draw(enemy.sprite);
            }
        }
        window.draw(crosshair.sprite);
        window.display();
    }

    return 0;
}
