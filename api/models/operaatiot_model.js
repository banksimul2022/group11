const db = require('../database')

const operaatiot = {
  getTapahtumatByKortti: function (params, callback) { 
    console.log(params);
    return db.query('CALL sp_HaeTilitapahtumat(?, ?, ?)',
    [params.cardNumber, params.offset, params.noOfRows], callback);
  },
  getSaldoByKortti: function (cardNumber, callback) { 
    console.log(cardNumber);
    return db.query('CALL sp_HaeSaldo(?)',
    [cardNumber], callback);
  },
  createWithdraw: function (params, callback) {
    console.log(params.cardNumber);
    return db.query('Call sp_NostaRahaa(?, ?)',
    [params.cardNumber, params.amount], callback);
  },
  createTransaction: function (params, callback) {
    console.log(params.cardNumber, params.amount, params.targetCardNumber);
    return db.query('Call sp_SiirraRahaa(?, ?, ?)',
    [params.cardNumber, params.amount, params.targetCardNumber], callback);
  }
}

module.exports = operaatiot