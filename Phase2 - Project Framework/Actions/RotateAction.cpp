#include "Action.h"
#include "RotateAction.h"
#include "../Figures/CFigure.h"

RotateAction::RotateAction(ApplicationManager* pApp) : Action(pApp)
{}

void RotateAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Rotate the selected item by 90, 180, or 270 degrees. Please type the rotation degree you want: ");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();

}

void RotateAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//This action needs to read some parameters first
	ReadActionParameters();
	//Get the degree from the user
	if (SelecFigCount != 0)
	{
		string degree = pIn->GetString(pOut);
		while (degree != "90" && degree != "180" && degree != "270")
		{
			pOut->PrintMessage("Wrong rotation degree input! please type '90', '180', or '270'");
			degree = pIn->GetString(pOut);
		}
		pOut->PrintMessage("You selected: " + degree);
		for (int i = 0; i < SelecFigCount; i++)
		{
			SelectedFigList[i]->Rotate(degree);
		}
		pOut->ClearDrawArea();
		pOut->CreateUtilityToolbar();
		pManager->UpdateInterface();
	}
	else
	{
		pOut->PrintMessage("No items selected, please select an item first!");
	}

}

void RotateAction::Undo()
{

}
void RotateAction::Redo()
{

}
RotateAction::~RotateAction()
{}