const db = require('../database')

const operaatiot = {
  getTapahtumatByKortti: function (cardNumber, callback) { 
    console.log(cardNumber);
    return db.query('CALL sp_HaeTilinTiedot(?)',
    [cardNumber], callback)
  },
  getSaldoByKortti: function (cardNumber, callback) { 
    console.log(cardNumber);
    return db.query('CALL sp_HaeTilinSaldo(?)',
    [cardNumber], callback)
  }
}

module.exports = operaatiot