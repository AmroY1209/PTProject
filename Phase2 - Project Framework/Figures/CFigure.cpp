#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	MYid = ++ID;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::print(Output* pOut)
{}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }


void CFigure::SetID(int id)
{
	ID = id;
}


int CFigure::getID()
{
	return MYid;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::HighLightClr()
{
	FigGfxInfo.HighLightClr = VIOLET;
}


bool CFigure::checkLoc(int x, int y)
{
	return true;
}
GfxInfo CFigure::GetGFXINFO()
{
	return FigGfxInfo;
}
 //To hide the picked figure
void CFigure::hide()
{
	fig_status = true;
}
//To unhide the picked figure
void CFigure::unHide()
{
	fig_status = false;
}
//Returns status of the figure (whether it is hidden or unhidden)
bool CFigure::figStatus()
{
	return fig_status;
}