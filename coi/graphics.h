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

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <cstdint>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

#include "defconfig.h"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
# define RMASK 0xff000000
# define GMASK 0x00ff0000
# define BMASK 0x0000ff00
# define AMASK 0x000000ff
#else
# define RMASK 0x000000ff
# define GMASK 0x0000ff00
# define BMASK 0x00ff0000
# define AMASK 0xff000000
#endif

#define NORMALFONTSIZE 16

#define LOCALEINDEPENDENTFONT DATADIR "font/source-code-pro/SourceCodePro-Regular.otf"

const SDL_Color white = { 255, 255, 255, 255 };
const SDL_Color red = { 255, 0, 0, 255 };
const SDL_Color green = { 0, 255, 0, 255 };
const SDL_Color blue = { 0, 0, 255, 255 };
const SDL_Color cyan = { 0, 255, 255, 255 };
const SDL_Color magenta = { 255, 0, 255, 255 };
const SDL_Color yellow = { 255, 255, 0, 255 };
const SDL_Color orange = { 255, 128, 0, 255 };
const SDL_Color purple = { 128, 0, 255, 255 };
const SDL_Color pink = { 255, 170, 170, 255 };

// Class for rendered text.
class TextContainer
{
public:
    TextContainer& operator=(TextContainer&) = delete;
    TextContainer& operator=(TextContainer&&);
    TextContainer();
    TextContainer(TextContainer&) = delete;
    TextContainer(TextContainer&& other);
    TextContainer(const char* string, SDL_Color color, SDL_Renderer* renderer, std::string& locale, std::uint32_t width = 0);
    ~TextContainer();
    void RenderText(int x, int y, SDL_Renderer* renderer) const;
    void RenderText(int x, int y, SDL_Renderer* renderer, bool rightjust) const;
    void GetTextSize(int* w, int* h) const;
    static void FreeAllFonts();
private:
    SDL_Texture *text;
    static void ChangeLocale(std::string& locale);
    static TTF_Font* lifont;
    static TTF_Font* ldfont;
    static std::string curlocale;
};

#endif /* GRAPHICS_H */
