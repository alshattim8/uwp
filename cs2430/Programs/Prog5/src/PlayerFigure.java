import java.awt.*;

/**
The PlayerFigure class draws and handles the movement and controls of the
player character. Extends PFigure.
@author John Hunter
@author Andre Fugere
*/
public class PlayerFigure extends PFigure
{ 
   private final int movementDivisor = 2;
   private final int eyeWidth = 6;
   private final int eyeHeight = 12;
   private final int eyeWidth2 = 18;
   /**
   This constructor makes a new instance of the player figure at the center
   of the screen. 
   @param pan the panel to be drawn in
   */
   public PlayerFigure(Panel pan)
   {
      super(335, 135, 50, 50 , 0, pan);
   }
   
   /**
   The draw method draws the player figure into the panel.
   */
   @Override
   public void draw()
   {   
      Graphics g = panel.getGraphics();
      g.setColor(Color.yellow);
      g.fillOval(x, y, width - 1, height - 1);
      g.setColor(Color.black);
      g.fillOval(x + eyeWidth, y + eyeHeight, eyeHeight, eyeHeight);
      g.fillOval(x + width - eyeWidth2, y + eyeHeight, eyeHeight, eyeHeight);
      g.fillOval(x + eyeHeight, y + (height / movementDivisor),
            width / movementDivisor, 
            height / (movementDivisor * movementDivisor));
   }

   /**
   The move method controls the movement of the player figure using the
   arrow keys. 
   @param deltaX the amount of distance left or right
   @param deltaY the amount of distance up or down
   */
   @Override
   public void move ( int deltaX, int deltaY )
   {
      super.move(deltaX, deltaY);
      if ( x < -width / movementDivisor )
         x = panel.getSize().width - width / movementDivisor;
      else if ( (x + width / movementDivisor) > panel.getSize().width )
         x = -width / movementDivisor;
      if ( y < -height / movementDivisor )
         y = panel.getSize().height - height / movementDivisor;
      else if ( (y + height / movementDivisor) > panel.getSize().height )
         y = -height / movementDivisor;
   }
}
