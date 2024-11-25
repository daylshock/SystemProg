#include "include/CursorPixel.h"

Cursor::Cursor() :  _imageCur(new sf::Image),
                    _cursor(new sf::Cursor),
                    isClick(false)
{
    std::cout << "_imageCur CREATE\n";
    std::cout << "_cursor CREATE" << std::endl;
    if (Cursor::setCursor());
    else { std::cout << "ERROR CURSOR LOAD!\n"; }
}
Cursor::~Cursor() 
{
	if (_imageCur != nullptr && _cursor != nullptr) 
	{
        delete              _imageCur;
        delete              _cursor;

                            _imageCur = nullptr;
                            _cursor = nullptr;

                            std::cout << "_imageCur DEL\n";
                            std::cout << "_cursor DEL" << std::endl;
	}
}

bool Cursor::setCursor() 
{
    if (!_imageCur->loadFromFile("Cursor/imagecursor.png")) { return false; }
    if (!_cursor->loadFromPixels(_imageCur->getPixelsPtr(), _imageCur->getSize(), sf::Vector2u(0, 0))) { return false; }
    return true;
}
sf::Cursor* Cursor::getCursor() { return _cursor; }