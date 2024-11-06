#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

int main() {
    Texture texture;
    Sprite s1, s2, s3, s4;

    std::string ruta = "rcircle.png";
    if (!texture.loadFromFile(ruta)) {
        return -1;
    }

    s1.setTexture(texture);
    s2.setTexture(texture);
    s3.setTexture(texture);
    s4.setTexture(texture);

    float width = texture.getSize().x;
    float height = texture.getSize().y;

    s2.setPosition(800 - width, 0);
    s3.setPosition(0, 600 - height);
    s4.setPosition(800 - width, 600 - height);

    RenderWindow App(VideoMode(800, 600), "Fondo");

    
    bool isDragging = false;          
    Sprite* selectedSprite = nullptr; 

    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();

            
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));

                    if (s1.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        selectedSprite = &s1;
                    }
                    else if (s2.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        selectedSprite = &s2;
                    }
                    else if (s3.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        selectedSprite = &s3;
                    }
                    else if (s4.getGlobalBounds().contains(mousePos)) {
                        isDragging = true;
                        selectedSprite = &s4;
                    }
                }
            }

           
            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    isDragging = false;
                    selectedSprite = nullptr;
                }
            }
        }

       
        if (isDragging && selectedSprite) {
            Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));
            selectedSprite->setPosition(mousePos.x - width / 2, mousePos.y - height / 2);
        }

        
        App.clear();
        App.draw(s1);
        App.draw(s2);
        App.draw(s3);
        App.draw(s4);
        App.display();
    }

    return 0;
}

