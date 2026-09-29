-- CRUD (Criar, Ler, Atualizar e Deletar)
-- DDL ( Data Definition Language)
-- CRUD DDL (Create, [Show, Describe], Alter, Drop)

-- Para criar do zero podemos exvluir o banco se ja existe e criar novamente
drop database if exists pedidos;
-- Criar um banco de dados chamado "pedidos"
create database produtos;
-- Selecionar o banco de dados chamado "pedidos"
use pedidos;
-- Criar a tabela de produtos
create table produtos (
    id int primary key  not null auto_increment, 
    nome varchar(40) not null, 
    descricao varchar(200) not null, 
    volume decimal(10,2) not null,
    valor decimal(10,2) not null
);
-- Criar a tebela de pedidos
create table pedidos (
    id int primary key not null auto_increment,
    cliente varchar(40) not null,
    cep varchar(10) not null,
    numero varchar(10), 
    complemento varchar(20), 
    data date not null default(CURDATE())
);
-- Criar a tabela de itens
create table itens (
    id int primary key not null auto_increment, 
    id_pedido int  not null,
    id_produto int not null,
    preco decimal(10,2) not null, 
    quantidade int not null
);
-- Criando os relacionamentos, alterando a tabela de itens
alter table itens add constraint eh foreign key (id_produto) references produtos(id);
alter table itens add constraint possui foreign key (id_pedido) references pedidos(id);
-- Exibir os resultados
describe produtos;
describe pedidos;
describe itens;
show tables;
