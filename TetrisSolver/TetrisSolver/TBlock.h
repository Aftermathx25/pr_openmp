#pragma once

void fill3dMatrix(boolean (&values)[4][4][4])
{
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 4; k++){
				values[i][j][k] = false;
			}
		}
	}
}

void rotate2dMatrix(boolean(&values)[4][4][4], int(&height)[4], int(&width)[4], int rotation)
{
	boolean temp[4][4][4];
	fill3dMatrix(temp);
	switch (rotation)
	{
	case 1:
		{
			  for (int i = 0; i < height[0]; i++){
				  for (int j = 0; j < width[0]; j++){
					  temp[1][j][i] = values[0][i][j];
				  }
			  }
			  int t = height[1] - 1;
			  for (int i = 0; i < height[1]; i++){
				  for (int j = 0; j < width[1]; j++){
					  values[1][i][j] = temp[1][t][j];
				  }
				  t--;
			  }
		}
		break;

	case 2:
		break;

	case 3:
		break;
	}
		
	
}

class TBlock {
public:
	int height[4];
	int width[4];
	//int rotation;
	boolean values[4][4][4]; // [Rotation][Vertical][Horizontal]
	int getHeight(int);
	int getWidth(int);
	//int getRotation(TBlock);
	//boolean setRotation(int);
	boolean getValueAt(int, int, int);
};


int TBlock::getHeight(int v)
{
	if (v >= 0 && v < 4){
		return height[v];
	}
	else return 0;
}

int TBlock::getWidth(int v)
{
	if (v >= 0 && v < 4){
		return width[v];
	}
	else return 0;
}

boolean TBlock::getValueAt(int r, int h, int w){
	if ((r >= 0 && r < 4) && (h >= 0 && h < 4) && (w >= 0 && w < 4))
	{
		return values[r][h][w];
	}
	else return false;
}

class L : public TBlock {
public:
	L(){
		
		fill3dMatrix(values); //Setting initial state
		
		height[0] = 3; width[0] = 2; //Setting initial size for every rotation state
		height[1] = width[0]; width[1] = height[0];
		height[2] = height[0]; width[2] = width[0];
		height[3] = height[1]; width[3] = width[1];
		
			for (int j = 0; j < height[0]; j++){
				for (int k = 0; k < width[0]; k++){
					if (j != 2){
						if (k == 0) values[0][j][k] = true;
					}
					else if (j == 2) values[0][j][k] = true;		
				}
			}
		
			rotate2dMatrix(values, height, width, 1);

	}
};

class S : public TBlock {
public:
	S();
};

class I : public TBlock {
public:
	I();
};

class Z : public TBlock {
public:
	Z();
};

class O : public TBlock {
public:
	O();
};

class T : public TBlock {
public:
	T();
};

class J : public TBlock {
public:
	J();
};