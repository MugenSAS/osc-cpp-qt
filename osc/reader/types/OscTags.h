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
 
#ifndef OSC_TAGS_H_
#define OSC_TAGS_H_

#include <osc/reader/types/OscValue.h>

/** Class representing the type tags string of this message. */
class OscTags: public OscValue
{
public:
	virtual bool toBoolean();
	virtual QByteArray toBytes();
	virtual char toChar();
	virtual double toDouble();
	virtual float toFloat();
	virtual qint32 toInteger();
	virtual qint64 toLong();
	virtual Midi toMIDI();
	virtual RGBA toRGBA();
	virtual QString toString();
	virtual QString toSymbol();
	virtual QDateTime toTimetag();

private:
	/**
	 * Build a new OscTags from the given location in packet.
	 *
	 * @param pos
	 *            the message type tags string position.
	 */
	OscTags(ByteBuffer* packet, qint32 pos);

	/**
	 * Returns the OSC type tags associated to this message.
	 *
	 * @return a string value.
	 */
	QString get();

	friend class OscMessage;

};

#endif // OSC_TAGS_H_
