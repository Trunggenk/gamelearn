//
// Created by trung on 4/9/2024.
//

#include "../header/Entity.h"

Entity::Entity(Vector2f p_pos, SDL_Texture * p_texture)

{
    pos = p_pos;
    texture = p_texture;
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 100;
    currentFrame.h = 100;
}



const SDL_Rect &Entity::getCurrentFrame() const {
    return currentFrame;
}

SDL_Texture *Entity::getTexture() const {
    return texture;
}

