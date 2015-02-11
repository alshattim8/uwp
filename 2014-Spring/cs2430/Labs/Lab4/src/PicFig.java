import java.awt.*;
import javax.imageio.*;
import java.io.*;

public class PicFig extends PFig
{
   private int xVel = 20;
   private int yVel = 20;
   private Image img;

   public PicFig(Panel p)
   {
      super(50,  50,  110,  78,  p );
       try
       {
          File file = new File("gof.jpg");
          img = ImageIO.read(file);
       }
       catch ( Exception e )
       {
          System.out.println("Crashing: " + e);
            // Whatever???
       }
   }

   public void move()
   {
      if ( xVel < 0 && x <= 0 ||
           xVel > 0 && x + width >= panel.getSize().width )
         xVel = - xVel;
      if ( yVel < 0 && y <= 0 ||
           yVel > 0 && y + height >= panel.getSize().height )
         yVel = - yVel;
      x = x + xVel;
      y = y + yVel;
   }

   public void draw()
   {
      if( img != null )
      {
         Graphics g = panel.getGraphics();
         g.drawImage( img, x, y, width, height, null );
      }
   }


}
