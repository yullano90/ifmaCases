<h5 align="center">
</br>
<img src="https://user-images.githubusercontent.com/40738499/168456236-ce8aac11-ddb7-4dbb-a540-00c39e10927b.png" width="250px" />
</br></br>

DEPARTAMENTO DE COMPUTAÇÃO</br>
SISTEMAS DE INFORMAÇÃO</br>
IULANO SILVA DOS SANTOS</br>
</br>

[![sistemas_de_informação](https://img.shields.io/badge/Sistemas_de_Informação-@IFMA-blue.svg)](url)</br>
[![software_livre](https://img.shields.io/badge/Software_Livre-Prof%20Mauro%20Lopes-yellow.svg)](url)</br>
</br>


PRÁTICA DE COMANDOS LINUX</br>
</br>


SÃO LUÍS, MA </br>
2022
</h5>

---

### Questões:

</br>
<img src="https://user-images.githubusercontent.com/40738499/170411431-a27f1870-1fc3-422d-a2fe-482feba35bf2.png" width="900px" />
<img src="https://user-images.githubusercontent.com/40738499/170411661-0a09fbfe-129d-420f-ba20-6e90b466ea2b.png" width="900px" />
</br>


<!-- | Questão | Abordagem |
| ----------------- | -------- |
| 01. | Comandos para Cancelamento e Inicialização de sessão |
| 02. | Comando para saber mais sobre outros comandos |
| 03. | Comandos para criação de diretórios |
| 04. | Comando de detalhamento de diretórios |
| 05. | Comando para exibição de caminho do diretório corrente |
| 06. | Comando para Criação de Arquivos |
| 07. | Comando para *input* de dados em arquivos de texto |
| 08. | Comando para *input* de dados em arquivos de texto  |
| 09. | Comando para apresentação sas três primeiras linhas do arquivo.txt |
| 10. | Comando para apresentação das três ultimas linhas do arquivo.txt |
| 11. | Aplicação do editor **nano** para input de dados no arquivo.txt |
| 12. | Aplicação do editor **nano** para input de dados no arquivo.txt  |
| 13. | Apresentação de conteúdo de arquivos SEM uso do nano |
| 14. | Limpeza do Terminal |
| 15. | Criação do diretório Backup + Transferência de arquivos dos diretórios A e B |
| 16. | Deleção de Arquivos dos diretórios A e B + Transferência de arquivos |
| 17. | Deleção do diretório Backup |
| 18. | Exibição da data atual do sistema |
| 19. | Exibição do usuário que está logado |
| 20. | Criação de um arquivo listando o histórico de comandos aplicados |
| 21. | Aplicação do comando **grep** |
| 22. | Comandos para alterãção de senha | -->

---

Utilizei o WSL (*Subsistema Linux do Windows*) com a distribuição do Ubuntu, para realizar a atividade:

![image](https://user-images.githubusercontent.com/40738499/169708351-0e92eff1-9f41-4247-8373-3089e4b06ba2.png)

#### Questão 01:
 
**login:** Inicia a sessão </br>
**logout**: "Deslogar", ou seja, terminar a sessão atual, mas apenas na shell e na bash shell. </br>
**exit**: Terminar a sessão, ou seja, mata shell. </br>
**reboot:** Reinicializa a máquina </br>
**halt:** Desliga a máquina </br>

---
#### Questão 02:
**man**: O comando *man* seguido por um espaço e um comando **ls**, abre e manual do Linux na “página man” que descreve o sufixo escolhido.
Neste caso o **ls**. Sendo assim é possível saber mais sobre qualquer outro comando, seguindo apenas a sintaxe "man + comando":

![image](https://user-images.githubusercontent.com/40738499/169708397-488a9685-74f2-47ba-81d5-a0362d53ba2f.png)

---

#### Questão 03:

**mkdir:** Criação dos diretórios "Atividade1" e "Atividade2". </br>
OBS: **Pra quem usar o WSL, quando se cria um usuário no Ubuntu**, ele cria um subdiretório dentro de "home".
Neste caso, entrei como super usuário para deletar o arquivo e deixar a "home" limpa, para criar os diretórios pedidos :

![image](https://user-images.githubusercontent.com/40738499/169708452-3c4bb3f4-0bc9-4ecd-92ae-dbf779d04deb.png)

---

#### Questão 04:

**ls -a**, **ls -l**, **ls -t**: Lisgtagem de conteúdo e detalhes do diretório:

![image](https://user-images.githubusercontent.com/40738499/169709217-fe6aaeff-f1e4-4ffc-860f-9d936494f3af.png)

---

#### Questão 05:

**pwd:** Exibição do caminho corrente:

![image](https://user-images.githubusercontent.com/40738499/169709355-c593a8c8-b219-4118-a2a5-18a35318167e.png)

---

#### Questão 06:

**touch:** Criação do file bairros.txt em dir atividade1 e file disciplinas em dir atividade2:

![image](https://user-images.githubusercontent.com/40738499/169709834-73789148-738a-459f-ad1a-d519786141d2.png)

---

#### Questão 07:

**echo:** Input de bairros no file bairros.txt:

![image](https://user-images.githubusercontent.com/40738499/169713138-d81d9c2f-64f7-4240-a3a1-f99ee23b4644.png)

---

#### Questão 08:

**echo:** Input de disciplinas no file disciplinas.txt:

![image](https://user-images.githubusercontent.com/40738499/169712198-63c4aaf5-9694-4828-9b23-423ff460dce9.png)

---

#### Questão 09:

**head**: Listar os 3 primeiros bairros:

![image](https://user-images.githubusercontent.com/40738499/169712779-d9e37414-ed19-4b2f-bd88-22e841c12d99.png)

---

#### Questão 10:

**tail**: Listar as 3 ultimas disciplinas:

![image](https://user-images.githubusercontent.com/40738499/169712369-2d1c5b93-38de-435c-bac8-9e0532171691.png)

---

#### Questão 11:

<!-- ![image](https://user-images.githubusercontent.com/40738499/169713435-731f731b-fe99-4b7d-80d4-dbad6745767a.png)

![image](https://user-images.githubusercontent.com/40738499/169713529-6060c716-a4e3-47d6-9ca8-b6fffb43dde5.png)

![image](https://user-images.githubusercontent.com/40738499/169713590-202972fa-fcce-4ae5-8fb1-74d56024144b.png) -->

![image](https://user-images.githubusercontent.com/40738499/169713633-5177da3e-b384-48d2-98f7-2e6534ac6614.png)


---

#### Questão 12:

![image](https://user-images.githubusercontent.com/40738499/169713844-01e2aab3-9995-4b32-a137-1c51c751e196.png)

---

#### Questão 13:

![image](https://user-images.githubusercontent.com/40738499/169714045-7e9e2617-1c36-40de-a33e-5cd92aaa5a65.png)

---

#### Questão 14:

Aplicação do **clear**.

---

#### Questão 15:

![image](https://user-images.githubusercontent.com/40738499/169730911-79be1816-0f0a-449e-859b-b60e50668d41.png)

---

#### Questão 16:

![image](https://user-images.githubusercontent.com/40738499/169732197-b751dd83-9047-4b74-86c6-857680397eff.png)

---
#### Questão 17:

![image](https://user-images.githubusercontent.com/40738499/169732393-c977848b-3816-4b8b-af61-5f0273486095.png)

---

#### Questão 18:

![image](https://user-images.githubusercontent.com/40738499/169714846-35f46cb8-51a1-4795-ad60-e32889633aaf.png)

---

#### Questão 19:

![image](https://user-images.githubusercontent.com/40738499/169715032-ed6f219f-78ca-4d6a-842e-92a3a2badab7.png)

---

#### Questão 20:

![image](https://user-images.githubusercontent.com/40738499/169733891-b4992cda-2edd-4fcf-b9cc-165064965c2c.png)
<!-- ![image](https://user-images.githubusercontent.com/40738499/169734034-0491acba-7138-4989-9093-3fce52473b1f.png) -->

---

#### Questão 21:

![image](https://user-images.githubusercontent.com/40738499/169734847-71af9d71-3b12-46bf-b755-c665fc6d5bf5.png)

---
