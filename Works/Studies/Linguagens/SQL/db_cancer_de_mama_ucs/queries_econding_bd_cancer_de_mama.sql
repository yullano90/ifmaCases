# Tipos de Labels: Label Encoding e One-hot-encoding
# Label Encoding: normalmente aplicamos quando a variável categórica tem até 5 catergorias.
# One-Hot-Encoding: usado em variável acima de 05 categorias para criar variáveis Dummy
# (criando uma representação numérica para cada acategoria de uma variável categórica).

# BINARIZAÇÃO:
# O  objetivo é  limpar  e  transformar  os  dados  através  de  categorização,  codificação  e binarização 
# e  então  gerar  um  novo  dataset que  poderá  ser  usado  mais  a  frente  por  outros profissionais da equipe 
# de Ciência de Dados. Conjunto de dados de pacientes que desenvolveram câncer de mama:
# Fonte: https://archive.ics.uci.edu/ml/datasets/breast+cancer
# https://archive.ics.uci.edu/ml/machine-learning-databases/breast-cancer/


CREATE DATABASE bd_cancer_de_mama;
CREATE TABLE bd_cancer_de_mama.tb_dados_cmm (
  `classe` VARCHAR(100) NULL,
  `idade` VARCHAR(45) NULL,
  `menopausa` VARCHAR(45) NULL,
  `tamanho_tumor` VARCHAR(45) NULL,
  `inv_nodes` VARCHAR(45) NULL,
  `node_caps` VARCHAR(3) NULL,
  `deg_malig` INT NULL,
  `seio` VARCHAR(5) NULL,
  `quadrante` VARCHAR(10) NULL,
  `irradiando` VARCHAR(3) NULL);

SELECT * FROM bd_cancer_de_mama.tb_dados_cmm;

# Binarização da variável classe (0/1)
SELECT DISTINCT classe FROM bd_cancer_de_mama.tb_dados_cmm;

SELECT 
	CASE 
		WHEN classe = 'no-recurrence-events' THEN 0 
        WHEN classe = 'recurrence-events' THEN 1
	END as classe
FROM bd_cancer_de_mama.tb_dados_cmm;

# Binarização da variável irradiando (0/1)
SELECT DISTINCT irradiando FROM bd_cancer_de_mama.tb_dados_cmm;

SELECT 
	CASE 
		WHEN irradiando = 'no' THEN 0 
        WHEN irradiando = 'yes' THEN 1
	END as irradiando
FROM bd_cancer_de_mama.tb_dados_cmm;


# Para ajustar a variável node_caps iremos agora codificar a variável e não mais binarizar:
SELECT 
	CASE 
		WHEN node_caps = 'no' THEN 0 
        WHEN node_caps = 'yes' THEN 1
        ELSE 2
	END as node_caps
FROM bd_cancer_de_mama.tb_dados_cmm;


# Categorização da variável seio (E/D)
SELECT DISTINCT seio FROM bd_cancer_de_mama.tb_dados_cmm;

SELECT 
	CASE 
		WHEN seio = 'left' THEN 'E' 
        WHEN seio = 'right' THEN 'D'
	END as seio
FROM bd_cancer_de_mama.tb_dados_cmm;

# Categorização da variável tamanho_tumor (6 Categorias)
SELECT DISTINCT tamanho_tumor FROM bd_cancer_de_mama.tb_dados_cmm;

SELECT 
	CASE 
		WHEN tamanho_tumor = '0-4' OR tamanho_tumor = '5-9' THEN 'Muito Pequeno'
        WHEN tamanho_tumor = '10-14' OR tamanho_tumor = '15-19' THEN 'Pequeno'
        WHEN tamanho_tumor = '20-24' OR tamanho_tumor = '25-29' THEN 'Medio'
        WHEN tamanho_tumor = '30-34' OR tamanho_tumor = '35-39' THEN 'Grande'
        WHEN tamanho_tumor = '40-44' OR tamanho_tumor = '45-49' THEN 'Muito Grande'
        WHEN tamanho_tumor = '50-54' OR tamanho_tumor = '55-59' THEN 'Tratamento Urgente'
	END as tamanho_tumor
FROM bd_cancer_de_mama.tb_dados_cmm;

# Label Encoding da variável quadrante (1,2,3,4,5)
SELECT DISTINCT quadrante FROM bd_cancer_de_mama.tb_dados_cmm;

SELECT 
	CASE 
		WHEN quadrante = 'left_low' THEN 1 
        WHEN quadrante = 'right_up' THEN 2 
        WHEN quadrante = 'left_up' THEN 3
        WHEN quadrante = 'right_low' THEN 4
        WHEN quadrante = 'central' THEN 5
        ELSE 0
	END as quadrante
FROM bd_cancer_de_mama.tb_dados_cmm;
