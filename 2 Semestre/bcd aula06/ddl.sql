drop database if exists amparo_taxi;
create database amparo_taxi;

use amparo_taxi;

create table motorista (
    id int(11) primary key auto_increment,
    nome varchar(100),
    cpf varchar(15),
    cnh varchar(20),
    celular varchar(15),
    email varchar(100),
    obs text,
    status enum('ativo','inativo')
);

create table passageiro (
    id int(11) primary key auto_increment,
    nome varchar(100),
    cpf varchar(15),
    celular varchar(15),
    email varchar(100),
    obs text,
    status enum('ativo','banido')
);

create table veiculo (
    placa varchar(10) primary key,
    modelo varchar(20),
    marca varchar(20),
    cor varchar(20),
    ano int(11),
    motorista_id int(11),
    foreign key (motorista_id) references motorista(id)
);

create table viagem (
    id int(11) primary key auto_increment,
    passageiro_id int(11),
    placa varchar(10),
    valor decimal(10,2),
    origem varchar(50),
    hora_partida datetime,
    destino varchar(50),
    hora_chegada datetime,
    avaliacao_motorista int(11),
    avaliacao_passageiro int(11),
    foreign key (passageiro_id) references passageiro(id),
    foreign key (placa) references veiculo(placa)
);