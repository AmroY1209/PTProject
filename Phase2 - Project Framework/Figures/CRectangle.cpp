#include "CRectangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::print(Output* pOut)
{
	int width = Corner2.x - Corner1.x;
	if (width < 0) { width *= -1; }
	
	int length= Corner2.y - Corner1.y;
	if (length < 0) { length *= -1; }

	string strl;
	strl = "Figure ID: ";
	strl += to_string(MYid);
	strl += " - Corner 1: (";
	strl += to_string(Corner1.x);
	strl += ", ";
	strl += to_string(Corner1.y);
	strl += ") - Corner 2: (";
	strl += to_string(Corner2.x);
	strl += ", ";
	strl += to_string(Corner2.y);
	strl += ") - Length: ";
	strl += to_string(length);
	strl += " - Width: ";
	strl += to_string(width);
	strl += " - Area: ";
	strl += to_string(length*width);

	pOut->PrintMessage(strl);
}


bool CRectangle::checkLoc(int x, int y)
{
	if ( ((Corner1.x <= x && x <= Corner2.x) || (Corner2.x <= x && x <= Corner1.x)) && ((Corner1.y <=y && y<= Corner2.y) || (Corner2.y <=y && y<= Corner1.y)) )
	{
		return true;
	}
	else return false;

}
//Gets coordinates of corner point 1
Point CRectangle::GetP1_Rect()
{
	return Corner1;
}
//Gets coordinates of corner point 2
Point CRectangle::GetP2_Rect()
{
	return Corner2;
}
void CRectangle::Move(int x, int y)
{
	Corner2.x = x - Corner1.x + Corner2.x; Corner2.y = y - Corner1.y + Corner2.y;
	Corner1.x = x; Corner1.y = y;
}

Point CRectangle::getFirstPt()
{
	Point P;
	P.x = Corner1.x;
	P.y = Corner1.y;
	return P;
}
//Get width of the drawn rectangle
int CRectangle::GetWidth_Rect()
{
	int w = Corner1.x - Corner2.x;
	if (w > 0)
		return w;
	else
		return (-w);
}
//Get height of the drawn rectangle
int CRectangle::GetHeight_Rect()
{
	int h = Corner1.y - Corner2.y;
	if (h > 0)
		return h;
	else
		return (-h);
}