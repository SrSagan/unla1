-- Creación de esquema:
create database if not exists farmacia;

-- Para mostrar los esquemas existentes en la BD:
show schemas;

-- Para establecer el esquema sobre el que trabajamos:
use farmacia;

-- Para consultar cual es el esquema en uso:
select schema();

-- Creamos la tabla obra_social en el esquema activo:
create table if not exists obra_social(
	codigo int primary key,
	nombre varchar(45) not null,
	descripcion varchar(100) not null
);

-- Para mostrar la definición de la tabla:
show create table obra_social;

-- para mostrar las tablas definidas en el esquema 
-- activo:
show tables;

-- para eliminar una tabla
-- drop table obra_social;

-- Para renombrar una tabla:
alter table obra_social rename to obra;
alter table obra rename to obra_social;

-- Para cambiar la columna descripcion a descr
-- (hay que indicar todos los datos de la columna):
alter table obra_social change column descripcion descr varchar(100);
alter table obra_social change column descr descripcion varchar(100);

truncate table obra_social;

-- Insertamos datos en la tabla:
insert into obra_social 
	values(1,"PAMI","Programa de Atención Médica Integral");
-- Intentamos insertar con la misma PK:
insert into obra_social 
	values(2,"IOMA","Instituto de Obra Medico Asistencial");

insert into obra_social (codigo, nombre, descripcion) 
	values(3,"IOMA","Instituto de Obra Medico Asistencial");

insert into obra_social (codigo, nombre, descripcion) 
	values(4,"OSECAC","Obra Social de Empleados de Comercio");

-- Consultamos los registos insertados
select * from obra_social;

/*****************************************************************
Práctica:
Hacer lo mismo para tablas calle, localidad y provincia. 
Agregar en provincia: (1, Buenos Aires) y (2, CABA) 
Agregar en localidad: (1, Lanús), (2, Pompeya), (3, Avellaneda)
Agregar en calles: (1, 9 de Julio) , (2, Hipólito Yrigoyen) , (3, Mitre), (4, Sáenz).
Para cada una  de ellas:
crearla, eliminarla, crearla nuevamente, 
cambiar el nombre y volver a cambiarlo al original.
cambiar el nombre de alguna columna y volver a cambiarlo al original,
agregar los datos especificados, 
consultar y verificar que los datos hayan ingresado.
******************************************************************/

create table if not exists provincia
(
	id int not null primary key,
    nombre varchar(45) not null
);

create table if not exists localidad
(
	id int not null primary key,
    nombre varchar(45) not null,
    provincia_id int not null
);

create table if not exists calle
(
	id int not null primary key,
    nombre varchar(45) not null,
    localidad_id int not null
);

drop table provincia;
drop table localidad;
drop table calle;

create table if not exists provincia
(
	id int not null primary key,
    nombre varchar(45) not null
);

create table if not exists localidad
(
	id int not null primary key,
    nombre varchar(45) not null,
    provincia_id int
);

create table if not exists calle
(
	id int not null primary key,
    nombre varchar(45) not null,
    localidad_id int
);

alter table provincia rename to estado;
alter table localidad rename to partido;
alter table calle rename to avenida;

alter table estado rename to provincia;
alter table partido rename to localidad;
alter table avenida rename to calle;

alter table provincia change column nombre name varchar(45);
alter table localidad change column nombre name varchar(45);
alter table calle change column nombre name varchar(45);

alter table provincia change column name nombre varchar(45);
alter table localidad change column name nombre varchar(45);
alter table calle change column name nombre varchar(45);

insert into provincia (id, nombre)
	values (1, "Buenos Aires");
    
insert into provincia (id, nombre)
	values (2, "CABA");
    
insert into localidad (id, nombre)
	values (1, "Lanus");
    
insert into localidad (id, nombre)
	values (2, "Pompeya");

insert into localidad (id, nombre)
	values (3, "Avellaneda");

insert into calle (id, nombre)
	values (1, "9 de Julio");
    
insert into calle (id, nombre)
	values (2, "Hipolito Yrigoyen");

insert into calle (id, nombre)
	values (3, "Mitre");

insert into calle (id, nombre)
	values (4, "Saenz");