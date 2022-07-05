CREATE SCHEMA `db_ifood` ;


CREATE TABLE `db_ifood`.`TB_CLIENTES` (
  `id_cliente` INT NULL,
  `nome_cliente` VARCHAR(50) NULL,
  `endereco_cliente` VARCHAR(50) NULL,
  `cidade_cliente` VARCHAR(50) NULL,
  `estado_cliente` VARCHAR(50) NULL);


INSERT INTO `db_ifood`.`TB_CLIENTES` (`id_cliente`, `nome_cliente`, `endereco_cliente`, `cidade_cliente`, `estado_cliente`)
VALUES (1, "Bob Silva", "Rua 67", "Fortaleza", "CE");

INSERT INTO `db_ifood`.`TB_CLIENTES` (`id_cliente`, `nome_cliente`, `endereco_cliente`, `cidade_cliente`, `estado_cliente`)
VALUES (2, "Ronaldo Azevedo", "Rua 64", "Campinas", "SP");

INSERT INTO `db_ifood`.`TB_CLIENTES` (`id_cliente`, `nome_cliente`, `endereco_cliente`, `cidade_cliente`, `estado_cliente`)
VALUES (3, "John Lenon", "Rua 42", "Rio de Janeiro", "RJ");

INSERT INTO `db_ifood`.`TB_CLIENTES` (`id_cliente`, `nome_cliente`, `endereco_cliente`, `cidade_cliente`, `estado_cliente`)
VALUES (4, "Billy Joel", "Rua 39", "Campos", "RJ");

INSERT INTO `db_ifood`.`TB_CLIENTES` (`id_cliente`, `nome_cliente`, `endereco_cliente`, `cidade_cliente`, `estado_cliente`)
VALUES (5, "Lady Gaga", "Rua 45", "Porto Alegre", "RS");


CREATE TABLE `db_ifood`.`TB_PEDIDOS` (
  `id_pedido` INT NULL,
  `id_cliente` INT NULL,
  `id_vendedor` INT NULL,
  `data_pedido` DATETIME NULL,
  `id_entrega` INT NULL);


INSERT INTO `db_ifood`.`TB_PEDIDOS` (`id_pedido`, `id_cliente`, `id_vendedor`, `data_pedido`, `id_entrega`)
VALUES (1001, 1, 5, now(), 23);

INSERT INTO `db_ifood`.`TB_PEDIDOS` (`id_pedido`, `id_cliente`, `id_vendedor`, `data_pedido`, `id_entrega`)
VALUES (1002, 1, 7, now(), 24);

INSERT INTO `db_ifood`.`TB_PEDIDOS` (`id_pedido`, `id_cliente`, `id_vendedor`, `data_pedido`, `id_entrega`)
VALUES (1003, 2, 5, now(), 23);


CREATE TABLE `db_ifood`.`TB_VENDEDOR` (
  `id_vendedor` INT NULL,
  `nome_vendedor` VARCHAR(50) NULL);


INSERT INTO `db_ifood`.`TB_VENDEDOR` (`id_vendedor`, `nome_vendedor`)
VALUES (1, "Vendedor 1");

INSERT INTO `db_ifood`.`TB_VENDEDOR` (`id_vendedor`, `nome_vendedor`)
VALUES (2, "Vendedor 2");

INSERT INTO `db_ifood`.`TB_VENDEDOR` (`id_vendedor`, `nome_vendedor`)
VALUES (3, "Vendedor 3");

INSERT INTO `db_ifood`.`TB_VENDEDOR` (`id_vendedor`, `nome_vendedor`)
VALUES (4, "Vendedor 4");

INSERT INTO `db_ifood`.`TB_VENDEDOR` (`id_vendedor`, `nome_vendedor`)
VALUES (5, "Vendedor 5");

INSERT INTO `db_ifood`.`TB_VENDEDOR` (`id_vendedor`, `nome_vendedor`)
VALUES (6, "Vendedor 6");

INSERT INTO `db_ifood`.`TB_VENDEDOR` (`id_vendedor`, `nome_vendedor`)
VALUES (7, "Vendedor 7");


-- JUNÇÕES UTILIZANDO INNER JOIN:

-- Retornar clientes que realizaram pedidos (Modelo I):

SELECT P.id_pedido, C.nome_cliente
FROM db_ifood.tb_pedidos AS P INNER JOIN db_ifood.tb_clientes AS C
ON P.id_cliente = C.id_cliente;

-- OU SIMPLISMENTE:

SELECT P.id_pedido, C.nome_cliente
FROM db_ifood.tb_pedidos AS P
JOIN db_ifood.tb_clientes AS C
USING (id_cliente);


=========================================================================================

-- Retornar clientes que realizaram pedidos (Modelo II):

SELECT P.id_pedido, C.nome_cliente
FROM db_ifood.tb_pedidos AS P INNER JOIN db_ifood.tb_clientes AS C
WHERE P.id_cliente = C.id_cliente;
=========================================================================================

-- Retornar id_pedido, nome_cliente, nome_vendedor (Modelo I):

SELECT P.id_pedido, C.nome_cliente, V.nome_vendedor
FROM ((db_ifood.tb_pedidos AS P 
INNER JOIN db_ifood.tb_clientes AS C ON P.id_cliente = C.id_cliente)
INNER JOIN db_ifood.tb_vendedor AS V ON P.id_vendedor = V.id_vendedor)

=========================================================================================

-- Retornar id_pedido, nome_cliente, nome_vendedor (Modelo II):

SELECT P.id_pedido, C.nome_cliente, V.nome_vendedor
FROM db_ifood.tb_pedidos AS P, db_ifood.tb_clientes AS C, db_ifood.tb_vendedor AS V
WHERE P.id_cliente = C.id_cliente
AND P.id_vendedor = V.id_vendedor

