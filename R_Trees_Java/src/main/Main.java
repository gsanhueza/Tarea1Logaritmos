package main;

public class Main {

	public static void main(String[] args) {
		
		RTree linearSplitRTree = new LinearSplitRTree();
		// RTree greeneSplitRTree = new GreeneSplitRTree();
		
		Rectangle r1 = new Rectangle(1, 2, 3, 4, null);
		Rectangle r2 = new Rectangle(1, 2, 3, 4, null);
		Rectangle r3 = new Rectangle(1, 2, 3, 4, null);
		
		// TODO Rellenar los RTrees
		// TODO Testear los RTrees

		linearSplitRTree.insertar(r1);
		linearSplitRTree.insertar(r2);
		linearSplitRTree.insertar(r3);

		linearSplitRTree.buscar(r1);

	}

}
