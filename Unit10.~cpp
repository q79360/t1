//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit3.h"
#include "Unit10.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm10::Button1Click(TObject *Sender)
{
   if(Edit1->Text=="" || Edit2->Text=="")
    { ShowMessage("原账户或原密码不得为空");
      return;
    }
   if(Edit3->Text=="" || Edit4->Text=="")
    { ShowMessage("新密码或确认新密码不得为空");
      return;
    }
    if(Edit3->Text !=Edit4->Text)
    { ShowMessage("新密码或确认新密码不一致");
      return;
    }
    //判断原用户名和密码是否正确
    AnsiString an1=" select * from glyb where gno='"+Edit1->Text+"' and gpass='"+Edit2->Text+"'";
    DataModule3->ADOQuery1->SQL->Clear() ;
    DataModule3->ADOQuery1->SQL->Add(an1);
    DataModule3->ADOQuery1->Open() ;
    if( DataModule3->ADOQuery1->RecordCount ==0)
      { ShowMessage("原账户或密码不正确");
      return;
     }
    an1=" update glyb set gpass='"+Edit3->Text+"' where gno ='"+Edit1->Text+"' ";
    DataModule3->ADOQuery1->SQL->Clear() ;
    DataModule3->ADOQuery1->SQL->Add(an1);
    DataModule3->ADOQuery1->ExecSQL() ;
    ShowMessage("修改成功");
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button2Click(TObject *Sender)
{
  Form2->Show() ;
  Form10->Hide() ;

}
//---------------------------------------------------------------------------

