/**
Contains data for individual devices along with methods to access 
the private data
@author John Hunter
*/
public class Device
{
   private String name;           // name of the device
   private float readings[];      // array of readings for the device
   private int curIndex;          // index where next reading goes

   /*
   Constructor for the device class.
   @params deviceName   name of the device to add.
   @params numReadings  number of readings for the device.
   @params initValue    inital value of the device reading.
   */
   public Device ( String deviceName, int numReadings, float initValue )
   {
      name = deviceName;
      readings = new float[numReadings];
      curIndex = 0;
      for (int i = 0; i < numReadings; i++)
         readings[i] = initValue;
   }

   /*
   Method to get the name of the device.
   @return name   of the device.
   */
   public String getName()
   {
     return name;
   }

   /*
   Method to represent all the data of a device in string form.
   @return string    that contains all of the data of the device.
   */
   @Override
   public String toString()
   {
      String temp = name + ": " + curIndex;
      for (int i = 0; i < readings.length; i++)
         temp += "," + readings[i];
      return temp;
   }
   
   /*
   Stores a reading to the device. If the list of readings is full, returns to 
   the begining of the list and overwrites the old data.
   */
   public void storeReading(float reading)
   {
      readings[curIndex] = reading;
      if (curIndex == readings.length - 1)
         curIndex = 0;
      else
         curIndex++;
   }
   
   /*
   Returns the reading of the device as the average of all the readings in the 
   readings array. 
   @return average   of all the readings in readings array.
   */
   public float returnReading()
   {
      float average = 0;
      for (int i = 0; i < readings.length; i++)
         average += readings[i];
      average /= readings.length;
      return average;
   }
} // class Device
