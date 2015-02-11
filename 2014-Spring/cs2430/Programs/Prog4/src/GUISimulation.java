/**
The GUISimulation class manipulates an instance of Simulation. 
Contains methods to create an AWT form and respond to user interaction.
@author Andre Fugere
*/
public class GUISimulation extends java.awt.Frame
{
   private Simulation mySim;
  
   /**
   Creates new form GUISimulation.
   */
   public GUISimulation()
   {
      mySim = new Simulation();
      initComponents();
   }

   /**
   This method is called from within the constructor to initialize the form.
   */
   // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
   private void initComponents()
   {

      panel1 = new java.awt.Panel();
      label1 = new java.awt.Label();
      label2 = new java.awt.Label();
      label3 = new java.awt.Label();
      Display = new java.awt.Button();
      Arrival = new java.awt.Button();
      Completion = new java.awt.Button();
      numWaiting = new java.awt.TextField();
      incrTime = new java.awt.Button();
      currTime = new java.awt.TextField();
      currCust = new java.awt.TextField();
      label4 = new java.awt.Label();
      label5 = new java.awt.Label();
      label6 = new java.awt.Label();
      averWait = new java.awt.TextField();
      label7 = new java.awt.Label();
      totalWait = new java.awt.TextField();
      notWaited = new java.awt.TextField();
      served = new java.awt.TextField();

      setPreferredSize(new java.awt.Dimension(500, 500));
      addWindowListener(new java.awt.event.WindowAdapter()
      {
         public void windowClosing(java.awt.event.WindowEvent evt)
         {
            exitForm(evt);
         }
      });

      panel1.setLayout(null);

      label1.setText("Current time:");
      panel1.add(label1);
      label1.setBounds(10, 10, 100, 20);

      label2.setText("Current customer:");
      panel1.add(label2);
      label2.setBounds(10, 30, 120, 20);

      label3.setText("People waiting:");
      panel1.add(label3);
      label3.setBounds(10, 50, 90, 20);

      Display.setLabel("Display");
      Display.addMouseListener(new java.awt.event.MouseAdapter()
         {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
               DisplayMouseClicked(evt);
            }
         });
         panel1.add(Display);
         Display.setBounds(10, 160, 57, 24);

