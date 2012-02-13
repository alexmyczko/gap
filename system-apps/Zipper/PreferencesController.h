#import <Foundation/NSObject.h>

@class NSPanel, NSForm, NSTextField, Archive;

@interface PreferencesController : NSObject
{
    IBOutlet NSPanel *_panel;
	IBOutlet NSButton *_bsdTarButon;
	IBOutlet NSTextField *_defaultOpenApp;

	IBOutlet NSTextField *_tarTextField;
	IBOutlet NSTextField *_unzipTextField;
	IBOutlet NSTextField *_rarTextField;
	IBOutlet NSTextField *_lhaTextField;
	IBOutlet NSTextField *_lzxTextField;
	IBOutlet NSTextField *_sevenZipTextField;
	
	// this holds a reference to an Archive subclass that the user
	// needs to set before he can leave the prefs dialog
	id _archiveClass;
}

- (void)showPreferencesPanel;
		
@end

