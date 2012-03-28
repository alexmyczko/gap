/* CynthiuneAnimatedImageView.h - this file is part of Cynthiune
 *
 * Copyright (C) 2005 Wolfgang Sourdeau
 *
 * Author: Wolfgang Sourdeau <Wolfgang@Contre.COM>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef CYNTHIUNEANIMATEDIMAGEVIEW_H
#define CYNTHIUNEANIMATEDIMAGEVIEW_H

#import <AppKit/NSImageView.h>

#import <Foundation/NSDate.h>

@class NSMutableArray;
@class NSTimer;

@interface CynthiuneAnimatedImageView : NSImageView
{
  int frameNumber;

  NSMutableArray *frames;
  NSTimer *animationTimer;
  NSTimeInterval interval;
}

- (id) init;

- (void) startAnimation;
- (void) stopAnimation;

- (void) addFramesFromImagenames: (NSString *) firstImagename, ...;
- (void) setInterval: (NSTimeInterval) newInterval;

@end

#endif /* CYNTHIUNEANIMATEDIMAGEVIEW_H */