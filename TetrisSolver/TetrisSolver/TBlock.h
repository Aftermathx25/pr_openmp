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

void rotate2dMatrix(boolean(&values)[4][4][4], int(&height)[4], int(&width)[4])
{
	boolean temp[4][4][4];
	fill3dMatrix(temp);

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
		
			  int b = height[0] - 1;
			  int g = width[0] - 1;
			  for (int i = 0; i < height[0]; i++){
				  for (int j = 0; j < width[0]; j++){
					  values[2][i][j] = values[0][b][g];
					  g--;
				  }
				  g = width[0] - 1;
				  b--;
			  }
	
			  int a = height[1] - 1;
			  int l = width[1] - 1;
			  for (int i = 0; i < height[1]; i++){
				  for (int j = 0; j < width[1]; j++){
					  values[3][i][j] = values[1][a][l];
					  l--;
				  }
				  l = width[1] - 1;
				  a--;
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
		
			rotate2dMatrix(values, height, width);
	}
};

class S : public TBlock {
public:
	S(){

		fill3dMatrix(values); 

		height[0] = 2; width[0] = 3; 
		height[1] = width[0]; width[1] = height[0];
		height[2] = height[0]; width[2] = width[0];
		height[3] = height[1]; width[3] = width[1];

		for (int j = 0; j < height[0]; j++){
			for (int k = 0; k < width[0]; k++){
				if ((j == 0 && k == 0) || (j == height[0] - 1 && k == width[0] - 1)){ 
					values[0][j][k] = false; 
				}
				else values[0][j][k] = true;
			}
		}

		rotate2dMatrix(values, height, width);
	}
};

class I : public TBlock {
public:
	I(){

		fill3dMatrix(values);

		height[0] = 4; width[0] = 1;
		height[1] = width[0]; width[1] = height[0];
		height[2] = height[0]; width[2] = width[0];
		height[3] = height[1]; width[3] = width[1];

		for (int j = 0; j < height[0]; j++){
			values[0][j][0] = true;
		}

		rotate2dMatrix(values, height, width);
	}
};

class Z : public TBlock {
public:
	Z(){

		fill3dMatrix(values);

		height[0] = 2; width[0] = 3;
		height[1] = width[0]; width[1] = height[0];
		height[2] = height[0]; width[2] = width[0];
		height[3] = height[1]; width[3] = width[1];

		for (int j = 0; j < height[0]; j++){
			for (int k = 0; k < width[0]; k++){
				if ((j == 0 && k == width[0] - 1) || (j == height[0] - 1 && k == 0)){
					values[0][j][k] = false;
				}
				else values[0][j][k] = true;
			}
		}

		rotate2dMatrix(values, height, width);
	}
};

class O : public TBlock {
public:
	O(){

		fill3dMatrix(values);

		for (int i = 0; i < 4; i++){
			height[i] = 2; width[i] = 2;
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++){
					values[i][j][k] = true;
				}
			}
		}

	}
};

class T : public TBlock {
public:
	T(){
		{

			fill3dMatrix(values);

			height[0] = 2; width[0] = 3;
			height[1] = width[0]; width[1] = height[0];
			height[2] = height[0]; width[2] = width[0];
			height[3] = height[1]; width[3] = width[1];

			for (int j = 0; j < height[0]; j++){
				for (int k = 0; k < width[0]; k++){
					if ((j == 0 && k == width[0] - 1) || (j == 0 && k == 0)){
						values[0][j][k] = false;
					}
					else values[0][j][k] = true;
				}
			}

			rotate2dMatrix(values, height, width);
		}
	}
};

class J : public TBlock {
public:
	J(){

		fill3dMatrix(values); 

		height[0] = 3; width[0] = 2; 
		height[1] = width[0]; width[1] = height[0];
		height[2] = height[0]; width[2] = width[0];
		height[3] = height[1]; width[3] = width[1];

		for (int j = 0; j < height[0]; j++){
			for (int k = 0; k < width[0]; k++){
				if (j != 2){
					if (k == 1) values[0][j][k] = true;
				}
				else if (j == 2) values[0][j][k] = true;
			}
		}

		rotate2dMatrix(values, height, width);
	}
};