//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(Edit1->Text=="" || Edit2->Text=="")
     { ShowMessage("对不起，用户名或密码不得为空");
       return;
     }
     AnsiString an1="select * from glyb where gno='"+Edit1->Text+"' and gpass='"+Edit2->Text+"' ";
     DataModule3->ADOQuery1->SQL->Clear() ;  //清除缓冲区
     DataModule3->ADOQuery1->SQL->Add(an1);  //将SQL命令加入到缓冲区
     DataModule3->ADOQuery1->Open() ;//执行SQL命令
     if(DataModule3->ADOQuery1->RecordCount ==0)
      { ShowMessage("对不起，用户名或密码不正确");
       return;
      }
    Form2->Show() ;
    Form1->Hide() ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   Form1->Close() ;        
}
//---------------------------------------------------------------------------

