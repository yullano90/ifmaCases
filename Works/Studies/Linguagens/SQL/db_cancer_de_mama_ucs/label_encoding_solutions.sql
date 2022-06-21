# Verificando cada categoria que há na variável 'menopausa':

SELECT DISTINCT menopausa FROM tb_dados_cmm;

#----------------------------------------------------------------------------
# label encoding na variável menopausa:

CREATE TABLE bd_cancer_de_mama.tb_menopausa
AS
SELECT
	classe,
	idade,
	CASE
		WHEN menopausa = 'premeno' THEN 1
		WHEN menopausa = 'ge40' THEN 2
		WHEN menopausa = 'lt40' THEN 3
	END AS menopausa, 
	tamanho_tumor,
	inv_nodes,
	node_caps,
	deg_malig,
	seio,
	quadrante,
	irradiando
	
 FROM 
 	bd_cancer_de_mama.tb_dados_cmm;

#----------------------------------------------------------------------------
# Após binarização, verificar as categorias da variável 'menopausa':

SELECT DISTINCT menopausa FROM bd_cancer_de_mama.tb_menopausa;
#----------------------------------------------------------------------------

#Concatendo as colunas inv_nodes e quadrante:

CREATE TABLE bd_cancer_de_mama.tb_concat
AS
SELECT
	classe,
	idade,
	menopausa, 
	tamanho_tumor,
CONCAT(inv_nodes ,'-', quadrante) AS posicao_tumor,
	node_caps,
	deg_malig,
	seio,
	irradiando
	
 FROM 
 	bd_cancer_de_mama.tb_menopausa;

#----------------------------------------------------------------------------
#Os processos acima, chamamos também de técnicas de Engenharia de Atributos.
#One-hot-encoding na variável "deg_malig":

SELECT DISTINCT deg_malig FROM tb_menopausa;

CREATE TABLE bd_cancer_de_mama.tb_deg_malig
AS
SELECT
	classe,
	idade,
	menopausa, 
	tamanho_tumor,
	posicao_tumor,
	node_caps,
CASE WHEN deg_malig = 1 THEN 1 ELSE 0 END AS deg_malig_1,
CASE WHEN deg_malig = 2 THEN 1 ELSE 0 END AS deg_malig_2,
CASE WHEN deg_malig = 3 THEN 1 ELSE 0 END AS deg_malig_3,
	seio,
	irradiando
	
 FROM 
 	bd_cancer_de_mama.tb_concat;

#----------------------------------------------------------------------------

