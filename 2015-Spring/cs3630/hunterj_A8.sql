-- ---------------------------------------------
-- Name       : John W Hunter
-- UserName   : hunterj@eddb
-- Date       : 2015-04-08
-- Course     : CS 3630
-- Description: HW 8
-- ---------------------------------------------

Prompt
-- setting column constraints
Prompt Setting column constraints...
col Hotel_No Format a10 Heading 'Hotel No'
col Name Format a15 Heading 'Hotel Name'
col Address Format a30 Heading 'Address'
col Room_No Format a10 Heading 'Room No'
col RType Format a10 Heading 'Room Type'
col Price Format $999.99 
col Guest_No Format a10 Heading 'Guest No'
col Guest_Name Format a15 Heading 'Guest Name'
col Date_From Format a10 Heading 'Date From'
col Date_To Format a10 Heading 'Date To'
col Avg(Price) Format $999.99 Heading 'Average Price'
col Max(Price) Format $999.99 Heading 'Highest Price'
col Min(Price) Format $999.99 Heading 'Lowest Price'
--
pause
-- query 1
Prompt Query # 1
Prompt List the names and addresses of all guests from London (Address 
Prompt contains string "London") sorted by name in ascending order. 
select Guest_Name, Address
from Guest
where Address like '%London%'
order by Guest_Name asc;
--
pause
-- query 2
Prompt Query # 2
Prompt List all guests whose address is missing. 
select *
from Guest
where Address is null;
--
pause
-- query 3
Prompt Query # 3
Prompt List all double or family rooms with a price below 40 per night 
Prompt sorted in ascending order of price. 
select *
from Room
where (RType = 'Double' or RType = 'Family') and Price < 40
order by Price asc;
--
pause
-- query 4
Prompt Query # 4
Prompt For each room type, list the type and the average price, sorted 
Prompt by the average price in descending order. 
select RType, Avg(Price)
from Room
group by RType
order by Avg(Price) desc;
--
pause
-- query 5
Prompt Query # 5
Prompt List the number of different guests who have bookings during 
Prompt April 2005. 
select count(unique Guest_No) "Number of Guests"
from Booking
where Date_To <= '30-Apr-2005' 
   and Date_From >= '1-Apr-2005';
--
pause
-- query 6
Prompt Query # 6
Prompt For each guest who has made at least one booking, list the guest
Prompt number and the total number of bookings the guest has made, 
Prompt sorted by guest number.
select Guest_No, count(*) "Number of Bookings"
from Booking
group by Guest_No
order by Guest_No;
--
pause
-- query 7
Prompt Query # 7
Prompt For each hotel that has at least one booking during April 2005, 
Prompt list the hotel number, the total number of bookings the hotel 
Prompt has for April 2005 and the latest Date_from for such bookings, 
Prompt sorted by the total number of bookings. 
select Hotel_No, count(Date_From) "Number of Bookings", To_Char(Max(Date_From), 'Month dd yyyy') 
   "Latest Date_From"
from Booking
where Date_To <= '30-Apr-2005' 
   and Date_From >= '1-Apr-2005'
group by Hotel_No
order by count(Date_From);

--
pause
-- query 8
Prompt Query # 8
Prompt List all bookings that start in the current month of the current
Prompt year. The query should work for any month of any year without 
Prompt modification. 
select Hotel_No, Guest_No, To_Char(Date_From, 'Month dd yyyy') "Date From", To_Char(Date_To, 'Month dd yyyy') "Date To", Room_No
from Booking
where Date_From <= Last_Day(SysDate)
  and  Date_From >= (SysDate - To_Number(To_Char(SysDate, 'dd')) + 1);
--
pause
-- query 9
Prompt Query # 9
Prompt For each room type of each hotel, list the hotel number, room 
Prompt type, the highest and the lowest room prices for the room type. 
Prompt Sort the result by hotel number and then room type.
select Hotel_No, RType, Max(Price), Min(Price)
from Room
group by Hotel_No, RType
order by Hotel_No, RType;
--
pause
-- query 10
Prompt Query # 10
Prompt For each room type of each hotel, list the hotel number and room
Prompt type with the highest and the lowest room prices, if the highest 
Prompt price is at least 100 or the lowest price is at most 30, sorted 
Prompt by hotel_no and the highest price. 
select Hotel_No, RType, Max(Price), Min(Price)
from room
where (Price >= 100) or (Price <= 30)
group by Hotel_No, RType
order by Hotel_No, RType;
--
pause
-- clearing columns 
Prompt Clearing columns...
Clear Col
--
pause
-- End Script File
Prompt End of Script
Prompt