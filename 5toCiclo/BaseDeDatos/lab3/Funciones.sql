SET SERVEROUTPUT ON;

-- A
CREATE OR REPLACE FUNCTION FN_INASISTENCIAS (id_socio GT_SOCIOS.SOCIO_ID%TYPE)
RETURN NUMBER
IS
    vCANT       NUMBER;
    vESTADO     CHAR;
BEGIN
    SELECT COUNT(*) INTO vCANT FROM GT_SOCIOS WHERE SOCIO_ID = id_socio;
    
    IF vCANT = 0 THEN
        RETURN -1; -- El socio no existe
    ELSE
        SELECT ESTADO INTO vESTADO FROM GT_SOCIOS WHERE SOCIO_ID = id_socio;
        
        IF vESTADO = 'I' THEN
            RETURN -2;
        ELSE
            -- Contamos las inasistencias
            SELECT COUNT(*)
            INTO vCANT
            FROM GT_RESERVAS
            WHERE SOCIO_ID = id_socio AND ASISTIO = 'N';
            
            RETURN vCANT;
        END IF;
    END IF;
END;
/

SELECT FN_INASISTENCIAS(3) FROM DUAL;

-- B
CREATE OR REPLACE FUNCTION FN_OCUPACION_CLASE (vClase_id NUMBER) RETURN NUMBER
IS
    vCant       NUMBER;
    vEstado     CHAR(1 BYTE);
    vReservas   NUMBER;
    vCapacidad  NUMBER;
BEGIN
    SELECT COUNT(*) INTO vCant FROM GT_CLASES WHERE CLASE_ID = vClase_id;
    
    IF vCant = 0 THEN
        RETURN -1;
    ELSE
        -- vemos si la clase esta cancelada o no
        SELECT ESTADO INTO vEstado FROM GT_CLASES WHERE CLASE_ID = vClase_id;
        
        IF vEstado = 'C' THEN
            RETURN -2;
        ELSE
            -- Calculamos la cantidad de reservas
            SELECT COUNT(*) INTO vReservas FROM GT_RESERVAS WHERE CLASE_ID = vClase_id AND ESTADO = 'R';
            -- Calculamos la capacidad
            SELECT CUPO_MAXIMO INTO vCapacidad FROM GT_CLASES WHERE CLASE_ID = vClase_id;
            -- Devolvemos el % de ocupación     
            RETURN ROUND((vReservas/vCapacidad * 100),0);
        END IF;
    END IF;
END;
/

SELECT FN_OCUPACION_CLASE(999) FROM DUAL;


-- A2
DECLARE
    vInasistencias  NUMBER;
    vSocio          VARCHAR(100);
    vIDsocio         NUMBER;
BEGIN
    vIDsocio := 2;
    vInasistencias := FN_INASISTENCIAS(vIDsocio);
    
    IF vInasistencias = -1 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || vIDsocio || ' no existe.');
    ELSIF vInasistencias = -2 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || vIDsocio || ' está inactivo.');
    ELSE
        SELECT NOMBRES || ' ' || APE_PATERNO INTO vSocio FROM GT_SOCIOS WHERE SOCIO_ID = vIDsocio;
        DBMS_OUTPUT.PUT_LINE(vSocio || ': ' || vInasistencias || ' inasistencias'); 
    END IF;
    -----------------------------------------------------------------------------------------------
    vIDsocio := 7;
    vInasistencias := FN_INASISTENCIAS(vIDsocio);
    
    IF vInasistencias = -1 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || vIDsocio || ' no existe.');
    ELSIF vInasistencias = -2 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || vIDsocio || ' está inactivo.');
    ELSE
        SELECT NOMBRES || ' ' || APE_PATERNO INTO vSocio FROM GT_SOCIOS WHERE SOCIO_ID = vIDsocio;
        DBMS_OUTPUT.PUT_LINE(vSocio || ': ' || vInasistencias || ' inasistencias'); 
    END IF;
    -----------------------------------------------------------------------------------------------
    vIDsocio := 999;
    vInasistencias := FN_INASISTENCIAS(vIDsocio);
    
    IF vInasistencias = -1 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || vIDsocio || ' no existe.');
    ELSIF vInasistencias = -2 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || vIDsocio || ' está inactivo.');
    ELSE
        SELECT NOMBRES || ' ' || APE_PATERNO INTO vSocio FROM GT_SOCIOS WHERE SOCIO_ID = vIDsocio;
        DBMS_OUTPUT.PUT_LINE(vSocio || ': ' || vInasistencias || ' inasistencias'); 
    END IF;
