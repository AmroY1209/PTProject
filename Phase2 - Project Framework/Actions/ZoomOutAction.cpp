#include "ZoomOutAction.h"
#include "Action.h"
#include "../Figures/CFigure.h"

ZoomOutAction::ZoomOutAction(ApplicationManager* pApp) : Action(pApp)
{}

void ZoomOutAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("To Zoom Out, Please type '1/2' or '1/4' for the respective scaling");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();

}

//Execute the action
void ZoomOutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//This action needs to read some parameters first
	ReadActionParameters();
	//Get the scale from the user

	string scale = pIn->GetString(pOut);

	while (scale != "1/2" && scale != "1/4" && scale != "half" && scale != "quarter")
	{
		pOut->PrintMessage("Wrong scaling input! please type '1/2' or '1/4'");
		scale = pIn->GetString(pOut);
	}
	pOut->PrintMessage("You selected: " + scale);

	ZoomOut(scale);
	int x, y;
	pOut->PrintMessage("click any where to exit zoom");
	pIn->GetPointClicked(x, y); //3lashan ytl3 bara el zoom 

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pOut->CreateUtilityToolbar();

}

void ZoomOutAction::ZoomOut(string scale)
{
	image img2 = "images\\MenuItems\\zoomtemp.jpg";
	Output* pOut = pManager->GetOutput();
	//pOut->StoreImage(img2, 2, UI.ToolBarHeight, UI.width, (UI.height-UI.StatusBarHeight));
	pOut->StoreImage(img2, 0, UI.ToolBarHeight, UI.width - 15 - UI.UtilToolbarWidth, (UI.height - UI.StatusBarHeight - UI.ToolBarHeight));
	pOut->ClearDrawArea();
	if (scale == "1/2" || scale == "half")
	{
		pOut->DrawImage(img2, 0, UI.ToolBarHeight + 1, UI.width / 2, UI.height / 2);
	}
	else if (scale == "1/4" || scale == "quarter")
	{
		pOut->DrawImage(img2, 0, UI.ToolBarHeight + 2, UI.width / 4, UI.height / 4);
	}
	pOut->CreateUtilityToolbar();
}
void ZoomOutAction::Undo()
{


	//Output* pOut = pManager->GetOutput();
	//pOut->ClearDrawArea();
	//figcount = pManager->GetFigCount();
	//pManager->SetFigCount(--figcount);
}

void ZoomOutAction::Redo()
{

	//Output* pOut = pManager->GetOutput();
	//pOut->ClearDrawArea();
	//Execute();
}
