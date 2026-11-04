SET SERVEROUTPUT ON;

-- A
DECLARE
    vCLASE      GT_CLASES.CLASE_ID%TYPE      := 99;
    vESTADO     GT_CLASES.ESTADO%TYPE;
    vRESERVAS   NUMBER;
    vCAPACIDAD  NUMBER;
    vOCUPACION  NUMBER;
    vNIVEL      VARCHAR(10);
    vCANT       NUMBER;
BEGIN
    SELECT COUNT(*) INTO vCANT FROM GT_CLASES WHERE CLASE_ID = vCLASE;
    
    IF vCANT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vCLASE || ' no existe.');
    ELSE
        SELECT ESTADO INTO vESTADO FROM GT_CLASES WHERE CLASE_ID = vCLASE;
        
        IF vESTADO = 'C' THEN
            DBMS_OUTPUT.PUT_LINE('La clase ' || vCLASE || ' fue cancelada.');
        ELSE
            -- Contamos la cantidad de reservas validas
            SELECT COUNT(*) INTO vRESERVAS FROM GT_RESERVAS WHERE CLASE_ID = vCLASE AND ESTADO = 'R';
            
            -- Ahora obtenemos la capacidad de la clase
            SELECT CUPO_MAXIMO INTO vCAPACIDAD FROM GT_CLASES WHERE CLASE_ID = vCLASE;
            
            -- Calculamos el porcentaje de ocupacion
            vOCUPACION := vRESERVAS/vCAPACIDAD *100;
            
            -- Calculamos el nivel
            CASE 
                WHEN vOCUPACION = 100 THEN vNIVEL := 'LLENO';
                WHEN vOCUPACION >= 50 THEN vNIVEL := 'ALTA';
                WHEN vOCUPACION >= 20 THEN vNIVEL := 'MEDIA';
                ELSE vNIVEL := 'BAJA';
            END CASE;
            
            -- Mostramos la salida
            DBMS_OUTPUT.PUT_LINE('Clase ' || vCLASE || ': ' || vRESERVAS || '/' || vCAPACIDAD || ' reservas (' || vOCUPACION || '%) - ' || vNIVEL);
        END IF;
    END IF;
END;
/

-- B
DECLARE
    vMEMBRESIA  GT_MEMBRESIAS.MEMBRESIA_ID%TYPE := 6;
    vESTADO     VARCHAR2(20);
    vMOTIVOFIN  VARCHAR2(15);
    vCANT       NUMBER;
BEGIN
    SELECT COUNT(*) INTO vCANT FROM GT_MEMBRESIAS WHERE MEMBRESIA_ID = vMEMBRESIA;
    
    IF vCANT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('La membresia ' || vMEMBRESIA || ' no existe');
    ELSE
        -- Consultamos el estado de la membresia
        SELECT CASE ESTADO WHEN 'V' THEN 'Vigente' WHEN 'G' THEN 'Congelada' ELSE 'Finalizada' END
        INTO vESTADO
        FROM GT_MEMBRESIAS
        WHERE MEMBRESIA_ID = vMEMBRESIA;
        
        SELECT CASE MOTIVO_FIN WHEN 'N' THEN 'Vencida' WHEN 'C' THEN 'Cancelada' ELSE '' END
        INTO vMOTIVOFIN
        FROM GT_MEMBRESIAS
        WHERE MEMBRESIA_ID = vMEMBRESIA;
        
        DBMS_OUTPUT.PUT_LINE('Membresía ' || vMEMBRESIA || ': ' || vESTADO || ' (' || vMOTIVOFIN || ')');
    END IF;
END;
/

-- C
DECLARE
    vRESERVA        NUMBER          := 6;
    vASISTIO        CHAR(1 BYTE);
BEGIN
    SELECT ASISTIO INTO vASISTIO FROM GT_RESERVAS WHERE RESERVA_ID = vRESERVA;
    
    CASE vASISTIO
        WHEN 'S' THEN DBMS_OUTPUT.PUT_LINE('Reserva ' || vRESERVA || ': Asistió');
        WHEN 'N' THEN DBMS_OUTPUT.PUT_LINE('Reserva ' || vRESERVA || ': No asistió');
        ELSE DBMS_OUTPUT.PUT_LINE('Reserva ' || vRESERVA || ': Pendiente');
    END CASE;
END;
/