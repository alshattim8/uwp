import java.awt.*;

public class StickFig extends PFig
{
   public StickFig(Panel p)
   {
      super(200,  100,  80,  80,  p);
   }
     
   public void move ( int deltaX, int deltaY )
   {
      super.move(deltaX, deltaY);
      if ( x < -width / 2 )
         x = panel.getSize().width - width / 2;
      else if ( (x + width / 2) > panel.getSize().width )
         x = -width / 2;
      if ( y < -height / 2 )
         y = panel.getSize().height - height / 2;
      else if ( (y + height / 2) > panel.getSize().height )
         y = -height / 2;
   }

   public void draw()
   {
      Graphics g = panel.getGraphics();
      g.setColor(Color.blue);
      g.drawOval(x + width / 4 , y + 1, width / 2, height / 2);
      g.setColor(Color.red);
      g.drawLine( x + width / 2, y + height / 2 + 1, x + width / 2, y + 3 * height / 4 );
      g.setColor(Color.green);
      g.drawLine( x + width / 4, y + 5 * height / 8 + 1, x + 3 * width / 4, y + 5 * height / 8 + 1);
      g.setColor(Color.blue);
      g.drawLine( x + width / 2, y + 3 * height / 4, x + width / 4, y + 7 * height / 8 );
      g.drawLine( x + width / 2, y + 3 * height / 4, x + 3 * width / 4, y + 7 * height / 8 );
   }
   
}
