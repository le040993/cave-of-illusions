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

#include <assert.h>

#include "graphics.h"
#include "screens.h"
#include "strings.h"

MainMenuScreen::MainMenuScreen(SDL_Renderer* renderer, ProgState& progstate) : Screen()
{
    std::string loc = progstate.globalstrings.GetLocale();
    std::string neutloc = "zxx";
    text[0] = TextContainer(progstate.globalstrings[STRING_NEW_GAME], white, renderer, loc);
    text[1] = TextContainer(progstate.globalstrings[STRING_CONTINUE], white, renderer, loc);
    text[2] = TextContainer(progstate.globalstrings[STRING_LOAD_GAME], white, renderer, loc);
    text[3] = TextContainer(progstate.globalstrings[STRING_OPTIONS], white, renderer, loc);
    text[4] = TextContainer(progstate.globalstrings[STRING_ACHIEVEMENTS], white, renderer, loc);
    text[5] = TextContainer(progstate.globalstrings[STRING_HELP], white, renderer, loc);
    text[6] = TextContainer(progstate.globalstrings[STRING_MAINMENU_SPLASH], white, renderer, loc, 1024);
    text[7] = TextContainer("1:", white, renderer, neutloc);
    text[8] = TextContainer("2:", white, renderer, neutloc);
    text[9] = TextContainer("3:", white, renderer, neutloc);
    text[10] = TextContainer("4:", white, renderer, neutloc);
    text[11] = TextContainer("5:", white, renderer, neutloc);
    text[12] = TextContainer("6:", white, renderer, neutloc);
}

int MainMenuScreen::RunScreen(ProgState& progstate, Window& window)
{
    SDL_Renderer* renderer;
    SDL_Event evt;

    renderer = window.GetRenderer();
    NotImplementedScreen notimplemented(renderer, progstate);

    for (;;)
    {
        window.ClearWindow();
        for (int i = 0; i < 6; ++i)
        {
            assert(i + 7 < 13);
            text[i].RenderText(24, i * 24, renderer);
            text[i + 7].RenderText(0, i * 24, renderer);
        }
        text[6].RenderText(0, 192, renderer);
        window.RenderWindow();
        while (SDL_PollEvent(&evt))
        {
            switch (evt.type)
            {
            case SDL_KEYDOWN:
                switch (evt.key.keysym.scancode)
                {
                case SDL_SCANCODE_1:
                case SDL_SCANCODE_2:
                case SDL_SCANCODE_3:
                case SDL_SCANCODE_4:
                case SDL_SCANCODE_5:
                case SDL_SCANCODE_6:
                    notimplemented.RunScreen(progstate, window);
                    break;
                case SDL_SCANCODE_BACKSPACE:
                    return 0;
                    break;
                case SDL_SCANCODE_ESCAPE:
                    throw ExitException();
                    break;
                default:
                    break;
                }
                break;
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
