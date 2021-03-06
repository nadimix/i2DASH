/*
 *  Frame - AV Frame structure
 *  Copyright (C) 2013  Fundació i2CAT, Internet i Innovació digital a Catalunya
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Authors: David Cassany <david.cassany@i2cat.net> 
 *          
 */
#include <iostream>

#include "Frame.hh"

Frame::Frame() : frameBuff(NULL), frameLen(0),
                presentationTime(0), decodeTime(0),
                duration(0)
{

}

Frame::~Frame()
{
}

void Frame::setPresentationTime(size_t pTime)
{
    presentationTime = pTime;
}

void Frame::setDecodeTime(size_t dTime)
{
    decodeTime = dTime;
}

void Frame::setDuration(size_t dur) 
{
    duration = dur;
}

void Frame::setDataBuffer(unsigned char *buff, size_t length)
{
    frameBuff = buff;
    frameLen = length;
}

AVCCFrame::AVCCFrame(): Frame(), width(0), height(0), intra(false)
{
}

AVCCFrame::~AVCCFrame()
{
}

void AVCCFrame::setVideoSize(int width, int height)
{
    this->width = width;
    this->height = height;
}

void AVCCFrame::clearFrame()
{
    width = 0;
    height = 0;
    frameLen = 0;
    frameBuff = NULL;
    intra = false;
}

void AVCCFrame::setIntra(bool isIntra)
{
    intra = isIntra;
}

AACFrame::AACFrame(): Frame(), sampleRate(0)
{
}

AACFrame::~AACFrame()
{
}

void AACFrame::clearFrame()
{
    frameLen = 0;
    frameBuff = NULL;
    sampleRate = 0;
}

