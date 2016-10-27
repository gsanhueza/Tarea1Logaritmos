package main;

import java.io.Serializable;
import java.util.ArrayList;

public abstract class Rectangle implements Serializable {
	private static final long serialVersionUID = 301762099683018640L;

	private int coord_X;
	private int coord_Y;
	private int width;
	private int height;
	private Rectangle next;

	/**
	 * Constructor de un rectángulo para R-Trees.
	 * @param x Coordenada X del rectángulo.
	 * @param y Coordenada Y del rectángulo.
	 * @param w Ancho del rectángulo.
	 * @param h Alto del rectángulo.
	 */
	public Rectangle(int x, int y, int w, int h, Rectangle next) {
		this.coord_X = x;
		this.coord_Y = y;
		this.width = w;
		this.height = h;
		this.next = next;
	}

	/**
	 * Accesor de la coordenada X.
	 * @return Coordenada X.
	 */
	public int getX() {
		return coord_X;
	}

	/**
	 * Accesor de la coordenada Y.
	 * @return Coordenada Y.
	 */
	public int getY() {
		return coord_Y;
	}

	/**
	 * Accesor del ancho.
	 * @return Ancho del rectángulo.
	 */
	public int getWidth() {
		return width;
	}

	/**
	 * Accesor del alto.
	 * @return Alto del rectángulo.
	 */
	public int getHeight() {
		return height;
	}
	
	/**
	 * Devuelve el siguiente R-Tree.
	 * @return Siguiente R-Tree respecto al rectángulo.
	 */
	public Rectangle getNext() {
		return next;
	}
	
	/**
	 * Busca el rectángulo en el R-Tree
	 * @param rect El rectángulo a buscar.
	 * @return ??
	 */
	public ArrayList<Rectangle> buscar(Rectangle rect) {
		return null;
	}
	
	/**
	 * Inserta el rectángulo en el mbr. Abstracto para implementar distintas versiones.
	 * @param rect Rectángulo a insertar.
	 */
	public abstract void insertar(Rectangle rect);

	public boolean intersect(Rectangle R1){
		return R1.intersect( this.coord_X, this.coord_Y, this.width, this.height );
	}

	protected boolean intersect( int x, int y, int width, int height ){
		return this.coord_X < x + width && this.coord_X + this.width > x && this.coord_Y < y + height && this.coord_Y + this.height > y;
	}

}
