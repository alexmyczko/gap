include $(GNUSTEP_MAKEFILES)/common.make
BUNDLE_NAME = Skeleton

#BUNDLE_INSTALL_DIR = $(GNUSTEP_APPLICATION_SUPPORT)/TalkSoup/OutFilters
$(BUNDLE_NAME)_COPY_INTO_DIR = ../../Source/TalkSoup.app/Resources/OutFilters

Skeleton_LANGUAGES = English
Skeleton_LOCALIZED_RESOURCE_FILES = Localizable.strings

Skeleton_PRINCIPAL_CLASS = Skeleton

Skeleton_OBJC_FILES = Skeleton.m

ifeq ($(OBJC_RUNTIME_LIB), apple)
Skeleton_BUNDLE_LIBS = -framework TalkSoupBundles $(ADDITIONAL_FRAMEWORK_DIRS)
else
Skeleton_BUNDLE_LIBS = -lTalkSoupBundles
endif

GUI_LIB = 

-include GNUmakefile.preamble
include $(GNUSTEP_MAKEFILES)/bundle.make
-include GNUmakefile.postamble

