//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit9.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm9::Button10Click(TObject *Sender)
{
  ComboBox1->Text="请选择";
  ComboBox2->Text="请选择";
  ComboBox3->Text="请选择";       
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button2Click(TObject *Sender)
{
   Form2->Show() ;
   Form9->Hide() ;
}
//---------------------------------------------------------------------------





void __fastcall TForm9::FormClick(TObject *Sender)
{
         ComboBox1->Items->Clear() ;
         ComboBox2->Items->Clear() ;
         ComboBox3->Items->Clear() ;
         DBGrid1->DataSource =DataSource2;
         AnsiString an1=" select distinct hno from jckb ";
         DataModule3->ADOQuery1->SQL->Clear() ;
         DataModule3->ADOQuery1->SQL->Add(an1);
         DataModule3->ADOQuery1->Open() ;
         int i;
         for(i=1;i<=DataModule3->ADOQuery1->RecordCount ;i++)
          {ComboBox1->Items->Add(DataModule3->ADOQuery1->FieldValues["hno"]);
           DataModule3->ADOQuery1->Next() ;
          }
        //取年号
         an1=" select distinct year(hp_date) as hpn from jckb ";
         DataModule3->ADOQuery1->SQL->Clear() ;
         DataModule3->ADOQuery1->SQL->Add(an1);
         DataModule3->ADOQuery1->Open() ;
         for(i=1;i<=DataModule3->ADOQuery1->RecordCount ;i++)
          {ComboBox2->Items->Add(DataModule3->ADOQuery1->FieldValues["hpn"]);
           DataModule3->ADOQuery1->Next() ;
          }
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox2Click(TObject *Sender)
{        ComboBox3->Items->Clear() ;
         AnsiString  an1=" select distinct month(hp_date) as hpy from jckb ";
         an1+=" where year(hp_date)="+ComboBox2->Text+" ";
         DataModule3->ADOQuery1->SQL->Clear() ;
         DataModule3->ADOQuery1->SQL->Add(an1);
         DataModule3->ADOQuery1->Open() ;
         int i;
         for(i=1;i<=DataModule3->ADOQuery1->RecordCount ;i++)
          {ComboBox3->Items->Add(DataModule3->ADOQuery1->FieldValues["hpy"]);
           DataModule3->ADOQuery1->Next() ;
          }
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button1Click(TObject *Sender)
{
   AnsiString an1=" select jckb.hno,hname,sum(hp_num) as 库存 ,-sum(hp_num*hp_price) as 利润 ";
   an1+=" from hpb,jckb where  ";
   if(ComboBox1->Text!="请选择")
     an1+=" jckb.hno='"+ComboBox1->Text+"' and ";
   if(ComboBox2->Text!="请选择")
     an1+=" year(hp_date)="+ComboBox2->Text+" and ";
   if(ComboBox3->Text!="请选择")
     an1+=" month(hp_date)="+ComboBox3->Text+" and ";
   an1+=" hpb.hno=jckb.hno  group by jckb.hno,hname ";
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->Open() ;
   DBGrid1->DataSource =DataSource1;
   
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button3Click(TObject *Sender)
{
   AnsiString an1=" select -sum(hp_num*hp_price) as 总利润 from jckb,hpb where  ";
   if(ComboBox2->Text!="请选择")
     an1+=" year(hp_date)="+ComboBox2->Text+" and ";
   if(ComboBox3->Text!="请选择")
     an1+=" month(hp_date)="+ComboBox3->Text+" and ";
   an1+=" hpb.hno=jckb.hno  ";
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->Open() ;
   DBGrid1->DataSource =DataSource1;
}
//---------------------------------------------------------------------------


void __fastcall TForm9::Image1Click(TObject *Sender)
{
        ComboBox1->Items->Clear() ;
         ComboBox2->Items->Clear() ;
         ComboBox3->Items->Clear() ;
         DBGrid1->DataSource =DataSource2;
         AnsiString an1=" select distinct hno from jckb ";
         DataModule3->ADOQuery1->SQL->Clear() ;
         DataModule3->ADOQuery1->SQL->Add(an1);
         DataModule3->ADOQuery1->Open() ;
         int i;
         for(i=1;i<=DataModule3->ADOQuery1->RecordCount ;i++)
          {ComboBox1->Items->Add(DataModule3->ADOQuery1->FieldValues["hno"]);
           DataModule3->ADOQuery1->Next() ;
          }
        //取年号
         an1=" select distinct year(hp_date) as hpn from jckb ";
         DataModule3->ADOQuery1->SQL->Clear() ;
         DataModule3->ADOQuery1->SQL->Add(an1);
         DataModule3->ADOQuery1->Open() ;
         for(i=1;i<=DataModule3->ADOQuery1->RecordCount ;i++)
          {ComboBox2->Items->Add(DataModule3->ADOQuery1->FieldValues["hpn"]);
           DataModule3->ADOQuery1->Next() ;
          }
}
//---------------------------------------------------------------------------

