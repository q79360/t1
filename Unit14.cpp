//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit3.h"
#include "Unit14.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Button1Click(TObject *Sender)
{
        if(Edit1->Text=="")
     { ShowMessage("请输入货品编号");
       return;
     }
     AnsiString an1=" select * from hpb where hno='"+Edit1->Text+"' ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->Open() ;
     if(DataModule3->ADOQuery1->RecordCount ==0)
       { ShowMessage("查无此物");
       return;
       }
     Edit2->Text=DataModule3->ADOQuery1->FieldValues["hname"];
     Edit3->Text=DataModule3->ADOQuery1->FieldValues["hdw"];
     Edit4->Text=DataModule3->ADOQuery1->FieldValues["hsort"];
     Edit5->Text=DataModule3->ADOQuery1->FieldValues["hfact"];
     Edit6->Text=DataModule3->ADOQuery1->FieldValues["hdate"];
}
//---------------------------------------------------------------------------
void __fastcall TForm14::Button2Click(TObject *Sender)
{
        AnsiString an1=" update hpb set hname='"+Edit2->Text+"', ";
    an1+=" hdw ='"+Edit3->Text+"' ,";
    an1+=" hsort='"+Edit4->Text+"' ,";
    an1+=" hfact ='"+Edit5->Text+"'," ;
    an1+=" hdate='"+Edit6->Text+"' where hno='"+Edit1->Text+"' ";
    DataModule3->ADOQuery1->SQL->Clear() ;
    DataModule3->ADOQuery1->SQL->Add(an1);
    DataModule3->ADOQuery1->ExecSQL() ;
    ShowMessage("修改成功！");
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Button3Click(TObject *Sender)
{
        Form2->Show() ;
        Form14->Hide() ;
}
//---------------------------------------------------------------------------

