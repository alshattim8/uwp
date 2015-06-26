Group Identifier: Group 4, Team Awesome

-----------------------------------------------------------------------
Group Member Names:
-----------------------------------------------------------------------
Scott Schroeder
John Hunter
Nathan Blaubach
Peter Emery

-----------------------------------------------------------------------
System description:
-----------------------------------------------------------------------
This software system is designed to function as a hotel and flight 
reservation beta. 
Users can access flights and rooms by searching via filters, choose 
specific flights/rooms of interest, and reserve selected items. 
Confirmation for reservations is done by showing receipts and an 
itinerary to the user. 
Users are able to cancel orders that have been made in case of mistake 
or scheduling conflicts.
The System reads in a database from a file at start-up and saves the 
database at close to allow for saving of reservations and other changes 
to the database.

-----------------------------------------------------------------------
Build instructions:
-----------------------------------------------------------------------
The \src folder in this directory contains all files needed for building
this system. The project can be built in Visual Studios 2012, as that 
is the only resource used in building the project. It can be loaded 
into Visual Studio by simply opening the solution file in the \src 
directory. To run the main program, make sure that the 'SE333 Project' 
project is selected as the start-up project.

-----------------------------------------------------------------------
Build File Dependancies:
-----------------------------------------------------------------------
The three database files: "FlightDB", "HotelDB", and 
"Reservation DataBase" need to be placed into the project file under
the directory "Project\src\SE333 Project". This provides the database
access for the controllers, and without these files the system would 
fail to have data to load/run off of.

-----------------------------------------------------------------------
Build Assumptions:
-----------------------------------------------------------------------
As noted within the Build File Dependancies, it is assumed that the 
three database files are within the same folder as the controller
objects upon building.

-----------------------------------------------------------------------
Bugs:
-----------------------------------------------------------------------
No known bugs are noteable within the system.

-----------------------------------------------------------------------
Design Deficiencies:
-----------------------------------------------------------------------
1. A better display for the search screen, which would better define
the details of flight objects. This would allow the user to better pick
which flight/flightpath they would prefer to use.

2. A none case sensitive textfield, such that users can avoid issues
that would seem to occur when they have the correct spelling and format
of the input search strings (with the only exception being the case).

3. The use of listboxes to display information was a fairly obvious and
useful choice, however our implementation of synchronization between
multiple listboxes based off of the selected index of a single listbox
causes some slight issues with design fluidity. It would be nice to 
rework the event handler such that the listbox displays display more
effectively as you approach the bottom of each list.

4. Scaling issue within formats on different screens. Within all of the 
computers that are/were used to design and build our system the window 
display scaling will keep the forms uniform and nicely visible. When
run on an out of scale screen, some issue might arise with the form 
displaying way too large, possibly effecting positions of status labels
based on the use of fixed pixel ratios.

-----------------------------------------------------------------------
Generating Test Coverage:
-----------------------------------------------------------------------
To generate the test coverage results follow this procedure for each 
of the 16 test projects. Open "\Project\src\SE333 Project" Solution.
Within visual studio's Solution Explorer panel, select withever test
is desired. Right click the test"X" project and select the option
"Set as StartUp Project". Next click the green Local Windows Debugger  
button to run the test. 

For all tests, the test project has tests for each and every method
written. Because the test project does not throw any assert exceptions,
this represents that all test were passed. For all projects the test
coverage should be 100% and no exceptions should be thrown.



