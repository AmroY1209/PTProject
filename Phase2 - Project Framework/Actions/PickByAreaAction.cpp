#include "PickByAreaAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"

PickByAreaAction::PickByAreaAction(ApplicationManager* pApp) :Action(pApp)
{
	Cx = 0;
	Cy = 0;
	no_of_figs = 0;
	rightPick = 0;
	wrongPick = 0;
	num_of_each_fig[0] = 0;
	num_of_each_fig[1] = 0;
	num_of_each_fig[2] = 0;
	no_to_pick = 0;
}

PickByAreaAction::~PickByAreaAction()
{
}

void PickByAreaAction::printScore(int score)
{
	string msg;
	if (score == 1)
	{
		rightPick++;
		msg = "Right, Keep Going!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";
	}
	else if (score == 2)
	{
		wrongPick++;
		msg = "Wrong, Look carfully!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";
	}
	else if (score == 3)
		msg = "YOU WIN!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(msg);
}

void PickByAreaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Game: Pick Figures by Area , Click on a figure to start playing ");

	fig = pManager->GetDrawnFigs();
	no_of_figs = pManager->GetFigCount();

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	CFigure* pFig = pManager->GetFigure(Cx, Cy);
	MaxArea = pFig->GetArea();
	for (int i = 0; i < no_of_figs; i++)
	{
		if (fig[i]->GetArea() < MaxArea)
		{
			no_to_pick++;
		}

		fig[i]->unHide();
	}

}

void PickByAreaAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (no_to_pick >= 1)
	{
		pOut->PrintMessage("You have to pick all figures smaller than the one you chose!");
		while (no_to_pick > 0)
		{
			pIn->GetPointClicked(Cx, Cy);
			if (Cy > UI.ToolBarHeight || Cx > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				CFigure* selectedFigure = pManager->GetFigure(Cx, Cy);
				CFigure* SecondMaxFig = NULL;
				float SecondMaxArea = -10;
				if (selectedFigure != NULL)
				{
					for (int i = 0; i < no_of_figs; i++)
					{
						if (fig[i]->GetArea() < MaxArea && fig[i]->figStatus() == false && fig[i]->GetArea() > SecondMaxArea)
						{
							SecondMaxFig = fig[i];
							SecondMaxArea = fig[i]->GetArea();
						}
					}
					if (selectedFigure == SecondMaxFig)
					{
						IsCorrect = true;
					}
					else
						IsCorrect = false;

					if (IsCorrect == true)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (IsCorrect == false)
					{
						printScore(2);
						if (selectedFigure->GetArea() > MaxArea)
						{
							selectedFigure->hide();
							pManager->UpdateInterface_PlayMode();
						}
					}
				}
			}
			else
			{
				pOut->PrintMessage("Toolbar clicked, you stopped the game");
				no_to_pick = -1;
			}
			if (no_to_pick == 0)
				printScore(3);
		}
	}
	else if (no_of_figs <= 1)
	{
		pOut->PrintMessage("You must draw at least two figures to play!");
	}
	else if (no_to_pick == 0)
	{
		pOut->PrintMessage("You have selected the smallest figure! please try the game again");
	}
	for (int i = 0; i < no_of_figs; i++)
	{
		fig[i]->unHide();
		pManager->UpdateInterface_PlayMode();
	}
}

void PickByAreaAction::Undo()
{

}

void PickByAreaAction::Redo()
{

}