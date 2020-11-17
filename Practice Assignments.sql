# Practice Assignment- 1

create database COMPANY;
use COMPANY;
create table EMPLOYEE(
		EMPLOYEE_ID mediumint,
          LAST_NAME varchar(15),
          FIRST_NAME varchar(25),
		JOB_ID mediumint,
          MANAGER_ID mediumint,
          HIRE_DATE date,
          SALARY double(9,2),
          COMMISSION double(9,2));

alter table EMPLOYEE modify LAST_NAME varchar(25);
create table EMPLOYEE1 as select EMPLOYEE_ID, FIRST_NAME, LAST_NAME from EMPLOYEE;
alter table EMPLOYEE1 rename column EMPLOYEE_ID to ID,
				  rename column FIRST_NAME to F_NAME,
				  rename column LAST_NAME to L_NAME;
describe EMPLOYEE1;
rename table EMPLOYEE1 to EMPLOYEE2;	
alter table EMPLOYEE2 drop column L_NAME;
drop table EMPLOYEE2;

# Practice Assignment- 2

create table DEPARTMENT(
		DEPARTMENT_ID smallint,
          LOCATION_ID smallint,
          DNAME varchar(15),
          LOCATION smallint,
		primary key(DEPARTMENT_ID), unique(DNAME));

create table JOB(
		JOB_ID mediumint,
          FUNCTION_ varchar(15),
          primary key(JOB_ID), unique(FUNCTION_));

create table SALARY_GRADE(
		GRADE_ID smallint,
          LOWER_SAL double(9,2),
          UPPER_SAL double(9,2),
          primary key(GRADE_ID));

create table LOCATION(
		LOCATION_ID smallint,
          REGIONAL_GROUP varchar(15),
          primary key(LOCATION_ID));

alter table EMPLOYEE add primary key(EMPLOYEE_ID);
alter table EMPLOYEE add foreign key(JOB_ID) references JOB(JOB_ID) on update cascade;
alter table EMPLOYEE add foreign key(MANAGER_ID) references EMPLOYEE(EMPLOYEE_ID) on update set null;
alter table EMPLOYEE modify FIRST_NAME varchar(25) not null;
alter table EMPLOYEE modify HIRE_DATE date not null;
alter table EMPLOYEE add constraint check(SALARY < 100000);
alter table EMPLOYEE add column DEPARTMENT_ID smallint;
alter table EMPLOYEE add foreign key(DEPARTMENT_ID) references DEPARTMENT(DEPARTMENT_ID) on update cascade;

alter table DEPARTMENT add foreign key(LOCATION_ID) references LOCATION(LOCATION_ID) on update cascade;

alter table SALARY_GRADE add constraint check(UPPER_SAL < 10000000);

show tables;
describe EMPLOYEE;
describe DEPARTMENT;
describe JOB;
describe SALARY_GRADE;
describe LOCATION;

# Practice Assignment- 3

insert into LOCATION (LOCATION_ID, REGIONAL_GROUP) values
	(122, "NEW YORK"),
	(124, "DALLAS"),
	(123, "CHICAGO"),
	(167, "BOSTON");

insert into DEPARTMENT (DEPARTMENT_ID, DNAME, LOCATION) values
	(10, "ACCOUNTING", 122),
	(20, "RESEARCH", 124),
	(30, "SALES", 123),
	(40, "OPERATIONS", 167);

insert into JOB (JOB_ID, FUNCTION_) values
	(667, "CLERK"),
	(668, "STAFF"),
	(669, "ANALYST"),
	(670, "SALESPERSON"),
	(671, "MANAGER"),
	(672, "PRESIDENT");
     
insert into SALARY_GRADE (GRADE_ID, LOWER_SAL, UPPER_SAL) values
	(1, 7000, 12000),
	(2, 12001, 14000),
	(3, 14001, 20000),
	(4, 20001, 30000),
	(5, 30001, 99999);

