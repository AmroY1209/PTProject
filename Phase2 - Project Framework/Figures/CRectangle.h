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


	 Point getFirstPt() ;
	 Point getLastPt();
	 void Move(int x, int y) ;        //Move the figure
	 void Resize(string scale);					//Resize the figure
	 void Save(ofstream& Outfile);	//Save the figure parameters to the file
	 //void Load(ifstream& Infile);	//Load the figure parameters to the file

	Point GetP1_Rect();   //Gets coordinates of corner point 1
	Point GetP2_Rect();   //Gets coordinates of corner point 2
	//Get width of rectangle drawn
	virtual int GetWidth_Rect();
	//Get height of rectangle drawn
	virtual int GetHeight_Rect();
};
