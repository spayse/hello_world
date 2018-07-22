
Debian
====================
This directory contains files used to package hellod/hello-qt
for Debian-based Linux systems. If you compile hellod/hello-qt yourself, there are some useful files here.

## hello: URI support ##


hello-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install hello-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your helloqt binary to `/usr/bin`
and the `../../share/pixmaps/hello128.png` to `/usr/share/pixmaps`

hello-qt.protocol (KDE)

