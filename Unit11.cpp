//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit11.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button2Click(TObject *Sender)
{
          Form2->Show() ;
          Form11->Hide() ;
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button1Click(TObject *Sender)
{
          if(ComboBox1->Text =="请选择"){
          ShowMessage("请选择备份年");
          return;
          }
          AnsiString an1="delete from jckb1 where year(hp_date)="+ComboBox1->Text+"";
          DataModule3->ADOQuery1->SQL->Clear() ;
          DataModule3->ADOQuery1->SQL->Add(an1);
          DataModule3->ADOQuery1->ExecSQL() ;

          an1="insert into jckb1(hno,gno,hp_num,hp_price,hp_date,hp_sort) ";
          an1+=" select hno,gno,hp_num,hp_price,hp_date,hp_sort from jckb where year(hp_date)="+ComboBox1->Text+"";
          DataModule3->ADOQuery1->SQL->Clear() ;
          DataModule3->ADOQuery1->SQL->Add(an1);
          DataModule3->ADOQuery1->ExecSQL() ;
          ShowMessage("备份成功") ;
}
//---------------------------------------------------------------------------



void __fastcall TForm11::FormClick(TObject *Sender)
{
        ComboBox1->Items->Clear();
        AnsiString an1="select distinct year(hp_date) as hpn from jckb";
        DataModule3->ADOQuery1->SQL->Clear() ;
        DataModule3->ADOQuery1->SQL->Add(an1);
        DataModule3->ADOQuery1->Open() ;\
        int i;
        for(i=1;i<=DataModule3->ADOQuery1->RecordCount;i++){
                ComboBox1->Items->Add(DataModule3->ADOQuery1->FieldValues["hpn"]);
                DataModule3->ADOQuery1->Next() ;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm11::Image1Click(TObject *Sender)
{
         ComboBox1->Items->Clear();
        AnsiString an1="select distinct year(hp_date) as hpn from jckb";
        DataModule3->ADOQuery1->SQL->Clear() ;
        DataModule3->ADOQuery1->SQL->Add(an1);
        DataModule3->ADOQuery1->Open() ;\
        int i;
        for(i=1;i<=DataModule3->ADOQuery1->RecordCount;i++){
                ComboBox1->Items->Add(DataModule3->ADOQuery1->FieldValues["hpn"]);
                DataModule3->ADOQuery1->Next() ;
        }
}
//---------------------------------------------------------------------------

