show databases;
create database hospital_management;
use hospital_management;
SET FOREIGN_KEY_CHECKS=1;


CREATE TABLE DEPARTMENT(D_NAME VARCHAR(20) unique, 
D_LOCATION VARCHAR(35), FACILITIES VARCHAR(50),
primary key (D_NAME));

CREATE TABLE ALL_DOCTORS ( DOC_NO VARCHAR(8) unique primary key constraint LIKETHESE CHECK (
DOC_NO LIKE 'DR%' OR DOC_NO LIKE 'DC%'),
DEPARTMENT varchar(20),
CONSTRAINT ADDFRKYDMT FOREIGN KEY (DEPARTMENT)
REFERENCES DEPARTMENT(D_NAME)
);

CREATE TABLE DOC_REG ( DOC_NO VARCHAR(8), D_NAME VARCHAR(25), QUALIFICATION VARCHAR(10), SALARY NUMERIC(6),
EN_TIME DATETIME, EX_TIME DATETIME,  ADDRESS VARCHAR(50), PH_NO VARCHAR(20), DOJ DATETIME,
CONSTRAINT DCRGFRKY foreign key (DOC_NO) REFERENCES ALL_DOCTORS(DOC_NO),
CONSTRAINT DRLIKE CHECK (DOC_NO LIKE 'DR%')
);

CREATE TABLE DOC_ON_CALL( DOC_NO VARCHAR(8), D_NAME VARCHAR(25), QUALIFICATION VARCHAR(10),
FS_PR_CL NUMERIC(5), PYMT_DU NUMERIC(6), ADDRESS VARCHAR(50), PH_NO VARCHAR(20),
 CONSTRAINT DCCLFRKY foreign key (DOC_NO) REFERENCES ALL_DOCTORS(DOC_NO),
 CONSTRAINT DCLIKE CHECK (DOC_NO LIKE 'DC%')
);


CREATE TABLE PAT_ENTRY (PAT_NO VARCHAR(8), PAT_NAME VARCHAR(25), CHKUP_DT DATETIME, PT_AGE NUMERIC(3),
SEX VARCHAR(1), RFRG_CSTNT VARCHAR(25), DIAGNOSIS VARCHAR(50), RFD VARCHAR(1), ADDRESS VARCHAR(50), 
CITY VARCHAR(10),PH_NO VARCHAR(10), DEPARTMENT VARCHAR(20), 
CONSTRAINT PTETDPTNFRKYDPT foreign key (DEPARTMENT) references DEPARTMENT(D_NAME),
CONSTRAINT PTPRKY PRIMARY KEY (PAT_NO),CONSTRAINT PTLIKE CHECK (PAT_NO LIKE 'PT%'),
CONSTRAINT SEX CHECK (SEX IN('M','F')),
CONSTRAINT RFYN CHECK (RFD IN('Y','N'))
);

CREATE TABLE PAT_CHKUP( PAT_NO VARCHAR(8), DOC_NO VARCHAR(8), DIAGNOSIS VARCHAR(50),
STATUS VARCHAR(10), TREATMENT VARCHAR(35),
CONSTRAINT PRCKRFKY foreign key (PAT_NO) REFERENCES PAT_ENTRY(PAT_NO),
CONSTRAINT PTRFDCPRKY foreign key (DOC_NO) REFERENCES ALL_DOCTORS(DOC_NO)
);

CREATE TABLE ROOM_DETAILS(ROOM_NO VARCHAR(6), ROOM_TYPE VARCHAR(1), ROOM_STATUS VARCHAR(1),
RM_DL_CRG NUMERIC(4), OTHER_CRG NUMERIC(5),
CONSTRAINT RMNOPRKY PRIMARY KEY (ROOM_NO),
CONSTRAINT RNLIKE CHECK (ROOM_NO LIKE 'RN%'),
CONSTRAINT WDINGP CHECK (ROOM_TYPE IN ('G','P')),
CONSTRAINT INYN CHECK (ROOM_STATUS IN ('Y','N'))
);

