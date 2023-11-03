Compile and run using the terminal commands as below,

1. gcc -c readfile.c
2. gcc -o workerdb workerdb.c readfile.o
3. ./workerdb input.txt


And you will see the terminal menu like this

Employee DB Menu:
----------------------------------
  (1) Print the Database
  (2) Lookup by ID
  (3) Lookup by Last Name
  (4) Add an Employee
  (5) Quit
----------------------------------
Enter your choice: 1

NAME                    SALARY          ID
---------------------------------------------------------------
Cathryn Danner          72000           165417
Matt Meeden             69000           273225
Robert Dufour           91000           471163
Mike Griffin            72000           499959
Daniel McNamee          71000           547935
Peter Olsen             82000           553997
Martine Marshall                99000           633976
Jean Jones              94000           702234
Dana Parrish            87000           784372
Ann Coddington          82000           786785
Melissa Dufour          114000          849387
Dylan Steinberg         84000           485913
Heather James           98000           935460
Russ Vorobiev           109000          970016
---------------------------------------------------------------
 Number of Employees (14)
