--------------------------------------------------------------------------------
-- 1. GT_SEDES
--------------------------------------------------------------------------------
CREATE TABLE GT_SEDES (
  SEDE_ID        NUMBER(4)        NOT NULL,
  NOMBRE         VARCHAR2(60 BYTE)  NOT NULL,
  DIRECCION      VARCHAR2(150 BYTE) NOT NULL,
  HORA_APERTURA  DATE             NOT NULL,
  HORA_CIERRE    DATE             NOT NULL,
  AFORO_MAXIMO   NUMBER(5)        NOT NULL,
  ESTADO         CHAR(1 BYTE)     NOT NULL,
  CONSTRAINT PK_SEDES PRIMARY KEY (SEDE_ID)
);

COMMENT ON TABLE  GT_SEDES IS 'Sedes del gimnasio GymTotal';
COMMENT ON COLUMN GT_SEDES.SEDE_ID IS 'Identificador de la sede';
COMMENT ON COLUMN GT_SEDES.NOMBRE IS 'Nombre comercial de la sede';
COMMENT ON COLUMN GT_SEDES.DIRECCION IS 'Direccion fisica de la sede';
COMMENT ON COLUMN GT_SEDES.HORA_APERTURA IS 'Hora de apertura de atencion de la sede';
COMMENT ON COLUMN GT_SEDES.HORA_CIERRE IS 'Hora de cierre de atencion de la sede';
COMMENT ON COLUMN GT_SEDES.AFORO_MAXIMO IS 'Aforo maximo permitido segun infraestructura';
COMMENT ON COLUMN GT_SEDES.ESTADO IS 'Estado de la sede: A-Activa, I-Inactiva';

--------------------------------------------------------------------------------
-- 2. GT_PLANES_MEMBRESIA
--------------------------------------------------------------------------------
CREATE TABLE GT_PLANES_MEMBRESIA (
  PLAN_ID              NUMBER(4)        NOT NULL,
  NOMBRE               VARCHAR2(50 BYTE)  NOT NULL,
  DIAS_VIGENCIA        NUMBER(5)        NOT NULL,
  PRECIO               NUMBER(7,2)      NOT NULL,
  ACCESO_SALA_PESAS    CHAR(1 BYTE)     NOT NULL,
  CLASES_ILIMITADAS    CHAR(1 BYTE)     NOT NULL,
  CASILLERO_INCLUIDO   CHAR(1 BYTE)     NOT NULL,
  ESTADO               CHAR(1 BYTE)     NOT NULL,
  CONSTRAINT PK_PLANES_MEMBRESIA PRIMARY KEY (PLAN_ID)
);

COMMENT ON TABLE  GT_PLANES_MEMBRESIA IS 'Catalogo de planes de membresia ofrecidos';
COMMENT ON COLUMN GT_PLANES_MEMBRESIA.PLAN_ID IS 'Identificador del plan de membresia';
COMMENT ON COLUMN GT_PLANES_MEMBRESIA.NOMBRE IS 'Nombre del plan (mensual, trimestral, semestral, anual)';
COMMENT ON COLUMN GT_PLANES_MEMBRESIA.DIAS_VIGENCIA IS 'Cantidad de dias de vigencia del plan';
COMMENT ON COLUMN GT_PLANES_MEMBRESIA.PRECIO IS 'Precio del plan en soles';
COMMENT ON COLUMN GT_PLANES_MEMBRESIA.ACCESO_SALA_PESAS IS 'Indica si el plan incluye acceso a sala de pesas: S-Si, N-No';
COMMENT ON COLUMN GT_PLANES_MEMBRESIA.CLASES_ILIMITADAS IS 'Indica si el plan incluye clases grupales ilimitadas: S-Si, N-No';
COMMENT ON COLUMN GT_PLANES_MEMBRESIA.CASILLERO_INCLUIDO IS 'Indica si el plan incluye casillero: S-Si, N-No';
COMMENT ON COLUMN GT_PLANES_MEMBRESIA.ESTADO IS 'Estado del plan: A-Activo, I-Inactivo';

