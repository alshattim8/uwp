-- ---------------------------------------------
-- Name       : John W Hunter
-- UserName   : hunterj@eddb
-- Date       : 03-27-15
-- Course     : CS 3630
-- Description: Lab 7
-- ---------------------------------------------

-- Drop tables
Prompt Dropping tables
Drop Table Booking;
Drop Table Guest;
Drop Table Room;
Drop Table Hotel;
Pause

-- Create Tables
Prompt Creating table Hotel
Create Table Hotel (
    Hotel_No Char(3) Primary Key,
    Name Varchar2(15) Not Null,
    Address Varchar2(30) Not Null
    );
desc Hotel;
Pause

Prompt Creating table Room
Create Table Room (
    Room_No Char(4),
    Hotel_No Char(3) References Hotel,
    RType Char(6) DEFAULT 'Double' Not Null Check (RType in ('Single', 'Double', 'Family')), 
    Price number Not Null Check (Price Between 30 and 200),
    Constraint Room_PK
        Primary Key (Hotel_No, Room_No)
    ); 
desc Room;
Pause

Prompt Creating table Guest
Create Table Guest (
    Guest_No Char(6) Primary Key,
    Guest_Name Varchar2(30) Not Null,
    Address Varchar2(40)
    );
desc Guest;
Pause

Prompt Creating table Booking
Create Table Booking (
    Hotel_No Char(3),
    Guest_No Char(6) Not Null References Guest,
    Date_From Date,
    Date_To Date Not Null,
    Room_No Char(4),
    Constraint Booking_PK
        Primary Key (Hotel_No, Room_No, Date_From),
    Constraint Booking_FK
        Foreign Key (Hotel_No, Room_No) References Room (Hotel_No, Room_No)
    );
desc Booking;
Pause

-- Insert records
Prompt Inserting records into Hotel
Insert into Hotel
Values ('H01', 'Grosvenor', 'London');
Insert into Hotel
Values ('H05', 'Glasgow', 'London');
Insert into Hotel
Values ('H07', 'Aberdeen', 'London');
Insert into Hotel
Values ('H12', 'London', 'Glasgow');
Insert into Hotel
Values ('H16', 'Aberdeen', 'Glasgow');
Insert into Hotel
Values ('H24', 'London', 'Aberdeen');
Insert into Hotel
Values ('H28', 'Glasgow', 'Aberdeen');

Pause

Prompt Inserting records into Room
Insert into Room
Values ('R001', 'H01', 'Single', 30);
Insert into Room
Values ('R002', 'H01', 'Single', 100);
Insert into Room
Values ('R103', 'H01', 'Double', 30);
Insert into Room
Values ('R105', 'H01', 'Double', 119);
Insert into Room
Values ('R209', 'H01', 'Family', 150);
Insert into Room
Values ('R219', 'H01', 'Family', 190);
Insert into Room
Values ('R001', 'H05', 'Double', 39);
Insert into Room
Values ('R003', 'H05', 'Single', 40);
Insert into Room
Values ('R103', 'H05', 'Single', 55);
Insert into Room
Values ('R101', 'H05', 'Double', 40);
Insert into Room
Values ('R104', 'H05', 'Double', 105);
Insert into Room
Values ('R105', 'H12', 'Double', 45);
Insert into Room
Values ('R201', 'H12', 'Family', 80);
Insert into Room
Values ('R003', 'H28', 'Family', 49.95);

Pause

Prompt Inserting records into Guest
Insert into Guest
Values ('G01003', 'John White', '6 Lawrence Street, Glasgow');
Insert into Guest
Values ('G01011', 'Mary Tregear', '5 Tarbot Rd, Aberdeen');
Insert into Guest
Values ('G02003', 'Aline Stewart', '64 Fern Dr, London');
Insert into Guest
Values ('G02005', 'Mike Ritchie', '18 Tain St, London, W1H 7DL, England');
Insert into Guest
Values ('G02007', 'Joe Keogh', Null);
Insert into Guest
Values ('G12345', 'CS 3630', 'London');
Insert into Guest
Values ('G02008', 'Scott Summers', 'London, W1H 7DL, England');

Pause

Prompt Inserting records into Booking
Insert into Booking
Values ('H01', 'G01003', '25-Apr-04', '14-May-04', 'R001');
Insert into Booking
Values ('H01', 'G02003', '24-Apr-04', '26-Apr-04', 'R103');
Insert into Booking
Values ('H01', 'G01011', '25-Apr-04', '30-Apr-04', 'R209');
Insert into Booking
Values ('H05', 'G01003', '05-May-05', '14-May-05', 'R003');
Insert into Booking
Values ('H05', 'G02003', '14-Apr-05', '16-Apr-05', 'R101');
Insert into Booking
Values ('H05', 'G01011', '15-Apr-05', '16-Apr-05', 'R003');
Insert into Booking
Values ('H05', 'G02003', '12-Mar-05', '15-May-05', 'R003');
Insert into Booking
Values ('H01', 'G01011', '11-Mar-05', '30-Apr-05', 'R103');
Insert into Booking
Values ('H01', 'G02007', '11-Apr-05', '02-Sep-05', 'R001');
Insert into Booking
Values ('H28', 'G01003', '01-Jan-10', '10-Jan-10', 'R003');
Insert into Booking
Values ('H05', 'G02003', '12-Mar-15', '15-May-15', 'R003');
Insert into Booking
Values ('H01', 'G01011', '11-Mar-15', '30-Apr-15', 'R103');
Insert into Booking
Values ('H01', 'G02007', '11-Apr-15', '02-Sep-15', 'R001');
Insert into Booking
Values ('H01', 'G02007', '11-Jan-15', '22-Jan-15', 'R001');
Insert into Booking
Values ('H01', 'G02003', '11-Dec-12', '22-Jan-16', 'R209');

Pause

-- Select all from tables
Prompt Displaying all records from Hotel 
Select *
From Hotel;
Pause

Prompt Displaying all records from Room
Select *
From Room;
Pause

Prompt Displaying all records from Guest
Select *
From Guest;
Pause

Prompt Displaying all records from Booking
Select *
From Booking;
Pause

-- Commiting changes
Prompt Committing changes...
commit;

-- End Script File
Prompt End of Script