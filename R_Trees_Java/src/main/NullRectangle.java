package main;

import java.util.ArrayList;

public class NullRectangle extends Rectangle {
	private static final long serialVersionUID = -4747499361482457121L;

	public NullRectangle(int x, int y, int w, int h, Rectangle next) {
		super(x, y, w, h, next);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public ArrayList<Rectangle> buscar(Rectangle rect) {
		return null;
	}

	@Override
	public void insertar(Rectangle rect) {
		// TODO Auto-generated method stub
		
	}

}
