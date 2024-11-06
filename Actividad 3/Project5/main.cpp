#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace sf;

int main() {
    Texture redTexture, blueTexture;

 
    if (!redTexture.loadFromFile("rcircle.png")) {
        return -1;
    }
    if (!blueTexture.loadFromFile("CIRCULO AZUL.png")) {
        return -2;
    }
    IntRect redSize(0, 0, redTexture.getSize().x, redTexture.getSize().y);
 
    std::vector<Sprite> redCircles;
    std::vector<Sprite> blueCircles;

    RenderWindow App(VideoMode(800, 600), "Círculos de Colores");

    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();

           
            if (event.type == Event::MouseButtonPressed) {
                Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));

                if (event.mouseButton.button == Mouse::Left) {
                    
                    Sprite redSprite;
                    redSprite.setTexture(redTexture);
                    redSprite.setPosition(mousePos.x - redTexture.getSize().x / 2, mousePos.y - redTexture.getSize().y / 2);
                    redCircles.push_back(redSprite);
                }
                else if (event.mouseButton.button == Mouse::Right) {
                    
                    Sprite blueSprite;
                    blueSprite.setTexture(blueTexture);
                    blueSprite.setPosition(mousePos.x - blueTexture.getSize().x / 2, mousePos.y - blueTexture.getSize().y / 2);
                    blueCircles.push_back(blueSprite);
                }
            }
        }

       
        App.clear();
        for (const auto& circle : redCircles) {
            App.draw(circle);
        }
        for (const auto& circle : blueCircles) {
            App.draw(circle);
        }
        App.display();
    }

    return 0;
}
