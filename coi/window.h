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

#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>
#include <string>
#include "SDL.h"

// Class for individual windows
class Window
{
public:
    Window& operator=(Window&) = delete;
    Window& operator=(Window&& other);
    Window();
    Window(Window&) = delete;
    Window(Window&& other);
    ~Window();
    void InitializeWindow(const char* title, int w, int h, std::uint32_t flags);
    void InitializeWindow(std::string& title, int w, int h, std::uint32_t flags);
    int GetHeight() const;
    int GetWidth() const;
    void ClearWindow();
    void RenderWindow();
    SDL_Renderer* GetRenderer() const;
    SDL_Window* GetWindow() const;
private:
    void CreateWindowAndRenderer(const char* title, int w, int h, std::uint32_t flags);
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
};

#endif /* WINDOW_H */
