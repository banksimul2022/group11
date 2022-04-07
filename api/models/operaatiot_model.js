const db = require('../database')

const operaatiot = {
  getTapahtumatByKortti: function (params, callback) { 
    console.log(params);
    return db.query('CALL sp_HaeTilinTiedot(?, ?, ?)',
    [params.cardNumber, params.offset, params.noOfRows], callback)
  },
  getSaldoByKortti: function (cardNumber, callback) { 
    console.log(cardNumber);
    return db.query('CALL sp_HaeTilinSaldo(?)',
    [cardNumber], callback)
  }
}

module.exports = operaatiot