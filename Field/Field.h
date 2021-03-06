#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.pngimage.hpp>

#include <vector>

#include "Obj.h"


class WorkingGrid
{
public:
	std::vector<TPoint> GridCord;
	std::vector<ShapeS*> ShapesOfField;
	std::vector<Connectors> ConnectorsOfField;
    int CurId;

	WorkingGrid(){
    	CurId = -1;
	}

	void Choose(int,int);
	TPoint* ChooseOPoint(int,int);
	TPoint* ChooseIPoint(int,int);
	void GenerateGrid(int X,int Y,int W,int H);
	void DeleteElements();
	void DeleteÑonnectors(int,int);
	void AddShape(ShapeS*);
	void AddConnector(Connectors);
	void ClearAll();
	void Repaint();
	void GridSetting();
};


