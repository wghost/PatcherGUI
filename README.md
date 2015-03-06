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

Proper directory structure:
===========================
To run PatcherGUI you need to set up a proper directory structure:
```
PatcherGUI/
  binaries/
    DecompressLZO
    PatchUPK
  favicon.ico
  PatcherGUI
  PatcherGUIReadme.txt
```
DecompressLZO and PatchUPK are part of UPKUtils project: https://github.com/wghost/UPKUtils
