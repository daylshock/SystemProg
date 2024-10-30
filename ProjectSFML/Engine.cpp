#include "include/Engine.h"
#define DEBUG

Engine::Engine() 
{
    window.create(sf::VideoMode(1280, 720), "Demo!", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(1);
}

float Engine::getFPS(float dtAsSeconds) 
{
    float lastTime = 0;
    float fps = 1.f / (dtAsSeconds - lastTime);
    lastTime = dtAsSeconds;
    return fps;
}

void Engine::render() 
{
    window.clear(sf::Color::Cyan);
    window.draw(player.getSprite());
    window.draw(deb.getTextDebug());
    window.display();
}

void Engine::input() 
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Resized)
        {
            sf::FloatRect view(0, 0, (float)event.size.width, (float)event.size.height);
            window.setView(sf::View(view));
        }
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
    player.update(dtAsSeconds);
    deb.updateDEBUG(player, dtAsSeconds);
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
        #ifdef DEBUG
            std::cout << "FPS: " << Engine::getFPS(dtAsSeconds) << std::endl;
        #endif // DEBUG
        player.soundPLAYERALL();
        input();
        update(dtAsSeconds);
        render();
    }
}
