const citycontroller = require('../controller/citycontroller');

module.exports = async function (app) {
    app.route('/country/getPopulationByCity').post(citycontroller.getPopulationByCity);
}
