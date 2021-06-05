#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void print(Output* pOut);
	bool checkLoc(int x, int y);
	float getarea(Point, Point, int, int);

	 Point getFirstPt() ;
	 Point getLastPt();
	void Move(int x, int y) ;        //Move the figure
	void Resize(string scale);					//Resize the figure
};

#endif