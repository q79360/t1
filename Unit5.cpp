//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm5::Button1Click(TObject *Sender)
{
  AnsiString an1= " select * from glyb where ";
  if(Edit1->Text!="")
    an1+=" gno='"+Edit1->Text+"' and ";
  if(Edit2->Text!="")
    an1+=" gname='"+Edit2->Text+"' and ";
  an1+=" '1'='1' ";  //¹Ø¿ÚÓï¾ä
  DataModule3->ADOQuery1->SQL->Clear() ;
  DataModule3->ADOQuery1->SQL->Add(an1)  ;
  DataModule3->ADOQuery1->Open() ;

}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{
   Form2->Show() ;
   Form5->Hide() ;
}
//---------------------------------------------------------------------------
