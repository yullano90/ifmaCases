require('dotenv').config({path: 'config.env'});
const express = require('express');
const routes = require('./routes/routes');
const app = express();
app.use(express.json()); //Mostra no console da API o body enviado;
const port = process.env.SERVER_PORT;

function main() {
    console.log(port);
    app.listen(port);
    routes(app);
}

main();