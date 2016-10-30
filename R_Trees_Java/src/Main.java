import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		/**
		 * Prueba 1: Rectángulos en memoria principal.
		 */
		Rectangle header = new Rectangle(1, 2, 3, 4, "header");
		ArrayList<String> aux = new ArrayList<String>();
		
		Rectangle r1 = new Rectangle(1, 2, 3, 4, "r1");
		Rectangle r2 = new Rectangle(1, 2, 3, 4, "r2");
		Rectangle r3 = new Rectangle(1, 2, 3, 4, "r3");
		Rectangle r4 = new Rectangle(1, 2, 3, 4, "r4");
		Rectangle r5 = new Rectangle(1, 2, 3, 4, "r5");
		Rectangle r6 = new Rectangle(1, 2, 3, 4, "r6");
		Rectangle r7 = new Rectangle(1, 2, 3, 4, "r7");
		Rectangle r8 = new Rectangle(-5, -5 ,1 ,1 ,"r8");

		aux.add(r5.id);
		aux.add(r6.id);
		aux.add(r7.id);
		aux.add(r8.id);
		r2.setList(aux);

		aux = new ArrayList<String>();
		aux.add(r3.id);
		aux.add(r4.id);
		r1.setList(aux);

		aux = new ArrayList<String>();
		aux.add(r1.id);
		aux.add(r2.id);
		header.setList(aux);
		try {
			r1.writeToDisk(r1.id);
			r2.writeToDisk(r2.id);
			r3.writeToDisk(r3.id);
			r4.writeToDisk(r4.id);
			r5.writeToDisk(r5.id);
			r6.writeToDisk(r6.id);
			r7.writeToDisk(r7.id);
			r8.writeToDisk(r8.id);
			header.writeToDisk(header.id);
		} catch (IOException e) {
			e.printStackTrace();
		}

		System.out.println(header.buscar(new Rectangle(1, 2, 3, 4, "Buscado")));
		
		/**
		 * Prueba 2: Rectángulos en disco.
		 */
		
		try {
			header.writeToDisk("test.rekt1");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			header = Rectangle.loadFromDisk("test.rekt1");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(header.buscar(new Rectangle(1, 2, 3, 4, "Buscado")));
		System.out.println("Ready xDDdDdDD");

	}

}
