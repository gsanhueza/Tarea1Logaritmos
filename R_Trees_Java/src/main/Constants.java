package main;

public class Constants {
	
	/**
	 * Tamaño máximo de un nodo de R-Tree. Debe ser del tamaño de una página de disco.
	 */
	public static int M = 4096;

	/**
	 * Tamaño mínimo de un nodo de R-Tree. Para la tarea se asume 40% de M.
	 */
	public static int m = (int) 0.4 * M;
}
