# MCFlex [![Build Status](https://travis-ci.org/nina-roth/MCFlex.svg?branch=master)](https://travis-ci.org/nina-roth/MCFlex)

A Monte-Carlo Integrator with user-defined functions

Disclaimer: still under development, but should be functional

Main.cpp has a few examples of user defined functions and how to call the MC Integrator. Further documentation will be generated using Doxygen (enabled by default, use ./configure --disable-doxygen to disable).

To build:
- download mcflex-(VERSION).tar.gz and unpack using tar xzf mcflex-0.1.tar.gz (or tar -xzf mcflex-0.1.tar.gz)
- enter directory mcflex-(VERSION)
- ./configure
- make
- make check (optional: runs minimal tests)
- make install

- to remove: make uninstall

