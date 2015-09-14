// Start of DeviceManager.java
import java.util.Scanner;

/**
Manages the list of devices for Program 1. Ways of managing include adding a 
device, deleting a device, outputting the reading of a device, printing all 
devices and their respective data, and updating the data of a device.
@author John Hunter
*/

public class DeviceManager
{
   // Maximum number of devices
   final int MAX_DEVICES = 5;

   // Array of devices
   private Device list[] = new Device[MAX_DEVICES];

   // Number of Devices currently in the list
   // "Valid" Devices are stored in cells 0 - (numDevices - 1)
   private int numDevices = 0;

   Scanner stdin;  // read from stdin

   /*
   Runs DeviceManager.java.
   */
   public void run() throws java.io.IOException
   {
      stdin = new Scanner(System.in);
      String inputCommand;
      inputCommand = stdin.next();
      while (! "Q".equalsIgnoreCase(inputCommand))
      {
         if ("A".equalsIgnoreCase(inputCommand))
            add();
         else if ("D".equalsIgnoreCase(inputCommand))
            delete();
         else if ("O".equalsIgnoreCase(inputCommand))
            output();
         else if ("P".equalsIgnoreCase(inputCommand))
            print();
         else if ("U".equalsIgnoreCase(inputCommand))
            update();
         inputCommand = stdin.next();
      }
      System.out.println("Normal Termination of Program 1");
   }
   
   /*
   Adds a device to the list of devices. If the list is full an error message 
   is printed. If the device is already in the list an error message is 
   printed.
   */
   private void add()
   {
      String name = stdin.next();
      if (find(name) == -1 && numDevices < list.length)
      {
         list[numDevices] = new Device(name, stdin.nextInt(), 
               stdin.nextFloat());
         numDevices++;
         System.out.println(name + " device has been added to the list.");
      }
      else if (find(name) != -1)
         System.out.println( name + " not added. It is already in the list.");
      else if (numDevices >= MAX_DEVICES)
         System.out.println("The list was full. " + name 
               + " not added to the list.");
   }
   
   /*
   Deletes a device from the list. If the device is not in the list, prints an
   error message.
   */
   private void delete()
   {
      String name = stdin.next();
      int pos = find(name);
      if (pos == -1)
         System.out.println(name + " not deleted.  It is not in the list.");
      else
      {
         for (int i = pos; i < list.length - 1; i++)
         {
            list[i] = list[i + 1];         
         }
         numDevices--;
         System.out.println(name + " was deleted from the list.");
      }
   }
   
   /*
   Outputs the reading of a device. If the device is not in the list, an 
   error message is printed.
   */
   private void output()
   {
      String name = stdin.next();
      int pos = find(name);
      if (pos != -1)
         System.out.println( "Device " + list[pos].getName() + " reads " 
               + list[pos].returnReading());
      else
         System.out.println(name + " not outputted.  It is not in the list.");
   }
   
   /*
   Prints out all data of all devices in the list regardless if there are any 
   devices in the list.
   */
   private void print()
   {
      System.out.println("The list of Devices is:");
      for (int i = 0; i < numDevices; i++)
         System.out.println(list[i].toString());
   }
   
   /*
   Updates the reading of a device. If the device is not in the list an error
   message is printed.
   */
   private void update()
   {
      String name = stdin.next();
      int pos = find(name);
      if (pos != -1)
      {
         float reading = stdin.nextFloat();
         list[pos].storeReading(reading);
         System.out.println("Device " + name + " updated with " + reading);
      }
      else
         System.out.println(name + " not updated.  It is not in the list.");
   }
   
   /*
   Finds the index of a device in the list based on the name passed to the 
   function.
   @params name   to be searched for
   @return index of the device, -1 if not found.
   */
   private int find(String name)
   {
      for (int i = 0; i < numDevices; i++)
         if (name.equals(list[i].getName()))
            return i;
      return -1;
   }
} // class DeviceManager