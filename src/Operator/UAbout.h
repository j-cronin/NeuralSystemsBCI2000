/* (C) 2000-2007, BCI2000 Project
/* http://www.bci2000.org
/*/
//---------------------------------------------------------------------------

#ifndef UAboutH
#define UAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfAbout : public TForm
{
__published:	// IDE-managed Components
        TButton *OKButton;
        TImage *ProgramIcon;
        TLabel *Copyright;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label2;
        TLabel *Label5;
        TLabel *Label7;
        TLabel *Label6;
        TLabel *Version;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        void __fastcall OKButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAbout *fAbout;
//---------------------------------------------------------------------------
#endif