CREATE TABLE PAT_ADMIT( PAT_NO VARCHAR(8), ADV_PYMT NUMERIC(6), MODE_PYMT VARCHAR(5), 
ROOM_NO VARCHAR(6), DEPTNAME VARCHAR(20), ADMTD_ON DATETIME, COND_ON VARCHAR(50), INVSTGTN_DN VARCHAR(20),
TRMT_SDT DATETIME, ATTDNT_NM VARCHAR(20), CONSTRAINT ADVPYMT CHECK(ADV_PYMT>=500),
CONSTRAINT MDPYMT CHECK (MODE_PYMT IN ('CHEQUE','CASH')),
CONSTRAINT PAFRKYDP foreign key (DEPTNAME) REFERENCES DEPARTMENT(D_NAME),
CONSTRAINT PARMNOFRKYOCDT foreign key (ROOM_NO) REFERENCES ROOM_DETAILS(ROOM_NO),
CONSTRAINT PRADRFKYPE foreign key (PAT_NO) REFERENCES PAT_ENTRY(PAT_NO), 
CONSTRAINT PRADPRKY PRIMARY KEY (PAT_NO)
);

CREATE TABLE PAT_DIS( PAT_NO VARCHAR(8), TR_ADVS VARCHAR(50), TR_GVN VARCHAR(50),
MEDICINES VARCHAR(50), PYMT_GV NUMERIC(7), DIS_ON DATETIME,
 CONSTRAINT PADSFRKY foreign key (PAT_NO) REFERENCES PAT_ADMIT(PAT_NO)
);

CREATE TABLE PAT_REG (PAT_NO VARCHAR(8), DATE_VIS DATETIME, PERSON_CONDITION VARCHAR(30),
TREATMENT VARCHAR(50), MEDICINES VARCHAR(50), DOC_NO VARCHAR(8), PAYMT NUMERIC(4),
 CONSTRAINT PAREDCPRKY foreign key (DOC_NO) REFERENCES ALL_DOCTORS(DOC_NO),
 CONSTRAINT PARERFKY foreign key (PAT_NO) REFERENCES PAT_ENTRY(PAT_NO )
);

CREATE TABLE PAT_OPR ( PAT_NO VARCHAR(8), DATE_OPR DATETIME, IN_COND VARCHAR(35), AFOP_COND VARCHAR(35),
TY_OPERATION VARCHAR(40), MEDICINES VARCHAR(5), DOC_NO VARCHAR(8),  OPTH_NO VARCHAR(4), OTHER_SUG VARCHAR(30),
CONSTRAINT PAOPDCPRKY foreign key (DOC_NO) REFERENCES ALL_DOCTORS(DOC_NO),
CONSTRAINT PAOPRFKY foreign key (PAT_NO) REFERENCES PAT_ENTRY(PAT_NO)
);

# inserting values
INSERT INTO DEPARTMENT (D_NAME, D_LOCATION , FACILITIES) 
VALUES('Cardiology', 'FirstFloor', 'GENERAL AND SPECIALIZED SURGERY'),
('hepatology', 'SecondFloor', 'GENERAL AND SPECIALIZED SURGERY');

INSERT INTO ALL_DOCTORS (DOC_NO, DEPARTMENT)
VALUES ('DR001','Cardiology'), ('DR002','hepatology'), ('DC001','Cardiology'), ('DC002','hepatology');

INSERT INTO DOC_REG (DOC_NO, D_NAME, QUALIFICATION, SALARY, EN_TIME, EX_TIME, ADDRESS, PH_NO, DOJ) 
VALUES ('DR001','DR.RAGINI ARAORA','MBBS, MD',25000,'2001-08-01 08:00:00','2001-08-01 09:00:00',
'230-F  MAYUR VIHAR NEW DELHI','2568931', '2000-06-01 08:30:00'),
('DR002','DR.RAGINI ','MBBS, MD',65000, '1997-01-11 09:30:00','1998-08-01 19:10:00', '230-G NEW DELHI',
'2568931', '2000-06-01 08:30:00');

