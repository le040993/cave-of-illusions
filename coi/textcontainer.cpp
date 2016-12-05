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

#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

#include "graphics.h"
#include "strings.h"

TTF_Font* TextContainer::lifont;
TTF_Font* TextContainer::ldfont;
std::string TextContainer::curlocale;

TextContainer::TextContainer()
{
    text = nullptr;
}

TextContainer::TextContainer(TextContainer&& other)
{
    if (text)
        SDL_DestroyTexture(text);
    text = other.text;
    other.text = nullptr;
}

TextContainer::TextContainer(const char* string, SDL_Color color, SDL_Renderer* renderer, std::string& locale, std::uint32_t width)
{
    SDL_Surface* surface;
    std::string exceptstr;
    TTF_Font* font;
    if (!string)
    {
        exceptstr = "Unable to create TextContainer: Pointer to string must not be null.";
        throw std::runtime_error(exceptstr);
    }
    if (locale == "zxx")
    {
        if (!lifont)
        {
            lifont = TTF_OpenFont(LOCALEINDEPENDENTFONT, NORMALFONTSIZE);
            if (!lifont)
            {
                exceptstr = "Unable to create TextContainer: ";
                exceptstr += SDL_GetError();
                throw std::runtime_error(exceptstr);
            }
        }
        font = lifont;
    }
    else if (locale == curlocale)
    {
        font = ldfont;
    }
    else
    {
        ChangeLocale(locale);
        font = ldfont;
    }
    if (width)
        surface = TTF_RenderUTF8_Blended_Wrapped(font, string, color, width);
    else
        surface = TTF_RenderText_Blended(font, string, color);
    if (surface)
    {
        text = SDL_CreateTextureFromSurface(renderer, surface);
        if (!text)
        {
            exceptstr = "Unable to create TextContainer: ";
            exceptstr += SDL_GetError();
            SDL_FreeSurface(surface);
            throw std::runtime_error(exceptstr);
        }
        SDL_FreeSurface(surface);
    }
    else
    {
        exceptstr = "Unable to create TextContainer: ";
        exceptstr += SDL_GetError();
        throw std::runtime_error(exceptstr);
    }
}

void TextContainer::RenderText(int x, int y, SDL_Renderer* renderer) const
{
    if (!text)
        return;
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_QueryTexture(text, nullptr, nullptr, &(rect.w), &(rect.h));
    SDL_RenderCopy(renderer, text, nullptr, &rect);
}

void TextContainer::RenderText(int x, int y, SDL_Renderer* renderer, bool rightjust) const
{
    if (!rightjust)
        this->RenderText(x, y, renderer);
    else
    {
        int w;
        SDL_QueryTexture(text, nullptr, nullptr, &w, nullptr);
        this->RenderText(x - w, y, renderer);
    }
}

TextContainer& TextContainer::operator=(TextContainer&& other)
{
    if (text)
        SDL_DestroyTexture(text);
    text = other.text;
    other.text = nullptr;
    return *this;
}

TextContainer::~TextContainer()
{
    if (text)
        SDL_DestroyTexture(text);
}

void TextContainer::GetTextSize(int* w, int* h) const
{
    SDL_QueryTexture(text, nullptr, nullptr, w, h);
}

void TextContainer::ChangeLocale(std::string& locale)
{
    TTF_CloseFont(ldfont);
    const char* fontname = TranslatedStrings::globalstrings->GetFont(locale);
    ldfont = TTF_OpenFont(fontname, NORMALFONTSIZE);
    if (!ldfont)
    {
        std::string exceptstr;
        exceptstr = "Unable to open font: ";
        exceptstr += SDL_GetError();
        throw std::runtime_error(exceptstr);
    }
}

void TextContainer::FreeAllFonts()
{
    TTF_CloseFont(lifont);
    TTF_CloseFont(ldfont);
}
