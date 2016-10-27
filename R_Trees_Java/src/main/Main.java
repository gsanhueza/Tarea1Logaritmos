package main;

import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {

	public static void main(String[] args) {
		
		Rectangle rect1 = new LinearSplitRectangle(1, 2, 3, 4, new NullRectangle());
		Rectangle rect2 = null;
		
		try {
			rect1.writeToDisk("test.rekt1");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			rect2 = Rectangle.loadFromDisk("test.rekt1");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(rect1.intersect(rect2));
		System.out.println("Ready xDDdDdDD");

	}

}