--------------------------------------------------------------------------------
-- 3. GT_SOCIOS
--------------------------------------------------------------------------------
CREATE TABLE GT_SOCIOS (
  SOCIO_ID        NUMBER(8)        NOT NULL,
  TIPO_DOCUMENTO  CHAR(1 BYTE)     NOT NULL,
  NRO_DOCUMENTO   VARCHAR2(15 BYTE)  NOT NULL,
  NOMBRES         VARCHAR2(50 BYTE)  NOT NULL,
  APE_PATERNO     VARCHAR2(50 BYTE)  NOT NULL,
  APE_MATERNO     VARCHAR2(50 BYTE),
  FECHA_NACIMIENTO DATE            NOT NULL,
  TELEFONO        VARCHAR2(15 BYTE),
  CORREO          VARCHAR2(80 BYTE)  NOT NULL,
  FECHA_REGISTRO  DATE             DEFAULT SYSDATE NOT NULL,
  ESTADO          CHAR(1 BYTE)     NOT NULL,
  CONSTRAINT PK_SOCIOS PRIMARY KEY (SOCIO_ID)
);

COMMENT ON TABLE  GT_SOCIOS IS 'Socios registrados en GymTotal';
COMMENT ON COLUMN GT_SOCIOS.SOCIO_ID IS 'Identificador del socio';
COMMENT ON COLUMN GT_SOCIOS.TIPO_DOCUMENTO IS 'Tipo de documento: D-DNI, C-Carnet de extranjeria, P-Pasaporte';
COMMENT ON COLUMN GT_SOCIOS.NRO_DOCUMENTO IS 'Numero de documento de identidad del socio';
COMMENT ON COLUMN GT_SOCIOS.NOMBRES IS 'Nombres del socio';
COMMENT ON COLUMN GT_SOCIOS.APE_PATERNO IS 'Apellido paterno del socio';
COMMENT ON COLUMN GT_SOCIOS.APE_MATERNO IS 'Apellido materno del socio';
COMMENT ON COLUMN GT_SOCIOS.FECHA_NACIMIENTO IS 'Fecha de nacimiento del socio';
COMMENT ON COLUMN GT_SOCIOS.TELEFONO IS 'Numero de telefono de contacto del socio';
COMMENT ON COLUMN GT_SOCIOS.CORREO IS 'Correo electronico del socio';
COMMENT ON COLUMN GT_SOCIOS.FECHA_REGISTRO IS 'Fecha en la que el socio se registro en el sistema';
COMMENT ON COLUMN GT_SOCIOS.ESTADO IS 'Estado del socio: A-Activo, I-Inactivo';

--------------------------------------------------------------------------------
-- 4. GT_MEMBRESIAS
--------------------------------------------------------------------------------
CREATE TABLE GT_MEMBRESIAS (
  MEMBRESIA_ID     NUMBER(10)      NOT NULL,
  SOCIO_ID         NUMBER(8)       NOT NULL,
  PLAN_ID          NUMBER(4)       NOT NULL,
  SEDE_ID          NUMBER(4)       NOT NULL,
  FECHA_INICIO     DATE            NOT NULL,
  FECHA_FIN        DATE            NOT NULL,
  DIAS_CONGELADOS  NUMBER(3)       DEFAULT 0 NOT NULL,
  ESTADO           CHAR(1 BYTE)    NOT NULL,
  MOTIVO_FIN       CHAR(1 BYTE),
  CONSTRAINT PK_MEMBRESIAS PRIMARY KEY (MEMBRESIA_ID)
);

COMMENT ON TABLE  GT_MEMBRESIAS IS 'Historial de membresias contratadas por cada socio';
COMMENT ON COLUMN GT_MEMBRESIAS.MEMBRESIA_ID IS 'Identificador de la membresia';
COMMENT ON COLUMN GT_MEMBRESIAS.SOCIO_ID IS 'Identificador del socio titular de la membresia';
COMMENT ON COLUMN GT_MEMBRESIAS.PLAN_ID IS 'Identificador del plan contratado';
COMMENT ON COLUMN GT_MEMBRESIAS.SEDE_ID IS 'Identificador de la sede donde se contrato la membresia';
COMMENT ON COLUMN GT_MEMBRESIAS.FECHA_INICIO IS 'Fecha de inicio de vigencia de la membresia';
COMMENT ON COLUMN GT_MEMBRESIAS.FECHA_FIN IS 'Fecha de fin de vigencia de la membresia (incluye extension por congelamiento)';
COMMENT ON COLUMN GT_MEMBRESIAS.DIAS_CONGELADOS IS 'Cantidad acumulada de dias congelados durante el año de vigencia (maximo 15)';
COMMENT ON COLUMN GT_MEMBRESIAS.ESTADO IS 'Estado de la membresia: V-Vigente, G-Congelada, F-Finalizada';
COMMENT ON COLUMN GT_MEMBRESIAS.MOTIVO_FIN IS 'Motivo de finalizacion (solo si ESTADO=F): N-Vencida natural, C-Cancelada';