END;
/

-- B2

DECLARE
    vOcupacion      NUMBER;
    vIDclase        NUMBER;
    vTipoClase      VARCHAR2(30);
    vTipoOcupacion  VARCHAR2(10);
BEGIN
    vIDclase := 7;
    vOcupacion := FN_OCUPACION_CLASE(vIDclase);
    
    IF vOcupacion = -1 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vIDclase || ' no existe.');
    ELSIF vOcupacion = -2 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vIDclase || ' fue cancelada.');
    ELSE
        SELECT t.NOMBRE INTO vTipoClase 
        FROM GT_CLASES c, GT_TIPOS_CLASE t
        WHERE t.TIPO_CLASE_ID = c.TIPO_CLASE_ID AND c.CLASE_ID = vIDclase;
        
        CASE
            WHEN vOcupacion >= 100 THEN vTipoOcupacion := 'LLENA';
            WHEN vOcupacion >= 50  THEN vTipoOcupacion := 'ALTA';
            WHEN vOcupacion >= 20  THEN vTipoOcupacion := 'MEDIA';
            ELSE vTipoOcupacion := 'BAJA';
        END CASE;
        
        DBMS_OUTPUT.PUT_LINE('Clase ' || vIDclase || ' (' || vTipoClase || '): ' || vOcupacion || '% - ' || vTipoOcupacion);
    END IF;
    -----------------------------------------------------------------------------------------------
    vIDclase := 2;
    vOcupacion := FN_OCUPACION_CLASE(vIDclase);
    
    IF vOcupacion = -1 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vIDclase || ' no existe.');
    ELSIF vOcupacion = -2 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vIDclase || ' fue cancelada.');
    ELSE
        SELECT t.NOMBRE INTO vTipoClase 
        FROM GT_CLASES c, GT_TIPOS_CLASE t
        WHERE t.TIPO_CLASE_ID = c.TIPO_CLASE_ID AND c.CLASE_ID = vIDclase;
        
        CASE
            WHEN vOcupacion >= 100 THEN vTipoOcupacion := 'LLENA';
            WHEN vOcupacion >= 50  THEN vTipoOcupacion := 'ALTA';
            WHEN vOcupacion >= 20  THEN vTipoOcupacion := 'MEDIA';
            ELSE vTipoOcupacion := 'BAJA';
        END CASE;
        
        DBMS_OUTPUT.PUT_LINE('Clase ' || vIDclase || ' (' || vTipoClase || '): ' || vOcupacion || '% - ' || vTipoOcupacion);
    END IF;
    -----------------------------------------------------------------------------------------------
    vIDclase := 10;
    vOcupacion := FN_OCUPACION_CLASE(vIDclase);
    
    IF vOcupacion = -1 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vIDclase || ' no existe.');
    ELSIF vOcupacion = -2 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vIDclase || ' fue cancelada.');
    ELSE
        SELECT t.NOMBRE INTO vTipoClase 
        FROM GT_CLASES c, GT_TIPOS_CLASE t
        WHERE t.TIPO_CLASE_ID = c.TIPO_CLASE_ID AND c.CLASE_ID = vIDclase;
        
        CASE
            WHEN vOcupacion >= 100 THEN vTipoOcupacion := 'LLENA';
            WHEN vOcupacion >= 50  THEN vTipoOcupacion := 'ALTA';
            WHEN vOcupacion >= 20  THEN vTipoOcupacion := 'MEDIA';
            ELSE vTipoOcupacion := 'BAJA';
        END CASE;
        
        DBMS_OUTPUT.PUT_LINE('Clase ' || vIDclase || ' (' || vTipoClase || '): ' || vOcupacion || '% - ' || vTipoOcupacion);
    END IF;
    -----------------------------------------------------------------------------------------------
    vIDclase := 99;
    vOcupacion := FN_OCUPACION_CLASE(vIDclase);
    
    IF vOcupacion = -1 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vIDclase || ' no existe.');
    ELSIF vOcupacion = -2 THEN
        DBMS_OUTPUT.PUT_LINE('La clase ' || vIDclase || ' fue cancelada.');
    ELSE
        SELECT t.NOMBRE INTO vTipoClase 
        FROM GT_CLASES c, GT_TIPOS_CLASE t
        WHERE t.TIPO_CLASE_ID = c.TIPO_CLASE_ID AND c.CLASE_ID = vIDclase;
        
        CASE
            WHEN vOcupacion >= 100 THEN vTipoOcupacion := 'LLENA';
            WHEN vOcupacion >= 50  THEN vTipoOcupacion := 'ALTA';
            WHEN vOcupacion >= 20  THEN vTipoOcupacion := 'MEDIA';
            ELSE vTipoOcupacion := 'BAJA';
        END CASE;
        
        DBMS_OUTPUT.PUT_LINE('Clase ' || vIDclase || ' (' || vTipoClase || '): ' || vOcupacion || '% - ' || vTipoOcupacion);
    END IF;
