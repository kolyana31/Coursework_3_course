#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.pngimage.hpp>

#include <vector>



class Obj
{
public:
	static TCanvas *device;
	int XPos;
	int YPos;
	int Wight;
	int Height;
	int Type;

	void Show();
	void Hide();
	virtual void DrawObj(int Value,int X,int Y);
};


class ShapeS : public Obj
{
public:
	short int EnterExitAmount;
	bool Selected;
	short int Type;
	std::vector<TPoint*> EnterPoints;
	std::vector<TPoint*> ExitPoints;
	AnsiString Text;
	void DrawObj(int Value,int X,int Y);
	void Move(int XChange, int YChange);

	ShapeS(int X,int Y,short int Tip){
		XPos = X;
		YPos = Y;
		Type = Tip;
		Text = "Text";
		Selected = false;
	}
};

class Connectors : public Obj
{
public:
	TPoint* StartPoint;
	TPoint* EndPoint;
	std::vector<TPoint> ConnectorWay;
	void DrawObj(int XStart,int YStart,int XEnd,int YEnd,std::vector<ShapeS> ShapeArray);
};

#endif
