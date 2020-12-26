//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit13.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Button2Click(TObject *Sender)
{
        Form2->Show() ;
        Form13->Hide() ;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Button1Click(TObject *Sender)
{
        AnsiString an1= " select * from hpb where ";
  if(Edit1->Text!="")
    an1+=" hno='"+Edit1->Text+"' and ";
  if(Edit2->Text!="")
    an1+=" hname='"+Edit2->Text+"' and ";
  an1+=" '1'='1' ";  //¹Ø¿ÚÓï¾ä
  DataModule3->ADOQuery1->SQL->Clear() ;
  DataModule3->ADOQuery1->SQL->Add(an1)  ;
  DataModule3->ADOQuery1->Open() ;
}
//---------------------------------------------------------------------------
