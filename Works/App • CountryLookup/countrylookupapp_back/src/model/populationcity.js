const mySQLWorldDB = require('../repository/mySQLWorldDB');
const populationCity = function () { }; //Forma de declarar classe de uma Model;

populationCity.getPopulationByCityID = async function (ID) {
    const connection = await mySQLWorldDB.getConnection();
    const query = connection.sql(
    `SELECT name, population  FROM city WHERE ID = ?`).bind([ID]);

    //Declaramos um Array vazio, para o return da query, pq o banco é remoto e pode estar off;
    let data = [];

    //O bloco try catch é crucial pois, em caso de indisponibilidade do banco, já há uma trativa.
    //O try joga o fluxo de execução para o catch se houver algum erro.
    //Assim, lança-se uma exceção informando detalhes do erro apresentado.
    try {
        data = await query.execute();

    } catch (ex) {
        if (connection) {//Verifica-se se a conexão está definida;
            connection.close(); //Se definida, fecha-se a conexão;
            throw ex;//Mostra-se o erro, caso ocorra;
            return data.fetchAll(); //Retorna-se a lista dos elementos da query;
        }
    }
}

module.exports = populationCity; //Exportação da classe;