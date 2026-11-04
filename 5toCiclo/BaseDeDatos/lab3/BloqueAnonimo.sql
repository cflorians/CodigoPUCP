SET SERVEROUTPUT ON;

-- Practica
DECLARE
    vNombres    VARCHAR2(50)    := 'Luis';
    vApePaterno VARCHAR2(50)    := 'Quispe';
    vApeMaterno VARCHAR2(50)    := 'Rojas';
    vPlan       VARCHAR2(50)    := 'Trimestral';
    vDias       NUMBER          := 90;
    cDescuento  CONSTANT NUMBER(3,2)     := 0.10;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Socio: ' || vNombres || ' ' || vApePaterno || ' ' || vApeMaterno);
    DBMS_OUTPUT.PUT_LINE('Plan: ' || vPlan || ' (' || vDias || ' días)' || ' | ' || 'Descuento: ' || TO_CHAR(cDescuento, 'FM0.0'));
END;
/

-- A
DECLARE
    vPLAN       VARCHAR2(50)    := 'Anual';
    vPRECIO     NUMBER          := 1200;
    cIGV        CONSTANT NUMBER := 0.18;
    vIGV        NUMBER;
    vTOTAL      NUMBER;
BEGIN
    vIGV    :=  vPRECIO * cIGV;
    vTOTAL  :=  vPRECIO + vIGV;
    
    DBMS_OUTPUT.PUT_LINE('Plan ' || vPLAN);
    DBMS_OUTPUT.PUT_LINE('Precio base: S/' || TO_CHAR(vPRECIO, 'FM99990.00') 
                         || ' | IGV: S/' || TO_CHAR(vIGV, 'FM9990.00') 
                         || ' | Total: S/' || TO_CHAR(vTOTAL, 'FM99990.00'));
END;
/

-- B
DECLARE
    vFECHAFIN   DATE        := TO_DATE('20/12/2026','DD/MM/YYYY');
    vDIASCONGELADOS NUMBER  := 12;
    vNUEVAFECHA DATE;
BEGIN
    vNUEVAFECHA := vFECHAFIN + vDIASCONGELADOS;
    
    DBMS_OUTPUT.PUT_LINE('Fecha de fin original: ' || TO_CHAR(vFECHAFIN, 'DD/MM/YYYY'));
    DBMS_OUTPUT.PUT_LINE('Dias congelados: ' || vDIASCONGELADOS);
    DBMS_OUTPUT.PUT_LINE('Nueva fecha de fin: ' || TO_CHAR(vNUEVAFECHA, 'DD/MM/YYYY'));
END;
/