SET FOREIGN_KEY_CHECKS = 0;
insert into EMPLOYEE (EMPLOYEE_ID, LAST_NAME, FIRST_NAME, JOB_ID, MANAGER_ID, HIRE_DATE, SALARY, COMMISSION, DEPARTMENT_ID) values
     (7499, 'ALLEN', 'KEVIN', 670, 7698, '2001-01-10', 16000, 3000, 30),
	(7369, 'SMITH', 'JOHN', 667, 7902, '2009-02-01', 8000, null, 20),
     (7491, 'ALLEN', 'KEVIN', 670, 7698, '2019-12-01', 16000, 3000, 30),
	(7505, 'DOYLE', 'JEAN', 671, 7839, '2011-04-21', 28500, null, 30),
     (7506, 'DENNIS', 'LYNN', 671, 7839, '2013-02-15', 27500, null, 30), 
	(7507, 'BAKER', 'LESLIE', 671, 7839, '2018-03-01', 22000, null, 40), 
	(7521, 'WARD', 'CYNTHIA', 670, 7698, '2011-09-16', 12500, 5000, 30), 
	(7555, 'PETERS', 'DANIEL', 670, 7505, '2005-01-11', 12500, 3000, 30),
	(7557, 'SHAW', 'KAREN', 670, 7505, '2018-07-11', 12500, 12000, 30),
	(7560, 'DUNCAN', 'SARAH', 670, 7506, '2017-02-16', 12500, null, 30),
	(7564, 'LANGE', 'GREGORY', 670, 7506, '2018-02-15', 12500, 3000, 30),
     (7566, 'JONES', 'TERRY', 671, 7839, '2019-03-01', 29750, null, 20),
	(7569, 'ALBERTS', 'CHRIS', 671, 7839, '2012-08-03', 30000, null, 20),
	(7600, 'PORTER','RAYMOND', 670, 7505, '2009-12-29', 12500, 9000, 30),
	(7609, 'LEWIS','RICHARD',668,7507, '2016-10-18',18000,null,40),
	(7654, 'MARTIN','KENNETH',670,7698, '2015-01-12',12500,14000,30),
     (7676, 'SOMMERS', 'DENISE', 668, 7507, '2012-08-10', 18500, null, 40),
     (7698, 'BLAKE', 'MARION', 671, 7839, '2018-06-15', 28500, null, 30),
     (7799, 'FISHER','MATTHEW',669,7569, '2017-02-10',30000,null,20),
	(7820, 'ROSS','PAUL',669,7505, '2018-04-15',13000,800,30),
	(7839, 'KING','FRANCIS', 672, null, '2019-07-01', 50000, null, 10),
     (7844, 'TURNER', 'MARY', 670, 7698, '2012-09-03', 15000, 0, 30),
     (7876, 'ADAMS', 'DIANE', 667, 7788, '2009-11-29', 11000, null, 20),
	(7900, 'JAMES', 'FRED', 667, 7698, '2016-02-18', 9500, null, 30),
	(7902, 'FORD', 'JENNIFER', 669, 7566, '2015-07-12', 30000, null, 20), 
	(7916, 'ROBERTS', 'GRACE', 669, 7569, '2012-09-10', 28750, null, 20), 
	(7919, 'DOUGLAS', 'MICHAEL', 667, 7799, '2018-11-11', 8000, null, 20), 
	(7934, 'MILLER', 'BARBARA', 667, 7782, '2015-02-16', 13000, null, 10), 
	(7950, 'JENSEN', 'ALICE', 667, 7505, '2013-02-15', 7500, null, 30), 
	(7954, 'MURRAY', 'JAMES', 667, 7506, '2016-03-01', 7500, null, 30),
	(7361, 'SMITH', 'JOHN', 667, 7902, '2017-08-03', 8000, null, 20);
SET FOREIGN_KEY_CHECKS = 1;

table EMPLOYEE;
table DEPARTMENT;
table JOB;
table SALARY_GRADE;
table LOCATION;

create table NEW_EMPLOYEE like EMPLOYEE;
update EMPLOYEE set SALARY = SALARY*1.01;
delete from EMPLOYEE where LAST_NAME = 'SMITH'; #...
update EMPLOYEE set SALARY = 10000 where SALARY < 9000;
truncate table EMPLOYEE;

# Practice Assignment- 4

select * from DEPARTMENT;
select EMPLOYEE_ID, FIRST_NAME, LAST_NAME, JOB_ID, HIRE_DATE, SALARY from EMPLOYEE;
select distinct JOB_ID from EMPLOYEE;
select FIRST_NAME, LAST_NAME, SALARY from EMPLOYEE where(SALARY > 12850);
select FIRST_NAME DEPARTMENT_ID from EMPLOYEE where(EMPLOYEE_ID = 7566);
select FIRST_NAME, SALARY from EMPLOYEE where(SALARY not between 15000 and 20000);
select FIRST_NAME, JOB_ID, HIRE_DATE from EMPLOYEE where(HIRE_DATE between '2010-02-20' and '2012-05-01') order by HIRE_DATE;
select FIRST_NAME, DEPARTMENT_ID from EMPLOYEE where(DEPARTMENT_ID in (10,30)) order by FIRST_NAME;
select FIRST_NAME, SALARY from EMPLOYEE where(SALARY > 20000 and DEPARTMENT_ID in (10,30));
select FIRST_NAME, HIRE_DATE from EMPLOYEE where year(HIRE_DATE) like '2018';
select FIRST_NAME, JOB_ID from EMPLOYEE where MANAGER_ID is null;
select FIRST_NAME, SALARY, COMMISSION from EMPLOYEE where (COMMISSION is not null and COMMISSION <> 0) order by SALARY desc, COMMISSION desc;
select FIRST_NAME from EMPLOYEE where FIRST_NAME like '__a%';
select FIRST_NAME, LAST_NAME from EMPLOYEE where (LAST_NAME like '%L%L%' and DEPARTMENT_ID = 30) OR MANAGER_ID=7689;
select FIRST_NAME, DEPARTMENT_ID, SALARY from EMPLOYEE where JOB_ID in (670,671) and SALARY not in (10000, 30000, 50000);
select FIRST_NAME, LAST_NAME, HIRE_DATE, SALARY from EMPLOYEE order by HIRE_DATE limit 1;
select FIRST_NAME, SALARY from EMPLOYEE order by SALARY desc limit 3;

#drop database COMPANY;
