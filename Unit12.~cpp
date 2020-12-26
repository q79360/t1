//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit12.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12 *Form12;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm12::Button2Click(TObject *Sender)
{
        Form2->Show() ;
        Form12->Hide() ;        
}
//---------------------------------------------------------------------------

void __fastcall TForm12::Button1Click(TObject *Sender)
{

    if(Edit1->Text=="")
      { ShowMessage("对不起，货品编号不得为空");
        return;
      }
    if(Edit2->Text=="")
      { ShowMessage("对不起，货品名称不得为空");
        return;
      }
    if(Edit3->Text=="")
      { ShowMessage("对不起，货品数量不得为空");
        return;
      }
    if(Edit5->Text=="")
      { ShowMessage("对不起，货品类别不得为空");
        return;
      }
    if(Edit4->Text=="")
      { ShowMessage("对不起，货品公司不得为空");
        return;
        }
      if(Edit6->Text=="")
      { ShowMessage("对不起，货品日期不得为空");
        return;
        }

      AnsiString an1=" select * from hpb where hno ='"+Edit1->Text+"' ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->Open() ;
      if(DataModule3->ADOQuery1->RecordCount >0  )
       { ShowMessage("对不起，货品编号已存在，请更换！");
        return;
        }

     an1=" insert into hpb values ( '"+Edit1->Text+"' ,   ";
     an1+=" '"+Edit2->Text+"' , '"+Edit3->Text+"' ,'"+Edit5->Text+"'  , ";
     an1+=" '"+Edit4->Text+"' ,'"+Edit6->Text+"' ) ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->ExecSQL() ;
     ShowMessage("录入成功！");
}
//---------------------------------------------------------------------------