--------------------------------------------------------------------------------
-- 5. GT_CONGELAMIENTOS
--------------------------------------------------------------------------------
CREATE TABLE GT_CONGELAMIENTOS (
  CONGELAMIENTO_ID  NUMBER(10)     NOT NULL,
  MEMBRESIA_ID      NUMBER(10)     NOT NULL,
  FECHA_INICIO      DATE           NOT NULL,
  FECHA_FIN         DATE           NOT NULL,
  DIAS              NUMBER(3)      NOT NULL,
  CONSTRAINT PK_CONGELAMIENTOS PRIMARY KEY (CONGELAMIENTO_ID)
);

COMMENT ON TABLE  GT_CONGELAMIENTOS IS 'Periodos de congelamiento solicitados sobre una membresia';
COMMENT ON COLUMN GT_CONGELAMIENTOS.CONGELAMIENTO_ID IS 'Identificador del periodo de congelamiento';
COMMENT ON COLUMN GT_CONGELAMIENTOS.MEMBRESIA_ID IS 'Identificador de la membresia congelada';
COMMENT ON COLUMN GT_CONGELAMIENTOS.FECHA_INICIO IS 'Fecha de inicio del congelamiento';
COMMENT ON COLUMN GT_CONGELAMIENTOS.FECHA_FIN IS 'Fecha de fin del congelamiento';
COMMENT ON COLUMN GT_CONGELAMIENTOS.DIAS IS 'Cantidad de dias congelados en este periodo';

--------------------------------------------------------------------------------
-- 6. GT_ROLES
--------------------------------------------------------------------------------
CREATE TABLE GT_ROLES (
  ROL_ID       NUMBER(4)         NOT NULL,
  NOMBRE       VARCHAR2(40 BYTE)   NOT NULL,
  DESCRIPCION  VARCHAR2(150 BYTE),
  CONSTRAINT PK_ROLES PRIMARY KEY (ROL_ID)
);

COMMENT ON TABLE  GT_ROLES IS 'Catalogo de roles que puede desempeñar el personal';
COMMENT ON COLUMN GT_ROLES.ROL_ID IS 'Identificador del rol';
COMMENT ON COLUMN GT_ROLES.NOMBRE IS 'Nombre del rol (Instructor, Entrenador Personal, Recepcion)';
COMMENT ON COLUMN GT_ROLES.DESCRIPCION IS 'Descripcion del rol';

--------------------------------------------------------------------------------
-- 7. GT_PERSONAL
-- Se mantiene en singular por ser un sustantivo colectivo en español
-- (equivalente a "staff"), tal como GT_PERSONAL no admite una forma
-- plural natural distinta.
--------------------------------------------------------------------------------
CREATE TABLE GT_PERSONAL (
  PERSONAL_ID     NUMBER(8)        NOT NULL,
  TIPO_DOCUMENTO  CHAR(1 BYTE)     NOT NULL,
  NRO_DOCUMENTO   VARCHAR2(15 BYTE)  NOT NULL,
  NOMBRES         VARCHAR2(50 BYTE)  NOT NULL,
  APE_PATERNO     VARCHAR2(50 BYTE)  NOT NULL,
  APE_MATERNO     VARCHAR2(50 BYTE),
  TELEFONO        VARCHAR2(15 BYTE),
  CORREO          VARCHAR2(80 BYTE)  NOT NULL,
  SEDE_ID         NUMBER(4)        NOT NULL,
  ESTADO          CHAR(1 BYTE)     NOT NULL,
  CONSTRAINT PK_PERSONAL PRIMARY KEY (PERSONAL_ID)
);

