SET SERVEROUTPUT ON;

-- Pregunta 1

CREATE OR REPLACE PROCEDURE sp_mostrar_socio(p_id_socio NUMBER)
IS
    v_socio         VARCHAR2(200);
    v_correo        GT_SOCIOS.CORREO%TYPE;
    v_cant          NUMBER;
BEGIN
    SELECT count(*)
    INTO v_cant
    FROM GT_SOCIOS
    WHERE SOCIO_ID = p_id_socio;
    
    IF v_cant = 0 THEN
        DBMS_OUTPUT.PUT_LINE('El socio ' || p_id_socio || ' no existe');
    ELSE
        SELECT NOMBRES || ' ' || APE_PATERNO, CORREO
        INTO v_socio, v_correo
        FROM GT_SOCIOS
        WHERE SOCIO_ID = p_id_socio;
        
        DBMS_OUTPUT.PUT_LINE('Socio: ' || v_socio || ' - ' || v_correo);
    END IF;
END;
/

EXEC sp_mostrar_socio(3);

-- Pregunta 2
CREATE OR REPLACE PROCEDURE sp_cancelar_membresia(p_id_membresia NUMBER)
IS
    v_estado                GT_MEMBRESIAS.ESTADO%TYPE;
    e_ya_finalizada         EXCEPTION;
    e_esta_congelada        EXCEPTION;
BEGIN
    SELECT ESTADO
    INTO v_estado
    FROM GT_MEMBRESIAS
    WHERE MEMBRESIA_ID = p_id_membresia;
    
    IF v_estado = 'F' THEN 
        RAISE e_ya_finalizada;
    END IF;
    
    IF v_estado = 'G' THEN
        RAISE e_esta_congelada;
    END IF;
    
    UPDATE GT_MEMBRESIAS
    SET ESTADO = 'F', MOTIVO_FIN = 'C'
    WHERE MEMBRESIA_ID = p_id_membresia;
    
    DBMS_OUTPUT.PUT_LINE('La membresia ' || p_id_membresia || ' fue cancelada correctamente.');
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('La membresia ' || p_id_membresia || ' no existe.');
    WHEN e_ya_finalizada THEN
        DBMS_OUTPUT.PUT_LINE('No se puede cancelar la membresia ' || p_id_membresia || ' porque ya esta finalizada.');
    WHEN e_esta_congelada THEN
        DBMS_OUTPUT.PUT_LINE('No se puede cancelar la membresia ' || p_id_membresia || ' porque esta congelada.');
END;
/

EXEC sp_cancelar_membresia(99);

-- Pregunta 3
CREATE OR REPLACE PROCEDURE sp_listar_membresias_socio (p_id_socio NUMBER)
IS
    CURSOR c (pc_id_socio NUMBER) IS
        SELECT m.MEMBRESIA_ID, p.NOMBRE, m.FECHA_INICIO, m.FECHA_FIN, m.ESTADO
        FROM GT_MEMBRESIAS m, GT_PLANES_MEMBRESIA p
        WHERE m.SOCIO_ID = pc_id_socio AND p.PLAN_ID = m.PLAN_ID
        ORDER BY m.FECHA_INICIO;
    v_cant_membresias       NUMBER      := 0;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Membresias del socio ' || p_id_socio);
    DBMS_OUTPUT.PUT_LINE('-----------------------------');
    
    FOR v_reg IN c(p_id_socio) LOOP
        DBMS_OUTPUT.PUT_LINE('ID: ' || v_reg.MEMBRESIA_ID || ' | ' ||
                             'Plan: ' || v_reg.NOMBRE || ' | ' ||
                             'Inicio: ' || TO_CHAR(v_reg.FECHA_INICIO, 'DD/MM/YYYY') || ' | ' ||
                             'Fin: ' || TO_CHAR(v_reg.FECHA_FIN, 'DD/MM/YYYY') || ' | ' ||
                             'Estado: ' || v_reg.ESTADO);
        v_cant_membresias := v_cant_membresias + 1;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Total de membresias: ' || v_cant_membresias);
END;
/

EXEC sp_listar_membresias_socio(99);

