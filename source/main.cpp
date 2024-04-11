#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "../header/RenderWindow.h"
#include "../header/Entity.h"
using namespace std;
int main(int argv, char * args[])
{
    if (SDL_Init(SDL_INIT_VIDEO >0))
    {
        cout<<"SDL_ERROR"<<SDL_GetError<<endl;
     }
    if(!IMG_Init(IMG_INIT_PNG))
    {
        cout<<"IMG_init error"<<SDL_GetError()<<endl;
    }
    RenderWindow window("Game", 800, 600);
    SDL_Texture * grassTexture = window.loadTexture("image/button.png");

    vector<Entity> entities ={
            Entity(Vector2f(0,0), grassTexture),
            Entity(Vector2f(100,100), grassTexture),
            Entity(Vector2f(200,200), grassTexture)

    };

    bool gameRunning = true;
    while (gameRunning)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }
        window.clear();
        for(Entity &e : entities)
        {
            window.render(e);
        }
        window.display();
    }
    window.cleanUp();
    SDL_Quit();
 return 0;
}