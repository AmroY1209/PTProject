#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point StartingPoint;
	Point EndPoint;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void print(Output* pOut);
	bool checkLoc(int x, int y);

	 Point getFirstPt() ;
	 Point getLastPt();
	 void Move(int x, int y);        //Move the figure
	 void Resize(string scale);					//Resize the figure
	 void Save(ofstream& Outfile);	//Save the figure parameters to the file
	 //void Load(ifstream& Infile);	//Load the figure parameters to the file
};

#endif