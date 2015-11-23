package sphere;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;
public class SphereMain extends JFrame {
	  public SphereMain() {
	        super("mvc��ʾ����");
	        setSize(400,200);
	        Sphere sphere=new Sphere(50);//����ģ�Ͷ���
	        TextView textView=new TextView();//�����ı���ͼ
	        GraphicsView graphicsView=new GraphicsView();//����ͼ����ͼ
	        //��Ӽ�����
	        textView.getTextField().addActionListener(new TextController(sphere));
	        //ģ������ͼ����
	        graphicsView.addMouseMotionListener(new GraphController(sphere));
	        sphere.addObserver(textView);
	        sphere.addObserver(graphicsView);
	        //����������
	        Container c=getContentPane();
	        c.setLayout(new GridLayout(1,2));
	        c.add(textView);
	        c.add(graphicsView);
	        textView.update(sphere, null);
	        graphicsView.update(sphere,null);
	    }
	    
	    /**
	     * @param args the command line arguments
	     */
	    public static void main(String[] args) {
	        // TODO code application logic here
	        new SphereMain().show();
	    }
	    
}
