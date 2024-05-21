-- create database base_de_datos_personas;

use base_de_datos_personas;

create table personas
(
	dni int not null,
    nombre varchar(40) not null,
    apellido varchar(40) not null,
    primary key(dni)
);

create table pasajeros
(
	dni int not null,
    pasajero_usual bool not null,
    vuelos_codigo int not null,
    personas_dni int,
    primary key(dni)
);

create table pilotos
(
	cuil int not null primary key,
    dni int not null,
    fecha_ingreso date,
    personas_dni int
);

create table vuelos
(
	codigo int not null primary key,
    distancia_recorrida int not null,
    pilotos_cuil int not null,
    aviones_matricula int not null,
    fecha_arribo date not null,
    fecha_partida date not null
);

create table aviones(
	matricula int not null primary key,
    fecha_entrada_servicio date not null,
    modelo varchar(20) not null,
    marcas_codigo int not null
);

create table marcas(
	
    codigo int not null primary key,
    pais_origen varchar(40) not null,
    nombre varchar(40) not null
);

create table domicilios
(
	dni_personas int not null primary key,
    calle varchar(45) not null,
    numero int not null,
    localidades_id int not null
);

create table localidades
(
	id int not null primary key,
    nombre varchar(45) not null,
    provincias_id int not null
);

create table provincias
(
	id int not null primary key,
    nombre varchar(45)
);

create table domicilios_has_personas
(
	domicilios_dni_personas int not null,
    personas_dni int not null
);

create table aeropuertos
(
	iata int not null primary key,
    nombre varchar(45) not null,
    ciudad varchar(45) not null
);

create table aeropuertos_has_vuelos
(
	aeropuertos_iata_llegada int not null,
    aeropuertos_iata_partida int not null,
    vuelos_codigo int not null primary key
);

alter table pasajeros
add constraint persona_es_pasajero
foreign key (personas_dni)
references personas(dni);

alter table pilotos
add constraint persona_es_piloto
foreign key (personas_dni)
references personas(dni);

alter table domicilios
add constraint domicilio_en_localidad
foreign key (localidades_id)
references localidades(id);

alter table localidades
add constraint localidades_en_provincia
foreign key (provincias_id)
references provincias(id);

alter table domicilios_has_personas
add constraint persona_tiene_domicilio
foreign key (personas_dni)
references personas(dni);

alter table domicilios_has_personas
add constraint domicio_es_de_persona
foreign key (domicilios_dni_personas)
references domicilios(dni_personas);

alter table aeropuertos_has_vuelos
add constraint aeropuerto_llegada
foreign key (aeropuertos_iata_llegada)
references aeropuertos(iata);

alter table aeropuertos_has_vuelos
add constraint aeropuerto_partida
foreign key (aeropuertos_iata_partida)
references aeropuertos(iata);

alter table aeropuertos_has_vuelos
add constraint vuelo_aeropuertos
foreign key (vuelos_codigo)
references vuelos(codigo);

alter table vuelos
add constraint vuelos_de_aviones
foreign key (aviones_matricula)
references aviones(matricula);

alter table aviones
add constraint marca_de_avion
foreign key (marcas_codigo)
references marcas(codigo);

alter table vuelos
add constraint piloto_de_avion
foreign key (pilotos_cuil)
references pilotos(cuil);