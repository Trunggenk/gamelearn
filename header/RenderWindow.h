//
// Created by trung on 4/7/2024.
//

#ifndef GAMELEARN_RENDERWINDOW_H
#define GAMELEARN_RENDERWINDOW_H

#include "SDL_image.h"
#include "SDL.h"
#include  "Entity.h"
#include <iostream>
class RenderWindow {
public:
RenderWindow(const char* p_title, int p_w, int p_h);
SDL_Texture * loadTexture(const char* p_filePath);
void cleanUp();
void clear();
void render(Entity& p_entity);
void display();
private:
    SDL_Window * window;
    SDL_Renderer* renderer;
};


#endif //GAMELEARN_RENDERWINDOW_H
