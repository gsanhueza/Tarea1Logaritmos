import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Rectangle implements Serializable {
	private static final long serialVersionUID = 301762099683018640L;

	protected int coord_X;
	protected int coord_Y;
	protected int width;
	protected int height;
	public String id;
	protected final List<String> innerRectangles;

	/**
	 * Constructor de un rectángulo para R-Trees.
	 * @param x Coordenada X del rectángulo.
	 * @param y Coordenada Y del rectángulo.
	 * @param w Ancho del rectángulo.
	 * @param h Alto del rectángulo.
	 */
	public Rectangle(int x, int y, int w, int h, String id) {
		this.coord_X = x;
		this.coord_Y = y;
		this.width = w;
		this.height = h;
		this.id = id;
		this.innerRectangles = new ArrayList<>();
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
	public List<String> getNext() {
		return innerRectangles;
	}
	
	/**
	 * Busca el rectángulo en el R-Tree
	 * @param rect El rectángulo a buscar.
	 * @return El rectángulo encontrado.
	 */
	public List<String> buscar(Rectangle rect) {		 
		List<String> newList= new ArrayList<String>();

		if (this.intersect(rect)){
			if( this.innerRectangles.size() > 0 ){
				for (String rectangle : innerRectangles){
					Rectangle newRect = null;
					try {
						newRect = Rectangle.loadFromDisk(rectangle);
					} catch (FileNotFoundException e) {
						e.printStackTrace();
					} catch (ClassNotFoundException e) {
						e.printStackTrace();
					} catch (IOException e) {
						e.printStackTrace();
					}
					newList.addAll(newRect.buscar(rect));
				}
			}
			else {
				newList.add(this.id);
			}
		}
		
		return newList;
		
	}
	
	/**
	 * Inserta el rectángulo en el mbr. Abstracto para implementar distintas versiones.
	 * @param rect Rectángulo a insertar.
	 */
	public void insertar(Rectangle rect) {
		
	}
	
	/**
	 * Escribe un objeto a disco.
	 * @param fileName Nombre del archivo.
	 * @throws FileNotFoundException No se encuentra el archivo.
	 * @throws IOException No se puede escribir al archivo.
	 */
	public void writeToDisk(String fileName) throws FileNotFoundException, IOException {
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(fileName));
		out.writeObject(this);
		out.flush();
		out.close();
	}
	
	/**
	 * Carga un objeto desde el disco.
	 * @param fileName Nombre del archivo.
	 * @return Rectángulo (R-Tree) cargado.
	 * @throws FileNotFoundException No se encuentra el archivo.
	 * @throws IOException No se puede leer el archivo.
	 * @throws ClassNotFoundException No está la clase buscada.
	 */
	public static Rectangle loadFromDisk(String fileName) throws FileNotFoundException, IOException, ClassNotFoundException {
		ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileName));
		Rectangle r = (Rectangle) in.readObject();
		in.close();
		return r;
	}
	
	/**
	 * Dispatcher de intersección.
	 * @param R1 Rectángulo recibido.
	 * @return Intersección correcta o errónea.
	 */
	public boolean intersect(Rectangle R1){
		return R1.intersect(this.coord_X, this.coord_Y, this.width, this.height);
	}

	/**
	 * Chequea intersección de this con un rectángulo seccionado en sus componentes.
	 * @param x Coordenada X.
	 * @param y Coordenada Y.
	 * @param width Ancho del rectángulo recibido.
	 * @param height Alto del rectángulo recibido.
	 * @return Intersección correcta o errónea.
	 */
	protected boolean intersect( int x, int y, int width, int height ){
		return  this.coord_X <= x + width && this.coord_X + this.width >= x && 
				this.coord_Y <= y + height && this.coord_Y + this.height >= y;
	}

	// FIXME Esto no debería existir
	public void setList(ArrayList<String> aux) {
		this.innerRectangles.addAll(aux);
	}

}