INSERT INTO DOC_ON_CALL (DOC_NO, D_NAME, QUALIFICATION, FS_PR_CL, PYMT_DU, ADDRESS, PH_NO) 
VALUES ('DC001','DR.SUSANTA PRADHAN', 'MBBS, MD', '500','1000', '120F-NOIDA', '2587496'),
('DC002','DR.PRADHAN', 'MBBS, MD', '1000','2000', '120F-NEW DELHI', '5856972');

INSERT INTO PAT_ENTRY(PAT_NO,PAT_NAME,CHKUP_DT,PT_AGE, SEX,RFRG_CSTNT,DIAGNOSIS,RFD,ADDRESS,CITY,PH_NO,DEPARTMENT)
VALUES('PT001', 'MR.ALOK', '2009-2-6 13:25:32', '23', 'M', 'DR.RAGINI ARAORA', 'OPEN HEART SURGERY', 
'Y', '330F-NOIDA', 'NEW DELHI', '7584289', 'Cardiology'),
('PT002', 'MR.KK', '2009-2-6 11:15:30', '23', 'M', 'DR.RAGINI', 'Aster Integrated Liver Care', 
'Y', '130F-NOIDA', 'NEW DELHI', '7584289', 'hepatology');

INSERT INTO PAT_CHKUP (PAT_NO , DOC_NO, DIAGNOSIS, STATUS, TREATMENT)
VALUES('PT001','DR001','CRACK IN ANKLE BONE', 'SERIOUS', 'PLASTER'),
('PT002','DR002','LIVER', 'SERIOUS', 'TRANSPALNTATION');

INSERT INTO PAT_ADMIT (PAT_NO , ADV_PYMT, MODE_PYMT, ROOM_NO, DEPTNAME, ADMTD_ON, COND_ON, INVSTGTN_DN, TRMT_SDT, ATTDNT_NM)
VALUES ('PT001', '150000', 'CASH', 'RN001', 'Cardiology','2009-2-6 14:21:32','SERIOUS',
'LEAKAGE IN HEART', '2009-2-6 23:25:32', 'MR.ALOK'),
('PT002', '10000', 'CASH', 'RN002', 'hepatology','2009-2-6 11:11:20','SERIOUS',
'LIVER', '2009-2-6 13:15:30', 'MR.KK');

INSERT INTO PAT_DIS (PAT_NO, TR_ADVS, TR_GVN, MEDICINES, PYMT_GV, DIS_ON)
VALUES ('PT001','REST FOR 6 MNTHS','OBSERVED FOR WEEK','ANTI ALLERGICS','275000','2009-2-8 13:25:32'),
('PT002','REST FOR 10 MNTHS','OBSERVED FOR WEEK','ANTI ALLERGICS','355000','2009-2-8 13:15:30');

INSERT INTO PAT_REG (PAT_NO, DATE_VIS, PERSON_CONDITION, TREATMENT, MEDICINES, DOC_NO, PAYMT)
VALUES ('PT001', '2009-2-8 13:25:32', 'STABLE', 'CONTINUE THE MEDICINE', 'PAINKILLER', 'DR001','100'),
('PT002', '2009-2-6 13:15:30', 'STABLE', 'CONTINUE THE MEDICINE', '-', 'DR002','101');

INSERT INTO PAT_OPR (PAT_NO, DATE_OPR, IN_COND, AFOP_COND,TY_OPERATION, MEDICINES, DOC_NO,  OPTH_NO, OTHER_SUG) 
VALUES ('PT001','2009-2-6 23:25:32','CONTROLLED','STABLE','OPEN HEART SURGERY',
'ANALR','DR001','10','UNDER OBSERVATION FOR 24 HOURS'),
('PT002','2009-2-6 13:15:30','CONTROLLED','UNSTABLE','Aster Integrated Liver Care',
'Dolo','DR002','7','UNDER OBSERVATION FOR 24 HOURS');

INSERT INTO ROOM_DETAILS (ROOM_NO, ROOM_TYPE, ROOM_STATUS, RM_DL_CRG, OTHER_CRG)
VALUES ('RN001','G','N','500','100'), ('RN002','G','N','1000','2000');



