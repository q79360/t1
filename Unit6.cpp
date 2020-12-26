//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit3.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm6::Button1Click(TObject *Sender)
{
   if(Edit1->Text=="")
     { ShowMessage("请输入管理员编号");
       return;
     }
     AnsiString an1=" select * from glyb where gno='"+Edit1->Text+"' ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->Open() ;
     if(DataModule3->ADOQuery1->RecordCount ==0)
       { ShowMessage("查无此人");
       return;
       }
     Edit2->Text=DataModule3->ADOQuery1->FieldValues["gpass"];
     Edit3->Text=DataModule3->ADOQuery1->FieldValues["gname"];
     AnsiString xb;
     xb=DataModule3->ADOQuery1->FieldValues["gsex"];
     if(xb=="男")
       RadioButton1->Checked =true;
     if(xb=="女")
       RadioButton2->Checked =true;
     Edit4->Text=DataModule3->ADOQuery1->FieldValues["gtele"];
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
    AnsiString an1=" update glyb set gpass='"+Edit2->Text+"', ";
    an1+=" gname ='"+Edit3->Text+"' ,";
    AnsiString xb;
    if(RadioButton1->Checked ==true)
      xb="男";
    if(RadioButton2->Checked ==true)
      xb="女";
    an1+=" gsex='"+xb+"' , ";
    an1+=" gtele ='"+Edit4->Text+"' where gno='"+Edit1->Text+"' ";
    DataModule3->ADOQuery1->SQL->Clear() ;
    DataModule3->ADOQuery1->SQL->Add(an1);
    DataModule3->ADOQuery1->ExecSQL() ;
    ShowMessage("修改成功！");

}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender)
{
        Form2->Show() ;
        Form6->Hide() ;
}
//---------------------------------------------------------------------------

