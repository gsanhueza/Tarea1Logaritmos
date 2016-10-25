package main;

public class Main {

	public static void main(String[] args) {
		Rectangle r = new Rectangle(1, 2, 3, 4);
		RTree rtree = new RTree(r);

		System.out.println(r.getX());
		System.out.println(r.getY());
		System.out.println(r.getWidth());
		System.out.println(r.getHeight());
		System.out.println();
		rtree.insertar(r);
		rtree.buscar(r);
		rtree.print();
	}

}
