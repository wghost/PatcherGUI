PatcherGUI
==========
A tool to install and maintain modifications for XCOM: EU/EW

How to compile under Linux:
===========================
Install gcc-c++ (g++) compiler, cmake, git and wxGTK-devel v.3.0+ package available for your distribution repository.

Clone github repo and compile the project:
```
git clone https://github.com/wghost/PatcherGUI.git
cd PatcherGUI/build
cmake .
make
```
PatcherGUI executable is placed into main project folder, so resulting directory/file structure should look like this:
```
PatcherGUI/
  binaries/
    DecompressLZO
    PatchUPK
  favicon.ico
  PatcherGUI
  PatcherGUIReadme.txt
```
DecompressLZO and PatchUPK are part of UPKUtils project: https://github.com/wghost/UPKUtils You need to build those separately and manually place them into binaries directory.

By default PatcherGUI looks for DecompressLZO and PatchUPK inside binaries directory, but this can be changed with "Advanced -> Settings" menu option.

Update by tukkek
================
I had a hard time finding the exact package names for building this project on Debian testing so I thought I'd share a easy to copy-and-paste command line:
```
sudo apt-get install g++ cmake git libwxgtk3.0-gtk3-dev
```
