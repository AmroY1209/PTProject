#include "ZoomInAction.h"
#include "Action.h"
#include "../Figures/CFigure.h"

ZoomInAction::ZoomInAction(ApplicationManager* pApp) : Action(pApp)
{}

void ZoomInAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("To Zoom In, Please type '2' or '4' for the respective scaling");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();

}

//Execute the action
void ZoomInAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//This action needs to read some parameters first
	ReadActionParameters();
	//Get the scale from the user

	string scale = pIn->GetString(pOut);

	while (scale != "2" && scale != "4" && scale != "double" && scale != "quadruple")
	{
		pOut->PrintMessage("Wrong scaling input! please type '2' or '4'");
		scale = pIn->GetString(pOut);
	}
	pOut->PrintMessage("You selected: " + scale);

	ZoomIN(scale);
	int x, y;
	pOut->PrintMessage("click any where to exit zoom");
	pIn->GetPointClicked(x, y); //3lashan ytl3 bara el zoom 

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();

}

void ZoomInAction::ZoomIN(string scale)
{
	image img2 = "images\\MenuItems\\zoomtemp.jpg";
	Output* pOut = pManager->GetOutput();
	if (scale == "2" || scale == "double")
	{
		pOut->StoreImage(img2, 0, UI.ToolBarHeight + 1, UI.width / 2, UI.height / 2);
	}
	else if (scale == "4" || scale == "quadruple")
	{
		pOut->StoreImage(img2, 0, UI.ToolBarHeight + 2, UI.width / 4, UI.height / 4);
	}
	pOut->ClearDrawArea();

	pOut->DrawImage(img2, 0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
