import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;

/**
 * Created by rdelg on 02-11-2016.
 */
public class RectangleTest extends TestCase {

    Rectangle rectangle;
    Rectangle header;
    String[] array;
    @org.junit.Before
    public void setUp() throws Exception {
        rectangle = new Rectangle( 0, 0, 1, 2, "r0" );
        header = Rectangle.loadFromDisk("header");
        array = new String[]{"r1"};
    }

    @org.junit.After
    public void tearDown() throws Exception {

    }

    public void testGetX() throws Exception {
        assertEquals( rectangle.getX(), 0 );
    }

    public void testGetY() throws Exception {
        assertEquals( rectangle.getY(), 0 );
    }

    public void testGetWidth() throws Exception {
        assertEquals( rectangle.getWidth(), 1 );
    }

    public void testGetHeight() throws Exception {
        assertEquals( rectangle.getHeight(), 2 );
    }

    public void testBuscar() throws Exception {
        assertArrayEquals( rectangle.buscar(new Rectangle( -2, -2, 1, 1, "hola")).toArray(), new ArrayList<String>().toArray());
        assertArrayEquals( header.buscar(new Rectangle( 0, 0, 1, 1, "r0")).toArray(), array );
    }



    public void testMergeRectangle() throws Exception {
        Rectangle r1 = new Rectangle(-1,-1,1,2, "r2");
        assertEquals(rectangle.getX(),0);
        rectangle.mergeRectangle(r1);
        assertEquals(rectangle.getX(),-1);
        assertEquals(rectangle.getHeight(),3);
        assertEquals(rectangle.getWidth(), 2);
        rectangle.mergeRectangle(new Rectangle(0,0,1,1,"newId"));
        assertEquals(rectangle.getX(),-1);
        assertEquals(rectangle.getHeight(),3);
        assertEquals(rectangle.getWidth(), 2);

    }

    public void testMBR() throws Exception {

    }

    public void testInsertar() throws Exception {

    }

    public void testWriteToDisk() throws Exception {

    }

    public void testLoadFromDisk() throws Exception {

    }

    public void testIntersect() throws Exception {

    }

    public void testIntersect1() throws Exception {

    }

    public void testSetList() throws Exception {

    }

    public void testAddRectangle() throws Exception {

    }





}