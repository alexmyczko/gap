/*
   Project: MPDCon

   Copyright (C) 2004

   Author: Daniel Luederwald

   Created: 2004-05-14 11:37:03 +0200 by flip

   MPD Controller

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

#ifndef _PCAPPPROJ_MPDCONTROLLER_H_
#define _PCAPPPROJ_MPDCONTROLLER_H_

#include <Foundation/Foundation.h>
#include <mpd/client.h>
#include "PlaylistItem.h"
#include "StatisticsItem.h"
#include "Strings.h"

#define state_NOCONN -1
#define state_UNKNOWN 0
#define state_STOP 1
#define state_PLAY 2
#define state_PAUSE 3

@interface MPDController : NSObject
{
  struct mpd_connection *mpdConnection;
  
  NSString *host;
  NSString *port;
  NSString *password;
  NSString *timeout;

  long long currPlaylist;
  unsigned int currPlaylistVersion;
  // those two are used to check whether the collection changed
  unsigned int numArtists;
  unsigned int numAlbums;
}

// Initialization Methods
+ (id) sharedMPDController;

// Connection Methods
- (BOOL) connectToServer: (NSString *)hostName 
                    port: (NSString *)port 
                password: (NSString *)pword
		 timeout: (NSString *)tout;

// Play Methods
- (void) play;
- (void) playSong: (int)song;
- (void) stop;
- (void) prev;
- (void) next;
- (void) toggleShuffle;
- (void) toggleRepeat;

- (void) seekToTime: (int)time;
- (void) setVolume: (int)volume;
- (void) setCrossfade: (int)cfTime;

// Information Methods
- (int) getState;

- (BOOL) isRandom;
- (BOOL) isRepeat;

- (int) getVolume;
- (int) getCrossfade;

- (StatisticsItem *) getStatistics;

// Playlist Commands
- (PlaylistItem *) getCurrentSong;
- (int) getCurrentSongNr;

- (int) getPlaylistLength;
- (NSArray *) getPlaylist;

- (BOOL) playlistChanged;
- (void) shuffleList;
- (void) clearPlaylist;

- (void) removeSong: (int)song;
- (void) removeSongRange: (NSRange)songRange;
- (void) addTrack: (NSString *)file;
- (void) moveSongNr: (int)song1 to: (int)song2;
- (void) moveSongWithID: (int)song1 to: (int)song2;

- (NSArray *) getAllPlaylists;

- (void) loadPlaylist: (NSString *)title;
- (void) savePlaylist: (NSString *)title;
- (void) removePlaylist: (NSString *)title;

// Collection Commands
- (BOOL) collectionChanged;
- (NSArray *) getAllArtists;
- (NSArray *) getAllAlbums;
- (NSArray *) getAllTracksWithMetadata: (BOOL) withMetadata;

- (NSArray *) getAlbumsForArtist: (NSString *)artist;
- (NSArray *) getAllTracksForArtist: (NSString *)artist;
- (NSArray *) getAllTracksForArtist: (NSString *)artist 
                              album: (NSString *)album;

- (NSArray *) getAllTracksForAlbum: (NSString *)album;
-(NSArray *) getAllFilesInDirectory: (NSString *) directory;

- (void) updateCollection;

- (NSArray *) getAllDirectories;


@end
#endif

