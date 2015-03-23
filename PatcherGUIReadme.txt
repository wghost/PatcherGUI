PatcherGUI - a tool to install and maintain modifications for XCOM:EU and EW
============================================================================

The information below is intended for mod-users mostly. If you're a mod developer, please, consult "PatchUPK_Readme.txt" file, included in the program distribution. It contains all the information needed to create mod files for use with PatchUPK/PatcherGUI.


Program features:
=================
- Does not require installation: unpack and use.
- Has graphical interface.
- Can install mods for both XCOM:EU and EW.
- Maintains separate install logs for every game path.
- Writes backup files for every change it makes.
- Automatically reverts to latest backup if something goes wrong with install/uninstall process.
- Automatically creates uninstall files.
- Automatically unpacks game packages.
- Has an option to disable hash checks for XCOM:EU (Windows only).
- Has an option to enable direct ini loading (Windows only).
- Has an option to disable phoning home (ini re-downloading) (Windows only).
- Can perform batch install and uninstall operations.
- Cross-platform: works with Windows, Linux and Mac XCOM versions
  (under Linux and Mac program should be built from source code).


Quick overview:
===============
XCOM doesn't have official modding support, so we have a bit of a problem here. Actually, more than a bit.

To make some significant changes to the game, we need to alter its packed resources ("packages"). And those are compressed, "cooked" and hashed (for EU). Fortunately, the PC version can read decompressed packages and hash check can be disabled. But the problem of packages being "cooked" stays and raises a lot of questions about inter-patch and inter-mod compatibility.

First, each time Firaxis releases a new patch, those packages get "re-cooked" and all the prior mods, written for each specific patch, stop working.

Second, we can't simply distribute altered packages, as that would make it impossible to combine several mods into one game. So, to allow installation of multiple different mods, we have to distribute changed parts instead of full packages, which, again, raises inter-patch compatibility questions.

Trying to solve the problem of cooked packages, the XCOM modding community eventually came to the idea of distributing not a package itself, but rather a set of instructions on how to modify local user's packages - i.e. distributing a mod's source code, which can be made compatible to all the game versions.

This approach is a bit less user-friendly than a final GUI tool with sliders and check-boxes, but modularity and flexibility allows for easier mods creation, distribution and maintaining: anyone can contribute and the next patch will not ruin the majority of the hard work of prior mods!

Linux and Mac differences:
==========================
There are no pre-built PatcherGUI binaries for Linux and Mac, so you will have to build them yourself. Both GUI and core utilities are open-source and are available via GitHub:
https://github.com/wghost/PatcherGUI
https://github.com/wghost/UPKUtils
Both projects contain README.md file with description and detailed build instructions.

Both Linux and Mac releases do not perform upk hash check, so disabling it is not required.

You can disable phoning home (automatic ini re-downloading) by editing hosts file. For Linux it is usually located at /etc/hosts. Open it (administrator access is required) and add two following lines inside:
127.0.0.1       prod.xcom.firaxis.com
127.0.0.1       prod.xcom-ew.firaxis.com

Both Linux and Mac versions prioritize XCom*.ini files over default*.ini files. Thus, if some mod instructs you to edit defaultgamecore.ini, for example, you need to locate and edit XComGameCore.ini file instead.

Under Linux XCom*.ini files for EU are stored in
~/.local/share/feral-interactive/XCOM/WritableFiles/XComGameCore.ini
And for EW they are stored in
~/.local/share/feral-interactive/XCOM/XEW/WritableFiles/XComGameCore.ini

Under Mac search for XCom*.ini files under
~/Library/Application Support/Feral Interactive/XCOM Enemy Unknown/MacInit
and
~/Library/Application Support/Feral Interactive/XCOM Enemy Unknown/XEW/MacInit


Preparing your game for handling mods:
======================================
First mandatory thing you should do (Windows only): make sure your XCOM game is installed outside the "C:\Program Files" (or "C:\Program Files (x86)" on 64-bit Systems) folder. The reason for this is that Windows (since Vista) considers the "Program Files" folder trees to be restricted areas and will revert all the changes any mod makes to a saved "shadow" copy. It's explained better in the "Installing Games on Windows Vista+" wiki article:
http://wiki.tesnexus.com/index.php/Installing_Games_on_Windows_Vista%2B

