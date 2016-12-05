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

#include "strings.h"

TranslatedStrings* TranslatedStrings::globalstrings;

TranslatedStrings::TranslatedStrings()
{
    transstrings["en"] = InitTranslatedStrings_en();
}

void TranslatedStrings::SetLocale(std::string& locstring)
{
    // The only purpose of this line is to throw an exception if the locale
    // does not exist.
    transstrings.at(locstring);

    curlocale = locstring;
}

void TranslatedStrings::SetLocale(const char* locstring)
{
    // The only purpose of this line is to throw an exception if the locale
    // does not exist.
    transstrings.at(locstring);

    curlocale = locstring;
}

const char* TranslatedStrings::GetLocaleName(std::string& locstring) const
{
    const std::unordered_map<StringIdent, const char*>& s = transstrings.at(locstring);
    return s.at(STRING_LOCALE_NAME);
}

const char* TranslatedStrings::GetLocaleName(const char* locstring) const
{
    const std::unordered_map<StringIdent, const char*>& s = transstrings.at(locstring);
    return s.at(STRING_LOCALE_NAME);
}

std::string TranslatedStrings::GetLocale() const
{
    return curlocale;
}

const char* TranslatedStrings::GetFont(std::string& locstring) const
{
    const std::unordered_map<StringIdent, const char*>& s = transstrings.at(locstring);
    return s.at(STRING_FONTFILE);
}

const char* TranslatedStrings::GetFont(const char* locstring) const
{
    const std::unordered_map<StringIdent, const char*>& s = transstrings.at(locstring);
    return s.at(STRING_FONTFILE);
}

const char* TranslatedStrings::operator[](StringIdent idx) const
{
    const std::unordered_map<StringIdent, const char*>& s = transstrings.at(curlocale);
    return s.at(idx);
}
