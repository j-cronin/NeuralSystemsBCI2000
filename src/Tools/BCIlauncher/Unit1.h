//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ActnMan.hpp>
#include <ExtActns.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <string>
#include <vector.h>
#include <dir.h>
#include <stdio.h>
#include <list.h>
#include <process.h>
#include <iostream>
#include <fstream>
#include <dir.h>
#include <sstream>
#include "EncodedString.h"

using namespace std;
//---------------------------------------------------------------------------
class TmainForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TListBox *sourceList;
    TListBox *sigProcList;
    TListBox *appList;
    TGroupBox *GroupBox2;
    TListBox *othersList;
    TActionManager *ActionManager1;
    TFileRun *FileRun1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TGroupBox *GroupBox3;
    TEdit *parmBox;
    TLabel *Label5;
    TButton *getParmBut;
    TOpenDialog *OpenParmDlg;
    TEdit *sourceIPBox;
    TEdit *sigProcIPBox;
    TEdit *appIPBox;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TGroupBox *GroupBox4;
    TButton *launchBut;
    TListBox *statusList;
    TLabel *Label4;
    TButton *clearBut;
    TPopupMenu *sourcePopup;
    TPopupMenu *spPopup;
    TPopupMenu *appPopup;
    TPopupMenu *othersPopup;
    TMenuItem *Move1;
    TMenuItem *sourceToSP;
    TMenuItem *sourceToApp;
    TMenuItem *sourceToOthers;
    TMenuItem *MoveTo1;
    TMenuItem *spToSource;
    TMenuItem *spToOthers;
    TMenuItem *spToApp;
    TMenuItem *MoveTo2;
    TMenuItem *appToSource;
    TMenuItem *appToSp;
    TMenuItem *appToOthers;
    TMenuItem *MoveTo3;
    TMenuItem *othersToSource;
    TMenuItem *othersToSp;
    TMenuItem *othersToApp;
    TMainMenu *MainMenu1;
    TMenuItem *Help1;
    TMenuItem *helpMnu;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall launchButClick(TObject *Sender);
    void __fastcall getParmButClick(TObject *Sender);
    void __fastcall clearButClick(TObject *Sender);
    void __fastcall sourceToSPClick(TObject *Sender);
    void __fastcall sourceToAppClick(TObject *Sender);
    void __fastcall sourceToOthersClick(TObject *Sender);
    void __fastcall spToSourceClick(TObject *Sender);
    void __fastcall spToAppClick(TObject *Sender);
    void __fastcall spToOthersClick(TObject *Sender);
    void __fastcall appToSourceClick(TObject *Sender);
    void __fastcall appToSpClick(TObject *Sender);
    void __fastcall appToOthersClick(TObject *Sender);
    void __fastcall othersToSourceClick(TObject *Sender);
    void __fastcall othersToSpClick(TObject *Sender);
    void __fastcall othersToAppClick(TObject *Sender);
    void __fastcall sourceListDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
    void __fastcall sourceListDragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
    void __fastcall sourceListMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall sigProcListDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
    void __fastcall sigProcListDragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
    void __fastcall sigProcListMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall appListDragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
    void __fastcall appListMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall appListDragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
    void __fastcall helpMnuClick(TObject *Sender);
private:	// User declarations
    vector<string> dirListing;
    bool ismember(string str, vector<string> strs);
    vector<string> sourceStr;
    vector<string> SPStr;
    vector<string> appStr;
    string curdir;
    AnsiString helpLoc;

    //for drag-n-drop
    TPoint startPoint;

    bool updateINIFile();
public:		// User declarations
    __fastcall TmainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmainForm *mainForm;
//---------------------------------------------------------------------------
#endif

bool ismember(string str, vector<string> strs);
void removeAt(vector<string> &str, int pos);
bool getNextLine(ifstream &in, vector<string> &tokens, string delimiters);
void stringSplit(const string& str, vector<string>& tokens, string delimiters);
string lowerCase(string str);
char *current_directory(char *path);
