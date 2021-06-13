#include "CutAction.h"
#include "..\ApplicationManager.h"
CutAction::CutAction(ApplicationManager* pApp):Action(pApp)
{
	Cx = 0;
	Cy = 0;
}
CutAction::~CutAction()
{
}
void CutAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	SelectedFig_List = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();
	if (SelectedFig_List[0])
		pOut->PrintMessage("Cut Figure: Selected figure has been cut to the Clipboard");
	else if (!SelectedFig_List[0])
		pOut->PrintMessage("Cut Figure: Please select a figure first to cut");
	 
}
void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (SelectedFig_List[0] != NULL)
	{
		for (int i = 0; i < SelecFigCount; i++)
			SelectedFig_List[i]->SetSelected(false);
		pManager->SetClipboard(SelectedFig_List);

		for (int i = 0; i < SelecFigCount; i++)
		{
			pManager->remove_Fig(SelectedFig_List[i]->getID());
		}
		pOut->ClearDrawArea();
		pOut->CreateUtilityToolbar();
		pManager->setCut(true);   //Indication that the figure is cut
	}
}
