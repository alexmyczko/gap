/*
 Project: Graphos
 GRCircle.h

 Copyright (C) 2009-2013 GNUstep Application Project

 Author: Ing. Riccardo Mottola

 Created: 2009-12-27

 This application is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public
 License as published by the Free Software Foundation; either
 version 2 of the License, or (at your option) any later version.

 This application is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Library General Public License for more details.

 You should have received a copy of the GNU General Public
 License along with this library; if not, write to the Free
 Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


#import <Foundation/Foundation.h>
#import "GRPathObject.h"
#import "GRObjectControlPoint.h"


@interface GRCircle : GRPathObject
{
    NSPoint      pos;
    NSSize       size;
    NSRect bounds;
    GRObjectControlPoint *startControlPoint;
    GRObjectControlPoint *endControlPoint;
    float rotation;
}

- (BOOL)onControlPoint:(NSPoint)p;
- (void)setStartAtPoint:(NSPoint)aPoint;
- (void)setEndAtPoint:(NSPoint)aPoint;
- (GRObjectControlPoint *) startControlPoint;
- (GRObjectControlPoint *) endControlPoint;
- (NSRect)bounds;
- (NSPoint)position;

@end
