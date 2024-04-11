//
// Created by trung on 4/9/2024.
//

#ifndef GAMELEARN_ENTITY_H
#define GAMELEARN_ENTITY_H
#include <SDL.h>
#include <SDL_image.h>
#include "Math.h"

class Entity {
public :
    Entity(Vector2f p_pos ,SDL_Texture * p_texture);

    Vector2f &getPosition()
    {
        return pos ;
    }

    const SDL_Rect &getCurrentFrame() const;

    SDL_Texture *getTexture() const;

private :
    Vector2f pos;
    SDL_Rect currentFrame;
SDL_Texture * texture;
};


#endif //GAMELEARN_ENTITY_H
