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

// This header gives default values for compile-time configuration variables. Do
// NOT alter any of these defaults if your repository is synced to the original;
// the defaults may be changed without notice. If you need to change any of the
// variables for your own build, then the variable and its new value must be
// supplied on the command line. Alternatively, you may supply a config.h file
// and define HAVE_CONFIG_H on the command line. Each setting in the config.h
// file must be set as follows:
//   #undef SETTING
//   #define SETTING newvalue

#pragma once

#ifndef DEFCONFIG_H
#define DEFCONFIG_H

// The location of the folder containing the program's resources. For non-
// portable Unix installations, this should be set to $(PREFIX)/share/games/coi/
// on the command line (e.g. -DDATADIR=/usr/local/share/games/coi/). The default
// value is "./" (the current directory), which is best suited for Windows. The
// trailing slash is mandatory; without it, there may be references to folders
// named "coifont", for example.
#ifndef DATADIR
#define DATADIR "./"
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#endif /* DEFCONFIG_H */
