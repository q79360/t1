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
      { ShowMessage("�Բ��𣬻�Ʒ��Ų���Ϊ��");
        return;
      }
    if(Edit2->Text=="")
      { ShowMessage("�Բ��𣬻�Ʒ���Ʋ���Ϊ��");
        return;
      }
    if(Edit3->Text=="")
      { ShowMessage("�Բ��𣬻�Ʒ��������Ϊ��");
        return;
      }
    if(Edit5->Text=="")
      { ShowMessage("�Բ��𣬻�Ʒ��𲻵�Ϊ��");
        return;
      }
    if(Edit4->Text=="")
      { ShowMessage("�Բ��𣬻�Ʒ��˾����Ϊ��");
        return;
        }
      if(Edit6->Text=="")
      { ShowMessage("�Բ��𣬻�Ʒ���ڲ���Ϊ��");
        return;
        }

      AnsiString an1=" select * from hpb where hno ='"+Edit1->Text+"' ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->Open() ;
      if(DataModule3->ADOQuery1->RecordCount >0  )
       { ShowMessage("�Բ��𣬻�Ʒ����Ѵ��ڣ��������");
        return;
        }

     an1=" insert into hpb values ( '"+Edit1->Text+"' ,   ";
     an1+=" '"+Edit2->Text+"' , '"+Edit3->Text+"' ,'"+Edit5->Text+"'  , ";
     an1+=" '"+Edit4->Text+"' ,'"+Edit6->Text+"' ) ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->ExecSQL() ;
     ShowMessage("¼��ɹ���");
}
//---------------------------------------------------------------------------

