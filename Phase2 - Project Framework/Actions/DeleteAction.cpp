#include "DeleteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters()
{
	selectedFig = pManager->GetSelectedFigs();

	SelecFigCount = pManager->GetSelectedCount();

}

void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (selectedFig[0] == NULL)
	{
		pOut->PrintMessage("Invalid Action: please select figure first");
	}
	else
	{
		for (int i = 0; i < SelecFigCount; i++)
		{
			DelID = selectedFig[i]->getID();

			pManager->removeFig(DelID);

			delete selectedFig[i];

		}
		pManager->clearselcFig();
		pOut->PrintMessage("Figure Deleted");
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
	}


}

DeleteAction::~DeleteAction() {}