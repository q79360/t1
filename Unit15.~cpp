//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit3.h"
#include "Unit15.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm15 *Form15;
//---------------------------------------------------------------------------
__fastcall TForm15::TForm15(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm15::Button3Click(TObject *Sender)
{
        Form2->Show() ;
        Form15->Hide() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm15::Button1Click(TObject *Sender)
{
        if (Edit1->Text=="")
     { ShowMessage("请输入货品编号");
     return;
     }
    AnsiString an1="select * from hpb where hno='"+Edit1->Text+"'";
    DataModule3->ADOQuery1->SQL->Clear();
    DataModule3->ADOQuery1->SQL->Add(an1);
    DataModule3->ADOQuery1->Open();
    if(DataModule3->ADOQuery1->RecordCount ==0)
    { ShowMessage("查无此物");
      return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm15::Button2Click(TObject *Sender)
{
        Button2->Enabled=true;
    Edit1->Enabled=false;
   int ts;
   ts=MessageBox(NULL,"确定要删除吗？（Y/N）","删除窗口",4);
   if(ts==6)
   {  AnsiString an1="delete from hpb where hno='"+Edit1->Text+"' ";
      DataModule3->ADOQuery1->SQL->Clear();
      DataModule3->ADOQuery1->SQL->Add(an1);
      DataModule3->ADOQuery1->ExecSQL();
      ShowMessage("删除成功！");
      Button2->Enabled=false;
      Edit1->Enabled=true;
   }
}
//---------------------------------------------------------------------------

