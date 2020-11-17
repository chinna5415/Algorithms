CREATE TABLE PAT_ADMIT( PAT_NO VARCHAR(8), ADV_PYMT NUMERIC(6), MODE_PYMT VARCHAR(5), 
ROOM_NO VARCHAR(6), DEPTNAME VARCHAR(20), ADMTD_ON DATETIME, COND_ON VARCHAR(50), INVSTGTN_DN VARCHAR(20),
TRMT_SDT DATETIME, ATTDNT_NM VARCHAR(20), CONSTRAINT ADVPYMT CHECK(ADV_PYMT>=500),
CONSTRAINT MDPYMT CHECK (MODE_PYMT IN ('CHEQUE','CASH')),
CONSTRAINT PAFRKYDP foreign key (DEPTNAME) REFERENCES DEPARTMENT(D_NAME),
CONSTRAINT PARMNOFRKYOCDT foreign key (ROOM_NO) REFERENCES ROOM_DETAILS(ROOM_NO),
CONSTRAINT PRADRFKYPE foreign key (PAT_NO) REFERENCES PAT_ENTRY(PAT_NO), 
CONSTRAINT PRADPRKY PRIMARY KEY (PAT_NO)
);
