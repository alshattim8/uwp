------------------------------------------------
-- Name    : Qi Yang
--
-- UserName: YangQ
--
-- Date    : May-06-2015
--         
-- Course  : CS 3630
--           Creating tables and inserting records
------------------------------------------------

Prompt
Prompt Drop tables
Prompt You may get some error messages saying
Prompt "table or view does not exist"
Prompt

Drop table ContractPayRoll;
Drop table AllStaff;
Drop table AllHotels;

pause

Prompt
Prompt Create table AllHotels
prompt

Create table AllHotels(
   HotelNo       Char(5) Primary Key,
   Name          Varchar2(15) not null,
   City          Varchar2(15) not null,
   State         Char(2) not null,
   Rating        VarChar2(5) Check (Rating in ('*', '**', '***', '****', '*****')) not null);

desc AllHotels
pause

Prompt
Prompt Create AllStaff
Prompt

Create table AllStaff(
   NIN           Char(4) Primary Key,
   FirstName     Varchar2(10) not null,
   LastName      Varchar2(10) not null,
   StreetAddress Varchar(15) Not null,
   City          Varchar2(15) not null,
   State         Char(2) not null,
   ZipCode       Char(5),
   DOB           Date,
   Gender        Char Check (Gender in ('M', 'F')) not null);

desc AllStaff
pause

Prompt
Prompt Create table ContractPayRoll
prompt

Create table ContractPayRoll (
   ContractNo Char(3),
   NIN        Char(4) References AllStaff,
   Hours      Number not null,
   Payment    Number not null, 
   HotelNo    Char(5) References AllHotels,
   PayDate    Date Not null,
   Primary key (ContractNo, NIN, PayDate));

desc ContractPayRoll
pause

Prompt
Prompt Insert records to table AllHotels
prompt

insert into AllHotels
values('H1801', 'Country Inn', 'Platteville', 'WI', '***');

insert into AllHotels
values('H1807', 'Mound View Inn', 'Platteville', 'WI', '**');

insert into AllHotels
values('H7908', 'Holiday Inn', 'Madison', 'WI', '*****');

insert into AllHotels
values('H6404', 'Julien', 'Dubuque', 'IA', '****');

insert into AllHotels
values('H1800', 'Super 8', 'Platteville', 'WI', '*');

insert into AllHotels
values('H6407', 'Holiday Inn', 'Dubuque', 'IA', '****');


pause
Prompt
Prompt Insert records to table AllStaff
prompt


insert into AllStaff
values('1135', 'Tom', 'Scanlan', '15 Pioneer Dr', 'Platteville', 'WI', '53818', '21-Jun-1955', 'M');

insert into AllStaff
values('2005', 'Scott', 'Summers', '15 Pioneer Dr', 'Platteville', 'WI', '53818', '26-Jun-65', 'M');

insert into AllStaff
values('1057', 'Joe', 'Clifton', 'Grandview St', 'Platteville', 'WI', '53818', '21-Jun-1955', 'M');

insert into AllStaff
values('1068', 'Lisa', 'Landgraf', '123 Westhill St', 'Dubuque', 'IA', '52001', '04-Dec-1974', 'F');

insert into AllStaff
values('2007', 'Yan', 'Shi', '500 Maple Rd', 'Belmont', 'WI', '53818', Null, 'F');

insert into AllStaff
values('3000', 'Qi', 'Yang', '213 Main St', 'Platteville', 'WI', '53818', '05-May-1949', 'M');
pause


Prompt
Prompt Insert records to table ContractPayRoll
prompt

insert into ContractPayRoll
values('C01', '1135', 25, 500, 'H1801', '11-Mar-2015');

insert into ContractPayRoll
values('C03', '1135', 20, 400, 'H1807', '11-Apr-2015');

insert into ContractPayRoll
values('C01', '1057', 15, 225, 'H1801', '11-Feb-2015');

insert into ContractPayRoll
values('C14', '1135', 40, 800, 'H6404', '11-Apr-2015');

insert into ContractPayRoll
values('C55', '1068', 22, 660, 'H7908', '11-Apr-2015');

insert into ContractPayRoll
values('C55', '1068', 18, 540, 'H7908', '18-Apr-2015');

insert into ContractPayRoll
values('C09', '1135', 39, 780, 'H1801', '04-Apr-2015');

insert into ContractPayRoll
values('C55', '1135', 50, 1000, 'H7908', '25-Apr-2015');

insert into ContractPayRoll
values('C55', '1135', 50, 1000, 'H7908', '01-May-2015');

insert into ContractPayRoll
values('C55', '1135', 30, 600, 'H6407', '03-May-2015');

insert into ContractPayRoll
values('C55', '1135', 25, 500, 'H6407', '05-May-2015');

insert into ContractPayRoll
values('C55', '1068', 18, 540, 'H6407', '05-May-2015');

insert into ContractPayRoll
values('C55', '1057', 18, 540, 'H6407', '01-May-2015');

insert into ContractPayRoll
values('C55', '1135', 25, 500, 'H6407', '05-Mar-2014');

insert into ContractPayRoll
values('C55', '1068', 18, 540, 'H6407', '05-May-2014');

insert into ContractPayRoll
values('C55', '1057', 18, 540, 'H6407', '01-Apr-2014');

insert into ContractPayRoll
values('C55', '3000', 18, 540, 'H6407', '01-May-2015');

insert into ContractPayRoll
values('C50', '3000', 18, 540, 'H6404', '01-May-2010');

commit;

pause

prompt Table AllHotels has 6 records

Select *
From AllHotels;

Pause

prompt Table AllStaff has 6 records

Select *
From AllStaff;

Pause

prompt Table ContractPayRoll has 17 records
set pagesize 20

Select *
From ContractPayRoll;
