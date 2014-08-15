/*
 * Copyright (c) 2014 MUGEN SAS
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _OSC_API_H_
#define _OSC_API_H_

#include <QtGlobal>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#ifdef Q_OS_WIN
// Define to export or import depending if we are building or using the library.
// OSC_EXPORT should only be defined when building.
#if defined(OSC_EXPORT)
#define OSC_API __declspec(dllexport)
#else
#define OSC_API __declspec(dllimport)
#endif
#else
// Define empty for other platforms
#define OSC_API
#endif
#else
#ifdef Q_WS_WIN
// Define to export or import depending if we are building or using the library.
// OSC_EXPORT should only be defined when building.
#if defined(OSC_EXPORT)
#define OSC_API __declspec(dllexport)
#else
#define OSC_API __declspec(dllimport)
#endif
#else
// Define empty for other platforms
#define OSC_API
#endif
#endif

#endif // _OSC_API_H_
