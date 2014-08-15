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
 
#ifndef OSC_FLOAT_H_
#define OSC_FLOAT_H_

#include <osc/reader/types/OscValue.h>

/** Class representing an OSC-Float value. */
class OscFloat : public OscValue
{
public:
	virtual bool toBoolean();
	virtual QByteArray toBytes();
	virtual char toChar();
	virtual double toDouble();
	virtual qint64 toLong();
	virtual Midi toMIDI();
	virtual RGBA toRGBA();
	virtual QString toString();

#ifndef BUILD_UNITTESTS
private:
#endif
	/**
	 * Build a new OscFloat from the given location in packet.
	 *
	 * @param pos
	 *            the float value position.
	 */
	OscFloat(ByteBuffer* packet, qint32 pos);

	/**
	 * Returns the float value.
	 *
	 * @return a float value.
	 */
	float get();

	friend class OscMessage;
};

#endif // OSC_FLOAT_H_
