//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
    if(Edit1->Text=="")
      { ShowMessage("对不起，管理员编号不得为空");
        return;
      }
    if(Edit2->Text=="")
      { ShowMessage("对不起，管理员密码不得为空");
        return;
      }
    if(Edit3->Text=="")
      { ShowMessage("对不起，管理员姓名不得为空");
        return;
      }
    AnsiString xb="" ;
    if(RadioButton1->Checked ==true)
      xb="男";
    if(RadioButton2->Checked ==true)
      xb="女";
    if(xb=="")
      { ShowMessage("对不起，管理员性别不得为空");
        return;
      }

     if(Edit4->Text=="")
      { ShowMessage("对不起，管理员电话不得为空");
        return;
      }
     if(Edit4->Text<'0' ||  Edit4->Text>'9')
       { ShowMessage("对不起，管理员电话须为数字");
        return;
      }
     if(Edit4->Text.Length() != 11)
       { ShowMessage("对不起，管理员电话须为11位");
        return;
      }
    //查重管理员编号
     AnsiString an1=" select * from glyb where gno ='"+Edit1->Text+"' ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->Open() ;
      if(DataModule3->ADOQuery1->RecordCount >0  )
       { ShowMessage("对不起，管理员号已存在，请更换！");
        return;
      }

     an1=" insert into glyb values ( '"+Edit1->Text+"' ,   ";
     an1+=" '"+Edit2->Text+"' , '"+Edit3->Text+"' , '"+xb+"' , ";
     an1+=" '"+Edit4->Text+"' ) ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->ExecSQL() ;
     ShowMessage("录入成功！");

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
   Form2->Show() ;
   Form4->Hide() ;
}
//---------------------------------------------------------------------------