-- Pregunta 4
CREATE OR REPLACE PROCEDURE sp_reporte_sede(p_id_sede NUMBER)
IS
    v_sede      GT_SEDES%ROWTYPE;   
    CURSOR c(cp_id_sede NUMBER) IS 
        SELECT s.NOMBRES || ' ' || s.APE_PATERNO AS SOCIO,
               p.NOMBRE AS PLAN,
               p.PRECIO AS PRECIO,
               m.ESTADO AS ESTADO
        FROM GT_SOCIOS s, 
             GT_MEMBRESIAS m, 
             GT_PLANES_MEMBRESIA p
        WHERE m.SEDE_ID = cp_id_sede 
              AND p.PLAN_ID = m.PLAN_ID
              AND m.SOCIO_ID = s.SOCIO_ID;
    v_cant_vigentes         NUMBER      := 0;
    v_cant_congeladas       NUMBER      := 0;
    v_cant_finalizadas      NUMBER      := 0;
    v_socio_mas_caro        VARCHAR2(100 BYTE);
    v_plan_mas_caro         VARCHAR2(100 BYTE);
    v_precio_mas_caro       NUMBER      := 0;
BEGIN
    SELECT *
    INTO v_sede
    FROM GT_SEDES
    WHERE SEDE_ID = p_id_sede;
    
    DBMS_OUTPUT.PUT_LINE('Sede: ' || v_sede.NOMBRE);
    DBMS_OUTPUT.PUT_LINE('Dirección: ' || v_sede.DIRECCION);
    DBMS_OUTPUT.PUT_LINE('Aforo máximo: ' || v_sede.AFORO_MAXIMO);
    DBMS_OUTPUT.PUT_LINE('SOCIO - PLAN - PRECIO - ESTADO');
    DBMS_OUTPUT.PUT_LINE('*********************************');
    
    FOR v_reg IN c(p_id_sede) LOOP
        DBMS_OUTPUT.PUT_LINE(v_reg.SOCIO || ' - ' || v_reg.PLAN || ' - ' || v_reg.PRECIO || ' - ' || v_reg.ESTADO);
        
        IF v_reg.ESTADO = 'V' THEN
            v_cant_vigentes := v_cant_vigentes + 1;
        ELSIF v_reg.ESTADO = 'G' THEN
            v_cant_congeladas := v_cant_congeladas + 1;
        ELSIF v_reg.ESTADO = 'F' THEN
            v_cant_finalizadas := v_cant_finalizadas + 1;
        END IF;
        
        IF v_precio_mas_caro < v_reg.PRECIO THEN
            v_precio_mas_caro := v_reg.PRECIO;
            v_socio_mas_caro := v_reg.SOCIO;
            v_plan_mas_caro := v_reg.PLAN;
        END IF;
    END LOOP;
    
    DBMS_OUTPUT.PUT_LINE('Vigentes: ' || v_cant_vigentes || ' | Congeladas: ' || v_cant_congeladas || ' | Finalizadas: ' || v_cant_finalizadas);
    DBMS_OUTPUT.PUT_LINE('Plan más caro: ' || v_socio_mas_caro || ' con ' || v_plan_mas_caro || ' (S/ ' || TO_CHAR(v_precio_mas_caro) || ')');

EXCEPTION
    WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('La sede ' || p_id_sede || ' no existe.');
END;
/

EXEC sp_reporte_sede(1);

-- Pregunta 5
DECLARE
    id_clase        NUMBER          := 4;
    CURSOR c(cp_id_clase NUMBER) IS
        SELECT s.NOMBRES || ' ' || s.APE_PATERNO AS SOCIO,
               r.ESTADO AS ESTADO,
               NVL(r.ASISTIO, 'U') AS ASISTIO  -- U de Undefined
        FROM GT_SOCIOS s,
             GT_RESERVAS r
        WHERE r.CLASE_ID = cp_id_clase AND
              s.SOCIO_ID = r.SOCIO_ID;
    v_cant_reservados       NUMBER := 0;
    v_lista_espera          NUMBER := 0;
    v_canceladas            NUMBER := 0;
    v_asistieron            NUMBER := 0;
    v_no_asistieron         NUMBER := 0;
    v_sin_registrar         NUMBER := 0;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Reservas de la clase ' || id_clase);
    DBMS_OUTPUT.PUT_LINE('-----------------------------');

    FOR r IN c(id_clase) LOOP
        DBMS_OUTPUT.PUT_LINE(r.SOCIO || ' - Estado: ' || r.ESTADO || ' - Asistio: ' || r.ASISTIO);
        
        IF r.ESTADO = 'L' THEN
            v_lista_espera := v_lista_espera + 1;
        ELSIF r.ESTADO = 'R' THEN
            v_cant_reservados := v_cant_reservados + 1;
        ELSIF r.ESTADO = 'C' THEN
            v_canceladas := v_canceladas + 1;
        END IF;
        
        IF r.ASISTIO = 'S' THEN
            v_asistieron := v_asistieron + 1;
        ELSIF r.ASISTIO = 'N' THEN
            v_no_asistieron := v_no_asistieron + 1;
        ELSIF r.ASISTIO = 'U' THEN
            v_sin_registrar := v_sin_registrar + 1;
        END IF;
        
    END LOOP;
    
    DBMS_OUTPUT.PUT_LINE('Reservados: ' || v_cant_reservados || ' | ' ||
                         'Lista de espera: ' || v_lista_espera || ' | ' ||
                         'Canceladas: ' || v_canceladas);
    DBMS_OUTPUT.PUT_LINE('Asistieron: ' || v_asistieron || ' | ' ||
                         'No asistieron: ' || v_no_asistieron || ' | ' ||
                         'Sin registrar: ' || v_sin_registrar);
