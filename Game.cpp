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
#pragma region Loading_Assets
    // For Background
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");
    Sprite spriteBackground(textureBackground);
    spriteBackground.setPosition(0, 0);

    // For Tree
    Texture textureTree;
    textureTree.loadFromFile("graphics/tree2.png");
    Sprite spriteTree(textureTree);
    spriteTree.setPosition(810, 0);

    // For Bee
    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee(textureBee);
    spriteBee.setPosition(0, 800);

    // For Clouds
    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");
    Sprite spriteCloud1(textureCloud);
    Sprite spriteCloud2(textureCloud);
    Sprite spriteCloud3(textureCloud);
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 150);
    spriteCloud3.setPosition(0, 300);

    String messageString = "Enter \'Space Bar\' to Start";
    Font   font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    Text messageText;
    messageText.setFont(font);
    messageText.setFillColor(Color::Cyan);
    messageText.setCharacterSize(70);
    messageText.setString(messageString);
    messageText.setOrigin(messageText.getLocalBounds().width / 2, messageText.getLocalBounds().height / 2);
    messageText.setPosition(1920 / 2, 1080 / 2);

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setFillColor(Color::Red);
    scoreText.setCharacterSize(100);
    scoreText.setString("Score : 0");
    scoreText.setPosition(20, 20);

    Text pauseText;
    pauseText.setFont(font);
    pauseText.setFillColor(Color::Green);
    pauseText.setCharacterSize(80);
    pauseText.setString("Press 'P' to Pause/Unpause");
    pauseText.setOrigin(pauseText.getLocalBounds().width / 2, pauseText.getLocalBounds().height / 2);
    pauseText.setPosition(1920 / 2, 1080 / 2);

    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setFillColor(Color::Green);
    gameOverText.setCharacterSize(80);
    gameOverText.setString("Game Over");
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2, gameOverText.getLocalBounds().height / 2);
    gameOverText.setPosition(2000, 2000);

    RectangleShape timebar(Vector2f(barWidth, barHeight));
    timebar.setFillColor(Color::Red);
    timebar.setPosition(view.getSize().x / 2 - barWidth / 2, view.getSize().y - 75);

    // For Player
    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/player.png");
    Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(Player_L, 720);

    // For Axe
    Texture textureAxe;
    textureAxe.loadFromFile("graphics/axe.png");
    Sprite spriteAxe(textureAxe);
    spriteAxe.setPosition(3000, 830);

    // For Brach
    Texture textureBranch;
    textureBranch.loadFromFile("graphics/branch.png");

    for (int i = 0; i < NUM_BRANCHES; i++) {
        spriteBranches[i].setTexture(textureBranch);
        spriteBranches[i].setOrigin(spriteBranches[i].getLocalBounds().width / 2, spriteBranches[i].getLocalBounds().height / 2);
    }

    // For RIP
    Texture textureRIP;
    textureRIP.loadFromFile("graphics/rip.png");
    Sprite spriteRIP(textureRIP);
    spriteRIP.setPosition(Player_L, 762);

    // For Log
    Texture textureLog;
    textureLog.loadFromFile("graphics/log.png");
    Sprite spriteLog(textureLog);
    spriteLog.setPosition(810, 760);

    //Audio Chop
    SoundBuffer chopBuffer;
    chopBuffer.loadFromFile("sound/chop.wav");
    Sound chop;
    chop.setBuffer(chopBuffer);

    //Audio death
    SoundBuffer chopDeath;
    chopDeath.loadFromFile("sound/death.wav");
    Sound death;
    death.setBuffer(chopDeath);

    //Audio oot
    SoundBuffer chopOOT;
    chopOOT.loadFromFile("sound/out_of_time.wav");
    Sound oot;
    oot.setBuffer(chopOOT);

#pragma endregion
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