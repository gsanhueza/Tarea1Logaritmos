package main;

public class Main {

	public static void main(String[] args) {
		Rectangle r = new Rectangle(1, 2, 3, 4, null);
		RTree linearSplitRTree = new LinearSplitRTree();
		RTree greeneSplitRTree = new GreeneSplitRTree();
		
		// TODO Rellenar los RTrees
		// TODO Testear los RTrees

		linearSplitRTree.insertar(r);
		linearSplitRTree.buscar(r);
		
		greeneSplitRTree.insertar(r);
		greeneSplitRTree.buscar(r);
	}

}
