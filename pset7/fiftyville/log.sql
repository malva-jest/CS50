-- Keep a log of any SQL queries you execute as you solve the mystery.
-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.

SELECT description
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
-- – each of their interview transcripts mentions the bakery.

-- SELECT transcript, name
-- FROM interviews
-- WHERE year = 2021 AND month = 7 AND day = 28;
-- DONE ++++ Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          | Ruth
-- DONE ++++ I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 | Eugene
-- DONE ++++ As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. | Raymond
-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SELECT activity, license_plate
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 24;

Remeber: these bitches were leaving the bakery

ELIMINATED -- 0NTHK55 = Kelsey --- straight-up elimating her because she wasn't at ATM
ELIMINATED -- 5P2BI95 = Vanessa --- not her because she didn't make a < 60 sec phone call
ELIMINATED -- L93JTIZ = Iman --- it's NOT Iman -- only withdrew
ELIMINATED -- 6P58WS2 = Barry --- it's not him, didn't withdraw, phone, or buy flight
ELIMINATED -- 322W7JE = Diana --- she withdrew cash and made a phone call but has no ticket booked in her/receiver's name
ELIMINATED -- G412CB7 = Sofia --- did not withdraw cash but made a call from bakery to Jack -- flight in her name?
                              --- she didn't withdraw so it surely can't be her because thief was spotted at ATM.
-- 94KL13X = Bruce --- he did make a < 60 sec phone call but he also withdrew money so it could be him + has an 8am flight
-- 4328GD8 = Luca --- left the bakery but did not MAKE the phone call from the bakery, but received one and has a flight in her name



-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-- SELECT people.name
-- FROM people
-- WHERE license_plate = '5P2BI95' AND license_plate = '94KL13X'
-- AND  license_plate = '6P58WS2' AND license_plate = '4328GD8' AND license_plate = 'G412CB7' AND license_plate = 'L93JTIZ';
SELECT name
FROM people
WHERE license_plate = '0NTHK55';

-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-- SELECT transaction_type, account_number, amount
-- FROM atm_transactions
-- WHERE atm_location = 'Leggett Street'
-- AND year = 2021 AND month = 7 AND day = 28;
Could probably check these accounts at airport purchases or something
-- all withdrawn amounts and associated account_number IDs
-- 28500762 = 48 ----> Luca     -----------> ELIMINATED
-- 28296815 = 20 ----> Kenny    -----------> ELIMINATED
-- 76054385 = 60 ----> Taylor   -----------> ELIMINATED
-- 49610011 = 50 ----> Bruce    ----------->
-- 16153065 = 80 ----> Brooke   -----------> ELIMINATED
-- 25506511 = 20 ----> Iman     -----------> ELIMINATED
-- 81061156 = 30 ----> Benista  -----------> ELIMINATED
-- 26013199 = 35 ----> Diana    -----------> ELIMINATED
SELECT people.name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number = 26013199;
-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

-- Phone calls less than a minute - associated phone number
Remeber: people on the left were at the bakery

SELECT caller
FROM phone_calls
WHERE duration BETWEEN 1 AND 60 AND year = 2021 AND month = 7 AND day = 28;
(130) 555-0289 = Sofia -- spoke to receiver -- (996) 555-8899 = Jack        -----------> ELIMINATED
(499) 555-9472 = Kelsey -- spoke to receiver -- (892) 555-8872 = Larry      -----------> ELIMINATED
(367) 555-5533 = Bruce -- spoke to receiver -- (375) 555-8161 = Robin       -----------> BOOM!
(609) 555-5876 = Kathryn -- spoke to receiver -- (389) 555-5198 = Luca      -----------> ELIMINATED
(499) 555-9472 = Kelsey -- spoke to receiver -- (717) 555-1342 = Melissa    -----------> ELIMINATED
(286) 555-6063 = Taylor -- spoke to receiver -- (676) 555-6554 = James      -----------> ELIMINATED
(770) 555-1861 = Diana -- spoke to receiver -- (725) 555-3243 = Philip      -----------> ELIMINATED
(031) 555-6622 = Carina -- spoke to receiver -- (910) 555-3251 = Jacqueline -----------> ELIMINATED
(826) 555-1652 = Kenny -- spoke to receiver -- (066) 555-9701 = Doris       -----------> ELIMINATED
(338) 555-6650 = Benista -- spoke to receiver -- (704) 555-2131 = Anna      -----------> ELIMINATED
SELECT people.name
FROM people
WHERE phone_number = '(367) 555-5533';
-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

-- earliest flights 29th July 2021 (check IDs)
SELECT hour
FROM flights
WHERE year = 2021 AND month = 7 AND day = 29;
| hour |
+------+
16
12
8
9
15

-- +++ I'M GUESSING THAT "EARLIEST FLIGHT" LITERALLY MEANS 8 am +++
SELECT passengers.passport_number
FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE year = 2021 AND month = 7 AND day = 29 AND hour = 8;

| passport_number for the earliest flight
+-----------------+
| 7214083635 = Doris   ----------->ELIMINATED
| 1695452385 = Sofia   -----------> ELIMINATED
| 1540955065 = Edward  -----------> ELIMINATED
| 1988161715 = Taylor  -----------> ELIMINATED
| 9878712108 = Kenny   -----------> ELIMINATED
| 8294398571 = Kelsey  -----------> ELIMINATED
| 5773159633 = Bruce   ----------->
| 8496433585 = Luca    -----------> ELIMINATED
SELECT people.name
FROM people
WHERE passport_number = 8496433585;

================================
Bruce has a flight_id = 36
    - destination_airport_id = 4
    - LaGuardia Airport | New York City
    - seat = 4A
    - Bruce's accomplice/phone-mate (Robin) doesn't have a passport number -- c'mon!

Luca has flight_ids = 11, 36, 48
    - flight_id = 11
    - destination_airport_id = NONE -- therefore did fly on this day
    - flight_id = 48
    - destination_airport_id = NONE -- therefore did fly on this day
    - flight_id = 36
    - destination_airport_id = 4
    - LaGuardia Airport | New York City
    - seat = 7B
    - Luca's accomplice/phone-mate (Kathryn) isn't even on the fucking 29th flight so how can it be them??


================================

-- Check destination on 29th July 2021 (check IDs)
SELECT flights.destination_airport_id
FROM flights
JOIN airports ON flights.id = airports.id
JOIN passengers ON flights.id = passengers.flight_id
WHERE year = 2021 AND month = 7 AND day = 29 AND passport_number = 5773159633;


SELECT flights.destination_airport_id
FROM flights
JOIN airports ON flights.id = airports.id
JOIN passengers ON flights.id = passengers.flight_id
WHERE passport_number = '5773159633';


SELECT destination_airport_id
FROM flights
WHERE id = 48 AND year = 2021 AND month = 7 AND day = 29;

SELECT airports.full_name, airports.city
FROM airports
WHERE id = 4;

-- Let's check if Luca/Bruce has more than one seat in her name
SELECT flight_id, seat
FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE passport_number = 5773159633 AND year = 2021 AND month = 7 AND day = 29;

-- Let's check if Luca's chat-mate (Kathryn) is on the same flight
-- first let's sift out her details
SELECT passport_number
FROM people
WHERE name = 'Robin';
Kathryn's passport number = 6121106406
Robin doesn't have a fucking passport number, what!?!?