Second thing you should do is to switch off automatic updates for XCOM in Steam. Right-click XCOM in the Steam applications list and search it's properties for "updates" options. Note, that turning auto-updates off will not prevent Steam from downloading a newly released patch, but it will prevent silent updates running in the background and breaking your game.

Third thing to do is to stop the game from "phoning home". Each time you launch XCOM it "calls" to Firaxis' servers and downloads some "ini" files to prevent multiplayer cheating. If you're planning to make modifications to game "ini" files (like the "Arc Thrower in Pistol Slot" tweak), you need to disable "phoning home" feature. You can now do it with PatcherGUI using "Tools -> Disable Phoning Home" option (Windows only, for Linux and Mac see "Linux and Mac differences" section above).

For more information on how to install mods for XCOM, please, consult these wiki articles:
http://wiki.tesnexus.com/index.php/Basic_Guide_to_installing_mods
http://wiki.tesnexus.com/index.php/Steam_and_mods


Making a first step:
====================
Download the latest PatcherGUI distribution and unpack it to any folder without locale-specific (i.e. "unicode") symbols in the path. "C:\" or "C:\XCOM-Mods-and-Utils" will do nicely under Windows. Under Linux and Mac you should build the program (see "Linux and Mac differences" section above) and put it under your home directory.

Open the folder where you unpacked PatcherGUI and run "PatcherGUI" executable ("PatcherGUI.exe" under Windows). You can create a desktop link to the executable by the usual OS means if you want.

The very first line of the tool, which has a "Path to XCOM:EU or XCOM:EW" tool-tip (which appears when you hover your mouse over it for a few seconds), should point to your actual XCOM install folder. Press the corresponding "Browse" button (one with a "Set path to XCOM:EU or XCOM:EW" tool-tip) and select the "Path-to-SteamLibrary\SteamApps\common\XCom-Enemy-Unknown" folder if you're planning to install EU mods; and the "Path-to-SteamLibrary\SteamApps\common\XCom-Enemy-Unknown\XEW" folder if you're planning to install mods for EW.

("Path-to-SteamLibrary" is a placeholder for the actual path to your SteamLibrary folder location, for example, "D:\SteamLibrary" under Windows.)

Now you're ready to install mods.


XCOM: Enemy Unknown — disabling hash check (Windows only):
==========================================================

If you're planning to install EU mods under Windows, you need to disable hash checks, otherwise the game won't load your modified packages. To do so, click "Tools -> Disable hash check" in PatcherGUI main menu. If game path is correct (see "Making a first step" section above), program will patch XComGame.exe and you'll see "Success!" message. If you'll see an error message, read this file again and make sure you've followed all the instructions carefully.

You need to do this only once.

Note: "Disable hash check" option disables hash check for the four most commonly used packages: core.upk, engine.upk, xcomgame.upk and xcomstrategygame.upk. If a specific mod uses some other package, you need to disable it separately via "Advanced -> Disable hash..." option in main menu.


Installing a mod:
=================
Download a mod's archive and unpack it. It's not required, but recommended to unpack all the mods into a "PatcherGUI\Mods" folder. Each mod file is a plain text file, which usually contains human-readable description at the top followed by a bunch of utility-specific commands.

Run PatcherGUI and use a second "Browse" button (one with "Open mod file" tool-tip) to browse for a file you just unpacked. PatcherGUI will load it and display its contents in it's simple text viewer/editor.

If you haven't yet set a path to your XCOM:EU or XCOM:EW folder, do it now (see "Making a first step" section above).

If the mod doesn't have any user-editable variables, press the "Apply" button to install it. If the mod provides some configurable options, consult the mod's "Readme" file on how to set it up properly.

If installation was successful, close PatcherGUI and run the game. If an error message appears, read this file and the mod instructions carefully and try to repeat the installation. If it still fails, report a bug (see "Reporting bugs and asking questions" section later in this file).

If you're installing a mod for EU under Windows, you need to disable hash check (see "XCOM: Enemy Unknown — disabling hash check" section above).


Uninstalling a mod:
===================
PatcherGUI automatically creates "uninstall files" for all the installed mods. You can find the uninstall file in the same folder where the mod file is located. Each uninstall file is automatically named "name_of_the_original_mod_file.uninstall.txt".