END;
/

-- C
CREATE OR REPLACE FUNCTION FN_VOLUMEN_RUTINA (vIDsocio NUMBER)
RETURN NUMBER
IS
    vVolumen        NUMBER;
    vCant           NUMBER;
BEGIN
    SELECT COUNT(*) INTO vCant FROM GT_SOCIOS WHERE SOCIO_ID = vIDsocio;
    IF vCant = 0 THEN
        RETURN -1;
    END IF;
    
    SELECT COUNT(*) INTO vCant FROM GT_RUTINAS WHERE ESTADO = 'V' AND SOCIO_ID = vIDsocio;
    IF vCant = 0 THEN
        RETURN -2;
    END IF;

    SELECT NVL(SUM(d.SERIES*d.REPETICIONES), 0)
    INTO vVolumen
    FROM GT_RUTINAS r, GT_DETALLES_RUTINA d
    WHERE r.SOCIO_ID = vIDsocio and r.RUTINA_ID = d.RUTINA_ID and r.ESTADO = 'V';
    RETURN vVolumen;
END;
/

DECLARE
    vIDsocio        NUMBER;
    vResultado      NUMBER;
BEGIN
    vIDsocio    :=  1;
    vResultado  :=  FN_VOLUMEN_RUTINA(vIDsocio);
    DBMS_OUTPUT.PUT_LINE(vResultado);
    -----------------------------------------------
    vIDsocio    :=  3;
    vResultado  :=  FN_VOLUMEN_RUTINA(vIDsocio);
    DBMS_OUTPUT.PUT_LINE(vResultado);
    -----------------------------------------------
    vIDsocio    :=  6;
    vResultado  :=  FN_VOLUMEN_RUTINA(vIDsocio);
    DBMS_OUTPUT.PUT_LINE(vResultado);
    -----------------------------------------------
    vIDsocio    :=  2;
    vResultado  :=  FN_VOLUMEN_RUTINA(vIDsocio);
    DBMS_OUTPUT.PUT_LINE(vResultado);
    -----------------------------------------------
    vIDsocio    :=  999;
    vResultado  :=  FN_VOLUMEN_RUTINA(vIDsocio);
    DBMS_OUTPUT.PUT_LINE(vResultado);
    -----------------------------------------------
END;
/