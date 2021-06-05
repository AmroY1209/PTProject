#include "PasteAction.h"
#include "..\ApplicationManager.h"
#include "AddRectAction.h"
#include "..\Figures\CFigure.h"

PasteAction::PasteAction(ApplicationManager* pApp):Action(pApp)
{
	Cx=0;
	Cy=0;
}
PasteAction::~PasteAction()
{
}
void PasteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Paste Figure: Click anywhere to paste");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void PasteAction::Execute()
{
	ReadActionParameters();
	fig = pManager->GetClipboard();
	if (fig == NULL)
	{
		return;
	}
	else
	{
		if (dynamic_cast<CRectangle*>(fig))
		{
			Point CP1;
			Point CP2;
			int NewCP1X= Cx- (((CRectangle*)fig)->GetWidth_Rect())/2;
			int NewCP2X= Cx+ (((CRectangle*)fig)->GetWidth_Rect()) / 2;
			int NewCP1Y= Cy- (((CRectangle*)fig)->GetHeight_Rect()) / 2;
			int NewCP2Y= Cy + (((CRectangle*)fig)->GetHeight_Rect()) / 2;
			CP1.x = NewCP1X;
			CP1.y = NewCP1Y;
			CP2.x = NewCP2X;
			CP2.y = NewCP2Y;

			//Checks that the y-coordinate of the clicked point is in the drawing area
			//if (CP1.y > UI.ToolBarHeight && CP1.y <= (UI.width - UI.StatusBarHeight) && CP2.y > UI.ToolBarHeight && CP2.y <= (UI.width - UI.StatusBarHeight))
			//{
			CRectangle* pR = new CRectangle(CP1, CP2, (fig->GetGFXINFO()));
			pManager->AddFigure(pR);
			/*}
			else
			{
				Output* pOut = pManager->GetOutput();
				Input* pIn = pManager->GetInput();
				pOut->PrintMessage("You can only draw in the drawing area, Click in the drawing area to paste");
				pIn->GetPointClicked(Cx, Cy);
			}*/
		}
		
	}
}