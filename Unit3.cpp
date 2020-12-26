//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDataModule3 *DataModule3;
//---------------------------------------------------------------------------
__fastcall TDataModule3::TDataModule3(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDataModule3::DataModuleCreate(TObject *Sender)
{
   ADOQuery1->ConnectionString="DRIVER={MYSQL ODBC 5.1 DRIVER};server=127.0.0.1; DATABASE=ckgl;USER=root;PASSWORD=123;OPTION=3";
}
//---------------------------------------------------------------------------
 