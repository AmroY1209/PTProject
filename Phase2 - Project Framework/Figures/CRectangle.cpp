#include "CRectangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

void CRectangle::Draw(Output* pOut) const
{
	bool x = isValid(Corner1, Corner2);
	//Call Output::DrawRect to draw a rectangle on the screen	
	if (x)
	{
		pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
	}
	else pOut->PrintMessage("Invalid Drawing Area Please try again");
}

void CRectangle::print(Output* pOut)
{
	int width = Corner2.x - Corner1.x;
	if (width < 0) { width *= -1; }

	int length = Corner2.y - Corner1.y;
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
	strl += to_string(length * width);

	pOut->PrintMessage(strl);
}
float CRectangle::GetArea()
{
	int width = Corner2.x - Corner1.x;
	if (width < 0) { width *= -1; }

	int length = Corner2.y - Corner1.y;
	if (length < 0) { length *= -1; }

	return length * width;
}

bool CRectangle::isValid(Point C1, Point C2) const
{
	if ((C1.x < 0 || C1.x>UI.width) || (C2.x<0 || C2.x>UI.width))
	{
		return false;
	}
	else if ((C1.y<UI.ToolBarHeight || C1.y>(UI.height - UI.StatusBarHeight)) || (C2.y<UI.ToolBarHeight || C2.y>(UI.height - UI.StatusBarHeight)))
	{
		return false;
	}
	else return true;
}

bool CRectangle::checkLoc(int x, int y)
{
	if (((Corner1.x <= x && x <= Corner2.x) || (Corner2.x <= x && x <= Corner1.x)) && ((Corner1.y <= y && y <= Corner2.y) || (Corner2.y <= y && y <= Corner1.y)))
	{
		return true;
	}
	else return false;

}
void CRectangle::Move(int x, int y)
{
	Corner2.x = x - Corner1.x + Corner2.x; Corner2.y = y - Corner1.y + Corner2.y;
	Corner1.x = x; Corner1.y = y;
}

void CRectangle::Paste(int x, int y, Point& temp1, Point& temp2, Point& temp3)
{
	temp2.x = x - Corner1.x + Corner2.x; temp2.y = y - Corner1.y + Corner2.y;
	temp1.x = x; temp1.y = y;
}

Point CRectangle::getFirstPt()
{
	Point P;
	P.x = Corner1.x;
	P.y = Corner1.y;
	return P;
}
Point CRectangle::getLastPt()
{
	Point P;
	P.x = Corner2.x;
	P.y = Corner2.y;
	return P;
}

Point CRectangle::getCenter()
{
	Point P;
	P.x = (Corner1.x + Corner2.x) / 2;
	P.y = (Corner1.y + Corner2.y) / 2;
	return P;
}
void CRectangle::Rotate(string degree)
{

	Point C1 = Corner1;	Point C2 = Corner2;
	float dist = (abs(Corner2.x - Corner1.x) - abs(Corner1.y - Corner2.y)) / 2.0;
	if (degree == "90")
	{
		if (Corner1.x < Corner2.x && Corner1.y < Corner2.y)
		{
			Corner1.x = C1.x + abs(dist) + abs(C1.y - C2.y);
			Corner1.y = C1.y - abs(dist);
			Corner2.x = C2.x - abs(dist) - abs(C1.y - C2.y);
			Corner2.y = C2.y + abs(dist);
		}
		else if (Corner1.x > Corner2.x && Corner1.y < Corner2.y)
		{
			Corner1.x = C1.x - abs(dist);
			Corner1.y = C1.y + abs(C1.y - C2.y) + abs(dist);
			Corner2.x = C2.x + abs(dist);
			Corner2.y = C2.y - abs(C1.y - C2.y) - abs(dist);
		}
		else if (Corner1.x > Corner2.x && Corner1.y > Corner2.y)
		{
			Corner1.x = C1.x - abs(dist) - abs(C1.y - C2.y);
			Corner1.y = C1.y + abs(dist);
			Corner2.x = C2.x + abs(dist) + abs(C1.y - C2.y);
			Corner2.y = C2.y - abs(dist);
		}
		else if (Corner1.x < Corner2.x && Corner1.y > Corner2.y)
		{
			Corner1.x = C1.x + abs(dist);
			Corner1.y = C1.y - abs(C1.y - C2.y) - abs(dist);
			Corner2.x = C2.x - abs(dist);
			Corner2.y = C2.y + abs(C1.y - C2.y) + abs(dist);
		}
	}
	else if (degree == "180")
	{
		Corner1 = C2;
		Corner2 = C1;

	}
	else if (degree == "270")
	{
		Corner1.x = (Corner1.y - getCenter().y) + getCenter().x;
		Corner1.y = -(Corner1.x - getCenter().x) + getCenter().y;
		Corner2.x = (Corner2.y - getCenter().y) + getCenter().x;
		Corner2.y = -(Corner2.x - getCenter().x) + getCenter().y;

	}
}

void CRectangle::Resize(string scale)
{
	if (scale == "1/4" || scale == "quarter")
	{
		Corner2.x = (Corner2.x - Corner1.x) / 4 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) / 4 + Corner1.y;
	}
	else if (scale == "1/2" || scale == "half")
	{
		Corner2.x = (Corner2.x - Corner1.x) / 2 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) / 2 + Corner1.y;
	}
	else if (scale == "2" || scale == "double")
	{
		Corner2.x = (Corner2.x - Corner1.x) * 2 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) * 2 + Corner1.y;
	}
	else if (scale == "4" || scale == "quadruple")
	{
		Corner2.x = (Corner2.x - Corner1.x) * 4 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) * 4 + Corner1.y;
	}
}

void CRectangle::Save(ofstream& Outfile)
{
	string DrawClr = GetColorName(FigGfxInfo.DrawClr);
	Outfile << "RECT\t" << MYid << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t";
	Outfile << Corner2.y << "\t" << DrawClr << "\t";
	if (FigGfxInfo.isFilled)
	{
		string FillClr = GetColorName(FigGfxInfo.FillClr);
		Outfile << FillClr << "\n";
	}
	else
	{
		Outfile << "NO_FILL\n";
	}
}
void CRectangle::Load(ifstream& Infile)
{
	string draw_clr;
	string fill;
	Infile >> MYid >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	Infile >> draw_clr >> fill;
	FigGfxInfo.DrawClr = GetColor(draw_clr);
	if (fill == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.FillClr = GetColor(fill);
	}
}