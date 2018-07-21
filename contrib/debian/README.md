
Debian
====================
This directory contains files used to package Hellod/Hello-qt
for Debian-based Linux systems. If you compile Hellod/Hello-qt yourself, there are some useful files here.

## Hello: URI support ##


Hello-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install Hello-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your Helloqt binary to `/usr/bin`
and the `../../share/pixmaps/Hello128.png` to `/usr/share/pixmaps`

Hello-qt.protocol (KDE)