=========================================================================================

-- A ordem como o programador faz um JOIN interfere diretamente nos dados recuperados.
-- Abaixo temos cenários onde a posição das tabelas na query fizeram toda diferença:

-- Clientes que ainda não realizaram pedidos:
SELECT nome_cliente, id_pedido
FROM db_ifood.tb_clientes AS C LEFT OUTER JOIN db_ifood.tb_pedidos AS P
ON C.id_cliente = P.id_cliente
WHERE P.id_pedido IS NOT NULL;

-- OU

SELECT nome_cliente, id_pedido
FROM db_ifood.tb_clientes AS C RIGHT JOIN db_ifood.tb_pedidos AS P
ON C.id_cliente = P.id_cliente;

=========================================================================================

-- Clientes com ou sem pedido realizado:
SELECT nome_cliente, id_pedido
FROM db_ifood.tb_clientes AS C LEFT OUTER JOIN db_ifood.tb_pedidos AS P
ON C.id_cliente = P.id_cliente;

-- OU

SELECT nome_cliente, id_pedido
FROM db_ifood.tb_pedidos AS C RIGHT JOIN db_ifood.tb_clientes AS P
ON C.id_cliente = P.id_cliente;


=========================================================================================

-- Retornar data do pedido, nome do cliente, todos os vendedores (com ou sem pedido) e ordenar pelo nome do cliente.
SELECT data_pedido, nome_cliente, nome_vendedor
FROM ((tb_pedidos AS P 
  JOIN tb_clientes AS C ON P.id_cliente = C.id_cliente)
  RIGHT JOIN tb_vendedor AS V ON P.id_vendedor = V.id_vendedor)
  ORDER BY nome_cliente;


=========================================================================================

-- Inserção de registros para testar Integridade Referencial. Será possível perceber que houve a inserção, gerando registros órfãos:

INSERT INTO db_ifood.tb_pedidos (id_pedido, id_cliente, id_vendedor, data_pedido, id_entrega)
VALUES (1004, 16, 100, NOW(), 23);


INSERT INTO db_ifood.tb_pedidos (id_pedido, id_cliente, id_vendedor, data_pedido, id_entrega)
VALUES (1005, 17, 101, NOW(), 24);


=========================================================================================

-- Quando o programador usa o MySQL e deseja fazer um FULL OUTER JOIN não é possível pois o MySQL não o implementou em sua sintaxe.
-- Nesse caso, é necessário usar o UNION conforme abaixo:
-- Retornar nome_cliente e id_pedido mesmo que exista um registro órfão:

SELECT nome_cliente, id_pedido
FROM (db_ifood.tb_clientes AS C) LEFT OUTER JOIN (db_ifood.tb_pedidos P)
ON (C.id_cliente = P.id_cliente)

UNION

SELECT nome_cliente, id_pedido
FROM (db_ifood.tb_clientes AS C) RIGHT OUTER JOIN (db_ifood.tb_pedidos P)
ON (C.id_cliente = P.id_cliente);

-- Cenário anterior com duplicatas:

SELECT nome_cliente, id_pedido
FROM (db_ifood.tb_clientes AS C) LEFT OUTER JOIN (db_ifood.tb_pedidos P)
ON (C.id_cliente = P.id_cliente)
UNION ALL
SELECT nome_cliente, id_pedido
FROM (db_ifood.tb_clientes AS C) RIGHT OUTER JOIN (db_ifood.tb_pedidos P)
ON (C.id_cliente = P.id_cliente);

=========================================================================================

-- Inserir um novo cliente em Campinas Sao Paulo, e em seguida, identificar clientes diferentes nessa localidade.
-- Chamamos essa estratégia de consulta de SELF JOIN:

INSERT INTO db_ifood.tb_clientes VALUES (6, 'Yullano Santos', 'Rua 07', 'Campinas', 'SP');

SELECT A.nome_cliente, A.cidade_cliente 
FROM tb_clientes AS A, tb_clientes AS B
WHERE A.id_cliente <> B.id_cliente AND
A.cidade_cliente = B.cidade_cliente;

=========================================================================================
-- CROSS JOIN para retornar todos os dados ou por questões de performance:

USE DB_IFOOD;
SELECT P.id_pedido, C.nome_cliente
FROM tb_pedidos AS P, tb_clientes AS C
ORDER BY nome_cliente;

=========================================================================================


https://www.kaggle.com/datasets/arjunprasadsarkhel/2021-olympics-in-tokyo

Os dados contêm um resumo das Olímpiadas de Tokyo 2020 (mas que foi realizada em 2021 devido à pandemia). 
Você deve criar uma tabela para cada arquivo, carregar os arquivos no banco de dados e então responder às perguntas abaixo:
1-Quem são os técnicos (coaches) e atletas das equipes de Handball?
2-Quem são os técnicos (coaches) dos atletas da Austrália que receberam medalhas de Ouro?
3-Quais países tiveram mulheres conquistando medalhas de Ouro?
4-Quais atletas da Noruega receberam medalhas de Ouro ou Prata?
5-Quais atletas Brasileiros não receberam medalhas?

Obs:  Segundo  o  autor  dos  datasets,  os  dados  foram  extraídos  do  site  oficial  das Olimpíadas  de  Tokyo,  
mas  não  validamos  a  acurácia  ou  veracidade  dos  dados.  

Como  nosso propósito aqui é estudar Linguagem SQL e não as Olimpíadas, os dados atendem nosso propósito. 
Mas as conclusões não devem ser consideradas oficiais sem validação dos dados (o  que não é necessário para este exercício). 
Vamos estudar SQL.Atenção: Você deve fazer cadastro no Kaggle para poder realizar o download dos arquivos.












