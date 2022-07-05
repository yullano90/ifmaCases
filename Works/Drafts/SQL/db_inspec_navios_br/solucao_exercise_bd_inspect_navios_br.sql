-- 1- Quais embarcações possuem pontuação de risco igual a 310?
-- 2- Quais embarcações têm classificação de risco A e índice de conformidade maior ou
-- igual a 95%?
-- 3- Quais embarcações têm classificação de risco C ou D e índice de conformidade menor
-- ou igual a 95%?
-- 4- Quais embarcações têm classificação de risco A ou pontuação de risco igual a 0?
-- 5- [DESAFIO] Quais embarcações foram inspecionadas em Dezembro de 2016?



# Solução Exercício 1


# Item 1:

SELECT * 
FROM cap02.TB_NAVIOS 
WHERE pontuacao_risco = 310;


# Item 2

SELECT * 
FROM cap02.TB_NAVIOS 
WHERE classificacao_risco = 'A'
  AND indice_conformidade >= 95;


# Item 3

SELECT * 
FROM cap02.TB_NAVIOS 
WHERE classificacao_risco = 'C' OR classificacao_risco = 'D'
  AND indice_conformidade <= 95;

SELECT * 
FROM cap02.TB_NAVIOS 
WHERE classificacao_risco IN ('C','D')
  AND indice_conformidade <= 95;


# Item 4

SELECT * 
FROM cap02.TB_NAVIOS 
WHERE classificacao_risco = 'A' 
   OR pontuacao_risco = 0;


# Item 5

SELECT * 
FROM cap02.TB_NAVIOS 
WHERE temporada LIKE '%Dezembro 2016';


