#pragma once

#include "CFigure.h"
class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void print(Output* pOut);
	bool checkLoc(int x, int y);

	Point GetP1_Rect();   //Gets coordinates of corner point 1
	Point GetP2_Rect();   //Gets coordinates of corner point 2
};
