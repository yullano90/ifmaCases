const mySQLWorldDB = require('../repository/mySQLWorldDB');
const languageCountry = function () { };

populationCity.getLanguageByCountryID = async function (CountryCode) {
    const connection = await mySQLWorldDB.getConnection();
    const query = connection.sql(
        `SELECT CountryCode, Language FROM countrylanguage `+
        ` WHERE CountryCode = ?`).bind([CountryCode]);
    let data = [];

    try {
        data = await query.execute();

    } catch (ex) {
        if (connection) {
            connection.close();
            throw ex;
            return data.fetchAll();
        }
    }
}

module.exports = languageCountry;