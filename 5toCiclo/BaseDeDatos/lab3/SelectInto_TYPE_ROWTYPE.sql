SET SERVEROUTPUT ON;

-- A
DECLARE
    vNOMBRE     VARCHAR2(200);
    vCORREO     GT_SOCIOS.CORREO%TYPE;
    vSOCIO      GT_SOCIOS.SOCIO_ID%TYPE;
BEGIN
    SELECT NOMBRES || ' ' || APE_PATERNO || ' ' || APE_MATERNO, SOCIO_ID, CORREO
    INTO vNOMBRE, vSOCIO, vCORREO
    FROM GT_SOCIOS
    WHERE SOCIO_ID = 2;
    
    DBMS_OUTPUT.PUT_LINE('Socio: ' || vSOCIO || ': ' || TRIM(vNOMBRE) || ' | ' || 'Correo: ' || vCORREO);
END;
/

-- B
DECLARE
    vSEDE       GT_SEDES%ROWTYPE;
BEGIN
    SELECT *
    INTO vSEDE
    FROM GT_SEDES
    WHERE SEDE_ID = 2;
    
    DBMS_OUTPUT.PUT_LINE('Sede: ' || vSEDE.NOMBRE || ' | Aforo: ' || vSEDE.AFORO_MAXIMO
                         || ' | Horario: ' || TO_CHAR(vSEDE.HORA_APERTURA,'HH24:MI')
                         || ' - ' || TO_CHAR(vSEDE.HORA_CIERRE,'HH24:MI'));
END;
/

-- C
DECLARE
    vNOMBRE         GT_SOCIOS.NOMBRES%TYPE;
    vINASISTENCIAS  NUMBER;
    vCANT           NUMBER;
    vSOCIO          GT_SOCIOS.SOCIO_ID%TYPE := 999;
BEGIN
    SELECT COUNT(*) INTO vCANT FROM GT_SOCIOS WHERE SOCIO_ID = vSOCIO;
    
    IF vCANT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || vSOCIO || ' no existe.');
    ELSE
        SELECT COUNT(*)
        INTO vINASISTENCIAS
        FROM GT_RESERVAS
        WHERE ASISTIO = 'N' AND SOCIO_ID = vSOCIO;
        
        SELECT NOMBRES
        INTO vNOMBRE
        FROM GT_SOCIOS
        WHERE SOCIO_ID = vSOCIO;
        
        DBMS_OUTPUT.PUT_LINE('Inasistencias de ' || vNOMBRE || ': ' || vINASISTENCIAS);
    END IF;
END;
/

-- D
DECLARE
    vNOMBRES        VARCHAR2(200);
    vPLAN           GT_PLANES_MEMBRESIA.NOMBRE%TYPE;
    vVENCIMIENTO    GT_MEMBRESIAS.FECHA_FIN%TYPE;
    vCANT           NUMBER;
    vSOCIO          NUMBER      := 2;
BEGIN
    -- Verificamos que exista el socio
    SELECT COUNT(*) INTO vCANT FROM GT_SOCIOS WHERE SOCIO_ID = vSOCIO;
    
    IF vCANT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || vSOCIO || ' no existe.');
    ELSE
        -- Verificamos que tenga una membresia vigente
        SELECT COUNT(*) INTO vCANT FROM GT_MEMBRESIAS WHERE SOCIO_ID = vSOCIO AND ESTADO = 'V';
            IF vCANT = 0 THEN
                DBMS_OUTPUT.PUT_LINE('El socio ' || vSOCIO || ' no cuenta con membresias vigentes');
            ELSE
                -- Obtenemos los nombres
                SELECT NOMBRES || ' ' || APE_PATERNO || ' ' || APE_MATERNO
                INTO vNOMBRES
                FROM GT_SOCIOS
                WHERE SOCIO_ID = vSOCIO;
                
                -- Obtenemos la membresia vigente
                SELECT p.NOMBRE, m.FECHA_FIN
                INTO vPLAN, vVENCIMIENTO
                FROM GT_MEMBRESIAS m, GT_PLANES_MEMBRESIA p
                WHERE vSOCIO = m.SOCIO_ID AND m.PLAN_ID = p.PLAN_ID AND m.ESTADO = 'V';
                
                DBMS_OUTPUT.PUT_LINE(TRIM(vNOMBRES) || ' | ' || vPLAN || ' | Vence: ' || TO_CHAR(vVENCIMIENTO,'DD/MM/YYYY'));
            END IF;
    END IF;
END;
/

-- E
DECLARE
    vNOMBRES        VARCHAR(200);
    vCANT           NUMBER;
BEGIN
    SELECT count(*) INTO vCANT FROM GT_SOCIOS WHERE ESTADO = 'A';
    
    DBMS_OUTPUT.PUT_LINE(vCANT);
END;
/