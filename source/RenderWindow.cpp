//
// Created by trung on 4/7/2024.
//

#include "../header/RenderWindow.h"
#include "../header/Entity.h"

using namespace std;
RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h)
:window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        cout<<"Window failed to init. Error: "<<SDL_GetError()<<endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); ;

}
SDL_Texture * RenderWindow::loadTexture(const char *p_filePath)
{
    SDL_Texture * texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    if(texture == NULL)
    {
        cout<<"Failed to load texture. Error: "<<SDL_GetError()<<endl;
    }
    return texture;
}
void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}
void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}
void RenderWindow::render(Entity &p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;
    //Đoạn mã này đang tạo một cấu trúc `SDL_Rect` tên là `dst`, sau đó sử dụng nó để sao chép texture đến renderer.
    //
    //1. `SDL_Rect dst; dst.x = p_entity.getX(); dst.y = p_entity.getY(); dst.w = p_entity.getCurrentFrame().w; dst.h = p_entity.getCurrentFrame().h;`: Đây là khai báo và khởi tạo một cấu trúc `SDL_Rect` tên là `dst`. `dst` đại diện cho một hình chữ nhật có góc trên cùng bên trái tại vị trí của entity và có kích thước bằng với kích thước của frame hiện tại của entity.
    //
    //2. `SDL_RenderCopy(renderer, p_entity.getTexture(), &p_entity.getCurrentFrame(), &dst);`: Hàm này sao chép một phần của texture đến một phần của renderer. Trong trường hợp này, nó sẽ sao chép frame hiện tại của entity đến vị trí của entity trên renderer.
    SDL_Rect dst;
    dst.x = p_entity.getPosition().x;
    dst.y = p_entity.getPosition().y;
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}