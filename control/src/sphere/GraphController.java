package sphere;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.JApplet;
public class GraphController extends MouseAdapter{
	private Sphere sphere;
	private int endX;	
	private double radius;
	public GraphController(Sphere sphere) {
		this.sphere = sphere;
	}


		/* public void mousePressed(MouseEvent e){
			 int x=e.getX();
			 int y=e.getY();
			 Graphics g=getGraphics();
			
			 g.fillRect(x-100,y-100,200,200); 
			 }*/

	    
	 public void mouseDragged(MouseEvent e) {
		endX = e.getX();
		radius = endX/2;
		sphere.setRadius(radius);
		 
		 //Graphics g ;
	        //JTextField t = (JTextField)e.getSource();
	       // double r = Double.parseDouble(t.getText());
	       // sphere.setRadius(r);
	 }

}
