package main;

public class Rectangle {
	private int coord_X;
	private int coord_Y;
	private int width;
	private int height;

	public Rectangle(int x, int y, int w, int h) {
		this.coord_X = x;
		this.coord_Y = y;
		this.width = w;
		this.height = h;
	}

	public int getX() {
		return coord_X;
	}

	public int getY() {
		return coord_Y;
	}

	public int getWidth() {
		return width;
	}

	public int getHeight() {
		return height;
	}

}
