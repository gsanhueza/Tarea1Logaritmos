//import java.io.FileNotFoundException;
//import java.io.IOException;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
	public static int M;
	public static int m;

	public static void main(String[] args) {
		
		Rectangle header = new Rectangle(-2, 0, 8, 4, "header");
		ArrayList<String> aux = new ArrayList<String>();
		
		Rectangle r1 = new Rectangle(0, -2, 4, 6, "r1");
		Rectangle r2 = new Rectangle(4, 0, 4, 4, "r2");
		Rectangle r3 = new Rectangle(1, 3, 2, 1, "r3");
		Rectangle r4 = new Rectangle(4, 0, 1, 3, "r4");
		Rectangle r5 = new Rectangle(6, 0, 1, 2, "r5");
		Rectangle r6 = new Rectangle(6, 3, 2, 1, "r6");
		Rectangle r7 = new Rectangle(4, 3, 3, 1, "r7");
		Rectangle r8 = new Rectangle(-2, 2 ,2 ,1 ,"r8");

		aux.add(r1.id);
		aux.add(r2.id);
		header.setList(aux);
		try {
			r1.writeToDisk(r1.id);
			r2.writeToDisk(r2.id);
			header.writeToDisk(header.id);
		} catch (IOException e) {
			e.printStackTrace();
		}

		header.insertar(r5);
		header.insertar(r6);
		header.insertar(r7);
		header.insertar(r4);

		header.insertar(r3);
		header.insertar(r8);

		try {
			header.writeToDisk(header.id);
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(header.buscar(new Rectangle(0, 0, 1, 1, "Buscado")));
		System.out.println(header.buscar(r1));
		System.out.println(header.buscar(r2));
		/*
		try {
			root.writeToDisk("test.rekt1");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			rect = Rectangle.loadFromDisk("test.rekt1");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(root.buscar(rect));
		System.out.println("Ready xDDdDdDD");
		*/

	}

}
