package main;

public class RTree {
	private Rectangle mbr;

	public RTree(Rectangle r) {
		this.mbr = r;
	}

	public RTree buscar(Rectangle rect) {
		System.out.println("Buscar no implementado");
		return null;
	}
	
	public void insertar(Rectangle r) {
		System.out.println("Insertar no implementado");
	}

	public void linearSplit() {
		System.out.println("Linear no implementado");
	}

	public void greeneSplit() {
		System.out.println("Greene no implementado");
	}

	public void print() {
		System.out.println(mbr.getHeight());
	}

}
