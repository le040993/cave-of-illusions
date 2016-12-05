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

#ifndef STRINGS_H
#define STRINGS_H

#include <string>
#include <unordered_map>

// Indexes to each string in the globalstrings structure.
enum StringIdent
{
    STRING_LOCALE_NAME,
    STRING_FONTFILE,
    STRING_IDENT_TITLE,
    STRING_PLACEHOLDER,
};

// Class holding translated strings
class TranslatedStrings
{
public:
    TranslatedStrings();
    void SetLocale(std::string& locstring);
    void SetLocale(const char* locstring);
    const char* GetLocaleName(std::string& locstring) const;
    const char* GetLocaleName(const char* locstring) const;
    std::string GetLocale() const;
    const char* GetFont(std::string& locstring) const;
    const char* GetFont(const char* locstring) const;
    const char* operator[](StringIdent idx) const;
    static TranslatedStrings* globalstrings;
private:
    std::unordered_map<std::string, std::unordered_map<StringIdent, const char*>> transstrings;
    std::string curlocale;
};

std::unordered_map<StringIdent, const char*> InitTranslatedStrings_en();

#endif /* STRINGS_H */
