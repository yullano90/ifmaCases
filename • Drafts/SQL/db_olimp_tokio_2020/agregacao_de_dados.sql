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
Atenção: Você deve fazer cadastro no Kaggle para poder realizar o download dos arquivos.

====================================================================================================================================

RESULTADO: 

- Essa análise NÃO PODE SER FEITA!!!

- Somente o item 01 é filé, o restante dos ítens não são possíveis.

Ao importar os dados para o MySQL um conflito no arquivo .csv é logo detectado.

Uma forma bem interessante de checar se o character set do schema criado é do tipo utf8, senão antes de dar o import do dataset já criar o schema com a configuração correta:

DROP DATABASE bd_olimp_tokio;
CREATE SCHEMA bd_olimp_tokio DEFAULT CHARACTER SET utf8mb4;


Uma outra alternativa é mudar o character set de colunas específicas (isso também é possível).
Outra forma de verificação de character set e collation é com a seguinte instrução:


SELECT @@character_set_database, @@collation_database;
** @@character_set_database = Configuração de como os caracteres serão armazenados;
** @@collation_database = Configuração do idioma do banco de dados;


Outra forma de verificar é:
SHOW VARIABLES LIKE 'collation%';

-- Temos collations de conexão, do banco e do servidor (instalação do MySQL como um todo);

Podemos ver ainda os collations a nível de tabela, exemplo:

USE bd_olimp_tokio;
SELECT
	table_schema,
    table_name,
    table_collation
FROM information_schema.tables
WHERE table_schema = 'bd_olimp_tokio';


Uma forma de gravar dados no mysql sem se preocupar com erros no codec, é usar linha de comando:

Após criar as tabelas, executar o LOAD DATA LOCAL INFILE:

# Conectar no MySQL via linha de comando
/usr/local/mysql/bin/mysql -u root -p

# Configurar o parâmetro para habilitar o comando de carga:
SET GLOBAL local_infile = true;
exit;

# Conectar novamente
/usr/local/mysql/bin/mysql --local-infile=1 -u root -p

# Carregar os dados
LOAD DATA LOCAL INFILE '/Users/yullano90/Dropbox/folder-tals/Athletes.csv' INTO TABLE `bd_olimp_tokio`.`TB_ATLETAS` CHARACTER SET UTF8
FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

LOAD DATA LOCAL INFILE '/Users/yullano90/Dropbox/folder-tals/Coaches.csv' INTO TABLE `bd_olimp_tokio`.`TB_COACHES` CHARACTER SET UTF8
FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

LOAD DATA LOCAL INFILE '/Users/yullano90/Dropbox/folder-tals/Medals.csv' INTO TABLE `bd_olimp_tokio`.`TB_MEDALS` CHARACTER SET UTF8
FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

LOAD DATA LOCAL INFILE '/Users/yullano90/Dropbox/folder-tals/EntriesGender.csv' INTO TABLE `bd_olimp_tokio`.`TB_ENTRIESGENDER` CHARACTER SET UTF8
FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

LOAD DATA LOCAL INFILE '/Users/yullano90/Dropbox/folder-tals/Teams.csv' INTO TABLE `bd_olimp_tokio`.`TB_TEAMS` CHARACTER SET UTF8
FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

(PENDENTE EXECUÇÃO);


Stop in 5/5