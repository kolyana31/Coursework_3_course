//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TScrollBox *ScrollBox1;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TImage *Image1;
	TScrollBox *ScrollBox2;
	TValueListEditor *ValuesList;
	TMenuItem *repaint1;
	TButton *ChooseElem;
	TButton *DeleteElem;
	TLabel *Status;
	TCheckBox *Move;
	TCheckBox *Grid;
	TMenuItem *ClearAll1;
	TButton *StartConnect;
	TButton *DeleteConnection;
	TImage *Image2;
	TImage *Image9;
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall repaint1Click(TObject *Sender);
	void __fastcall ChooseElemClick(TObject *Sender);
	void __fastcall DeleteElemClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MoveClick(TObject *Sender);
	void __fastcall ClearAll1Click(TObject *Sender);
	void __fastcall GridClick(TObject *Sender);
	void __fastcall StartConnectClick(TObject *Sender);
	void __fastcall DeleteConnectionClick(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall ValuesListStringsChange(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