Multiple subsequent installations of the same mod will create multiple subsequent uninstall files: "name_of_the_original_mod_file.uninstall1.txt",
"name_of_the_original_mod_file.uninstall2.txt",
and so on. The very first uninstall file ("name_of_the_original_mod_file.uninstall.txt") contains vanilla code, and the others - previous modded code. So, to completely uninstall a mod use the very first uninstall file and to undo only the last changes to that mod use the most recent uninstall file.


Using a log:
============
PatcherGUI writes an install log for each of your game folders (you'll have separate install logs for EU and EW). You may access that log by pressing the "Show log" button.

The log window contains info on current install directories and a list of all installed mods for the current path (names of the corresponding mod files). For each of the listed mods you can load it's installer or uninstaller file into PatcherGUI by pressing the corresponding "Load Installer" or "Load Uninstaller" button.

When you install a mod, it's automatically added to the install list. When you uninstall a mod, it's automatically removed from the list.


Cleaning things up:
===================
If you want to revert to the vanilla game, go to Steam, right-click XCOM and search for "verify game cache" under "game properties". Steam will check all the game files and re-download "broken" (i.e. modded) ones.

To clean up PatcherGUI you need to manually cleanup the "PatcherGUI\Backup" and "PatcherGUI\Logs" folder. The "Backup" folder contains all the modified files backups and the "Logs" folder contains install logs for all the game folders.


Enabling ini loading (Windows only):
====================================

PatcherGUI can alter game executable to enable direct loading of DefaultGameCore.ini and DefaultLoadouts.ini. Click "Tools -> Enable ini loading" in program main menu. If game path is correct (see "Making a first step" section above), program will patch current game executable and you'll see "Success!" message. If you'll see an error message, read this file again and make sure you've followed all the instructions carefully.

You need to do it once for each install path (EU and EW).


Disabling phoning home (Windows only):
======================================

PatcherGUI can disable phoning home (to stop ini files re-downloading and re-writing) by altering game executable. Click "Tools -> Disable phoning home" in program main menu. If game path is correct (see "Making a first step" section above), program will patch current game executable and you'll see "Success!" message. If you'll see an error message, read this file again and make sure you've followed all the instructions carefully.

You need to do it once for each install path (EU and EW).


Using batch install/uninstall functionality:
============================================

PatcherGUI batch files have *.pgui extension and contain a simple list of modfiles to apply, separated by end of line character. Example (Windows):
L:\Path\To\ModFile1.txt
L:\Path\To\ModFile2.txt

You can generate a batch file using an install log:
1. Click "Show log" button to open current log file.
2. Click "Batch installer" to generate batch install file, containing all the currently installed mods. A save file dialog will pop up, allowing you to save batch file and load it into PatcherGUI.
3. Click "Batch uninstaller" to generate batch uninstall file, containing uninstall file references for all the currently installed mods in reverse order. A save file dialog will pop up, allowing you to save batch file and load it into PatcherGUI.
4. Click "Apply" button to apply all the mods, listed in batch file. Note, that for long lists this operation may take some time.

You can edit batch file with PatcherGUI or text editor (like Notepad under Windows) and create your own batch files.


Reporting bugs and asking questions:
====================================
For Nexus mods you can report bugs and ask questions in the mod-specific topic which can be accessed via the "POSTS" link on the Nexus Download page.

If you want to report a bug or ask a question about the UPKUtils utility itself, use the UPKUtils Nexus forum topic:
http://forums.nexusmods.com/index.php?showtopic=1253992

Click "Tools -> Show debug log" in program main menu to open program debug log. This log contains the output stream of all the utilities involved in a patching process. If something goes wrong, this information can be extremely helpful, so, please, copy and paste it into your bugreport.


Acknowledgements:
=================
Eliot van Uytfanghe for UE Explorer
Gildor for Unreal Engine Package Decompressor (decompress.exe)
bokauk for XCOM ToolBoks
Amineri and XMarksTheSpot for UPKModder
Bertilsson, Drakous79, JohnnyLump and all NexusForums authors for helpful info and discussions
dubiousintent for NexusWiki articles and helpful advices

All trademarks, mentioned herein, are properties of their respective owners.
