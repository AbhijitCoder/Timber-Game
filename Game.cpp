#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace sf;

VideoMode vm(1920, 1080);
RenderWindow window(vm,"Timber", Style::Fullscreen);
View view(FloatRect(0, 0, 1920, 1080));
window.setView(view);
Clock clock;
Time dt;
while (window.isOpen()) {
        dt = clock.restart();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape)
                    window.close();
            }
        }
    }
    window.clear();
    window.display();