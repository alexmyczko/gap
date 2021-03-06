/***************************************************************************
                                Channel.m
                          -------------------
    begin                : Tue Apr  8 17:15:55 CDT 2003
    copyright            : (C) 2005 by Andrew Ruder
                         : (C) 2013-2015 The GNUstep Application Project
    email                : aeruder@ksu.edu
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#import "Models/Channel.h"
#import "GNUstepOutput.h"

#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>
#import <Foundation/NSEnumerator.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSZone.h>

#import <AppKit/NSTableView.h>
#import <AppKit/NSTableColumn.h>

@interface ChannelUser (PrivateMethods)
- (NSString *)lowerName;
@end

@implementation ChannelUser (PrivateMethods)
- (NSString *)lowerName
{
	return lowerName;
}
@end

@implementation ChannelUser
- initWithModifiedName: (NSString *)aName
   withConnectionController: aConnection
{
	if (!(self = [super init])) return nil;
	
	[self setUserName: aName];
	connection = aConnection;
	
	return self;
}
- copyWithZone: (NSZone *)aZone
{
	return [[ChannelUser allocWithZone: aZone]
	  initWithModifiedName: [self formattedName]
	  withConnectionController: connection];
}
- (void)dealloc
{
	[userName release];

	[super dealloc];
}
- (NSString *)userName
{
	return userName;
}
- (NSString *)formattedName
{
	if (hasOps)
	{
		return [NSString stringWithFormat: @"@%@", userName];
	}
	if (hasVoice)
	{
		return [NSString stringWithFormat: @"+%@", userName];
	}

	return userName;
}
- setUserName: (NSString *)aName
{
	if (aName == userName) return self;
	
	hasOps = hasVoice = NO;
	
	if ([aName hasPrefix: @"@"])
	{
		hasOps = YES;
		aName = [aName substringFromIndex: 1];
	}
	else if ([aName hasPrefix: @"+"])
	{
		hasVoice = YES;
		aName = [aName substringFromIndex: 1];
	}
	
	[userName release];
	userName = [aName retain];
	[lowerName release];
	lowerName = [GNUstepOutputLowercase(userName, connection) retain];

	return self;
}
- (BOOL)isOperator
{
	return hasOps;
}
- setOperator: (BOOL)aOp
{
	hasOps = aOp;
	return self;
}
- (BOOL)isVoice
{
	return hasVoice;
}
- setVoice: (BOOL)aVoice
{
	hasVoice = aVoice;
	return self;
}
- (NSComparisonResult)sortByName: (ChannelUser *)aUser
{
	return [lowerName compare: [aUser lowerName]];
}

- (NSString *)description
{
  NSLog(@"Description of channel");
  return [super description];
}
@end

@implementation ChannelFormatter
- (NSString *)stringForObjectValue: (id)anObject
{
	if (![anObject isKindOfClass: [ChannelUser class]]) return nil;
	return [anObject formattedName];
}
- (BOOL)getObjectValue: (id *)obj forString: (NSString *)string
   errorDescription: (NSString **)error
{
	*obj = [[[ChannelUser alloc] initWithModifiedName: string
	  withConnectionController: nil] autorelease];
	return YES;
}
@end

@interface Channel (TableViewDataSource)
@end

@implementation Channel
- (id)init
{
	return [self initWithIdentifier: nil withConnectionController: nil];
}
- (id)initWithIdentifier: (NSString *)aName
   withConnectionController: aConnection
{
	if (!(self = [super init])) return nil;
	
	resetFlag = YES;
	tempList = [NSMutableArray new];
	userList = [NSMutableArray new];
	lowercaseList = [NSMutableArray new];
	connection = aConnection;
	
	[self setIdentifier: aName];
	
	return self;
}
- (void)dealloc
{
	[identifier release];
	[tempList release];
	[userList release];
	[lowercaseList release];
	[topic release];
	[topicAuthor release];
	[topicDate release];
	
	[super dealloc];
}
- setTopic: (NSString *)aTopic
{
	if (topic == aTopic) return self;
	
	[topic release];
	topic = [aTopic retain];
	
	return self;
}
- (NSString *)topic
{
	return topic;
}
- setTopicAuthor: (NSString *)aTopicAuthor
{
	if (topicAuthor == aTopicAuthor) return self;
	[topicAuthor release];
	topicAuthor = [aTopicAuthor retain];
	return self;
}
- (NSString *)topicAuthor
{
	return topicAuthor;
}
- setTopicDate: (NSString *)aTopicDate
{
	if (topicDate == aTopicDate) return self;
	
	[topicDate release];
	topicDate = [aTopicDate retain];
	return self;
}		
- (NSString *)topicDate
{
	return topicDate;
}
- setIdentifier: (NSString *)aIdentifier
{
	if (aIdentifier == identifier) return self;

	[identifier release];
	identifier = [aIdentifier retain];
	
	return self;
}
- (NSString *)identifier
{
	return identifier;
}
- sortUserList
{
	NSEnumerator *iter;
	id object;
	
	[userList sortUsingSelector: @selector(sortByName:)];
	[lowercaseList removeAllObjects];
	
	iter = [userList objectEnumerator];
	while ((object = [iter nextObject]))
	{
		[lowercaseList addObject: GNUstepOutputLowercase([object userName], connection)];
	}
	
	return self;
}
- addUser: (NSString *)aString
{
	id user;

	user = [[[ChannelUser alloc] initWithModifiedName: aString 
	  withConnectionController: connection] autorelease];
	
	[userList addObject: user];
	
	[self sortUserList];
	
	return self;
}
- (BOOL)containsUser: aString
{
	return [lowercaseList containsObject: GNUstepOutputLowercase(aString, connection)];
}
- removeUser: (NSString *)aString
{
	NSUInteger x = [lowercaseList indexOfObject: GNUstepOutputLowercase(aString, connection)];
	if (x != NSNotFound)
	{
		[userList removeObjectAtIndex: x];
		[lowercaseList removeObjectAtIndex: x];
	}
	return self;
}
- userRenamed: (NSString *)oldName to: (NSString *)newName // Keeps mode in tact
{
	BOOL hasVoice;
	BOOL hasOps;
	NSUInteger index;

	index = [lowercaseList indexOfObject: GNUstepOutputLowercase(oldName, connection)];
	if (index == NSNotFound) return self;
	
	hasVoice = [[userList objectAtIndex: index] isVoice];
	hasOps = [[userList objectAtIndex: index] isOperator];
	
	[self removeUser: oldName];
	[self addUser: newName];

	index = [lowercaseList indexOfObject: GNUstepOutputLowercase(newName, connection)];
	if (index == NSNotFound) return self;

	[(ChannelUser *)[userList objectAtIndex: index] setVoice: hasVoice];
	[(ChannelUser *)[userList objectAtIndex: index] setVoice: hasOps];

	return self;
}
- (ChannelUser *)userWithName: (NSString *)name
{
	NSUInteger index;

	index = [lowercaseList indexOfObject: GNUstepOutputLowercase(name, connection)];

	if (index == NSNotFound) return nil;

	return [userList objectAtIndex: index];
}	
- addServerUserList: (NSString *)aString
{
	NSEnumerator *iter;
	NSArray *array = [aString componentsSeparatedByString: @" "];
	NSString *object;
	ChannelUser *user;
	
	iter = [array objectEnumerator];
	while ((object = [iter nextObject]))
	{
		if ([object length] == 0) break;
		user = [[[ChannelUser alloc] initWithModifiedName: object 
		  withConnectionController: connection] autorelease];
		[tempList addObject: user];
	}
	
	return self;
}
- endServerUserList
{
	[userList setArray: tempList];
	[tempList removeAllObjects];
	
	[self sortUserList];
	
	return self;
}
- (NSArray *)userList
{
	return [NSArray arrayWithArray: userList];
}
@end

@implementation Channel (TableViewDataSource)
- (NSInteger)numberOfRowsInTableView: (NSTableView *)aTableView
{
  return (NSInteger)[userList count];
}
- (id)tableView: (NSTableView *)aTableView 
     objectValueForTableColumn: (NSTableColumn *)aTableColumn
	 row: (NSInteger)rowIndex
{
	return [userList objectAtIndex: rowIndex];
}
@end
