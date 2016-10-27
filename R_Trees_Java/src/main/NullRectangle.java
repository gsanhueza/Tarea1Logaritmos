package main;

public class NullRectangle extends Rectangle {
	private static final long serialVersionUID = -4747499361482457121L;

	public NullRectangle(int x, int y, int w, int h, Rectangle next) {
		this();
	}
	
	public NullRectangle() {}
	
	@Override
	public Rectangle buscar(Rectangle rect) {
		return this;
	}

	@Override
	public void insertar(Rectangle rect) {
		// TODO Auto-generated method stub
		
	}

}
