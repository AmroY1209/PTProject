#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}


void CTriangle::print(Output* pOut)
{
	string strl;
	strl = to_string(MYid);
	strl += "  ";
	strl += to_string(Corner1.x);
	strl += ", ";
	strl += to_string(Corner1.y);
	strl += "  ";
	strl += to_string(Corner2.x);
	strl += ", ";
	strl += to_string(Corner2.y);
	strl += "  ";
	strl += to_string(Corner3.x);
	strl += ", ";
	strl += to_string(Corner3.y);
	
	pOut->PrintMessage(strl);
}


bool CTriangle::checkLoc(int x, int y)
{
	return true;
}