COMMENT ON TABLE  GT_PERSONAL IS 'Personal que labora en GymTotal';
COMMENT ON COLUMN GT_PERSONAL.PERSONAL_ID IS 'Identificador del personal';
COMMENT ON COLUMN GT_PERSONAL.TIPO_DOCUMENTO IS 'Tipo de documento: D-DNI, C-Carnet de extranjeria, P-Pasaporte';
COMMENT ON COLUMN GT_PERSONAL.NRO_DOCUMENTO IS 'Numero de documento de identidad del personal';
COMMENT ON COLUMN GT_PERSONAL.NOMBRES IS 'Nombres del personal';
COMMENT ON COLUMN GT_PERSONAL.APE_PATERNO IS 'Apellido paterno del personal';
COMMENT ON COLUMN GT_PERSONAL.APE_MATERNO IS 'Apellido materno del personal';
COMMENT ON COLUMN GT_PERSONAL.TELEFONO IS 'Telefono de contacto del personal';
COMMENT ON COLUMN GT_PERSONAL.CORREO IS 'Correo electronico del personal';
COMMENT ON COLUMN GT_PERSONAL.SEDE_ID IS 'Identificador de la sede a la que esta asignado principalmente';
COMMENT ON COLUMN GT_PERSONAL.ESTADO IS 'Estado del personal: A-Activo, I-Inactivo';

--------------------------------------------------------------------------------
-- 8. GT_PERSONAL_ROLES
-- Relacion M:N pura entre Personal y Rol: SIN ID propio, PK compuesta.
--------------------------------------------------------------------------------
CREATE TABLE GT_PERSONAL_ROLES (
  PERSONAL_ID      NUMBER(8)       NOT NULL,
  ROL_ID           NUMBER(4)       NOT NULL,
  ESPECIALIDAD     VARCHAR2(60 BYTE),
  HORA_INICIO      DATE,
  HORA_FIN         DATE,
  ESTADO           CHAR(1 BYTE)    NOT NULL,
  CONSTRAINT PK_PERSONAL_ROLES PRIMARY KEY (PERSONAL_ID, ROL_ID)
);

COMMENT ON TABLE  GT_PERSONAL_ROLES IS 'Roles asignados a cada persona del personal (una persona puede tener varios roles)';
COMMENT ON COLUMN GT_PERSONAL_ROLES.PERSONAL_ID IS 'Identificador del personal (parte de la PK compuesta)';
COMMENT ON COLUMN GT_PERSONAL_ROLES.ROL_ID IS 'Identificador del rol asignado (parte de la PK compuesta)';
COMMENT ON COLUMN GT_PERSONAL_ROLES.ESPECIALIDAD IS 'Especialidad asociada al rol (ej. Yoga, Spinning, Rehabilitacion)';
COMMENT ON COLUMN GT_PERSONAL_ROLES.HORA_INICIO IS 'Hora de inicio del horario de trabajo para este rol';
COMMENT ON COLUMN GT_PERSONAL_ROLES.HORA_FIN IS 'Hora de fin del horario de trabajo para este rol';
COMMENT ON COLUMN GT_PERSONAL_ROLES.ESTADO IS 'Estado de la asignacion de rol: A-Activo, I-Inactivo';

--------------------------------------------------------------------------------
-- 9. GT_TIPOS_CLASE
--------------------------------------------------------------------------------
CREATE TABLE GT_TIPOS_CLASE (
  TIPO_CLASE_ID  NUMBER(4)         NOT NULL,
  NOMBRE         VARCHAR2(50 BYTE)   NOT NULL,
  DESCRIPCION    VARCHAR2(200 BYTE),
  ESTADO         CHAR(1 BYTE)      NOT NULL,
  CONSTRAINT PK_TIPOS_CLASE PRIMARY KEY (TIPO_CLASE_ID)
);

COMMENT ON TABLE  GT_TIPOS_CLASE IS 'Catalogo de tipos de clase grupal ofrecidos';
COMMENT ON COLUMN GT_TIPOS_CLASE.TIPO_CLASE_ID IS 'Identificador del tipo de clase';
COMMENT ON COLUMN GT_TIPOS_CLASE.NOMBRE IS 'Nombre del tipo de clase (Spinning, Funcional, Yoga, Zumba, etc.)';
COMMENT ON COLUMN GT_TIPOS_CLASE.DESCRIPCION IS 'Descripcion del tipo de clase';
COMMENT ON COLUMN GT_TIPOS_CLASE.ESTADO IS 'Estado del tipo de clase: A-Activo, I-Inactivo';

