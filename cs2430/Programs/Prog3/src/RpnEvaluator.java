/*
Evaluates Fraction RPN expressions using a stack.
In addition, stores the intermediate results in a queue.
When done evaluating, prints out the value of the RPN expression
and a list of intermediate results.
Intermediate results are those numbers which are computed
and pushed back on the stack when an operator is encountered.
@author John Hunter
*/

import java.util.Scanner;
import java.util.StringTokenizer;

public class RpnEvaluator
{
   private final int DEFAULT_SIZE = 100; // Default size for stack and queue
   private String expression; // String to store the expression to print
   private Stack myStack = new Stack(DEFAULT_SIZE); // Stack for fractions
   private Queue interExp = new Queue(DEFAULT_SIZE); // Queue for 
                                                   // intermediate results
   Scanner stdin; // Standard scanner for input

   /*
   run method
   Method to run the evaluator. Evaluator runs while there is not an end 
   of file. If there is an error, this method throws an IOException.
   */
   public void run() throws java.io.IOException
   {
      stdin = new Scanner(System.in);
      int expCount = 0;
      boolean valid;
      while (stdin.hasNext())
      {
         expCount++;
         expression = "";
         valid = processExpression();
         printExpression(expCount, valid);
         myStack.clean();
         interExp.clean();
      }
      System.out.println("Normal Termination of Program 3.");
   }

   /*
   addFracToStack method
   Method to add a fraction to the stack. Takes a string of the fraction to 
   add as a parameter.
   @param fracToAdd  fraction to add to stack in string form
   */
   private void addFracToStack(String fracToAdd)
   {
      StringTokenizer str = new StringTokenizer(fracToAdd, "(");
      StringTokenizer str2 = new StringTokenizer(str.nextToken(), ")");
      Fraction newFrac = new Fraction(str2.nextToken());
      newFrac.reduce();
      expression += "(" + newFrac.toString() + ")";
      myStack.push(newFrac);
   }

   /*
   processOperator method
   Method to process an operator. Takes a string of an operator as a parameter
   and returns a boolean value of if the operation succeeded or not.
   @param oper operator in string value to use
   @return boolean   of if the operation succeeded or not
   */
   private boolean processOperator(String oper)
   {
      boolean error = false;
      Fraction exp1, exp2;
      if (!myStack.isEmpty())
      {
         exp2 = (Fraction) myStack.pop();
         if (!myStack.isEmpty())
         {
            exp1 = (Fraction) myStack.pop();
            useOperator(oper, exp1, exp2);
         }
         else
            error = true;
      }
      else
         error = true;
      return error;
   }

   /*
   printInterResults method
   Method to print the intermediate results from the queue. Returns the 
   intermediate results as a string.
   @return intermediate results  in string form
   */
   private String printInterResults()
   {
      String temp = "";
      Fraction tempFrac;
      while (!interExp.isEmpty())
      {
         tempFrac = (Fraction)interExp.remove();
         temp += "(" + tempFrac.toString() + ")";
      }
      return temp;
   }

   /*
   useOperator method
   Method to use an operator. Takes the operator as a string and the two 
   operands as fractions to use.
   @param oper operator to use
   @param operand1   first operand
   @param operand2   second operand
   */
   private void useOperator(String oper, Fraction operand1, Fraction operand2)
   {
      Fraction temp = new Fraction();
      if (oper.equals("+"))
         temp = operand1.plus(operand2);
      else if (oper.equals("-"))
         temp = operand1.minus(operand2);
      else if (oper.equals("*"))
         temp = operand1.times(operand2);
      interExp.add(temp);
      myStack.push(temp);
   }
   
   /*
   processExpression method
   Method to process an expression. Reads expressions from standard input and 
   returns if the expression is valid or not.
   @return boolean   if the expression is valid or not
   */
   private boolean processExpression()
   {
      boolean valid = true;
      String temp;
      temp = stdin.next();
      while (!temp.equals("#") && valid)
      {
         if (temp.charAt(0) == '(' && temp.charAt(temp.length() - 1) == ')')
            addFracToStack(temp);
         else if (temp.equals("+") || temp.equals("-") || temp.equals("*"))
         {
            valid = !processOperator(temp);
            expression += temp;
         }
         else
         {
            valid = false;
            expression += temp;
         }
         if (valid)
            temp = stdin.next();
         else
            stdin.nextLine();
      }
      if (expression.equalsIgnoreCase(""))
         valid = false;
      return valid;
   }
   
   /*
   printExpression method
   Method to print an expression. Takes the expression count and if the 
   expression is valid or not as parameters the prints the expression.
   @param expCount   current expression number
   @param valid   if the expression is valid or not.
   */
   private void printExpression(int expCount, boolean valid)
   {
      Fraction result;
      System.out.println("Expression " + expCount + " is: " + expression);
         if (valid)
            if (!myStack.isEmpty())
            {
               result = (Fraction)myStack.pop();
               if (myStack.isEmpty())
                  System.out.println("The value is: (" + result.toString() 
                        + ")");
               else
                  valid = false;
            }
         if (!valid)
            System.out.println("Invalid Expression");
         System.out.println("Intermediate results: " + printInterResults());
   }
} // class RpnEvaluator