#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	StartingPoint = P1;
	EndPoint = P2;
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(StartingPoint, EndPoint, FigGfxInfo, Selected);
}