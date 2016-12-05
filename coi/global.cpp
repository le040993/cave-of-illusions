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


#include <stdexcept>
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"

#include "global.h"
#include "graphics.h"
#include "strings.h"

Screen::Screen(SDL_Renderer* renderer, ProgState& progstate)
{
    std::string loc = progstate.globalstrings.GetLocale();
    placeholdertext = TextContainer(progstate.globalstrings[STRING_PLACEHOLDER], white, renderer, loc);
}

int Screen::RunScreen(ProgState& /*progstate*/, Window& window)
{
    SDL_Event evt;

    for (;;)
    {
        window.ClearWindow();
        placeholdertext.RenderText(0, 0, window.GetRenderer());
        window.RenderWindow();
        while (SDL_PollEvent(&evt))
        {
            switch (evt.type)
            {
            case SDL_KEYDOWN:
                switch (evt.key.keysym.scancode)
                {
                case SDL_SCANCODE_ESCAPE:
                    return 0;
                    break;
                default:
                    break;
                }
            case SDL_QUIT:
                throw ExitException();
                break;
            default:
                break;
            }
        }
        SDL_Delay(15);
    }
}

Program::Program()
{
    std::string exceptstr;
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        exceptstr = "Unable to initialize SDL library: ";
        exceptstr += SDL_GetError();
        throw std::runtime_error(exceptstr);
    }
    if (TTF_Init())
    {
        exceptstr = "Unable to initialize SDL_ttf library: ";
        exceptstr += SDL_GetError();
        SDL_Quit();
        throw std::runtime_error(exceptstr);
    }
    TranslatedStrings::globalstrings = &programstate.globalstrings;
}

Program::~Program()
{
    TTF_Quit();
    SDL_Quit();
}

void Program::Run()
{
    programstate.globalstrings.SetLocale("en");
    mainwindow.InitializeWindow(programstate.globalstrings[STRING_IDENT_TITLE], 1024, 768, 0);
    Screen screen(mainwindow.GetRenderer(), programstate);
    try
    {
        screen.RunScreen(programstate, mainwindow);
    }
    catch (ExitException&)
    {
        // TODO: Add code to save game state
    }
}
