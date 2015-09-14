import java.awt.*;

/**
The PFigure class represents any figure in the game. 
@author Mr. Scanlan
*/
public abstract class PFigure implements Comparable
{
   protected int x, y;          
   protected int width, height;  
   protected int priority;       
   protected Panel panel;        

   /**
   The constructor creates a new instance of PFigure based on the 
   specifications it is passed.
   @param startX x coordinate of where figure starts
   @param startY y coordinate of where figure starts
   @param _width width of figure
   @param _height length of figure
   @param pr priority of figure
   @param p panel the figure will go into
   */
   public PFigure ( int startX, int startY, int _width, int _height, 
                    int pr, Panel p )
   {
       x = startX;
       y = startY;
       width = _width;
       height = _height;
       priority = pr;
       panel = p;
   }
   
   /**
   Determines which figure is "greater" or has more priority.
   @param o object to be compared
   @return which figure is greater
   */
   @Override
   public int compareTo(Object o)
   {
      if( o instanceof PFigure )
         return priority - ((PFigure)o).priority;
      return Integer.MAX_VALUE;
   }
      
   /**
   Tests to see if a figure has collided with another figure.
   @param p the figure to test for collision
   @return true if collision, false if not
   */
   public boolean collidedWith ( PFigure p )
   {
      if (  p == null )
         return false;

      return ( x + width ) >= p.x && ( p.x + p.width ) >= x &&
             ( y + height ) >= p.y && ( p.y + p.height ) >= y;
   }
   
   // Can be used for moving by keyboard or mouse
   /**
   Moves the figure based on user inputted arrow key presses.
   @param deltaX distance moved left or right
   @param deltaY distance moved up or down
   */
   public void move ( int deltaX, int deltaY )
   {
      x = x + deltaX;
      y = y + deltaY;
   }
   
   /**
   Hides a figure from user's view.
   */
   public void hide()
   {
      Graphics g = panel.getGraphics();
      Color oldColor = g.getColor();
      g.setColor(panel.getBackground() );
      g.fillRect(x, y, width, height);
      g.setColor(oldColor);
   }
   
   /**
   Moves the figure.
   */
   public void move()
   {
   }

   /**
   Draws the figure into the frame.
   */
   abstract public void draw(); 
}