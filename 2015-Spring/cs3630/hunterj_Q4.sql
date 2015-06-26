---------------------------------------------------------------------------------
-- Name       : John Hunter
--
-- UserName   : hunterj@eddb
--
-- Course     : CS 3630
--
-- Section    : 1 (09 AM) 
--
-- Description: Quiz 4
--
-- Date       : May 1, 2015
--              Queries using joins and sub-queries
--              Views can be used but not required
---------------------------------------------------------------------------------

prompt
prompt Set column format 
Prompt 

col NIN format a8 heading "Staff No"
col FirstName format a11 heading "First Name"
col LastName format a10 heading "Last Name"
col Name format a15 heading "Hotel Name"
col HotelNo format a8 heading "Hotel No"
col city format a12 heading "City"
col State format a6 heading "State"
col hours format 999 heading "Hours"
col Payment format $9,999 heading "Salary"

prompt
prompt 1.
prompt For each pay roll record in ContractPayRoll, 
prompt list Hotel No, Hotel Name, payDate and payment,
prompt sorted on Hotel No in descending order,
prompt and then on payDate in ascending order.
prompt PayDate must be in the format Month dd yyyy, 
prompt e.g., May 01 2015 with heading "Pay Date"
select h.HotelNo, to_char(payDate, 'Month dd yyy') "Pay Date", c.payment 
from ContractPayRoll c
join AllHotels h
on h.HotelNo = c.HotelNo
order by h.HotelNo desc, c.payDate asc;

pause
prompt
prompt 2.
prompt For each hotel, 
prompt list Hotel No, Hotel Name, and the total number 
prompt of payments in ContractPayRoll by the hotel 
prompt with heading "Total # of Payments", 
prompt sorting on hotel no.
prompt A zero must be displayed if a hotel has no payments at all.
prompt
select h.HotelNo, h.name, Count(c.payment) "Total # of Payments"
from allhotels h
left join ContractPayRoll c
on h.HotelNo = c.HotelNo
group by h.HotelNo, h.Name
order by h.HotelNo;



pause
prompt
prompt 3.
prompt For each staff who received payments
prompt from more than one hotel,
prompt list first name, last name and the number of 
prompt different hotels he/she received payments from
prompt with heading "# Hotels Worked on", 
prompt sorting on NIN.
prompt
select s.nin, s.firstname, s.lastname, count(c.hotelno) "# Hotels Worked on"
from allstaff s
left join contractpayroll c
on s.nin = c.nin
having  count(c.hotelno) > 1
group by s.nin, s.firstname, s.lastname
order by s.nin;



pause
prompt
prompt 4.  For each staff who received payments during the last month, 
prompt     list NIN and last name of the staff, hotel number
prompt     and name of each hotel the staff received payments from, and 
prompt     the total amount of payments the staff received from the hotel with  
prompt     heading "Total Amount of Payments", sorted on NIN and HotelNo.
prompt     The same query should work for any day.
prompt     
select s.nin, s.lastname, c.hotelno, h.name, sum(c.payment) "Total Amount of Payments"
from allStaff s
join contractpayroll c
on s.nin = c.nin
and (To_Char(c.paydate, 'yyyy') = To_Char(sysDate, 'yyyy')
and To_Char(c.paydate, 'mm') = To_Char(sysDate, 'mm'))
join allhotels h
on c.hotelno = h.hotelno
group by s.nin, s.lastname, c.hotelno, h.name
order by nin, hotelno;



pause
prompt
prompt 5.  For each staff who did not receive any payments
prompt     during the last month, list NIN, last name, and 
prompt     the total number of payments the staff has received
prompt     with heading "No. of Payments", sorted by NIN. 
prompt     The same query should work for any day.
prompt 
select s.nin, s.lastname, count(c.payment) "No. of Payments"
from allstaff s
join contractpayroll c
on s.nin = c.nin
and not (To_Char(c.paydate, 'yyyy') = To_Char(sysDate, 'yyyy')
and To_Char(c.paydate, 'mm') = To_Char(sysDate, 'mm'))
group by s.nin, s.lastname
order by nin;




pause
prompt
prompt 6.  For each male staff from Platteville, WI, list NIN,
prompt     first name, last name and the total number of payments the staff
prompt     has received from all hotels with a rating of "*****". 
prompt     A zero should be displayed as the total number of payments for 
prompt     those specified staff without any specified payments.
select s.nin,  s.firstname, s.lastname, count(c.payment)
from contractpayroll c
join allhotels h
on c.hotelno = h.hotelno
and h.rating = '*****'
right join allstaff s
on s.nin = c.nin
and s.gender = 'M'
group by s.nin,  s.firstname, s.lastname;


  
prompt Remove all column formatting
Clear col
