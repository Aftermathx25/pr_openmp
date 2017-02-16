#include <stdio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "TField.h"
#include "TBlock.h"

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));

	TField tetris = TField();


	for (int i = 0; i < tetris.getHeight(); i++) {
		for (int j = 0; j < tetris.getWidth(); j++) {
			if (i>=19) tetris.setValueAt(i, j, 1);
			printf("%d ", tetris.getValueAt(i, j));
		}
		printf("\n");
	}

	printf("\n\n");

	TBlock block = L();


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