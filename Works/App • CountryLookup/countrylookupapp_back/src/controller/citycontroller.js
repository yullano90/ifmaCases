const populationCity = require('../model/populationcity')

async function getPopulationByCity(req, res) {
    if (req.body && req.body.ID) {
        try {
            let ID = parseInt(req.body.ID);
            if (!isNaN(ID)) {
                const response = await populationCity.getPopulationByCityID(ID);
                res.status(200).send(response);
            }
            else {
                res.status(500).send({ error: 'A propriedade "ID" precisa ser um número!' });
            }
        }
        catch (ex) {
            res.status(500).send({ error: ex });
        }
    }
    else {
        res.status(500).send({ error: 'Você deve definir a propriedade "ID" corretamente!' });
    }
}

exports.getPopulationByCity = getPopulationByCity;
