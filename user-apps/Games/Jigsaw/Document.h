#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <AppKit/NSDocument.h>
#import <AppKit/NSDocumentController.h>

#define DOCTYPE  @"jigsaw"

#define DESKTOPEXTRA 150
#define DESKTOPMAX   400

typedef enum {
  MENU_ACTION = 64,
  MENU_SCRAMBLE,
  MENU_VERIFY,
  MENU_SOLVE
} MENU_TAG;


@interface Document : NSDocument
{
    NSImage *image;
    NSMutableArray *clusters;
    NSView *view;
    NSString *nameOfImageFile;
    NSInteger px, py;

    BOOL solving;
    NSInteger done;

    NSInteger piece_width, piece_height;
}

+ actionMenu;

- init;
- (void)dealloc;

- (NSInteger)setDone:(NSInteger)flag;

- (NSSize)withPadding;

- scramble:(id)sender;
- verify:(id)sender;
- solve:(id)sender;

- (NSMutableArray *)clusters;

- (NSData *)dataRepresentationOfType:(NSString *)aType;
- (BOOL)loadDataRepresentation:(NSData *)data ofType:(NSString *)aType;

- (BOOL)readFromFile:(NSString *)fileName ofType:(NSString *)docType;

- (void)makeWindowControllers;
- (void)windowControllerDidLoadNib:(NSWindowController *)aController;


@end
