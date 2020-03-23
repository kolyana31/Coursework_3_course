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
	std::vector<ShapeS> ShapesOfField;
	std::vector<Connectors> ConnectorsOfField;

	//1 ����� ��� ����� ����� � 2 ����� ��� ����� ������,1 ���� ����� ��� ����� ������ � 2 ���� ����� ����� �����

	ShapeS Choose(int,int);
	TPoint* ChooseOPoint(int,int);//output �����
	TPoint* ChooseIPoint(int,int);//input �����
	void GenerateGrid(int X,int Y,int W,int H);
	void DeleteElements();
	void Delete�onnectors(int,int);
	void AddShape(ShapeS);
	void AddConnector(Connectors);
	void ClearAll();
	void Repaint();
	void GridSetting();
};


