#include "CutAction.h"
#include "..\ApplicationManager.h"
CutAction::CutAction(ApplicationManager* pApp) :Action(pApp)
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

	pOut->PrintMessage("Cut Figure: Selected figure has been cut to the Clipboard, Click any where to continue");

	SelectedFig_List = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();   //mlosh lazma
	Temp_Count = SelecFigCount;  //mab2tsh 3ayzo
	CFigure** TempList = new CFigure * [SelecFigCount];   //Temporary list of figures
	for (int i = 0; i < SelecFigCount; i++)
	{
		TempList[i] = SelectedFig_List[i];
	}
	pManager->SetClipboard(TempList);
	for (int i = 0; i < SelecFigCount; i++)
	{
		/*DelID = SelectedFig_List[i]->getID();

		pManager->removeFig(DelID);*/

		delete SelectedFig_List[i];

	}
	//emsah el selected figure hena ya youssef
	//DeleteAction Temp(pManager);
	//Temp.Execute();
	pManager->OnlyclearselcFig();
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void CutAction::Execute()
{
	ReadActionParameters();
	//fig = pManager->GetFigure(Cx, Cy);  //Get the coordinates of the selected figure
	//pManager->SetClipboard(fig);
	//pManager->SetIsFigCut(true);       //The Figure is cut not copied
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}
void CutAction::Undo()
{


	//Output* pOut = pManager->GetOutput();
	//pOut->ClearDrawArea();
	//figcount = pManager->GetFigCount();
	//pManager->SetFigCount(--figcount);
}

void CutAction::Redo()
{

	//Output* pOut = pManager->GetOutput();
	//pOut->ClearDrawArea();
	//Execute();
}