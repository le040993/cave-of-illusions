//------------------------------------------------------------------------------
//
// The Cave of Illusions
//
//------------------------------------------------------------------------------
//
// Copyright (c) 2016 le040993 (Innocence Seekers Project)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//------------------------------------------------------------------------------
//
// Website of the Innocence Seekers Project:
// https://www.innocenceseekers.net/
// GitHub repository:
// https://github.com/le040993/cave-of-illusions
//
//------------------------------------------------------------------------------

#include <cstdint>
#include <stdexcept>
#include <string>
#include "SDL.h"

#include "window.h"

Window::Window()
{
    window = nullptr;
    renderer = nullptr;
    width = 0;
    height = 0;
}

Window::Window(Window&& other)
{
    if (window || renderer)
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    }
    window = other.window;
    renderer = other.renderer;
    width = other.width;
    height = other.height;
}

Window& Window::operator=(Window&& other)
{
    if (window || renderer)
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    }
    window = other.window;
    renderer = other.renderer;
    width = other.width;
    height = other.height;
    return *this;
}

void Window::InitializeWindow(const char* title, int w, int h, std::uint32_t flags)
{
    CreateWindowAndRenderer(title, w, h, flags);
}

void Window::InitializeWindow(std::string& title, int w, int h, std::uint32_t flags)
{
    CreateWindowAndRenderer(title.c_str(), w, h, flags);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int Window::GetHeight() const
{
    return height;
}

int Window::GetWidth() const
{
    return width;
}

void Window::ClearWindow()
{
    SDL_RenderClear(renderer);
}

void Window::RenderWindow()
{
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::GetRenderer() const
{
    return renderer;
}

SDL_Window* Window::GetWindow() const
{
    return window;
}

void Window::CreateWindowAndRenderer(const char* title, int w, int h, std::uint32_t flags)
{
    std::string exceptstr;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
    if (!window)
    {
        exceptstr = "Unable to create SDL window: ";
        exceptstr += SDL_GetError();
        throw std::runtime_error(exceptstr);
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    }
    else
    {
        exceptstr = "Unable to create SDL rendering context: ";
        exceptstr += SDL_GetError();
        throw std::runtime_error(exceptstr);
    }
    width = w;
    height = h;
}
