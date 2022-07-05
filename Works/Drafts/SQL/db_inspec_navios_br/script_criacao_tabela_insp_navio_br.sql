CREATE DATABASE bd_Inspec_Navios_BR;
-- USE bd_Inspec_Navios_BR;

CREATE TABLE `bd_Inspec_Navios_BR`.`TB_NAVIOS` (
  `nome_navio` VARCHAR(50) NULL,
  `mes_ano` VARCHAR(10) NULL,
  `classificacao_risco` VARCHAR(15) NULL,
  `indice_conformidade` VARCHAR(15) NULL,
  `pontuacao_risco` INT NULL,
  `temporada` VARCHAR(200) NULL);

