package main;

import java.util.ArrayList;
import java.util.List;

public class NullRectangle extends Rectangle {
	private static final long serialVersionUID = -4747499361482457121L;

	public NullRectangle(int x, int y, int w, int h, String id) {
		this();
	}
	
	public NullRectangle() {
		this.id = "NULL";
	}
	
	@Override
	public List<Rectangle> buscar(Rectangle rect) {
		return new ArrayList<Rectangle>();
	}

	@Override
	public void insertar(Rectangle rect) {
		System.out.println("Error: Agregando en NullRectangle");
	}

}
