import java.awt.Graphics;
import java.awt.Image;
import java.awt.Panel;
import java.io.File;
import javax.imageio.ImageIO;

/**
The SmallFigure class draws and controls the movement of
the small figure in the game.
It extends PFigure.
@author John Hunter
@author Andre Fugere
*/
public class SmallFigure extends PFigure
{
   private final int delta = 40;
   private final int movementDircetions = 9;
   private int deltaX;
   private int deltaY;
   private Image img; 
   
   private final int north = 1;
   private final int east = 2;
   private final int south = 3;
   private final int west = 4;
   private final int northEast = 5;
   private final int southEast = 6;
   private final int southWest = 7;
   private final int northWest = 8;
   
   /**
   This constructor makes a new instance of the small figure picture.
   @param pan the panel to be drawn in
   */
   public SmallFigure(Panel pan)
   {
      super(0, 0, 50, 50 , 0, pan);
      this.deltaX = delta;
      this.deltaY = delta;
      try
       {
          File file = new File("050Diglett.png");
          img = ImageIO.read(file);
       }
       catch ( Exception e )
       {
          System.out.println("File Error: " + e);
       }
   }
   
   /**
   The draw method draws the figure into the panel. 
   */
   @Override
   public void draw()
   {
      if( img != null )
      {
         Graphics g = panel.getGraphics();
         g.drawImage( img, x, y, width, height, null );
      }
   }

   /**
   The move method controls the movement of the small enemy through a random
   number generator. 
   */
   @Override
   public void move()
   {
      boolean valid = false;
      int randInt;
      while (!valid)
      {
         randInt = this.generateRandomInt();
         if (randInt >= north && randInt <= west)
            valid = processDirHorVert(randInt);
         else if (randInt <= northEast && randInt <= northWest)
            valid = processDirDiag(randInt);
         
      }
   }
   
   /**
   The generateRandomInt method generates a random integer for the game to 
   use.
   @return the random integer
   */
   private int generateRandomInt()
   {
      return (int)(Math.random() * movementDircetions);   
   }

   /**
   The checkValid method checks to see if the movement done by the small
   figure is a valid movement or not.
   @param randInt the move to be checked
   @return true if valid, false if not
   */
   private boolean checkValid(int randInt)
   {
      if (randInt == 1) // Up
         return y - height >= 0;
      else if (randInt == 2) // Right
         return x + width <= panel.getSize().width;
      else if (randInt == 3) // Down
         return y + height <= panel.getSize().height;
      else if (randInt == 4) // Left
         return x - width >= 0;
      else if (randInt == 5) // NE
         return y - height >= 0 && x + width <= panel.getSize().width;
      else if (randInt == 6) // SE
         return y + height <= panel.getSize().height && x + width <= panel.getSize().width;
      else if (randInt == 7) // SW
         return y + height <= panel.getSize().height && x - width >= 0;
      else if (randInt == 8) // NW
         return y - height >= 0 && x - width >= 0;
      return false;
   }
   
   /**
   Processes the movements for the horizontal and vertical
   @param dir direction of movement
   @return if the movement was executed or not 
   */
   private boolean processDirHorVert(int dir)
   {
      boolean valid = true;
      if (dir == north) // North
      {
         if (checkValid(dir))
         {
            y -= deltaY;
         }
      }
      else if (dir == east) // East
      {
         if (checkValid(dir))
         {
            x += deltaX;
         }
      }
      else if (dir == south) // South
      {
         if (checkValid(dir))
         {
            y += deltaY;
         }
      }
      else if (dir == west) // West
      {
         if (checkValid(dir))
         {
            x -= deltaX;
         }
      }
      else
         valid = false;
      return valid;
   }

   /**
   Processes the diagonal movements.
   @param dir direction of movement
   @return if the movement was executed or not
   */
   private boolean processDirDiag(int dir)
   {
      boolean valid = true;
      if (dir == northEast) // NE
      {
         if (checkValid(dir))
         {
            y -= deltaY;
            x += deltaX;
         }
      }
      else if (dir == southEast) // SE
      {
         if (checkValid(dir))
         {
            y += deltaY;
            x += deltaX;
         }
      }
      else if (dir == southWest) // SW
      {
         if (checkValid(dir))
         {
            y += deltaY;
            x -= deltaX;
         }
      }
      else if (dir == northWest) // NW
      {
         if (checkValid(dir))
         {
            y -= deltaY;
            x -= deltaX;
         }
      }
      else
         valid = false;
      return valid;
   }
}
