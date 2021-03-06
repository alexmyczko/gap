/* 
   Project: AudioMixer
   AppController.h

   Application Controller

   Copyright (C) 2011 Free Software Foundation

   Author: Riccardo Mottola

   Created: 2011-05-23 23:55:14 +0200 by Riccardo Mottola


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
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.
*/


#import <AppKit/AppKit.h>

@class SoundDevice;

@interface AppController : NSObject
{
  IBOutlet NSWindow *outMainWin;
  IBOutlet NSSlider *sliderOutMainLevel;
  IBOutlet NSSlider *sliderOutMainBalance;
  IBOutlet NSTextField *fieldOutMainLevel;
  IBOutlet NSTextField *fieldOutMainBalance;

  SoundDevice *soundDev;
}

- (void) awakeFromNib;

- (void) applicationDidFinishLaunching: (NSNotification *)aNotif;
- (BOOL) applicationShouldTerminate: (id)sender;
- (void) applicationWillTerminate: (NSNotification *)aNotif;
- (BOOL) application: (NSApplication *)application
	    openFile: (NSString *)fileName;

- (void) showPrefPanel: (id)sender;

- (IBAction) outMainLevelChanged: (id)sender;
- (IBAction) outMainBalanceChanged: (id)sender;

@end
