#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 600), "4");

    sf::Texture redPointTexture;
    redPointTexture.loadFromFile("rcircle.png");

    sf::Texture yellowSquareTexture;
    yellowSquareTexture.loadFromFile("cuad_yellow.png");

    sf::Sprite objeto(yellowSquareTexture);

    bool isSquare = true;
    int x = 250, y = 250;

    while (window.isOpen()) {
        sf::Event event;

        objeto.setPosition(250, 250);

        while (window.pollEvent(event)) {

            if (isSquare) {
                objeto.setScale(0.25, 0.25);
                objeto.setTexture(yellowSquareTexture);
            }
            else {
                objeto.setScale(1, 1);
                objeto.setTexture(redPointTexture);
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (isSquare) {
                        isSquare = false;
                    }
                    else {
                        isSquare = true;
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed) {

                if (event.key.code == sf::Keyboard::A) {
                    if (x > 0) {
                        x -= 1;
                    }
                }

                if (event.key.code == sf::Keyboard::S) {
                    if (y < 600 - 128) {
                        y += 1;
                    }
                }

                if (event.key.code == sf::Keyboard::D) {
                    if (x < 1024 - 128) {
                        x += 1;
                    }
                }

                if (event.key.code == sf::Keyboard::W) {
                    if (y > 0) {
                        y -= 1;
                    }
                }
            }


        }

        window.clear();

        objeto.setPosition(x, y);
        window.draw(objeto);

        window.display();
    }
}