--------------------------------------------------------------------------------
-- 10. GT_CLASES
-- El instructor se referencia con el par (PERSONAL_INSTRUCTOR_ID,
-- ROL_INSTRUCTOR_ID) porque apunta a la PK compuesta de GT_PERSONAL_ROLES.
--------------------------------------------------------------------------------
CREATE TABLE GT_CLASES (
  CLASE_ID                NUMBER(10)     NOT NULL,
  TIPO_CLASE_ID           NUMBER(4)      NOT NULL,
  SEDE_ID                 NUMBER(4)      NOT NULL,
  PERSONAL_INSTRUCTOR_ID  NUMBER(8)      NOT NULL,
  ROL_INSTRUCTOR_ID       NUMBER(4)      NOT NULL,
  FECHA_CLASE             DATE           NOT NULL,
  HORA_INICIO             DATE           NOT NULL,
  HORA_FIN                DATE           NOT NULL,
  CUPO_MAXIMO             NUMBER(4)      NOT NULL,
  ESTADO                  CHAR(1 BYTE)   NOT NULL,
  CONSTRAINT PK_CLASES PRIMARY KEY (CLASE_ID)
);

COMMENT ON TABLE  GT_CLASES IS 'Sesiones programadas de clase grupal';
COMMENT ON COLUMN GT_CLASES.CLASE_ID IS 'Identificador de la sesion de clase';
COMMENT ON COLUMN GT_CLASES.TIPO_CLASE_ID IS 'Identificador del tipo de clase dictada';
COMMENT ON COLUMN GT_CLASES.SEDE_ID IS 'Identificador de la sede donde se dicta la clase';
COMMENT ON COLUMN GT_CLASES.PERSONAL_INSTRUCTOR_ID IS 'Identificador del personal que dicta la clase (parte de la FK compuesta a GT_PERSONAL_ROLES)';
COMMENT ON COLUMN GT_CLASES.ROL_INSTRUCTOR_ID IS 'Identificador del rol de instructor (parte de la FK compuesta a GT_PERSONAL_ROLES)';
COMMENT ON COLUMN GT_CLASES.FECHA_CLASE IS 'Fecha en la que se dicta la clase';
COMMENT ON COLUMN GT_CLASES.HORA_INICIO IS 'Hora de inicio de la clase';
COMMENT ON COLUMN GT_CLASES.HORA_FIN IS 'Hora de fin de la clase';
COMMENT ON COLUMN GT_CLASES.CUPO_MAXIMO IS 'Cantidad maxima de participantes permitidos';
COMMENT ON COLUMN GT_CLASES.ESTADO IS 'Estado de la clase: P-Programada, R-Realizada, C-Cancelada';

--------------------------------------------------------------------------------
-- 11. GT_RESERVAS
--------------------------------------------------------------------------------
CREATE TABLE GT_RESERVAS (
  RESERVA_ID     NUMBER(10)        NOT NULL,
  CLASE_ID       NUMBER(10)        NOT NULL,
  SOCIO_ID       NUMBER(8)         NOT NULL,
  FECHA_RESERVA  DATE              DEFAULT SYSDATE NOT NULL,
  ASISTIO        CHAR(1 BYTE),
  ESTADO         CHAR(1 BYTE)      NOT NULL,
  CONSTRAINT PK_RESERVAS PRIMARY KEY (RESERVA_ID)
);

COMMENT ON TABLE  GT_RESERVAS IS 'Reservas de socios a sesiones de clase grupal';
COMMENT ON COLUMN GT_RESERVAS.RESERVA_ID IS 'Identificador de la reserva';
COMMENT ON COLUMN GT_RESERVAS.CLASE_ID IS 'Identificador de la sesion de clase reservada';
COMMENT ON COLUMN GT_RESERVAS.SOCIO_ID IS 'Identificador del socio que realiza la reserva';
COMMENT ON COLUMN GT_RESERVAS.FECHA_RESERVA IS 'Fecha y hora en que se registro la reserva';
COMMENT ON COLUMN GT_RESERVAS.ASISTIO IS 'Indica si el socio asistio (check-in): S-Si, N-No; nulo si la clase aun no se realiza';
COMMENT ON COLUMN GT_RESERVAS.ESTADO IS 'Estado de la reserva: R-Reservado, L-Lista de espera, C-Cancelada';

