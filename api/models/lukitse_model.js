const db = require('../database')

const lukitse = {
  changeLockCard: function (params, callback) {
    console.log(params);
    return db.query('Call sp_AvaaLukitseKortti(?, ?)',
    [params.cardNumber, params.lockStatus], callback);
  }
}

module.exports = lukitse