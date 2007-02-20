/* (C) 2000-2007, BCI2000 Project
/* http://www.bci2000.org
/*/
#include "PCHIncludes.h"
#pragma hdrstop
//---------------------------------------------------------------------------

#include "UAbout.h"
#include "UMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAbout *fAbout;
//---------------------------------------------------------------------------
__fastcall TfAbout::TfAbout(TComponent* Owner)
        : TForm(Owner)
{
  Version->Caption = TXT_OPERATOR_VERSION;
  Copyright->Caption = TXT_OPERATOR_COPYRIGHT;
}
//---------------------------------------------------------------------------

void __fastcall TfAbout::OKButtonClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------



