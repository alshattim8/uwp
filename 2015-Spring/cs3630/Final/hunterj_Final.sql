------------------------------------------------
-- Name    : John W Hunter
--
-- UserName: hunterj@eddb
--
-- Date    : May-14-2015
--
-- Course  : CS 3630
--           Part II of Final Exam (60 points)
--
-- Section : 1 (09 AM)
--         
------------------------------------------------

set pagesize 20

col NIN format a8 heading "Staff No"
col DOB format a12 heading "Birth Day"
col FirstName format a11 heading "First Name"
col LastName format a10 heading "Last Name"
col State format a6 heading "State"
col Name format a15 heading "Hotel Name"
col HotelNo format a8 heading "Hotel No"
col city format a12 heading "City"
col hours format 999 heading "Hours"
col PayDate heading "Pay Date"
col Payment format $9,999 heading "Payment"
col "Amount of Payments" format $9,999 
col "Largest Payment"  format $9,999 
col "Smallest Payment"  format $9,999 
col "Average" format $9,999.00  
col "Total" format $9,999 
col ContractNo format a16 heading "Contract number"


Prompt
Prompt 1.  List NIN, ContractNo, HotelNo and PayDate of all pay roll records
Prompt     between April 1 2014 and March 11 2015, inclusive, sorted on payDate
Prompt     in ascending order and then on NIN in descending order
Prompt
select nin, contractno, hotelno, payDate
from contractpayroll
where to_char(paydate, 'yyyy mm dd') >= '2014 04 01'
and to_char(paydate, 'yyyy mm dd') <= '2015 03 11'
order by paydate asc, nin desc;


pause
Prompt
Prompt 2.  For each staff who has received more than three payments, 
Prompt     list NIN, total number of payments received by the staff
Prompt     and the average payment of all payments received by the staff,
Prompt     sorted by NIN. 
Prompt     The heading must be "# of Payments" and "Average".
Prompt
select nin, count(*) "# of Payments", avg(payment) "Average"
from contractpayroll
group by nin
having count(*) > 3 
order by nin;


pause
prompt
prompt 3.
prompt For each pay roll record in ContractPayRoll, 
prompt list the HotelNo, hotel name, payDate and payment,
prompt sorted on payDate in descending order,
prompt and then on HotelNo in ascending order.
prompt PayDate must be in the format dd Month yyyy, 
prompt e.g., 01 May 2015 with heading "Pay Date"
select c.hotelno, h.name, to_char(c.paydate, 'dd Month yyyy') "Pay Date", c.payment
from contractpayroll c
join allhotels h 
on c.hotelno = h.hotelno 
order by c.paydate desc, c.hotelno asc;


pause
Prompt
Prompt 4.  Retrieve hotel number, name, city and state of all
Prompt     hotels that did not give any payments in the 
Prompt     previous month, sorted by HotelNo.
prompt     The same query should work at any time.
prompt 
select hotelno, name, city, state 
from allhotels 
where hotelno not in (
	select hotelno
	from contractpayroll 
	where to_char(paydate, 'Month') 
		= to_char(add_months(sysdate, -1), 'Month')
)
order by hotelno;

               
pause
Prompt
Prompt 5. For each hotel, list hotel name, city, state and and the number
Prompt    of payments the hotel has given for all staff with heading 
Prompt    "Number of Payments", sorted by HotelNo.
Prompt    For a hotel without any payments, a zero should be displayed. 
Prompt
select h.name, h.city, h.state, count(c.payment) "Number of Payments"
from allhotels h
left join contractpayroll c 
on h.hotelno = c.hotelno 
group by h.hotelno, h.name, h.city, h.state
order by h.hotelno;

pause 
Prompt
Prompt 6. For each hotel that gave any payments in the previous month, 
Prompt    list hotel number, city, state and total number of payments (with 
Prompt    heding "Count") and the total amount of payments 
Prompt    (with heading "Total") the hotel gave
Prompt    in the previous month, sorted by the count
Prompt    then on HotelNo.
select h.hotelno, h.city, h.state, count(c.payment) "Count", sum(c.payment) "Total"
from allhotels h
join contractpayroll c
on h.hotelno = c.hotelno 
and h.hotelno in (
	select hotelno
	from contractpayroll 
	where to_char(paydate, 'Month') 
		= to_char(add_months(sysdate, -1), 'Month')
)
group by h.hotelno, h.city, h.state
order by count(c.payment), h.hotelno;


pause 
Prompt
Prompt 7. For each hotel that has given at least two payments, 
Prompt    but has not given any payments during this month, 
Prompt    list the hotel name, city, state, the average payment amount 
Prompt    with heading "Average" by the hotel, 
Prompt    sorted by hotel number in descending order.
select h.name, h.city, h.state, avg(c.payment) "Average"
from allhotels h
join contractpayroll c 
on h.hotelno = c.hotelno 
and h.hotelno not in (
	select hotelno
	from contractpayroll 
	where to_char(paydate, 'Month') 
		= to_char(sysdate, 'Month')
)
group by h.name, h.city, h.state, h.hotelno
having count(c.payment) >= 2 
order by h.hotelno desc;

pause 
Prompt
Prompt 8. For each hotel in Platteville, WI, 
Prompt       that has given no more than three payments 
Prompt       to male staff who were born before 1965, 
Prompt    list HotelNo, Name and the number of payments 
Prompt    with heading "Count" the hotel has given to
Prompt    male staff who were born before 1965, 
Prompt    sorted by hotel number. 
Prompt    For a hotel that has no such payments, 
Prompt       a zero should be displayed. 
Prompt
select h.hotelno, h.name, count(c.payment) "Count"
from allhotels h 
left join contractpayroll c 
on h.hotelno = c.hotelno 
and h.city = 'Platteville'
and h.state = 'WI'
and c.nin in (
	select c2.nin 
	from contractpayroll c2 
	join allstaff s 
	on c2.nin = s.nin 
	and s.gender = 'M'
	and to_char(s.dob, 'yyyy') < '1965'
	group by c2.nin 
	having count(c2.payment) <= 3 
)
group by h.hotelno, h.name
order by h.hotelno;



Prompt 
Prompt Remove column formatting
Prompt 

clear col 
