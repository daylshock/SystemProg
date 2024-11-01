#include "include/Engine.h"
Engine::Engine() 
{
    window.create(sf::VideoMode(1280, 720), "Demo!", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(1);
}

void Engine::render() 
{
   
    window.clear(sf::Color::Cyan);
    window.setView(view);
    window.draw(player.getSprite());
    window.setView(window.getDefaultView());
    window.draw(deb.getTextDebug());
    window.display();
}

void Engine::input() 
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab) 
        {
            if (!deb.isDebug())
            {
                deb.degubACTIVE();
            }
            else deb.degubDISABLE();
        }
        if (event.type == sf::Event::KeyPressed) 
        {
            if (event.key.code == sf::Keyboard::H && !player.isHIT())
            {
                player.playerKKP();
            }
            if (event.key.code == sf::Keyboard::LShift) 
            {
                player.playerKSHIFTP();
            }
            if (event.key.code == sf::Keyboard::A)
            {
                player.playerKLP();
            }
            if (event.key.code == sf::Keyboard::D)
            {
                player.playerKRP();
            }
            if (event.key.code == sf::Keyboard::W)
            {
                player.playerKUP();
            }
            if (event.key.code == sf::Keyboard::S)
            {
                player.playerKDP();
            }
        }
        if (event.type == sf::Event::KeyReleased) 
        {
            if (event.key.code == sf::Keyboard::H)
            {
                player.playerKKR();
            }
            if (event.key.code == sf::Keyboard::A)
            {
                player.playerKLR();
            }
            if (event.key.code == sf::Keyboard::D)
            {
                player.playerKRR();
            }
            if (event.key.code == sf::Keyboard::W)
            {
                player.playerKUR();
            }
            if (event.key.code == sf::Keyboard::S)
            {
                player.playerKDR();
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) 
        {
            if (event.mouseButton.button == sf::Mouse::Left) 
            {
                player.playerKMOUSELEFT_P();
            }
        }
    }
}
void Engine::update(float dtAsSeconds)
{
    cam.updateCamera(window, view, player, dtAsSeconds);
    player.update(dtAsSeconds);
    deb.updateDEBUG(window, player, dtAsSeconds);
}

void Engine::start() 
{
    sf::Clock clock;

    sf::SoundBuffer buffer;
    sf::Sound sound;
    buffer.loadFromFile("BGS Loops/Forest Day/Forest Day.wav");
    sound.setBuffer(buffer);
    sound.play();
    sound.setVolume(40);
    sound.setLoop(true);

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        player.soundPLAYERALL();
        input();
        update(dtAsSeconds);
        render();
    }
}
