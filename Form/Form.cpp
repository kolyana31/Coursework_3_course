//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form.h"
#include "Obj.h"
#include "Field.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
TCanvas * Obj::device;
WorkingGrid Field;
Connectors AddConnect;


bool PosChoice = false;

bool ShapeChoice = false;

bool StartChoice = false;

bool SecondChoice = false;

bool ConnectionChoice = false;

int TagsChoice = 0;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Image7Click(TObject *Sender)
{
	Move->Checked = false;
	PosChoice = true;
	ShapeChoice = false;
	StartChoice = false;
	SecondChoice = false;
	Status->Caption = "Press to put ur element";
	TagsChoice = (dynamic_cast<TComponent *>(Sender))->Tag;
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	ShapeS ChosenElem(0,0,-1);
	if (PosChoice) {
			ShapeS AddAbleObject(X,Y,TagsChoice);
			Field.AddShape(AddAbleObject);
			Field.ShapesOfField[Field.ShapesOfField.size()-1].DrawObj(TagsChoice,X,Y);
			PosChoice = false;
			Status->Caption = "Object added";
	}
	else if (ShapeChoice) {
		SecondChoice= false;
		if (Field.Choose(X,Y).Type != -1)
		{

			   ChosenElem = Field.Choose(X,Y);
			   if (ChosenElem.XPos == 0) {
				  ShapeChoice = false;
				  Status->Caption = "Object not found";
				  ValuesList->Cells[1][1] = "";
				  ValuesList->Cells[1][2] = "";
				  ValuesList->Cells[1][3] = "";
				  StartConnect->Enabled = false;
			   }
			   else{
				ValuesList->Cells[1][1] = ChosenElem.XPos;
				ValuesList->Cells[1][2] = ChosenElem.YPos;
				ValuesList->Cells[1][3] = ChosenElem.Text;
				ShapeChoice = false;
				StartConnect->Enabled = true;
				Status->Caption = "Object Chosen";
			   }
		}
		else{
				  ShapeChoice = false;
				  Status->Caption = "Object not found";
				  ValuesList->Cells[1][1] = "";
				  ValuesList->Cells[1][2] = "";
				  ValuesList->Cells[1][3] = "";
		}
	}
	else if (StartChoice) {  //ïåðâûé êëèê
		 if(Field.ChooseOPoint(X,Y)->X != 0 && Field.ChooseOPoint(X,Y)->Y != 0){
			AddConnect.StartPoint = Field.ChooseOPoint(X,Y);
			Status->Caption = "OutPut Point Chosen";
			SecondChoice = true;
			StartChoice = false;
		 }
		 else{
			 Status->Caption = "Not found or already chosen";
		 }
	}
	else if(SecondChoice){ //2 êëèê
		if (Field.ChooseIPoint(X,Y)->X != 0 && Field.ChooseIPoint(X,Y)->Y != 0) {
			AddConnect.EndPoint = Field.ChooseIPoint(X,Y);
			Field.AddConnector(AddConnect);
			Status->Caption = "Input Point Chosen";
			Field.ConnectorsOfField[Field.ConnectorsOfField.size()-1].DrawObj(Field.ConnectorsOfField[Field.ConnectorsOfField.size()-1].StartPoint->X,
																			  Field.ConnectorsOfField[Field.ConnectorsOfField.size()-1].StartPoint->Y,
																			  Field.ConnectorsOfField[Field.ConnectorsOfField.size()-1].EndPoint->X,
																			  Field.ConnectorsOfField[Field.ConnectorsOfField.size()-1].EndPoint->Y,
																			  Field.ShapesOfField);
			for (int i = 0; i < Field.ConnectorsOfField.size(); i++) {
				if (Field.ConnectorsOfField[i].ConnectorWay.size() == 0) {
					Field.ConnectorsOfField.erase(Field.ConnectorsOfField.begin()+i);
				}
			}
			SecondChoice = false;
		}
		else{
			Status->Caption = "Not found";
		}
	}
	else if (ConnectionChoice) {
		Field.DeleteÑonnectors(X,Y);
		ConnectionChoice = false;
	}


	if(Grid->Checked){
		Field.GridSetting();
	}
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::repaint1Click(TObject *Sender)
{
	Field.GenerateGrid(ScrollBox1->Width,ScrollBox1->Top,ScrollBox2->Left,ScrollBox2->Height);
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ChooseElemClick(TObject *Sender)
{
	Move->Checked = false;
	PosChoice = false;
	ShapeChoice = true;
	StartChoice = false;
	SecondChoice = false;
	Status->Caption = "Press on element to choose";
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::DeleteElemClick(TObject *Sender)
{
	Move->Checked = false;
	SecondChoice = false;
	ValuesList->Cells[1][1] = "";
	ValuesList->Cells[1][2] = "";
	ValuesList->Cells[1][3] = "";
	Field.DeleteElements();
	Field.Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	Obj::device = this->Canvas;
	Field.GenerateGrid(ScrollBox1->Width,ScrollBox1->Top,ScrollBox2->Left,ScrollBox2->Height);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MoveClick(TObject *Sender)
{
	PosChoice = false;
	ShapeChoice = false;
	StartChoice = false;
	Status->Caption = "Press on field to move chosen element";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClearAll1Click(TObject *Sender)
{
	Field.ClearAll();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GridClick(TObject *Sender)
{
	if (Grid->Checked) {
		Field.GridSetting();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StartConnectClick(TObject *Sender)
{
	StartChoice = true;
	PosChoice = false;
	ShapeChoice = false;
	Move->Checked = false;
	Status->Caption = "Press on other element to connect";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DeleteConnectionClick(TObject *Sender)
{
	ConnectionChoice = true;
	StartChoice = false;
	PosChoice = false;
	ShapeChoice = false;
	Move->Checked = false;
	SecondChoice = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{

	if (Move->Checked && Shift.Contains(ssLeft)) {
		if (ValuesList->Cells[1][1] != "" && ValuesList->Cells[1][2]!= "") {
			for (int i = 0; i < Field.ShapesOfField.size(); i++) {
				if(Field.ShapesOfField[i].Selected == true){
					Field.ShapesOfField[i].Move(X,Y);
					Field.Repaint();

					ValuesList->Cells[1][1] = X;
					ValuesList->Cells[1][2] = Y;
					break;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ValuesListStringsChange(TObject *Sender)
{
	if (ValuesList->Cells[1][1] != "" && ValuesList->Cells[1][2]!= "") {
		for (int i = 0; i < Field.ShapesOfField.size(); i++) {
			if(Field.ShapesOfField[i].Selected == true){

				Field.ShapesOfField[i].XPos = ValuesList->Cells[1][1].ToInt();
				Field.ShapesOfField[i].YPos = ValuesList->Cells[1][2].ToInt();
				Field.ShapesOfField[i].Text = ValuesList->Cells[1][3];
				break;
			}
		}
	}
	Field.Repaint();
}
//---------------------------------------------------------------------------





void __fastcall TMainForm::FormMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled)
{
	for (int i = 0; i < Field.ShapesOfField.size(); i++) {
		Field.ShapesOfField[i].Selected = false;
		Field.ShapesOfField[i].Move(Field.ShapesOfField[i].XPos,Field.ShapesOfField[i].YPos+10);
	}
	ValuesList->Cells[1][1] = "";
	ValuesList->Cells[1][2] = "";
	ValuesList->Cells[1][3] = "";
	Field.Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
	for (int i = 0; i < Field.ShapesOfField.size(); i++) {
		Field.ShapesOfField[i].Selected = false;
		Field.ShapesOfField[i].Move(Field.ShapesOfField[i].XPos,Field.ShapesOfField[i].YPos-10);
	}
	ValuesList->Cells[1][1] = "";
	ValuesList->Cells[1][2] = "";
	ValuesList->Cells[1][3] = "";
	Field.Repaint();
}
//---------------------------------------------------------------------------