--------------------------------------------------------------------------------
-- 12. GT_EVALUACIONES_FISICAS
-- Servicio opcional. El entrenador se referencia con el par
-- (PERSONAL_ENTRENADOR_ID, ROL_ENTRENADOR_ID) apuntando a GT_PERSONAL_ROLES.
--------------------------------------------------------------------------------
CREATE TABLE GT_EVALUACIONES_FISICAS (
  EVALUACION_ID           NUMBER(10)  NOT NULL,
  SOCIO_ID                NUMBER(8)   NOT NULL,
  PERSONAL_ENTRENADOR_ID  NUMBER(8)   NOT NULL,
  ROL_ENTRENADOR_ID       NUMBER(4)   NOT NULL,
  FECHA_EVALUACION        DATE        DEFAULT SYSDATE NOT NULL,
  PESO                    NUMBER(5,2) NOT NULL,
  TALLA                   NUMBER(3,2) NOT NULL,
  PORCENTAJE_GRASA        NUMBER(4,2),
  OBSERVACIONES           VARCHAR2(500 BYTE),
  CONSTRAINT PK_EVALUACIONES_FISICAS PRIMARY KEY (EVALUACION_ID)
);

COMMENT ON TABLE  GT_EVALUACIONES_FISICAS IS 'Evaluaciones fisicas realizadas a socios por un entrenador (servicio opcional)';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.EVALUACION_ID IS 'Identificador de la evaluacion fisica';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.SOCIO_ID IS 'Identificador del socio evaluado';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.PERSONAL_ENTRENADOR_ID IS 'Identificador del personal que realiza la evaluacion (parte de la FK compuesta a GT_PERSONAL_ROLES)';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.ROL_ENTRENADOR_ID IS 'Identificador del rol de entrenador personal (parte de la FK compuesta a GT_PERSONAL_ROLES)';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.FECHA_EVALUACION IS 'Fecha en que se realizo la evaluacion';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.PESO IS 'Peso del socio en kilogramos';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.TALLA IS 'Talla del socio en metros';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.PORCENTAJE_GRASA IS 'Porcentaje de grasa corporal estimado';
COMMENT ON COLUMN GT_EVALUACIONES_FISICAS.OBSERVACIONES IS 'Observaciones sobre lesiones previas u otras condiciones';

--------------------------------------------------------------------------------
-- 13. GT_RUTINAS
-- La rutina se asigna directamente al socio; la evaluacion fisica es una
-- referencia OPCIONAL (EVALUACION_ID nulo permitido).
--------------------------------------------------------------------------------
CREATE TABLE GT_RUTINAS (
  RUTINA_ID              NUMBER(10)  NOT NULL,
  SOCIO_ID               NUMBER(8)   NOT NULL,
  EVALUACION_ID          NUMBER(10),
  FECHA_INICIO_VIGENCIA  DATE        NOT NULL,
  FECHA_FIN_VIGENCIA     DATE,
  ESTADO                 CHAR(1 BYTE) NOT NULL,
  CONSTRAINT PK_RUTINAS PRIMARY KEY (RUTINA_ID)
);

COMMENT ON TABLE  GT_RUTINAS IS 'Versiones de rutina de entrenamiento asignadas directamente al socio';
COMMENT ON COLUMN GT_RUTINAS.RUTINA_ID IS 'Identificador de la version de rutina';
COMMENT ON COLUMN GT_RUTINAS.SOCIO_ID IS 'Identificador del socio al que pertenece la rutina';
COMMENT ON COLUMN GT_RUTINAS.EVALUACION_ID IS 'Identificador de la evaluacion fisica de referencia (opcional, puede ser nulo)';
COMMENT ON COLUMN GT_RUTINAS.FECHA_INICIO_VIGENCIA IS 'Fecha desde la cual la rutina esta vigente';
COMMENT ON COLUMN GT_RUTINAS.FECHA_FIN_VIGENCIA IS 'Fecha hasta la cual la rutina estuvo vigente (nulo si es la vigente actual)';
COMMENT ON COLUMN GT_RUTINAS.ESTADO IS 'Estado de la rutina: V-Vigente, H-Historica';

