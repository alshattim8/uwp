import java.awt.*;

public abstract class PFig
{
   protected int x, y;           // Current position of the figure
   protected int width, height;  // Drawn or displayed this size
   protected Panel panel;        // Panel the figure lives on

   public PFig ( int startX, int startY, int _width, int _height, Panel p )
   {
       x = startX;
       y = startY;
       width = _width;
       height = _height;
       panel = p;
   }
   
   public boolean collidedWith ( PFig p )
   {
      if (  p == null )
         return false;

      return ( x + width ) >= p.x && ( p.x + p.width ) >= x &&
             ( y + height ) >= p.y && ( p.y + p.height ) >= y;
   }
   
   public void move ( int deltaX, int deltaY )
   {
      x = x + deltaX;
      y = y + deltaY;
   }
   
   public void move()
   {
   }

   // Draw the figure.
   abstract public void draw();
   
   public void hide()
   {
      Graphics g = panel.getGraphics();
      Color oldColor = g.getColor();
      g.setColor(panel.getBackground() );
      g.fillRect(x, y, width, height);
      g.setColor(oldColor);
   }


}