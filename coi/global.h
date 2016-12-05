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

#ifndef GLOBAL_H
#define GLOBAL_H

#include <exception>
#include <vector>

#include "graphics.h"
#include "strings.h"
#include "window.h"

// This exception does not signal an error; rather it signals that there is a
// request to close the program.
class ExitException : public std::exception
{
public:
    ExitException() : std::exception() {};
};

// Program state structures
struct ProgState
{
    TranslatedStrings globalstrings;
    // TODO: Add program state structures
};

// Base class for screens. Do not use this class directly; instead create a new
// class using this class as a parent.
class Screen
{
public:
    Screen(SDL_Renderer* renderer, ProgState& progstate);
    // The RunScreen function returns an integer which is to be interpreted by
    // the parent screen's code.
    virtual int RunScreen(ProgState& progstate, Window& window);
private:
    TextContainer placeholdertext;
protected:
    std::vector<TextContainer> text;
};

// The program class
class Program
{
public:
    Program();
    ~Program();
    void Run();
    Window mainwindow;
private:
    ProgState programstate;
};

#endif /* GLOBAL_H */