--------------------------------------------------------------------------------
-- 14. GT_EJERCICIOS
--------------------------------------------------------------------------------
CREATE TABLE GT_EJERCICIOS (
  EJERCICIO_ID     NUMBER(6)        NOT NULL,
  NOMBRE           VARCHAR2(60 BYTE)  NOT NULL,
  GRUPO_MUSCULAR   VARCHAR2(40 BYTE),
  DESCRIPCION      VARCHAR2(300 BYTE),
  CONSTRAINT PK_EJERCICIOS PRIMARY KEY (EJERCICIO_ID)
);

COMMENT ON TABLE  GT_EJERCICIOS IS 'Catalogo de ejercicios disponibles para las rutinas';
COMMENT ON COLUMN GT_EJERCICIOS.EJERCICIO_ID IS 'Identificador del ejercicio';
COMMENT ON COLUMN GT_EJERCICIOS.NOMBRE IS 'Nombre del ejercicio';
COMMENT ON COLUMN GT_EJERCICIOS.GRUPO_MUSCULAR IS 'Grupo muscular principal trabajado';
COMMENT ON COLUMN GT_EJERCICIOS.DESCRIPCION IS 'Descripcion o instrucciones del ejercicio';

--------------------------------------------------------------------------------
-- 15. GT_DETALLES_RUTINA
-- Relacion M:N pura entre Rutina y Ejercicio: SIN ID propio, PK compuesta.
-- Se incluye DIA_SEMANA en la PK porque un mismo ejercicio puede repetirse
-- en distintos dias dentro de la misma rutina.
--------------------------------------------------------------------------------
CREATE TABLE GT_DETALLES_RUTINA (
  RUTINA_ID       NUMBER(10)        NOT NULL,
  EJERCICIO_ID    NUMBER(6)         NOT NULL,
  DIA_SEMANA      CHAR(2 BYTE)      NOT NULL,
  SERIES          NUMBER(2)         NOT NULL,
  REPETICIONES    NUMBER(3)         NOT NULL,
  CONSTRAINT PK_DETALLES_RUTINA PRIMARY KEY (RUTINA_ID, EJERCICIO_ID, DIA_SEMANA)
);

COMMENT ON TABLE  GT_DETALLES_RUTINA IS 'Ejercicios que componen cada version de rutina';
COMMENT ON COLUMN GT_DETALLES_RUTINA.RUTINA_ID IS 'Identificador de la rutina a la que pertenece (parte de la PK compuesta)';
COMMENT ON COLUMN GT_DETALLES_RUTINA.EJERCICIO_ID IS 'Identificador del ejercicio asignado (parte de la PK compuesta)';
COMMENT ON COLUMN GT_DETALLES_RUTINA.DIA_SEMANA IS 'Dia de la semana asignado: LU,MA,MI,JU,VI,SA,DO (parte de la PK compuesta)';
COMMENT ON COLUMN GT_DETALLES_RUTINA.SERIES IS 'Cantidad de series a realizar';
COMMENT ON COLUMN GT_DETALLES_RUTINA.REPETICIONES IS 'Cantidad de repeticiones por serie';

--------------------------------------------------------------------------------
-- 16. LLAVES FORANEAS
-- Patron FK_[TablaOrigen]_[TablaDestino]. Se abrevia PLANES_MEMBRESIA a
-- PLANES y EVALUACIONES_FISICAS a EVALUACIONES dentro del nombre del
-- constraint quando la concatenacion supera los 30 caracteres.
--------------------------------------------------------------------------------

ALTER TABLE GT_MEMBRESIAS
  ADD CONSTRAINT FK_MEMBRESIAS_SOCIOS FOREIGN KEY (SOCIO_ID)
  REFERENCES GT_SOCIOS (SOCIO_ID);

ALTER TABLE GT_MEMBRESIAS
  ADD CONSTRAINT FK_MEMBRESIAS_PLANES FOREIGN KEY (PLAN_ID)
  REFERENCES GT_PLANES_MEMBRESIA (PLAN_ID);

