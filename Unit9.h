//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TLabel *Label4;
        TLabel *Label6;
        TComboBox *ComboBox3;
        TDBGrid *DBGrid1;
        TButton *Button1;
        TButton *Button10;
        TButton *Button2;
        TBevel *Bevel1;
        TLabel *Label2;
        TComboBox *ComboBox1;
        TLabel *Label1;
        TButton *Button3;
        TComboBox *ComboBox2;
        TDataSource *DataSource2;
        TLabel *Label3;
        TImage *Image1;
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClick(TObject *Sender);
        void __fastcall ComboBox2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm9(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
