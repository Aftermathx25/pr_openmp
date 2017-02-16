#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "TField.h"
#include "TBlock.h"

using namespace std;

int main(int argc, char* argv[])
{
	srand( time( NULL ) );

	TField tetris = TField();


	for (int i = 0; i < tetris.getHeight(); i++) {
		for (int j = 0; j < tetris.getWidth(); j++) {
			if (i>=19) tetris.setValueAt(i, j, 1);
			printf("%d ", tetris.getValueAt(i, j));
		}
		printf("\n");
	}

	printf("\n\n");


	int number = rand()%6;

	printf("Number is equal to %d\n", number);


	TBlock block;

	switch (number)
	{
	case 0:
		block = L();
		break;
	case 1:
		block = S();
		break;
	case 2:
		block = Z();
		break;
	case 3:
		block = T();
		break;
	case 4:
		block = O();
		break;
	case 5:
		block = I();
		break;
	case 6:
		block = J();
		break;
	}


	for (int i = 0; i < 4; i++){
		for (int j = 0; j < block.getHeight(i); j++){
			for (int k = 0; k < block.getWidth(i); k++){
				printf("%d ", block.getValueAt(i, j, k));
			}
			printf("\n");
		}
		printf("-------\n");
	}

	system("pause");
	return 0;
}