END;
/

-- Pregunta 6
CREATE OR REPLACE PROCEDURE sp_recalcular_fecha_fin
IS
    CURSOR c IS
        SELECT *
        FROM GT_MEMBRESIAS
        WHERE ESTADO = 'V' OR ESTADO = 'G';
    v_fecha_nueva               GT_MEMBRESIAS.FECHA_FIN%TYPE;
    v_dias_vigencia             GT_PLANES_MEMBRESIA.DIAS_VIGENCIA%TYPE;
    v_total_recalculadas        NUMBER := 0;
BEGIN
    FOR r IN c LOOP
        SELECT DIAS_VIGENCIA
        INTO v_dias_vigencia
        FROM GT_PLANES_MEMBRESIA
        WHERE PLAN_ID = r.PLAN_ID;
        
        v_fecha_nueva := r.FECHA_INICIO + v_dias_vigencia + r.DIAS_CONGELADOS;
        
        UPDATE GT_MEMBRESIAS
        SET FECHA_FIN = v_fecha_nueva
        WHERE MEMBRESIA_ID = r.MEMBRESIA_ID;
        
        DBMS_OUTPUT.PUT_LINE('Membresia ' || r.MEMBRESIA_ID || ': ' || r.FECHA_FIN || ' -> ' || v_fecha_nueva);
        
        v_total_recalculadas := v_total_recalculadas + 1;
    END LOOP;
    
    DBMS_OUTPUT.PUT_LINE('Total recalculadas: ' || v_total_recalculadas);
END;
/

EXEC sp_recalcular_fecha_fin;

ROLLBACK;

-- Pregunta 7
CREATE OR REPLACE PROCEDURE sp_membresias_por_sede
IS
    CURSOR c_sede IS
        SELECT SEDE_ID, NOMBRE
        FROM GT_SEDES
        WHERE ESTADO = 'A'
        ORDER BY NOMBRE;
        
    CURSOR c_membresias(pc_sede_id NUMBER) IS
        SELECT s.NOMBRES || ' ' || s.APE_PATERNO AS SOCIO,
               p.NOMBRE AS PLAN,
               m.FECHA_FIN AS VENCIMIENTO
        FROM GT_SOCIOS s, 
             GT_MEMBRESIAS m, 
             GT_PLANES_MEMBRESIA p
        WHERE m.SEDE_ID = pc_sede_id AND 
              s.SOCIO_ID = m.SOCIO_ID AND  
              m.PLAN_ID = p.PLAN_ID AND
              m.ESTADO = 'V';
    v_total_sede                NUMBER := 0;
    v_sede_mas_vigentes         GT_SEDES.NOMBRE%TYPE;
    v_cant_mas_vigentes         NUMBER := 0;
BEGIN
    DBMS_OUTPUT.PUT_LINE('REPORTE DE MEMBRESIAS VIGENTES POR SEDE');
    
    FOR r_sede IN c_sede LOOP
        v_total_sede := 0;
        DBMS_OUTPUT.PUT_LINE(r_sede.NOMBRE);
        FOR r_membresia IN c_membresias(r_sede.SEDE_ID) LOOP
            DBMS_OUTPUT.PUT_LINE('   - ' || r_membresia.SOCIO || ' | ' ||
                                 'Plan: ' || r_membresia.PLAN || ' | ' ||
                                 'Vence: ' || r_membresia.VENCIMIENTO);
            v_total_sede := v_total_sede + 1;
        END LOOP;
        
        IF v_total_sede = 0 THEN 
            DBMS_OUTPUT.PUT_LINE('   (sin membresias vigentes)');
        ELSE
            DBMS_OUTPUT.PUT_LINE('   Total sede: ' || v_total_sede);
        END IF;
        
        IF v_total_sede > v_cant_mas_vigentes THEN
            v_sede_mas_vigentes := r_sede.NOMBRE;
            v_cant_mas_vigentes := v_total_sede;
        END IF;
    END LOOP;
    
    DBMS_OUTPUT.PUT_LINE('Sede con más vigentes: ' || v_sede_mas_vigentes || ' (' || v_cant_mas_vigentes || ')');
END;
/

EXEC sp_membresias_por_sede;