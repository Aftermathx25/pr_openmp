#pragma once
class TField {
	boolean values[30][10];
	const int height = 30;
	const int width = 10;

public:
	TField(boolean[30][10]);
	TField();
	int getHeight() { return height; }
	int getWidth() { return width; }
	boolean getValueAt(int, int);
	boolean setValueAt(int, int, boolean);
};

TField::TField(boolean fvalues[30][10]) {
	memcpy(values, fvalues, 30 * 10 * sizeof(int));
}

TField::TField() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			values[i][j] = false;
		}
	}
}


boolean TField::getValueAt(int i, int j) {
	if (j < width && j >= 0 && i >= 0 && i < height) {
		return values[i][j];
	}
	else
	{
		return false;
	}
}

boolean TField::setValueAt(int i, int j, boolean value) {
	if (j < width && j >= 0 && i >= 0 && i < height) {
		values[i][j] = value;
		return true;
	}
	else
	{
		return false;
	}
}