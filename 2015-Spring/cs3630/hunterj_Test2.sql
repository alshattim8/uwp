------------------------------------------------
-- Name    : John Hunter
--
-- UserName: hunterj@eddb
--
-- Date    : May-06-2015
--
-- Course  : CS 3630
--           Test 2 (60 points)
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
col "Total Amount of Payments" format $9,999 
col Payment format $9,999 heading "Payment"
col Average format $9,999.00 heading "Average"
col "Amount of Payments" format $9,999 
col "Largest Payment"  format $9,999 
col "Smallest Payment"  format $9,999 

Prompt
Prompt 1.  List NIN, FirstName, LastName and DOB of all staff whose birth day 
Prompt     is between June 21 1955 and June 26 1965, inclusive, sorted on DOB
Prompt     in ascending order and then on LastName in descending order
Prompt
select nin, firstname, lastname, dob
from allstaff
where to_date('June 21 1955', 'month dd yyyy') <= dob
and to_date('June 26 1965', 'month dd yyyy') >= dob
order by dob asc, lastname desc;


pause
Prompt
Prompt 2.  For each hotel that has made more than three payments, 
Prompt     list the HotelNo, total number of payments by the hotel
Prompt     and the average payment of all payments by the Hotel,
Prompt     sorted by hotel number. 
Prompt     The heading must be "Count" and "Average".
Prompt
select h.hotelno, count(c.payment) "Count", avg(c.payment) "Average"
from allhotels h
join contractpayroll c
on h.hotelno = c.hotelno
group by h.hotelno
having count(c.payment) > 3 
order by hotelno;



pause
prompt
prompt 3.
prompt For each pay roll record in ContractPayRoll, 
prompt list the FirstName, LastName, payDate and payment,
prompt sorted on NIN in descending order,
prompt and then on payDate in ascending order.
prompt PayDate must be in the format Month dd yyyy, 
prompt e.g., May 01 2015 with heading "Pay Date"
select s.firstname, s.lastname, to_char(c.paydate, 'month dd yyyy') "Pay Date" , c.payment
from contractpayroll c
join allstaff s 
on c.nin = s.nin 
order by s.nin desc, c.paydate asc;

pause
Prompt
Prompt 4.  Retrieve NIN, FirstName and LastName of all staff 
Prompt     who have not received any payments in the current 
Prompt     month, sorted by NIN.
prompt     The same query should work at any time.
prompt 
select s.nin, s.firstname, s.lastname
from allstaff s
where s.nin not in (
select c.nin
from contractpayroll c 
where to_char(c.paydate, 'month yyyy') = to_char(sysdate, 'month yyyy')
)
order by nin;


               
pause
Prompt
Prompt 5. For each staff, list FirstName, LastName and the number of 
Prompt    payments the staff has received from all hotels with heading 
Prompt    "Number of Payments", sorted by NIN.
Prompt    For a staff member without payments, a zero should be displayed. 
Prompt
select firstname, lastname, count(payment) "Number of Payments"
from allstaff s 
left join  contractpayroll c
on s.nin = c.nin
group by s.nin, s.firstname, s.lastname
order by s.nin; 


pause 
Prompt
Prompt 6. For each staff who has received payments in the current month, 
Prompt    list FirstName, LastName, total number of payments (with 
Prompt    heding "Number of Payments") and the total amount of payments 
Prompt    (with heading "Amount of Payments") the staff has received 
Prompt    in the current month, sorted by the total amount of payments 
Prompt    then on NIN.
select s.firstname, s.lastname, count(c.payment) "Number of Payments", sum(c.payment) "Amount of Payments"
from allstaff s
join contractpayroll c 
on s.nin = c.nin 
and to_char(c.paydate, 'month yyyy') = to_char(sysdate, 'month yyyy')
group by s.nin, s.firstname, s.lastname
order by count(c.payment), s.nin;





pause 
Prompt
Prompt 7. For each staff who has received at least two payments, 
Prompt    but did not received any payments during the last month, 
Prompt    list FirstName, LastName, the largest payment amount 
Prompt    with heading "Largest Payment" and the smallest payment
Prompt    amount with heading "Smallest Payment" the staff has received.
Prompt
select s.firstname, s.lastname, max(c.payment) "Largest Payment", min(c.payment) "Smallest Payment"
from allstaff s 
join contractpayroll c 
on s.nin = c.nin 
and s.nin not in (
select c.nin
from contractpayroll c 
where to_char(c.paydate, 'month yyyy') = to_char(add_months(sysdate, -1), 'month yyyy')
)
group by s.firstname, s.lastname;



pause 
Prompt
Prompt 8. For each male staff, list FirstName, LastName and the number of payments
Prompt    the staff has received from hotels in Platteville, WI, sorted by NIN.
Prompt    Using heading "Number of Payments" for the count. 
Prompt    For a staff member who has no such payments, a zero should be displayed. 
Prompt
select s.firstname, s.lastname, count(c.payment) "Number of Payments"
from allstaff s 
left join contractpayroll c 
on s.nin = c.nin 
and c.hotelno in (
select hotelno
from hotel
where city = 'Platteville'
and state = 'WI'
)
group by s.nin, s.firstname, s.lastname
order by s.nin;



Prompt 
Prompt Remove column formatting
Prompt 

clear col 
