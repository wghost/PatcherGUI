CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(PatcherGUI)

SET(CMAKE_BUILD_TYPE Release)
SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -Wall -fexceptions -O2")
SET(EXECUTABLE_OUTPUT_PATH ..)

IF(wxWidgets_USE_MONOLITHIC)
	SET(wxWidgets_USE_LIBS mono richtext)
ELSE(wxWidgets_USE_MONOLITHIC)
	SET(wxWidgets_USE_LIBS base core richtext)
ENDIF(wxWidgets_USE_MONOLITHIC)

FIND_PACKAGE(wxWidgets)
IF(wxWidgets_FOUND)
	INCLUDE(${wxWidgets_USE_FILE})
	ADD_EXECUTABLE(PatcherGUI ../src/PatcherGUIApp.cpp ../src/PatcherGUIApp.h ../src/PatcherGUIMain.cpp ../src/PatcherGUIMain.h ../src/SettingsDialog.cpp ../src/SettingsDialog.h ../src/ShowDebugLogDialog.cpp ../src/ShowDebugLogDialog.h ../src/ViewLog.cpp ../src/ViewLog.h)
	TARGET_LINK_LIBRARIES(PatcherGUI ${wxWidgets_LIBRARIES})
ELSE(wxWidgets_FOUND)
	MESSAGE("wxWidgets not found!")
ENDIF(wxWidgets_FOUND)
