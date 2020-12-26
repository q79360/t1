//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit3.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm8::FormCreate(TObject *Sender)
{
   Edit3->Text=Date();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::RadioButton1Click(TObject *Sender)
{
   ComboBox1->Items->Clear();
   ComboBox2->Items->Clear();
   AnsiString an1=" select gno from glyb ";
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->Open() ;
   if( DataModule3->ADOQuery1->RecordCount ==0)
     { ShowMessage("管理员表里没有数据");
       return;
     }
    int i;
    for(i=1;i<=DataModule3->ADOQuery1->RecordCount;i++)
     { ComboBox1->Items->Add(DataModule3->ADOQuery1->FieldValues["gno"]);
       DataModule3->ADOQuery1->Next() ;
     }
    an1="select hno from hpb" ;
    DataModule3->ADOQuery1->SQL->Clear() ;
    DataModule3->ADOQuery1->SQL->Add(an1);
    DataModule3->ADOQuery1->Open() ;
    if( DataModule3->ADOQuery1->RecordCount ==0)
     { ShowMessage("货品表里没有数据");
       return;
     }
     for(i=1;i<=DataModule3->ADOQuery1->RecordCount;i++)
     { ComboBox2->Items->Add(DataModule3->ADOQuery1->FieldValues["hno"]);
       DataModule3->ADOQuery1->Next() ;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm8::RadioButton2Click(TObject *Sender)
{
   ComboBox1->Items->Clear();
   ComboBox2->Items->Clear();
   AnsiString an1=" select gno from glyb ";
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->Open() ;
   if( DataModule3->ADOQuery1->RecordCount ==0)
     { ShowMessage("管理员表里没有数据");
       return;
     }
    int i;
    for(i=1;i<=DataModule3->ADOQuery1->RecordCount;i++)
     { ComboBox1->Items->Add(DataModule3->ADOQuery1->FieldValues["gno"]);
       DataModule3->ADOQuery1->Next() ;
     }
   an1=" select distinct hno  from jckb ";
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->Open() ;
   if( DataModule3->ADOQuery1->RecordCount ==0)
     { ShowMessage("没有进出库数据");
       return;
     }
    for(i=1;i<=DataModule3->ADOQuery1->RecordCount;i++)
     { ComboBox2->Items->Add(DataModule3->ADOQuery1->FieldValues["hno"]);
       DataModule3->ADOQuery1->Next() ;
     }

}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button1Click(TObject *Sender)
{
    if(RadioButton1->Checked ==false && RadioButton2->Checked ==false)
    { ShowMessage("请选择入库或出库");
       return;
    }
    if(ComboBox1->Text=="请选择")
     { ShowMessage("请选择管理员编号");
       return;
     }
     if(ComboBox2->Text=="请选择")
     { ShowMessage("请选择货品编号");
       return;
     }
       if(Edit1->Text=="" || Edit2->Text =="")
     { ShowMessage("数量或单价不得为空");
       return;
     }
    AnsiString lb="" ;
    AnsiString an1;
    if(RadioButton1->Checked ==true)
     { lb="入库";
       an1=" insert into jckb(gno,hno,hp_num,hp_price,hp_date,hp_sort) values( ";
       an1+=" '"+ComboBox1->Text+"','"+ComboBox2->Text+"',"+Edit1->Text+", ";
       an1+=" "+Edit2->Text+" ,'"+Edit3->Text+"' ,'"+lb+"') ";
      }
    if(RadioButton2->Checked ==true)
    {   lb="出库";
       if(Edit1->Text.ToInt() >Label8->Caption.ToInt() )
          { ShowMessage("你的库存没有这么多数量！");
           return;
          }
       an1=" insert into jckb(gno,hno,hp_num,hp_price,hp_date,hp_sort) values( ";
       an1+=" '"+ComboBox1->Text+"','"+ComboBox2->Text+"',-"+Edit1->Text+", ";
       an1+=" "+Edit2->Text+" ,'"+Edit3->Text+"' ,'"+lb+"') ";
    }
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->ExecSQL()  ;
   ShowMessage("录入成功");
   an1=" select * from jckb order by hp_date desc";
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->Open()  ;
   DBGrid1->DataSource =DataSource1;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox2Click(TObject *Sender)
{
     AnsiString an1=" select sum(hp_num) as kc from jckb where hno='"+ComboBox2->Text+"' ";
     DataModule3->ADOQuery1->SQL->Clear() ;
     DataModule3->ADOQuery1->SQL->Add(an1);
     DataModule3->ADOQuery1->Open()   ;
     Label8->Caption =DataModule3->ADOQuery1->FieldValues["kc"];
}
//---------------------------------------------------------------------------



void __fastcall TForm8::Button10Click(TObject *Sender)
{
  RadioButton1->Checked =false;
  RadioButton2->Checked =false;
  ComboBox1->Text="请选择";
  ComboBox2->Text="请选择";
  Edit1->Text="";
  Edit2->Text="";
  DBGrid1->DataSource =DataSource2;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button2Click(TObject *Sender)
{
  Form2->Show() ;
  Form8->Hide() ;        
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button3Click(TObject *Sender)
{
    AnsiString an1=" select * from jckb where ";
    AnsiString lb="";
    if(RadioButton1->Checked ==true)
      lb="入库";
    if(RadioButton2->Checked ==true)
      lb="出库";
    if(lb!="")
     an1+=" hp_sort='"+lb+"' and  ";
    if(ComboBox1->Text!="请选择")
      an1+=" gno='"+ComboBox1->Text+"' and ";
    if(ComboBox2->Text!="请选择")
      an1+=" hno='"+ComboBox2->Text+"' and ";
    an1+= " '1'='1' ";
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->Open()  ;
   DBGrid1->DataSource =DataSource1;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button6Click(TObject *Sender)
{
  DataModule3->ADOQuery1->First() ;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button7Click(TObject *Sender)
{
 DataModule3->ADOQuery1->Prior() ;        
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button8Click(TObject *Sender)
{
  DataModule3->ADOQuery1->Next()  ;        
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button9Click(TObject *Sender)
{
  DataModule3->ADOQuery1->Last()  ;        
}
//---------------------------------------------------------------------------

void __fastcall TForm8::DBGrid1CellClick(TColumn *Column)
{
   Label11->Caption =DataModule3->ADOQuery1->FieldValues["id"];
   Button5->Enabled =true;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button5Click(TObject *Sender)
{
   int i;
   i=MessageBox(NULL,"真得要删除吗","删除窗口",4);
   if(i==6)
   { AnsiString an1=" delete from jckb where id= "+Label11->Caption+" ";
   DataModule3->ADOQuery1->SQL->Clear() ;
   DataModule3->ADOQuery1->SQL->Add(an1);
   DataModule3->ADOQuery1->ExecSQL()  ;
   ShowMessage("删除成功");
   Button5->Enabled =false;
    }
}
//---------------------------------------------------------------------------


