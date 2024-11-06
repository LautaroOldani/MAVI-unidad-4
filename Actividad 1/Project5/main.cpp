#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    string ruta = "crosshair.png";

    Texture texture;
    if (!texture.loadFromFile(ruta)) {
        cout << "Error al cargar la textura" << endl;
        return 1; 
    }

    Sprite sprite;
    sprite.setTexture(texture);

    float height = texture.getSize().y;
    float width = texture.getSize().x;

    sprite.setPosition(400 - (width / 2), 300 - (height / 2));

    RenderWindow App(VideoMode(800, 600, 32), "");

    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }

        App.clear();
        App.draw(sprite);
        App.display();
    }

    return 0;
}
