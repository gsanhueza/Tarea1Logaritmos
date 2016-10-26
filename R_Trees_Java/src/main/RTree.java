package main;

import java.util.ArrayList;
import java.util.List;

public abstract class RTree {
	protected ArrayList<Rectangle> mbr;

	/**
	 * Constructor de RTree.
	 * Un RTree posee entre m y M rectángulos. 
	 * La raíz al menos tiene 2 rectángulos.
	 */
	public RTree() {
		mbr = new ArrayList<Rectangle>();
	}

	/**
	 * Implementación del método buscar.
	 * @param rect Rectángulo a buscar.
	 * @return Todos los rectángulos que intersectan a rect.
	 */
	public List<Rectangle> buscar(Rectangle rect) {
		// TODO Buscar no implementado
		System.out.println("Idea: Buscar en los nodos hojas todos los rectángulos que intersectan *rect*");
		for (Rectangle r : mbr) {
			if (rect.equals(r)) {
				System.out.println("Rectangle found!");
			}
		}
		return null;
	}
	
	/**
	 * Inserta rect en el árbol.
	 * En caso de overflow, cada implementación de "split" se hace cargo.
	 * @param rect
	 */
	public void insertar(Rectangle rect) {
		// TODO Insertar no implementado
		System.out.println("Insertamos la hoja");
		System.out.println("Reestablecemos los invariantes (usando algun split)");
		boolean needsSplit = true;
		if (needsSplit) {
			split();
		}
		
		if (mbr.size() <= Constants.M)
			mbr.add(rect);
	}

	/**
	 * Método abstracto de splitting para casos de overflow. Cada subclase debe implementarlo.
	 */
	public abstract void split();

}
