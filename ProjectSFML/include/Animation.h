#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

struct Frame {
    sf::IntRect rect;
    double duration;
};

class Animation 
{
private:
    std::vector<Frame> frames;
    double totalLength;
    double totalProgress;
    sf::Sprite* target;
public:
    Animation(sf::Sprite& target);
    void addFrame(Frame frame);
    void update(float elapsed);
};