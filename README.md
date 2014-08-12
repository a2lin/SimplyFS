SimplyFS
========

What is filesystem? This is filesystem.

This filesystem is intended to be extremely simple with functionality
added whenever the mood suits it. Ideally it'll support ls, mv, cat,
and the standard set of commands.

The Makefile is for MacFUSE, but it is intended to eventually support
using Linux FUSE (when the frikin internet stops dropping so development
on a vps can actually happen). (Ideally just a Makefile fix).

Usage:
mkdir /tmp/simplyfs
make
./simplyfs /tmp/simplyfs

---------------------

umount /tmp/simplyfs
