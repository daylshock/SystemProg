#include "include/Animation.h"
Animation::Animation(sf::Sprite& target) {
    this->target = &target;
    totalProgress = 0.0;
    totalLength = 0.0;
}

void Animation::addFrame(Frame frame) {
    frames.push_back(std::move(frame));
    totalLength += frame.duration;
}

void Animation::update(float elapsed) {
    totalProgress += elapsed;
    double progress = totalProgress;
     
    if (totalProgress >= totalLength) {
        totalProgress = fmod(totalProgress, totalLength);
    }

    for (auto& frame : frames)
    {
        progress -= frame.duration;
        if (progress <= 0.0 || &frame == &frames.back() )
        {
            target->setTextureRect(frame.rect);
            break;
        }
    }
}