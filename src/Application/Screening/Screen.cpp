/* (C) 2000-2007, BCI2000 Project
/* http://www.bci2000.org
/*/
#include "PCHIncludes.h"
#pragma hdrstop
#include <vcl.h>
//---------------------------------------------------------------------------
USEFORM("Usr.cpp", User);
USEFORM("..\..\shared\UCoreMain.cpp", fMain);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Application";
                 Application->CreateForm(__classid(TfMain), &fMain);
         Application->CreateForm(__classid(TUser), &User);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------


