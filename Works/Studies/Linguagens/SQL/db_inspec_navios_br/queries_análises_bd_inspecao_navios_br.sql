
-- Embarcações com Classificação "C" ou "D" e índice de confirmidade  maior que 95%.
SELECT * from tb_navios
WHERE classificacao_risco in ('C','D') AND indice_conformidade <= 95;

-- Embarcações com Classificação de Risco "A" ou Pontuação de Risco = 0;
SELECT * from tb_navios;
SELECT nome_navio, classificacao_risco, pontuacao_risco from tb_navios
WHERE classificacao_risco = "A" or pontuacao_risco = 0;

-- Recurso, Variável, Característica, Atributo são nomes dados para colunas em BD.

