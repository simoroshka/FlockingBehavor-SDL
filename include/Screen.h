#ifndef SCREEN_H
#define SCREEN_H

#include <cstring>
#include <SDL2/SDL.h>


namespace mysdl {
class Screen
{
    public:
        const static int WIDTH = 500;
        const static int HEIGHT = 500;


    protected:
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;

    public:
        Screen();
        bool init();
        bool ProcessEvents();
        void update();
        void clear();
        void boxBlur();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        void close();


        virtual ~Screen();
};
}
#endif // SCREEN_H
