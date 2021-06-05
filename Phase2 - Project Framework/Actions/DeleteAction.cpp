#include "DeleteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp)
{}

void DeleteAction::ReadActionParameters()
{
	selectedFig = pManager->GetSelectedFigs();
	selecFigCount = pManager->GetSelectedCount();
}

void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	//3lashan nbd2 lazm n3ml cheeck
	if (selectedFig[0] == NULL)
	{
		pOut->PrintMessage("Invalid! select figure first");
	}
	else
	{
		for (int i = 0; i < selecFigCount; i++)
		{

		}
	}
	


}

DeleteAction::~DeleteAction(){}