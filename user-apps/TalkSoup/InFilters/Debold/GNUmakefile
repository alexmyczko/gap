include $(GNUSTEP_MAKEFILES)/common.make
BUNDLE_NAME = Debold

#BUNDLE_INSTALL_DIR = $(GNUSTEP_APPLICATION_SUPPORT)/TalkSoup/InFilters
$(BUNDLE_NAME)_COPY_INTO_DIR = ../../Source/TalkSoup.app/Resources/InFilters

Debold_LANGUAGES = English
Debold_LOCALIZED_RESOURCE_FILES = Localizable.strings

Debold_PRINCIPAL_CLASS = Debold

Debold_OBJC_FILES = Debold.m

ifeq ($(OBJC_RUNTIME_LIB), apple)
Debold_BUNDLE_LIBS = -framework TalkSoupBundles $(ADDITIONAL_FRAMEWORK_DIRS)
else
Debold_BUNDLE_LIBS = -lTalkSoupBundles
endif

GUI_LIB = 

-include GNUmakefile.preamble
include $(GNUSTEP_MAKEFILES)/bundle.make
-include GNUmakefile.postamble

