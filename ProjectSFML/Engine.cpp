#include "include/Engine.h"
Engine::Engine() :  window(new sf::RenderWindow),
                    _ptrplayer(new Player),
                    _ptrdeb(new DebugInteface),
                    _ptrcameraPlayer(new Camera),
                    _ptrcursor(new Cursor)
{
    std::cout << "_window CREATE" << std::endl;
    window->create(sf::VideoMode(1280, 720), "Demo!", sf::Style::Close);
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(1);
    window->setMouseCursor(*(_ptrcursor->getCursor()));
}
Engine::~Engine() 
{ 
    if (_ptrdeb != nullptr && _ptrcameraPlayer != nullptr 
        && _ptrplayer != nullptr && window != nullptr && _ptrcursor != nullptr)
    { 
        delete              _ptrdeb;
        delete              _ptrplayer;
        delete              _ptrcameraPlayer;
        delete              window;
        delete              _ptrcursor;
                            
                            _ptrcursor = nullptr;
                            _ptrdeb = nullptr;
                            _ptrplayer = nullptr;
                            _ptrcameraPlayer = nullptr;
                            window = nullptr;

        std::cout<<"_ptrdeb DEL\n";
        std::cout << "_ptrcameraPlayer DEL\n";
        std::cout << "player DEL\n";
        std::cout << "_ptrcursor DEL\n";
        std::cout << "_window DEL" << std::endl;
    }
}
void Engine::_renderPlayer() 
{
    window->setView(*(_ptrcameraPlayer->getView()));
    window->draw(_ptrplayer->getSprite());
}
void Engine::_renderDebugInfo() 
{
    window->setView(window->getDefaultView());
    window->draw(_ptrdeb->getTextDebug());
}

void Engine::render() 
{
    window->clear(sf::Color::Cyan);
    Engine::_renderPlayer();
    Engine::_renderDebugInfo();
    window->display();
}
void Engine::toggleDebug() 
{
    if (!_ptrdeb->isDebug())
    {
        _ptrdeb->degubACTIVE();
    }
    else _ptrdeb->degubDISABLE();
}
void Engine::handleKeyPressed(sf::Keyboard::Key key) 
{
    switch (key)
    {
    case sf::Keyboard::Tab:
        Engine::toggleDebug();
        break;
    case sf::Keyboard::H:
        if (!_ptrplayer->isHIT()) 
        {
            _ptrplayer->playerKKP();
        }
        break;
    case sf::Keyboard::LShift:
        _ptrplayer->playerKSHIFTP();
        break;
    case sf::Keyboard::A:
        _ptrplayer->playerKLP();
        break;
    case sf::Keyboard::D:
        _ptrplayer->playerKRP();
        break;
    case sf::Keyboard::W:
        _ptrplayer->playerKUP();
        break;
    case sf::Keyboard::S:
        _ptrplayer->playerKDP();
        break;
    default:
        break;
    }
}
void Engine::handleKeyReleased(sf::Keyboard::Key key) 
{
    switch (key)
    {
    case sf::Keyboard::H:
        _ptrplayer->playerKKR();
        break;
    case sf::Keyboard::A:
        _ptrplayer->playerKLR();
        break;
    case sf::Keyboard::D:
        _ptrplayer->playerKRR();
        break;
    case sf::Keyboard::W:
        _ptrplayer->playerKUR();
        break;
    case sf::Keyboard::S:
        _ptrplayer->playerKDR();
        break;
    default:
        break;
    }
}

void Engine::input() 
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            Engine::handleKeyPressed(event.key.code);
            break;
        case sf::Event::KeyReleased:
            Engine::handleKeyReleased(event.key.code);
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                _ptrplayer->playerKMOUSELEFT_P();
            }
            break;
        default:
            break;
        }

    }
}

void Engine::update(float dtAsSeconds)
{
    _ptrcameraPlayer->updateCAMERA(_ptrplayer, dtAsSeconds);
    _ptrplayer->updatePLAYER(dtAsSeconds);
    _ptrdeb->updateDEBUG(window, _ptrcameraPlayer, _ptrplayer, dtAsSeconds);
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

    while (window->isOpen())
    {
        sf::Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        _ptrplayer->soundPLAYERALL();
        input();
        update(dtAsSeconds);
        render();
    }
}
