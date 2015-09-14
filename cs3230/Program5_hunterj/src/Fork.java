/**
 Class that contains methods to manage a fork. A fork and be busy and not busy, 
 and the forks busy status can be toggled to true and false.
 @author John
 */

public class Fork 
{
   private boolean busy;

   /**
   Default constructor
   */
   Fork() 
   {
      busy = false;
   }

   /**
   Method to return if the fork is in use or not
   @return  is busy
   */
   public boolean isBusy() 
   {
      return busy;
   }

   /**
   Method to toggle the current busy status of the fork
   Returns a confirmation if the change was successful or not
   @param newValue  new busy value
   @return  if the change was successful
   */
   public boolean toggleBusy(boolean newValue) 
   {
      if (busy != newValue) 
      {
         busy = newValue;
         return true;
      }
      return false;
   }
}
