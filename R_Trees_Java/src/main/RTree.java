package main;

import java.util.List;

public abstract class RTree {
	protected Rectangle[] mbr;

	/**
	 * Constructor de RTree.
	 * Un RTree posee entre m y M rectángulos. 
	 * La raíz al menos tiene 2 rectángulos.
	 */
	public RTree() {
		this.mbr = new Rectangle[Constants.M];
	}

	/**
	 * Implementación del método buscar.
	 * @param rect Rectángulo a buscar.
	 * @return Todos los rectángulos que intersectan a rect.
	 */
	public List<Rectangle> buscar(Rectangle rect) {
		// TODO Buscar no implementado
		System.out.println("Idea: Buscar en los nodos hojas todos los rectángulos que intersectan *rect*");
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
	}

	/**
	 * Método abstracto de splitting para casos de overflow. Cada subclase debe implementarlo.
	 */
	public abstract void split();

}
