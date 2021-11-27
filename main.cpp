#include <iostream>
#include <string>
using namespace std;

// Prototype methods
void drawInputBox();
void shapeSelectionInput();
void sizeSelectionInput(int shapeType);
void drawSquare(int size);
void drawRightTriangle(int size);
void drawIsoscelesTriangle(int size, bool shouldRestart);
void drawHourglass(int size);
void drawDiamond(int size);

// Welcomes the user
int main()
{
	cout << "Welcome to the shape renderer! \nYou can draw a few different shapes at a variety of sizes!" << endl;
	drawInputBox();

	return 0;
}

// Draws the box that shows all options
void drawInputBox()
{
	cout << "********************************************************************************" << endl;
	cout << "* Please select a menu option(1 - 6) :" << endl;
	cout << "* 1 - Square" << endl;
	cout << "* 2 - Right Triangle" << endl;
	cout << "* 3 - Isosceles Triangle" << endl;
	cout << "* 4 - Hourglass" << endl;
	cout << "* 5 - Diamond" << endl;
	cout << "* 6 - Quit(exit the application)" << endl;
	cout << "********************************************************************************" << endl;
	cout << "Please select a menu option(1-6)" << endl;

	shapeSelectionInput();
}

// Prompts user to input shape selection
void shapeSelectionInput()
{
	int shapeSelection;

	cin >> shapeSelection;
	if (shapeSelection < 1 || shapeSelection > 6)
	{
		cout << "You have not selected a valid menu option, please try again." << endl;
		cout << "Please select a menu option(1-6)" << endl;
		shapeSelectionInput();
		return;
	}
	else
		sizeSelectionInput(shapeSelection);
}

// Prompts user for size of shape
void sizeSelectionInput(int shapeType)
{
	int sizeSelection = 0;

	// Asks for square size
	if (shapeType == 1)
	{
		cout << "You have selected a square!  What size should your square be (1-20)?" << endl;
		cin >> sizeSelection;

		// Re-promts user for size if they chose inappropriate size
		if (sizeSelection < 1 || sizeSelection > 20)
		{
			cout << "You have not selected an appropriate size, please try again." << endl;
			sizeSelectionInput(1);
			return;
		}
		else drawSquare(sizeSelection);
	}

	// Asks for right triangle size
	else if (shapeType == 2)
	{
		cout << "You have selected a right triangle!  What size should your right triangle be (1-20)?" << endl;
		cin >> sizeSelection;

		// Re-promts user for size if they chose inappropriate size
		if (sizeSelection < 1 || sizeSelection > 20)
		{
			cout << "You have not selected an appropriate size, please try again." << endl;
			sizeSelectionInput(2);
			return;
		}
		else drawRightTriangle(sizeSelection);
	}

	// Asks for isoceles triangle size
	else if (shapeType == 3)
	{
		cout << "You have selected a isosceles triangle!  What size should your isosceles triangle be (1-20)?" << endl;
		cin >> sizeSelection;

		// Re-promts user for size if they chose inappropriate size
		if (sizeSelection < 1 || sizeSelection > 20)
		{
			cout << "You have not selected an appropriate size, please try again." << endl;
			sizeSelectionInput(3);
			return;
		}
		else drawIsoscelesTriangle(sizeSelection, true);
	}

	// Asks for hourglass size
	else if (shapeType == 4)
	{
		cout << "You have selected an hourglass!  What size should your hourglass be (1-20)?" << endl;
		cin >> sizeSelection;

		// Re-promts user for size if they chose inappropriate size
		if (sizeSelection < 1 || sizeSelection > 20)
		{
			cout << "You have not selected an appropriate size, please try again." << endl;
			sizeSelectionInput(4);
			return;
		}
		else drawHourglass(sizeSelection);
	}

	// Asks for diamond size
	else if (shapeType == 5)
	{
		cout << "You have selected an diamond!  What size should your diamond be (1-20)?" << endl;
		cin >> sizeSelection;

		// Re-promts user for size if they chose inappropriate size
		if (sizeSelection < 1 || sizeSelection > 20)
		{
			cout << "You have not selected an appropriate size, please try again." << endl;
			sizeSelectionInput(5);
			return;
		}
		else drawDiamond(sizeSelection);
	}

	// Closes the application
	else
	{
		cout << "Thank you for using our application!  Good-bye!" << endl;
	}
}

// Draws a square
void drawSquare(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	drawInputBox();
}

// Draws a right triangle
void drawRightTriangle(int size)
{
	for (int i = 1; i < size + 1; i++)
	{
		for (int j = size - i; j < size; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	drawInputBox();
}

// Draws an isoceles triangle
void drawIsoscelesTriangle(int size, bool shouldRestart)
{
	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < (i * 2) - 1; k++)
		{
			cout << "*";
		}
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";
		}
		cout << endl;
	}

	// Determines if input box should be re-drawn
	if(shouldRestart)
		drawInputBox();
}

//Draws an hourglass
void drawHourglass(int size)
{
	// Draws the top half of the hourglass
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < (size * 2) - 1 - (2 * i); k++)
		{
			cout << "*";
		}
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";
		}
		cout << endl;
	}

	// Draws the bottom half of the hourglass
	drawIsoscelesTriangle(size, false);

	drawInputBox();
}

// Draws a diamond
void drawDiamond(int size)
{
	// Draws the top half of the diamond
	drawIsoscelesTriangle(size, false);

	// Draws the bottom half of the diamond
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < (size * 2) - 1 - (2 * i); k++)
		{
			cout << "*";
		}
		for (int j = 0; j < size - i; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
	drawInputBox();
}