         Arrival.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
         Arrival.setLabel("Arrival");
         Arrival.setName(""); // NOI18N
         Arrival.addMouseListener(new java.awt.event.MouseAdapter()
         {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
               ArrivalMouseClicked(evt);
            }
         });
         panel1.add(Arrival);
         Arrival.setBounds(10, 70, 49, 24);

         Completion.setLabel("Completion");
         Completion.addMouseListener(new java.awt.event.MouseAdapter()
         {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
               CompletionMouseClicked(evt);
            }
         });
         panel1.add(Completion);
         Completion.setBounds(10, 100, 80, 24);

         numWaiting.setEditable(false);
         numWaiting.setName("numWait"); // NOI18N
         numWaiting.setText("0");
         panel1.add(numWaiting);
         numWaiting.setBounds(130, 50, 40, 20);

         incrTime.setLabel("Increment Time");
         incrTime.addMouseListener(new java.awt.event.MouseAdapter()
         {
            public void mouseClicked(java.awt.event.MouseEvent evt)
            {
               incrTimeMouseClicked(evt);
            }
         });
         panel1.add(incrTime);
         incrTime.setBounds(10, 130, 102, 24);

         currTime.setEditable(false);
         currTime.setName("CurrTime"); // NOI18N
         currTime.setText("0");
         panel1.add(currTime);
         currTime.setBounds(130, 10, 40, 20);

         currCust.setEditable(false);
         currCust.setName("currCust"); // NOI18N
         currCust.setText("None");
         panel1.add(currCust);
         currCust.setBounds(130, 30, 40, 20);

         label4.setName(""); // NOI18N
         label4.setText("Average wait time:");
         label4.setVisible(false);
         panel1.add(label4);
         label4.setBounds(210, 10, 100, 20);

         label5.setName(""); // NOI18N
         label5.setText("Total wait time:");
         label5.setVisible(false);
         panel1.add(label5);
         label5.setBounds(210, 30, 86, 20);

         label6.setName(""); // NOI18N
         label6.setText("People that did not have to wait:");
         label6.setVisible(false);
         panel1.add(label6);
         label6.setBounds(210, 50, 176, 20);

         averWait.setEditable(false);
         averWait.setName(""); // NOI18N
         averWait.setText("0");
         averWait.setVisible(false);
         panel1.add(averWait);
         averWait.setBounds(390, 10, 40, 20);

         label7.setName(""); // NOI18N
         label7.setText("People served:");
         label7.setVisible(false);
         panel1.add(label7);
         label7.setBounds(210, 70, 90, 20);

         totalWait.setEditable(false);
         totalWait.setName(""); // NOI18N
         totalWait.setText("0");
         totalWait.setVisible(false);
         panel1.add(totalWait);
         totalWait.setBounds(390, 30, 40, 20);

         notWaited.setEditable(false);
         notWaited.setName(""); // NOI18N
         notWaited.setText("0");
         notWaited.setVisible(false);
         panel1.add(notWaited);
         notWaited.setBounds(390, 50, 40, 20);

         served.setEditable(false);
         served.setName(""); // NOI18N
         served.setText("0");
         served.setVisible(false);
         panel1.add(served);
         served.setBounds(390, 70, 40, 20);

         add(panel1, java.awt.BorderLayout.CENTER);

         pack();
      }// </editor-fold>//GEN-END:initComponents

   /**
   Exit the Application
   */
    private void exitForm(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_exitForm
       System.exit(0);
    }//GEN-LAST:event_exitForm
   /**
   This method simulates an arrival when the user clicks on the "Arrival"
   button.
   @param evt the event that happens
   */
   private void ArrivalMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_ArrivalMouseClicked
   {//GEN-HEADEREND:event_ArrivalMouseClicked
      setNotVisibleDisplay();
      boolean arrived = mySim.Arrival();
      if (arrived)
      {
         currCust.setText(mySim.currCustomer().toString());
         numWaiting.setText("" + mySim.currWaiting());
      }
   }//GEN-LAST:event_ArrivalMouseClicked
   /**
   This method handles a time update when the user clicks on the "Increment
   Time" button. Time always incremented by one.
   @param evt the event that happens
   */
   private void incrTimeMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_incrTimeMouseClicked
   {//GEN-HEADEREND:event_incrTimeMouseClicked
      setNotVisibleDisplay();
      mySim.clockUpdate(1);
      currTime.setText("" + mySim.returnTime());
   }//GEN-LAST:event_incrTimeMouseClicked
   /**
   This method handles a completion when the user clicks on the "Completion"
   button. 
   @param evt the event that happens 
   */
   private void CompletionMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_CompletionMouseClicked
   {//GEN-HEADEREND:event_CompletionMouseClicked
      setNotVisibleDisplay();
      mySim.servComplete();
      if (mySim.currWaiting() == 0 && mySim.currCustomer() == null)
      {
         currCust.setText("none");
         numWaiting.setText("" + mySim.currWaiting());
      }
      else
      {
         currCust.setText("" + mySim.currCustomer().toString());
         numWaiting.setText("" + mySim.currWaiting());
      }
   }//GEN-LAST:event_CompletionMouseClicked
   /**
   Method to display the average wait time, total wait time, number of people
   that did not have to wait, and the number of people served.
   @author John Hunter
   @param evt that happened
   */
   private void DisplayMouseClicked(java.awt.event.MouseEvent evt)//GEN-FIRST:event_button4MouseClicked
   {//GEN-HEADEREND:event_button4MouseClicked
      averWait.setText("" + mySim.avgTimeWait());
      totalWait.setText("" + mySim.totalWait());
      notWaited.setText("" + mySim.numPeopleNotWaited());
      served.setText("" + mySim.numServed());
      setVisibleDisplay();
   }//GEN-LAST:event_button4MouseClicked

   /**
   Sets the visibility of the display labels and text fields to true.
   @author John Hunter
   */
   private void setVisibleDisplay()
   {
      label4.setVisible(true);
      label5.setVisible(true);
      label6.setVisible(true);
      label7.setVisible(true);
      averWait.setVisible(true);
      totalWait.setVisible(true);
      notWaited.setVisible(true);
      served.setVisible(true);
   }
   
   /**
   Sets the visibility of the display labels and text fields to false.
   @author John Hunter
   */
   private void setNotVisibleDisplay()
   {
      label4.setVisible(false);
      label5.setVisible(false);
      label6.setVisible(false);
      label7.setVisible(false);
      averWait.setVisible(false);
      totalWait.setVisible(false);
      notWaited.setVisible(false);
      served.setVisible(false);
   }
   
   /**
   Runs the AWT form.
   @param args the command line arguments (unused)
   */
   public static void main(String args[])
   {
      java.awt.EventQueue.invokeLater(new Runnable()
      {
         @Override
         public void run()
         {
            new GUISimulation().setVisible(true);
         }
      });
   }
   // Variables declaration - do not modify//GEN-BEGIN:variables
   private java.awt.Button Arrival;
   private java.awt.Button Completion;
   private java.awt.Button Display;
   private java.awt.TextField averWait;
   private java.awt.TextField currCust;
   private java.awt.TextField currTime;
   private java.awt.Button incrTime;
   private java.awt.Label label1;
   private java.awt.Label label2;
   private java.awt.Label label3;
   private java.awt.Label label4;
   private java.awt.Label label5;
   private java.awt.Label label6;
   private java.awt.Label label7;
   private java.awt.TextField notWaited;
   private java.awt.TextField numWaiting;
   private java.awt.Panel panel1;
   private java.awt.TextField served;
   private java.awt.TextField totalWait;
   // End of variables declaration//GEN-END:variables
} // class GUISimulation