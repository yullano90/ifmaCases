require('dotenv').config({ path: 'config.env' });
const mysqlx = require('@mysql/xdevapi');
const mySQLWorldDB = function () { }; //Forma de declarar classe;

async function getConnection() {
    //Recebe parâmetros em um json devidamente formatado;
    //Esses parâmetros já estão setados no arquivo de configuração;
    //Somente assim, será possível abrir uma conexão com o banco de dados;
    //Dessa forma estaremos acessando as variáveis de ambiente do Node.js;
    const config = {
        password: process.env.WORLD_MYSQL_DB_PASSWORD,
        user: process.env.WORLD_MYSQL_DB_USER,
        host: process.env.WORLD_MYSQL_DB_HOST,
        port: parseInt(process.env.WORLD_MYSQL_DB_PORT),
        schema: process.env.WORLD_MYSQL_DB_SCHEMA
    }
    // console.log(config);
    return mysqlx.getSession(config);
}

mySQLWorldDB.getConnection = getConnection;
module.exports = mySQLWorldDB;