ALTER TABLE GT_MEMBRESIAS
  ADD CONSTRAINT FK_MEMBRESIAS_SEDES FOREIGN KEY (SEDE_ID)
  REFERENCES GT_SEDES (SEDE_ID);

ALTER TABLE GT_CONGELAMIENTOS
  ADD CONSTRAINT FK_CONGELAMIENTOS_MEMBRESIAS FOREIGN KEY (MEMBRESIA_ID)
  REFERENCES GT_MEMBRESIAS (MEMBRESIA_ID);

ALTER TABLE GT_PERSONAL
  ADD CONSTRAINT FK_PERSONAL_SEDES FOREIGN KEY (SEDE_ID)
  REFERENCES GT_SEDES (SEDE_ID);

ALTER TABLE GT_PERSONAL_ROLES
  ADD CONSTRAINT FK_PERSONAL_ROLES_PERSONAL FOREIGN KEY (PERSONAL_ID)
  REFERENCES GT_PERSONAL (PERSONAL_ID);

ALTER TABLE GT_PERSONAL_ROLES
  ADD CONSTRAINT FK_PERSONAL_ROLES_ROLES FOREIGN KEY (ROL_ID)
  REFERENCES GT_ROLES (ROL_ID);

ALTER TABLE GT_CLASES
  ADD CONSTRAINT FK_CLASES_TIPOS_CLASE FOREIGN KEY (TIPO_CLASE_ID)
  REFERENCES GT_TIPOS_CLASE (TIPO_CLASE_ID);

ALTER TABLE GT_CLASES
  ADD CONSTRAINT FK_CLASES_SEDES FOREIGN KEY (SEDE_ID)
  REFERENCES GT_SEDES (SEDE_ID);

ALTER TABLE GT_CLASES
  ADD CONSTRAINT FK_CLASES_PERSONAL_ROLES FOREIGN KEY (PERSONAL_INSTRUCTOR_ID, ROL_INSTRUCTOR_ID)
  REFERENCES GT_PERSONAL_ROLES (PERSONAL_ID, ROL_ID);

ALTER TABLE GT_RESERVAS
  ADD CONSTRAINT FK_RESERVAS_CLASES FOREIGN KEY (CLASE_ID)
  REFERENCES GT_CLASES (CLASE_ID);

ALTER TABLE GT_RESERVAS
  ADD CONSTRAINT FK_RESERVAS_SOCIOS FOREIGN KEY (SOCIO_ID)
  REFERENCES GT_SOCIOS (SOCIO_ID);

ALTER TABLE GT_EVALUACIONES_FISICAS
  ADD CONSTRAINT FK_EVALUACIONES_SOCIOS FOREIGN KEY (SOCIO_ID)
  REFERENCES GT_SOCIOS (SOCIO_ID);

ALTER TABLE GT_EVALUACIONES_FISICAS
  ADD CONSTRAINT FK_EVALUACIONES_PERSONAL_ROLES FOREIGN KEY (PERSONAL_ENTRENADOR_ID, ROL_ENTRENADOR_ID)
  REFERENCES GT_PERSONAL_ROLES (PERSONAL_ID, ROL_ID);

ALTER TABLE GT_RUTINAS
  ADD CONSTRAINT FK_RUTINAS_SOCIOS FOREIGN KEY (SOCIO_ID)
  REFERENCES GT_SOCIOS (SOCIO_ID);

ALTER TABLE GT_RUTINAS
  ADD CONSTRAINT FK_RUTINAS_EVALUACIONES FOREIGN KEY (EVALUACION_ID)
  REFERENCES GT_EVALUACIONES_FISICAS (EVALUACION_ID);

ALTER TABLE GT_DETALLES_RUTINA
  ADD CONSTRAINT FK_DETALLES_RUTINA_RUTINAS FOREIGN KEY (RUTINA_ID)
  REFERENCES GT_RUTINAS (RUTINA_ID);

ALTER TABLE GT_DETALLES_RUTINA
  ADD CONSTRAINT FK_DETALLES_RUTINA_EJERCICIOS FOREIGN KEY (EJERCICIO_ID)
  REFERENCES GT_EJERCICIOS (EJERCICIO_ID);

COMMIT;
