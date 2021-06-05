#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, Radius, FigGfxInfo, Selected);
}


void CCircle::print(Output* pOut)
{
	float radius = sqrt((Center.x - Radius.x) * (Center.x - Radius.x) + (Center.y - Radius.y) * (Center.y - Radius.y));
	int Area = 3.14 * (radius) * (radius);

	string strl;
	strl = "Figure ID: ";
	strl += to_string(MYid);
	strl += "  Center: (";
	strl += to_string(Center.x);
	strl += ", ";
	strl += to_string(Center.y);
	strl += ")  Radius: ";
	strl += to_string(radius);
	strl += "  Area: ";
	strl += to_string(Area);


	pOut->PrintMessage(strl);
}


bool CCircle::checkLoc(int x, int y)
{
	double radius = sqrt((Center.x - Radius.x) * (Center.x - Radius.x) + (Center.y - Radius.y) * (Center.y - Radius.y));
	double check = sqrt((x - Center.x) * (x - Center.x) + (y - Center.y) * (y - Center.y));
	if (check <= radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CCircle::Move(int x, int y)
{
	Radius.x = x - Center.x + Radius.x; Radius.y = y - Center.y + Radius.y;
	Center.x = x; Center.y = y;
}

Point CCircle::getFirstPt()
{
	return Center;
}

Point CCircle::getLastPt()
{
	return Radius;
}

void CCircle::Resize(string scale)
{
	if (scale == "1/4" || scale == "quarter")
	{
		Radius.x = (Radius.x - Center.x) / 4 + Center.x;
		Radius.y = (Radius.y - Center.y) / 4 + Center.y;
	}
	else if (scale == "1/2" || scale == "half")
	{
		Radius.x = (Radius.x - Center.x) / 2 + Center.x;
		Radius.y = (Radius.y - Center.y) / 2 + Center.y;
	}
	else if (scale == "2" || scale == "double")
	{
		Radius.x = (Radius.x - Center.x) * 2 + Center.x;
		Radius.y = (Radius.y - Center.y) * 2 + Center.y;
	}
	else if (scale == "4" || scale == "quadruple")
	{
		Radius.x = (Radius.x - Center.x) * 4 + Center.x;
		Radius.y = (Radius.y - Center.y) * 4 + Center.y;
	}
}