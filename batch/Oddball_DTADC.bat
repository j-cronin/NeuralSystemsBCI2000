:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: $Id$
::
:: File: Oddball_DTADC.bat
:: Description: BCI2000 startup script for the WinNT shell.
::
:: (C) 2000-2007, BCI2000 Project
:: http://www.bci2000.org
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cd ..\prog
start operat.exe
wait 0
start DT2000.exe AUTOSTART 127.0.0.1
start DummySignalProcessing.exe AUTOSTART 127.0.0.1
start Oddball.exe AUTOSTART 127.0.0.1
cd ..