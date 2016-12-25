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
#include <unordered_map>

#include "defconfig.h"
#include "strings.h"

std::unordered_map<StringIdent, const char*> InitTranslatedStrings_en()
{
    std::unordered_map<StringIdent, const char*> s;
    s[STRING_LOCALE_NAME] = "English";
    s[STRING_FONTFILE] = DATADIR "font/source-sans-pro/SourceSansPro-Regular.otf";
    s[STRING_IDENT_TITLE] = "The Cave of Illusions";
    s[STRING_PLACEHOLDER] = "This is a placeholder screen.";
    s[STRING_NOTIMPLEMENTED] = "This screen is currently not implemented. Please do not file bug reports regarding the lack"
        "of implementation of this screen; we are fully aware of this and are working to implement this"
        "screen as soon as possible. Please press Backspace to return to the previous screen.";
    s[STRING_NEW_GAME] = "New Game";
    s[STRING_CONTINUE] = "Continue";
    s[STRING_LOAD_GAME] = "Load Game";
    s[STRING_OPTIONS] = "Options";
    s[STRING_ACHIEVEMENTS] = "Achievements";
    s[STRING_HELP] = "Help";
    s[STRING_MAINMENU_SPLASH] = "Welcome to the Cave of Illusions, a roguelike project set in the Innocence Seekers universe. "
        "In this game, you will follow a magical girl as she helps investigate the sudden appearance of "
        "mysterious portals all over the galaxy. It is known that whatever lies beyond these portals changes "
        "every time someone enters or exits them. However, it is known that all of them are linked to the "
        "Cave of Illusions, a strange and magical cave near one of the most northern settlements on the "
        "planet of Ocypsa.\nThis game implements menus that require you to input a specific key to select a "
        "specific choice. The key needed to select a choice is indicated to the left of the choice. Note "
        "that the game engine interprets upper and lower case letters differently, so if you are having "
        "trouble selecting a choice, make sure that Caps Lock is not on.\nThis game is currently under "
        "development, and many features are missing or incomplete. Additionally, save file compatibility is "
        "not guaranteed between versions at this point in time. Bugs are to be expected; should you find "
        "one, please report it to us on the GitHub issue tracker. Additional requested features will be "
        "considered at this point in time; feature requests also go on the issue tracker.\n"
        "The Cave of Illusions version 0.0.1 pre-alpha";
    return s;
}
