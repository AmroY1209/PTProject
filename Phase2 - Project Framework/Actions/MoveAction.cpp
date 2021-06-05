#include "MoveAction.h"
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "../DEFS.h"

MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp)
{}

void MoveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Move the selected item to a point. Click on a point");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();
	//Read a point and store in point P
	pIn->GetPointClicked(P.x, P.y);


	pOut->ClearStatusBar();

}

//Execute the action
void MoveAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (SelecFigCount != 0)
	{
		SelectedFigList[0]->Move(P.x, P.y);
		Point newPosition;
		for (int i = 1; i < SelecFigCount; i++)
		{
			newPosition.x = P.x - SelectedFigList[i]->getFirstPt().x;
			newPosition.y = P.y - SelectedFigList[i]->getFirstPt().y;
			SelectedFigList[i]->Move(newPosition.x, newPosition.y);
		}
	}
	else
	{
		pOut->PrintMessage("No items selected, please select an item first!");
	}

}