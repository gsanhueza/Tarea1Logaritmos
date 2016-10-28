package main;

//import java.io.FileNotFoundException;
//import java.io.IOException;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		Rectangle header = new Rectangle(1, 2, 3, 4, "header");
		ArrayList<Rectangle> aux = new ArrayList<Rectangle>();
		
		Rectangle r1 = new Rectangle(1, 2, 3, 4, "r1");
		Rectangle r2 = new Rectangle(1, 2, 3, 4, "r2");
		Rectangle r3 = new Rectangle(1, 2, 3, 4, "r3");
		Rectangle r4 = new Rectangle(1, 2, 3, 4, "r4");
		Rectangle r5 = new Rectangle(1, 2, 3, 4, "r5");
		Rectangle r6 = new Rectangle(1, 2, 3, 4, "r6");
		Rectangle r7 = new Rectangle(1, 2, 3, 4, "r7");
		
		r3.setList(new ArrayList<Rectangle>());
		r4.setList(new ArrayList<Rectangle>());
		r5.setList(new ArrayList<Rectangle>());
		r6.setList(new ArrayList<Rectangle>());
		r7.setList(new ArrayList<Rectangle>());
		
		aux = new ArrayList<Rectangle>();
		aux.add(r5);
		aux.add(r6);
		aux.add(r7);
		r2.setList(aux);
		
		aux = new ArrayList<Rectangle>();
		aux.add(r3);
		aux.add(r4);
		aux.add(new Rectangle());
		r1.setList(aux);
		
		aux = new ArrayList<Rectangle>();
		aux.add(r1);
		aux.add(r2);
		aux.add(new Rectangle());
		header.setList(aux);
		
		System.out.println(header.buscar(new Rectangle(1, 2, 3, 4, "Buscado")));
		
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
