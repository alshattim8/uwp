-- ---------------------------------------------
-- Name       : John W Hunter
-- UserName   : hunterj@eddb
-- Date       : 04-27-15
-- Course     : CS 3630
-- Description: Assignment 9
-- ---------------------------------------------

-- Set columns
prompt Setting columns...
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

pause

-- Query 1
prompt 1.   List all rooms (all details) of hotel Glasgow, sorted by 
prompt      hotel number and then price. 
select * 
from Room
where Hotel_No in (
   select Hotel_No
   from Hotel
   where Name = 'Glasgow')
order by Hotel_No, Price;

pause

-- Query 2
prompt 2.   List all double or family rooms (all details) of hotel 
prompt      Glasgow with a price below 50 per night sorted in ascending
prompt      order of price. 
select *
from Room
where Hotel_No in (
   select Hotel_No
   from Hotel
   where Name = 'Glasgow')
and RType in ('Double', 'Family')
and Price < 50
order by price asc;

pause

-- Query 3 
prompt 3.   For each hotel that has at least 6 bookings, list the hotel
prompt      name, hotel number and the number of bookings, sorted by 
prompt      the number of bookings in ascending order.
select H.Name, H.Hotel_No, count(B.Guest_no) "Number of Bookings"
from Hotel H
left join Booking B
on H.Hotel_No = B.Hotel_No
group by H.Hotel_No, Name
having count(B.Guest_no) >= 6
order by count(B.Guest_no) asc;

pause

-- Query 4
prompt 4.   For each hotel, list the hotel name, hotel number and the
prompt      number of bookings during the current month of the current 
prompt      year. A zero should be displayed for hotels that do not 
prompt      have any bookings during the current month, and the query 
prompt      should work for any month of any year. 
select H.Name, H.Hotel_No, count(B.Guest_no) "Number of Bookings"
from Hotel H
left join Booking B
on H.Hotel_No = B.Hotel_No
and (To_Char(Date_From, 'yyyy') <= To_Char(sysDate, 'yyyy')
and  To_Char(Date_To, 'yyyy') >= To_Char(sysDate, 'yyyy'))
and (To_Char(Date_From, 'mm') <= To_Char(sysDate, 'mm')
and  To_Char(Date_To, 'mm') >= To_Char(sysDate, 'mm'))
group by H.Hotel_No, Name;

pause

-- Query 5
prompt 5.   List all guests (all details) currently staying at hotel 
prompt      Grosvenor in London, sorted on Guest_no. The query should 
prompt      work for any day. 
select *
from Guest 
where Guest_No in (
   select guest_no
   from booking
   where sysDate <= Date_To
   and sysDate >= Date_From
   and Hotel_No in(
      select Hotel_No
      from Hotel
      where Name = 'Grosvenor'
      and Address = 'London'))
order by Guest_No;

pause

-- Query 6
prompt 6.   For each hotel that does not have any bookings, display the 
prompt      hotel details, sorted on Hotel_No.
select *
from hotel
where hotel_no not in (
   select hotel_no
   from booking
   group by hotel_no)
order by hotel_no;

pause

-- Query 7
prompt 7.   List the rooms (all details) that are currently unoccupied 
prompt      at hotel Grosvenor in London. The query should produce 
prompt      correct results today and any day in the future. 
select *
from room
where room_no not in (
   select room_no
   from booking
   where sysDate <= Date_To
   and sysDate >= Date_From)
and hotel_no in (
   select hotel_no
   from hotel
   where name = 'Grosvenor'
   and address = 'London');

pause

-- Query 8
prompt 8.   For each hotel in London, list the hotel number, hotel 
prompt      name, and number of Family rooms with a price below 180. 
prompt      Display a zero for hotels in London that do not have 
prompt      specified rooms. 
select h.hotel_no, h.name, count(r.room_no) "Number of Rooms"
from hotel h
left join room r
on h.hotel_no = r.hotel_no
and r.rtype = 'Family'
and r.price < 180
where h.address = 'London'
group by h.hotel_no, h.name;

pause

-- Query 9
prompt 9.   List the guest number, guest name and the number of 
prompt      bookings for the current year, sorted by guest_no. Display
prompt      a zero for guests who do not have any bookings for the 
prompt      current year. Your query should work for any year. Booking 
prompt      could be longer than one year. 
select g.guest_no, g.guest_name, count(b.guest_no) "Number of Bookings"
from guest g
left join booking b
on g.guest_no = b.guest_no
and (To_Char(Date_From, 'yyyy') <= To_Char(sysDate, 'yyyy')
and  To_Char(Date_To, 'yyyy') >= To_Char(sysDate, 'yyyy'))
group by g.guest_no, g.guest_name;

pause

-- Query 10
-- Unable to complete requested query
prompt 10.  For each hotel that has at least one booking, list the 
prompt      Hotel number, Hotel name, and the most commonly booked room
prompt      type for the hotel (the number of bookings is the largest)
prompt      with the count of bookings for that room type. Notice that
prompt      multiple types may have the same largest number of 
prompt      bookings, and all such types should be listed. 

select h.hotel_no, h.name, r.rtype, count(b.hotel_no) "Count of Bookings"
from hotel h
join room r
on r.hotel_no = h.hotel_no
left join booking b
on b.room_no = r.room_no
group by h.hotel_no, h.name, r.rtype
having count(b.hotel_no) > 0
order by h.hotel_no, count(b.hotel_no) desc;

pause

-- Clear columns
prompt Clearing columns...
clear col

prompt End of Script


